/*
    Task	: mid65_countries
    Author	: First
    School	: KU
    Language: C++
    Created	: 30 January 2023 [13:08]
    Algo	:
    Status	:
*/
#include <bits/stdc++.h>
using namespace std;

int di[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int R, C, A, B, X, Y;
    cin >> R >> C >> A >> B >> X >> Y;
    A--;
    B--;
    X--;
    Y--;

    int Map[R][C];
    int visited[R][C];
    vector<pair<int, int>> pos[R * C + 1000]; // location of that country

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int a;
            cin >> a;
            Map[i][j] = a;
            visited[i][j] = 0;
            pos[a].push_back({i, j}); // location of that country
        }
    }

    int s_country = Map[A][B];
    int e_country = Map[X][Y];

    // cout << s_country << " " << e_country << endl;

    // create graph
    vector<int> graph[R * C + 1000];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            visited[i][j] = 1;
            for (int k = 0; k < 4; k++)
            {
                int ni = i + di[k][0];
                int nj = j + di[k][1];
                if (ni < 0 || ni >= R || nj < 0 || nj >= C)
                    continue;
                if (visited[ni][nj] == 1)
                    continue;
                if (Map[i][j] != Map[ni][nj])
                {
                    if (find(graph[Map[i][j]].begin(), graph[Map[i][j]].end(), Map[ni][nj]) != graph[Map[i][j]].end())
                        continue;
                    graph[Map[i][j]].push_back(Map[ni][nj]);
                    graph[Map[ni][nj]].push_back(Map[i][j]);
                }
            }
        }
    }

    // for (int i = 0; i < R*C+1000; i++){
    //     if (graph[i].size() == 0)
    //         continue;
    //     cout << i << ": ";
    //     for (int j = 0; j < graph[i].size(); j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // find depth of the target country using bfs
    queue <int> q;
    int depth[R*C+1000];
    fill(depth, depth+R*C+1000, 1000000);
    q.push(s_country);
    depth[s_country] = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i];
            if (depth[next] > depth[now] + 1){
                depth[next] = depth[now] + 1;
                q.push(next);
            }
        }
    }

    cout << depth[e_country] << endl;
    return 0;
}