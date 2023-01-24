/*
    Task	: 03_jumppoint
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 26 December 2022 [13:23]
    Algo	: BFS and DFS
    Status	: Completed
*/
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100010;

int m, n;
vector<int> adj[MAX_N];
int deg[MAX_N];

void readInput()
{
    cin >> m >> n;
    for (int u = 0; u < n; u++){
        deg[u] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        deg[u]++;
        adj[v].push_back(u);
        deg[v]++;
    }
}

int layer[MAX_N];
bool visited[MAX_N];

void init(){
    for (int i = 0; i < m; i++){
        layer[i] = -1;
        visited[i] = false;
    }
}

void bfs(int s){
    vector<int> current_layer;
    vector<int> next_layer;
    current_layer.push_back(s);
    layer[s] = 0;
    int l = 0;
    while (!current_layer.empty()){
        for (auto ui = current_layer.begin();
            ui != current_layer.end(); 
            ui++) {
            int u = *ui;
            visited[u] = true;
            for (int d = 0; d < deg[u]; d++){
                int v = adj[u][d];
                if (layer[v] == -1){ // v is undiscovered
                    layer[v] = l + 1;
                    next_layer.push_back(v);
                }
            }
        }
        current_layer = next_layer;
        next_layer.clear();
        l++;
    }
}

void dfs(int u){
    visited[u] = true;
    for (int d = 0; d < deg[u]; d++){
        int v = adj[u][d];
        if (!visited[v]){
            dfs(v);
        }
    }
}

int main()
{
    readInput();
    init();
    int ccount = 0;

    for (int i = 0; i < m; i++){
        if (!visited[i]){
            bfs(i);
            ccount++;
        }
    }

    cout << ccount << endl;
}