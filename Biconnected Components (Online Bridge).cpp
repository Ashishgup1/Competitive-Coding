const int N=1e5+5;

int n, bridges, m;
int bcc[N], comp[N], link[N], sz[N], vis[N];
int current = 0;

void init()
{
	for(int i=0;i<=n;i++)
	{
		bcc[i] = comp[i] = i; //BCC and CC of a node
		link[i] = -1; //Link to parent in Connected Component
		sz[i] = 1; //Size of Connected Component 
	}
	bridges = 0;
}

int getBCC(int u)
{
	if(u == -1)
		return -1;
	if(bcc[u] == u)
		return u;
	return bcc[u] = getBCC(bcc[u]);
}

int getComp(int u)
{
	if(comp[u] == u)
		return u;
	return comp[u] = getComp(comp[u]);
}

void mergePath(int u, int v)
{
	current++;
	vector<int> va, vb;
	int lca = -1;
	while(lca == -1)
	{
		if(u != -1)
		{
			u = getBCC(u);
			va.push_back(u);
			if(vis[u] == current)
				lca = u;
			vis[u] = current;
			u = link[u];
		}
		if(v != -1)
		{
			vb.push_back(v);
			v = getBCC(v);
			if(vis[v] == current)
				lca = v;
			vis[v] = current;
			v = link[v];
		}
	}
	for(auto &it:va)
	{
		bcc[it] = lca;
		if(it == lca)
			break;
		bridges--;
	}
	for(auto &it:vb)
	{
		bcc[it] = lca;
		if(it == lca)
			break;
		bridges--;
	}
}

void MakeRoot(int u)
{
	u = getBCC(u);
	int root = u, child = -1;
	while(u != -1)
	{
		int par = getBCC(link[u]);
		link[u] = child;
		comp[u] = root;
		child = u;
		u = par;
	}
	sz[root] = sz[child];
}

void addEdge(int u, int v)
{
	u = getBCC(u), v = getBCC(v);
	if(u == v)
		return;
	int compu = getComp(u), compv = getComp(v);
	if(compu != compv)
	{
		bridges++;
		if(sz[compu] > sz[compv])
		{
			swap(u, v);
			swap(compu, compv);
		}
		MakeRoot(u);
		link[u] = v;
		comp[u] = v;
		sz[compv] += sz[compu];
	}
	else
		mergePath(u, v);
}

//Problem 1: https://www.codechef.com/ENFE2019/problems/HTST9
//Solution 1: https://www.codechef.com/viewsolution/23221102
