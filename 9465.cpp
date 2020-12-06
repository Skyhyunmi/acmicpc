#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;
int tab[2][100'006],res[2][100'006],n;
int val=-1;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        val=-1;
        scanf("%d",&n);
        for(int i=0;i<2;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&tab[i][j]);
                res[i][j]=0;
            }
        }
        res[1][0]=res[0][0]=0;
        res[0][1]=tab[0][1];
        res[1][1]=tab[1][1];
        for(int i=2;i<=n;i++){
            res[0][i] = max(res[1][i-1],res[1][i-2])+tab[0][i];
            res[1][i] = max(res[0][i-1],res[0][i-2])+tab[1][i];
        }

        printf("%d\n",max(res[0][n],res[1][n]));
    }
}