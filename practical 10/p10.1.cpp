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
    cout << "Enter number of vehicles: ";
    cin >> n;
    if (n > 10)
    {
        cout << "Parking lot is full. Maximum 10 vehicles allowed.";
        return 0;
    }
    cout << "Enter vehicle registration numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        int index = number % 10;
        int start = index;
        while (hashTable[index] != -1)
        {
            index = (index + 1) % 10;
            if (index == start)
            {
                cout << "Parking lot is full!" << endl;
                break;
            }
        }
        if (hashTable[index] == -1)
        {
            hashTable[index] = number;
        }
    }
    cout << endl;
    cout << "Final Parking Slots:" << endl;
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
