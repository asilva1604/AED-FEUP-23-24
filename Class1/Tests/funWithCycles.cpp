#include "funWithCycles.h"
//=============================================================================
// Exercise 1: Palindromes
//=============================================================================
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    unsigned length = s.size();
    for (unsigned i = 0; i < length/2; i++)
        if (s[i] != s[length-i-1])
            return false;
    return true;
}


//=============================================================================
// Exercise 2: Palindrome Sentences
//=============================================================================
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    std::string strippedS;
    for (const auto &c : s) {
        if (c != ' ') {
            if (std::isalpha(c))
                strippedS.push_back(std::tolower(c));
        }
    }
    return palindrome(strippedS);
}


//=============================================================================
// Exercise 3: Interesting Numbers
//=============================================================================
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    while (true) {
        n++;
        if (digitSum(n) == sum) return n;
    }
}

// This auxiliary function should return the sum of the digits of n
// TODO
int FunWithCycles::digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}


//=============================================================================
// Exercise 4: Winter is coming
//=============================================================================
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    vector<int> seq;
    int counter = 1;
    bool flag = false;
    for (size_t i = 1; i < v.size(); i++) {
        if (v.at(i) < v.at(i-1)) {
            flag = true;
            counter++;
        }
        else if (flag) {
            flag = false;
            seq.push_back(counter);
            counter = 1;
        }
    }

    if (flag) seq.push_back(counter);
    if (seq.empty()) return 0;

    std::sort(seq.begin(), seq.end());
    return seq.at(seq.size()-1)-1;
}

// 5 4 3 6

//=============================================================================
// Exercise 5: Playing with vectors
//=============================================================================

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    int count = 0;
    for (const auto &a : v) {
        if (a == n) {
           count++;
        }
    }
    return count;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {

}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    return ans;
}


//=============================================================================
// Exercise 6: Playing with prime numbers
//=============================================================================

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    return false;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    return ans;
}
