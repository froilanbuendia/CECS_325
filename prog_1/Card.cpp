// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 1 – Solitaire Fibonacci)
// Due Date 09/19/2022
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include "Card.h"
using namespace std;

Card::Card(){};
Card::Card(char r, char s){
    //have char rank and char suit private
    rank = r;
    suit = s;
}

void Card::setCard(char r, char s){
    rank = r;
    suit = s;
}

int Card::getValue(){
    if (rank == 'A'){
        return 1;
    }else if(rank == '2'){
        return 2;
    }else if(rank == '3'){
        return 3;
    }else if(rank == '4'){
        return 4;
    }else if(rank == '5'){
        return 5;
    }else if(rank == '6'){
        return 6;
    }else if(rank == '7'){
        return 7;
    }else if(rank == '8'){
        return 8;
    }else if(rank == '9'){
        return 9;
    }else{
        return 10;
    }
}

void Card::display(){
    if (rank == '1'){
        cout<<rank<<'0'<<suit<< " ";
    }else{
        cout<<rank<<suit<< ", ";
    }
}