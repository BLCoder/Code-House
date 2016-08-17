#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    int m,n;
    int a[109][109];
    string s3[109][109];
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 or j==0){
                a[i][j]=0;
                s3[i][j]="";
            }
            else if(s1[i-1]==s2[j-1]){
                a[i][j]=a[i-1][j-1]+1;
                s3[i][j]=s3[i-1][j-1]+s1[i-1];
            }
            else if(a[i][j-1]!=a[i-1][j]){
                a[i][j]=max(a[i][j-1],a[i-1][j]);
                s3[i][j]=max(s3[i][j-1],s3[i-1][j]);
            }
            else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
                s3[i][j]=min(s3[i-1][j],s3[i][j-1]);
            }
        }
    }
    cout<<s3[n][m]<<endl;
}
