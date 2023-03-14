/*
Shamim Ehsan
SUST CSE 12
*/
#include<stdio.h>
#include<string.h>
#include<bitset>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
#define PI (2* acos(0))
#define pb push_back
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
int main()
{
    int t,n;

    scanf("%d",&t);

    for(int cs=1;cs<=t;cs++)
    {
        int one=0;
        scanf("%d",&n);
//                bitset<64> k(n);
       int zero=true;
        for(int i=0;i<=31;i++)
        {
            if((n&1<<i))
            one++;
            if ((n& 1<<i)==0 && one)
            {
                zero=i;
                break;

            }

        }
        n=n|(1<<(zero));

//        printf("%\n",k.c_str());//<<endl;
//        cout<<k<<endl;;
        one--;
        int on=zero-one;
        for(int i=zero-1;on;on--,i--)
        {
            n &= (~(1<<i));
        }
        for(int i=0;i<one;i++)
        n|=(1<<i);
//                bitset<64> K(n);
//                cout<<K<<endl;
    printf("Case %d: %d\n",cs,n);
    }
    return 0;
}

