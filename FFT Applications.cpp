1) String Matching - Hamming Distance:

// Logic: http://codeforces.com/blog/entry/59386

void work(char ch1, char ch2)
{
	int n=a.size(), m=b.size();
	vector<int> poly1(n, 0), poly2(n, 0);
	for(int i=0;i<n;i++)
		poly1[i]=(a[i]==ch1);
	for(int i=0;i<m;i++)
		poly2[m-1-i]=(b[i]==ch2);
	vector<int> res;
	do_FFT(poly1, poly2, res);
	for(int i=m-1;i<=n+m-1;i++)
		ans[i]+=res[i];
}

//Problem 1: https://www.spoj.com/problems/ADAMATCH/
//Solution 1: http://p.ip.fi/2K6S

//Problem 2: https://codeforces.com/gym/101667/ : Problem H
//Solution 2: http://p.ip.fi/dzmX
