#include "funSetProblem.h"

FunSetProblem::FunSetProblem() {}


//=============================================================================
// Exercise 2: FunSetProblem
//=============================================================================
// TODO
pair<int, int> FunSetProblem::pairSum(const vector<int> &values, int sum) {
    set<int> s;

    for (const auto &i : values) {
        int complement = sum - i;
        if (s.find(complement) != s.end()) {
            return make_pair(i, complement);
        }
        s.insert(i);
    }

    return make_pair(0, 0);
}
