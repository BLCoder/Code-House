#include<bits/stdc++.h>
using namespace std;
#define MAX 102
vector<int>edge[MAX];
int visit[MAX];
vector<int>tp;
void dfs(int n){
    visit[n]=1;
    for(int i=0;i<edge[n].size();i++){
        if(visit[edge[n][i]]==-1){
            dfs(edge[n][i]);
        }
    }
    tp.push_back(n);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(visit,-1,sizeof(visit));
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            if(visit[i]==-1){
                dfs(i);
            }
        }
        reverse(tp.begin(),tp.end());
        printf("%d",tp[0]);
        for(int i=1;i<tp.size();i++){
            printf(" %d",tp[i]);
        }
        printf("\n");
        for(int j=0;j<=n;j++){
            edge[j].clear();
        }
        tp.clear();
    }
}
//======================================================================

#include<bits/stdc++.h>
using namespace std;
#define MAX 102
vector<int>edge[MAX];
int ind[MAX];
vector<int> top_sort(int N){
    queue<int>q;
    for(int i=1;i<=N;i++){
        if(ind[i]==0) q.push(i);
    }
    vector<int>top_s;
    while(!q.empty()){
        int u=q.front();
        top_s.push_back(u);
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            ind[edge[u][i]]--;
            if(ind[edge[u][i]]==0){
                q.push(edge[u][i]);
            }
        }
    }
    return top_s;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            ind[v]++;
        }
        vector<int>tp=top_sort(n);
        printf("%d",tp[0]);
        for(int i=1;i<tp.size();i++){
            printf(" %d",tp[i]);
        }
        printf("\n");
        for(int j=0;j<=n;j++){
            edge[j].clear();
        }
        memset(ind,0,sizeof(ind));
    }
}
