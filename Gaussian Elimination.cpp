struct Gauss 
{
	static const int bits = 20;

	int table[bits];

	Gauss() 
	{
		for(int i = 0; i < bits; i++) 
			table[i] = 0;
	}

	int size() 
	{
		int ans = 0;
		for(int i = 0; i < bits; i++) 
		{
			if(table[i]) 
				ans++;
		}
		return ans;
	}

	bool can(int x) 
	{
		for(int i = bits-1; i >= 0; i--) 
			x = min(x, x ^ table[i]);
		return x == 0;
	}

	void add(int x) 
	{
		for(int i = bits-1; i >= 0 && x; i--) 
		{
			if(table[i] == 0) 
			{
				table[i] = x;
				x = 0;
			} 
			else 
				x = min(x, x ^ table[i]);
		}
	}

	int getBest() 
	{
		int x = 0;
		for(int i = bits-1; i >= 0; i--) 
			x = max(x, x ^ table[i]);
		return x;
	}

	void merge(Gauss &other)
	{
		for(int i = bits-1; i >= 0; i--)
			add(other.table[i]);
	}
};

//Logic: https://math.stackexchange.com/questions/48682/maximization-with-xor-operator
//Source: https://codeforces.com/profile/tfg

//Problem 1: http://codeforces.com/contest/959/problem/F
//Solution 1: https://codeforces.com/contest/959/submission/50314871

//Problem 2: https://codeforces.com/contest/1101/problem/G
//Solution 2: https://codeforces.com/contest/1101/submission/50315103

