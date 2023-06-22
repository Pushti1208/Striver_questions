#include<iostream>
#include<vector>
using namespace std;

void combination_sum2(int index,int target,int n,int arr[],vector<vector<int>>&ans,vector<int>&ds)
{
    if(target==0)
    {
        ans.push_back(ds);
        return;
    }

    for(int i=index;i<n;i++)
    {
           if(i>index && arr[i]==arr[i-1])
                continue;
           if(arr[i]>target)
                break;  
           ds.push_back(arr[i]);
           combination_sum2(index+1,target-arr[i],n,arr,ans,ds);
           ds.pop_back();     
     }
}

int main()
{
       int n;
       cout<<"Enter n:";
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
       vector<int> ds;


       combination_sum2(0,target,n,arr,ans,ds);

        for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


}