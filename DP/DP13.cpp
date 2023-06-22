#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxChocolatesTotal(int i, int j1, int j2, int n, int m, vector < vector < int >> & grid, vector < vector < vector < int >>> & dp) 
{
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e9;

  if (i == n - 1) {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = INT_MIN;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      int ans;
      if (j1 == j2)
        ans = grid[i][j1] + maxChocolatesTotal(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
      else
        ans = grid[i][j1] + grid[i][j2] + maxChocolatesTotal(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
      maxi = max(maxi, ans);
    }
  }
  return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector < vector < int >> & grid) {

  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int> (m, -1)));

  return maxChocolatesTotal(0, 0, m - 1, n, m, grid, dp);
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

  cout << maximumChocolates(n, m, matrix);
}