#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of entries:";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter 0,1 or 2 ONLY."<<endl;
        cin >> arr[i];
    }
    int zero = 0, one = 0, two = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            zero++;
        else if(arr[i] == 1)
            one++;
        else if(arr[i] == 2)
            two++;
    }
    int i = 0;
    while(zero--)
        arr[i++] = 0;
    while(one--)
        arr[i++] = 1;
    while(two--)
        arr[i++] = 2;

    cout<<"Rearranged colour codes are:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
     /* tried using for loop but didn't work
     for(int i=zero;i>=0;i--)
        {
            arr[i]=0;
        }
        for(int i=one;i>=0;i--)
        {
            arr[i]=1;
        }
        for(int i=two;i>=0;i--)
        {
            arr[i]=2;
        }*/
