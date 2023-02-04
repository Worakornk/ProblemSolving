/*
    Task	: 10_mid64_roundtable
    Author	: First
    School	: KU
    Language: C++
    Created	: 26 January 2023 [11:23]
    Algo	: Loop and Count
    Status	: Completed
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,distance,max=-1;
    cin >> n;
    vector<int> dishes(n, 0);
    vector<int> dp(n, 0);
    for (int i = 0 ; i<n; i++){
        cin >> dishes[i];
        distance = (i + n - dishes[i]) % n;
        dp[distance]++;
        if (dp[distance] > max){
            max = dp[distance];
        }
    }
    cout << max;
    return 0;
}