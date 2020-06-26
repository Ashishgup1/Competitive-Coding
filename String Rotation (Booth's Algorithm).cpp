//Returns the lexicographically least rotation of string

string least_rotation(string s)
{
	s += s;
	vector<int> f(s.size(), -1);
	int k = 0;
	for(int j = 1; j < s.size(); j++)
	{
		char sj = s[j];
		int i = f[j - k - 1];
		while(i != -1 && sj != s[k + i + 1])
		{
			if(sj < s[k + i + 1])
				k = j - i - 1;
			i = f[i];
		}
		if(sj != s[k + i + 1])
		{
			if(sj < s[k])
				k = j;
			f[j - k] = -1;
		}
		else
			f[j - k] = i + 1;
	}
	return s.substr(k, s.size() / 2);
}

//Problem 1: https://www.codechef.com/BIT32020/problems/BIT3B
