#include <iostream>
using namespace std;
struct Node
{
    string name;
    Node* next;
};
void arrive(Node*& front, Node*& rear, string name)
{
    Node* newNode = new Node;
    newNode->name = name;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void attend(Node*& front, Node*& rear)
{
    if (front == NULL)
    {
        cout << "Error: No patients waiting.\n";
        return;
    }
    Node* temp = front;
    cout << "Patient attended: " << front->name << endl;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    delete temp;
}
void displayFront(Node* front)
{
    if (front == NULL)
    {
        cout << "No patients waiting.\n";
    }
    else
    {
        cout << "Current front patient: "
             << front->name << endl;
    }
}
int main()
{
    Node* front = NULL;
    Node* rear = NULL;
    int choice;
    string name;
    do
    {
        cout << "\n--- HOSPITAL QUEUE ---\n";
        cout << "1. Patient Arrive\n";
        cout << "2. Patient Attend\n";
        cout << "3. Display Front Patient\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter patient name: ";
            cin >> name;
            arrive(front, rear, name);
            displayFront(front);
            break;
        case 2:
            attend(front, rear);
            displayFront(front);
            break;
        case 3:
            displayFront(front);
            break;
        case 4:
            cout << "Program ended.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
