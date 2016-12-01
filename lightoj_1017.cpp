#include <stdio.h>
int main ()
{
    int i,j,n,sum,prod;
    prod=1,sum=0;
    scanf ("%d",&n);
    for (i=1;i<=n;i++) {
        prod=1;
        for (j=0;j<i;j++)
        {
            prod=prod*i;
        }
        sum=sum+prod;
    }
    printf ("the sum is %d\n",sum);
    return 0;
}
