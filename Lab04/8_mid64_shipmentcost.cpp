/*
    Task	: 8_mid64_shipmentcost
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 25 January 2023 [19:59]
    Algo	: Shortest Path
    Status	: 
*/
#include<bits/stdc++.h>
using namespace std;

int ShortestPath(vector<int> graph[],int n,int s,int t){
    int dist[n];
    for (int i=0;i<n;i++)
    {
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t];
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int N, M, S, T;
    vector<int> ls_warehouse;
    vector<int> ls_factory;
    cin >> N >> M >> S >> T;
    vector<int> graph[N];
    for (int i=0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=0;i<S;i++)
    {
        int x;
        cin >> x;
        ls_warehouse.push_back(x-1);
    }

    for (int i=0;i<T;i++)
    {
        int y;
        cin >> y;
        ls_factory.push_back(y-1);
    }

    for (int i=0;i<T;i++)
    {
        vector<int> ls_cost;
        for (int j=0;j<S;j++)
        {
            ls_cost.push_back(ShortestPath(graph,N,ls_factory[i],ls_warehouse[j]));
        }
        cout << *min_element(ls_cost.begin(),ls_cost.end()) << endl;
    }
 
    return 0;
}