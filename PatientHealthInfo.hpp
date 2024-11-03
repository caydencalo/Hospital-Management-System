#pragma once
#include "PatientLoginData.hpp"

/**************************************************************************************************
 * PatientHealthInfo class will contain the patient health attributes (first name, last name, height, weight,
 * blood type, etc. All attributes are accessible in the portal once the patient/doctor is logged in correctly.
 **************************************************************************************************/
class PatientHealthInfo {
public:
    PatientHealthInfo(); //Constructor
    //~PatientHealthInfo(); //Destructor
    PatientHealthInfo(const string &newFirstName, const string &newLastName, const string &newHeight,
                      const string &newWeight, const string &newBloodType, const string &newAge,
                      const string &newOccupation, const string &newBloodPressure,
                      const string &newTemperature, const string &newPulse, const string &newAllergies,
                      const string &newFamilyConditions, const string &newMedications,
                      const string &newExistingConditions, const int newRecordNumber);

    //Getters for all patient health attributes
    string getFirstName() const;
    string getLastName() const;
    string getHeight() const;
    string getWeight() const;
    string getBloodType() const;
    string getAge() const;
    string getOccupation() const;
    string getBloodPressure() const;
    string getTemperature() const;
    string getPulse() const;
    string getAllergies() const;
    string getFamilyConditions() const;
    string getMedications() const;
    string getExistingConditions() const;
    int getRecordNumber() const;

    //Getters for all patient health attributes
    void setFirstName(const string &newFirstName);
    void setLastName(const string &newLastName);
    void setHeight(const string &newHeight);
    void setWeight(const string &newWeight);
    void setBloodType(const string &newBloodType);
    void setAge(const string &newAge);
    void setOccupation(const string &newOccupation);
    void setBloodPressure(const string &newBloodPressure);
    void setTemperature(const string &newTemperature);
    void setPulse(const string &newPulse);
    void setAllergies(const string &newAllergies);
    void setFamilyConditions(const string &newFamilyConditions);
    void setMedications(const string &newMedications);
    void setExistingConditions(const string &newExistingConditions);
    void setRecordNumber(int newRecordNumber);

private:
    PatientFullName mName;
    string mHeight, mOccupation, mBloodPressure, mTemperature, mAllergies, mFamilyConditions,
            mMedications, mExistingConditions, mWeight, mAge, mPulse, mBloodType;
    int mRecordNumber;
};

//General Program:
void importPatientMedicalList(List<PatientHealthInfo> &masterList);
int patientMenuDisplay();
void patientPortalMenu();
void patientInputsMedicalInfo(List<PatientHealthInfo> &masterList);

PatientHealthInfo::PatientHealthInfo() { //Constructor
    mName.firstName = "";
    mName.lastName = "";
    mHeight = "";
    mOccupation = "";
    mBloodPressure = "";
    mTemperature = "";
    mAllergies = "";
    mFamilyConditions = "";
    mMedications = "";
    mExistingConditions = "";
    mWeight = "";
    mAge = "";
    mPulse = "";
    mBloodType = "";
    mRecordNumber = 0;
}

PatientHealthInfo::PatientHealthInfo(const string &newFirstName, const string &newLastName, const string &newHeight,
                                     const string &newWeight, const string &newBloodType, const string &newAge,
                                     const string &newOccupation, const string &newBloodPressure,
                                     const string &newTemperature, const string &newPulse, const string &newAllergies,
                                     const string &newFamilyConditions, const string &newMedications,
                                     const string &newExistingConditions, const int newRecordNumber) {
    this->setFirstName(newFirstName);
    this->setLastName(newLastName);
    this->setHeight(newHeight);
    this->setWeight(newWeight);
    this->setBloodType(newBloodType);
    this->setAge(newAge);
    this->setOccupation(newOccupation);
    this->setBloodPressure(newBloodPressure);
    this->setTemperature(newTemperature);
    this->setPulse(newPulse);
    this->setAllergies(newAllergies);
    this->setFamilyConditions(newFamilyConditions);
    this->setMedications(newMedications);
    this->setExistingConditions(newExistingConditions);
    this->setRecordNumber(newRecordNumber);
}


/////////////Getters////////////
string PatientHealthInfo::getFirstName() const {
    return this->mName.firstName;
}

string PatientHealthInfo::getLastName() const {
    return this->mName.lastName;
}

string PatientHealthInfo::getHeight() const {
    return this->mHeight;
}

string PatientHealthInfo::getWeight() const {
    return this->mWeight;
}

string PatientHealthInfo::getBloodType() const {
    return this->mBloodType;
}

string PatientHealthInfo::getAge() const {
    return this->mAge;
}

string PatientHealthInfo::getOccupation() const {
    return this->mOccupation;
}

string PatientHealthInfo::getBloodPressure() const {
    return this->mBloodPressure;
}

string PatientHealthInfo::getTemperature() const {
    return this->mTemperature;
}

string PatientHealthInfo::getPulse() const {
    return this->mPulse;
}

string PatientHealthInfo::getAllergies() const {
    return this->mAllergies;
}

string PatientHealthInfo::getFamilyConditions() const {
    return this->mFamilyConditions;
}

string PatientHealthInfo::getMedications() const {
    return this->mMedications;
}

string PatientHealthInfo::getExistingConditions() const {
    return this->mExistingConditions;
}

int PatientHealthInfo::getRecordNumber() const {
    return this->mRecordNumber;
}

/////////////////Setters////////////////
void PatientHealthInfo::setFirstName(const string &newFirstName) {
    this->mName.firstName = newFirstName;
}

/////////////////Setters////////////////
void PatientHealthInfo::setLastName(const string &newLastName) {
    this->mName.lastName = newLastName;
}

void PatientHealthInfo::setHeight(const string &newHeight) {
    this->mHeight = newHeight;
}

void PatientHealthInfo::setWeight(const string &newWeight) {
    this->mWeight = newWeight;
}

void PatientHealthInfo::setBloodType(const string &newBloodType) {
    this->mBloodType = newBloodType;
}

void PatientHealthInfo::setAge(const string &newAge) {
    this->mAge = newAge;
}

void PatientHealthInfo::setOccupation(const string &newOccupation) {
    this->mOccupation = newOccupation;
}

void PatientHealthInfo::setBloodPressure(const string &newBloodPressure) {
    this->mBloodPressure = newBloodPressure;
}

void PatientHealthInfo::setTemperature(const string &newTemperature) {
    this->mTemperature = newTemperature;
}

void PatientHealthInfo::setPulse(const string &newPulse) {
    this->mPulse = newPulse;
}

void PatientHealthInfo::setAllergies(const string &newAllergies) {
    this->mAllergies = newAllergies;
}

void PatientHealthInfo::setFamilyConditions(const string &newFamilyConditions) {
    this->mFamilyConditions = newFamilyConditions;
}

void PatientHealthInfo::setMedications(const string &newMedications) {
    this->mMedications = newMedications;
}

void PatientHealthInfo::setExistingConditions(const string &newExistingConditions) {
    this->mExistingConditions = newExistingConditions;
}

void PatientHealthInfo::setRecordNumber(int newRecordNumber) {
    this->mRecordNumber = newRecordNumber;
}

/*****************************************************************
 * Pre-Condition:
 * Post-Condition:
 *****************************************************************/
void importPatientMedicalList(List<PatientHealthInfo> &masterList) { //Used for Management
    ifstream readFile("PatientMedicalInfo.csv");
    string line;
    getline(readFile, line); //Skips the header line

    while (getline(readFile, line)) { //Keeps reading every line of classlist.csv using setters from Data class
        stringstream ss(line);
        string field;
        PatientHealthInfo patient;

        //Record Number:
        getline(ss, field, ',');
        patient.setRecordNumber(stoi(field));

        //Last Name:
        getline(ss, field, '"');
        getline(ss, field, ',');
        patient.setLastName(field);

        //First Name:
        getline(ss, field, '"');
        patient.setFirstName(field);

        //Height:
        getline(ss, field, ',');
        getline(ss, field, ',');
        patient.setHeight(field);

        //Weight:
        getline(ss, field, ',');
        patient.setWeight(field);
        //patient.setWeight(stoi(field));

        //BloodType:
        getline(ss, field, ',');
        patient.setBloodType(field);
        //patient.setBloodType(field[0]); // Converts to char type

        //Age:
        getline(ss, field, ',');
        patient.setAge(field);
        //patient.setAge(stoi(field));

        //Occupation
        getline(ss, field, ',');
        patient.setOccupation(field);

        //Blood Pressure
        getline(ss, field, ',');
        patient.setBloodPressure(field);

        //Temperature
        getline(ss, field, ',');
        patient.setTemperature(field);

        //Pulse
        getline(ss, field, ',');
        patient.setPulse(field);
        //patient.setPulse(stoi(field));

        //Allergies
        getline(ss, field, ',');
        patient.setAllergies(field);

        //Family Conditions
        getline(ss, field, ',');
        patient.setFamilyConditions(field);

        //Medications
        getline(ss, field, ',');
        patient.setMedications(field);

        //Existing Conditions
        getline(ss, field, '\n');
        patient.setExistingConditions(field);

        masterList.insert(patient); //updates master list
    }
    readFile.close();
}

int patientMenuDisplay() { //Displays menu of what user can access
    int patientPortalOption;
    //patientPortalOption = 0;
    cout << "Please enter what you would like to display/edit... " << endl << endl;
    cout << "Patient Portal: " << endl;
    cout << "[1] - View Past Appointment Summary" << endl; //Medical Summary from previous appointment
    cout << "[2] - View Your Medical History" << endl;
    cout << "[3] - Schedule Your Next Appointment" << endl;
    cout << "[4] - View Test Results" << endl;
    cout << "[5] - View/Change Healthcare Provider" << endl;
    cout << "[6] - Log Off" << endl;

    cout << endl << "User Input: ";
    cin >> patientPortalOption;
    while (patientPortalOption != 1 && patientPortalOption != 2 && patientPortalOption != 3 && patientPortalOption != 4 && patientPortalOption != 5 && patientPortalOption != 6) {
        cout << "Error, please enter a valid input." << endl;
        cout << "User Input [1-6]: ";
        cin >> patientPortalOption;
    }
    return patientPortalOption;
}

/*****************************************************************
 * Pre-Condition:
 * Post-Condition:
 *****************************************************************/
void patientPortalMenu () {
    int patientMenuOption;
    do {
        patientMenuOption = patientMenuDisplay();
        if (patientMenuOption == 1) { //Enters if user intends to view past appointment summary
            cout << "You have entered past appointment Summary!" << endl;
        }
        if (patientMenuOption == 2) { //Enters if user intends to view medical history
            cout << "You have entered View Medial History!" << endl;
        }
        if (patientMenuOption == 3) { //Enters if user intends to schedule next appointment
            cout << "You have entered Schedule Next Appointment!" << endl;
        }
        if (patientMenuOption == 4) { //Enters if user intends to view test results
            cout << "You have entered View your Test Results!" << endl;
        }
        if (patientMenuOption == 5) { //Enters if user intends to view/change healthcare provider
            cout << "You have entered View/Change Healthcare Provider!" << endl;
        }
    } while (patientMenuOption != 6); //Leaves loop if user intentionally logs off
    cout << "You have logged out of patient portal!" << endl;
}

/*****************************************************************
 * Pre-Condition:
 * Post-Condition:
 *****************************************************************/
void patientInputsMedicalInfo(List<PatientHealthInfo> &masterList) {
    int recordNumber = 0;
    ifstream readFile("PatientMedicalInfo.csv");
    string line;
    getline(readFile, line); //Skips the header line
    while (getline(readFile, line)) { // Read each line to count records
        recordNumber++;
    }
    readFile.close();

    //Assigns the characteristics in the file
    cout << endl << "Please fill out your following Medical Information: " << endl;
    cout << "Enter NA if not know." << endl;

    //Patients Name:
    string patientsFirstName, patientsLastName;
    string patientsHeight, patientsOccupation, patientsBloodPressure, patientsTemperature, patientsAllergies;
    string patientsFamilyConditions, patientsMedications, patientsWeight, patientsAge, patientsPulse, patientsBloodType;
    string patientsExistingConditions;
    cout << "First Name: ";
    cin >> patientsFirstName;
    cout << "Last Name: ";
    cin >> patientsLastName;
    cout << "Height [0'0" << '"' << "]: ";
    cin >> patientsHeight;
    cout << "Weight (lbs): ";
    cin >> patientsWeight;
    cout << "Blood Type [AB, A, B, O]: ";
    cin >> patientsBloodType;
    cout << "Age: ";
    cin >> patientsAge;
    cout << "Occupation: ";
    cin >> patientsOccupation;
    cout << "Blood Pressure: ";
    cin >> patientsBloodPressure;
    cout << "Temperature (F): ";
    cin >> patientsTemperature;
    cout << "Pulse: ";
    cin >> patientsPulse;
    cout << "Allergies (Ex: Pollen/Grass): ";
    cin >> patientsAllergies;
    cout << "Family Conditions (Ex: HBP/Cancer): ";
    cin >> patientsFamilyConditions;
    cout << "Medications: ";
    cin >> patientsMedications;
    cout << "Existing Conditions: ";
    cin >> patientsExistingConditions;
    cout << endl;

    PatientHealthInfo newPatientHealthData;
    newPatientHealthData.setRecordNumber(+2);
    newPatientHealthData.setFirstName(patientsFirstName);
    newPatientHealthData.setLastName(patientsLastName);
    newPatientHealthData.setHeight(patientsHeight);
    newPatientHealthData.setWeight(patientsWeight);
    newPatientHealthData.setBloodType(patientsBloodType);
    newPatientHealthData.setAge(patientsAge);
    newPatientHealthData.setOccupation(patientsOccupation);
    newPatientHealthData.setBloodPressure(patientsBloodPressure);
    newPatientHealthData.setTemperature(patientsTemperature);
    newPatientHealthData.setPulse(patientsPulse);
    newPatientHealthData.setAllergies(patientsAllergies);
    newPatientHealthData.setFamilyConditions(patientsFamilyConditions);
    newPatientHealthData.setExistingConditions(patientsExistingConditions);
    newPatientHealthData.setMedications(patientsMedications);
    masterList.insert(newPatientHealthData);

    //Writes login information into the PatientLoginInfo.csv
    ofstream writeFile("PatientMedicalInfo.csv");
    Node<PatientHealthInfo> *pMem = masterList.getHeadPtr();
    writeFile << ",Name(last/first),Height,Weight,BloodType,Age,Occupation,BloodPressure,Temperature,Pulse,Allergies,FamilyConditions,Medications,ExistingConditions" << endl;
    int patientNumber = 0;
    while (pMem != nullptr) {
        ++patientNumber;
        writeFile << patientNumber << ',' << '"' << pMem->getData().getLastName() << ',' <<
                  pMem->getData().getFirstName() << '"' << ',' << pMem->getData().getHeight() << ',' << pMem->getData().getWeight() << ',' <<
                  pMem->getData().getBloodType() << ',' << pMem->getData().getAge() << ',' << pMem->getData().getOccupation() << ',' <<
                  pMem->getData().getBloodPressure() << ',' << pMem->getData().getTemperature() << ',' << pMem->getData().getTemperature() << ',' <<
                  pMem->getData().getPulse() << ',' << pMem->getData().getAllergies() << ',' << pMem->getData().getFamilyConditions() << ',' <<
                  pMem->getData().getMedications() << ',' << pMem->getData().getExistingConditions() << "\n";
        pMem = pMem->getNextPtr();
    }
    writeFile.close();

    cout << "You have successfully input your medical information!" << endl; //Directs user to sign into patient portal menu
}