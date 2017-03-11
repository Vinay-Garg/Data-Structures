#include <stdio.h>

int max(int a, int b)
{
    return ((a>b)? a: b );
}

int main() 
{
    int stack[100000];
    int top = 0;

    int t, in, item, m=0, m2=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &in);

        if(in==1)
        {
            scanf("%d", &item);
            if(item > m)
            {
                m2 = m;
                m = item;
            }            

            top++;
            stack[top] = item;
        }

        else if(in==2)
        {   
            if(stack[top] == m)
                m = m2;

            top--;   
        }

        else if(in==3)
        {
            printf("%d\n",m);
        }
    }
    
    return 0;
}