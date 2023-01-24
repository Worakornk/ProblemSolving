#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, Ans = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++){
        if (v[i] > 0){
            Ans += v[i];
        }
    }
    cout << Ans;
    return 0;
}