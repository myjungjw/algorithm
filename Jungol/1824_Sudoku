#include <stdio.h>
int map[9][9];

void input(){
    freopen("sudoku.txt","r",stdin);
    for ( int i = 0 ; i < 9 ; i++ ){
        for ( int j = 0 ; j < 9 ; j++ ){
            scanf("%d", &map[i][j]);
        }
    }
}
void output(){
    for ( int i = 0 ; i < 9 ; i++ ){
        for ( int j = 0 ; j < 9 ; j++ ){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}


int check(int i, int j, int k){
    for ( int y = 0 ; y < 9 ; y++ ) if (map[y][j]==k) return 0;
    for ( int x = 0 ; x < 9 ; x++ ) if (map[i][x]==k) return 0;

    int startx = j / 3 * 3;
    int starty = i / 3 * 3;
    for ( int y = starty ; y < starty + 3 ; y++){
        for ( int x = startx ; x < startx + 3 ; x++){
            if (map[y][x] == k) return 0;
        }
    }
    return 1; 
}

int dfs(){
    int zeroCnt=0;
    for ( int i = 0 ; i < 9 ; i++ ){
        for ( int j = 0 ; j < 9 ; j++ ){
            if (map[i][j] != 0) continue;
            zeroCnt++;
            for ( int k = 1 ; k <= 9 ; k++ ){
                
                int result = check(i, j, k);
                if (result == 1) {
                    map[i][j] = k;
                    if (dfs() == 1 ) return 1;
                    map[i][j] = 0;
                }
            }
            
        }
    }
    if (zeroCnt == 0 ) return 1;
    else return 0;
}

int main(){
    input();
    dfs();
    output();
    return 0;
}
