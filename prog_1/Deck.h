// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 1 – Solitaire Fibonacci)
// Due Date 09/19/2022
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
# include <iostream>
# include "Card.h"
#ifndef DECK_H
#define DECK_H
using namespace std;

class Deck{
    //have char rank and char suit private
    private:
        Card store[52];
        int count;
    public:
        Deck();

        void refreshDeck();

        Card deal();

        void shuffle();

        bool isEmpty();

        void display();
};
#endif