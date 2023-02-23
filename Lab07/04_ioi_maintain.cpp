/*
    Task	: ioi_maintain
    Author	: First
    School	: KU
    Language: C++
    Created	: 20 February 2023 [13:15]
    Algo	: Minimum Spanning Tree
    Status	: 
*/
#include<bits/stdc++.h>
using namespace std;

int find_parent(vector<int> &parent, int u){
    if (u != parent[u])
        parent[u] = find_parent(parent, parent[u]);
    return parent[u];
}

int union_set(vector<int> &parent, vector<int> &rank, int u, int v){
    int x = find_parent(parent, u);
    int y = find_parent(parent, v);

    if (x == y) return 0;

    if (rank[x] > rank[y])
        parent[y] = x;
    else
        parent[x] = y;
    if (rank[x] == rank[y])
        rank[y]++;
    return 1;
}

int minimum_spanning(vector<pair<int, pair<int, int>>> weighted_grapgh, int nFarms){
    int mst_weight = 0;
    vector<int> parent(nFarms+1);
    vector<int> rank(nFarms+1);

    for (int i = 0; i < nFarms+1; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(weighted_grapgh.begin(), weighted_grapgh.end());

    for (int i = 0; i < weighted_grapgh.size(); i++)
    {
        int u = weighted_grapgh[i].second.first;
        int v = weighted_grapgh[i].second.second;
        int w = weighted_grapgh[i].first;

        int x = find_parent(parent, u);
        int y = find_parent(parent, v);

        if (x != y)
        {
            mst_weight += w;
            union_set(parent, rank, x, y);
        }
    }
    return mst_weight;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int nFarms, paths;
    cin >> nFarms >> paths;

    vector<pair<int, pair<int, int>>> weighted_grapgh;
    for (int i = 0; i < paths; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        weighted_grapgh.push_back({w, {u, v}});
        minimum_spanning(weighted_grapgh, nFarms);
    }
    return 0;
}