#include <iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
struct p
{
    ll s;
    ll e;
    friend bool operator<(p a,p b)
    {
        if(a.s==b.s)
            return a.e>b.e;
        return a.s>b.s;
    }
} x[100010],a;
priority_queue<p> q;
int main()
{
    ll n,t,i,j;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0; i<=n-1; i++)
        {
            scanf("%lld %lld",&x[i].s,&x[i].e);
            q.push(x[i]);
        }
        ll ans=1;
        ll s;
        ll t=n;
        a=q.top();
        q.pop();
        s=a.s+1;
        while(q.size()!=0)
        {
            a=q.top();
            q.pop();
            if(a.s<s)
            {
                if(a.s!=a.e)
                {
                    a.s=s;
                    a.e=a.e;
                    q.push(a);
                }
                continue;
            }
            if(a.e>=s)
            {
                ans++;
                if(a.s>=s)
                {
                    s=a.s+1;
                }
            }
        }
        printf("%lld\n",ans);

    }


}
