#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define FF(N,M) for(int i=0;i<N;i++)for(int j=0;j<M;j++)
#define FI(N) for(int i=0;i<N;i++)
#define FJ(M) for(int j=0;j<M;j++)
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}},tab[101][101], n,m,cnt=0;
typedef pair<int,int> pii;
queue<pii> airq;
// void prnt(){
//     FI(n){
//         FJ(m) {
//             tab[i][j]?printf("%d ",tab[i][j]):printf("  ");
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

void air(){
    while(!airq.empty()){
        int x = airq.front().first, y = airq.front().second;
        airq.pop();
        if(tab[x][y]==-1) continue;
        tab[x][y]=-1;
        FI(4){
            int dx=x+dir[i][0],dy=y+dir[i][1];
            if(dx>=0 && dx<n && dy>=0 && dy<m &&tab[dx][dy]== 0) airq.push({dx,dy});
        }
    }
    
}

void melt(int x, int y){
    int how=0;
    FI(4){
        int dx=x+dir[i][0],dy=y+dir[i][1];
        if(dx>=0 && dx<n && dy>=0 && dy<m && tab[dx][dy]== -1) how++;
    }
    if(how>=2){
        cnt--;
        tab[x][y]=0;
        airq.push({x,y});
    }
}

int main(){

    scanf("%d %d",&n,&m);
    FI(n){
        FJ(m){
            scanf("%d",&tab[i][j]);
            if(tab[i][j]==1) cnt++;
        }
    }
    int day=0;
    airq.push({0,0});
    
    while(cnt>0){
        day++;
        air();
        FI(n)FJ(m)if(tab[i][j]==1)melt(i,j);
    }
    printf("%d\n",day);
}