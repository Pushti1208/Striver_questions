#include<iostream>
using namespace std;


void reverse(int arr[],int i,int j)
{
      if(i>=j)
      {
           return ;
      }

      int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;

      reverse(arr,i+1,j-1);
}

int main()
{
    int n;
    cout<<"Enter number of array elements=";
    cin>>n;

    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Original Array:";

     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    reverse(arr,0,n-1);
    cout<<"\n"; 
    cout<<"Reversed Array:";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}