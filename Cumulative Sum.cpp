/**
4  /1  /2  /6  /8  /2
| / | / | / | / | / |
4   5   7   13  21  23

sum of lo to hi =   sum[hi]-sum[lo-1]
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int sum[MAX];
int ar[MAX],n;
void cumilative(){
    sum[0]=ar[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+ar[i];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    int q;
    cumilative();
    while(1){
        int lo,hi;
        scanf("%d%d",&lo,&hi);   //1 base
        printf("%d ",sum[hi-1]-sum[lo-2]);
        int s=0;
        for(int i=lo-1;i<hi;i++) s+=ar[i];
        printf("%d\n",s);
    }
}
