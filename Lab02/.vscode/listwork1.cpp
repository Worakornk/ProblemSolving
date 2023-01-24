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
        if (cmd == "I")
            mylist.push_back(value);
        }
        else if (cmd == "D"){
            it1 = mylist.begin();
            advance(it1,value);
            mylist.erase(it1);
        }
    }

    for (int i=0; i<mylist.size(); i++){
        it2 = mylist.begin();
        advance(it2,i);
        cout << *it2 << endl;
    }
}