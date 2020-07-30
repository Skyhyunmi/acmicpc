#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>
using namespace std;

int sqrtN;

struct Query{
    int idx,s,e;
};

bool comp (const Query &a,const Query &x){
    if(a.s / sqrtN != (x.s) / sqrtN) return a.s / sqrtN < (x.s) / sqrtN;
    return a.e < x.e;
}

vector<Query> q;
vector<int> v;
int main(){
    int n;
    scanf("%d",&n);
    sqrtN = sqrt(n);
    for(int i=0;i<n;i++) {
        int t;
        scanf("%d",&t);
        v.push_back(t);
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int s, e;
        scanf("%d %d",&s,&e);
        struct Query T = {i,s,e};
        q.push_back(T);
    }
    sort(q.begin(),q.end(),comp);
    long long sum = 0,ans[100005];
    int s = q[0].s, e = q[0].e;
    for(int i=s;i<e;i++) sum += v[i];
    ans[q[0].idx] = sum;
    for(int i=1;i<m;i++){
        while(s<q[i].s) sum-=v[s++];
        while(s>q[i].s) sum+=v[--s];
        while(e>q[i].e) sum-=v[e--];
        while(e<q[i].e) sum+=v[++e];
        ans[q[i].idx] = sum;
    }
    for(int i=0;i<m;i++) printf("%lld\n",ans[i]);
}