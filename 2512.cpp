#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int g[10005];
int n,m,low=1,high,res;
bool pos(int bud){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=g[i]>bud?bud:g[i];
    }
    return m>=cnt;
}

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&g[i]);
        if(high<g[i]) high = g[i];
    }
    scanf("%d",&m);
    while (low<=high)
    {
        int mid = (low + high) / 2;
        if(pos(mid)){
            low = mid+1;
            res=mid;
        }else{
            high = mid-1;
        }
    }
    printf("%d\n",res);
}