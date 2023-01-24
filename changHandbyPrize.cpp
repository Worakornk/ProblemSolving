// More Efficient Method

#include<bits/stdc++.h>

using namespace std;

bool visit[100000]={false};
int ans[100000]={0};

void dfs(vector <int> *Graph,int current,int head){
    visit[current]=true;
    ans[current]=head;
    if(visit[Graph[current][0]]==false){
        ans[Graph[current][0]]=head;
        dfs(Graph,Graph[current][0],head);
    }
}

int main(){
    int n,m,head;
    cin>>n;
    vector <int> Graph[n];
    for(int i=0;i<n;i++){
        cin>>m;
        Graph[i].push_back(m-1);
    }
    for(int i=0;i<n;i++){
        if(!visit[i]){
            dfs(Graph,i,i);
        }
    }
    sort(ans,ans+n);
    int mysum=1,count=1;
    for(int i=0;i<n;i++){
        if(ans[i]==ans[i+1]&i!=n-1){
            count+=1;
        }
        else if(ans[i]!=ans[i+1]&i!=n-1){
            count=1;
        }
        if(count>mysum){
            mysum=count;
        }
    }
    cout<<mysum;
}
