#include<iostream>
using namespace std;
int main()
{
    int slargest,largest;

    int a[5];
    for(int i=0;i<5;i++)
    {
        cin>>a[i];

    }
    largest = a[0];
    slargest=-1;
    for(int i=1;i<5;i++)
    {
        if(a[i]>largest)
        {
            slargest=largest;
            largest=a[i];
        }
        else if(a[i]>slargest )
        {
            slargest=a[i];
        }
    }
    cout<<"Largest: "<<largest<<endl;
    cout<<"Second Largest: "<<slargest<<endl;
}