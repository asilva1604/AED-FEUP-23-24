#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}


//=============================================================================
// Exercise 1: Dictionary
//=============================================================================
//TODO
bool WordMean::operator< (const WordMean& wm2) const {
     return this->word < wm2.getWord();
}

//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
//TODO
void Dictionary::readFile(ifstream &f) {
    string word;
    while (getline(f, word)) {
        string mean;
        getline(f, mean);
        words.emplace(word, mean);
    }
}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
//TODO
void Dictionary::print() const {
    for (const auto &p : words) {
        cout << p.getWord() << "\n" << p.getMeaning() << "\n";
    }
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    if (words.empty()) {
        previous = {"", ""};
        next = {"", ""};
        return "word not found";
    }
    auto it = find_if(words.begin(),
                      words.end(),
                      [w1](const WordMean &w) {
        return w1 == w.getWord();
    });
    if (it != words.end()) return it->getMeaning();
    
    return "";
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
//TODO
bool Dictionary::update(string w1, string m1) {
    return true;
}
