#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class linkedList {

    Node* head;
    Node* tail;

public:
    linkedList() {
        head = tail = NULL;
    }
//push_front
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
//pop_front
    void pop_front() {
         Node* toDelete = head;
            head = head->next;
            if (head == NULL) tail = NULL; 
            delete toDelete;
    }
//print
    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
//insertAtPosition
    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) { 
            tail = newNode;
        }
    }
//deleteAtPosition
    void deleteNode(int pos) {
        if (pos < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos == 0) {
           pop_front();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next == NULL) tail = temp; 
        delete toDelete;
    }
//search
void search( int val){
	int index =0;
	Node* temp = head;
	while(temp!= NULL){
	
		if(temp -> data == val){
		   cout<<index;
		}
		temp = temp -> next;
		index++;
	}		
}
};

int main() {
    linkedList ll;

    ll.push_front(1);  // add value
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    
    cout<<"Linked List \n";
    ll.printLL();     //print
    
    cout<<"\nInsertion \n";
    ll.insert(10, 2);  //insert
    ll.printLL();
    
    cout<<"\nDeletion \n";
    ll.deleteNode(2);   // delete
    ll.printLL();
    
    cout<<"\nSearch \n";  //search
    ll.search(3);
    return 0;
}
