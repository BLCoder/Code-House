#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int check[100];
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
    //I always use scanf && printf
    //freopen("in.txt","w",stdout);
    int t,t1,t2,r,mn;
    string s;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        memset(check,0,sizeof(check));
        getline(cin,s);
        int mn=s[0]+1;
        r=mn;
        while(getline(cin,s)){
            if(s.empty()) break;
            ver.u=s[0];
            ver.v=s[1];
            if(check[ver.u]==0&&ver.u<mn&&ver.u!=ver.v) r--,check[ver.u]=1;
            if(check[ver.v]==0&&ver.v<mn&&ver.u!=ver.v) r--,check[ver.v]=1;
            if(check[ver.u]==0&&ver.u==ver.v&&ver.v<=mn) r--,check[ver.u]=1;
            //cout<<r;
            mp[ver.u++];
            mp[ver.v++];
            e.push_back(ver);
        }
        disjoint_set(120);
        mp.clear();
        for(int i=0;i<e.size();i++){
            mp[find(e[i].u)]++;
        }
        if(i!=t-1) printf("%d\n\n",mp.size()+r-65);
        else printf("%d\n",mp.size()+r-65);
        //cout<<mn;
        mp.clear();
        e.clear();
    }
}

