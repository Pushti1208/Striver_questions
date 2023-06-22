#include<iostream>
#include<vector>
using namespace std;


void subsequenceSumK(int index,int arr[],vector<int>&v,int n,int K,int sum)
{
      if(index==n)
      {   
        if(sum==K)
        {
            for(auto it:v)
           {
             cout<<it<<" ";
           }
          cout<<endl;
       }
       return;
      }

    v.push_back(arr[index]);
    sum=sum+arr[index];

    subsequenceSumK(index+1,arr,v,n,K,sum);

    sum=sum-arr[index];

    v.pop_back();

    subsequenceSumK(index+1,arr,v,n,K,sum);
    



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

     subsequenceSumK(0,arr,v,n,K,0);  
}