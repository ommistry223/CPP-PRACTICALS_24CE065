#include<iostream>
using namespace std;
void patterns(int n)
{
    
   for(int i=1;i<=n;i++)
   {
        char ch='A'+n;
        for(int j=1;j<=i;j++)
        {
            cout<<ch;
            ch--;
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