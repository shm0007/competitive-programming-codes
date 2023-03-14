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
struct HopcroftKarp
{
    int n, m;
    vector <vector <int> > adj;
    vector <int> right, left;
    vector <int> dist;

    HopcroftKarp (int n, int m): n(n), m(m), adj(n + 1) {}

    void AddEdge (int l, int r)
    {
        adj[l].push_back(r);
    }

    bool BFS ()
    {
        queue <int> q;
        dist = vector <int>(n + 1, -1);
        for (int l = 1; l <= n; ++l)
        {
            if (right[l] == 0)
            {
                dist[l] = 0;
                q.push(l);
            }
        }

        while (!q.empty())
        {
            int l = q.front();
            q.pop();
            if (dist[0] == -1 || dist[l] < dist[0])
            {

                int sizel=adj[l].size();
                for(int i=0; i<sizel; i++)
                {
                    int r=adj[l][i];
                    if (dist[left[r]] == -1)
                    {
                        dist[left[r]] = dist[l] + 1;
                        q.push(left[r]);
                    }

                }
            }
        }
        return dist[0] != -1;
    }

    bool DFS (int l)
    {
        if (l != 0)
        {
            int sizel=adj[l].size();
            for(int i=0; i<sizel; i++)
            {
              int  r=adj[l][i];
                if (dist[left[r]] == dist[l] + 1 && DFS(left[r]))
                {
                    left[r] = l;
                    right[l] = r;
                    return true;
                }
            }
            dist[l] = -1;
            return false;
        }
        return true;
    }

    int Match ()
    {
        right = vector <int>(n + 1, 0);
        left = vector <int>(m + 1, 0);
        int ret = 0;
        while (BFS())
        {
            for (int l = 1; l <= n; ++l)
            {
                if (right[l] == 0 && DFS(l))
                {
                    ret++;
                }
            }
        }
        return ret;
    }
};
typedef struct {
    int hour,minute,a,b,c,d,total;
}man;
man arr[550];
int main()
{

    int t;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d:%d %d %d %d %d",&arr[i].hour,&arr[i].minute,&arr[i].a,&arr[i].b,&arr[i].c,&arr[i].d);
            arr[i].total=(arr[i].hour*60)+arr[i].minute;
        }
        HopcroftKarp HP(n,n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(arr[i].total+ abs(arr[i].a-arr[i].c)+abs(arr[i].b-arr[i].d) + abs(arr[j].a-arr[i].c)+abs(arr[j].b-arr[i].d) <arr[j].total)
                HP.AddEdge(i,j);
                else if (arr[j].total+ abs(arr[j].a-arr[j].c)+abs(arr[j].b-arr[j].d) + abs(arr[i].a-arr[j].c)+abs(arr[i].b-arr[j].d) <arr[i].total)
                HP.AddEdge(j,i);
            }
            printf("Case %d: %d\n",cs,n-HP.Match());
    }
    return 0;
}
