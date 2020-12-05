#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int tab[11],res;

int main(){
    for(int i=0;i<10;i++){
        int tmp;
        scanf("%d",&tmp);
        if(i==0) {
            tab[0] = tmp;
            continue;
        }
        tab[i] = tab[i-1] + tmp;
    }
    for(int i=1;i<10;i++){
        if(tab[i-1]<=100 && tab[i] >= 100){
            if(tab[i-1]==100) res=tab[i-1];
            else if (tab[i] == 100) res = tab[i];
            else if(abs(100-tab[i-1]) >= abs(100-tab[i])){
                res = tab[i];
            }
            else res = tab[i-1];
        }
    }
    if(tab[9]<100) res = tab[9];
    printf("%d\n",res);
}