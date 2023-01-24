#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main(){
    list<int> cardDecks;
    int x;
    while(cin >> x && x != 0){
        cardDecks.push_back(x);
    }

    list<int>::iterator it = cardDecks.begin();

    while(it != cardDecks.end()){
        list<int> cardDeck;
        for (int i = 1; i <= *it; i++){
            cardDeck.push_back(i);
        }

        if (cardDeck.size() == 1){
            cout << "Discarded cards:" << endl;
            cout << "Remaining card: " << cardDeck.front() << endl;
            it++;
            continue;
        }
        
        cout << "Discarded cards: " << cardDeck.front();
        cardDeck.pop_front();
        cardDeck.push_back(cardDeck.front());
        cardDeck.pop_front();

        while(cardDeck.size() > 1){
            cout << ", " << cardDeck.front();
            cardDeck.pop_front();
            cardDeck.push_back(cardDeck.front());
            cardDeck.pop_front();
        }

        cout << endl << "Remaining card: " << cardDeck.front() << endl;
        it++;
    } 
    return 0;
}