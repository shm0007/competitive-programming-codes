#include <stdio.h>
#define max(a,b) (a>b)?a:b;
int main()
 {
  int r,c,r1,ans,temp,t1,t,cs=1;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d %d",&r,&c);

    if(r==1 || c==1)
    ans=r*c;
    else if(r==2 || c==2)
    {
        temp=max(r,c)
        t1=2*(temp/4);
        if(temp%4==3)
        t1+=2;
        else
        t1+=temp%4;
        ans=t1*2;
    }


else
ans=(c*r+1)/2;


    printf("Case %d: %d\n",cs++,ans);
    }
return 0;
}
