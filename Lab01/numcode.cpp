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

    else if(T==2){
        for(int i=0;i < N;i++){    
            if (i == 0){
                if (myArray[i] - N == 1){
                    cout << "1" << endl;
                } else if (myArray[i] - N == -1){
                    cout << "0" << endl;
                }
            }
            if(y[0]==n+1){
                cout << "1" << endl;
            }
            else if(y[0]==n-1){
                cout << "0" << endl;
            }
            for(int i=1;i<n;i++){
                if(y[i]==y[i-1]+1){
                    cout << "1" << endl;
                }
                else if(y[i]==y[i-1]-1){
                    cout << "0" << endl;
                }
            }
    }
    return 0;
}


//  else if(mode==2){
//         vector <int> y;
//         y.push_back(code[0]);
//         for(int i=1;i<n;i++){    
//             if(code[i]-2*y[i-1]==y[i-1]+1){
//                 y.push_back(y[i-1]+1);
//             }
//             else if(code[i]-y[i-1]==y[i-1]-1){
//                 y.push_back(y[i-1]-1);
//             }
//         }
//         if(y[0]==n+1){
//             ans.push_back(1);
//         }
//         else if(y[0]==n-1){
//             ans.push_back(0);
//         }
//         for(int i=1;i<n;i++){
//             if(y[i]==y[i-1]+1){
//                 ans.push_back(1);
//             }
//             else if(y[i]==y[i-1]-1){
//                 ans.push_back(0);
//             }
//         }
//     }