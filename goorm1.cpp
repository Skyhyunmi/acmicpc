#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int maxhb = 220-n;
    int hb=-1;
    string hbc;
    int res[10]={0,};
    while(~scanf("%d",&hb)){
        if(100*hb/maxhb <60){
            res[0]++;
        }
        else if(100*hb/maxhb<68){
            res[1]++;
        }
         else if(100*hb/maxhb<75){
            res[2]++;
        } else if(100*hb/maxhb<80){
            res[3]++;
        } else if(100*hb/maxhb<90){
            res[4]++;
        } else{
            res[5]++;
        }
        printf("%d %d %d %d %d %d\r",res[5],res[4],res[3],res[2],res[1],res[0]);
    }
    
}