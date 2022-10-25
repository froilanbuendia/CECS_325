// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 1 – Solitaire Fibonacci)
// Due Date 09/19/2022
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
# include <iostream>
# include "Deck.h"
# include <cstdlib>
using namespace std;

char r[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};
char s[4] = {'S', 'H', 'D', 'C'};
Deck::Deck() {
    count = 0;
    int i = 0;
    for (int j = 0; j < 4; j++){
        for (int k = 0; k < 13; k++){
            store[i] = Card(r[k], s[j]);
            i += 1;
        }
    }
    
}

void Deck::refreshDeck(){
    count = 0;
    int i = 0;
    for (int j = 0; j < 4; j++){
        for (int k = 0; k < 13; k++){
            store[i] = Card(r[k], s[j]);
            i += 1;
        }
    }
}

Card Deck::deal(){
    //uses count
    return store[count++];
}

void Deck::shuffle(){
    //generate a random number
    //swap 2 random cards
    //use a for loop
    int x = rand() % (52 - count);
    int y = rand() % (52 - count);
    Card temp = store[x];
    store[x] = store[y];
    store[y] = temp;
}

bool Deck::isEmpty(){
    //uses count
    if (count == 52) {
        return true;
    }
    return false;
}

void Deck::display(){
    int i = 0;
    for (int j = 0; j < 4; j++){
        for (int k = 0; k < 13; k++){
            if (k == 12){
                store[i].display();
            }else{
                store[i].display();
            }
            i++;
        }
    cout << endl;
    }
}
