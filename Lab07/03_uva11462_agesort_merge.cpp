/*
    Task	: 03_uva11462_agesort_merge
    Author	: First
    School	: KU
    Language: C++
    Created	: 20 February 2023 [13:16]
    Algo	: 
    Status	: 
*/
#include<bits/stdc++.h>
using namespace std;

int tmp[2000005];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0) break;

        

        for(int i = 0; i < n; i++)
            cin >> tmp[i];
        sort(tmp, tmp + n);

        for (int i = 0; i < n; i++)
        {
            if (i < n-1)
                cout << tmp[i] << " ";
            else
                cout << tmp[i] << "\n";
        }
    }
    return 0;
}