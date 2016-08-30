#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define LL long long
LL int a[MAX];
LL int seg[MAX*3];
void build(LL int ar[],LL int seg[],LL int pos,LL int low,LL int high){
    if(low==high){
        seg[pos]=ar[low];
        return;
    }
    LL int left=pos*2+1;
    LL int right=pos*2+2;
    LL int mid=(low+high)/2;
    build(ar,seg,left,low,mid);
    build(ar,seg,right,mid+1,high);
    seg[pos]=seg[left]+seg[right];
}
LL int query(LL int seg[],LL int pos,LL int low,LL int high,LL int qlow,LL int qhigh){
    if(qlow>high||qhigh<low) return 0;
    if(low>=qlow&&high<=qhigh) return seg[pos];
    LL int left=pos*2+1;
    LL int right=pos*2+2;
    LL int mid=(low+high)/2;
    return query(seg,left,low,mid,qlow,qhigh)+query(seg,right,mid+1,high,qlow,qhigh);
}
void update(LL int seg[],LL int pos,LL int low,LL int high,LL int ipos,LL int val){
    if(ipos>high||ipos<low)return;
    if(low>=ipos&&high<=ipos){
        seg[pos]=val;
        return;
    }
    LL int left=pos*2+1;
    LL int right=pos*2+2;
    LL int mid=(low+high)/2;
    update(seg,left,low,mid,ipos,val);
    update(seg,right,mid+1,high,ipos,val);
    seg[pos]=seg[left]+seg[right];
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case %d:\n",i);
        LL int n,q;
        scanf("%lld%lld",&n,&q);
        for(LL int j=0;j<n;j++){
            scanf("%lld",&a[j]);
        }
        build(a,seg,0,0,n-1);
        for(int j=0;j<q;j++){
            LL int t1,ii,jj;
            scanf("%lld",&t1);
            if(t1==1){
                scanf("%lld",&ii);
                printf("%lld\n",a[ii]);
                update(seg,0,0,n-1,ii,0);
                a[ii]=0;
            }
            else if(t1==2){
                scanf("%lld%lld",&ii,&jj);
                update(seg,0,0,n-1,ii,jj+a[ii]);
                a[ii]+=jj;
            }
            else{
                scanf("%lld%lld",&ii,&jj);
                printf("%lld\n",query(seg,0,0,n-1,ii,jj));
            }
        }
    }
}
