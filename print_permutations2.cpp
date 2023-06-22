#include<iostream>
#include<vector>
using namespace std;

void print_per(int index,vector<int>&arr,vector<vector<int>>&ans,int n)
{
    if(index==n)
    {
        ans.push_back(arr);
        return;
    } 

     
     for(int i=index;i<n;i++)
     {
        swap(arr[i],arr[index]);
        print_per(index+1,arr,ans,n);
        swap(arr[i],arr[index]);
     }
}


int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    
    vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   
    vector<vector<int>>ans;
     
     print_per(0,arr,ans,n);

     for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
