#include<bits/stdc++.h>

using namespace std;

struct necklace {
  int number ;
  necklace* prev;
  necklace* next;
};

int main() {
  int num ;
  cin>> num ;

  necklace node[num];
  for (int i=0; i<num ; i++){
    node[i].number = i+1;
    node[i].prev = NULL;
    node[i].next = NULL;
  }

  for (int i=0; i< num-1 ; i++){
    int x , y;
    cin>> x;
    cin>> y;

    int m = x-1;
    int n = y-1;

    necklace* temp = NULL;
    if ( node[n].next != NULL) {
      temp = node[n].next;
    }

    node[n].next = &node[m];
    node[m].prev = &node[n];
    necklace* last = &node[m];
    while ((*last).next != NULL)
    {
      last = (*last).next;
    }
    
    last->next = temp;
  }

  necklace* head = &node[0];
  while (head->prev != NULL){
    head = head->prev;
  }
  while (head->next != NULL)
  {
    cout << head->number << " ";
    head =  head->next;
  }
    cout<< head->number;
}