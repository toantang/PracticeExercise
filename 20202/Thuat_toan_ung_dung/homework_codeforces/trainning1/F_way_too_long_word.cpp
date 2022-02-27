#include<iostream>
#include<string.h>
using namespace std;
int main()
{
     int n,len;
     char x[1000];
     cin>>n;
     for(int i=1;i<=n;i++)
     {
        cin>>x;
        len=strlen(x);
        if(len<=10) cout<<x<<endl;
        else
        {
             cout<<x[0]<<len-2<<x[len-1]<<endl;
        }
     }
}
