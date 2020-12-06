#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
int num[10],t[10];
bool visit[10];
void func(int cur){
    if(cur == m){
        for(int i=0;i<m;i++)printf("%d ",t[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++){
        if(!visit[i]){
            visit[i]=true;
            t[cur]=num[i];
            func(cur+1);
            visit[i]=false;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    sort(num,num+n);
    func(0);
}