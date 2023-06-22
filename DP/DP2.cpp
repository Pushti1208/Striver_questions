#include<iostream>
#include<vector>
using namespace std;

int climbing_stair(int n,vector<int>&dp)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return 1;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }
    
    return dp[n]=climbing_stair(n-1,dp)+climbing_stair(n-2,dp);
}

int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;

    vector<int> dp(n+1,-1);

    cout<<climbing_stair(n,dp);
}