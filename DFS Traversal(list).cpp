#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
int visit[1000];
stack<int>q;
void dfs(int n){
    q.push(n);
    cout<<n<<" "; ///see dfs traversal
    visit[n]=1;
    while(!q.empty()){
        int cur=q.top();
        for(int i=0;i<edge[cur].size();i++){
            if(visit[edge[cur][i]]==0){
                dfs(edge[cur][i]);
            }
        }
        if(q.empty()!=0) break;
        q.pop();
    }
}
int main(){
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(edge[i].begin(),edge[i].end());
    }
    dfs(1);
}
/**

9 12
1 8
1 2
1 9
5 8
5 4
5 7
2 6
2 3
7 4
6 9
4 9
6 3

dfs traversal -> 1 2 3 6 9 4 5 7 8

*/
