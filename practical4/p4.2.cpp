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
void deleteByValue(Node*& head, int value) {

if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL &&
           temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value not found" << endl;
        return;
    }
    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;
}
void displayForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void displayReverse(Node* head) {
if (head == NULL) {
        return;
    }
    displayReverse(head->next);
    cout << head->data << " ";
}
int main() {
    Node* head = NULL;
    insertEnd(head, 101);
    insertEnd(head, 150);
    insertEnd(head, 102);
    insertEnd(head, 103);
    cout << "Original list:" << endl;
    displayForward(head);
    deleteByValue(head, 150);
    cout << "After deletion:" << endl;
    displayForward(head);
    cout << "Reverse order: ";
    displayReverse(head);
    cout << endl;
    return 0;
}
