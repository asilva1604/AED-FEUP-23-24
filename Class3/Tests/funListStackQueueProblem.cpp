#include "funListStackQueueProblem.h"
#include "cell.h"

FunListStackQueueProblem::FunListStackQueueProblem() {}


//=============================================================================
// Exercise 1: Remove Higher
//=============================================================================
// TODO
list<int> FunListStackQueueProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    auto it = values.begin();
    while (it != values.end()) {
        if (*it > x) {
            l1.push_back(*it);
            it = values.erase(it);
            continue;
        }
        it++;
    }
    return l1;
}

//=============================================================================
// Exercise 2: Overlapping Intervals
//=============================================================================
//TODO
list<pair<int,int>> FunListStackQueueProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int,int>> res;
    values.sort();
    auto it = values.begin();
    int start = it->first;
    int end = it->second;
    it++;
    while (it != values.end()) {
        if (it->first <= end) {
            end = it->second;
        } else {
            res.emplace_back(start, end);
            start = it->first;
            end = it->second;
        }
        it++;
    }
    res.emplace_back(start, end);
    return res;
}


//=============================================================================
// Exercise 4: Binary Numbers
//=============================================================================
// TODO
vector<string> FunListStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    queue<string> q;
    q.emplace("1");\

    while (n--) {
        string curr = q.front();
        q.pop();

        res.push_back(curr);

        q.push(curr + "0");
        q.push(curr + "1");
    }
    return res;
}


//=============================================================================
// Exercise 5: Calculate Span
//=============================================================================
//TODO
vector<int> FunListStackQueueProblem::calculateSpan(vector<int> prices) {
    vector<int> res;
    return res;
}


//=============================================================================
// Exercise 7: Knight Jumps
//=============================================================================
//TODO
int FunListStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}
