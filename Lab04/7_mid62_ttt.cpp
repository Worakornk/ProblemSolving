/*
    Task	: 7_mid62_ttt
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 25 January 2023 [19:58]
    Algo	: Bipartite Graph
    Status	: 
*/
#include<bits/stdc++.h>
using namespace std;
 
int is_bipartite(vector<int> graph[], int n, int src, int color[]){
    color[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x: graph[u]){
            if(color[x] == -1){
                color[x] = 1 - color[u];
                q.push(x);
            }
            else if(color[x] == color[u])
                return 0;
        }
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,m;
    vector>
    for (int i = 0; i<m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
        connection[i][0] = u;
        connection[i][1] = v;
    }



    // int n,m;
    // cin >> n >> m;

    // vector<int> graph[n];
    // int connection[n][2];
    // vector<int> indegree(n,0);

    // for (int i = 0; i < m ; i++)
    // {
    //     int u,v;
    //     cin >> u >> v;
    //     graph[u].push_back(v);
    //     indegree[v]++;
    //     connection[i][0] = u;
    //     connection[i][1] = v;
    // }

    // //check which edge can be removed to get bipartite graph
    // for (int i = 0; i < m; i++)
    // {
    //     int u = connection[i][0];
    //     int v = connection[i][1];
    //     graph[u].erase(find(graph[u].begin(),graph[u].end(),v));
    //     indegree[v]--;
    //     int color[n];
    //     memset(color,-1,sizeof(color));
    //     int flag = 1;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if(indegree[j] == 0 && color[j] == -1){
    //             if(!is_bipartite(graph,n,j,color)){
    //                 flag = 0;
    //                 break;
    //             }
    //         }
    //     }
    //     if(flag){
    //         cout << u << " " << v << endl;
    //         return 0;
    //     }
    //     graph[u].push_back(v);
    //     indegree[v]++;
    // }
    // cout << connection[0][0] << " " << connection[0][1] << endl;

    // return 0;
}