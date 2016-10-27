#include<bits/stdc++.h>
using namespace std;
#define MAX 100002
#define LL long long
#define inf 1LL << 62
vector<int>edge[MAX];
map<pair<int,int>,int>mp;
LL int d[MAX];
int pr[MAX];
int ch[MAX];
int ar[MAX];
int tt=0;
void dijsktra(int n,int N){
    priority_queue<pair<LL int,int>>q;
    //for(int i=0;i<=N;i++) d[i]=100000000000;
    fill_n(d,100001,inf);
    q.push({0,n});
    d[n]=0;
    int u,v,w;
    while(!q.empty()){
        u=q.top().second;
        if(u==N) return;   ///you find your specific node where you want to go ,so return ;
        q.pop();
        if(ch[u]==0){
            ch[u]=1;
            for(int i=0;i<edge[u].size();i++) {
                v=edge[u][i],w=mp[{u,edge[u][i]}]+d[u];
                if(ch[v]==0 and d[v]>mp[{u,edge[u][i]}]+d[u]){
                    d[v]=mp[{u,edge[u][i]}]+d[u];
                    pr[v]=u;
                    q.push({-w,v});
                }
            }
        }
    }
}
void find(int n,int en){
    ar[tt++]=n;
    if(n==en) return ;
    find(pr[n],en);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge[u].push_back(v);
        edge[v].push_back(u);
        if(mp[{u,v}]==0){
            mp[{u,v}]=w;
            mp[{v,u}]=w;
        }
        else if(mp[{u,v}]>w){
            mp[{u,v}]=w;
            mp[{v,u}]=w;
        }
    }
    tt=0;
    dijsktra(1,n);
    if(d[n]==inf) printf("-1\n");
    else{
        find(n,1);
        for(int i=tt-1;i>=0;i--){
            printf("%d ",ar[i]);
        }
    }
}
===============================================================

struct data{
    int city;
    LL int dist;
    bool operator<(const data&p)const{
        return dist>p.dist;
    }
};
void dijsktra(int n,int N){
    priority_queue<data>q;
    for(int i=0;i<=N;i++) d[i]=100000000000;
    data u,v;
    u.city=n,u.dist=0;
    q.push(u);
    d[n]=0;
    ch[n]=1;
    while(!q.empty()){
        u=q.top();
        int ucost=d[u.city];
        ch[u.city]=1;
        q.pop();
        for(int i=0;i<edge[u.city].size();i++) {
            v.city=edge[u.city][i],v.dist=mp[{u.city,edge[u.city][i]}]+ucost;
            if(ch[v.city]==0 and d[v.city]>mp[{u.city,edge[u.city][i]}]+ucost){
                d[v.city]=mp[{u.city,edge[u.city][i]}]+ucost;
                pr[v.city]=u.city;
                q.push(v);
            }
        }
    }
}
void find(int n,int en){
    ar[tt++]=n;
    if(n==en) return ;
    find(pr[n],en);
}
