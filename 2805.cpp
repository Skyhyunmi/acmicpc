#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
long long g[1'000'006];
long long n,m,low=0,high=0,res=0;

int main(){

    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&g[i]);
        if(high<g[i]) high = g[i];
    }

    while (low<=high)
    {
        long long mid = (low + high) / 2;
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+=g[i]>mid?g[i]-mid:0;
        }
        if(m<=cnt){
            low = mid+1;
            if(res<mid) res=mid;
        }else{
            high = mid-1;
        }
    }
    printf("%lld\n",res);
}