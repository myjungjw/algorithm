#include <stdio.h>
int main(void)
{
    int test_case;
    int T;
    int arr[100010]={0,};
    int N;
    int in;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int arr[100000]={0,};
        int cnt=0;
        scanf("%d",&N);
        for (int i = 1 ; i<=N ; i++){
            scanf("%d", &in);
            arr[in]=1;
        }
 
        for (int i = 1 ; i<=N ; i++){
            while(arr[i]==1){
                cnt = cnt+1;
                break;
            }
        }
 
        printf("#%d ",test_case);
        if(cnt==N) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}