#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main(){
    int M;
    cin >> M;
    list<int> mylist;
    list<int>::iterator it1,it2;

    for (int i=0; i<M; i++){
        char cmd;
        int value;
        cin >> cmd >> value;
        if (cmd == 'I'){
            mylist.push_front(value);
        }
        else if (cmd == 'A'){
            mylist.push_back(value);
        }
        else if (cmd == 'D'){
            if (value <= mylist.size()){
                it1 = mylist.begin();
                advance(it1,value-1);
                mylist.erase(it1);
            }
        }
    }

    for (int i: mylist){
        cout << i << endl;
    }
    return 0;
}