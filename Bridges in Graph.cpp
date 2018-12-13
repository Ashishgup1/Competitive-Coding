int tim=0;
int u[N], v[N], vis[N];
int tin[N], tout[N], isBridge[M], minAncestor[N];
vector<pair<int, int> > g[N]; //vertex, index of edge

void dfs(int k, int par)
{
	vis[k]=1;
	tin[k]=++tim;
	minAncestor[k]=tin[k];
	for(auto it:g[k])
	{
		if(it.first==par)
			continue;
		if(vis[it.first])
		{	
			minAncestor[k]=min(minAncestor[k], tin[it.first]);
			continue;
		}
		dfs(it.first, k);
		minAncestor[k]=min(minAncestor[k], minAncestor[it.first]);
		if(minAncestor[it.first]>tin[k])
			isBridge[it.second]=1;
	}
	tout[k]=tim;
}

//Sample Problem 1: https://www.spoj.com/problems/EC_P/
//Sample Solution 1: http://p.ip.fi/shDA
