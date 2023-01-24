#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    //setup
    int N,count = 0;
    cin >> N;
    vector<int> myArray;
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        myArray.push_back(x);
    }

    //process
    int i = 0;
    while (i<=N-1){
        for (int j = i+1; j < myArray.size(); j++){
            if (myArray[i] < myArray[j]){
                count++;
            }
        }
        i++;
    }

    cout << count;
    return 0;
}