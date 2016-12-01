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
#define SZ 1000000
#define SZ2 790000

int c, prime[SZ2];
char  flag[SZ];


void sieve(void)
{
    int i, j, add;
    flag[0] = flag[1] = 1;
    prime[c++] = 2;
    for(i = 4; i < SZ; i+=2)
        flag[i] = 1;
    for(i = 3; i < SZ; i+=2)
    {
        if(!flag[i])
        {
            prime[c++] = i;
            if(SZ/i >= i)
            {
                add = i * 2;
                for(j = i * i; j < SZ; j += add)
                    flag[j] = 1;
            }
        }
    }
}
ll int POW(int n,int p)
{
    ll int temp=1;
    for(int i=1;i<=p;i++)
    temp*=n;
    return temp;
}
int main()
{
    int t;
    ll int a,b,lcm;
    scanf("%d",&t);
    sieve();
    for(int cs=1; cs<=t; cs++)
    {
        int imp=0;
        scanf("%lld %lld %lld",&a,&b,&lcm);
        ll int lcm_ab=(a*b)/__gcd(a,b);
        int tmp = (int)sqrt((double)lcm) ;
        ll int ret = 1 ;
        ll int LCM_temp=lcm,LCM_AB_TEMP=lcm_ab;
        ll int ans=1;
        for(int i=0; prime[i]<=tmp; i++)
        {
            int tk=0,tk2=0,cnt=0,cnt2=0;
            if(LCM_temp % prime[i] == 0)
            {
                cnt =  0 ;
                while(LCM_temp % prime[i] == 0)
                {
                    cnt ++ ;
                    LCM_temp /= (ll)prime[i] ;
                }
                tmp = sqrt((double)LCM_temp) ;
                tk=1;
            }
            if(LCM_AB_TEMP % prime[i] == 0)
            {
                cnt2 =  0 ;
                while(LCM_AB_TEMP % prime[i] == 0)
                {
                    cnt2 ++ ;
                    LCM_AB_TEMP /= (ll)prime[i] ;
                }
                tk2=1;
            }
            if(tk2 && !tk)
            {
                imp=1;
                break;
            }
            if(cnt2>cnt)
            {
                imp=1;
                break;
            }
            else
            {

                if(cnt!=cnt2)
                    ans*=POW(prime[i],cnt);

            }
        }
        if(LCM_temp!= 1 && LCM_AB_TEMP==1)
        {
            ans*=LCM_temp;
        }
        if(!imp)
        {
            if( (ans*lcm_ab)/__gcd(ans,lcm_ab)!=lcm)
                printf("Case %d: impossible\n",cs);
            else
                printf("Case %d: %lld\n",cs,ans);

        }
        else
            printf("Case %d: impossible\n",cs);

    }

    return 0;
}


