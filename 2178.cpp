#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
bool check[105][105];
bool tab[105][105];
queue<pair<int,int>> q;
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        char temp[105];
        scanf("%s",temp);
        for(int j=1;j<=m;j++){
            tab[i][j] = temp[j-1]-'0';
        }
        getchar();
    }
    q.push({1,1});
    check[1][1]=true;
    int cnt=0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(x==n&&y==m) break;
        if(check[x][y]) continue;
        check[x][y]=true;
        cnt++;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = x+dir[i][0];
            int dy = y+dir[i][1];
            if(check[dx][dy]|| tab[dx][dy]==0||dx<1||dx>n||dy<1||dy>m) continue;
            q.push({dx,dy});
        }
        

    }
    printf("%d\n",cnt);
}