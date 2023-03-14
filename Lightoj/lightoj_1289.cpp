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

#define SZ 10000000
#define SZ2 1000000

int c, prime[SZ2+100];
char  flag[SZ+100];
int multi[SZ+100];
void sieve(void);
void sieve(void)
{
    int i, j, add;
    flag[0] = flag[1] = 1;
    prime[c++] = 2;
    multi[2]=2;
    for(i = 4; i < SZ; i*=2)
        multi[i] = 2;
    for(i = 3; i < SZ; i+=2)
    {
        if(!flag[i])
        {
            prime[c++] = i;
            multi[i]=i;
            if(i*i<SZ)
            for(ll int j=(ll int)i* (ll int)i;j<SZ;j*=(ll int)i)
            {

                            multi[j]=i;

            }
            {
                add = i * 2;
                for(j = i * 2; j < SZ; j += i)
                    flag[j] = 1;
            }
        }
    }
}
typedef struct{
int b;
unsigned int a;
}ST;
ST arr[10010];
bool comp(ST A, ST B)
{
    return A.a<B.a;
}
bool comp_2(ST A,ST B)
{
    return A.b<B.b;
}

int check(int n)
{
    int sq=sqrt(n);
    int nm=n;
    for(int i=0;prime[i]<=sq;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
            }
            if(n!=1)
            return 0;
            return prime[i];
        }
    }
return nm;
}
void print_solution(int t)
{
    sort(arr,arr+t,comp_2);
    for(int i=0;i<t;i++)
    printf("Case %d: %u\n",arr[i].b+1,arr[i].a);
}
void solve(int t)
{
    int in=0;
    int mx=arr[t-1].a;
    unsigned int lcm=1;
    for(int i=2;i<=10000000;i++)
    {
        if(multi[i])
        {
//            printf("%u %d %d\n",lcm,multi[i],i);
            lcm*= (unsigned int )multi[i];
        }
        if(arr[in].a==(unsigned int)i)
        arr[in].a=lcm,in++;

    }
    int ck;
    for(int i=10000001;i<=mx;i++)
    {
        ck=check(i);
        if(ck)
        {
            lcm*=(unsigned int)ck;
        }
        if(arr[in].a==i)
        arr[in].a=lcm,in++;

    }
    print_solution(t);
    return ;
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    for(int cs=0;cs<t;cs++)
    {
        scanf("%u",&arr[cs].a);
        arr[cs].b=cs;

    }
    sort(arr,arr+t,comp);
    solve(t);

    return 0;
}
