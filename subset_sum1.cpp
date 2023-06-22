#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void subset_sum1(int index,int arr[],int n,vector<int>&ans,int sum)
{
   if(index==n)
   {
        ans.push_back(sum);
        return;
   }
   subset_sum1(index+1,arr,n,ans,sum+arr[index]);

   subset_sum1(index+1,arr,n,ans,sum);
}

int main()
{
       int n;
       vector<int>ans;
       cout<<"Enter n:";
       cin>>n;

       int arr[n];

       for(int i=0;i<n;i++)
       {
            cin>>arr[i];
       }

       subset_sum1(0,arr,n,ans,0);

       sort(ans.begin(),ans.end());

       for(int i=0;i<ans.size();i++)
       {
         cout<<ans[i]<<" ";
       }
}
