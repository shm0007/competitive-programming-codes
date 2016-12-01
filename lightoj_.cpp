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
#define PI (2* acos(0))
#define pb push_back
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
int m,n;
int F[2050000];
char arr[2000000],pattern[5000000];
void build()
{
    F[0] = F[1] = 0; // always true

    for(int i = 2; i <= m; i++)
    {
        int  j = F[i - 1];
        for( ; ; )
        {
            if(pattern[j] == pattern[i - 1])
            {
                F[i] = j + 1;
                break;
            }
            if(j == 0)
            {
                F[i] = 0;
                break;
            }
            j = F[j];
        }
    }
}

int main()
{
    int t,cs=1,ans,num;
    scanf("%d",&t);

    for(cs=1;cs<=t;cs++)
    {
        scanf("%s",arr);
        n=strlen(arr);
        for(int i=0;i<strlen(arr);i++)
        {
//            putchar(arr[n-1-i]);
            pattern[i]=arr[n-1-i];

        }
        pattern[strlen(arr)]='.';
        pattern[strlen(arr)+1]='\0';
//        puts(pattern);
        strcat(pattern,arr);
        m=strlen(pattern);
//        puts(pattern);
        build();
        printf("Case %d: %d\n",cs,m-1-F[m]);

    }
    return 0;
}
