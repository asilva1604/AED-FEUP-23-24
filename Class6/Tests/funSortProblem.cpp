#include "funSortProblem.h"

FunSortProblem::FunSortProblem() {}


//=============================================================================
// Exercise 4: Min Difference
//=============================================================================
// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (nc > values.size()) return -1;
    auto v = values;
    std::sort(v.begin(), v.end());
    return (int)v.at(nc-1) - (int)v.at(0);
}


//=============================================================================
// Exercise 6: Num Inversions (extra)
//=============================================================================
//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    return 0;
}


//=============================================================================
// Exercise 7: Nuts and Bolts (extra)
//=============================================================================
// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}
