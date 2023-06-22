#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int knapsackTotal(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        if(wt[0] <=W) return val[0];
        else return 0;
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackTotal(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackTotal(wt,val,ind-1,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}


int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return knapsackTotal(wt, val, n-1, W, dp);
}

int main() {

  int n,temp;
  cout<<"Enter size of weigt and value array:";
  cin>>n;
  vector<int> wt ;
  vector<int> val ;
  cout<<"Enter weight matrix:";
  for(int i=0;i<n;i++)
  { 
      cin>>temp;
      wt.push_back(temp);
  }

   cout<<"Enter value matrix:";
  for(int i=0;i<n;i++)
  { 
      cin>>temp;
      val.push_back(temp);
  }

  int W;
  cout<<"Enter total weight of bag: ";
  cin>>W;
  
  
                                 
  cout<<"The Maximum value of items, thief can steal is " <<knapsack(wt,val,n,W);
}