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

//Problem 1: http://codeforces.com/contest/706/problem/D
//Solution 1: http://codeforces.com/contest/706/submission/39515647 (Maxxor)

//Problem 2: http://codeforces.com/problemset/problem/948/D
//Solution 2: http://codeforces.com/contest/948/submission/39663985 (Minxor)

//Problem 3: http://codeforces.com/contest/665/problem/E
//Solution 3: http://codeforces.com/contest/665/submission/39664021 (Subarray Count with Xor >= K)

//Problem 4: http://codeforces.com/contest/282/problem/E
//Solution 4: http://codeforces.com/contest/282/submission/39664030 (Maxxor)

//Problem 5: https://codeforces.com/contest/842/problem/D
//Solution 5: https://codeforces.com/contest/842/submission/50659739 (Recursive Insert + Mex)
