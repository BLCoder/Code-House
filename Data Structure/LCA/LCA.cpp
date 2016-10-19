#include<bits/stdc++.h>
using namespace std;
#define mx 100002
int L[mx];
int L1[mx];
int P[mx][22];
int T[mx];
int T1[mx];
vector<int>edge[mx];
void bfs(int u){
    L1[u]=0;
    T1[u]=0;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            if(L1[edge[u][i]]==0){
                L1[edge[u][i]]=L1[u]+1;
                T1[edge[u][i]]=u;
                q.push(edge[u][i]);
            }
        }
    }
}
void dfs(int from,int u,int dep){
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}
int LCA_query(int N, int p, int q){
    if (L[p]<L[q]) swap(p,q);
    int log=1;
    while(1){
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
    }
    ///int log=log2(L[p])+1; alter
    for(int i=log;i>=0;i--){
        if (L[p]-(1<<i)>=L[q]){
            p=P[p][i];
        }
    }
    if(p==q) return p;
    for(int i=log; i>=0;i--){
        if (P[p][i]!=-1&&P[p][i]!=P[q][i]){
            p=P[p][i],q=P[q][i];
        }
    }
    return T[p];
}

void Sparse(int N){
    memset(P,-1,sizeof(P));
    for(int i=0;i<N;i++){
        P[i][0]=T[i];
    }
    for(int j=1;(1<<j)<N;j++){
        for(int i=0;i<N;i++){
            if (P[i][j-1]!=-1){
                P[i][j]=P[P[i][j-1]][j-1];
            }
        }
    }
}
int main(){
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(0,0,0);
    bfs(0);
    Sparse(n);
    printf("%d\n",LCA_query(n,3,4));
}
