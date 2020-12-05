#include <stdio.h>
int ft[10001],tt[10001];
int main(void)
{
	int test_case;
	int T,f,t;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n,cnt=0; scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&f,&t);
            if()
            cnt+=ft[f+1]>tt[t-1]?tt[t-1]:ft[f+1];
            for(int j=f;j<=10000;j++) ft[j]++;
            for(int j=t;j>=0;j--) tt[j]++;
        }
        printf("#%d %d\n",test_case,cnt);
	}
	return 0;
}