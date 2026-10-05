#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
int main()
{
    Node* hashTable[10];
    for (int i = 0; i < 10; i++)
    {
        hashTable[i] = NULL;
    }
    int n;
cout << "Enter number of books: ";
    cin >> n;
        cout << "Enter book codes:" << endl;
    for (int i = 0; i < n; i++)
    {
        int code;
        cin >> code;
        int index = code % 10;
        Node* newNode = new Node();
        newNode->data = code;
        newNode->next = NULL;
        if (hashTable[index] == NULL)
        {
            hashTable[index] = newNode;
        }
        else
        {
            Node* temp = hashTable[index];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    cout << endl;
    cout << "Final Shelf Contents:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Shelf " << i << ": ";
        Node* temp = hashTable[i];
        if (temp == NULL)
        {
            cout << "Empty";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
    return 0;
}
