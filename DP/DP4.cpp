#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int frog_jump(int ind,vector<int> &dp,int height[],int k)
{
     if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      int jump = frog_jump(ind-j, dp,height , k)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
    
}

int main()
{
    int n,k;
    cout<<"Enter n:";
    cin>>n;

    int height[n];

    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }
    cout<<"Enter k:";
    cin>>k;
    vector<int> dp(n+1,-1);

    cout<<frog_jump(n-1,dp,height,k);
}
