//For Decimals

int sz = 0;
int x[20];
int cache[20][2][5];

int dp(int idx, bool less, int taken)
{
	if(taken > 3)
		return 0;
	if(idx == sz)
		return 1;
	int &ans = cache[idx][less][taken];
	if(ans != -1)
		return ans;
	ans = 0;
	int lo = 0, hi = 9;
	if(!less)
		hi = x[idx];
	for(int i = lo; i <= hi; i++)
		ans += dp(idx + 1, less | (i < x[idx]), taken + (i > 0));
	return ans;
}

int f(int k)
{
	memset(cache, -1, sizeof(cache));
	sz = 0;
	while(k > 0)
	{
		x[sz++] = k % 10;
		k /= 10;
	}
	reverse(x, x + sz);
	int ans = dp(0, 0, 0);
	return ans;
}

//Problem 1: https://codeforces.com/contest/1036/problem/C

