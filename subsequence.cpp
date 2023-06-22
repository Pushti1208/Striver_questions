#include<iostream>
#include<vector>
using namespace std;

void subsequence(int index,int arr[],vector<int> &v,int n)
{
     if(index>=n)
     {
        for(auto it:v)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
     }

     v.push_back(arr[index]);

     subsequence(index+1,arr,v,n);

     v.pop_back();

     subsequence(index+1,arr,v,n);

}


int main()
{
    int n;
    cout<<"Enter number of array elements:";
    cin>>n;
    int arr[n];

     for(int i=0;i<n;i++)
     {
        cin>>arr[i];
     }    

     vector<int> v;

     subsequence(0,arr,v,n);  
}