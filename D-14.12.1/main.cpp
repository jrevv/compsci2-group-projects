#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class List {
private:
    Node* first;

public:
    List() : first(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if(!first) {
            first = newNode;
            first->next = first;
            first->prev = first;
        }
        else {
            Node* last = first->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = first;
            first->prev = newNode;
        }
    }

    void remove(int val) {
        if(!first) {
            return;
        }
        Node* curr = first;
        do {
            if (curr->data == val) {
                if (curr->next == curr) {
                    delete curr;
                    first = nullptr;
                }
                else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    if (curr == first) {
                        first = curr->next;
                    }
                    delete curr;
                }
                return;
            }
            curr = curr->next;
        }
        while (curr != first);
    }

    void print() const {
        if (!first) {
            return;
        }
        Node* curr = first;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        }
        while (curr != first);
        cout << endl;
    }

    ~List() {
        if (!first) {
            return;
        }
        Node* curr = first->next;
        while (curr != first) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete first;
        first = nullptr;
    }
};

int main() {
    // Testing

    List a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.print();

    a.remove(2);
    cout << "Removing 2: ";
    a.print();

    a.insert(2);
    cout << "Adding 2: ";
    a.print();

    a.remove(1);
    cout << "Removing 1: ";
    a.print();

    a.remove(2);
    cout << "Removing 2: ";
    a.print();

    return 0;
}
