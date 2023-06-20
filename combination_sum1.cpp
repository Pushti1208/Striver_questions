#include<iostream>
#include<vector>
using namespace std;

void combination_sum(int index,int target,int n,int arr[],vector<vector<int>> &ans,vector<int> &ds)
{
    if(index==n)
    {
        if(target==0)
        {
            ans.push_back(ds);
        }

        return ;
    }

    if(arr[index]<=target)
    {
        ds.push_back(arr[index]);
        combination_sum(index,target-arr[index],n,arr,ans,ds);
        ds.pop_back();
    }

    combination_sum(index+1,target,n,arr,ans,ds);




}

int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;
    
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int target;
    cout<<"Enter target sum:";
    cin>>target;

    vector<vector<int>>ans;
    vector<int>ds;
    combination_sum(0,target,n,arr,ans,ds);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}


