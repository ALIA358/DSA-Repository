#include <iostream>
#include <string>
using namespace std;

class Applicant {
public:
    int applicant_id;
    double height;
    double weight;
    string eyesight;
    bool test_done;

    
    Applicant(int id, double h, double w, string e, bool t) {
        applicant_id = id;
        height = h;
        weight = w;
        eyesight = e;
        test_done = t;
    }

   
    Applicant() {
        applicant_id = 0;
        height = 0;
        weight = 0;
        eyesight = "0/0";
        test_done = false;
    }
};

class Node {
public:
    Applicant data;
    Node *next;
    Node *prev;

    Node(Applicant a) {
        data = a;
        next = NULL;
        prev = NULL;
    }
};

class Queue {
public:
    Node *front;
    Node *rear;

    Queue() {
        front = rear = NULL;
    }

    // Add new applicant at end
    void enqueue(Applicant a) {
        Node *newNode = new Node(a);

        if (front == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << "Applicant " << a.applicant_id << " added to the line." << endl;
    }

    // Remove applicant from front 
    void dequeue() {
        if (front == NULL) {
            cout << "Underflow - No applicants left." << endl;
            return;
        }
        Node *temp = front;
        temp->data.test_done = true; 
        cout << "Applicant " << temp->data.applicant_id << " has given the test and removed from line." << endl;

        front = front->next;
        if (front != NULL)
            front->prev = NULL;
        else
            rear = NULL;

        delete temp;
    }

    // Remove applicant from any specific position 
    void removeAtPosition(int pos) {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = front;
        int i = 1;

        while (temp != NULL && i < pos) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Invalid position." << endl;
            return;
        }

        cout << "Applicant " << temp->data.applicant_id << " left the line from position " << pos << "." << endl;

        if (temp == front) {
            dequeue();
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (temp == rear)
            rear = temp->prev;

        delete temp;
    }

    // Display all applicants
    void display() {
        if (front == NULL) {
            cout << "Line is empty." << endl;
            return;
        }

        Node *temp = front;
        cout << "\nCurrent Line (Front to Rear):\n";
        while (temp != NULL) {
            cout << "ID: " << temp->data.applicant_id
                 << ", Height: " << temp->data.height
                 << ", Weight: " << temp->data.weight
                 << ", Eyesight: " << temp->data.eyesight
                 << ", Test Done: " << (temp->data.test_done ? "Yes" : "No") << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    // Adding 7 applicants
    q.enqueue(Applicant(101, 170.5, 68.0, "6/6", false));
    q.enqueue(Applicant(102, 165.0, 60.2, "6/9", false));
    q.enqueue(Applicant(103, 172.3, 75.4, "6/6", false));
    q.enqueue(Applicant(104, 160.8, 55.0, "6/12", false));
    q.enqueue(Applicant(105, 168.9, 62.0, "6/6", false));
    q.enqueue(Applicant(106, 175.0, 80.5, "6/6", false));
    q.enqueue(Applicant(107, 169.2, 70.1, "6/9", false));

    cout << "\n Initial Line " << endl;
    q.display();

    
    cout << "  Applicant at 2nd position has urgency " << endl;
    q.removeAtPosition(2);
    q.display();

    
    cout << " Applicants giving test (dequeue)  " << endl;
    while (q.front != NULL) {
        q.dequeue();
        q.display();
    }

    return 0;
}
