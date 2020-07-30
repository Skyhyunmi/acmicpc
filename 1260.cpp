#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> vec[1002];
queue<int> q;
bool dcheck[1002],bcheck[1002];
int n,m,v;

void dfs(int cur){
    printf("%d ",cur);
    dcheck[cur] = true;
    for(int i : vec[cur]){
        if(!dcheck[i]) dfs(i);
    }
}

void bfs(int start){
    q.push(start);
    bcheck[start] =true;
    while(!q.empty()){
        int temp = q.front(); q.pop();
        printf("%d ",temp);
        bcheck[temp] = true;
        for(int i : vec[temp]){
            if(!bcheck[i]) {
                q.push(i);
                bcheck[i] = true;
            }
        }
    }
}


int main(){
    scanf("%d %d %d",&n,&m,&v);
    while(m--){
        int f,t;
        scanf("%d %d",&f,&t);
        vec[f].push_back(t);
        vec[t].push_back(f);
    }
    for(int i=0;i<n;i++)
        sort(vec[i].begin(),vec[i].end());

    dfs(v);
    printf("\n");
    bfs(v);
}
