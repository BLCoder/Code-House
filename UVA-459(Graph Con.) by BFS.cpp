#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
vector<int>cost[1000];
set<int>st;
int visit[1000];
void bfs(int m){
    queue<int>q;
    q.push(m);
    visit[m]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto it:edge[u]) visit[it]==0?q.push(it),visit[it]=1:0;
    }
}
int main(){
    //I always use scanf && printf
    //freopen("in.txt","w",stdout);
    int t,t1,t2,r,mn,u,v,cnt=0;
    string s;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        memset(visit,0,sizeof(visit));
        cnt=0;
        getline(cin,s);
        int mn=s[0]+1;
        for(int i=0;i<150;i++) edge[i].clear();
        while(getline(cin,s)){
            if(s.empty()) break;
            u=s[0];
            v=s[1];
            edge[u].push_back(v);
            edge[v].push_back(u);
            st.insert(u);
            st.insert(v);
        }
        for(auto it:st) visit[it]==0?bfs(it),cnt++:0;
        for(int i=65;i<mn;i++) visit[i]==0?cnt++:0;
        if(i!=t-1) printf("%d\n\n",cnt);
        else printf("%d\n",cnt);
        st.clear();
    }
}

