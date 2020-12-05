#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int A[100006];
int main(){
    int n,m,low=0,high=1000000000,res=0;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(low<A[i]) low=A[i];
    }
    while(low<=high){
        int mid = (low + high) / 2;
        int b=0,cnt=0;
        for(int i=0;i<n;i++){
            if(cnt + A[i] > mid) {
                b++;
                cnt=0;
            }
                cnt+=A[i];
        }
        if(cnt) b++;
        if(b>m){
            low = mid+1;
        }
        else if(b<=m){
            high = mid-1;
        }
    }
    printf("%d\n",low);
}