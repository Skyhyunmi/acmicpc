#include <stdio.h>
int num[10],n,m;
void func(int cur){
    if(m==cur) {
        for(int i=0;i<m;i++) printf("%d ",num[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        num[cur]=i;
        func(cur+1);
    }  
}

int main(){
    scanf("%d %d",&n,&m);
    func(0);
}

/*
#include <cstdio>
int t[10],n,m;
void f(int c){
    int i;
    if(m==c) {
        for(i=0;i<m;i++)printf("%d ",t[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)t[c]=i,f(c+1);
}

int main(){
    scanf("%d%d",&n,&m);
    f(0);
}
*/