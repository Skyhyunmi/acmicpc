#include <stdio.h>
#define FF(n) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
int tab[102][102][2],n,t,min=101,max=-1,res=0,cur,cnt;

void check(int x, int y){
    tab[x][y][1]=1;
    if(x+1<=n && tab[x+1][y][1]==0)check(x+1,y);
    if(y+1<=n && tab[x][y+1][1]==0)check(x,y+1);
    if(x-1>=1 && tab[x-1][y][1]==0)check(x-1,y);
    if(y-1>=1 && tab[x][y-1][1]==0)check(x,y-1);
}

int main(){
    scanf("%d",&n);
    FF(n){
        scanf("%d",&t);
        tab[i][j][0]=t;
        if(t<min) min = t;
        if(t>max) max = t;
    }
    for(cur=min-1;cur<=max;cur++){
        FF(n) tab[i][j][1]=tab[i][j][0]>=cur?0:1;
        cnt=0;
        FF(n) if(tab[i][j][1]==0){
                check(i,j);
                cnt++;
            }
        if(cnt>res) res=cnt;
    }
    printf("%d\n",res);
}