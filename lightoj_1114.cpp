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
char dick[101100];
int text[110][130][130];

int main()
{
    int t;
    char temp[1500];
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {

        memset(text,0,sizeof(text));
        int n,len;
        map<string,int>mp;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",temp);
            len=strlen(temp);
            if(len>3)
            sort(temp+1,temp+len-1);
            if(mp.find(temp)==mp.end())
            mp[temp]=1;
            else
            mp[temp]++;
        }
        int q;
        char *p;
        scanf("%d",&q);
        getchar();
        printf("Case %d:\n",cs);
        while(q--)
        {
           int ans = 1;
            gets(dick);
            p = strtok(dick , " ");
            while(p != NULL)
            {
                strcpy(temp , p);
//                puts(one);
                len = strlen(temp);
                if(len>3)
                sort(temp+1,temp+len-1);
                ans *= mp[temp];
                p = strtok(NULL , " ");
            }
        printf("%d\n",ans);
        }


    }

    return 0;
}

