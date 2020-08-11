#include <stdio.h>
#define RAD_SQURE(x, y) (x*x+y*y)

int main(void)
{
	int test_case;
	int T;
    int x, y, N;
    int rad[10];
    for ( int i =0 ; i<10; i++)
        rad[i] = (i+1)*20;
	setbuf(stdout, NULL);
    scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
        int sum=0;
        scanf("%d", &N);
        for ( int j = 0; j< N; j++)
        {
            scanf("%d %d",&x, &y);
            for ( int i =0 ; i<10; i++)
                if (RAD_SQURE(x, y)<=(rad[i]*rad[i]))
                {
                    sum += 11-rad[i]/20;
                    break;
                }
        }
        printf("#%d %d\n", test_case, sum);
	}
	return 0;
}
