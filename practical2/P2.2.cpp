#include<iostream>

using namespace std;

int main()
{
  cout<<"Enter Number of Entries:";
  int n;
  cin>>n;
   int book_code[n];
   for(int i=0;i<n;i++)
   {
       cin>>book_code[i];
   }
   cout<<"Enter book code to search:";
   int code;
   cin>>code;
   int low=0;
   int high=n-1;
   int mid;
   while(low<=high)
   {
       mid=(low+high)/2;
       if(code==book_code[mid]){
        cout<<"Element found at index :"<<mid+1;
        break;
       }
       else if(code>book_code[mid])
       {
           low=mid+1;
       }
       else if(code<book_code[mid])
       {
           high=mid-1;
       }

   }

}
