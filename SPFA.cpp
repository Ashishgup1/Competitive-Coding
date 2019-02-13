const int INF=1e9;

int n, m;
int dist[N], cnt[N];
bool inqueue[N];
vector<pair<int, int> > g[N];

bool SPFA(int source) //Returns true if there is a negative cycle reachable from source
{
	queue<int> q;

	for(int i=1;i<=n;i++)
	{
		cnt[i]=0;
		dist[i]=INF;
	}

	dist[source]=0;
	q.push(source);
	inqueue[source]=true;

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
				dist[to] = max(dist[to], -INF);
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
	
