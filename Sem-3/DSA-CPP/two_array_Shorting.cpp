#include<iostream>
using namespace std;

int main()
{
    int n;

    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }

    return 0;
}