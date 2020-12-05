#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
bool tab[130][130];
int res=0;
int b=0,w=0;
void dq(int xs, int xe, int ys,int ye, int size){
    if(size == 1){
        if(tab[xs][ys]) b++;
        else w++;
        return;
    }
    int xm = (xs + xe) / 2;
    int ym = (ys + ye) / 2;
    int tcnt=0;
    for(int i=xs;i<xe;i++)for(int j=ys;j<ye;j++)
        tcnt+=tab[i][j];
    if(tcnt == size * size) b++;
    else if(!tcnt) w++;
    else{
        dq(xs,xm,ys,ym,size/2);
        dq(xs,xm,ym,ye,size/2);
        dq(xm,xe,ys,ym,size/2);
        dq(xm,xe,ym,ye,size/2);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&tab[i][j]);
        }
    }
    dq(0,n,0,n,n);
    printf("%d\n%d",w,b);
}