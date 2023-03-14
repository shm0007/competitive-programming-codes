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
//int arr[510];
//bool col[510];
//vector<int>adj[510];
//int man=0;

//int match(void)
//{
//    memset(arr,-1,sizeof arr);
//    int cnt=0;
//    for(int i=0; i<man; i++)
//    {
//        if(adj[i].size()==0)
//        continue;
//        memset(col,false,sizeof col);
//        if(dfs[i]){cout<<i<<endl;cnt++;}
//    }
//    return  cnt;
//}
int  arr[1020];
bool col[1020];
vector<int>adj[1020];
int man;
bool dfs(int now)
{
    if(col[now]) return false;
    col[now]=true;
    int i, end;
    for(i=0; i<adj[now].size(); i++)
    {
        end = adj[now][i];
        if((arr[end]==-1) || (dfs(arr[end])))
        {
            arr[end] = now;
            return true;
        }
    }
    return false;
}
//int match()
//{
//    memset(arr,-1,sizeof arr);
//    int cnt=0;
//    for(int i=0; i<man; i++)
//    {
//        memset(col,false,sizeof col);
//        if(dfs[i])
//            cnt++;
//    }
//    return  cnt;
//}

int match()
{
    memset(arr, -1, sizeof arr);
    int i, cnt=0;
    for(i=0; i<man; i++)
    {
        memset(col, false, sizeof col);
        if(dfs(i))
            cnt++;
    }
    return cnt;
}
int main()
{
    int t,n,m,k,cat,dog,lik,dis;
    char ch,ch2;
    scanf("%d",&t);

    for(int cs=1;cs<=t;cs++)
    {scanf("%d %d %d",&cat,&dog,&man);
        char like[550][10];
        char dislike[550][10];

        char s[150],ss[15];
        for(int i=0; i<man; i++)
        {
            scanf(" %s %s",like[i],dislike[i]);
        }

        for(int i=0; i<=man; i++)
            adj[i].clear();
        for(int i=0; i<man; i++)
            for(int j=0; j<man; j++)
            {
                if(i==j)continue;
                    if(  strcmp(like[i],dislike[j])==0 || strcmp(dislike[i],like[j])==0)
                    {
//                        printf("%d %d\n",i+1,j+1);

                        adj[i].pb(j);
//                        adj[j].pb(i);
//                        puts("s");

                    }
            }
            int ansss=match();
//            printf("%d %d",ansss,man);
        printf("Case %d: %d\n",cs,((man*2 ) - ansss)/2);
    }

    return 0;
}

