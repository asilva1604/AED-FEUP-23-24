#include "hospital.h"

Hospital::Hospital() { }

void Hospital::addDoctor(const Doctor& d) {
	doctors.push_back(d);
}

void Hospital::addPatient(const Patient& p) {
    patients.push_back(p);
}

void Hospital::addOldPatient(const Patient& p) {
    oldPatients.insert(p);
}

void Hospital::addStackConsultations(const stack<Consultation>& s) {
    consultations.push_back(s);
}

vector<Doctor> Hospital::getDoctors() const {
	return doctors;
}

list<Patient> Hospital::getPatients() const {
    return patients;
}

set<Patient> Hospital::getOldPatients() const {
    return oldPatients;
}

list<stack<Consultation>> Hospital::getConsultations() const {
    return consultations;
}

void Hospital::setConsultations(const list<stack<Consultation>>& consults) {
    consultations = consults;
}


// --------------------------------------------------------------------

bool comp(const Doctor &one, const Doctor &other) {
    if (one.getPatientsToAttend().size() == other.getPatientsToAttend().size()) {
        return one.getID() < other.getID();
    }
    return one.getPatientsToAttend().size() > other.getPatientsToAttend().size();
}

//TODO
void Hospital::sortDoctors() {
    std::sort(doctors.begin(), doctors.end(), comp);
}


// TODO
float Hospital::averageNPatients(string sp) const {
    vector<unsigned long> n;
    for (const auto &d : doctors) {
        if (d.getSpecialty() == sp) {
            n.push_back(d.getPatientsToAttend().size());
        }
    }
    if (n.empty()) return 0;
    float sum = 0;
    for (const auto &i : n) sum = sum + (float)i;
    return sum / (float)n.size();
}


// TODO
int Hospital::removePatients(int minC) {
    int count = 0;
    list<Patient> temp;
    for (const auto &p : patients) {
        if (p.getNumConsultations() < minC) {
            count++;
            continue;
        }
        temp.push_back(p);
    }
    patients = temp;

    return count;
}


// TODO
vector<Patient> Hospital::getOldPatients(int y) const {
    vector<Patient> res;
    for (const auto &p : oldPatients) {
        if (p.getLastConsultationYear() < y) {
            res.push_back(p);
        }
    }
    return res;
}


// TODO
void Hospital::processConsultation(Consultation c) {
    for (auto &s : consultations) {
        if (s.top().getSpecialty() == c.getSpecialty()) {
            s.push(c);
            return;
        }
    }
    stack<Consultation> n;
    n.push(c);
    consultations.push_back(n);
}


// TODO
bool Hospital::addDoctor(int id2, string sp2, int id1) {
    Doctor d(id2, sp2);
    auto it = find_if(doctors.begin(), doctors.end(), [id1](const Doctor &d) {
        return d.getID() == id1;
    });
    if (it == doctors.end() || it->getSpecialty() != sp2) {
        doctors.push_back(d);
        return false;
    }
    auto id1toAttend = it->getPatientsToAttend();
    int counter = 0;
    queue<Patient> n;
    while (!id1toAttend.empty()) {
        if (counter % 2 == 0) {
            n.push(id1toAttend.front());
            id1toAttend.pop();
            counter++;
            continue;
        }
        d.addPatientToAttend(id1toAttend.front());
        id1toAttend.pop();
        counter++;
    }
    it->setPatientsToAttend(n);
    doctors.push_back(d);
    return true;
}
