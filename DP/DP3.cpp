#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int frog_jump(int n,vector<int>&dp,int height[])
{
    int left;
    int right=INT_MAX;
    if(n==0)
    {
        return 0;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }
    
    left=frog_jump(n-1,dp,height)+abs(height[n]-height[n-1]);
   if(n>1)
   {
       right=frog_jump(n-2,dp,height)+abs(height[n]-height[n-2]);
   }
   return dp[n]=min(left,right);   

}

int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;

    int height[n];

    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }

    vector<int> dp(n+1,-1);

    cout<<frog_jump(n-1,dp,height);
}
