// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 1 – Solitaire Fibonacci)
// Due Date 09/19/2022
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include "Card.cpp"
#include "Deck.cpp"
using namespace std;

 
bool isFibo(int num){
    if (num == 0 || num == 1 || num == 2 || num == 3 || num == 5 || num == 8 || num == 13 || num == 21 || num == 34 || num == 55 || num == 89 || num == 144 || num == 233){
        return true;
    }
    return false;
}

int main() {
    //objects and variables
    Deck deck;
    Card pile[52];
    int games = 1;
    bool valid = true;
    bool last = false;
    cout <<"Welcome to Fibonacci Solitaire" << endl;
    do{
        int userValue;
        cout << "1) New Deck\n2) Display\n3) Shuffle Deck\n4) Play Solitaire\n5) Exit" << endl;
        cin >> userValue;
        cout << endl;
        //refreshes deck
        if (userValue == 1){
            if (deck.isEmpty() == true){
                cout << "Refreshing Deck..." << endl;
                deck.refreshDeck();
                cout << endl;
            }else{
                cout << "You already have a deck" << endl;
            }
        //must have a deck to display
        }else if (userValue == 2){
            if (deck.isEmpty() == true){
                cout << "No deck to display, please refresh deck first." << endl;
            }else{
                cout << "Displaying Deck..." << endl;
                deck.display();
            }
        //must have a deck to shuffle
        }else if (userValue == 3){
            if (deck.isEmpty() == true){
                cout << "Create a new deck before shuffling" << endl;
            }else{
                cout << "Shuffling..." << endl;
                for (int i = 0; i < 100; i++){
                    deck.shuffle();
                }
            }
            cout << endl;
        //must have a deck to play solitaire
        }else if (userValue == 4){
            if (deck.isEmpty() == true){
                cout << "Please get a new deck to continue." << endl;
            }else{
                int sum = 0;
                int curr = 0;
                int piles = 0;
                cout << "Playing Fibonacci Solitaire" << endl;
                cout << endl;
                while (curr < 52){
                    pile[curr++] = deck.deal();
                }
                piles += 1;
                for (int i = 0; i < 52; i ++){
                    pile[i].display();
                    sum += pile[i].getValue();
                    if (isFibo(sum) == true){
                        piles += 1;
                        cout << "Fibo: " << sum  << endl;
                        sum = 0;
                        if(i == 51){
                            last = true;
                        }
                    }
                }  
                if (isFibo(sum) == true){
                    cout << "Winner in " << piles << " piles" << endl;
                }else{
                    cout << endl << "Last hand value: " << sum << endl;
                    cout << endl << "Loser in " << piles << " piles" << endl;
                }
                cout << "Games played: " << games++ << endl;
            }
            cout << endl;
        //ends game
        }else if (userValue == 5){
            cout << "Thanks for Playing!!!" << endl;
            valid = false;
        }else{
            cout << "Invalid Input" << endl;
            valid = false;
        }
        cout << endl;
    }while(valid == true);
}