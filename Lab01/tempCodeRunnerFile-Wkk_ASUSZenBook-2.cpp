#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,T;
    cin >> N >> T;
    vector<int> myArray;

    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        myArray.push_back(x);
    }

    if (T == 1)
    {
        for (int i=0; i < N; i++)
        {
            if (i == 0){
                if (myArray[i] - N == 1){
                    cout << "1" << endl;
                } else if (myArray[i] - N == -1){
                    cout << "0" << endl;
                }
            }
            else if(myArray[i] - myArray[i-1] == 1)
            {
                cout << "1" << endl;
            }
            else if (myArray[i] - myArray[i-1] == -1)
            {
                cout << "0" << endl;
            }
        }
    } 

    else if (T == 2)
    {
        int tempY = 0;
        vector<int> arrayY;
        for (int i = 0; i < N; i++){
            if (i == 0){
                if (myArray[i] - N == 1){
                    cout << "1" << endl;
                    tempY = N+1;
                } else if (myArray[i] - N == -1){
                    cout << "0" << endl;
                    tempY = N-1;
                }
            } else {
                if (myArray[i] = 2*tempY+1){
                    cout << "0" << endl;
                    tempY = tempY + 1;
                } else if (myArray[i] = tempY+2*(tempY-1)){
                    cout << "1" << endl;
                    tempY = tempY - 1;
                }
            }
        }

    }
    return 0;
}