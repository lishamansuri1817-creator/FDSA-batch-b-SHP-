#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of inputs:";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cout<<i+1<<". Enter book id borrowed:";
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
                count++;
        }
        if(count > 1)
        {
            int k;
            for(k = 0; k < i; k++)
            {
                if(arr[k] == arr[i])
                    break;
            }
            if(k == i)
                cout << arr[i] << " was borrowed "<<count<<" times."<<endl;
        }
    }
    return 0;
}
