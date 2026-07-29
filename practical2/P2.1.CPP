#include<iostream>
using namespace std;
int main()
{
    string word[5];
    for(int i=0;i<5;i++)
    {
        cin>>word[i];
    }
    cout<<endl;
    cout<<"Enter word you want to search:";
    string s;
    cin>>s;
    for(int i=0;i<5;i++)
    {
       if(s==word[i])
       {
           cout<<"Word "<<s<<" found at position "<<i+1<<endl;
       }
    }
}
