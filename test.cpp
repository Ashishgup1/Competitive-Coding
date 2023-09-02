//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
6
5
1 2 3 4 5
3
2 3 1
6
4 6 2 1 5 3
1
1
4
3 4 1 2
5
5 1 2 4 3
*/
ll n;
ll compute(ll u,ll a[])
{
    ll cnt=1;
    ll tmp[n];
    for(ll i=1;i<=n;i++)
    {
        tmp[i]=a[i];
    }
    while(tmp[u]!=u)
    {
        tmp[u]=tmp[tmp[u]];
        //u=a[u];
        u=tmp[u];
        cnt++;
    }
    return cnt;
}
int main()
{
    ll t,i,j,k,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n];
        for(i=1;i<=n;i++)
        {
            cin>>m;
            a[i]=m;
            //cout<<a[i]<<" ";
        }
        for(i=1;i<=n;i++)
        {
            ll p=compute(i,a);
            cout<<p<<" ";
        }
        cout<<endl;
        
    }
}