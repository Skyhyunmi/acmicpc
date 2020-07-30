#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int tab[2500][2500];
int res[4];

void dq(int x, int y, int size){
    bool same=true;
    int f = tab[x][y];
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(f != tab[i][j]) {
                same=false;
                break;
            }
        }
    }
    if(same) {
        res[f+1]++;
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            dq(x+i*size/3,y+j*size/3,size/3);
        }
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
    dq(0,0,n);
    printf("%d\n%d\n%d",res[0],res[1],res[2]);
}