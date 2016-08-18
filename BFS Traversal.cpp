/**
traversal all node from initial node
find whatever we go to all node or nor


*/

#include<bits/stdc++.h>
using namespace std;
int edge[100][1000];
int visited[1000];
int bfs(int start,int end,int r){
    queue<int>q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(int i=0;i<=r;i++) {
            if(edge[cur][i]==1&&visited[i]==0) {
                q.push(i);
                visited[i]=1;
            }
        }
    }
    return visited[end];
}
int main(){
    int v,e;
    cin>>v>>e;
    int a,b;
    for(int i=1;i<=e;i++) {
        cin>>a>>b;
        edge[a][b]=1;
        edge[b][a]=1;
    }
    int start,end;
    scanf("%d%d",&start,&end);
    int k=bfs(start,end,v);
    cout<<((k)?"YES":"NO")<<endl;

    return 0;
}

/**

8 9
1 2
1 5
2 6
6 3
6 7
3 7
3 4
7 8
4 8
2 8
output:
2 1 6 5 3 7 4 8 YES
*/
