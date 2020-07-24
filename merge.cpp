#include<bits/stdc++.h>
#define mod 1000000007
#define fr first
#define se second
#define endl "\n"
#define ll long long
#define PI 3.1415926535 
#define pb push_back
#define mpr make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
using namespace std;

ll fac[2000005];
void pre(){ fac[0]=1; fac[1]=1; for(int i=2;i<200005;i++) fac[i]=(i*fac[i-1])%mod;}
ll power(ll a,ll b){ll res=1;while(b){if(b&1) res=(res*a)%mod;a=(a*a)%mod;b=b/2;}return res%mod;}
ll ncr(ll n,ll r){return ((fac[n]*power(fac[r],mod-2))%mod*power(fac[n-r],mod-2))%mod;}

void merge (int a[], int b[], int n, int m)
{
    int x=n-1;
    int y=0;
    while(x>=0 && y<m)
    {
        if(a[x] > b[y]){
            swap(a[x], b[y]);
            x--;
            y++;
        }else{
         break;
        }
    }
    sort(a, a+n);
    sort(b, b+m);
}

signed main()
{   

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

      
      
      int n,m;
	    cin>>n>>m;
	    int a[n], b[n];
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    
	    for(int i=0; i<m; i++)
	        cin>>b[i];
	    
	    merge(a,b,n,m);
	    
	    for(int i=0; i<n; i++)
	        printf("%d ", a[i]);
	    
	    for(int i=0; i<m; i++)
	        printf("%d ", b[i]);
	        
	    cout<<endl;





}
