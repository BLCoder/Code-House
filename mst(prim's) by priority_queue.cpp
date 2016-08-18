#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
vector<int>cost[1000];
int d[1000];
int pr[1000];
int check[100];
struct data{
    int city,dist;
    bool operator<(const data&p) const {
        return dist>p.dist;
    }
};
int mst(int source,int n){
    data u,v;
    priority_queue<data>q;
    for(int i=0;i<100;i++) d[i]=1e9;
    for(int i=0;i<100;i++) pr[i]=i;
    u.city=source,u.dist=0;
    q.push(u);
    d[source]=0;
    while(!q.empty()){
        u=q.top();
        check[u.city]=1;
        q.pop();
        for(int i=0;i<edge[u.city].size();i++){
            v.city=edge[u.city][i];
            v.dist=cost[u.city][i];
            if(v.dist<d[v.city]&&check[v.city]==0){
                d[v.city]=v.dist;
                pr[v.city]=u.city;
                q.push(v);
            }
        }
    }
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
    cout<<endl;
    mst(1,n);
    int sum=0;
    for(int i=2;i<=n;i++){
        cout<<i<<" "<<pr[i]<<endl;
        sum+=d[i];
    }
    cout<<endl<<"Minimum -> "<<sum<<endl;
}


/**
9 14
1 2 4
1 8 8
2 8 11
2 3 8
8 9 7
8 7 1
3 9 2
7 9 6
3 6 4
3 4 7
7 6 2
4 6 14
4 5 9
6 5 10
ANS -> 8-7 3-9 7-6 1-2 3-6 3-4 1-8 4-5
path -> 37

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
Ans -> 1-2 1-3 4-5 2-6 3-5 6-8 7-8
path -> 11

9 19
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
4 7 3
2 8 4
6 8 5
2 6 4
8 9 5
3 9 7
5 8 5
4 9 5
Ans ->2-8 3-5 4-1 5-8 6-2 7-4 8-9 9-4
path -> 36

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
Ans -> 2-1 3-5 4-1 5-2 6-4 7-5
path -> 39

*/
