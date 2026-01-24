#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <limits>
using namespace std;
const int MAX_CHILDREN = 100;
// Color function
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
// STRUCTS
struct Child {
    int id;
    string name;
    int age;
    string admissionDate;
};
struct MedicalRecord {
    int childID;
    string checkupDate, doctorName, diagnosis, treatment;
};
struct Node {
    MedicalRecord data;
    Node* next;
    Node() : next(nullptr) {}
};
Node* head = nullptr;
//  Donation (STACK) using linked list 
struct Donation {
    int donationID;
    int childID; 
    string donorName;
    double amount;
    string date;
    string item;
};
struct DNode {
    Donation data;
    DNode* next;
    DNode(const Donation &d) : data(d), next(nullptr) {}
};
DNode* donationTop = nullptr;
int donationAutoID = 1;
// Adoption Request (QUEUE) using linked list 
struct Request {
    int requestID;
    int childID;
    string adopterName;
    string contact;
    string date;
    string status;
};
struct QNode {
    Request data;
    QNode* next;
    QNode(const Request &r) : data(r), next(nullptr) {}
};
QNode* qFront = nullptr;
QNode* qRear = nullptr;
int requestAutoID = 1;
//  FUNCTION PROTOTYPES
void displayMainMenu(Child[], int&);
void arrayMenu(Child[], int&);
void displayChildren(Child[], int);
void insertMenu(Child[], int&);
void insertAtStart(Child[], int&);
void insertAtEnd(Child[], int&);
void insertAtPosition(Child[], int&);
void deleteChild(Child[], int&);
void sortMenu(Child[], int);
void searchMenu(Child[], int);
void linearSearch(Child[], int, int);
void binarySearch(Child[], int, int);
void medicalMenu(Child[], int);
void insertMedicalFront(Child[], int);
void insertMedicalEnd(Child[], int);
void insertMedicalPosition(Child[], int);
void displayMedicalRecords();
void freeMedicalList();
void deleteMedicalFront();
void deleteMedicalEnd();
void deleteMedicalPosition();
void searchMedicalRecord(Child[], int);
void updateMedicalRecord(Child[], int);
void donationMenu(Child[], int&);
void pushDonation(const Donation &d);
bool isDonationStackEmpty();
Donation popDonation();
Donation peekDonation();
void displayDonations();
void freeDonationStack();
void adoptionMenu(Child[], int&);
void enqueueRequest(const Request &r);
bool isQueueEmpty();
Request dequeueRequest();
Request frontRequest();
Request rearRequest();
void displayQueue();
void freeRequestQueue();
bool removeChildByID(Child children[], int &size, int id);
bool childExists(Child children[], int size, int id);
void removeMedicalByChildID(int id);
void removeDonationsByChildID(int id);
void removeRequestsByChildID(int id);
//  MAIN FUNCTION
int main() {
    string username, correctUser = "admin";
    int password, correctPass = 12345;
    cout<<"\n\n\n";setColor(2);
    cout << setw(75) << " ----**************************************----\n";
    cout << setw(72) << " WELCOME TO ORPHANAGE MANAGEMENT SYSTEM\n";
    cout << setw(75) << " ----*************************************----\n\n";
    setColor(4);
    cout << setw(55) << "Enter the username: "; cin >> username;
    cout << setw(55) << "Enter the password: "; cin >> password;
    if (username != correctUser || password != correctPass) {
        setColor(4);
        cout << "\nIncorrect username or password!\n";
        return 0;
    }
    setColor(3);
    cout << "\n" << setw(63) << "Successfully logged in!\n";
    setColor(7);
    cout << setw(63) << " Loading main system..."; Sleep(2000);
    system("cls");
    // Initialize some children
    Child children[MAX_CHILDREN] = {
        {101, "Ali", 8, "01-01-2023"},
        {102, "Sara", 10, "15-02-2023"},
        {103, "Ahmed", 6, "10-03-2023"}
    };
    int size = 3;
    // Preload medical records 
    MedicalRecord mr1 = {101, "01-09-2025", "Dr. Smith", "Annual checkup", "Healthy"};
    Node* n1 = new Node();
    n1->data = mr1;
    n1->next = nullptr;
    head = n1;
    MedicalRecord mr2 = {102, "05-09-2025", "Dr. Jones", "Vaccination", "Administered"};
    Node* n2 = new Node();
    n2->data = mr2;
    n2->next = nullptr;
    n1->next = n2;
    MedicalRecord mr3 = {103, "10-09-2025", "Dr. Brown", "Dental check", "No issues"};
    Node* n3 = new Node();
    n3->data = mr3;
    n3->next = nullptr;
    n2->next = n3;
    // Preload 3 donation records 
    Donation d1 = { donationAutoID++, 101, "Ayesha", 2000.0, "01-10-2025", "Winter Coat" };
    Donation d2 = { donationAutoID++, 102, "Omar", 1500.0, "05-10-2025", "Shoes" };
    Donation d3 = { donationAutoID++, 103, "Zara", 500.0, "10-10-2025", "Books" };
    pushDonation(d1);
    pushDonation(d2);
    pushDonation(d3);
    // Preload adoption requests 
    Request req1 = {requestAutoID++, 101, "Alice Johnson", "alice@email.com", "12-11-2025", "pending"};
    enqueueRequest(req1);
    Request req2 = {requestAutoID++, 102, "Bob Smith", "bob@email.com", "13-11-2025", "pending"};
    enqueueRequest(req2);
    Request req3 = {requestAutoID++, 103, "Carol Davis", "carol@email.com", "14-11-2025", "pending"};
    enqueueRequest(req3);
displayMainMenu(children, size);
    // cleanup before exit
    freeMedicalList();
    freeDonationStack();
    freeRequestQueue();
    return 0;
}
// MAIN MENU 
void displayMainMenu(Child children[], int &size) {
    int choice;
    do {
        setColor(4);
        cout << "\n\t\t--- MAIN MENU ---\n";
        setColor(3);
        cout << "\t1. Manage Children (ARRAY)\n";
        cout << "\t2. Medical History (LINKED LIST)\n";
        cout << "\t3. Donation history (STACK)\n";
        cout << "\t4. Adoption requests (QUEUE)\n";
        cout << "\t5. Exit\n";
        setColor(13);
        cout << "\nEnter your choice: "; cin >> choice;
        system("cls");
        switch (choice) {
            case 1: arrayMenu(children, size); break;
            case 2: medicalMenu(children, size); break;
            case 3: donationMenu(children, size); break;
            case 4: adoptionMenu(children, size); break;
            case 5: cout << "Exiting program...\n"; return;
            default: setColor(4); cout << "Invalid choice!\n"; break;
        }
    } while (choice != 5);
}
//ARRAY MENU
void arrayMenu(Child children[], int &size) {
    int choice;
    do {
        setColor(8);
        cout << "\n--- CHILD RECORDS ---\n";
        displayChildren(children, size);
        setColor(13);
        cout << "\n1. Insert a Child\n2. Delete a Child\n3. Sort by Age\n4. Search by ID\n5. Back\n";
        cout << "Enter choice: "; cin >> choice;
        system("cls");
        switch (choice) {
            case 1: insertMenu(children, size); break;
            case 2: deleteChild(children, size); break;
            case 3: sortMenu(children, size); break;
            case 4: searchMenu(children, size); break;
            case 5: return;
            default: setColor(4); cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}
// DISPLAY CHILDREN
void displayChildren(Child children[], int size) {
    if (size == 0) { cout << "No records.\n"; return; }
    cout << left << setw(10) << "ID" << setw(15) << "Name"
         << setw(10) << "Age" << setw(15) << "Admission Date\n";
    cout << string(50, '-') << "\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(10) << children[i].id
             << setw(15) << children[i].name
             << setw(10) << children[i].age
             << setw(15) << children[i].admissionDate << "\n";
    }
}
//  INSERT MENU 
void insertMenu(Child children[], int &size) {
    int choice;
    do {
        cout << "\nInsert Menu:\n1. At Start\n2. At Position\n3. At End\n4. Back\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: insertAtStart(children, size); system("cls"); break;
            case 2: insertAtPosition(children, size); system("cls"); break;
            case 3: insertAtEnd(children, size); system("cls"); break;
            case 4: system("cls"); return;
            default: setColor(4); cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}
//  INSERT FUNCTIONS 
void insertAtStart(Child children[], int &size) {
    if (size >= MAX_CHILDREN) { setColor(4); cout << "No space!\n"; return; }
    Child c;
    cout << "Enter ID, Name, Age & Date: ";
    cin >> c.id >> ws; getline(cin, c.name);
    cin >> c.age >> ws; getline(cin, c.admissionDate);
    for (int i = size; i > 0; i--) children[i] = children[i-1];
    children[0] = c; size++; setColor(10);
    cout << "Inserted at start!\n";
}
void insertAtEnd(Child children[], int &size) {
    if (size >= MAX_CHILDREN) { cout << "No space!\n"; return; }
    Child c;
    cout << "Enter ID Name Age Date: ";
    cin >> c.id >> ws; getline(cin, c.name);
    cin >> c.age >> ws; getline(cin, c.admissionDate);
    children[size++] = c; setColor(10);
    cout << "Inserted at end!\n"; system("cls");
}
void insertAtPosition(Child children[], int &size) {
    if (size >= MAX_CHILDREN) { cout << "No space!\n"; return; }
    int pos; cout << "Enter position (0-" << size << "): "; cin >> pos;
    if (pos < 0 || pos > size) { setColor(4); cout << "Invalid!\n"; return; }
    Child c;
    cout << "Enter ID Name Age Date: ";
    cin >> c.id >> ws; getline(cin, c.name);
    cin >> c.age >> ws; getline(cin, c.admissionDate);
    for (int i = size; i > pos; i--) children[i] = children[i-1];
    children[pos] = c; size++; setColor(10);
    cout << "Inserted at position!\n"; system("cls");
}
//   DELETE  
void deleteChild(Child children[], int &size) {
    if (size == 0) { setColor(4); cout << "No records!\n"; return; }
    int id; cout << "Enter ID to delete: "; cin >> id;
    if (removeChildByID(children, size, id)) {
        setColor(2); cout << "Deleted!\n";
    } else {
        setColor(4); cout << "Not found!\n";
    }
}
bool removeChildByID(Child children[], int &size, int id) {
    int pos = -1;
    for (int i = 0; i < size; ++i) if (children[i].id == id) { pos = i; break; }
    if (pos == -1) return false;
    for (int i = pos; i < size - 1; ++i) children[i] = children[i+1];
    --size;
    // Remove related records for consistency
    removeMedicalByChildID(id);
    removeDonationsByChildID(id);
    removeRequestsByChildID(id);
    return true;
}
//   SORT MENU  
void sortMenu(Child children[], int size) {
    int choice;
    cout << "Sort Menu:\n1. Bubble\n2. Selection\n3. Insertion\nChoice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            for (int i = 0; i < size-1; i++)
                for (int j = 0; j < size-i-1; j++)
                    if (children[j].age > children[j+1].age)
                        swap(children[j], children[j+1]);
            setColor(2);
            cout << "Bubble sort done!\n";
            break;
        case 2:
            for (int i = 0; i < size-1; i++) {
                int min = i;
                for (int j = i+1; j < size; j++)
                    if (children[j].age < children[min].age) min = j;
                swap(children[i], children[min]);
            }setColor(2);
            cout << "Selection sort done!\n";
            break;
        case 3:
            for (int i = 1; i < size; i++) {
                Child key = children[i]; int j = i-1;
                while (j >= 0 && children[j].age > key.age)
                    children[j+1] = children[j--];
                children[j+1] = key;
            }setColor(2);
            cout << "Insertion sort done!\n";
            break;
        default: setColor(4); cout << "Invalid!\n";
    }
}
//   SEARCH MENU  
void searchMenu(Child children[], int size) {
    int choice, id;
    cout << "1. Linear\n2. Binary\nChoice: "; cin >> choice;
    cout << "Enter ID: "; cin >> id;
    (choice == 1) ? linearSearch(children, size, id) : binarySearch(children, size, id);
}
void linearSearch(Child children[], int size, int id) {
    for (int i = 0; i < size; i++)
        if (children[i].id == id) {
            setColor(2); cout << "Found: " << children[i].name << "\n"; return;
        } setColor(4);
    cout << "Not found!\n";
}
void binarySearch(Child children[], int size, int id) {
    // sort by id first
    for (int i = 0; i < size-1; i++)
        for (int j = 0; j < size-i-1; j++)
            if (children[j].id > children[j+1].id)
                swap(children[j], children[j+1]);
    int left=0, right=size-1;
    while (left<=right) {
        int mid=(left+right)/2;
        if (children[mid].id == id) {
            setColor(2); cout << "Found: " << children[mid].name << "\n"; return;
        }
        (children[mid].id < id) ? left=mid+1 : right=mid-1;
    } setColor(4);
    cout << "Not found!\n";
}
//  MEDICAL MENU (LINKED LIST) 
void medicalMenu(Child children[], int size) {
    int choice;
    do {
        setColor(8);
        cout << "\nMedical Menu:\n";
        setColor(3);
        cout << "1. Insert Front\n";
        cout << "2. Insert Middle (Position)\n";
        cout << "3. Insert End\n";
        cout << "4. View Records (Traverse)\n";
        cout << "5. Delete at Start\n";
        cout << "6. Delete at End\n";
        cout << "7. Delete at Position\n";
        cout << "8. Search by ChildID\n";
        cout << "9. Update Record by ChildID\n";
        cout << "10. Back\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: system("cls"); insertMedicalFront(children, size); break;
            case 2: system("cls"); insertMedicalPosition(children, size); break;
            case 3: system("cls"); insertMedicalEnd(children, size); break;
            case 4: system("cls"); displayMedicalRecords(); break;
            case 5: system("cls"); deleteMedicalFront(); break;
            case 6: system("cls"); deleteMedicalEnd(); break;
            case 7: system("cls"); deleteMedicalPosition(); break;
            case 8: system("cls"); searchMedicalRecord(children, size); break;
            case 9: system("cls"); updateMedicalRecord(children, size); break;
            case 10: system("cls"); return;
            default: setColor(4); cout << "Invalid!\n";
        }
    } while (choice != 10);
}
//  MEDICAL FUNCTIONS 
void insertMedicalFront(Child children[], int size) {
    Node* n = new Node;
    cout << "Enter ChildID: ";
    cin >> n->data.childID;
    if (!childExists(children, size, n->data.childID)) {
        setColor(4); cout << "Child does not exist!\n";
        delete n;
        return;
    }
    cout << "Enter Date, Doctor, Diagnosis & Treatment:\n";
    cin >> ws; getline(cin, n->data.checkupDate);
    getline(cin, n->data.doctorName); getline(cin, n->data.diagnosis);
    getline(cin, n->data.treatment);
    n->next = head; head = n; setColor(2);
    cout << "Inserted at front!\n";
}
void insertMedicalEnd(Child children[], int size) {
    Node* n = new Node;
    cout << "Enter ChildID: ";
    cin >> n->data.childID;
    if (!childExists(children, size, n->data.childID)) {
        setColor(4); cout << "Child does not exist!\n";
        delete n;
        return;
    }
    cout << "Enter Date Doctor Diagnosis Treatment:\n";
    cin >> ws; getline(cin, n->data.checkupDate);
    getline(cin, n->data.doctorName); getline(cin, n->data.diagnosis);
    getline(cin, n->data.treatment);
    n->next = nullptr;
    if (!head) head = n;
    else {
        Node* temp=head; while (temp->next) temp=temp->next;
        temp->next=n;
    } setColor(2);
    cout << "Inserted at end!\n";
}
void insertMedicalPosition(Child children[], int size) {
    int pos; cout << "Enter position: "; cin >> pos;
    if (pos==0) { insertMedicalFront(children, size); return; }
    Node* temp=head;
    for (int i=0;i<pos-1 && temp;i++) temp=temp->next;
    if (!temp) { cout << "Invalid pos!\n"; return; }
    Node* n=new Node;
    cout << "Enter ChildID: ";
    cin >> n->data.childID;
    if (!childExists(children, size, n->data.childID)) {
        setColor(4); cout << "Child does not exist!\n";
        delete n;
        return;
    }
    cout << "Enter Date, Doctor, Diagnosis, Treatment:\n";
    cin >> ws; getline(cin, n->data.checkupDate);
    getline(cin, n->data.doctorName); getline(cin, n->data.diagnosis);
    getline(cin, n->data.treatment);
    n->next=temp->next; temp->next=n; setColor(2);
    cout << "Inserted at position!\n";
}
void displayMedicalRecords() {
    if (!head) { setColor(4); cout << "No records!\n"; return; }
    Node* temp=head;
    while (temp) {
        cout << "ChildID: " << temp->data.childID
             << ", Date: " << temp->data.checkupDate
             << ", Doctor: " << temp->data.doctorName
             << ", Diagnosis: " << temp->data.diagnosis
             << ", Treatment: " << temp->data.treatment << "\n";
        temp=temp->next;
    }
}
// NEW: Delete at start
void deleteMedicalFront() {
    if (!head) { setColor(4); cout << "No records to delete!\n"; return; }
    Node* toDel = head;
    head = head->next;
    delete toDel;
    setColor(2); cout << "Record deleted from start!\n";
}
// NEW: Delete at end
void deleteMedicalEnd() {
    if (!head) { setColor(4); cout << "No records to delete!\n"; return; }
    if (!head->next) { delete head; head = nullptr; setColor(2); cout << "Last record deleted!\n"; return; }
    Node* temp = head;
    while (temp->next && temp->next->next) temp = temp->next;
    // temp->next is last
    delete temp->next;
    temp->next = nullptr;
    setColor(2); cout << "Record deleted from end!\n";
}
// NEW: Delete at position
void deleteMedicalPosition() {
    if (!head) { setColor(4); cout << "No records to delete!\n"; return; }
    int pos; cout << "Enter position to delete (0 = first): "; cin >> pos;
    if (pos < 0) { setColor(4); cout << "Invalid position!\n"; return; }
    if (pos == 0) { deleteMedicalFront(); return; }
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp; ++i) temp = temp->next;
    if (!temp || !temp->next) { setColor(4); cout << "Position out of range!\n"; return; }
    Node* toDel = temp->next;
    temp->next = toDel->next;
    delete toDel;
    setColor(2); cout << "Record deleted at position " << pos << "!\n";
}
// NEW: Search by ChildID
void searchMedicalRecord(Child children[], int size) {
    if (!head) { setColor(4); cout << "No records!\n"; return; }
    int id; cout << "Enter ChildID to search: "; cin >> id;
    if (!childExists(children, size, id)) {
        setColor(4); cout << "Child does not exist!\n";
        return;
    }
    Node* temp = head;
    int pos = 0;
    while (temp) {
        if (temp->data.childID == id) {
            setColor(2);
            cout << "Found at position " << pos << " -> "
                 << "ChildID: " << temp->data.childID
                 << ", Date: " << temp->data.checkupDate
                 << ", Doctor: " << temp->data.doctorName
                 << ", Diagnosis: " << temp->data.diagnosis
                 << ", Treatment: " << temp->data.treatment << "\n";
            return;
        }
        temp = temp->next; pos++;
    }
    setColor(4); cout << "Record not found!\n";
}
//Update record by ChildID
void updateMedicalRecord(Child children[], int size) {
    if (!head) { setColor(4); cout << "No records!\n"; return; }
    int id; cout << "Enter ChildID to update: "; cin >> id;
    if (!childExists(children, size, id)) {
        setColor(4); cout << "Child does not exist!\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        if (temp->data.childID == id) {
            setColor(3);
            cout << "Current -> Date: " << temp->data.checkupDate
                 << ", Doctor: " << temp->data.doctorName
                 << ", Diagnosis: " << temp->data.diagnosis
                 << ", Treatment: " << temp->data.treatment << "\n";
            cout << "Enter new Date: "; cin >> ws; getline(cin, temp->data.checkupDate);
            cout << "Enter new Doctor: "; getline(cin, temp->data.doctorName);
            cout << "Enter new Diagnosis: "; getline(cin, temp->data.diagnosis);
            cout << "Enter new Treatment: "; getline(cin, temp->data.treatment);
            setColor(2); cout << "Record updated!\n";
            return;
        }
        temp = temp->next;
    }
    setColor(4); cout << "Record not found!\n";
}
void freeMedicalList() {
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = nullptr;
}
// DONATION STACK IMPLEMENTATION (linked list) 
void pushDonation(const Donation &d) {
    DNode* n = new DNode(d);
    n->next = donationTop;
    donationTop = n;
}
bool isDonationStackEmpty() {
    return donationTop == nullptr;
}
Donation popDonation() {
    Donation tmp = donationTop->data;
    DNode* toDel = donationTop;
    donationTop = donationTop->next;
    delete toDel;
    return tmp;
}
Donation peekDonation() {
    return donationTop->data;
}
void displayDonations() {
    if (isDonationStackEmpty()) { setColor(4); cout << "No donation records!\n"; return; }
    cout << left << setw(6) << "ID" << setw(8) << "ChildID" << setw(20) << "Donor" << setw(10) << "Amount" << setw(15) << "Date" << setw(20) << "Item\n";
    cout << string(85, '-') << "\n";
    DNode* temp = donationTop;
    while (temp) {
        cout << left << setw(6) << temp->data.donationID
             << setw(8) << temp->data.childID
             << setw(20) << temp->data.donorName
             << setw(10) << temp->data.amount
             << setw(15) << temp->data.date
             << setw(20) << temp->data.item << "\n";
        temp = temp->next;
    }
}
void freeDonationStack() {
    while (donationTop) {
        DNode* nxt = donationTop->next;
        delete donationTop;
        donationTop = nxt;
    }
}
// DONATION MENU 
void donationMenu(Child children[], int &size) {
    int choice;
    do {
        setColor(8);
        cout << "\n--- DONATION HISTORY (STACK) ---\n";
        setColor(3);
        cout << "1. Add Donation (Push)\n";
        cout << "2. Remove Last Donation (Pop)\n";
        cout << "3. View Last Donation (Top)\n";
        cout << "4. Display All Donations\n";
        cout << "5. Back\n";
        setColor(13);
        cout << "Enter choice: "; cin >> choice;
        system("cls");
        switch (choice) {
            case 1: {
                setColor(3);
                cout << "--- Add Donation (Push) ---\n";
                Donation d;
                d.donationID = donationAutoID++;
                cout << "Child ID: "; cin >> d.childID;
                if (!childExists(children, size, d.childID)) {
                    setColor(4); cout << "Child does not exist!\n";
                    --donationAutoID; 
                    break;
                }
                cout << "Donor Name: "; cin >> ws; getline(cin, d.donorName);
                cout << "Amount: "; cin >> d.amount; cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Date (dd-mm-yyyy): "; getline(cin, d.date);
                cout << "Item (e.g., clothes/shoes/stuff): "; getline(cin, d.item);
                pushDonation(d);
                setColor(2); cout << "Donation pushed (ID: " << d.donationID << ").\n";
                break;
            }
            case 2: {
                setColor(3);
                cout << "--- Remove Last Donation (Pop) ---\n";
                if (isDonationStackEmpty()) { setColor(4); cout << "Stack empty!\n"; }
                else {
                    Donation d = popDonation();
                    setColor(2);
                    cout << "Popped donation ID " << d.donationID << ", ChildID: " << d.childID << ", Donor: " << d.donorName << ", Amount: " << d.amount << ", Item: " << d.item << "\n";
                }
                break;
            }
            case 3: {
                setColor(3);
                cout << "--- View Last Donation (Top) ---\n";
                if (isDonationStackEmpty()) { setColor(4); cout << "Stack empty!\n"; }
                else {
                    Donation d = peekDonation();
                    setColor(2);
                    cout << "Top donation ID " << d.donationID << ", ChildID: " << d.childID << ", Donor: " << d.donorName << ", Amount: " << d.amount << ", Item: " << d.item << "\n";
                }
                break;
            }
            case 4: {
                setColor(3);
                cout << "--- All Donations (Top -> Bottom) ---\n";
                displayDonations();
                break;
            }
            case 5:
                return;
            default:
                setColor(4); cout << "Invalid!\n";
        }
    } while (choice != 5);
}
//  ADOPTION QUEUE IMPLEMENTATION (linked list) 
void enqueueRequest(const Request &r) {
    QNode* n = new QNode(r);
    if (!qFront) { qFront = qRear = n; }
    else { qRear->next = n; qRear = n; }
}
bool isQueueEmpty() {
    return qFront == nullptr;
}
Request dequeueRequest() {
    Request tmp = qFront->data;
    QNode* toDel = qFront;
    qFront = qFront->next;
    if (!qFront) qRear = nullptr;
    delete toDel;
    return tmp;
}
Request frontRequest() {
    return qFront->data;
}
Request rearRequest() {
    return qRear->data;
}
void displayQueue() {
    if (isQueueEmpty()) { setColor(4); cout << "No adoption requests!\n"; return; }
    cout << left << setw(6) << "ReqID" << setw(8) << "ChildID" << setw(20) << "Adopter" << setw(15) << "Contact" << setw(12) << "Date" << setw(10) << "Status\n";
    cout << string(80, '-') << "\n";
    QNode* temp = qFront;
    while (temp) {
        cout << left << setw(6) << temp->data.requestID
             << setw(8) <<  temp->data.childID
             << setw(20) << temp->data.adopterName
             << setw(15) << temp->data.contact
             << setw(12) << temp->data.date
             << setw(10) << temp->data.status << "\n";
        temp = temp->next;
    }
}
void freeRequestQueue() {
    while (qFront) {
        QNode* nxt = qFront->next;
        delete qFront;
        qFront = nxt;
    }
    qRear = nullptr;
}
//  ADOPTION MENU  
void adoptionMenu(Child children[], int &size) {
    int choice;
    do {
        setColor(8);
        cout << "\n--- ADOPTION REQUESTS (QUEUE) ---\n";
        setColor(3);
        cout << "1. Add Request (Enqueue)\n";
        cout << "2. Serve Next Request (Dequeue + Approve/Reject)\n";
        cout << "3. View Front Request\n";
        cout << "4. View Rear Request\n";
        cout << "5. Display All Requests\n";
        cout << "6. Back\n";
        setColor(13);
        cout << "Enter choice: "; cin >> choice;
        system("cls");
        switch (choice) {
            case 1: {
                setColor(3);
                cout << "--- Add Adoption Request (Enqueue) ---\n";
                Request r;
                r.requestID = requestAutoID++;
                cout << "Child ID: "; cin >> r.childID;
                if (!childExists(children, size, r.childID)) {
                    setColor(4); cout << "Child does not exist!\n";
                    --requestAutoID; 
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Adopter Name: "; getline(cin, r.adopterName);
                cout << "Contact: "; getline(cin, r.contact);
                cout << "Date (dd-mm-yyyy): "; getline(cin, r.date);
                r.status = "pending";
                enqueueRequest(r);
                setColor(2); cout << "Request enqueued (ReqID: " << r.requestID << ").\n";
                break;
            }
            case 2: {
                setColor(3);
                cout << "--- Serve Next Request (Dequeue) ---\n";
                if (isQueueEmpty()) { setColor(4); cout << "No requests!\n"; }
                else {
                    Request r = frontRequest();
                    cout << "RequestID: " << r.requestID << ", ChildID: " << r.childID << ", Adopter: " << r.adopterName << ", Contact: " << r.contact << ", Date: " << r.date << ", Status: " << r.status << "\n";
                    cout << "Approve this request? (y/n): ";
                    char ch; cin >> ch; cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (ch == 'y' || ch == 'Y') {
                        Request served = dequeueRequest();
                        setColor(2); cout << "Request approved and dequeued (ReqID: " << served.requestID << ").\n";
                        cout << "Do you want to remove child record (ID " << served.childID << ") from children list? (y/n): ";
                        char ch2; cin >> ch2; cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if (ch2 == 'y' || ch2 == 'Y') {
                            bool removed = removeChildByID(children, size, served.childID);
                            if (removed) setColor(2), cout << "Child record removed (adopted).\n";
                            else setColor(4), cout << "Child ID not found in records.\n";
                        }
                    } else {
                        Request rejected = dequeueRequest();
                        setColor(4); cout << "Request rejected and dequeued (ReqID: " << rejected.requestID << ").\n";
                    }
                }
                break;
            }
            case 3: {
                setColor(3);
                cout << "--- Front Request ---\n";
                if (isQueueEmpty()) setColor(4), cout << "No requests!\n";
                else {
                    Request r = frontRequest();
                    setColor(2);
                    cout << "RequestID: " << r.requestID << ", ChildID: " << r.childID << ", Adopter: " << r.adopterName << ", Contact: " << r.contact << ", Date: " << r.date << ", Status: " << r.status << "\n";
                }
                break;
            }
            case 4: {
                setColor(3);
                cout << "--- Rear Request ---\n";
                if (isQueueEmpty()) setColor(4), cout << "No requests!\n";
                else {
                    Request r = rearRequest();
                    setColor(2);
                    cout << "RequestID: " << r.requestID << ", ChildID: " << r.childID << ", Adopter: " << r.adopterName << ", Contact: " << r.contact << ", Date: " << r.date << ", Status: " << r.status << "\n";
                }
                break;
            }
            case 5: {
                setColor(3);
                cout << "--- All Adoption Requests (Front -> Rear) ---\n";
                displayQueue();
                break;
            }
            case 6:
                return;
            default:
                setColor(4); cout << "Invalid!\n";
        }
    } while (choice != 6);
}
//  HELPER FUNCTIONS 
bool childExists(Child children[], int size, int id) {
    for (int i = 0; i < size; ++i) {
        if (children[i].id == id) return true;
    }
    return false;
}
void removeMedicalByChildID(int id) {
    Node* curr = head;
    Node* prev = nullptr;
    while (curr) {
        if (curr->data.childID == id) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            Node* del = curr;
            curr = curr->next;
            delete del;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
}
void removeDonationsByChildID(int id) {
    DNode* tempTop = nullptr;
    while (donationTop) {
        DNode* cur = donationTop;
        donationTop = donationTop->next;
        if (cur->data.childID != id) {
            cur->next = tempTop;
            tempTop = cur;
        } else {
            delete cur;
        }
    }
    while (tempTop) {
        DNode* cur = tempTop;
        tempTop = tempTop->next;
        cur->next = donationTop;
        donationTop = cur;
    }
}
void removeRequestsByChildID(int id) {
    QNode* tempFront = nullptr;
    QNode* tempRear = nullptr;
    while (qFront) {
        QNode* cur = qFront;
        qFront = qFront->next;
        if (cur->data.childID != id) {
            cur->next = nullptr;
            if (!tempFront) tempFront = tempRear = cur;
            else { tempRear->next = cur; tempRear = cur; }
        } else {
            delete cur;
        }
    }
    qFront = tempFront;
    qRear = tempRear;
}