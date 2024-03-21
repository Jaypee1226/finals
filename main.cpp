#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Tour
{
    string destination;
    int duration;
    double price;
    Tour* next;
};

struct Customer
{
    int customerId;
    string fullName;
    string email;
    string nationality;
    string destination;
    int pax;
    Customer* next;
};

struct Employee
{
    int employeeNumber;
    string fullName;
    char gender;
    string address;
    string birthday;
    string position;
    Employee* next;
};

struct Visa
{
    int applicationNumber;
    string applicantName;
    string passportNumber;
    string visaType;
    string submissionDate;
    string status;
    Visa* next;
};

struct LandTransportation {
    string type;
    string destination;
    string vehicleInfo;
    double pricePerDay;
    LandTransportation* next;
};

void AddRecordEmployee(Employee*& head) {
    Employee* newEmployee = new Employee;

    cout << "Employee Number : ";
    cin >> newEmployee->employeeNumber;
    cin.ignore();

    cout << "Full Name : ";
    getline(cin, newEmployee->fullName);

    cout << "Gender (M/F) : ";
    cin >> newEmployee->gender;

    cout << "Birthday (YYYY-MM-DD) : ";
    cin >> newEmployee->birthday;
    cin.ignore();

    cout << "Address : ";
    getline(cin, newEmployee->address);

    cout << "Position : ";
    getline(cin, newEmployee->position);

    newEmployee->next = head;
    head = newEmployee;

    cout << "Recorded Successfully" << endl;

    cin.ignore();
    system("cls");
}

void ViewSpecificRecordEmployee(const Employee* head) {
    ifstream inFile("employees.txt");
    int searchEmployeeId = 0, employeeNumber;
    string fullName, birthday, address, position;
    char gender;
    bool found = false;

    if (!inFile) {
        cout << "Unable to open file of the records" << endl;
        return;
    }
    cout << "Input the Employee's Number : ";
    cin >> searchEmployeeId;

    while (inFile >> employeeNumber >> fullName >> gender >> birthday >> address >> position) {
        if (employeeNumber == searchEmployeeId) {
            cout << "Record Found" << endl;
            cout << "Employee Number : " << employeeNumber << endl;
            cout << "Full Name : " << fullName << endl;
            cout << "Gender : " << gender << endl;
            cout << "Birthday : " << birthday << endl;
            cout << "Address : " << address << endl;
            cout << "Department : " << position << endl;
            found = true;
            break;
        }
    }
    inFile.close();

    if (!found)
        cout << "Record not found!" << endl;
    
}

void ViewAllRecordEmployee(const Employee* head) {
    ifstream inFile("employees.txt");
    int employeeNumber;
    string fullName, gender, birthday, address, position;
    if (inFile.is_open()) {


        cout << "ALL RECORDS" << endl;
        while (inFile >> employeeNumber >> fullName >> gender >> birthday >> address >> position) {
            cout << "Record Found" << endl;
            cout << "Employee Number : " << employeeNumber << endl;
            cout << "Full Name : " << fullName << endl;
            cout << "Gender : " << gender << endl;
            cout << "Birthday : " << birthday << endl;
            cout << "Address : " << address << endl;
            cout << "Department : " << position << endl;
            cout << endl;
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file of the records" << endl;
    }
   
}

void DeleteSpecificRecordEmployee(Employee*& head) {
    int deleteEmployeeId;
    Employee* current = head;
    Employee* prev = NULL;
    cout << "Input the Employee's Number : ";
    cin >> deleteEmployeeId;

    while (current != NULL) {
        if (current->employeeNumber == deleteEmployeeId) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Employee record deleted.." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Record Not Found" << endl;
    cin.ignore();
    system("cls");
}

void SaveRecordEmployee(const Employee* head) {
    ofstream outFile("employees.txt");
    if (outFile.is_open()) {
        const Employee* current = head;
        while (current != NULL) {
            outFile << current->employeeNumber << endl;
            outFile << current->fullName << endl;
            outFile << current->gender << endl;
            outFile << current->birthday << endl;
            outFile << current->address << endl;
            outFile << current->position << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Record Saved" << endl;
    }
    else {
        cout << "Unable to save records" << endl;
    }
    cin.ignore();
    system("cls");
}

void LoadRecordEmployee(Employee*& head) {
    ifstream inFile("employees.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            Employee* newEmployee = new Employee;
            inFile >> newEmployee->employeeNumber;
            inFile.ignore();
            getline(inFile, newEmployee->fullName);
            inFile >> newEmployee->gender;
            inFile.ignore();
            getline(inFile, newEmployee->birthday);
            getline(inFile, newEmployee->address);
            getline(inFile, newEmployee->position);
            inFile.ignore();
            newEmployee->next = head;
            head = newEmployee;
        }
        inFile.close();
        cout << "Records loaded successfully" << endl;
    }
    else {
        cout << "Unable to open file of the records" << endl;
    }
}

void EmployeeMenu()
{
    int employeeChoice;
    Employee* headEmployee = NULL;
    do {
        cout << "Employee Menu" << endl;
        cout << "1. Add Employee Record" << endl;
        cout << "2. View Specific Record" << endl;
        cout << "3. View All Records" << endl;
        cout << "4. Delete Specific Record" << endl;
        cout << "5. Save Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice :";
        cin >> employeeChoice;

        switch (employeeChoice)
        {
        case 1:
            AddRecordEmployee(headEmployee);
            break;
        case 2:
            ViewSpecificRecordEmployee(headEmployee);
            break;
        case 3:
            ViewAllRecordEmployee(headEmployee);
            break;
        case 4:
            DeleteSpecificRecordEmployee(headEmployee);
            break;
        case 5:
            SaveRecordEmployee(headEmployee);
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice. Please select another category";
        }
    } while (employeeChoice != 6);
}

void AddRecordVisa(Visa*& head) {
    Visa* newVisa = new Visa;

    cout << "Application Number : ";
    cin >> newVisa->applicationNumber;
    cin.ignore();

    cout << "Applicant Name : ";
    getline(cin, newVisa->applicantName);

    cout << "Passport Number : ";
    getline(cin, newVisa->passportNumber);

    cout << "Visa Type : ";
    getline(cin, newVisa->visaType);

    cout << "Submission Date (YYYY-MM-DD) : ";
    getline(cin, newVisa->submissionDate);

    cout << "Status : ";
    getline(cin, newVisa->status);

    newVisa->next = head;
    head = newVisa;

    cout << "Recorded Successfully" << endl;

    cin.ignore();
    system("cls");
}

void ViewSpecificRecordVisa(const Visa* head) {
    ifstream inFile("visas.txt");
    int searchApplicationNumber, applicationNumber;
    string applicantName, passportNumber, visaType, submissionDate, status;
    bool found = false;
    if (!inFile) {
        cout << "Unable to open file of the records" << endl;
        return;
    }

    cout << "Input the Application Number : ";
    cin >> searchApplicationNumber;


    while (inFile >> applicationNumber >> applicantName >> passportNumber >> visaType >> submissionDate >> status) {
        if (applicationNumber == searchApplicationNumber) {
            cout << "Record Found" << endl;
            cout << "Application Number : " << applicationNumber << endl;
            cout << "Applicant Name : " << applicantName << endl;
            cout << "Passport Number : " << passportNumber << endl;
            cout << "Visa Type : " << visaType << endl;
            cout << "Submission Date : " << submissionDate << endl;
            cout << "Status : " << status << endl;
            found = true;
            break;
        }
    }
    inFile.close();

    if (!found)
        cout << "Record not found!" << endl;
    
}

void ViewAllRecordVisa(const Visa* head) {
    ifstream inFile("visas.txt");
    int applicationNumber;
    string applicantName, passportNumber, visaType, submissionDate, status;
    if (inFile.is_open()) {

        cout << "ALL RECORDS" << endl;
        while (inFile >> applicationNumber >> applicantName >> passportNumber >> visaType >> submissionDate >> status) {
            cout << "Record Found" << endl;
            cout << "Application Number : " << applicationNumber << endl;
            cout << "Applicant Name : " << applicantName << endl;
            cout << "Passport Number : " << passportNumber << endl;
            cout << "Visa Type : " << visaType << endl;
            cout << "Submission Date : " << submissionDate << endl;
            cout << "Status : " << status << endl;
            cout << endl;
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file of the records" << endl;
    }
    
}

void DeleteSpecificRecordVisa(Visa*& head) {
    int deleteApplicationNumber;
    Visa* current = head;
    Visa* prev = NULL;
    cout << "Input the Application Number : ";
    cin >> deleteApplicationNumber;

    while (current != NULL) {
        if (current->applicationNumber == deleteApplicationNumber) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Visa record deleted.." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Record Not Found" << endl;
    cin.ignore();
    system("cls");
}

void SaveRecordVisa(const Visa* head) {
    ofstream outFile("visas.txt");
    const Visa* current = head;
    if (outFile.is_open()) {
        while (current != NULL) {
            outFile << current->applicationNumber << endl;
            outFile << current->applicantName << endl;
            outFile << current->passportNumber << endl;
            outFile << current->visaType << endl;
             outFile<< current->submissionDate << endl;
             outFile << current->status << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Record Saved" << endl;
    }
    else {
        cout << "Unable to save records" << endl;
    }
    cin.ignore();
    system("cls");
}

void LoadRecordVisa(Visa*& head) {
    ifstream inFile("visas.txt");
    Visa* newVisa = new Visa;
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile >> newVisa->applicationNumber;
            inFile.ignore();
            getline(inFile, newVisa->applicantName);
            getline(inFile, newVisa->passportNumber);
            getline(inFile, newVisa->visaType);
            getline(inFile, newVisa->submissionDate);
            getline(inFile, newVisa->status);
            inFile.ignore();
            newVisa->next = head;
            head = newVisa;
        }
        inFile.close();
        cout << "Records loaded successfully" << endl;
    }
    else {
        cout << "Unable to open file of the records" << endl;
    }
}

void VisaMenu()
{
    int visaChoice;
    Visa* headVisa = NULL;
    do {
        cout << "Visa Menu" << endl;
        cout << "1. Add Visa Record" << endl;
        cout << "2. View Specific Record" << endl;
        cout << "3. View All Records" << endl;
        cout << "4. Delete Specific Record" << endl;
        cout << "5. Save Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice :";
        cin >> visaChoice;

        switch (visaChoice)
        {
        case 1:
            AddRecordVisa(headVisa);
            break;
        case 2:
            ViewSpecificRecordVisa(headVisa);
            break;
        case 3:
            ViewAllRecordVisa(headVisa);
            break;
        case 4:
            DeleteSpecificRecordVisa(headVisa);
            break;
        case 5:
            SaveRecordVisa(headVisa);
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice. Please select another category";
        }
    } while (visaChoice != 6);
}

void AddRecordTour(Tour*& head) {
    Tour* newTour = new Tour;

    cout << "Destination : ";
    getline(cin, newTour->destination);

    cout << "Duration (in days): ";
    cin >> newTour->duration;

    cout << "Price : $";
    cin >> newTour->price;

    newTour->next = head;
    head = newTour;

    cout << "Recorded Successfully" << endl;

    cin.ignore();
    system("cls");
}

void ViewSpecificRecordTour(const Tour* head) {
    ifstream inFile("tours.txt");
    string searchDestination;
    string destination;
    int duration;
    double price;
    bool found = false;
    if (!inFile) {
        cout << "Unable to open file of the records" << endl;
        return;
    }
    cout << "Input the Destination : ";
    cin.ignore();
    getline(cin, searchDestination);

    while (inFile >> destination >> duration >> price) {
        if (destination == searchDestination) {
            cout << "Record Found" << endl;
            cout << "Destination : " << destination << endl;
            cout << "Duration : " << duration << " days" << endl;
            cout << "Price : $" << price << endl;
            found = true;
            break;
        }
    }
    inFile.close();

    if (!found)
        cout << "Record not found!" << endl;
    
}

void ViewAllRecordTour(const Tour* head) {
    ifstream inFile("tours.txt");
    string destination;
    int duration;
    double price;
    if (inFile.is_open()) {
     
        cout << "ALL RECORDS" << endl;
        while (inFile >> destination >> duration >> price) {
            cout << "Record Found" << endl;
            cout << "Destination : " << destination << endl;
            cout << "Duration : " << duration << " days" << endl;
            cout << "Price : $" << price << endl;
            cout << endl;
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file of the records" << endl;
    }
    
}

void DeleteSpecificRecordTour(Tour*& head) {
    string deleteDestination;
    Tour* current = head;
    Tour* prev = NULL;
    cout << "Input the Destination : ";
    cin.ignore();
    getline(cin, deleteDestination);

    while (current != NULL) {
        if (current->destination == deleteDestination) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Tour record deleted.." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Record Not Found" << endl;
    cin.ignore();
    system("cls");
}

void SaveRecordTour(const Tour* head) {
    ofstream outFile("tours.txt");
    const Tour* current = head;
    if (outFile.is_open()) {
        while (current != NULL) {
            outFile << current->destination << endl;
            outFile << current->duration << endl;
            outFile << current->price << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Record Saved" << endl;
    }
    else {
        cout << "Unable to save records" << endl;
    }
    cin.ignore();
    system("cls");
}

void LoadRecordTour(Tour*& head) {
    ifstream inFile("tours.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            Tour* newTour = new Tour;
            getline(inFile, newTour->destination);
            inFile >> newTour->duration;
            inFile >> newTour->price;
            inFile.ignore();
            newTour->next = head;
            head = newTour;
        }
        inFile.close();
        cout << "Records loaded successfully" << endl;
    }
    else {
        cout << "Unable to open file of the records" << endl;
    }
}

void TourMenu()
{
    int tourChoice;
    Tour* headTour = NULL;
    do {
        cout << "Tour Menu" << endl;
        cout << "1. Add Tour Record" << endl;
        cout << "2. View Specific Record" << endl;
        cout << "3. View All Records" << endl;
        cout << "4. Delete Specific Record" << endl;
        cout << "5. Save Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice :";
        cin >> tourChoice;

        switch (tourChoice)
        {
        case 1:
            AddRecordTour(headTour);
            break;
        case 2:
            ViewSpecificRecordTour(headTour);
            break;
        case 3:
            ViewAllRecordTour(headTour);
            break;
        case 4:
            DeleteSpecificRecordTour(headTour);
            break;
        case 5:
            SaveRecordTour(headTour);
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice. Please select another category";
        }
    } while (tourChoice != 6);
}

void AddCustomer(Customer*& head) {
    Customer* newCustomer = new Customer;

    cout << "Enter Customer ID: ";
    cin >> newCustomer->customerId;
    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, newCustomer->fullName);

    cout << "Enter Contact Information: ";
    getline(cin, newCustomer->email);

    cout << "Enter Nationality: ";
    getline(cin, newCustomer->nationality);

    cout << "Enter Number of Individuals: ";
    cin >> newCustomer->pax;
    cin.ignore();

    cout << "Enter Destination: ";
    getline(cin, newCustomer->destination);

    newCustomer->next = head;
    head = newCustomer;

    cout << "Customer added successfully.\n";
    cin.ignore();
    system("cls");
}

void DisplayAllCustomers(const Customer* head) {
    cout << "All Customers:\n";
    const Customer* current = head;
    while (current != nullptr) {
        cout << "Customer ID: " << current->customerId << endl;
        cout << "Name: " << current->fullName << endl;
        cout << "Contact Information: " << current->email << endl;
        cout << "Nationality: " << current->nationality << endl;
        cout << "Number of individuals: " << current->pax << endl;
        cout << "Destination: " << current->destination << endl;
        cout << endl;
        current = current->next;
    }
   
}

void SaveCustomerData(const Customer* head) {
    ofstream outFile("customer_data.txt");
    const Customer* current = head;
    if (outFile.is_open()) {
        while (current != nullptr) {
            outFile << current->customerId << endl;
            outFile << current->fullName << endl;
            outFile << current->email << endl;
            outFile << current->nationality << endl;
            outFile << current->pax << endl;
            outFile << current->destination << endl;;
            current = current->next;
        }
        outFile.close();
        cout << "Customer data saved successfully.\n";
    }
    else {
        cout << "Unable to save customer data.\n";
    }
    cin.ignore();
    system("cls");
}

void LoadCustomerData(Customer*& head) {
    ifstream inFile("customer_data.txt");
    Customer* newCustomer = new Customer;
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile >> newCustomer->customerId;
            inFile.ignore();
            getline(inFile, newCustomer->fullName);
            getline(inFile, newCustomer->email);
            getline(inFile, newCustomer->nationality);
            inFile >> newCustomer->pax;
            inFile.ignore();
            getline(inFile, newCustomer->destination);
            newCustomer->next = head;
            head = newCustomer;
        }
        inFile.close();
        cout << "Customer data loaded successfully.\n";
    }
    else {
        cout << "Unable to open customer data file.\n";
    }
}

void CustomerMenu() {
    int customerChoice;
    Customer* headCustomer = nullptr;
    LoadCustomerData(headCustomer);

    do {
        cout << "Customer Menu" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. View All Customers" << endl;
        cout << "3. Save Customer Data" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> customerChoice;

        switch (customerChoice) {
        case 1:
            AddCustomer(headCustomer);
            break;
        case 2:
            DisplayAllCustomers(headCustomer);
            break;
        case 3:
            SaveCustomerData(headCustomer);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please select another option." << endl;
        }
    } while (customerChoice != 4);
}

void AddLandTransportation(LandTransportation*& head) {
    LandTransportation* newService = new LandTransportation;

    cout << "Enter Type of Transportation (e.g., Car Rental, Bus Tour, etc.): ";
    cin.ignore();
    getline(cin, newService->type);

    cout << "Enter Destination: ";
    getline(cin, newService->destination);

    cout << "Enter Vehicle Information: ";
    getline(cin, newService->vehicleInfo);

    cout << "Enter Price per Day: $";
    cin >> newService->pricePerDay;

    newService->next = head;
    head = newService;

    cout << "Land transportation service added successfully.\n";
    cin.ignore();
    system("cls");
}

void DisplayAllLandTransportation(const LandTransportation* head) {
    const LandTransportation* current = head;
    cout << "All Land Transportation Services:\n";
    while (current != nullptr) {
        cout << "Type of Transportation: " << current->type << endl;
        cout << "Destination: " << current->destination << endl;
        cout << "Vehicle Information: " << current->vehicleInfo << endl;
        cout << "Price per Day: $" << current->pricePerDay << endl;
        cout << endl;
        current = current->next;
    }
   
}

void SaveLandTransportationData(const LandTransportation* head) {
    ofstream outFile("land_transportation_data.txt");
    const LandTransportation* current = head;
    if (outFile.is_open()) {
        while (current != nullptr) {
            outFile << current->type << endl;
            outFile << current->destination << endl;
            outFile << current->vehicleInfo << endl;
            outFile << current->pricePerDay << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Land transportation data saved successfully.\n";
    }
    else {
        cout << "Unable to save land transportation data.\n";
    }
    cin.ignore();
    system("cls");
}

void LoadLandTransportationData(LandTransportation*& head) {
    ifstream inFile("land_transportation_data.txt");
    LandTransportation* newService = new LandTransportation;
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile.ignore();
            getline(inFile, newService->type);
            getline(inFile, newService->destination);
            getline(inFile, newService->vehicleInfo);
            inFile >> newService->pricePerDay;
            inFile.ignore();
            newService->next = head;
            head = newService;
        }
        inFile.close();
        cout << "Land transportation data loaded successfully.\n";
    }
    else {
        cout << "Unable to open land transportation data file.\n";
    }
    cin.ignore();
    system("cls");
}

void LandTransportationMenu() {
    int landChoice;
    LandTransportation* landTransportationHead = nullptr;
    LoadLandTransportationData(landTransportationHead);

    do {
        cout << "Land Transportation Menu" << endl;
        cout << "1. Add Land Transportation Service" << endl;
        cout << "2. View All Land Transportation Services" << endl;
        cout << "3. Save Land Transportation Data" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> landChoice;

        switch (landChoice) {
        case 1:
            AddLandTransportation(landTransportationHead);
            break;
        case 2:
            DisplayAllLandTransportation(landTransportationHead);
            break;
        case 3:
            SaveLandTransportationData(landTransportationHead);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please select another option." << endl;
        }
    } while (landChoice != 4);
}

int main()
{
    int mainChoice;
    do
    {
        cout << "Main Menu" << endl;
        cout << "1. Employee Menu" << endl;
        cout << "2. Visa Menu" << endl;
        cout << "3. Tour Menu" << endl;
        cout << "4. Customer Menu" << endl;
        cout << "5. Land Transportation Menu" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice :";
        cin >> mainChoice;
        system("cls");
        switch (mainChoice)
        {
        case 1:
            EmployeeMenu();
            break;
        case 2:
            VisaMenu();
            break;
        case 3:
            TourMenu();
            break;
        case 4:
            CustomerMenu();
            break;
        case 5:
            LandTransportationMenu();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice. Please select another category";
        }
    } while (mainChoice != 6);

    return 0;
}
