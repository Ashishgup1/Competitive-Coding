Without Struct:

int connected;
int root[N], sz[N];

void init()
{
	for(int i=1;i<=n;i++)
	{
		root[i]=i;
		sz[i]=1;
	}
	connected=n;
}

int rt(int k)
{
	while(k!=root[k])
	{
		root[k]=root[root[k]];
		k=root[k];
	}
	return k;
}

void merge(int u, int v)
{
	int rt1=rt(u);
	int rt2=rt(v);

	if(rt1==rt2)
		return;

	connected--;

	if(sz[rt1]>sz[rt2])
		swap(rt1, rt2);

	sz[rt2]+=sz[rt1];
	sz[rt1]=0;
	root[rt1]=root[rt2];
}
 
Struct Implementation:

typedef struct data
{
	int connected;
	int root[N], sz[N];

	void init()
	{
		for(int i=1;i<=n;i++)
		{
			root[i]=i;
			sz[i]=1;
		}
		connected=n;
	}

	int rt(int k)
	{
		while(k!=root[k])
		{
			root[k]=root[root[k]];
			k=root[k];
		}
		return k;
	}

	void merge(int u, int v)
	{
		int rt1=rt(u);
		int rt2=rt(v);

		if(rt1==rt2)
			return;

		connected--;

		if(sz[rt1]>sz[rt2])
			swap(rt1, rt2);

		sz[rt2]+=sz[rt1];
		sz[rt1]=0;
		root[rt1]=root[rt2];
	}
}DSU;
