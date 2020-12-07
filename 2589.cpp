#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define FI(N) for(int i=0;i<N;i++)
#define FJ(M) for(int j=0;j<M;j++)
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}},n,m;
char tab[55][55];
int map[55][55],res=-1;
struct CRD{
    int x,y,val;
};

// void prnt(){
//     FI(n){
//         FJ(m){
//             printf("%d ",map[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

void bfs(int r, int c){
    queue<CRD> q;
    bool visit[55][55]={false,};
    CRD t = {r,c,0};
    visit[r][c]=true;
    q.push(t);
    while(!q.empty()){
        t = q.front(); q.pop();
        int x=t.x,y=t.y,val=t.val;
        res = max(res,val);
        map[x][y]=val;
        for(int i=0;i<4;i++){
            int dx=x+dir[i][0],dy=y+dir[i][1];
            if(dx>=0 && dx<n && dy>=0 && dy<m && tab[dx][dy]=='L' &&!visit[dx][dy]){
                t = {dx,dy,val+1};
                visit[dx][dy]=true;
                q.push(t);
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    FI(n){
        getchar();
        FJ(m){
            scanf("%1c",&tab[i][j]);
        }
        
    }

    FI(n){
        FJ(m){
            if(tab[i][j]=='L') bfs(i,j);
        }
    }
    printf("%d\n",res);
}