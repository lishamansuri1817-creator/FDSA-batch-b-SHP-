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
class Queue {
    Node* head ;
    Node* tail;
    int length;
public:
    Queue()
    {
    head = nullptr;
    tail = nullptr;
    length = 0;
    }
    void insFront(int val)
    {
        Node* newnode = new Node(val);
        if(head==nullptr)
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
        head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        length++;
    }
    void insPosition(int val,int k)
    {
       if(k<=0)
       {
        insFront(val);
        return;
       }
       if(k>=length)
       {
        insEnd(val);
        return;
       }
       Node* newnode = new Node(val);
       Node* temp = head;
       for(int i=0;i<k-1; i++)
       {
        temp=temp->next;
       }
       newnode->next = temp->next;
       temp->next = newnode;
       length++;
    }
    void Display()
    {
        Node* temp = head;
        while(temp!=nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    int n;
    cout << "Enter the size of queue : ";
    cin >> n;
    while(n--)
    {
        char type;
        int patients,pos;
        cout << "Enter the type : ";
        cin >> type;
        if(type == 'F')
        {
            cout << "Enter the ID of the patient : ";
            cin >> patients;
            q.insFront(patients);
        }
        else if(type=='E')
        {
            cout << "Enter the ID of the patient : ";
            cin >> patients;
            q.insEnd(patients);
        }
        else
        {
            cout << "Enter the ID of the patient : ";
            cin >> patients;
            cout << "Enter the position you want to insert the patient : ";
            cin >> pos;
            q.insPosition(patients,pos);
        }
        q.Display();
    }
    return 0;
}
