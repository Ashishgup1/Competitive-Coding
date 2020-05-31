
int grp = 0;
vector<int> g[N], newg[N], rg[N], todo;
int comp[N], indeg[N], sz[N];
bool vis[N];
set<int> gr[N];

void dfs(int u)
{
	vis[u] = 1;
	for(auto &it:g[u])
	{
		if(!vis[it])
			dfs(it);
	}
	todo.push_back(u);
}

void dfs2(int u, int val)
{
	comp[u] = val;
	sz[val]++;
	for(auto &it:rg[u])
	{
		if(comp[it] == -1)
			dfs2(it, val);
	}
}

void sccAddEdge(int from, int to)
{
	g[from].push_back(to);
	rg[to].push_back(from);
}

void scc()
{
	for(int i = 1; i <= n; i++)
		comp[i] = -1;

	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			dfs(i);
	}

	reverse(todo.begin(), todo.end());

	for(auto &it:todo)
	{
		if(comp[it] == -1)
			dfs2(it, ++grp);
	}

	/*Uncomment if SCC Tree is reqd

	for(int i = 1; i <= n; i++)
		for(auto &it:g[i])
			if(comp[i] != comp[it])
				gr[i].insert(it);

	*/
}

//Sample Problem 1 (SCC Compression): http://codeforces.com/contest/999/problem/E
//Sample Solution 1: http://codeforces.com/contest/999/submission/39489910

//Sample Problem 2 (Detection of Directed Cycle in a connected component): http://codeforces.com/contest/505/problem/D
//Sample Solution 2: http://codeforces.com/contest/505/submission/39885530

//Sample Problem 3: https://codeforces.com/contest/118/problem/E
//Sample Solution 3: https://codeforces.com/contest/118/submission/39888563

//Problem 4 (Weakly connected component): https://codeforces.com/problemset/problem/505/D

