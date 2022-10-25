// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 1 – Solitaire Fibonacci)
// Due Date 09/19/2022
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
using namespace std;

class Card{
    private:
        char suit;
        char rank;
    public:
        Card();
        Card(char r, char s);
        void setCard(char r, char s);
        int getValue();
        void display();
    
};
Card::Card(){};
Card::Card(char r, char s){
    //have char rank and char suit private
    rank = r;
    suit = s;
};

void Card::setCard(char r, char s){
    rank = r;
    suit = s;
};

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
};

void Card::display(){
    if (rank == '1'){
        cout<<rank<<'0'<<suit<< " ";
    }else{
        cout<<rank<<suit<< ", ";
    }
};

class Deck{
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

Deck::Deck(){
    char r[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};
    char s[4] = {'S', 'H', 'D', 'C'};
    count = 0;
    int i = 0;
    for (int j = 0; j < 4; j++){
        for (int k = 0; k < 13; k++){
            store[i] = Card(r[k], s[j]);
            i += 1;
        }
    }
};

void Deck::refreshDeck(){
    char r[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};
    char s[4] = {'S', 'H', 'D', 'C'};
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

 
bool isFibo(int num){
    if (num == 0 || num == 1 || num == 2 || num == 3 || num == 5 || num == 8 || num == 13 || num == 21 || num == 34 || num == 55 || num == 89 || num == 144 || num == 233){
        return true;
    }
    return false;
}

int main() {
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
        if (userValue == 1){
            if (deck.isEmpty() == true){
                cout << "Refreshing Deck..." << endl;
                deck.refreshDeck();
                cout << endl;
            }else{
                cout << "You already have a deck" << endl;
            }
        }else if (userValue == 2){
            if (deck.isEmpty() == true){
                cout << "No deck to display, please refresh deck first." << endl;
            }else{
                cout << "Displaying Deck..." << endl;
                deck.display();
            }
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