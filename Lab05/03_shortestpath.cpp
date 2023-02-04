/*
    Task	: 03_shortestpath
    Author	: First
    School	: KU
    Language: C++
    Created	: 27 January 2023 [09:58]
    Algo	: 
    Status	: 
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<pii> adj[100001];

int dijkstra(int s, int t){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(100001,INT_MAX);
    dist[s] = 0;
    pq.push({0,s});
    while (!pq.empty()){
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != dist[u])
            continue;
        for (auto x:adj[u]){
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist[t];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,m;
    cin >> n >> m;

    for (int i = 0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout << dijkstra(1,n);
    return 0;
}