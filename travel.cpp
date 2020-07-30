#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
bool tab[60][60];
int n;
char in[60],out[60];


int main(){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
        for(int i=0;i<55;i++){
            memset(tab[i],0,sizeof(bool) * 51);
        }
        scanf("%s",in);
        scanf("%s",out);

        for(int i=0;i<n;i++) {
            tab[i][i]=true;
            if(i-1 >= 0 && out[i]=='Y' && in[i-1]=='Y'){
                tab[i][i-1]=true;
                for(int j=i-1;j>=0;j--){
                    if(out[j] == 'Y' && j-1 >= 0 && in[j-1] == 'Y') tab[i][j-1]=true;
                    else break;
                }
            }

            if(i+1 < n && out[i]=='Y' && in[i+1]=='Y'){
                tab[i][i+1]=true;
                for(int j=i+1;j<n;j++){
                    if(out[j] == 'Y' && j+1<n && in[j+1] == 'Y') tab[i][j+1]=true;
                    else break;
                }
            }
        }
        printf("Case #%d:\n",tt);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c",tab[i][j]?'Y':'N');
            }
            printf("\n");
        }
    }
    return 0;
}