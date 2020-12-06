#include <stdio.h>
int tab[51][51];
int n,m,r,c,d;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int cnt=0;

int goLeft(int dir){
    int td = dir-1;
    if(td<0) td+=4;
    return td;
}
void start(int r,int c, int d){
    tab[r][c]=-1;
    cnt++;
    int dd=d;
    for(int i=1;i<=4;i++){
        int td = goLeft(dd),rx=r+dir[td][0],ry=c+dir[td][1];
        if(tab[rx][ry]==0) {
            start(rx, ry,td);
            return;
        }
        dd=td;
        if(i==4){
            if(tab[r-dir[d][0]][c-dir[d][1]]==1) return;
            else{
                r-=dir[d][0];
                c-=dir[d][1];
                i=1;
                dd=d;
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&r,&c,&d);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&tab[i][j]);
    start(r,c,d);
    printf("%d\n",cnt);
}