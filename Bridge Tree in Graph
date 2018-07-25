int tim=0, grp=1;
int u[N], v[N], comp[N];
bool vis[N], vis2[N], isBridge[M];
int tin[N], tout[N], minAncestor[N];
queue<int> Q[N];
vector<pair<int, int> > g[N];
vector<int> tree[N], vertices[N]; //Tree stores Bridge Tree, vertices stores the nodes in each component 

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

void dfs2(int k)
{
	int comp=grp;
	Q[comp].push(k);
	vis2[k]=1;
	while(!Q[comp].empty())
	{
		int u=Q[comp].front();
		Q[comp].pop();
		vertices[comp].push_back(u);
		for(auto it:g[u])
		{
			int v=it.first;
			int edgeidx=it.second;
			if(vis2[v])
				continue;
			if(isBridge[edgeidx])
			{
				grp++;
				tree[comp].push_back(grp);
				tree[grp].push_back(comp);
				dfs2(v);
			}
			else
			{
				Q[comp].push(v);
				vis2[v]=1;
			}
		}
	}
}

//Problem 1: http://codeforces.com/contest/1000/problem/E
//Solution 1: http://codeforces.com/contest/1000/submission/40743431

//Problem 2: http://codeforces.com/contest/178/problem/B3
//Solution 2: http://codeforces.com/contest/178/submission/40744889
