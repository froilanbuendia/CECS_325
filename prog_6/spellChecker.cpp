// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 6 – Spell Checker)
// Due Date (11/09/2022)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <map>
#include <iomanip>
#include <regex>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string clean(const string& s){// removes all punctations except for ' and - as well as makes all letters lowercase
    string r = "";
    for (int i = 0; i < s.length(); i++){
        char c = s[i];
        if ('a' <= c && c <= 'z'){
            r = r + c;
        }else if ('A' <= c && c <= 'Z'){
            c = c - 'A' + 'a';
            r = r + c;
        }else if('-' == c){
            r = r + c;
        }else if ('\'' == c){
            r = r + c;
        }
    }
    return r;
}
int main(int argc, char *argv[]){
    string dict;
    string word;
    // int count = 0;
    map <string, int> misspelled;
    unordered_set <string> dict_set;
    // regex reg("^[a-z]+[\'][a-z]{0,1}|^[a-z]+[a-z-]+");
    // regex reg("^[a-z]+[\'][a-z]{0,1}|^[a-z]+[a-z-]+|^[a-z]+'-+[a-z]+|^[a-z]+-[a-z]+'[a-z]");
    // regex reg("^[a-zA-Z]+[\'][a-zA-Z]{0,1}|^[a-zA-Z]+[a-zA-Z-]+|^'[a-zA-Z-]+'|-+[a-zA-Z]+|^'[a-zA-Z]+|'-|^'[a-zA-Z]'+[[a-zA-Z-]+|^-'|^\'[a-zA-Z]+\'-+[a-zA-Z]+|-[a-zA-Z]+-|^-[a-zA-Z]'|^[a-zA-Z]'[a-zA-Z]'|^[a-zA-Z]'[a-zA-Z]'[a-zA-Z]'|^[a-zA-Z]+-[a-zA-Z]+'[a-zA-Z]+|^[a-zA-Z]+'-+[a-zA-Z]+");
    regex reg("[a-z]+\'?-*[a-z]*");
    regex punct("[^-'a-z]");
    ifstream fin;
    // inserts the dictionary items into unordered sets
    fin.open (argv[1]);
    while  (fin >> dict){
        dict = clean(dict); // cleans dict so everything is lowercase
        dict_set.insert(dict);
    }
    fin.close();
    fin.open(argv[2]);
    //reads through flatland.txt
    while (fin >> word){
        transform(word.begin(),word.end(),word.begin(),::tolower); // changes word to lowercase
        for (int i = 0; i < word.size(); i++){
            word = regex_replace(word, punct, "");
        }
        if (word != ""){ // checks if word isn't empty after cleaning
            auto pos = misspelled.find(word);
            // checks if word is isn't in the dictionary
            if (dict_set.count(word) == 0 && (regex_match(word, reg))){
                if (pos == misspelled.end()){
                        misspelled[word] = 1;
                    }else{
                        pos -> second++;
                    }
            }   
        }
    }
    fin.close();
    // cout << "Misspelled Words: " << count << endl;
    cout << "Misspelled Words: " << '(' << misspelled.size() << ')' << endl; // outputs size of misspelled words
    // outputs all the mispelled words
    for (auto p = misspelled.begin(); p!= misspelled.end(); p++){ // outputs misspelled words and frequency
        cout << setw(20) << left << p -> first << setw(10) << right << p -> second << endl;
    }
    return 0;
}