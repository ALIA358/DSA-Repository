#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> road;   // Queue for trucks on the road
stack<int> garage; // Stack for trucks inside the garage

// add truck on the road
void On_road(int truck_id) {
    road.push(truck_id);
    cout << "Truck " << truck_id << " is now on the road." << endl;
}

//  move truck from road to garage
void Enter_garage(int truck_id) {
    if (!road.empty() && road.front() == truck_id) {
        road.pop();
        garage.push(truck_id);
        cout << "Truck " << truck_id << " entered the garage." << endl;
    } else {
        cout << "Truck " << truck_id << " is not at the front of the road queue." << endl;
    }
}

//  remove truck from garage
void Exit_garage(int truck_id) {
    if (!garage.empty() && garage.top() == truck_id) {
        garage.pop();
        cout << "Truck " << truck_id << " exited the garage." << endl;
    } else {
        cout << "Truck is not near garage door." << endl;
    }
}

// Function to show trucks
void Show_trucks(string place) {
    if (place == "road") {
        queue<int> temp = road;
        cout << "Trucks on road: ";
        if (temp.empty()) cout << "None";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    } 
    else if (place == "garage") {
        stack<int> temp = garage;
        cout << "Trucks in garage: ";
        if (temp.empty()) cout << "None";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    } 
    else {
        cout << "Invalid place. Use 'road' or 'garage'." << endl;
    }
}

int main() {
    int choice, id;
    string place;

    while (true) {
        cout << "\n1. On_road\n2. Enter_garage\n3. Exit_garage\n4. Show_trucks\n5. Exit program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter truck ID: ";
                cin >> id;
                On_road(id);
                break;
            case 2:
                cout << "Enter truck ID: ";
                cin >> id;
                Enter_garage(id);
                break;
            case 3:
                cout << "Enter truck ID: ";
                cin >> id;
                Exit_garage(id);
                break;
            case 4:
                cout << "Show trucks in (road/garage): ";
                cin >> place;
                Show_trucks(place);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}