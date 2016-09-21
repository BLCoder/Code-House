#include<bits/stdc++.h>
using namespace std;
#define MAX 100003
#define LL long long
#define INF 10000000
struct solve{
    LL int seg,lazy;
}tree[MAX*3];
void update(LL int lo,LL int hi,LL int qlo,LL int qhi,LL int pos,LL int value){
    if(tree[pos].lazy!=0){
        tree[pos].seg+=tree[pos].lazy*(hi-lo+1);
        if(lo!=hi){
            tree[pos*2+1].lazy+=tree[pos].lazy;
            tree[pos*2+2].lazy+=tree[pos].lazy;
        }
        tree[pos].lazy=0;
    }
    if(hi<qlo||qhi<lo) return;
    if(qlo<=lo&&qhi>=hi){
        tree[pos].seg+=(value*(hi-lo+1));
        if(lo!=hi){
            tree[pos*2+1].lazy+=value;
            tree[pos*2+2].lazy+=value;
        }
        return;
    }
    LL int mid=(lo+hi)/2;
    update(lo,mid,qlo,qhi,pos*2+1,value);
    update(mid+1,hi,qlo,qhi,pos*2+2,value);
    tree[pos].seg=tree[pos*2+1].seg+tree[pos*2+2].seg;
}
LL int query(LL int lo,LL int hi,LL int qlo,LL int qhi,LL int pos){
    if(tree[pos].lazy!=0){
        tree[pos].seg+=(tree[pos].lazy*(hi-lo+1));
        if(lo!=hi){
            tree[pos*2+1].lazy+=tree[pos].lazy;
            tree[pos*2+2].lazy+=tree[pos].lazy;
        }
        tree[pos].lazy=0;
    }
    if(hi<qlo||qhi<lo) return 0;
    if(qlo<=lo&&qhi>=hi){
        return tree[pos].seg;
    }
    LL int mid=(lo+hi)/2;
    LL int t1=query(lo,mid,qlo,qhi,pos*2+1);
    LL int t2=query(mid+1,hi,qlo,qhi,pos*2+2);
    return t1+t2;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        LL int n,m;
        scanf("%lld%lld",&n,&m);
        printf("Case %d:\n",i);
        for(int j=0;j<m;j++){
            LL int r,x,y,z;
            scanf("%lld",&r);
            if(r==1){
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",query(0,n-1,x,y,0));
            }
            else if(r==0){
                scanf("%lld%lld%lld",&x,&y,&z);
                update(0,n-1,x,y,0,z);
            }
        }
        memset(tree,0,sizeof(tree));
    }
}
