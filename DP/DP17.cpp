#include<iostream>
#include<vector>

using namespace std;

int subsetSum(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return 1;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = subsetSum(ind-1,target,arr,dp);
    
    int taken=0;
    if(arr[ind]<=target)
        taken = subsetSum(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken+taken;
}



int main() {

  int n,temp,k;
  cout<<"Enter size of array:";
  cin>>n;

   cout<<"Enter array elements:";

  vector<int> arr; 
  for(int i=0;i<n;i++)
  {
       cin>>temp;
       arr.push_back(temp);
  }
  
  cout<<"Enter Target Sum";
  cin>>k;

  vector<vector<int>> dp(n,vector<int>(k+1,-1));
                                 
  int res=subsetSum(n-1,k,arr,dp);
   
  cout<<res; 
}