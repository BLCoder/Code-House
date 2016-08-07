/**
find the sortest path of all node from a node

*/

#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
vector<int>edge[100],cost[100];
int bfs(int source,int des){
    int d[100];
    for (int i=0;i<100;i++){
        d[i]=inf;
    }
    queue<int>q;
    q.push(source);
    d[source]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for (int i=0;i<edge[u].size();i++){
            int v=edge[u][i];
            if (d[v]>d[u]+cost[u][i]){
                d[v]=d[u]+cost[u][i];
                q.push(v);
            }
        }
    }
    return d[des];
}

int main(){
    int n,e,i,j,t,x,y;
    cin>>n>>e;
    for(i=1;i<=e;i++){
        cin>>x>>y>>t;
        edge[x].push_back(y);
        edge[y].push_back(x);
        cost[x].push_back(t);
        cost[y].push_back(t);
    }
    cout<<endl;
    for(i=1;i<=n;i++){
        for(j=0;j<edge[i].size();j++){
            cout<<edge[i][j]<<" ";
        }
        cout<<endl;
    }
    int v1,v2;
    while(cin>>v1>>v2){
        cout<<bfs(v1,v2)<<endl;
    }

    return 0;
}
/**
8 15
1 2 1
1 3 1
1 4 3
2 3 3
2 5 4
2 6 2
3 5 2
3 6 3
4 5 1
4 7 4
5 6 4
5 7 3
6 7 3
6 8 2
7 8 2

overall all node's sortest path -->

0 1 1 3 3 3 6 5       sortest path distance from 1 to all node
1 0 2 4 4 2 5 4
1 2 0 3 2 3 5 5
3 4 3 0 1 5 4 6
3 4 2 1 0 4 3 5       sortest path distance from 4 to all node
3 2 3 5 4 0 3 2
6 5 5 4 3 3 0 2
5 4 5 6 5 2 2 0

*/
