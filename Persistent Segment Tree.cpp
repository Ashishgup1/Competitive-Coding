int n, m, ct=0, num=0;
int root[N], st[21*N], lc[21*N], rc[21*N];

int build(int L, int R)
{
	int node = ++ct;
	if(L==R)
		return node;
	int M = (L+R)/2;
	lc[node] = build(L, M);
	rc[node] = build(M+1, R);
	return node;
}

int update(int onode, int L, int R, int pos)
{
	int node = ++ct;
	if(L==R)
	{
		st[node] = st[onode] + 1;
		return node;
	}
	int M = (L+R)/2;
	lc[node] = lc[onode];
	rc[node] = rc[onode];
	if(pos <= M)
		lc[node] = update(lc[onode], L, M, pos);
	else
		rc[node] = update(rc[onode], M+1, R, pos);
	st[node] = st[lc[node]] + st[rc[node]];
	return node;
}

int query(int nodeu, int nodev, int L, int R, int pos)
{
	if(L==R)
		return L;
	int M = (L+R)/2;
	int leftval = st[lc[nodev]] - st[lc[nodeu]];
	int rightval = st[rc[nodev]] - st[rc[nodeu]];
	if(leftval>=pos)
		return query(lc[nodeu], lc[nodev], L, M, pos);
	else
		return query(rc[nodeu], rc[nodev], M+1, R, pos - leftval);
}

void persistentSegTree()
{
	root[0] = build(1, num);
	for(int i=1;i<=n;i++)
		root[i] = update(root[i-1], 1, num, a[i]);
}

//Problem 1 (kth minimum weight on the path from node u to node v): https://www.spoj.com/problems/COT/
//Solution 1: http://p.ip.fi/KLiG

//Problem 2 (Kth element in sorted range [i, j]): https://www.spoj.com/problems/MKTHNUM/
//Solution 2: http://p.ip.fi/B00r

//Problem 3 (Take atmost K values of a particular value in a range): https://codeforces.com/contest/813/problem/E
//Solution 3: https://codeforces.com/contest/813/submission/50422337

//Problem 4: https://www.codechef.com/ICMT2019/problems/ICM05
//Solution 4: http://p.ip.fi/bo0f
