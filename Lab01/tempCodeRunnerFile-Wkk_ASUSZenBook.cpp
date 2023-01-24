#include <iostream>
#include <iterator>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
cin.tie(NULL);
    int n;
    cin >> n;
    int howToMove[n] = {0};
    int myArray[n] = {0};
    int constArray[n] = {0};

    //setup
    for (int i = 0; i < n; i++){
        myArray[i] = i+1;
        constArray[i] = i+1;
    }

    //input
    for (int i = 0; i < n; i++){
        cin >> howToMove[i];
    }

    //process
    int check = 0, count = 0;
    while (check < n){
        count++;
        int temp[n] = {0};
        for (int j = 0; j < n; j++){
            temp[j] = myArray[j];
        }
        for (int i = 0; i < n; i++){
            myArray[i] = temp[howToMove[i]-1];
        }
        for (int i = 0; i < n; i++){
            if (myArray[i] == constArray[i]){
                check++;
                constArray[i] = 9999999;
            }
        }
    }
    cout << count;
    return 0;
}