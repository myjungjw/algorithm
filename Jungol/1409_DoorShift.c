#include <stdio.h>

int N;
int A, B;           // open 상태인 문 번호 
int num;            // 사용할 벽장 수
int order[20];
int visit[20];
int min;

void input()
{
    freopen("DoorShift.txt","r",stdin);
    scanf("%d", &N);
    scanf("%d %d", &A, &B);
    scanf("%d", &num);
    for ( int t = 1 ; t <= num ; t++ )
    {
        scanf("%d", &order[t]);
    }
    return;
}

void dfs(int start)
{
    // 벽장 순서대로 돌면서 해결
    visited[start] = 1;
    for ( int i = 1 ; i <= num ; i++ ){
        if ( ( order[i] == A || order[i] == B )) continue;   // 이미 문 열려있는 경우

        // order[i]가 A 왼쪽인 경우
        // order[i]가 B 오른쪽인 경우
        // order[i]가 A-B 사이인 경우

        if ( order[i] < A ){
            while( A != order[i]){
                A--;
                min++;
            }
        }else if ( order[i] > B ){
            while( B != order[i]){
                B++;
                min++;
            }
        }else{
            // A를 움직이는 경우
            // B를 움직이는 경우
            while( A != order[i]){
                A++;
                min++;
            }
            if( dfs(i) != 1 ) return 1;
            while( B != order[i]){
                B--;
                min++;
            }
            
        }
    }
    return;
}

int main()
{
    input();
    dfs(1);
    printf("%d", min);
    return 0;
}

