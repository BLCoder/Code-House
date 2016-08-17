#include<bits/stdc++.h>
using namespace std;
int edge[100][100];
int visit[1000];
stack<int>q;
void dfs(int n,int node){
    q.push(n);
    cout<<n<<" "; ///see dfs traversal
    visit[n]=1;
    while(!q.empty()){
        int cur=q.top();
        for(int i=0;i<=node;i++){
            if(edge[cur][i]==1&&visit[i]==0){
                dfs(i,node);
            }
        }
        if(q.empty()!=0) break;
        cout<<cur<<" ";   ///see the topological sort
        q.pop();
    }
}
int main(){
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a][b]=1;
        edge[b][a]=1;
    }
    dfs(1,n);
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
topological sort -> 1 2 3 6 9 4 5 8 7

*/
