/*
    Task	: mid65_teamprojects
    Author	: First
    School	: KU
    Language: C++
    Created	: 30 January 2023 [13:57]
    Algo	: Topological Sort
    Status	: 
*/
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     cin.tie(0)->sync_with_stdio(0);
//     cin.exceptions(cin.failbit);


//     int N,M,K;
//     cin >> N >> M >> K;
    
//     //Find if we can seperate into 2 groups
//     vector<int> graph[N+1];
//     vector<int> indegree(N+1,0);

//     for(int i=0;i<M;i++){
//         int u,v;
//         cin >> u >> v;
//         graph[u].push_back(v);
//         indegree[v]++;
//     }

//     // Remove node that has indegree >= K
//     for(int i=1;i<=N;i++){
//         if(indegree[i] >= K){
//             for(auto x:graph[i]){
//                 indegree[x]--;
//             }
//         }
//     }

//     // Topological Sort
//     queue<int> q;
//     for(int i=1;i<=N;i++){
//         if(indegree[i] == 0){
//             q.push(i);
//         }
//     }

//     int cnt = 0;
//     while(!q.empty()){
//         int now = q.front();
//         q.pop();
//         cnt++;
//         for(auto x:graph[now]){
//             indegree[x]--;
//             if(indegree[x] == 0){
//                 q.push(x);
//             }
//         }
//     }

//     if(cnt == N){
//         cout << "yes" << endl;
//     }else{
//         cout << "no" << endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);


    int N,M,K;
    cin >> N >> M >> K;
    
    //Find if we can seperate into 2 groups
    vector<int> graph[N+1];
    vector<int> indegree(N+1,0);

    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    // Remove node that has indegree >= K
    vector<int> ls;
    for(int i=1;i<=N;i++){
        if(indegree[i] >= K){
            for(auto x:graph[i]){
                indegree[x]--;
            }
            indegree[i] = 0;
        }
    }

    

    // Topological Sort
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cnt++;
        for(auto x:graph[now]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }

    if(cnt == N){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    return 0;
}