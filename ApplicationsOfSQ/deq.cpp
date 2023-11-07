#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> myDeque;

    while (true) {
        int choice;
        cout << "Double Ended Queue (Deque) Menu:" << endl;
        cout << "1. Enqueue from front" << endl;
        cout << "2. Enqueue from back" << endl;
        cout << "3. Dequeue from front" << endl;
        cout << "4. Dequeue from back" << endl;
        cout << "5. Display Deque" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    int value;
                    cout << "Enter a value to enqueue from the front: ";
                    cin >> value;
                    myDeque.push_front(value);
                    break;
                }
            case 2:
                {
                    int value;
                    cout << "Enter a value to enqueue from the back: ";
                    cin >> value;
                    myDeque.push_back(value);
                    break;
                }
            case 3:
                if (!myDeque.empty()) {
                    myDeque.pop_front();
                    cout << "Dequeued from the front." << endl;
                } else {
                    cout << "Deque is empty. Cannot dequeue from the front." << endl;
                }
                break;
            case 4:
                if (!myDeque.empty()) {
                    myDeque.pop_back();
                    cout << "Dequeued from the back." << endl;
                } else {
                    cout << "Deque is empty. Cannot dequeue from the back." << endl;
                }
                break;
            case 5:
                cout << "Deque elements: ";
                for (int element : myDeque) {
                    cout << element << " ";
                }
                cout << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
