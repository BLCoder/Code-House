/**
the main things is to find minimum spanning tree(mst), we always find the set of
two adjecent node,initially the reprasantator of all node is setup by their own
number. and we sort all edges by their weight. suppose it is u & v , we find out
which is the reprasantatorof their set, if the reprasantator of two node is same
that means these two node is in same set. so, if we take this two node for creat
mst, their have creat a cycle, so we can't take it.now if their reprasantator is
diffrent that means they are in diffrent set, so we take it, and we change their
set as their reprasantator

so, final approach is
-> we input all edges & push them in a vector
-> sort them by their weight
-> check reprasantator of two node is same or not
-> if it's not then we take it and exchange their reprasantator (any of them)
-> otherwise we don't take it

*/

#include<bits/stdc++.h>
using namespace std;
int parent[1000];
struct edge{
    int u,v,w;
}ver;
vector<edge>e;
void bubble_sort(int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(e[j].w>e[j+1].w) swap(e[j].w,e[j+1].w),swap(e[j].u,e[j+1].u),swap(e[j].v,e[j+1].v);
}
int find(int r){
    return (parent[r]==r)?r:parent[r]=find(parent[r]);
}
void mst(int n){
    for(int i=1;i<=n;i++) parent[i]=i;     ///just we setup the reprasantator of all node by their number
    int cnt=0,s=0;
    printf("we take the above edges -> \n");
    for(int i=0;i<e.size();i++){
        int u=find(e[i].u);
        int v=find(e[i].v);
        ///cout<<u<<" "<<v<<endl;      ///see the parants of u and v
        if(u!=v){
            cout<<"\t"<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;  ///for see which egde is we take for creating mst
            parent[u]=v;
            cnt++;
            s+=e[i].w;
            if(cnt==n-1) break; ///always the minimum adge are total vertic-1
        }
    }
    printf("Minimum Path is : %d\n",s);
}
int main(){
    int node,edge,u,v,w;
    scanf("%d%d",&node,&edge);
    for(int i=0;i<edge;i++){
        scanf("%d%d%d",&ver.u,&ver.v,&ver.w);
        e.push_back(ver);
    }
    bubble_sort(edge);
    mst(node);
}
/**
7 11
4 5 15
1 2 7
7 6 11
6 5 8
5 7 9
2 4 9
2 3 8
1 4 5
5 2 7
4 6 6
5 3 5
*/
