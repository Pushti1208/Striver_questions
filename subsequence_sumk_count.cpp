#include<iostream>
#include<vector>
using namespace std;


int subsequenceSumK(int index,int arr[],int n,int K,int sum)
{
      if(index==n)
      {   
        if(sum==K)
        {
           return 1;
        }
       return 0;
      }

    
    sum=sum+arr[index];

    int left=subsequenceSumK(index+1,arr,n,K,sum);

    sum=sum-arr[index];


    int right=subsequenceSumK(index+1,arr,n,K,sum);

    return left+right;
    



}

int main()
{
    int n,K;
    cout<<"Enter number of array elements:";
    cin>>n;
    int arr[n];


     for(int i=0;i<n;i++)
     {
        cin>>arr[i];
     }  

     cout<<"Enter K";
     cin>>K;  

     vector<int> v;

     cout<<subsequenceSumK(0,arr,n,K,0);  
}