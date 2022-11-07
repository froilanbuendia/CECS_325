#include <map>
#include <iomanip>
#include <regex>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string clean(const string& s){
    regex alpha("^[a-zA-Z]");
    string r = "";
    int count = 0;
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
    int count = 0;
	// vector<string> words;
    // map <string, int>::iterator mit; // pointer iterator
    // map <string, int> dictionary;
    map <string, int> misspelled;
    unordered_set <string> dict_set;
    regex reg("^[a-zA-Z]+[\'][a-zA-Z]{0,1}|^[a-zA-Z]+[a-zA-Z-]+");
    regex firstCharAlpha("^[a-zA-Z]");
    ifstream fin;
    fin.open (argv[1]);
    while  (fin >> dict){
        dict_set.insert(dict);
    }
    fin.close();
    fin.open(argv[2]);
    while (fin >> word){
        // regex apostrophe ("^[a-zA-Z]+[\'][a-zA-Z]{0,1}");
        // regex hyphen ("^([a-zA-Z])+([a-zA-Z-]+)");
        regex line ("^[-]{0,100}");
        regex alpha ("^[a-zA-Z]+");
        word = clean(word);
        if (word != ""){
            auto pos = misspelled.find(word);
            if (dict_set.count(word) == 0){
                if (regex_match(word, alpha)){
                    if (pos == misspelled.end()){
                        misspelled[word] = 1;
                    }else{
                        pos -> second++;
                    }
                    count++;

                }else if((!regex_match(word, reg) && !regex_match(word, line))){
                    if (pos == misspelled.end()){
                        misspelled[word] = 1;
                    }else{
                        pos -> second++;
                    }
                    count++;
                }
            }   
        }
    }
    fin.close();
    cout << "Misspelled Words: " << count << endl;
    for (auto p = misspelled.begin(); p!= misspelled.end(); p++){
        cout << setw(20) << left << p -> first << setw(10) << right << p -> second << endl;
    }
    return 0;
}