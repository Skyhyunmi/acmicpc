#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int cur[301][301], pre[301][301],cnt=0;

void check(int x, int y){
    if(pre[x-1][y]==0) cur[x][y]--;
    if(pre[x+1][y]==0) cur[x][y]--;
    if(pre[x][y+1]==0) cur[x][y]--;
    if(pre[x][y-1]==0) cur[x][y]--;
    if(cur[x][y]<=0) {
        cur[x][y]=0;
        cnt--;
    }
}
void cpy(int x, int y){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            pre[i][j]=cur[i][j];
        }
    }
}

void func(int i, int j,int x, int y){
    pre[i][j]=0;
    if(i+1<x && pre[i+1][j])func(i+1,j,x,y);
    if(j+1<y && pre[i][j+1])func(i,j+1,x,y);
    if(i-1>=0 && pre[i-1][j])func(i-1,j,x,y);
    if(j-1>=0 && pre[i][j-1])func(i,j-1,x,y);
}

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            int t;
            scanf("%d",&t);
            cur[i][j]=pre[i][j]=t;
            if(t) cnt++;
        }
    }
    int last=0;
    while(cnt){
        cpy(x,y);
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(cur[i][j]) check(i,j);
            }
        }
        cpy(x,y);
        int island=0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(pre[i][j]){
                    func(i,j,x,y);
                    island++;
                }
            }
        }
        last++;
        if(island>=2) break;
    }
    if(cnt) printf("%d\n",last);
    else printf("0\n");
}