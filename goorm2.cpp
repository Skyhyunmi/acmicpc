#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int tab[52][52];

void fun(int wx,int wy, int x, int y,int remain){

}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",tab[i][j]);
        }
    }
    fun(1,1,n,n,0);
}
