# include <stdio.h>
 
int main() {
    int test_case;
    int T = 10;
    int N;
    for (test_case = 1; test_case <= T; ++test_case) {
        int arr[110] = {0, };
        scanf("%d ", &N);
 
        for (int i = 0; i < N; i++) {
            scanf("%1d", &arr[i]);
        }
 
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                for (int j = i; j < N - 2; j++) 
                {
                    arr[j] = arr[j + 2];
                }
                N = N - 2;
                i = -1;
            }
        }
 
 
        printf("#%d ", test_case);
        for (int i = 0; i < N; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
 
 
    }
    return 0;
 
}