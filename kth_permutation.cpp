#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

string permutation_kth(int N,int k)
{     
      int fact=1;
      vector<int> v;

      for(int i=1;i<=N;i++)
      {
           fact=fact*i;
           v.push_back(i);
      }
      fact=fact/N;

      string ans="";
      k=k-1;
      
      while (true)
      {
        ans=ans+to_string(v[k / fact]);
        v.erase(v.begin() + k / fact);
        if (v.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / v.size();
        }

        return ans;
      

}

int main()
{
    int N,k;
    cout<<"Enter n:";
    cin>>N;

    cout<<"Enter value of k:";
    cin>>k;
    
    string res;
    res=permutation_kth(N,k);

    cout<<res;
}