#include <stdio.h>
int n,m,t[9];

void func(int cur){
    if(m==cur) {
        for(int i=0;i<m;i++)printf("%d ",t[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(cur>=1){
            if(t[cur-1]>i) continue;
        }
        t[cur]=i;
        func(cur+1);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    func(0);
}