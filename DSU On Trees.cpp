//Logic: https://codeforces.com/blog/entry/44351

int col[N], cnt[N], f[N], subtree[N], big[N], ans[N];
vector<int> g[N];
multiset<int> active;

void getsz(int v, int p) 
{
	subtree[v]=1;
	for(auto u:g[v])
	{
		if(u==p)
			continue;
		getsz(u, v);
		subtree[v]+=subtree[u];
	}
}

void add(int v, int p, int x) //Function changes as per question, 
{
	active.erase(cnt[col[v]]);
	f[cnt[col[v]]]-=col[v];
	cnt[col[v]]+=x;
	active.insert(cnt[col[v]]);
	f[cnt[col[v]]]+=col[v];
	for(auto u:g[v])
	{
		if(u!=p && !big[u])
			add(u, v, x);
	}
}

void computeans(int v)
{
	int maxf=*(--active.end());
	ans[v]=f[maxf];
}

void dfs(int v, int p, int keep)
{
	int mx = -1, bigChild = -1;
	for(auto u:g[v])
	{
		if(u!=p && subtree[u]>mx)
			mx=subtree[u], bigChild=u;
	}
	for(auto u:g[v])
	{
		if(u!=p && u!=bigChild)
			dfs(u, v, 0); //Run DFS on small children and clear them
	}
	if(bigChild!=-1)
	{
		dfs(bigChild, v, 1);
		big[bigChild]=1;
	}
	add(v, p, 1); 
	//Now we have the information of subtree of v
	computeans(v);
	if(bigChild!=-1)
		big[bigChild]=0;
	if(keep==0)
		add(v, p, -1);
}

//Sample Problem 1: https://codeforces.com/contest/600/problem/E
//Sample Solution 1: https://codeforces.com/contest/600/submission/40033997

//Sample Problem 2: https://codeforces.com/contest/570/problem/D
//Sample Solution 2 (Offline Processing): https://codeforces.com/contest/570/submission/40034531

//Sample Problem 3: https://codeforces.com/problemset/problem/246/E
//Sample Solution 3: https://codeforces.com/contest/246/submission/40040432

//Sample Problem 4: https://codeforces.com/contest/375/problem/D
//Sasmple Solution 4: https://codeforces.com/contest/375/submission/40044165
