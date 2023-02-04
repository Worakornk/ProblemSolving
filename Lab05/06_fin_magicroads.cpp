/*
    Task	: 06_fin_magicroads
    Author	: First
    School	: KU
    Language: C++
    Created	: 30 January 2023 [11:40]
    Algo	: 
    Status	: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N,M,K,H;
    cin >> N >> M >> K >> H;
    vector<vector<int>> Graph[N];
    for (int i = 0 ; i<M ; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        Graph[u].push_back({v,w});
        Graph[v].push_back({u,w});
    }
    




    return 0;
}