#include <iostream>
#include <iterator>
#include <list>
using namespace std;

list<int> mylist[100010];

int main(){
    int M;
    cin >> M;
    for(int i=0; i<M; i++){
        char cmd;
        int v1, v2;
        cin >> cmd >> v1 >> v2;
        if (cmd == 'N'){
            mylist[v2].push_back(v1);
        }
        else if (cmd == 'M'){
            mylist[v2].splice(mylist[v2].end(), mylist[v1]);
        }
    }
    for (auto j : mylist){
        for (auto i : j){
            cout << i << endl;
        }
    }
    return 0;
}