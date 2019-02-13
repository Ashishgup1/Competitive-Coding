SPFA:

int n, m;
int dist[N], cnt[N];
bool inqueue[N];
vector<pair<int, int> > g[N];

bool negativeCycle() //Returns true if there is a negative cycle
{
	queue<int> q;

	for(int i=1;i<=n;i++)
	{
		dist[i]=cnt[i]=0;
		q.push(i), inqueue[i]=true;
	}

	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		inqueue[v]=false;

		for(auto &edge:g[v])
		{
			int to=edge.first;
			int w=edge.second;

			if(dist[v] + w < dist[to])
			{
				dist[to] = dist[v] + w;
				dist[to] = max(dist[to], INF);
				if(!inqueue[to])
				{
					q.push(to);
					inqueue[to]=true;
					cnt[to]++;
					if(cnt[to]>n)
						return true;
				}
			}
		}
	}
	return false;
}
-----------------------------------------------------------------------------------------------------------------------------------------
Bellman Ford (with Path Printing of the negative cycle):

const int INF=1e9;

struct Edge
{
	int u, v, cost;	
};

int n, m;
vector<Edge> edges;

bool negativeCycle() //Return true if there is a negative cycle in the graph
{
	vector<int> dist(n+1, 0);
	vector<int> par(n, -1);
	int x;
	for(int i=1;i<=n;i++)
	{
		x=-1;
		for(auto &e:edges)
		{
			if(dist[e.u] + e.cost < dist[e.v])
			{
				dist[e.v] = dist[e.u] + e.cost;
				par[e.v] = e.u;
				x = e.v;
			}
		}
	}

	if(x==-1)
		return 0;
	else
	{
		for(int i=1;i<=n;i++)
			x=par[x];
		vector<int> cycle;
		for(int v=x;;v=par[v])
		{
			cycle.push_back(v);
			if(v==x && cycle.size()>1)
				break;
		}
		reverse(cycle.begin(), cycle.end());
		cout<<"Negative cycle: ";
		for(auto &it:cycle)
			cout<<it<<" ";
		cout<<endl;
		return 1;
	}
}

//Question 1: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2031
//Solution 1: http://p.ip.fi/muBP
