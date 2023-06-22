#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minimumCoinsTotal(vector<int>& arr, int ind, int Target, vector<vector<int>>& dp){

    if(ind == 0){
        if(Target%arr[0] == 0) return Target/arr[0];
        else return 1e9;
    }
    
    if(dp[ind][Target]!=-1)
        return dp[ind][Target];
        
    int notTaken = 0 + minimumCoinsTotal(arr,ind-1,Target,dp);
    
    int taken = 1e9;
    if(arr[ind] <= Target)
        taken = 1 + minimumCoinsTotal(arr,ind,Target-arr[ind],dp);
        
    return dp[ind][Target] = min(notTaken,taken);
}


int minimumCoins(vector<int>& arr, int Target){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(Target+1,-1));
    int ans =  minimumCoinsTotal(arr, n-1, Target, dp);
    if(ans >= 1e9) return -1;
    return ans;
}

int main() {

  int n;
  cout<<"Enter n:";
  cin>>n;
  vector<int> arr;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    arr.push_back(temp);
  }
  int Target;
  cout<<"Enter target:";
  cin>>Target;
                                 
  cout<<"The minimum number of coins are "  <<minimumCoins(arr,Target);
}