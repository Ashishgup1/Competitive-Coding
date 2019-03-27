
int indeg[N];
vector<int> topo; //Stores lexicographically smallest toposort
vector<int> g[N];

bool toposort() //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=1;i<=n;i++)
		for(auto &it:g[i])
			indeg[it]++;
	for(int i=1;i<=n;i++)
	{
		if(!indeg[i])
			pq.push(i);
	}
	while(!pq.empty())
	{
		int u=pq.top();
		pq.pop();
		topo.push_back(u);
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				pq.push(v);
		}
	}
	if(topo.size()<n)
		return 0;
	return 1;
}

//Problem 1: https://www.spoj.com/problems/TOPOSORT/
//Solution 1: http://p.ip.fi/RTRG
