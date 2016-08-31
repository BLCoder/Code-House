#include<bits/stdc++.h>
using namespace std;
int L[2000][2000];
int main(){
	int ar[100];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
	}
	int l[100];
	for(int i=0;i<n;i++) l[i]=1;
	for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            ar[i]>ar[j]?l[i]=max(l[i],l[j]+1):0;
        }
	}
	printf("%d",*max_element(l,l+n));

}
