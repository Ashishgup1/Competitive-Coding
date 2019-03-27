#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=2e5+5;

#define T pair<int, int>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

int getless(ordered_set &os, int R, int index)
{
	return os.order_of_key({R, index});
}

ordered_set os1;

//Problem 1 (PBDS with int): https://codeforces.com/contest/1042/problem/D
//Solution 1: https://codeforces.com/contest/1042/submission/42975984

//Problem 2 (PBDS with rational): https://csacademy.com/contest/round-75/task/race-cars/
//Solution 2: http://p.ip.fi/cYCx
