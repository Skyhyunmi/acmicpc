#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int cnt[105][105];
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
    q.push(make_pair(1,1));
    cnt[1][1]=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(x+dir[i][0]<1 || x+dir[i][0] >n || y+dir[i][1] < 1 || y+dir[i][1] > m) continue;
            if(tab[x+dir[i][0]][y+dir[i][1]]==1 && !cnt[x+dir[i][0]][y+dir[i][1]]){
                q.push(make_pair(x+dir[i][0],y+dir[i][1]));
                cnt[x+dir[i][0]][y+dir[i][1]] = cnt[x][y]+1;
            }
        }
    }
    printf("%d\n",cnt[n][m]);
}