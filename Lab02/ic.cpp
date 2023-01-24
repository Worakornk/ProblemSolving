#include <iostream>
#include <list>
using namespace std;

int main(){
    int n,value;
    cin >> n;
    list<int> mylist;
    string cmd;
    for (int i = 0; i<n; i++){
        cin >> cmd;
        if (cmd == "li"){
            cin >> value;
            mylist.push_front(value);
        } else if (cmd == "ri"){
            cin >> value;
            mylist.push_back(value);
        } else if (cmd == "lr" && mylist.size() > 0){
            int temp = mylist.front();
            mylist.push_back(temp);
            mylist.pop_front();
        } else if (cmd == "rr" && mylist.size() > 0){
            int temp = mylist.back();
            mylist.push_front(temp);
            mylist.pop_back();
        }
    }
    for (auto i : mylist){
        cout << i << endl;
    }
    return 0;
}