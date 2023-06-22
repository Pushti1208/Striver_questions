
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;

    int height[n];
    int fj;
    int sj=INT_MAX;

    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }

    vector<int> dp(n,-1);
     
    dp[0]=0;

    for(int i=1;i<n;i++) 
    {
        fj=dp[i-1]+abs(height[i]-height[i-1]);

        if(i>1)
        {
            sj=dp[i-2]+abs(height[i]-height[i-2]);
        }
        
        dp[i]=min(fj,sj);
    }

    cout<<dp[n-1];
}

