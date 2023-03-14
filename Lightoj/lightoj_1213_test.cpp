#include <stdio.h>

int cases, caseno;
int n, K, MOD;
int A[1001],on[5];

int main()
{
//    while( cases-- )
    {

        int i, i1, i2, i3,i4,i5;
        n=5;
//        for( i = 0; i < n; i++ ) scanf("%d", &A[i]);

        int res = 0,osn[3];

        for( i1 = 0; i1 < n; i1++ )
        {
            for( i2 = 0; i2 < n; i2++ )
            {
                for( i3 = 0; i3 < n; i3++ )
                    for(i4=0;i4<n; i4++)
                        for(i5=0; i5< n; i5++)
                        {
                            printf("%d %d %d\n",i1,i2,i3);
                            on[i1]++;
                            on[i2]++;
                            on[i3]++;
                            on[i4]++;
                            on[i5]++;


                        }
            }
        }
        printf("Case %d: %d %d %d %d\n", ++caseno, res,on[0],on[1],on[2]);
    }
    return 0;
}
