#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n,m,map[1025][1025];
int sum[1025][1025];

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        scanf("%d ",&map[i][j]);
        sum[i][j] = map[i][j] + sum[i][j-1];
    }
    while(m--){
        int res=0,x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int i = x1;i<=x2;i++)
            res += sum[i][y2] - sum[i][y1-1];
        printf("%d\n",res);
    }
}