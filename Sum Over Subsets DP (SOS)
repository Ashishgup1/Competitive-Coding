//Logic: https://codeforces.com/blog/entry/45223

//Code below for following question: https://codeforces.com/contest/165/problem/E
const int N = (1 << 22) + 5;
 
int n;
int a[N], f[N], g[N];
 
int32_t main()
{
	IOS;
	memset(g, -1, sizeof(g));
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
		g[a[i]] = a[i];
	}
	for(int i = 0; i < 22; i++)	
	{
		for(int mask = 0; mask < (1 << 22); mask++)
		{
			if(mask >> i & 1)
			{
				f[mask] += f[mask ^ (1 << i)];
				g[mask] = max(g[mask], g[mask ^ (1 << i)]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		cout << g[((1 << 22) - 1) ^ a[i]] << " ";
	cout << endl;
	return 0;
}

//Question 1: https://codeforces.com/contest/383/problem/E
//Solution 1 (Inclusion Exclusion): https://codeforces.com/contest/383/submission/64540469

//Question 2: https://www.hackerrank.com/contests/w16/challenges/vim-war/problem
//Solution 2 (Number of subsets with bitwise OR = X): https://www.hackerrank.com/contests/w16/challenges/vim-war/submissions/code/1317547443

//Question 3: https://codeforces.com/contest/449/problem/D
//Solution 3 (Conversion of AND to OR - Demorgan's Law): https://codeforces.com/contest/449/submission/64594753

//Question 4: https://codeforces.com/problemset/problem/1105/E
//Solution 4: https://codeforces.com/contest/1105/submission/68110558

//Question 5: https://csacademy.com/contest/round-53/task/maxor/statement/
//Solution 5: https://p.ip.fi/UWaF

//Question 6: http://codechef.com/problems/COVERING
//Solution 6: (Iterating over submasks first, then bits) https://www.codechef.com/viewsolution/35740758 
