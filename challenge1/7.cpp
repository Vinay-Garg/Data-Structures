#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);

    int l = strlen(s);
    int row = floor(sqrt(l));
    int col = ceil(sqrt(l));

    for (int i = 0; i < col; i++)
    {
        for (int j = i; j < l; j+=col)
            printf("%c", s[j]);
        printf(" ");
    }


    return 0;
}
