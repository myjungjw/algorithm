
#include <stdio.h>
int M, N;
int map[1000][1000];
int wp=0, rp=0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
 
typedef struct _Q{
    int x;
    int y;
    int d;
}Queue;
 
Queue q[1000000];
 
void input(){
    freopen("tomato.txt","r",stdin);
    scanf("%d %d", &M, &N);
    for ( int i = 0 ; i < N ; i++ ){
        for ( int j = 0 ; j < M ; j++ ){
            scanf("%d", &map[i][j]);
            if ( map[i][j] == 1 ){
                q[wp].x = j;
                q[wp].y = i;
                q[wp].d = 0;
                wp++;
            }
        }
    }
    return;
}
 
void bfs(){
    while ( wp != rp ) {
        int curx = q[rp].x;
        int cury = q[rp].y;
        int curd = q[rp].d;
        rp++;
 
        for (int i = 0 ; i < 4 ; i++ ){
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
 
            if ( nextx < 0 || nexty < 0 || nextx >= M || nexty >= N ) continue;
            if ( map[nexty][nextx] != 0 ) continue;
 
            map[nexty][nextx]=1;
 
            q[wp].x = nextx;
            q[wp].y = nexty;
            q[wp].d = curd + 1;
            wp++;
        }
    }
}
 
void output(){
    for ( int i = 0 ; i < N ; i++ ){
        for ( int j = 0 ; j < M ; j++ ){
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
    return;
}

int check(){
    for ( int i = 0 ; i < N ; i++ ){
        for ( int j = 0 ; j < M ; j++ ){
            if ( map[i][j] == 0 ) return -1;
        }
    }
    return 0;
}

int main(){
    input();
    bfs();
    output();
    if ( check() == -1 ) {
        printf("%d", -1);
    }else{
        printf("%d",q[rp-1].d);
    }
    return 0;
}
