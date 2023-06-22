#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


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


     dp[0]= arr[0];
    
     for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }

    cout<<dp[n-1];
    
}