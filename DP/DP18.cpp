#include<iostream>
#include<vector>

using namespace std;


int countPartitionstotal(int ind, int target, vector<int>& arr, vector<vector
<int>> &dp){

     if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionstotal(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionstotal(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken);
}

int countPartitions(int d, vector<int>& arr){
    int n = arr.size();
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    
    int s2 = (totSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countPartitionstotal(n-1,s2,arr,dp);
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

  int d;
  cout<<"Enter Difference:";
  cin>>d;
                                 
  cout<<countPartitions(d,arr);
}