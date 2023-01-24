/*
    Task	: 5_maxlate
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 25 January 2023 [00:12]
    Algo	: Interval Scheduling (Greedy Algorithm)
    Status	: 
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
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        intervals.push_back({s,t});
    }
    sort(intervals.begin(),intervals.end());

    

    return 0;
}