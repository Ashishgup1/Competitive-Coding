/*
Given array a of N integers , Given Q queries and in each query given L and r.
Print sum of array  element from index L to R ( L , R included).

Constraints.
1 <= N <= 10^5
1 <= a[i] <= 10^9
1 <= Q <= 10^5
1 <= L , R <= N


*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
int prefix_sum[N]; // array for

int main()
{
     //     int n;
     //     cin>>n;
     //      for (int i = 1; i <=n; i++)
     //      {
     //           cin >> arr[i];
     //      }
     //      int q;
     //      cin>>q;
     //      while (q--)
     //      {
     //           int l, r;
     //            cin >> l >> r;
     //           long long sum = 0;

     //           for (int i = l; i <= r; i++) // Worst case time complexity o(N) + o(Q) = o(N^2)
     //           {
     //                sum = sum + arr[i];
     //           }
     //           cout << sum << endl;
     //      }
     // time complexity is o(N^2) and code will also not run for 10^5 input/ second. so we will sum before computation.
     // In pre_computation prefix sum technique we use to store the sum of first i element.
     // suppose we are at index 3 then we will also have store the sum of index 1 , 2 and 3 .
     int n;
     cin >> n;

     for (int i = 1; i <= n; i++)
     {
          cin >> arr[i];

          prefix_sum[i] = prefix_sum[ i - 1] + arr[i];
     }
     int q;
     cin >> q;
     while (q--)
     {
          int l, r;
          cin >> l >> r;
          cout << prefix_sum[r] - prefix_sum[l-1] << endl;
     }
     // Now the time complexity is o(N). 
     // Here we use a array in which we store sum of ith element . and for finding sum l to r we just minus r - l-1.
     return 0;
}