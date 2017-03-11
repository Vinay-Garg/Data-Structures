#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int R; 
        int C; 
        scanf("%d %d",&R,&C);
        char* G[R];
        for(int G_i = 0; G_i < R; G_i++){
           G[G_i] = (char *)malloc(1024 * sizeof(char));
           scanf("%s",G[G_i]);
        }
        int r; 
        int c; 
        scanf("%d %d",&r,&c);
        char* P[r];
        for(int P_i = 0; P_i < r; P_i++){
           P[P_i] = (char *)malloc(1024 * sizeof(char));
           scanf("%s",P[P_i]);
        }

        int flag=0, temp=1;

        for (int i = 0; i <= R-r; i++)
        {
            for (int j = 0; j <= C-c; j++)
            {
                if(G[i][j] == P[0][0])
                {
                    for (int x = 0;  x<r; x++)
                    {
                        for (int y = 0; y<c; y++)
                        {
                            if(G[i+x][j+y] != P[x][y])
                            {
                                temp = 0;
                                break;
                            }
                            if(temp == 0)
                                break;
                        }
                    }

                    if(temp)
                        flag = 1;   
                    else
                        temp = 1;                 
                }
            }
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
