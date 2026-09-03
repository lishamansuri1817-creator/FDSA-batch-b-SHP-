#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};
void insertFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtPosition(Node*& head, int value, int position) {
    if (position < 1) {
        cout << "Invalid position" << endl;
        if (position == 1) {
        insertFront(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid position" << endl;
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
}
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = NULL;
    insertFront(head, 101);
    display(head);
    insertEnd(head, 102);
    display(head);
    insertEnd(head, 103);
    display(head);
    insertAtPosition(head, 150, 2);
    display(head);
    insertAtPosition(head, 200, 10);
    display(head);
return 0;
}
