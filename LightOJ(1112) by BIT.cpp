#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define gc getchar unlocked
#define gc getchar
#define pc putchar_unlocked
#define pc putchar
#define LL long long
int BIT[MAX];
int B[MAX];
void scan(int &n){
    n=0;
    bool negative=false;
    char c=gc();
    while(c<'0'||c>'9'){
        if(c=='-') negative=true;
        c=gc();
    }
    while(c>='0'&&c<='9'){
        n=n*10+c-48;
        c=gc();
    }
    if(negative) n=~(n-1);
}
void print(int n){
    if(n<0){
        pc('-');
        n=-n;
    }
    if(!n){
        pc('0');
        pc('\n');
        return;
    }
    char buff[12];
    int len=0;
    while(n) buff[len++]=n%10+48,n/=10;
    for(int i=len-1;i>=0;i--) pc(buff[i]);
    pc('\n');
}
void update(int idx,int n,int N){
    while(idx<=N){
        BIT[idx]+=n;
        idx+=(idx&-idx);
    }
}
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t;
    scan(t);
    for(int i=1;i<=t;i++){
        int n,m;
        scan(n);
        scan(m);
        for(int j=0;j<n;j++){
            int a;
            scan(B[j]);
            update(j+1,B[j],n);
        }
        printf("Case %d:\n",i);
        for(int j=0;j<m;j++){
            int x,y,z;
            scan(x);
            if(x==1){
                scan(y);
                print(B[y]);
                update(y+1,-B[y],n);
                B[y]=0;
            }
            else if(x==2){
                scan(y);
                scan(z);
                update(y+1,z,n);
                B[y]+=z;
            }
            else {
                scan(y);
                scan(z);
                int ans=query(z+1)-query(y);
                print(ans);
            }
        }
        memset(BIT,0,sizeof(BIT));
    }
}
