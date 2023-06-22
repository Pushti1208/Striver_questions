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

bool partition(int n, vector<int> &arr){
    
    int totSum=0;
    
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2!=0) return false;
    
    else{
        int half = totSum/2;
        vector<vector<int>> dp(n,vector<int>(half+1,-1));
        return subsetSum(n-1, half ,arr,dp);
    } 
}

int main() {

  int n,temp;
  cout<<"Enter size of array:";
  cin>>n;

   cout<<"Enter array elements:";

  vector<int> arr; 
  for(int i=0;i<n;i++)
  {
       cin>>temp;
       arr.push_back(temp);
  }
  
  
                                 
  if(partition(n,arr))
    cout<<"Array can be partitioned into two equal subsets";
  else 
    cout<<" Array cannot be partitioned into two equal subsets";
}