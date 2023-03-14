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
map<int,int>mp;
map<int,int>rev;
int prime[]= {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};
int in=0;
int dist[109700];
char vis[109700];
int flag[150];
void bfs(int st)
{
    memset(dist,-1,sizeof dist);
    memset(vis,0,sizeof vis);
    vis[mp[st]]=1;
    dist[mp[st]]=0;
    queue<int>Q;
    Q.push(mp[st]);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        int num=rev[u];
        if(u==0)
            return;
        vector<int>V;
        while(num)
        {
            V.pb(num%10);
            num/=10;
        }
        reverse(V.begin(),V.end());
        for(int i=0; i<8; i++)
        {
            for(int j=i+2; j<8; j++)
            {
                if(flag[V[i]]!=flag[V[j]] && prime[V[j]+V[i]])
                {
                    //set i before position j
                    int   nn=0;
                    for(int k=0; k<i; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    for(int k=i+1; k<j; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    nn*=10;
                    nn+=V[i];
                    nn*=10;
                    nn+=V[j];
                    for(int k=j+1; k<8; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    if(mp.find(nn)==mp.end())
                    {
                        mp[nn]=in++;
                        rev[in-1] = nn;
                    }
                    if(vis[mp[nn]]==0)
                    {
                        vis[mp[nn]]=1;
                        dist[mp[nn]]=dist[u]+1;
                        Q.push(mp[nn]);

                    }
                    //set i after position j
                    nn=0;
                    for(int k=0; k<i; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    for(int k=i+1; k<j; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    nn*=10;
                    nn+=V[j];
                    nn*=10;
                    nn+=V[i];
                    for(int k=j+1; k<8; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    if(mp.find(nn)==mp.end())
                    {
                        mp[nn]=in++;
                        rev[in-1] = nn;
                    }
                    if(vis[mp[nn]]==0)
                    {
                        vis[mp[nn]]=1;
                        dist[mp[nn]]=dist[u]+1;
                        Q.push(mp[nn]);

                    }
                    //set j after position i
                    nn=0;
                    for(int k=0; k<i; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    nn*=10;
                    nn+=V[i];
                    nn*=10;
                    nn+=V[j];
                    for(int k=i+1; k<j; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    for(int k=j+1; k<8; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    if(mp.find(nn)==mp.end())
                    {
                        mp[nn]=in++;
                        rev[in-1] = nn;
                    }
                    if(vis[mp[nn]]==0)
                    {
                        vis[mp[nn]]=1;
                        dist[mp[nn]]=dist[u]+1;
                        Q.push(mp[nn]);
                    }
                    //set j before position i
                    nn=0;
                    for(int k=0; k<i; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    nn*=10;
                    nn+=V[j];
                    nn*=10;
                    nn+=V[i];

                    for(int k=i+1; k<j; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }

                    for(int k=j+1; k<8; k++)
                    {
                        nn*=10;
                        nn+=V[k];
                    }
                    if(mp.find(nn)==mp.end())
                    {
                        mp[nn]=in++;
                        rev[in-1] = nn;
                    }
                    if(vis[mp[nn]]==0)
                    {
                        vis[mp[nn]]=1;
                        dist[mp[nn]]=dist[u]+1;
                        Q.push(mp[nn]);
                    }
                }
            }
        }

    }
    return;
}
int main()
{
    mp[12345678]=0;
    rev[0]=12345678;
    int t;
    int arr[150];
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        for(int i=0; i<8; i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]<0)
            {
                arr[i]*=-1;

                flag[arr[i]]=1;
            }
            else
                flag[arr[i]]=0;

        }
        int nn=0;
        for(int i=0; i<8; i++)
        {
            nn*=10;
            nn+=arr[i];

        }
        in++;
        if(mp.find(nn)==mp.end())
        {
            mp[nn]=in++;
            rev[in-1]=nn;
        }
        bfs(nn);
        printf("Case %d: %d\n",cs,dist[0]);
    }
    return 0;
}


