#include<iostream>
using namespace std;

void printUptoN(int n,int sum)
{
    if(n==0)
    {
        cout<<sum;
        return;
    }
    printUptoN(n-1,sum+n);
}


int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;

    printUptoN(n,0);
}