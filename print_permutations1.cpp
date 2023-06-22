#include<iostream>
#include<vector>
using namespace std;

void print_per(vector<int> &ds,int arr[],int n,vector<vector<int>>&ans,int freq[])
{
      if(ds.size()==n)
      {
           ans.push_back(ds);
           return;
      } 

 

    for(int i=0;i<n;i++)
    {
        if(freq[i]==0)
        {
            ds.push_back(arr[i]);
            freq[i]=1;
            print_per(ds,arr,n,ans,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}



int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n],freq[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int>ds;
    vector<vector<int>>ans;

    for(int i=0;i<n;i++)
    {
        freq[i]=0;
    }

    print_per(ds,arr,n,ans,freq);

      for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }




}