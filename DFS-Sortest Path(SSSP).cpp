#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
vector<int>cost[1000];
int d[1000];
stack<int>q;
int dfs(int n,int dis){
    q.push(n);
    while(!q.empty()){
        int cur=q.top();
        for(int i=0;i<edge[cur].size();i++){
            int v=edge[cur][i];
            if(d[v]>d[cur]+cost[cur][i]){
                d[v]=d[cur]+cost[cur][i];
                dfs(edge[cur][i],dis);
            }
        }
        if(q.empty()!=0) break;
        q.pop();
    }
    return d[dis];
}
int main(){
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edge[a].push_back(b);
        edge[b].push_back(a);
        cost[a].push_back(w);
        cost[b].push_back(w);
    }
    int start,end;
    while(scanf("%d%d",&start,&end)){
        for(int i=0;i<100;i++) d[i]=1e9;
        d[start]=0;
        cout<<dfs(start,end)<<endl;
    }
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

0 1 1 3 0 0 0 0
1 0 3 0 4 2 0 0
1 3 0 0 2 3 0 0
3 0 0 0 1 0 4 0
0 4 2 1 0 4 3 0
0 2 3 0 4 0 3 2
0 0 0 4 3 3 0 2
0 0 0 0 0 2 2 0

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
