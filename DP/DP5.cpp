#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max_sum(int arr[],int index,vector<int> &dp)
{
    if(index==0)
      return arr[index];
    if(index<0)
       return 0;

     if(dp[index]!=-1)
        return dp[index];  

    int pick=arr[index]+max_sum(arr,index-2,dp);

    int notPick=0+max_sum(arr,index-1,dp);

    return dp[index]=max(pick,notPick);   
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

    vector<int> dp(n+1,-1);
    cout<<max_sum(arr,n-1,dp);
}