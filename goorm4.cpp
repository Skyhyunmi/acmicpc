#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int tab[101][101];
int cnt=0;
vector<pair<int,int>> v;
int main(){
    int n, d;
    scanf("%d %d",&n,&d);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&tab[i][j]);
            if(tab[i][j]) {
                // printf("-> %d %d\n",i,j);
                v.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=0;i<v.size();i++){
        int x = v[i].first, y=v[i].second;
        printf("-> %d %d\n",x,y);
        for(int tx = x-d;tx<x+d;tx++){
            if(tx<0 || tx>n) continue;
            for(int ty = y-d;ty<y+d;ty++){
                if(ty<0 || ty>n) continue;
                if(tab[tx][ty]!=1&&(tx-x)*(tx-x) + (ty-y)*(ty-y) <= d*d){
                    if(tab[tx][ty]!=2) cnt++;
                    tab[tx][ty]=2;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }

    printf("%d\n",cnt);
}
