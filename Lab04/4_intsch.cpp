/*
    Task	: 4_intsch
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 24 January 2023 [21:35]
    Algo	: Interval Scheduling (Greedy Algorithm)
    Status	: Completed
*/
#include<bits/stdc++.h>
#define pii <pair<int,int>>
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,s,t;
    cin >> n;
    vector pii intervals;
    for(int i=0;i<n;i++){
        cin >> s >> t;
        intervals.push_back({s,t});
    }
    sort(intervals.begin(),intervals.end());

    int max = 0;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(intervals[i].first >= max){
            max = intervals[i].second;
            count++;
        }
        else if(intervals[i].second <= max){
            max = intervals[i].second;
        }
    }

    cout << count;
    return 0;
}