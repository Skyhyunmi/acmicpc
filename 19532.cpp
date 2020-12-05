#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main(){
    int a,b,c,d,e,f,x,y,ta,tb,tc,td,te,tf;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    ta=a*d;tb=b*d;tc=c*d;
    td=d*a;te=e*a;tf=f*a;
    if(te-tb && ta){
        y = (tf-tc)/(te-tb);
        x = (tc-tb*y)/ta;
        goto a;
    }
    ta=a*e;tb=b*e;tc=c*e;
    td=d*b;te=e*b;tf=f*b;
    if(td-ta && tb){
        x = (tf-tc)/(td-ta);
        y = (tc - ta*x)/tb;
        goto a;
    }
    x=0;y=0;
    a:
    printf("%d %d\n",x,y);
}