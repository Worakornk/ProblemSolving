/*
    Task	: 2.topo
    Author	: First
    School	: KU
    Language: C++
    Created	: 23 January 2023 [15:45]
    Algo	: Topological Sort
    Status	: Completed
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n];         // adjacency list
    vector<int> indegree(n, 0); // indegree of each node

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> ans;
    while(ans.size()<n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                temp.push_back(i);
                indegree[i]--;
            }
        }

        if (temp.empty())
        {
            cout << "no";
            return 0;
        }

        for (int i = 0; i < temp.size(); i++)
            ans.push_back(temp[i]);

        for (int i = 0; i < temp.size(); i++)
        {
            for (int j = 0; j < adj[temp[i]].size(); j++)
            {
                indegree[adj[temp[i]][j]]--;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << endl;

    return 0;
}