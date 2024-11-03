#pragma once
#include "List.hpp"

typedef struct patientFullName {
    string firstName;
    string lastName;
} PatientFullName;

/**************************************************************************************************
 * PatientLoginData class will contain the patient login attributes (first name, last name, email, username,
 * password, phone number, and Birthdate. All login attributes are accessible to staff but are encrypted (specifically)
 * the patients password.
 **************************************************************************************************/
class PatientLoginData {
public:
    PatientLoginData(); //Constructor
    //~PatientLoginData(); //Destructor <- Trivial Destructor (not explicitly stated)
    PatientLoginData(const string &newFirstName, const string &newLastName, const string &newEmail,
                     const string &newUsername, const string &newBirthdate, const string &newPhoneNumber,
                     const string &newPassword, const int newRecordNumber) : mName{newFirstName, newLastName}, // Initialize mName directly
    mEmail{newEmail},
    mUsername{newUsername},
    mPassword{newPassword},
    mBirthdate{newBirthdate},
    mPhoneNumber{newPhoneNumber},
    mRecordNumber{newRecordNumber} {} // Direct initialization

    //Getters for all patient login attributes
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    string getUsername() const;
    string getPassword() const;
    string getBirthdate() const;
    string getPhoneNumber() const;
    int getRecordNumber() const;

    //Setters for all patient login attributes
    //void setFirstName(string newFirstName);
    void setFirstName(const string &newFirstName);
    //void setLastName(string newLastName);
    void setLastName(const string &newLastName);
    //void setEmail(string newEmail);
    void setEmail(const string &newEmail);
    void setUsername(const string &newUsername);
    //void setUsername(string newUsername);
    //void setPassword(string newPassword);
    void setPassword(const string &newPassword);
    void setBirthdate(const string &newBirthdate);
    //void setBirthdate(string newBirthdate);
    //void setPhoneNumber(int newPhoneNumber);
    void setPhoneNumber(const string &newPhoneNumber);
    void setRecordNumber(int newRecordNumber);

private:
    PatientFullName mName;
    string mEmail, mUsername, mPassword, mBirthdate, mPhoneNumber;
    int mRecordNumber;
};

//General Program:
void importPatientLoginList(List<PatientLoginData> &masterList);
int patientSignIn(List<PatientLoginData> &masterList);
void patientSignUp(List<PatientLoginData> &masterList);
string encryptionDecryption(const string &input, char key);

PatientLoginData::PatientLoginData() { //Constructor
    mName.firstName = "";
    mName.lastName = "";
    mEmail = "";
    mUsername = "";
    mPassword = "";
    mBirthdate = "";
    mPhoneNumber = "";
    mRecordNumber = 0;
}

/*PatientLoginData::~PatientLoginData() { //Destructor
}*/

/*PatientLoginData::PatientLoginData(const string &newFirstName, const string &newLastName, const string &newEmail,
                                   const string &newUsername, const string &newBirthdate, const int newPhoneNumber,
                                   const string &newPassword, const int newRecordNumber) { //Copy Constructor
    this->setFirstName(newFirstName);
    this->setLastName(newLastName);
    this->setEmail(newEmail);
    this->setUsername(newUsername);
    this->setPassword(newPassword);
    this->setBirthdate(newBirthdate);
    this->setPhoneNumber(newPhoneNumber);
    this->setRecordNumber(newRecordNumber);
}*/

/////////////Getters////////////
string PatientLoginData::getFirstName() const {
    return this->mName.firstName;
}

string PatientLoginData::getLastName() const {
    return this->mName.lastName;
}

string PatientLoginData::getUsername() const {
    return this->mUsername;
}

string PatientLoginData::getEmail() const {
    return this->mEmail;
}

string PatientLoginData::getPassword() const {
    return this->mPassword;
}

string PatientLoginData::getBirthdate() const {
    return this->mBirthdate;
}

string PatientLoginData::getPhoneNumber() const {
    return this->mPhoneNumber;
}

int PatientLoginData::getRecordNumber() const {
    return this->mRecordNumber;
}

/////////////Setters////////////
void PatientLoginData::setFirstName(const string &newFirstName) {
    this->mName.firstName = newFirstName;
}

void PatientLoginData::setLastName(const string &newLastName) {
    this->mName.lastName = newLastName;
}

void PatientLoginData::setEmail(const string &newEmail) {
    this->mEmail = newEmail;
}

void PatientLoginData::setUsername(const string &newUsername) { //no need to modify input string, avoids unnecessary copying
    this->mUsername = newUsername;
}

void PatientLoginData::setPassword(const string &newPassword) {
    this->mPassword = newPassword;
}

void PatientLoginData::setBirthdate(const string &newBirthdate) {
    this->mBirthdate = newBirthdate;
}

void PatientLoginData::setPhoneNumber(const string &newPhoneNumber) {
    this->mPhoneNumber = newPhoneNumber;
}

void PatientLoginData::setRecordNumber(int newRecordNumber) {
    this->mRecordNumber = newRecordNumber;
}

/*****************************************************************
 * Pre-Condition:
 * Post-Condition:
 *****************************************************************/
void importPatientLoginList(List<PatientLoginData> &masterList) { //Used for Management
    ifstream readFile("PatientLoginInfo.csv");
    string line;
    getline(readFile, line); //Skips the header line

    while (getline(readFile, line)) { //Keeps reading every line using setters from Data class
        stringstream ss(line);
        string field;
        PatientLoginData patient;

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

        //Email:
        getline(ss, field, ',');
        getline(ss, field, ',');
        patient.setEmail(field);

        //Username:
        getline(ss, field, ',');
        patient.setUsername(field);

        //Password:
        getline(ss, field, ',');
        patient.setPassword(field);

        //Birthdate:
        getline(ss, field, ',');
        patient.setBirthdate(field);

        //Phone Number
        getline(ss, field, '\n');
        patient.setPhoneNumber(field);

        masterList.insert(patient); //updates master list
    }
    readFile.close();
}

/*****************************************************************
 * Pre-Condition:
 * Post-Condition:
 *****************************************************************/
int patientSignIn(List<PatientLoginData> &masterList) { //Used to sign in for patients <-- not finding the username/password in the file directly for caleb/mom
    int successfulSignIn = 0;
    Node<PatientLoginData> *pMem = masterList.getHeadPtr();
    cout << endl << "Please enter the following: " << endl;
    int fraudDetector = 0;
    string username, password;
    do {
        //Asks user for username/password:
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        //Handles incorrect/not found usernames:
        if (username != pMem->getData().getUsername()) {
            while (pMem->getNextPtr() != nullptr) {
                pMem = pMem->getNextPtr();
                if (username == pMem->getData().getUsername()) { //Enters if username matches
                    cout << username << " found on username file!" << endl;
                    break;
                }
                if (username != pMem->getData().getUsername() && pMem->getNextPtr() == nullptr) {
                    cout << username << " not found on username file. Please try again." << endl;
                }
            }
        }

        //Handles incorrect/not found password:
        if (password != pMem->getData().getPassword()) { //Enters if password doesn't match in the column of the entered username
            if (fraudDetector != 3) {
                cout << password << " not found on password file. Please try again." << endl;
            }
        } else {
            cout << password << " found on password file!" << endl;
        }
        fraudDetector++;
        if (fraudDetector == 3) { //Detects fraud users signing in
            return successfulSignIn;
        }
    } while (password != pMem->getData().getPassword() || username != pMem->getData().getUsername());
    cout << endl << "Welcome " << pMem->getData().getFirstName() << " " << pMem->getData().getLastName() << "!" << endl;
    successfulSignIn = 1;
    return successfulSignIn;
}

/*****************************************************************
 * Pre-Condition:
 * Post-Condition:
 *****************************************************************/
void patientSignUp(List<PatientLoginData> &masterList) {
    int recordNumber = 0;
    ifstream readFile("PatientLoginInfo.csv");
    string line;
    getline(readFile, line); //Skips the header line
    while (getline(readFile, line)) { // Read each line to count records
        recordNumber++;
    }
    readFile.close();

    //Assigns the characteristics in the file
    cout << endl << "Please fill out the following: " << endl;

    //Patients Name:
    string firstName, lastName;
    cout << "***Patient Name***" << endl;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << endl;

    string patientsUserName, patientsPassword, checkedPassword;
    cout << "***Login Information***" << endl;
    do {
        cout << "Username: ";
        cin >> patientsUserName;
        cout << "Password: ";
        cin >> patientsPassword;
        cout << "Re-enter Password: ";
        cin >> checkedPassword;
        if (patientsPassword != checkedPassword) {
            cout << "Password doesn't match, please try again." << endl;
        }
    } while(patientsPassword != checkedPassword);

    //Simple XOR code <-- random char which will be kept/passed to check the password (confirms the security of the password)
    char userKey = 'k';

    //Encryption Process:
    string encryptedString = encryptionDecryption(patientsPassword, userKey);
    cout << "Encrypted Password: " << encryptedString << endl << endl;

    //Check (by decryption):
    string decryptedString = encryptionDecryption(encryptedString, userKey);
    cout << "Decrypted text: " << decryptedString << endl << endl;


    //Patients Contact Information:
    string patientsBirthdate, patientsEmail, patientsPhoneNumber;
    cout << endl << "***Patient Information***" << endl;
    cout << "Email: ";
    cin >> patientsEmail;
    cout << "Birthdate [00/00/0000]: "; //<-- Need to parse and separate each number into days, months, and years
    cin >> patientsBirthdate;
    cout << "Phone number [(000)000-000]: ";
    cin >> patientsPhoneNumber;
    cout << endl << endl;

    PatientLoginData newPatientData;
    newPatientData.setRecordNumber(+2);
    newPatientData.setFirstName(firstName);
    newPatientData.setLastName(lastName);
    newPatientData.setUsername(patientsUserName);
    newPatientData.setPassword(patientsPassword);
    newPatientData.setEmail(patientsEmail);
    newPatientData.setBirthdate(patientsBirthdate);
    newPatientData.setPhoneNumber(patientsPhoneNumber);
    masterList.insert(newPatientData);

    //Writes login information into the PatientLoginInfo.csv
    ofstream writeFile("PatientLoginInfo.csv");
    Node<PatientLoginData> *pMem = masterList.getHeadPtr();
    writeFile << ",Name(last/first),Email,Username,Password,Birthdate(month/day/year),PhoneNumber," << endl;
    int patientNumber = 0;
    while (pMem != nullptr) {
        ++patientNumber;
        writeFile << patientNumber << ',' << '"' << pMem->getData().getLastName() << ',' <<
        pMem->getData().getFirstName() << '"' << ',' << pMem->getData().getEmail() << ',' << pMem->getData().getUsername()
        << ',' << pMem->getData().getPassword() << ',' << pMem->getData().getBirthdate() << ',' <<
        pMem->getData().getPhoneNumber() << "\n";
        pMem = pMem->getNextPtr();
    }
    writeFile.close();

    cout << "Welcome " << firstName << " " << lastName << "!" << endl;
    cout << "You have successfully signed up!" << endl; //Directs user to sign into patient portal
}

/*****************************************************************
 * Pre-Condition:
 * Post-Condition:
 *****************************************************************/
string encryptionDecryption(const string &userInput, char key) {
   string encryptedString = userInput;
   for (size_t i = 0; i < encryptedString.length(); ++i) {
       encryptedString[i] ^= key; // XOR with the key
   }
   return encryptedString;
}
/*string encryptionDecryption(string &userInput, char key) {
    //string encryptedString = userInput;
    for (size_t i = 0; i < userInput.length(); ++i) {
        userInput[i] ^= key; // XOR with the key
    }
    return userInput;
}*/


