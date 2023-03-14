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
char num[1500];
ll int ten[100];
ll int dp[12][2][90][90];
int len,MOD;
ll int rec(int pos,int flag,int mod1,int mod2)
{
    if(pos==len)
    {
//        printf("%d %d\n",mod1,mod2);

        if(mod1%MOD==0 && mod2%MOD==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[pos][flag][mod1][mod2]!=-1)
        return dp[pos][flag][mod1][mod2];
    int current=num[pos]-'0';
    ll int ret=0;
    if(flag==0)
    {
        for(ll int i=0; i<=9; i++)
            ret+=rec(pos+1, 0 , (mod1+(i*ten[len-pos-1])%MOD)%MOD,(mod2+i)%MOD);
    }
    else
    {
        for(ll int i=0; i<current; i++)
            ret+=rec(pos+1,0, (mod1+ (i)*ten[len-pos-1]%MOD)%MOD,(i+mod2)%MOD);
        ret+=rec(pos+1,1, (mod1+ (current)*ten[len-pos-1]%MOD)%MOD,(current+mod2)%MOD);


    }
    return dp[pos][flag][mod1][mod2]=ret;
}
int main()
{
    int t,a,b;
    ten[0]=1;
    for(int i=1; i<=10; i++)
        ten[i]=ten[i-1]*10;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d %d %d",&a,&b,&MOD);
        a--;
        if(MOD>81)
        {
            printf("Case %d: 0\n",cs);
            continue;

        }
        memset(dp,-1,sizeof dp);
        sprintf(num,"%d",a);
//        puts(num);
        len=strlen(num);
        ll int ans= rec(0,1,0,0);
        memset(dp,-1,sizeof dp);
        sprintf(num,"%d",b);
//        puts(num);
        len=strlen(num);
        ll int ans2= rec(0,1,0,0);

        printf("Case %d: %lld\n",cs,ans2-ans);

    }

    return 0;
}


