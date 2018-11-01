1D BIT:

int bit[N];

void update(int idx, int val)
{
	while(idx<=n)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}

int rsum(int l, int r)
{
	return pref(r) - pref(l-1);
}

Multiple BIT:

int bit[2][N];

void update(int i, int idx, int k)
{
	while(idx<=n)
	{
		bit[i][idx]+=k;
		idx+=idx&-idx;
	}
}

int pref(int i, int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[i][idx];
		idx-=idx&-idx;
	}
	return ans;
}

int rsum(int i, int l, int r)
{
	return pref(i, r) - pref(i, l-1);
}

//Problem 1: https://codeforces.com/contest/1073/problem/D
//Solution 1: https://codeforces.com/contest/1073/submission/44863255
