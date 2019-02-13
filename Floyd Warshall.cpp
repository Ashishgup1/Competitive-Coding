int dist[N][N];

void FloydWarshall()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
}

//Problem 1: https://codeforces.com/contest/189/problem/D
//Solution 1: https://codeforces.com/contest/189/submission/48938763
