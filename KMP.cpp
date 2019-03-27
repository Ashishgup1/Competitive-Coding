String:

vector<int> prefix_function(string &s) 
{
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> find_occurences(string &text, string &pattern)
{
	string cur=pattern + '#' + text;
	int sz1=text.size(), sz2=pattern.size();
	vector<int> v;
	vector<int> lps=prefix_function(cur);
	for(int i=sz2+1;i<=sz1+sz2;i++)
	{
		if(lps[i]==sz2)
			v.push_back(i-2*sz2);
	}
	return v;
}

Vector:

vector<int> prefix_function(vector<int> &v) 
{
	int n = (int)v.size();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i-1];
		while (j > 0 && v[i] != v[j])
			j = pi[j-1];
		if (v[i] == v[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> find_occurences(vector<int> &text, vector<int> &pattern)
{
	vector<int> v=pattern;
	v.push_back(-1);
	for(auto &it:text)
		v.push_back(it);
	int sz1=text.size(), sz2=pattern.size();
	vector<int> lps=prefix_function(v);
	vector<int> store;
	for(int i=sz2+1;i<=sz1+sz2;i++)
	{
		if(lps[i]==sz2)
			store.push_back(i-sz*2);
	}
	return v;
}


//Problem 1 (Basic KMP): https://codeforces.com/contest/1016/problem/B
//Solution 1: https://codeforces.com/contest/1016/submission/41167402

//Problem 2 and Solution (Cyclic Matching - Vectors): http://codeforces.com/gym/100502/submission/41562571

//Problem 3 (Ranking Pattern): https://qr.ae/TUG5h9 
//Solution 3: http://p.ip.fi/Hwpy
