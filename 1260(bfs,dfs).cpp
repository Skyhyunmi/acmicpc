#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<int> v[1003],d;
queue<int> q;
bool dchk[10004],bchk[10004];

int main(){
    int n,m,vv;
    scanf("%d %d %d",&n,&m,&vv);
    for(int i=0;i<m;i++){
        int f,t;
        scanf("%d %d",&f,&t);
        v[f].push_back(t);
        v[t].push_back(f);
    }
    for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
    // dchk[vv]=true;
    d.push_back(vv);
    while(!d.empty()){
        int cur = d.back(); d.pop_back();
        if(dchk[cur]) continue;
        dchk[cur]=true;
        printf("%d ",cur);
        int size=v[cur].size();
        for(int i=0;i<size;i++){
            d.push_back(v[cur][size-i-1]);
        }
    }
    printf("\n");
    q.push(vv);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(bchk[cur]) continue;
        bchk[cur]=true;
        printf("%d ",cur);
        int size = v[cur].size();
        for(int i=0;i<size;i++){
            q.push(v[cur][i]);
        }
    }
}