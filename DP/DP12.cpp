#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int getMaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;
}

int main() {

  int n,m;

  cout<<"Enter n";
  cin>>n;
  cout<<"Enter m";
  cin>>m;

  vector<vector<int> > matrix(n,vector<int> (m));

  for(int i=0;i<n;i++)
  {
       for(int j=0;j<m;j++)
       {
            cin>>matrix[i][j];
       }
  }
  
  cout<<getMaxPathSum(matrix);
}
