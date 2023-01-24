#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int nDarts = 0;
    int Score = 0;
    cin >> nDarts;
    for (int i = 0; i < nDarts; i++){
        int x,y;
        cin >> x >> y;
        float distance = sqrt(x*x + y*y);
        if (distance <= 2){
            Score += 5;
        } else if (distance <= 4){
            Score += 4;
        } else if (distance <= 6){
            Score += 3;
        } else if (distance <= 8){
            Score += 2;
        } else if (distance <= 10){
            Score += 1;
        } else {
            Score += 0;
        }
    }
    cout << Score;
    return 0;
}