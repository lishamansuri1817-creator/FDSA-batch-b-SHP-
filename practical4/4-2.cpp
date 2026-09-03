#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
Node* head = nullptr;
Node* tail = nullptr;
int length = 0;
void insFront(int val)
{
    Node* newnode = new Node(val);
    if(head == nullptr)
    {
        head = tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    length++;
}
void insEnd(int val)
{
    Node* newnode = new Node(val);
    if(head == nullptr)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
    length++;
}
void insPosition(int val, int k)
{
    if(k <= 0)
    {
        insFront(val);
        return;
    }
    if(k >= length)
    {
        insEnd(val);
        return;
    }
    Node* newnode = new Node(val);
    Node* temp = head;
    for(int i = 0; i < k-1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    length++;
}
void deleteByValue(int val)
{
    if(head == nullptr)
        return;
    if(head->data == val)
    {
        Node* temp = head;
        head = head->next;
        if(head == nullptr)
            tail = nullptr;
        delete temp;
        length--;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr && temp->next->data != val)
    {
        temp = temp->next;
    }
    if(temp->next == nullptr)
        return;
    Node* del = temp->next;
    temp->next = del->next;
    if(del == tail)
        tail = temp;
    delete del;
    length--;
}
void Display()
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverseDisplay(Node* temp)
{
    if(temp == nullptr)
        return;

    reverseDisplay(temp->next);
    cout << temp->data << " ";
}
int main()
{
    insEnd(101);
    insEnd(102);
    insEnd(103);
    insEnd(104);
    insEnd(105);
    cout << "Forward: ";
    Display();
    deleteByValue(103);
    cout << "After deletion: ";
    Display();
    cout << "Reverse: ";
    reverseDisplay(head);
    cout << endl;
    return 0;
}
