#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
/*
N <-> N
플로이드 워셜 알고리즘은 모든 정점에서 다른 모든 정점에 대한 최소거리를 구하는 것. 음수 허용
res라는 2차원 배열 하나로 구현 가능
f(rom),m(id),t(o)로 나눠서 보면 m을 기준으로 f,t를 움직여가면서 모두 확인하면 됨.
그러기 위해서는 맨처음에 res 배열을 만들면서 INF로 초기화해야함.


@@@@@@    얘만 원래 배열을 수정한다. 다른 애들은 새로운 배열 res배열에 결과 저장한다.     @@@@@@
*/
int res[1004][1004];
int main(){
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);
        for(int k=1;k<=n;k++){
        for(int f=1;f<=n;f++){
            if(k!=f) res[k][f]=10000000;
        }
    }
    for(int i=0;i<m;i++){
        int f,t,w;
        scanf("%d %d %d",&f,&t,&w);
        res[f][t]=w;
    } 
    for(int k=1;k<=n;k++){
        for(int f=1;f<=n;f++){
            for(int t=1;t<=n;t++){
                res[f][t]=min(res[f][t],res[f][k]+res[k][t]);
            }
        }
    }
    int large=-1;
    for(int i=1;i<=n;i++){
        if(res[i][x]>=10000000 || res[x][i]>=10000000) continue;
        large = max(large, res[x][i]+res[i][x]);
    }
    printf("%d\n",large);
}