#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
#define INF 1000000
struct edge{
    int seg,lazy;
}tree[MAX];
int segg[MAX];
int seg1[MAX];
void build(int lo,int hi,int pos){
    if(hi==lo){
        tree[pos].seg=segg[lo];
        return ;
    }
    int mid=(lo+hi)/2;
    build(lo,mid,pos*2+1);
    build(mid+1,hi,pos*2+2);
    tree[pos].seg=min(tree[pos*2+1].seg,tree[pos*2+2].seg);
}
void update(int qlo,int qhi,int lo,int hi,int value,int pos){
    if(lo>hi) return;
    if(tree[pos].lazy!=0){
        tree[pos].seg+=tree[pos].lazy;
        if(lo!=hi){
            tree[pos*2+1].lazy+=tree[pos].lazy;
            tree[pos*2+2].lazy+=tree[pos].lazy;
        }
        tree[pos].lazy=0;
    }
    if(hi<qlo||lo>qhi) return;
    if(qlo<=lo&&qhi>=hi){
        tree[pos].seg+=value;
        if(lo!=hi){
            tree[pos*2+1].lazy+=value;
            tree[pos*2+2].lazy+=value;
        }
        return ;
    }
    int mid=(lo+hi)/2;
    update(qlo,qhi,lo,mid,value,pos*2+1);
    update(qlo,qhi,mid+1,hi,value,pos*2+2);
    tree[pos].seg=min(tree[pos*2+1].seg,tree[pos*2+2].seg);
}
int query(int qlo,int qhi,int lo,int hi,int pos){
    if(lo>hi) return INF;
    if(tree[pos].lazy!=0){
        tree[pos].seg+=tree[pos].lazy;
        if(lo!=hi){
            tree[pos*2+1].lazy+=tree[pos].lazy;
            tree[pos*2+2].lazy+=tree[pos].lazy;
        }
        tree[pos].lazy=0;
    }
    if(qlo>hi||qhi<lo) return INF;
    if(qlo<=lo&&qhi>=hi) return tree[pos].seg;
    int mid=(lo+hi)/2;
    int t1=query(qlo,qhi,lo,mid,pos*2+1);
    int t2=query(qlo,qhi,mid+1,hi,pos*2+2);
    return min(t1,t2);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&segg[i]);
    }
    build(0,n-1,0);
    for(int i=0;i<15;i++){
        printf("%d ",tree[i].seg);
    }
    printf("\n");
    int qlo,qhi,value;
    while(~scanf("%d%d%d",&qlo,&qhi,&value)){
        update(qlo,qhi,0,n-1,value,0);
        for(int i=0;i<15;i++){
            printf("%d ",tree[i].seg);
        }
        printf("%d",query(qlo,qhi,0,n-1,0));
    }
}
