/*
    Task	: 01_fin62_name
    Author	: First
    School	: KU
    Language: C++
    Created	: 26 January 2023 [14:47]
    Algo	: 
    Status	: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    string word,sentence;
    cin >> word;
    cin >> sentence;
    int count = 0;
    int j = 0;
    for (int i = 0; i < sentence.length(); i++){
        if (sentence[i] == word[j]){
            j++;
            if (j == word.length()){
                count++;
                j = 0;
            }
        }
    }
    cout << count;
    return 0;
}