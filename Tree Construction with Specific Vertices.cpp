int tim=0;
int parent[LG][N];
int tin[N], tout[N], level[N], vertices[N];
vector<int> g[N], tree[N];

void dfs(int k, int par, int lvl)
{
	tin[k]=++tim;
	parent[0][k]=par;
	level[k]=lvl;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
	tout[k]=tim;
}

void precompute()
{
	for(int i=1;i<LG;i++)
		for(int j=1;j<=n;j++)
			if(parent[i-1][j])
				parent[i][j]=parent[i-1][parent[i-1][j]];
}

int LCA(int u, int v)
{
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--)
	{
		if((1<<i) & diff)
		{
			u=parent[i][u];
		}
	}
	if(u==v)
		return u;
	for(int i=LG-1;i>=0;i--)
	{
		if(parent[i][u] && parent[i][u]!=parent[i][v])
		{
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	return parent[0][u];
}

bool isancestor(int u, int v) //Check if u is an ancestor of v
{
	return (tin[u]<=tin[v]) && (tout[v]<=tout[u]);
}

int work()
{
	sort(vertices+1, vertices+k+1, [](int a, int b)
	{
		return tin[a]<tin[b];
	});
	int idx=k;
	for(int i=1;i<idx;i++)
		vertices[++k]=LCA(vertices[i], vertices[i+1]);
	sort(vertices+1, vertices+k+1);
	k=unique(vertices+1, vertices+k+1) - vertices - 1;
	sort(vertices+1, vertices+k+1, [](int a, int b)
	{
		return tin[a]<tin[b];
	});
	stack<int> s;
	s.push(vertices[1]);
	for(int i=2;i<=k;i++)
	{
		while(!isancestor(s.top(), vertices[i]))
			s.pop();
		tree[s.top()].push_back(vertices[i]);
		s.push(vertices[i]);
	}
	for(int i=1;i<=k;i++)
		tree[vertices[i]].clear();
}

//Problem 1: http://codeforces.com/contest/613/problem/D
//Solution 1: http://codeforces.com/contest/613/submission/40474762

