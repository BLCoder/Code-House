#include<bits/stdc++.h>
using namespace std;
#define MAX 5000
int arr[MAX];
int seg[MAX*3];
void build(int arr[],int seg[],int low,int high,int pos){
    if(low==high){
        seg[pos]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(arr,seg,low,mid,pos*2+1);
    build(arr,seg,mid+1,high,pos*2+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
int quary(int seg[],int qlow,int qhigh,int low,int high,int pos){
    if(qlow<=low&&qhigh>=high) return seg[pos];
    if(qlow>high||qhigh<low) return MAX;
    int mid=(low+high)/2;
    //return min(quary(seg,qlow,qhigh,low,mid,2*pos+1),quary(seg,qlow,qhigh,mid+1,high,2*pos+2));
    int t1=quary(seg,qlow,qhigh,low,mid,2*pos+1);
    int t2=quary(seg,qlow,qhigh,mid+1,high,2*pos+2);
    return min(t1,t2);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n*3;i++) seg[i]=1e9;
    build(arr,seg,0,n-1,0);
    cout<<quary(seg,2,7,0,n-1,0);
}

