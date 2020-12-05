#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string.h>
using namespace std;

int dir[105][105];

int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    while(m--){
        int f,t;
        scanf("%d %d",&f,&t);
        dir[f][t]=1;
    }
    for(int mid=1;mid<=n;mid++){
        for(int str=1;str<=n;str++){
            for(int dest=1;dest<=n;dest++){
                if(dir[str][mid] && dir[mid][dest]) dir[str][dest]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(dir[i][j] || dir[j][i]) cnt ++;
        }
        printf("%d\n",n-cnt-1);
    }
}