#include<iostream>
using namespace std;
int main()
{
    int n,max,second_max=0;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<"Max: "<<max<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     if(arr[i]>second_max && arr[i]!=max)
    //     {
    //         second_max=arr[i];
    //     }
    // }
    // return second_max;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>second_max && arr[i]!=max)
        {
            second_max=arr[i];
        }
    }
    cout<<"Second Max: "<<second_max<<endl;
    return 0;
}