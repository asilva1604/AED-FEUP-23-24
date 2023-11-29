#include <iostream>
#include <string>
#include <fstream>
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

bool WordMean::operator==(const WordMean &other) const {
    if (this->word == other.getWord()) {
        return true;
    }
    return false;
}

//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
//TODO
void Dictionary::readFile(ifstream &f) {
    string w;
    string m;
    while (getline(f, w)) {
        getline(f, m);
        WordMean wm(w,m);
        words.insert(wm);
    }
}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
//TODO
void Dictionary::print() const {
    for (const auto &wm : words) {
        cout << wm.getWord() << "\n" << wm.getMeaning() << "\n";
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
    auto it = words.begin();
    while (it != words.end()) {
        if (it->getWord() == w1) {
            return it->getMeaning();
        }
        else if (it->getWord() > w1) {
            if (it == words.begin()) {
                previous = {"", ""};
                it++;
                next = *it;
                return "word not found";
            }
            next = *it;
            it--;
            previous = *it;
            return "word not found";
        }
        it++;
    }
    next = {"", ""};
    it--;
    previous = *it;
    return "word not found";
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
//TODO
bool Dictionary::update(string w1, string m1) {
    auto it = words.find({w1, ""});
    if (it == words.end()) {
        words.insert({w1, m1});
        return false;
    }
    WordMean n = {w1, m1};
    words.erase(it);
    words.insert(n);
    return true;
}
