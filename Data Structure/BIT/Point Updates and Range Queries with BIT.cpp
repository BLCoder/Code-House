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
int range_query(int i,int j){
	return query(j)-query(i-1);
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
                int qlo,value;
                scanf("%d%d",&qlo,&value);
                update(qlo+1,value);  /// qlo and qhi are zero-based indices
            }
            else if(s1[0]=='Q'){
                int qlo,qhi;
                scanf("%d%d",&qlo,&qhi);
                int rt=range_query(qlo+1,qhi+1);  /// qlo are zero-based indices
                printf("%d\n",rt);
            }
        }
        memset(BIT,0,sizeof(BIT));
    }
}
/**
1
9
I
0 3
I
1 5
I
2 6
I
3 7
I
4 6
Q
0 2
Q
1 3
Q
0 1
Q
1 4

*/
