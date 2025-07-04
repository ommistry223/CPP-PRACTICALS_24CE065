#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int counter=0;
using namespace std;
int Bs(int a[],int x,int l,int h)
{
    counter++;
    if(l>h)
    {
        return -1;
    }
    int m=(l+h)/2;
    if(a[m]==x)
    {
        return m;
    }
    else if(a[m]>x)
    {
       return Bs(a,x,l,m-1);    
    }
    else
    {
        return Bs(a,x,m+1,h);
    }
}
int main()
{
    int n,x,an;
    cin>>n;
    int a[20],b[20];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    cin>>x;
    an=Bs(a,x,0,n-1);
    
    if(an==-1)
   {
        cout<<"Not submitted";  
     }
     else{
        
         cout<<b[an]<<endl;
        cout<<counter;
    }
    
    
    return 0;
}