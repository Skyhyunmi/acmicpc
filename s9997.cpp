#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int th=0;
        scanf("%d",&th);
        int h = th/30;
        int m = th%30;
        printf("#%d %d %d\n",test_case,h,m*2);
	}
	return 0;
}