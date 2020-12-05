#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int diff[10005];
int check[10005];
int main(void)
{
	int test_case;
	int T,f,t;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n,k,cnt=-1; scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
            int size;
            scanf("%d",&size);
            v.push_back(size);
        }
        int pcur=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            if(i!=0) {check[0]++; continue;}
            int diff = v[i+1]-v[i];
            if(diff<=k) check[pcur]++;
            else pcur++;
        }
        for(int i=0;i<pcur;i++){
            printf("%d ",check[i]);
            if(check[i] >= cnt) cnt = check[i];
        }
        printf("#%d %d\n",test_case,cnt);
	}
	return 0;
}