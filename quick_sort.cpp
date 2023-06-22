#include<iostream>
using namespace std;

int partition(int arr[],int low,int high)
{
   int pivot=arr[low];
   int i=low;
   int j=high;

    while(i<j)
    {
       while(arr[i]<=pivot && i<=high)
       {
        i++;
       }
       while(arr[j]>pivot && j>=low)
       {
        j--;
       }

       if(i<j)
       {
           int temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
       }
   }

   int temp=arr[j];
   arr[j]=arr[low];
   arr[low]=temp;

   return j;

   int temp1=arr[j];
   arr[j]=pivot;
   arr[low]=temp1;

   return j;

}

void Quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);

        Quick_sort(arr,low,p);
        Quick_sort(arr,p+1,high);
    }
}

int main()
{
     int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Quick_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}