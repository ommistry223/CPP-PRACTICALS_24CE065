#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout<<"enter the number of element::";
  cin>>n;

  vector<int>a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int i=0; i<n-1; i++) {
        int minIdx = i;
        for(int j=i+1; j<n; j++)
            if(a[j] < a[minIdx]){
                minIdx = j;
            }
        swap(a[i], a[minIdx]);
    }
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<< " . ";
  }
  return 0;

}
