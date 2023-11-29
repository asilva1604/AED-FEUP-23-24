#include "patient.h"

Patient::Patient(int id, int n, int lcy): idPatient(id), numConsultations(n), lastConsultationYear(lcy)
{}

int Patient::getID() const {
    return idPatient;
}

int Patient::getNumConsultations() const {
    return numConsultations;
}

int Patient::getLastConsultationYear() const {
    return lastConsultationYear;
}

// --------------------------------------------------------------------

//TODO
bool Patient::operator<(const Patient &p2) const {
    if (this->lastConsultationYear == p2.getLastConsultationYear()) {
        return this->idPatient < p2.getID();
    }
    return this->lastConsultationYear < p2.getLastConsultationYear();
}