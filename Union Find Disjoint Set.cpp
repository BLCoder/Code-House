
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int parent[MAX];
map<int,int>mp;
struct edge{
    int u,v;
}ver;
vector<edge>e;
int find(int r){
   return (parent[r]==r)?r:parent[r]=find(parent[r]);
}
void disjoint_set(int n){
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<e.size();i++){
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v){
            parent[u]=v;
        }
    }
}
int main(){
    int node,edge,u,v;
    scanf("%d%d",&node,&edge);
    for(int i=0;i<edge;i++){
        scanf("%d%d",&ver.u,&ver.v);
        e.push_back(ver);
    }
    disjoint_set(node);
    for(int i=0;i<e.size();i++){
        cout<<e[i].u<<"->"<<find(e[i].u)<<" "<<e[i].v<<"->"<<find(e[i].v)<<endl;
        mp[find(e[i].u)]++;
    }
    printf("\nTotal sets are -> %d",mp.size());
}
/**
7 11
4 5
1 2
7 6
6 5
5 7
2 4
2 3
1 4
5 2
4 6
5 3

10 6
1 2
3 4
2 1
5 6
7 8
9 10

10 8
1 2
3 4
9 3
0 0
5 6
2 5
7 7
4 8

8 10
2 1
1 8
2 4
2 5
1 6
4 3
3 6
4 8
5 8
7 4
*/

