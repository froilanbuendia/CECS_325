#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(){
    map <string, int>::iterator mit; // pointer iterator
    map <string, int> dictionary;
    map <string, int> misspelled;

    mit = dictionary.begin();
    while (mit != dictionary.end()){ // take u all the way to the end
        cout << mit -> first;
        mit++;
    }

    for (auto mit = dictionary.begin(); mit != dictionary.end(); mit++){
        cout << mit -> first << ":" << mit -> second << endl;
    }



}