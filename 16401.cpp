#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
using namespace std;
int A[1'000'006];
int n,m,res=0,l=1,h=0;

bool pos(int mid){
    int cnt=0;
    for(int i=0;i<m;i++){
        cnt +=A[i]/mid;
    }
    if(cnt >= n) return true;
    else return false;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&A[i]);
        if(h<A[i]) h=A[i];
    }
    while(l<=h){
        int mid=(l+h)/2;
        if(pos(mid)){
            l = mid+1;
            res=mid;
        }
        else{
            h = mid-1;
        }
    }
    printf("%d\n",res);
}