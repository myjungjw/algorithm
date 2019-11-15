#include <stdio.h>
char str[1010];
char search[15];
static int cnt;
 
int recur(int i, int j)
{
    if (search[j] == NULL)
    {
        cnt = cnt + 1;
        return 0;
    }
    else if (str[i] == search[j])
    {
        recur(i + 1, j + 1);
        return 0;
    }
    else return 0;
}
 
int main() {
    int test_case = 10;
 
    for (int T = 1; T <= test_case; T++)
    {
        scanf("%d", &T);
        scanf("%s", search);
        scanf("%s", str);
 
        for (int i = 0; str[i] != NULL; i++)
        {
            if (str[i] == search[0])
            {
                recur(i, 0);
            }
        }
 
        printf("#%d %d \n", T, cnt);
        cnt=0;
    }
    return 0;
}