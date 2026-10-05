#include <iostream>
using namespace std;
int main()
{
    int hashTable[10];
    for (int i = 0; i < 10; i++)
    {
        hashTable[i] = -1;
    }
    int n;
    cout << "Enter number of student IDs: ";
    cin >> n;
    if (n > 10)
    {
        cout << "Table can store maximum 10 IDs.";
        return 0;
    }
    cout << "Enter student IDs:" << endl;
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        int index = id % 10;
        int jump = 7 - (id % 7);
        int start = index;
        while (hashTable[index] != -1)
        {
            index = (index + jump) % 10;
            if (index == start)
            {
                cout << "No suitable slot available for ID "
                     << id << endl;
                break;
            }
        }
        if (hashTable[index] == -1)
        {
            hashTable[index] = id;
        }
    }
    cout << endl;
    cout << "Final Hash Table:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Slot " << i << ": ";
        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];
        cout << endl;
    }
    return 0;
}
