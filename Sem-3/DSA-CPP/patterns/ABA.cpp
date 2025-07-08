#include<iostream>
using namespace std;
void patterns(int n)
{
    
   for(int i=0;i<n;i++)
   {
        // print Space
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        
        // print Letter
        char ch='A';
        int decrement=(2*i+1)/2;
        for(int j=0;j<2*i+1;j++)
        {
          cout<<ch;
            if(j<decrement)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        for(int j=0;j<=n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
   } 
}
int main()
{
    int n;
    cin>>n;
    patterns(n);
    return 0;
}