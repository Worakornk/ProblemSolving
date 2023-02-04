/*
    Task	: 05_fin59_hos2
    Author	: First
    School	: KU
    Language: C++
    Created	: 27 January 2023 [10:12]
    Algo	: BFS Algorithm
    Status	:
*/
#include<bits/stdc++.h>
using namespace std;

int count_by_BFS(vector<int> graph[],int s, int N, int maxHour){
    // // cout << s+1 << " ";
    // if (maxHour == 0) return 1;
    // int count = 1, travel_hours = 1;
    // int noNodeOfCurrentLevel = 1;
    // int noNodeOfNextLevel = 0;
    // vector<int> visited(N,0);
    // queue<int> q;

    // visited[s] = 1;
    // q.push(s);

    // while (!q.empty())
    // {
    //     int u = q.front();
    //     q.pop();
    //     noNodeOfCurrentLevel--;
    //     if (travel_hours > maxHour) break;
    //     for (int i = 0 ; i<graph[u].size(); i++){
    //         int v = graph[u][i];
    //         if (visited[v] == 0){
    //             // cout << v+1 << " ";
    //             visited[v] = 1;
    //             noNodeOfNextLevel++;
    //             q.push(v);
    //             count++;
    //         } else {
    //             continue;
    //         }
    //     }
    //     if (noNodeOfCurrentLevel == 0)
    //     {
    //         noNodeOfCurrentLevel = noNodeOfNextLevel;
    //         travel_hours++;
    //     }
    // }
    // // cout << endl;
    // return count;

    int count = 1;
    int travelingHours[10000];
    fill(travelingHours, travelingHours+N, 1000000);

    queue<int> q;
    q.push(s);
    travelingHours[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if (travelingHours[u] > maxHour) break;
        for (int i = 0 ; i<graph[u].size(); i++){
            int v = graph[u][i];
            if (travelingHours[v] > travelingHours[u] + 1 and travelingHours[u] + 1 <= maxHour){
                travelingHours[v] = travelingHours[u] + 1;
                q.push(v);
                count++;
            }
        }
    }
    return count;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N, M, maxHour;
    cin >> N >> M >> maxHour;
    int ans = 1;
    vector<int> graph[N];

    

    for (int i = 0 ; i<M; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (int i = 0 ; i<N; i++){
        int count = count_by_BFS(graph, i, N, maxHour);
        ans = max(ans, count);
    }
    cout << ans;
    return 0;
}
/*
Input
7 7 1
1 2
7 1
1 3
3 4
4 5
6 5
3 6
Output
4

Input
7 7 2
1 2
7 1
1 3
3 4
4 5
6 5
3 6
Output
7
*/

