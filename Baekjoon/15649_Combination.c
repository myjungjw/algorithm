int N, M;       // 1부터 N 까지 M개 고르기
int arr[10];
int visited[10];
# include <stdio.h>
void dfs(int dep){       // dep은 1 ~ N까지 
    if ( dep == M ){
        for ( int i = 1 ; i <= M ; i++ ){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }


    for ( int j = 1 ; j <= N ; j++ ){

        if ( visited[j] == 1 ) continue;

        visited[j] = 1;
        arr[dep+1] = j;
        dfs(dep + 1);
        visited[j] = 0;

    }
}

int main()
{

    scanf("%d %d", &N, &M);
    dfs(0);
    return 0;
}
