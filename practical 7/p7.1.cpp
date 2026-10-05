#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;
    int queue[n];
    int front = 0;
    int rear = -1;
    int count = 0;
    int choice, value;
    do
    {
        cout << "\n--- TOKEN COUNTER ---\n";
        cout << "1. Join\n";
        cout << "2. Serve\n";
        cout << "3. Display Front\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (count == n)
            {
                cout << "Error: Queue is full. Cannot join.\n";
            }
            else
            {
                cout << "Enter token number: ";
                cin >> value;
                rear = (rear + 1) % n;
                queue[rear] = value;
                count++;
                cout << "Token added successfully.\n";
                cout << "Current front token: "<< queue[front] << endl;
            }
            break;
        case 2:
            if (count == 0)
            {
                cout << "Error: Queue is empty. Cannot serve.\n";
            }
            else
            {
                cout << "Token served: "<< queue[front] << endl;
                front = (front + 1) % n;
                count--;
                if (count > 0)
                    cout << "Current front token: "<< queue[front] << endl;
                else
                    cout << "Queue is now empty.\n";
            }
            break;
        case 3:
            if (count == 0)
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Current front token: "<< queue[front] << endl;
            }
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
