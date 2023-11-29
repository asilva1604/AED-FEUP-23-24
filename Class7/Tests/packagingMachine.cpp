#include "packagingMachine.h"

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
	return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
	return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
	return this->boxes;
}

//=============================================================================
// Exercise 1: Packaging
//=============================================================================
// Subexercise 1.1: Load Objects
//=============================================================================
// TODO
unsigned PackagingMachine::loadObjects(std::vector<Object> &objs) {
    unsigned res = 0;
    auto it = objs.begin();

    while (it != objs.end()) {
        if (it->getWeight() <= this->boxCapacity) {
            // Load object into the priority queue based on priority (heaviest first)
            objects.push(*it);
            // Remove the loaded object from the objs vector
            it = objs.erase(it);
            res++;
            continue;
        }
        it++;
    }
    return res;
}


//=============================================================================
// Subexercise 1.2: Search Box
//=============================================================================
// TODO
Box PackagingMachine::searchBox(Object& obj) {
    HeapBox

    return Box(0);
}



//=============================================================================
// Subexercise 1.3: Pack Objects
//=============================================================================
// TODO
unsigned PackagingMachine::packObjects() {
	return 0;
}


//=============================================================================
// Subexercise 1.4: Box with More Objects
//=============================================================================
// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;
	return res;
}
