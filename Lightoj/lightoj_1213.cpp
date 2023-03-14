
/*
Shamim Ehsan
SUST CSE 12
*/
#include<stdio.h>
#include<string.h>
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
#include<sstream>
#define PI (2* acos(0))
#define pb push_back
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
ll int big_mod(ll int n,ll int p,ll int mod)
{
    if(p==1)
        return n%mod;
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll int ret = big_mod(n,p/2,mod)%mod;
        return (ret* ret) %mod;
    }
    else
    {
        ll int ret = big_mod(n,p-1,mod)%mod;
        return (ret* n) %mod;
    }
//    return ret%mod;

}
int cases, caseno;
ll int n, K, MOD;
ll int A[1001];

int main()
{
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%lld %lld %lld", &n, &K, &MOD);

        int i, i1, i2, iK;
        ll int res =0;
        for( i = 0; i < n; i++ ) scanf("%lld", &A[i]);


        for( i = 0; i< n; i++ )
        {

            res += (big_mod(A[i],K,MOD))%MOD;
//            cout<<res<<" "<<A[i]<<endl;
        }
        printf("Case %d: %lld\n", ++caseno, res);
    }
    return 0;
}
