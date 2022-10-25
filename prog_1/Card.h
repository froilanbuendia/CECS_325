// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 1 – Solitaire Fibonacci)
// Due Date 09/19/2022
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#ifndef CARD_H
#define CARD_H

class Card{
    //have char rank and char suit private
    private:
        char suit;
        char rank;
    public:
        Card();

        Card(char, char);

        void setCard(char, char);

        int getValue();

        void display();
};
#endif