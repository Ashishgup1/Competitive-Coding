
const int N = 1e5+5;
const int LG = log2(N) + 1;

int n, tim=0;
int a[N], level[N], tin[N], tout[N], rtin[N], nxt[N], subtree[N], parent[LG][N];
vector<int> g[N];

//Heavy Light Decomposition

void dfs(int u, int par, int lvl)
{	
	parent[0][u] = par;
	level[u] = lvl;
	for(auto &it:g[u])
	{
		if(it==par)
			continue;
		dfs(it, u, lvl+1);
	}
}

void dfs1(int u, int par)
{
	subtree[u] = 1;
	for(auto &it:g[u])
	{
		if(it==par)
			continue;
		dfs1(it, u);
		subtree[u] += subtree[it];
		if(subtree[it] > subtree[g[u][0]])
			swap(it, g[u][0]);
	}
}

void dfs_hld(int u, int par)
{
	tin[u] = ++tim;
	rtin[tim] = u;
	for(auto &v:g[u])
	{
		if(v==par)
			continue;
		nxt[v] = (v==g[u][0] ? nxt[u]:v);
		dfs_hld(v, u);
	}
	tout[u] = tim;
}

//LCA

int walk(int u, int h)
{
	for(int i=LG-1;i>=0;i--)
	{
		if((h>>i) & 1)
			u = parent[i][u];
	}
	return u;
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

int dist(int u, int v)
{
	return level[u] + level[v] - 2 * level[LCA(u, v)];
}

//Segment Tree

int st[4*N], lazy[4*N];

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=a[rtin[L]];
		return;
	}
	int M=(L+R)/2;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	st[node]=min(st[node*2], st[node*2+1]);
}

void propagate(int node, int L, int R)
{	
	if(L!=R)
	{
		lazy[node*2]+=lazy[node];
		lazy[node*2+1]+=lazy[node];
	}
	st[node]+=lazy[node];
	lazy[node]=0;
}

int query(int node, int L, int R, int i, int j)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return 1e9;
	if(i<=L && R<=j)
		return st[node];
	int M=(L+R)/2;
	int left=query(node*2, L, M, i, j);
	int right=query(node*2 + 1, M+1, R, i, j);
	return min(left, right);
}

void update(int node, int L, int R, int i, int j, int val)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		lazy[node]+=val;
		propagate(node, L, R);
		return;
	}
	int M=(L+R)/2;
	update(node*2, L, M, i, j, val);
	update(node*2 + 1, M+1, R, i, j, val);
	st[node]=min(st[node*2], st[node*2 + 1]);
}

void upd(int l, int r, int val)
{
	update(1, 1, n, l, r, val);
}

int get(int l, int r)
{
	return query(1, 1, n, l, r);
}
//Utility Functions

int query_up(int x, int y) //Assuming Y is an ancestor of X
{
	int res = 0;
	while(nxt[x] != nxt[y])
	{
		res += get(tin[nxt[x]], tin[x]);
		x = parent[0][nxt[x]];
	}
	res += get(tin[y] + 1, tin[x]); //use tin[y] to include Y
	return res;
}

int query_hld(int x, int y)
{
	int lca = LCA(x, y);
	int res = query_up(x, lca) + query_up(y, lca);
	return res;
}

void update_up(int x, int y, int val) //Assuming Y is an ancestor of X
{
	while(nxt[x] != nxt[y])
	{
		upd(tin[nxt[x]], tin[x], val);
		x = parent[0][nxt[x]];
	}
	upd(tin[y] + 1, tin[x], val); //use tin[y] to include Y
}

void update_hld(int x, int y, int val)
{
	int lca = LCA(x, y);
	update_up(x, lca, val);
	update_up(y, lca, val);
}

void hld()
{
	dfs(1, 0, 1);
	dfs1(1, 0);
	dfs_hld(1, 0);
	precompute();
	build(1, 1, n);
}

//Problem 1 (Maximum Climb for nodes with same value): https://www.codechef.com/CONA2019/problems/COMA19E
//Solution 1: https://www.codechef.com/viewsolution/23271645
