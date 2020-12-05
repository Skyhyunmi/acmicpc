#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int l,p,c,cnt=0;
        scanf("%d %d %d",&l,&p,&c);
        int f=p/c;
        while(f>l){
            printf("%d ",f);
            f/=c;    
            cnt++;
        }
        printf("#%d %d\n",test_case,cnt);
	}
	return 0;
}