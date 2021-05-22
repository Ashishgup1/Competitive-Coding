typedef struct trie
{
	typedef struct node
	{
		node* nxt[2];
		int cnt = 0;

		node()
		{
			nxt[0] = nxt[1] = NULL;
			cnt = 0;
		}

	}Node;

	Node* head;

	trie() { head = new Node(); }

	void insert(int x)
	{
		Node* cur = head;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			if(!cur -> nxt[b])
				cur -> nxt[b] = new Node();
			cur = cur -> nxt[b];
			cur -> cnt++;
		}
	}

	void remove(int x)
	{
		Node* cur = head;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			cur = cur -> nxt[b];
			cur -> cnt--;
		}
	}

	int maxxor(int x)
	{
		Node* cur = head;
		int ans = 0;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			if(cur -> nxt[!b] && cur -> nxt[!b] -> cnt > 0)
			{
				ans += (1LL << i);
				cur = cur -> nxt[!b];
			}
			else
				cur = cur -> nxt[b];
		}
		return ans;
	}
}Trie;

//Problem 1: http://codeforces.com/contest/706/problem/D
//Solution 1: http://codeforces.com/contest/706/submission/39515647 (Maxxor)
//Solution 1: https://codeforces.com/contest/706/submission/85771777 (Full Struct)

//Problem 2: http://codeforces.com/problemset/problem/948/D
//Solution 2: http://codeforces.com/contest/948/submission/39663985 (Minxor)

//Problem 3: http://codeforces.com/contest/665/problem/E
//Solution 3: http://codeforces.com/contest/665/submission/39664021 (Subarray Count with Xor >= K)

//Problem 4: http://codeforces.com/contest/282/problem/E
//Solution 4: http://codeforces.com/contest/282/submission/39664030 (Maxxor)

//Problem 5: https://codeforces.com/contest/842/problem/D
//Solution 5: https://codeforces.com/contest/842/submission/50659739 (Recursive Insert + Mex)

//Problem 6: https://www.codechef.com/problems/GPD
//Solution 6: http://p.ip.fi/rz9f (Persistent Trie + Recursive Insert, MinXor, MaxXor)

//Problem 7: https://www.codechef.com/problems/XRQRS
//Solution 7: http://p.ip.fi/i8dl (Persistent Trie + Recursive Insert, MinXor, MaxXor, Kth Largest in interval, <=X in interval)
