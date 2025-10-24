#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Append a node at the end
    void append(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Display the list
    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int value;

    cout << "Enter numbers to add to the list (enter -1 to stop):\n";

    while (true) {
        cout << "Enter a number: ";
        cin >> value;

        if (value == -1)
            break;

        list.append(value);
    }

    cout << "\nDoubly Linked List: ";
    list.display();

    return 0;
}