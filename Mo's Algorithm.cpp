const int N=2e5+5;
const int M=1e6+5;

struct data
{
	int l;
	int r;
	int idx;
	long long store_ans;
};

int n, q, blocksz=1000;
int a[N];
data queries[N];
long long freq[M];
long long ans=0;

bool comp(data &d1, data &d2)
{
	int blocka=d1.l/blocksz;
	int blockb=d2.l/blocksz;
	if(blocka<blockb)
		return true;
	else if(blocka==blockb)
		return (d1.r<d2.r)^(blocka%2);
	else  
		return false;
}

bool comp2(data &d1, data &d2)
{
	return d1.idx<d2.idx;
}

void update(long long k, int sign) //Sign 1 = Add, -1 = Remove
{
	if(sign==1)
	{
		ans-=freq[k]*freq[k]*k;
		freq[k]++;
		ans+=freq[k]*freq[k]*k;
	}
	else
	{
		ans-=freq[k]*freq[k]*k;
		freq[k]--;
		ans+=freq[k]*freq[k]*k;
	}
}

void calcmo()
{
	int moleft=1;
	int moright=0;
	for(int i=1;i<=q;i++)
	{
		int r=queries[i].r;
		int l=queries[i].l;
		while(moright<r)
		{
			moright++;
			update(a[moright], 1);
		}
		while(moright>r)
		{
			update(a[moright], -1);
			moright--;
		}
		while(moleft<l)
		{
			update(a[moleft], -1);
			moleft++;
		}
		while(moleft>l)
		{
			moleft--;
			update(a[moleft], 1);
		}
		queries[i].store_ans=ans;
	}
}

//Problem 1: https://codeforces.com/contest/86/problem/D
//Solution 1: https://codeforces.com/contest/86/submission/45491857

//Problem 2 (Prefix Xor): https://codeforces.com/contest/617/problem/E
//Solution 2: https://codeforces.com/contest/617/submission/45491963
