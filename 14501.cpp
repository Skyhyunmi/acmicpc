#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int t[20],p[20],cost[20];
int n,res=-1;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&t[i],&p[i]);
    }
    for(int i=1;i<=n;i++){//첫날부터 마지막날까지 순서대로 보면서 했을때 안했을때만 비교하면 된다.
        if(i+t[i] <= n+1){ //그날 일을 했는가!
            cost[i+t[i]] = max(cost[i+t[i]],cost[i]+p[i]);//그날 했으면 끝난 날에 받을 Cost 업데이트
            res = max(res,cost[i+t[i]]);//결과값 업데이트
        }
        //안했는가!
        cost[i+1] = max(cost[i+1],cost[i]);//안했으니까 다음날로 넘어갈건데 그전에 내일 값이 오늘 값보다 작으면 오늘걸로 업데이트
        res = max(res,cost[i+1]);//결과값 업데이트
    }
    printf("%d\n",res);
}