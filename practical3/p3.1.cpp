#include<iostream>
using namespace std;
 int main()
 {
     int n;
     cout<<"Enter number of elements:";
     cin>>n;
     int marks[n];
     cout<<"Enter Marks for "<<n<<" students:"<<endl;
     for(int i=0;i<n;i++)
     {
         cin>>marks[i];
     }
     cout<<"===Bubble sort==="<<endl;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n-1;j++)
          {
              if(marks[j]>marks[j+1])
              {
                  int temp=marks[j];
                  marks[j]=marks[j+1];
                  marks[j+1]=temp;
              }
          }
      }
      cout<<"sorted array:";
      for(int i=0;i<n;i++)
      {
          cout<<marks[i]<<"  ";
      }
      cout<<endl;
      cout<<"===Selection sort==="<<endl;
      for(int i=0;i<n;i++)
      {
         int index=i;
         for(int j=i+1;j<n;j++)
         {
             if(marks[j]<marks[index])
             {
                 index=j;
             }
         }
         int temp=marks[i];
         marks[i]=marks[index];
         marks[index]=temp;
      }
      cout<<"sorted array:";
      for(int i=0;i<n;i++)
      {
          cout<<marks[i]<<"  ";
      }
        cout<<endl;
      cout<<"===Insertion sort==="<<endl;
      int k;
      for(int i=1;i<n;i++)
      {
          int temp=marks[i];

          for(k=i-1;k>=0 && marks[k]>temp;k--)
          {
              marks[k+1]=marks[k];
          }
          marks[k+1]=temp;
      }
       cout<<"sorted array:";
      for(int i=0;i<n;i++)
      {
          cout<<marks[i]<<"  ";
      }
        cout<<endl;
}
