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

int X[]= {0,0,1,-1};
int Y[]= {-1,1,0,0};
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen)
{
    for (int j = 0; j < w[i].size(); j++)
    {
        if (w[i][j] && !seen[j])
        {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen))
            {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w)
{
    VI mr = VI(w.size(), -1);
    VI mc = VI(w[0].size(), -1);

    int ct = 0;
    for (int i = 0; i < w.size(); i++)
    {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d %d",&n,&m);
        VVI w(n,VI(n,0));
        int u,v;

        while(m--)
        {
            scanf("%d %d",&u,&v);
            w[u-1][v-1]=1;
        }
        printf("Case %d: %d\n",cs,n-BipartiteMatching(w));

    }


    return 0;
}

