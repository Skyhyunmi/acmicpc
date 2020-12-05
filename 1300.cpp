#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;
vector<int> v;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int sq = sqrt(k);
    for(int i=1;i<sq+1;i++){
        v.push_back((sq+1)*i);
        v.push_back((sq+1)*i);
    }
    sort(v.begin(),v.end());
    printf("%d\n",v[k - sq*sq]);
}