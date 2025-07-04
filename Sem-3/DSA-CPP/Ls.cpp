#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
static int counter=0;
using namespace std;


int LS(int n,int a[],int x)
{
    for(int i=0;i<n;i++)
    {
        counter++;
        if(a[i]==x)
        {
            return i;
        }
    }
    return -1;
}

int main() {
    int n,x,an;
    cin>>n;
    int a[20];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    an=LS(n,a,x);
        
    if(an==-1)
    {
        cout<<"Element "<<x<<" is not present in the array"<<endl;
        
    }
    else
    {
        cout<<an<<endl;
    }
    cout<<counter;
    
    return 0;
}
