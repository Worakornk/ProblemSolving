/*
    Task	: 10_mid64_roundtable
    Author	: First
    School	: KU
    Language: C++
    Created	: 26 January 2023 [11:23]
    Algo	: 
    Status	: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,b=0,count=0,max = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (i == 0 || a - b == -1 || a - b == n-1)
            count++;
        else 
        {
            if (count > max)
                max = count;
            count = 1;
        }
        b = a;
    }
    return 0;
}