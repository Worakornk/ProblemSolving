/*
    Task	: 6_fin_toofast
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 25 January 2023 [19:58]
    Algo	: 
    Status	: 
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int TooFast(int array[][4],int s,int t){
    set<array<int>> set;
    
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,m,A,B,C,S;
    cin >> n >> m;
    int ls_inputs[m][4]; // input 2d array
    for (int i = 0; i < m; i++)
    {
        cin >> A >> B >> C >> S;
        ls_inputs[i][0] = A;
        ls_inputs[i][1] = B;
        ls_inputs[i][2] = C;
        ls_inputs[i][3] = S;
    }

 
    return 0;
}