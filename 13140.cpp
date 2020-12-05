#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n;
int check[10];

int main(){
    scanf("%d",&n);
    while(n){

    }
    for(int h=1;h<10;h++){
        check[h]=true;
        for(int w=1;w<10;w++){
            check[w]=true;
            int tmp = n/10000;
            if(h+w != tmp) {
                check[h]=false;
                check[w]=false;
                continue;
            }
            for(int e=0;e<10;e++){
                check[e]=true;
                for(int o=0;o<10;o++){
                    check[o]=true;
                    tmp = n/1000;
                    tmp%=10;
                    if(e+o != tmp) {
                        check[e]=false;
                        check[o]=false;
                        continue;
                    }
                    for(int r=0;r<10;r++){
                        check[r]=true;
                        for(int l=0;l<10;l++){
                            check[l]=true;
                            tmp = n/100;
                            tmp%=10;
                            if(r+l !=tmp) {
                                check[l]=false;
                                check[r]=false;
                                continue;
                            }
                            tmp = n/10;
                            tmp%=10;
                            if(l+l != tmp){
                                check[l]=false;
                                check[r]=false;
                                continue;
                            }
                            for(int d=0;d<10;d++){
                                check[d]=true;
                                tmp = n%10;
                                if(o+d != tmp) {
                                    check[d]=false;
                                    continue;
                                }
                                else printf("%d%d%d%d%d",h,e,l,l,o);
                                
                            }
                            
                        }
                        
                    }
                 
                }
                
            }
            
        }
        
    }
}