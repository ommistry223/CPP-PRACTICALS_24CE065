#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int counter=0;
using namespace std;
int BS(int a[],int x,int l,int h)
{
    while(l<=h)
    {
        counter++;
        int m=(l+h)/2;
        if(a[m]==x)
        {
            return m;
        }
        else if(a[m]>x)
        {
            h=m-1;
        }
        else 
        {
            l=m+1;           
        }
    }
    return -1;
}

int main() {
    int n,x,an;
    cin>>n;
    int a[20],b[20];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    cin>>x;
    an=BS(a,x,0,n-1);
    if(an==-1)
    {
        cout<<"Not submitted";  
    }
    else{
        
        cout<<b[an]<<endl;
        cout<<counter;
    }
    Printf("\n");
    return 0;
}
