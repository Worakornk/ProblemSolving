#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct necklace{
    int value;
    necklace *next;
    necklace *prev;
};

vector<necklace> createNecklace(int n){
    vector<necklace> myArray(n);
    for (int i=0; i<n; i++){
        necklace temp;
        temp.value = i+1;
        temp.next = NULL;
        temp.prev = NULL;
        myArray[i] = temp;
    }
    return myArray;
}

int main(){
    int n;
    cin >> n;
    vector<necklace> myArray;
    myArray = createNecklace(n);
    for (int i=0; i<n-1 ; i++){
        int startWith, endWith;
        cin >> startWith >> endWith;
        int realStart = startWith - 1;
        int realEnd = endWith - 1;

        necklace* temp = NULL;
        if (myArray[realEnd].next != NULL){
            temp = myArray[realEnd].next;
        }

        myArray[realEnd].next = &myArray[realStart];
        myArray[realStart].prev = &myArray[realEnd];
        necklace* last = &myArray[realStart];
        while (last->next != NULL){
            last = last->next;
        }
        last->next = temp;
    }

    necklace* head = &myArray[0];
    while (head->prev != NULL){
        head = head->prev;
    }
    while (head->next != NULL){
        cout << head->value << " ";
        head = head->next;
    }
    cout << head->value;
    return 0;
}