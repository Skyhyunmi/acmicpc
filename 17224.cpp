#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main(){
    int n,l,k,e=0,h=0;
    scanf("%d %d %d",&n,&l,&k);
    while(n--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a<=l && l<b) e++;
        if(b<=l) h++;
    }
    int sum=0;
    sum+=140*min(k,h);
    k-=min(k,h);
    if(k){
        sum+=100*min(k,e);
    }
    printf("%d\n",sum);
}