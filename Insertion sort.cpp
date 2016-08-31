#include<bits/stdc++.h>
using namespace std;
int main(){
    int ar[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    for(int i=1;i<n;i++){
        int j=i;
        while(ar[j]<ar[j-1]&&j>0){
            swap(ar[j],ar[j-1]);
            j--;
            for(int k=0;k<n;k++){
                printf("%d ",ar[k]);
            }
            printf("\n");
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",ar[i]);
    }
}

/**

12
8 2 7 4 9 1 6 3 11 5 10 12

*/
