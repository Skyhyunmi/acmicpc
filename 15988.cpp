#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
long long dp[1'000'006]={0,1,2,4,0,};
int func(int n){
    if(dp[n]) return dp[n];
    for(int i=4;i<=1000000;i++){
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%1'000'000'009;
    }
    return dp[n];
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int res = func(n);
        printf("%d\n",res);
    }
}