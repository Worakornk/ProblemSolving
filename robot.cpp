#include <iostream>
#include <cstring>  
using namespace std;

int main(){
    string str;
    int x=0,y=0;
    cin >> str;
    for (int i;i<str.length();i++){
        if (str[i] == 'N'){
            y++;
        }
        else if (str[i] == 'S'){
            y--;
        }
        else if (str[i] == 'E'){
            x++;
        }
        else if (str[i] == 'W'){
            x--;
        } else if (str[i] == 'Z') {
            x = 0;
            y = 0;
        }
    }
    cout << x << " " << y;
}