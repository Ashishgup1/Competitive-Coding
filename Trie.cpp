typedef struct data
{
	data* bit[2];
	int cnt=0;
}trie;

trie* head;

void insert(int x)
{
	trie* node = head;
	for(int i=30;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		if(node->bit[curbit]==NULL)
			node->bit[curbit]=new trie();
		node=node->bit[curbit];
		node->cnt++;
	}
}

void remove(int x)
{
	trie* node = head;
	for(int i=30;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		node=node->bit[curbit];
		node->cnt--;
	}
}

int maxxor(int x)
{
	trie* node = head;
	int ans=0;
	for(int i=30;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		if(node->bit[curbit^1]!=NULL && node->bit[curbit^1]->cnt>0)
		{
			ans+=(1LL<<i);
			node=node->bit[curbit^1];
		}
		else
			node=node->bit[curbit];
	}
	return ans;
}

//Sample Problem 1: http://codeforces.com/contest/706/problem/D
//Sample Solution 1: http://codeforces.com/contest/706/submission/39515647 (Maxxor)

//Sample Problem 2: http://codeforces.com/problemset/problem/948/D
//Sample Solution 2: http://codeforces.com/contest/948/submission/39663985 (Minxor)

//Sample Problem 3: http://codeforces.com/contest/665/problem/E
//Sample Solution 3: http://codeforces.com/contest/665/submission/39664021 (Subarray Count)

//Sample Problem 4: http://codeforces.com/contest/282/problem/E
//Sample Solution 4: http://codeforces.com/contest/282/submission/39664030 (Maxxor)
