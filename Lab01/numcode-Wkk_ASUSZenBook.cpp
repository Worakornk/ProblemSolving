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
                    cout << "1" << "\n";
                } else if (myArray[i] - N == -1){
                    cout << "0" << "\n";
                }
            }
            else if(myArray[i] - myArray[i-1] == 1)
            {
                cout << "1" << "\n";
            }
            else if (myArray[i] - myArray[i-1] == -1)
            {
                cout << "0" << "\n";
            }
        }
    } 

    else if (T == 2)
    {
        int arrayY[N] = {0};
        arrayY[0] = myArray[0];
        int Ans[N] = {0};
        for (int i = 1; i < N; i++)
        {
            if (myArray[i] - 2*arrayY[i-1]==arrayY[i-1]+1)
            {
                arrayY[i] = arrayY[i-1] + 1;
            }
            else if (myArray[i] - arrayY[i-1]==arrayY[i-1]-1)
            {
                arrayY[i] = arrayY[i-1] - 1;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if ( i == 0 )
            {
                if (arrayY[i] - N == 1)
                {
                    Ans[i] = 1;
                }
                else if (arrayY[i] - N == -1)
                {
                    Ans[i] = 0;
                }
            }
            else if (arrayY[i] - arrayY[i-1] == 1)
            {
                Ans[i] = 1;
            }
            else if (arrayY[i] - arrayY[i-1] == -1)
            {
                Ans[i] = 0;
            }
        }
        for (int i = 0; i < N; i++)
        {
            cout << Ans[i] << "\n";
        }
    }
    return 0;
}