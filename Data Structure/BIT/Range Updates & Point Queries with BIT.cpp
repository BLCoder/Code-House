#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define INF 100000000
int BIT[MAX];
char s1[5];
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
void update(int idx,int n){
    while(idx<=MAX){
        BIT[idx]+=n;
        idx+=(idx&-idx);
    }
}
void range_update(int i,int j,int v){
	update(i,v);
	update(j+1,-v);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",i);
        for(int j=0;j<q;j++){
            scanf("%s",s1);
            if(s1[0]=='I'){
                int qlo,qhi,value;
                scanf("%d%d%d",&qlo,&qhi,&value);
                range_update(qlo+1,qhi+1,value);  /// qlo and qhi are zero-based indices
            }
            else if(s1[0]=='Q'){
                int qlo;
                scanf("%d",&qlo);
                int rt=query(qlo+1);  /// qlo are zero-based indices
                printf("%d\n",rt);
            }
        }
        memset(BIT,0,sizeof(BIT));
    }
}
