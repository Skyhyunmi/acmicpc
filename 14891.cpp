#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int W[5][10];

void wheel(int w,int dir){
    if(dir==1){
        for(int i=8;i>=1;i--){
            W[w][i+1]=W[w][i];
        }
        W[w][1]=W[w][9];
    }
    else{
        for(int i=1;i<=8;i++){
            W[w][i-1]=W[w][i];
        }
        W[w][8]=W[w][0];
    }
}

void check(int w, int dir){
    bool l=true,r=true;
    bool gl=false,gr=false;
    if(w==1) l=false;
    if(w==4) r=false;
    if(l){
        if(W[w-1][3]==W[w][7]){
            gl=true;
            wheel(w-1,-1*dir);
        }
    }
    if(r){
        if(W[w+1][7]==W[w][3]){
            gr=true;
            wheel(w+1,-1*dir);
        }
    }
    wheel(w,dir);
}

int main(){
    
    for(int i=1;i<=4;i++){
        for(int j=1;j<=8;j++){
            scanf("%1d",&W[i][j]);
        }
    }
    int n;
    scanf("%d",&n);
    while(n--){
        int w,dir;
        scanf("%d %d",&w,&dir);
        check(w,dir);
    }
    int res=0;
    for(int i=1,j=1;i<=4;i++){
        if(W[i][0]==1) {
            res+=1*j;
            printf("%d\n",res);
        }
        j*=2;
    }
    printf("%d\n",res);
}