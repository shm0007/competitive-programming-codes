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
char change[10][10];
char temp[150],st[150],end[500];
map<string,int>mp;
void check()
{
    for(int i=0;i<6;i++)
    strcpy(change[i],temp);
   if(temp[0]!='z')
   change[0][0]++;
   else
   change[0][0]='a';
   if(temp[1]!='z')
   change[1][1]++;
   else
   change[1][1]='a';
   if(temp[2]!='z')
   change[2][2]++;
   else
   change[2][2]='a';
   if(temp[0]!='a')
   change[3][0]--;
   else
   change[3][0]='z';
   if(temp[1]!='a')
   change[4][1]--;
   else
   change[4][1]='z';
   if(temp[2]!='a')
   change[5][2]--;
   else
   change[5][2]='z';
//   for(int i=0;i<6;i++)
//   printf("%s\n",change[i]);


}
    int dist[17590];
    char vis[17590];
int bfs(void)
{
    if(mp.find(st)!=mp.end() || mp.find(end)!=mp.end())
    return -1;
    if(!strcmp(st,end))
    return 0;

    memset(vis,0,sizeof(vis));
    queue<string>Q;
    Q.push(st);
    int in=0;
    map<string,int >num;
    num[st]=in++;
    dist[in]=0;
    vis[in]=1;
string ST;
    while(!Q.empty())
    {
        ST=Q.front();
        strcpy(temp,ST.c_str());
        Q.pop();
        check();
        for(int i=0;i<6;i++)
        {
            if(mp.find(change[i])!=mp.end())
            continue;
            if(num.find(change[i])!=num.end())
            continue;
            num[change[i]]=in++;

            if(vis[in-1]==1)
            continue;
            Q.push(change[i]);
            dist[in-1]=dist[num[temp]]+1;
            vis[in-1]=1;
            if(!strcmp(change[i],end))
            return dist[in-1];

        }

    }
return -1;
}
int main()
{
    int t,m;
    char tm[10];
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        mp.clear();
        scanf("%s",st);
//        check(st);
        scanf("%s",end);
        scanf("%d",&m);
        getchar();
        char forbid[3][500];
        for (int j=0;j<m;j++)
        {
            scanf("%s %s %s",forbid[0],forbid[1],forbid[2]);
            getchar();
            tm[3]='\0';
            for(int I=0;I<strlen(forbid[0]);I++)
                for(int J=0;J<strlen(forbid[1]);J++)
                    for(int K=0;K<strlen(forbid[2]);K++)
                    {
                        tm[0]=forbid[0][I];
                        tm[1]=forbid[1][J];
                        tm[2]=forbid[2][K];
                        tm[3]='\0';//forbid[0][i];
                                   mp[(string)tm]=1;
                    }


        }

        printf("Case %d: %d\n",cs,bfs());

    }

    return 0;
}


