// #include <iostream>
// using namespace std;

// int main()
// {
//     //setup
//     int nPlayer, nRound;
//     cin >> nPlayer >> nRound;
//     int myArray[nPlayer] = {0};
//     for (int i = 0; i < nPlayer; i++){
//         int x;
//         cin >> x;
//         myArray[i] = x;
//     }
//     float min = myArray[0];

//     //find min
//     for (int i = 0; i < nPlayer; i++){
//         if (myArray[i] < min){
//             min = myArray[i];
//         }
//     }

//     //process
//     int count = 0;
//     for (int i = 0; i < nPlayer; i++){
//         if (nRound - (nRound * min)/myArray[i] <= 1){
//             count++;
//         }
//     }
//     cout << count;
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    //setup
    int nPlayer, nRound;
    cin >> nPlayer >> nRound;
    int myArray[nPlayer] = {0};
    for (int i = 0; i < nPlayer; i++){
        int x;
        cin >> x;
        myArray[i] = x;
    }
    float min = myArray[0];

    //find min
    for (int i = 0; i < nPlayer; i++){
        if (myArray[i] < min){
            min = myArray[i];
        }
    }

    //process
    int count = 0;
    for (int i = 0; i < nPlayer; i++){
        if (min*nRound > myArray[i]*(nRound-1)){
            count++;
        }
    }
    cout << count;
    return 0;
}
