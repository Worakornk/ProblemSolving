/*
    Task	: 5_maxlate
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 25 January 2023 [00:12]
    Algo	: Interval Scheduling - minimize maximum lateness (Greedy Algorithm)
    Status	: 
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,dl,time;
    cin >> n;
    vector <pii> list_inputs;
    for (int i = 0; i < n; i++)
    {
        cin >> dl >> time;
        list_inputs.push_back({dl,time});
    }

    sort(list_inputs.begin(),list_inputs.end());
    int totaltime = 0;
    int maxLate = 0;
    for (int i = 0; i < n; i++)
    {
        totaltime += list_inputs[i].second;
        if (totaltime - maxLate > 10)
        {
            maxLate = max(maxLate,totaltime-list_inputs[i].first);
        }
    }
    if (maxLate == 0){
        cout << 0;
    }
    else{
        cout << (maxLate-10)*1000;
    }
}