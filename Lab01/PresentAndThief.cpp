#include <iostream>
using namespace std;

int main(){
    int nPeople, Shift, Theif, Present=1,count=0,check=0;
    cin >> nPeople >> Shift >> Theif;
    while(1){
        if (Present == Theif){
            count++;
            break;
        }
        else if (Present == 1 and check==0){
            check++;
            count++;
        }
        else if (Present == 1 and check==1){
            break;
        }
        else{
            count++;
        }
        Present = (Present+Shift)%nPeople;
    }
    cout << count;
    return 0;
}

    