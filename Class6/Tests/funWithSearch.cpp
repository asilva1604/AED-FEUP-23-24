#include "funWithSearch.h"


//=============================================================================
// Exercise 1: Elementary Search
//=============================================================================
// Subexercise 1.1: Linear Search
//=============================================================================
// TODO
int FunWithSearch::searchLinear(const vector<int> &v, int key) {
    for (unsigned i=0; i<v.size(); i++)
        if (v[i] == key)
            return i; // key found at index i
    return -1; // key not found
}

//=============================================================================
// Subexercise 1.2: Binary Search
//=============================================================================
// TODO
int FunWithSearch::searchBinary(const vector<int> & v, int key) {
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key < v[middle]) high = middle - 1;
        else if (key > v[middle]) low = middle + 1;
        else return middle; // key found at index middle
    }
    return -1; // key not found
}

//=============================================================================
// Exercise 2: Facing Sun
//=============================================================================
// TODO
int FunWithSearch::facingSun(const vector<int> & values) {
    int height = values.at(0);
    int count = 1;

    for (int i = 1; i < values.size(); i++) {
        if (values.at(i) > height) {
            height = values.at(i);
            count++;
        }
    }
    return count;
}


//=============================================================================
// Exercise 3: Square Root
//=============================================================================
// TODO
int FunWithSearch::squareR(int num) {
    int current = 0;
    while (current < num) {
        if (current*current == num) {
            return current;
        }
        else if (current*current > num) {return current-1;}
        current++;
    }

    return 0;
}


//=============================================================================
// Exercise 5: MinPages (extra)
//=============================================================================
// TODO
int FunWithSearch::minPages(const vector<int> & values, int numSt) {
    return 0;
}
