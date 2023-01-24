/*
    Task	: 03_jumppoint
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 27 December 2022 [22:54]
    Algo	: BFS
    Status	: 
*/
#include <bits/stdc++.h>
using namespace std;

int n, r;
pair<int, int> nodes[1010];
vector<int> adjlist[1010];
vector<int> visited;
queue<int> q;


bool isReachable(pair<int, int> a, pair<int, int> b)
{
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2) <= pow(r, 2);
}

int BFS()
{
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adjlist[u].size(); i++)
        {
            if (adjlist[u][i] == n+1) //endpoint 
            {
                return visited[u];
            }
            if (visited[adjlist[u][i]]) //already visited
            {
                continue;
            }
            q.push(adjlist[u][i]);
            visited[adjlist[u][i]] = visited[u] + 1;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> r;
    visited.resize(n+2);
    nodes[0].first = 0; nodes[0].second = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes[i].first = x;
        nodes[i].second = y;
    }
    nodes[n+1].first = 100; nodes[n+1].second = 100;
    for (int i = 0; i < n+2; i++)
    {
        for (int j = i + 1; j < n+2; j++)
        {
            if (isReachable(nodes[i], nodes[j]))
            {
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }
    cout << BFS();
    return 0;
}

/*

5 60
50 0
100 0
100 50
50 30
70 50

*/