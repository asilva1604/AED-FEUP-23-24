#ifndef PACKAGINGMACHINE_H_
#define PACKAGINGMACHINE_H_

#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include "box.h"

using namespace std;

struct CompareObjectPriority {
    bool operator()(const Object &obj1, const Object &obj2) {
        return obj1.getWeight() < obj2.getWeight();
    }
};

typedef priority_queue<Object, vector<Object>, CompareObjectPriority> HeapObj;
typedef priority_queue<Box> HeapBox;

class PackagingMachine {
	HeapObj objects;
	HeapBox boxes;
	unsigned boxCapacity;
public:
	PackagingMachine(int boxCap = 10);
	unsigned numberOfBoxes();
	unsigned addBox(Box& b1);
    HeapObj getObjects() const;
    HeapBox getBoxes() const;

	unsigned loadObjects(vector<Object> &objs);
	Box searchBox(Object& obj);
	unsigned packObjects();
	stack<Object> boxWithMoreObjects() const;
};

#endif
