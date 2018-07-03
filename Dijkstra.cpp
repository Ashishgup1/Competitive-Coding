void dijkstra(int source, int destination)
{
	for(int i=1;i<=n;i++)
		dist[i]=1e18;
	dist[source]=0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		vector<pair<int, int> > v;
		for(auto it:g[x.second])
		{
			v.push_back(it);

			if(dist[it.first] > dist[x.second] + it.second)
			{
				s.erase({dist[it.first], it.first});
				dist[it.first]=dist[x.second] + it.second;
				s.insert({dist[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	if(!vis[destination])
	{
		cout<<"-1";
		return;
	}
	int v=destination;
	vector<int> ans;
	while(parent[v])
	{
		ans.push_back(v);
		v=parent[v];
	}
	ans.push_back(source);
	reverse(ans.begin(), ans.end());
	for(auto it:ans)
		cout<<it<<" ";
}

//Sample Problem 1 (Direct Dijkstra): https://codeforces.com/contest/20/problem/C
//Sample Solution 1: https://codeforces.com/contest/20/submission/39891722

//Sample Problem 2: http://codeforces.com/contest/229/problem/B
