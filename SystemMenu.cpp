#include "PatientLoginData.hpp"
#include "PatientHealthInfo.hpp"

/*****************************************************************
 * Pre-Condition: loginMenu() doesn't accept any variables. This function is used within
 * application().
 * Post-Condition: This function returns the user choice  of who the user is identified as
 * (either patient, doctor, staff/management). LoginMenu() does handle errors if user
 * enters a integer not from one to three including characters.
 *****************************************************************/
int loginMenu() { //User enters if Patient, Doctor, or Management/Staff
    int userChoice;
    cout << "Please enter who you are:" << endl;
    cout << "[1] - Patient" << endl;
    cout << "[2] - Doctor" << endl;
    cout << "[3] - Management/Staff" << endl;
    cout << "User Input: ";
    cin >> userChoice;

    //Handles errors
    while (userChoice != 1 && userChoice != 2 && userChoice != 3) {
        cout << "Error, enter a valid input [1-3]." << endl;
        cout << "User Input: ";
        cin >> userChoice;
    }
    return userChoice;
}
/*****************************************************************
 * Pre-Condition: application() doesn't accept any variables. Function is used within the main().
 * Post-Condition: This function decides who the user as it puts the user through a login process
 * either as a patient (enters value 1), doctor (enters value 2), or management (enters value 3).
 * If user enters as a patient, the user can either create their profile on patient portal or sign
 * into their account. application() also returns no values.
 *****************************************************************/
void application() {
    List<PatientLoginData> Patients;
    List<PatientHealthInfo> MedicalRecords;

    int userChoice = loginMenu();
    if (userChoice == 1) { //Enters if user is a Patient
        cout << "Entered as Patient" << endl;

        //User chooses to sign in to portal or can sign up <- Can add a 2-Factor Authentication
        int signInUpOption;
        cout << endl << "Login Options" << endl;
        cout << "[1] - Sign in" << endl;
        cout << "[2] - Sign Up" << endl;
        cout << "User input: ";
        cin >> signInUpOption;

        //Handles errors
        while (signInUpOption != 1 && signInUpOption != 2) {
            cout << "Error, enter a valid input [1-2]." << endl;
            cout << "User Input: ";
            cin >> userChoice;
        }

        importPatientLoginList(Patients);
        int successfulSignIn = 0;
        if (signInUpOption == 1) { //Enters if user intends to sign in to portal
            successfulSignIn = patientSignIn(Patients);
        }

        bool newPatient;
        if (signInUpOption == 2) { //Enters if user intends to sign up as a new patient
            newPatient = true;
            patientSignUp(Patients);
            cout << endl << "Now Please Sign In." << endl;
            successfulSignIn = patientSignIn(Patients);
        }

        if (successfulSignIn == 1) { //Enters if user successfully signs in
            cout << "You have successfully signed in!" << endl;
            importPatientMedicalList(MedicalRecords);
            if (newPatient) { //if new patient, user creates medical info
                patientInputsMedicalInfo(MedicalRecords);
            }
            patientPortalMenu();
        } else { //Enters if user unsuccessfully signed in
            cout << "You have reached the limit of unsuccessful attempts. Now exiting..." << endl;
        }
    }
    if (userChoice == 2) { //Enters if user is a Doctor
        cout << "Entered as a Doctor" << endl;

        //Signs into portal (username/password) <-Can add a 2-Factor Authentication

    }
    if (userChoice == 3) { //Enters if user is Management/Staff
        cout << "Entered as Management/Staff" << endl;

        //Signs into portal (username/password) <-Can add a 2-Factor Authentication

    }
}

/*****************************************************************
 * Pre-Condition:
 * Post-Condition:
 *****************************************************************/
/*void systemMenu() { //Used for Management

}*/




