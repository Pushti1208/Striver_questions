#include<iostream>
#include<vector>

using namespace std;

bool subsetSum(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = subsetSum(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSum(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}

bool subsetSumTargetK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    
    return subsetSum(n-1,k,arr,dp);
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
                                 
  if(subsetSumTargetK(n,k,arr))
    cout<<"Subset is present with given target ";
  else 
    cout<<"Subset is not present";
}