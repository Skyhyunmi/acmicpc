#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
//너무 어려워서 킵 합니다.
using namespace std;

char jail[101][101];
int map[101][101]={100000,};
int n,m,prsnr[2][3],pos=0;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct coord{
    int x,y;
};

void prnt(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

void func(int cur[]){
    queue<pair<coord,int>> q;
    coord crd = {cur[0],cur[1]};
    q.push({crd,1});
    while(!q.empty()){
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n+1;i++){
            getchar();
            jail[i][0]=jail[i][m+1]
            for(int j=1;j<=m+1;j++){
                scanf("%1c",&jail[i][j]);
                if(jail[i][j]=='$'){
                    prsnr[pos][0]=i;
                    prsnr[pos++][1]=j;
                }
            }
            
        }
        // printf("%d %d\n",prsnr[0][0],prsnr[0][1]);
        // printf("%d %d\n",prsnr[1][0],prsnr[1][1]);
        func(prsnr[0]);
        func(prsnr[1]);
        func(prsnr[2]);
        // printf("%d\n",res);
    }
}