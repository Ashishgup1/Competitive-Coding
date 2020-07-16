struct DirectedEulerPath
{
	int n;
	vector<vector<int> > g;
	vector<int> path;

	void init(int _n)
	{
		n = _n;
		g = vector<vector<int> > (n + 1, vector<int> ());
		path.clear();
	}

	void add_edge(int u, int v)
	{
		g[u].push_back(v);
	}

	void dfs(int u)
	{
		while(g[u].size())
		{
			int v = g[u].back();
			g[u].pop_back();
			dfs(v);
		}
		path.push_back(u);
	}

	bool getPath()
	{
		int ctEdges = 0;
		vector<int> outDeg, inDeg;
		outDeg = inDeg = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
		{
			ctEdges += g[i].size();
			outDeg[i] += g[i].size();
			for(auto &u:g[i])
				inDeg[u]++;
		}
		int ctMiddle = 0, src = 1;
		for(int i = 1; i <= n; i++)
		{
			if(abs(inDeg[i] - outDeg[i]) > 1)
				return 0;
			if(inDeg[i] == outDeg[i])
				ctMiddle++;
			if(outDeg[i] > inDeg[i])
				src = i;
		}
		if(ctMiddle != n && ctMiddle + 2 != n)
			return 0;
		dfs(src);
		reverse(path.begin(), path.end());
		return (path.size() == ctEdges + 1);
	}
};

//Problem 1: https://csacademy.com/contest/round-48/task/matching-substrings/
//Solution 1: http://p.ip.fi/WTb7
