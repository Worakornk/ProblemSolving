/*
    Task	: ku01_under
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 27 December 2022 [22:34]
    Algo	: Array
    Status	: Completed
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int L,N;
    cin >> L >> N;

    array<int,2> a[N];
    for (int i=0; i<N; i++){
        cin >> a[i][0] >> a[i][1];
    }

    int ans = 0;
    float current_pos = 0;
    while (current_pos <= L){
        int tmp_ans = 0;
        for (int i=0; i<N; i++){
            if (a[i][0] < current_pos && current_pos < a[i][1]){
                tmp_ans++;
            }
        }
        if (tmp_ans >= ans){
            ans = tmp_ans;
        }
        current_pos+=0.5;
    } 
    cout << ans << endl;
    return 0;
}
