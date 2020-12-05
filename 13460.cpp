#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
char board[11][11];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1c",&board[i][j]);
        }
        getchar();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}