#include<bits/stdc++.h>
using namespace std;
int L[2000][2000];
int main(){
	string s1,s2;
    int n,m;
    cin>>s1>>s2;
    m=s1.size();
    n=s2.size();
    for (int i=0;i<=m;i++){
      for (int j=0;j<=n;j++){
         i==0||j==0?L[i][j]=0:s1[i-1]==s2[j-1]?L[i][j]=L[i-1][j-1]+1:L[i][j]=max(L[i-1][j],L[i][j-1]);
      }
    }
    cout<<L[m][n]<<endl;
}
