#include <stdio.h>

bool visit[10];
int num[10];
int n,m;
void func(int cur){
    if(m==cur) {
        for(int i=0;i<m;i++)
            printf("%d ",num[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            visit[i]=true;
            num[cur]=i;
            func(cur+1);
            visit[i]=false;
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    func(0);
}