#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

bool check_palindrome(string s,int start,int end)
{
       while (start<=end)
       {
           if(s[start++]!=s[end--])
           {
            return false;
           }
          
       }
       return true;
}

void palindrome_partition(int index,string s,vector<vector<string>>&ans,vector<string>&path)
{
      if(index==s.size())
      {
          ans.push_back(path);
          return;
      }
      
      for(int i=index;i<s.size();i++)
      {
             if(check_palindrome(s,index,i))
             {
                 path.push_back(s.substr(index,i-index+1));
                 palindrome_partition(i+1,s,ans,path);
                 path.pop_back();
             }
          
    }

}
int main()
{
    string s;
    cout<<"Enter String:";
    cin>>s;

    vector<vector<string>>ans;
    vector<string>path;

    palindrome_partition(0,s,ans,path);

     cout << "The Palindromic partitions are :-" << endl;
  cout << " [ ";
  for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

  return 0;
}

