#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n,k,Min=10000000,res=0;
bool visit[200'006];
void start(){
    queue<pair<int,int>> q;
    q.push({n,0});
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(Min < cnt) continue;
        visit[cur]=true;
        if(cur == k){
            Min=min(Min,cnt);
            res++;
            continue;
        }
        if(cur+1<=k && !visit[cur+1]) q.push({cur+1,cnt+1});
        if(cur-1 >= 0 && !visit[cur-1]) q.push({cur-1,cnt+1});
        if(cur*2<=k*2 && !visit[cur*2]) q.push({cur*2,cnt+1});
    }
}

int main(){
    scanf("%d %d",&n,&k);
    start();
    printf("%d\n%d",Min,res);
}