#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node *front; 
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to free remaining nodes (avoid memory leak)
    ~Queue() {
        while (front) {
            pop();
        }
    }

    // Insert element at rear
    void push(int n) {
        Node *newNode = new Node(n);
        if (newNode == nullptr) {               // rare in modern systems, but safe check
            cout << "Overflow" << endl;
            return;
        }
        if (front == nullptr) {                 // queue empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << n << " has been inserted successfully." << endl;
    }

    // Remove element from front
    void pop() {
        if (front == nullptr) {
            cout << "Underflow." << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        cout << temp->data << " has been removed." << endl;
        delete temp;
        if (front == nullptr) {                 // if queue became empty, update rear
            rear = nullptr;
        }
    }

    // Return value at front without removing
    int peek() const {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Display all elements
    void display() const {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue Q;
    Q.display();

    Q.push(10);
    Q.push(24);
    Q.push(28);
    Q.push(32);
    Q.push(30);

    Q.display();

    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();

    
    Q.pop();

    
    int val = Q.peek();
    if (val != -1) cout << "Front element is: " << val << endl;

    return 0;
}
