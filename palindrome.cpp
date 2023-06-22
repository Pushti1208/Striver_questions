#include<iostream>
#include<string>
using namespace std;

bool check_palindrome(string str,int i,int n)
{
          if(i>=n/2)
            return true;
          
          if(str[i]!=str[n-i-1])
            return false;

          return check_palindrome(str,i+1,n);
}

int main()
{
    string s;
    int length;
    cout<<"Enter a string=";
    cin>>s;
    length=s.length();
    bool val;

    val=check_palindrome(s,0,length);
    cout<<val;

}