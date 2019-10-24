#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
/*
6 4
1 2
2 3
1 3
4 5
*/
ll a[100001];
vector<ll>g[100005];
ll k;
ll visit[100001];
void dfs(ll i)
{
    visit[i]=1;
    for(auto m:g[i])
    {
        if(visit[m]==0)
        {
            //visit[m]=1;
            dfs(m);
        }
    }
}
int main()
{
    ll n,i,u,v;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        //cin>>a[i];
        visit[i]=0;
    }
    for(i=1;i<=k;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //dfs(1,1);
    //cout<<cnt<<endl;
    ll c=0;
    for(i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            dfs(i);
            c++;
        }
    }
    cout<<c<<endl;
}





