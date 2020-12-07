#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define FF(N,M) for(int i=0;i<N;i++)for(int j=0;j<M;j++)
#define FI(N) for(int i=0;i<N;i++)
#define FJ(M) for(int j=0;j<M;j++)
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}},Max=-1;

using namespace std;
vector<int> v[20001];
queue<pair<int,int>> q;
vector<int> vv[20001];
bool visit[20001]={false,};

void prnt(int Max){
    FI(Max){
        printf("%d: ",i);
        int len = vv[Max].size();
        for(auto iter : vv[Max]) printf("%d ",iter);
        printf("\n");
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FI(m){
        int f,t;
        scanf("%d %d",&f,&t);
        v[f].push_back(t);
        v[t].push_back(f);
    }
    q.push({1,0});
    visit[1]=true;
    while(!q.empty()){
        int cur = q.front().first,dist = q.front().second;
        q.pop();
        
        int len = v[cur].size();
        for(int i=0;i<len;i++){
            if(!visit[v[cur][i]]){
                vv[dist+1].push_back(v[cur][i]);
                visit[v[cur][i]] = true;
                Max=dist+1;
                q.push({v[cur][i],dist+1});
            }
        }
    }
    sort(vv[Max].begin(),vv[Max].end());
    printf("%d %d %lu\n",vv[Max][0],Max,vv[Max].size());
}