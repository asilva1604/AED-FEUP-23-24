#include "doctor.h"

Doctor::Doctor(int id, string sp): idDoctor(id), specialty(sp)
{}

int Doctor::getID() const {
	return idDoctor;
}

string Doctor::getSpecialty() const {
	return specialty;
}

queue<Patient> Doctor::getPatientsToAttend() const {
	return toAttend;
}

void Doctor::setSpecialty(string sp) {
    specialty = sp;
};

void Doctor::setPatientsToAttend(queue<Patient> toAtt) {
    toAttend = toAtt;
}

void Doctor::addPatientToAttend(const Patient& p1) {
	toAttend.push(p1);
}


//--------------------------------------------------------------------------

//TODO
void Doctor::moveToFront(int idP) {
    queue<Patient> n;
    queue<Patient> temp1;
    queue<Patient> temp2;
    bool flag = false;
    while (!toAttend.empty()) {
        if (toAttend.front().getID() == idP) {
            n.push(toAttend.front());
            toAttend.pop();
            flag = true;
            continue;
        }
        if (flag) {
            temp2.push(toAttend.front());
            toAttend.pop();
            continue;
        }
        temp1.push(toAttend.front());
        toAttend.pop();
    }
    while (!temp1.empty()) {
        n.push(temp1.front());
        temp1.pop();
    }
    while (!temp2.empty()) {
        n.push(temp2.front());
        temp2.pop();
    }
    toAttend = n;
}
