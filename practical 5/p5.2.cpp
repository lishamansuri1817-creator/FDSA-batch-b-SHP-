#include <iostream>
using namespace std;

struct sllNode
{
    int data;
    sllNode* next;
};

void scllInsert(sllNode*& head, int value)
{
    sllNode* newNode = new sllNode{value, NULL};
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    sllNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}
void scllDelete(sllNode*& head, int value)
{
    if (head == NULL)
        return;
    sllNode* temp = head;
    sllNode* prev = NULL;
    do
    {
        if (temp->data == value)
        {
            if (temp->next == head && temp == head)
            {
                delete temp;
                head = NULL;
                return;
            }
            if (temp == head)
            {
                sllNode* last = head;
                while (last->next != head)
                {
                   last = last->next;
                }
                head = head->next;
                last->next = head;
                delete temp;
                return;
            }
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    cout << "Student not found in SCLL\n";
}
void displayscll(sllNode* head)
{
    cout << "SCLL: ";
    if (head == NULL)
    {
        cout << "Empty\n";
        return;
    }
    sllNode* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
struct dllNode
{
    int data;
    dllNode* prev;
    dllNode* next;
};
void dcllInsert(dllNode*& head, int value)
{
    dllNode* newNode = new dllNode{value, NULL, NULL};
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }
    dllNode* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}
void dcllDelete(dllNode*& head, int value)
{
    if (head == NULL)
        return;
    dllNode* temp = head;
    do
    {
        if (temp->data == value)
        {
            if (temp->next == temp)
            {
                delete temp;
                head = NULL;
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head)
                head = temp->next;
            delete temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Student not found in DCLL\n";
}
void displaydcll(dllNode* head)
{
    cout << "DCLL forward: ";
    if (head == NULL)
    {
        cout << "Empty\n";
        return;
    }
    dllNode* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
    cout << "DCLL backward: ";
    temp = head->prev;
    dllNode* last = temp;
    do
    {
        cout << temp->data << " ";
        temp = temp->prev;

    } while (temp != last);
    cout << endl;
}
int main()
{
    sllNode* sHead = NULL;
    dllNode* dHead = NULL;
    int choice, value;
    do
    {
        cout << "\n===== PASSING GAME =====\n";
        cout << "1. Student Join\n";
        cout << "2. Student Leave\n";
        cout << "3. Display Circle\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter student number: ";
            cin >> value;
            scllInsert(sHead, value);
            dcllInsert(dHead, value);
            cout << "\nAfter Join:\n";
            displayscll(sHead);
            displaydcll(dHead);
            break;
        case 2:
            cout << "Enter student number to leave: ";
            cin >> value;
            scllDelete(sHead, value);
            dcllDelete(dHead, value);
            cout << "\nAfter Leave:\n";
            displayscll(sHead);
            displaydcll(dHead);
            break;
        case 3:
            cout << "\nCurrent Circle:\n";
            displayscll(sHead);
            displaydcll(dHead);
            break;
        case 4:
            cout << "Program ended.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
