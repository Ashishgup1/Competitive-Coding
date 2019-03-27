const int N = 2e5 + 5;
const int Q = 2e5 + 5;
const int M = 1e6 + 5;
const int SZ = sqrt(N) + 1;

struct data
{
	int l, r, idx;
}qr[Q];

int n, q, a[N];
int freq[M];
long long ans[Q];
long long cur = 0;

bool comp(struct data &d1, struct data &d2)
{
	int b1 = d1.l / SZ;
	int b2 = d2.l / SZ;
	if(b1 != b2)
		return b1 < b2;
	else
		return (b1 & 1) ? d1.r < d2.r : d1.r > d2.r;
}

inline void add(int x)
{	
	cur -= 1LL * freq[x] * freq[x] * x;
	freq[x]++;
	cur += 1LL * freq[x] * freq[x] * x;
}

inline void remove(int x)
{
	cur -= 1LL * freq[x] * freq[x] * x;
	freq[x]--;
	cur += 1LL * freq[x] * freq[x] * x;
}

void mo()
{
	sort(qr + 1, qr + q + 1, comp);
	int l = 1, r = 0;
	cur = 0;
	for(int i=1;i<=q;i++)
	{
		while(l < qr[i].l) remove(a[l++]);
		while(l > qr[i].l) add(a[--l]);
		while(r < qr[i].r) add(a[++r]);
		while(r > qr[i].r) remove(a[r--]);
		ans[qr[i].idx] = cur;
	}
}


//Problem 1: https://codeforces.com/contest/86/problem/D
//Solution 1: https://codeforces.com/contest/86/submission/50507192

//Problem 2 (Prefix Xor): https://codeforces.com/contest/617/problem/E
//Solution 2: https://codeforces.com/contest/617/submission/45491963

//Problem 3 (Inversions in a Range): https://www.codechef.com/CCOQ2019/problems/DRAGONS/
//Solution 3: https://www.codechef.com/viewsolution/23234139
