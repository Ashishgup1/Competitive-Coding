//O(1) query sparse matrix for Max/Min/GCD

int RMQ[20][N];

void precompute()
{
	for(int i=0;(1<<i)<N;i++)
	{
		for(int j=(1<<i);j<N && j<(1<<(i+1)); j++)
			floorlog[j]=i;
	}

	for(int i=n;i>=1;i--)
	{
		RMQ[0][i]=dp[i]; 
		int mxj=floorlog[n-i+1]; //2^j <= n-i+1
		int pw=1;
		for(int j=1;j<=mxj;j++)
		{
			RMQ[j][i]=max(RMQ[j-1][i], RMQ[j-1][i+pw]);
			pw<<=1;
		}
	}	
}

int getMax(int L, int R)
{
	int k=floorlog[R-L+1]; //2^k <= R-L+1
	return max(RMQ[k][L], RMQ[k][R - (1<<k) +1]);
}

//Sample Problem 1: http://codeforces.com/contest/373/problem/E
//Sample Solution 1: http://codeforces.com/contest/373/submission/39948771
