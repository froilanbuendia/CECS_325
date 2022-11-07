#include <map>
#include <iomanip>
#include <regex>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string word;
	vector<string> words;
	map <string, int> misspelled;
	regex reg("[a-z]+\'*[a-z]+");  // this will match any word with 0 or more apostophes
	ifstream fin;
	fin.open (argv[2]);
	cout << "\nFirst pass\n";
	while (fin >> word)
	{
		words.push_back(word);
	    if (regex_match(word,reg))
	    	cout << "match:"<<word<<endl;
	    else
	    	cout << "no match:"<<word<<endl;
		
	}

	cout << "\nSecond pass\n";
	regex punct("\"");  // now I an declaring a regex object with a double quote... \""
	for(int i=0; i<words.size(); i++)
	{
		word = regex_replace(words[i], punct, ""); // I replace teh double quote with nothing
													// in other words, remove or delete all double quotes
	
		if (regex_match(word,reg))
	    	cout << "match:"<<word<<endl;
	    else
	    	cout << "no match:"<<word<<endl;
		
	}

	cout << "\nThird pass\n";
	regex exclaim("!");  // create a regex that has a period
	for(int i=0; i<words.size(); i++)
	{
		word = regex_replace(words[i], exclaim, ""); // remove all teh periods
	
		if (regex_match(word,reg))
	    	cout << "match:"<<word<<endl;
	    else
	    	cout << "no match:"<<word<<endl;
			auto pos = misspelled.find(word);
            if (pos == misspelled.end()){
                misspelled[word] = 1;
            }else{
                pos -> second++;
            }
	}
	cout << "Misspelled Words: " << misspelled.size() << endl;
    for (auto p = misspelled.begin(); p!= misspelled.end(); p++){
        cout << setw(20) << left << p-> first << setw(10) << right << p -> second << endl;
    }
	
}
