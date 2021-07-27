/*
Given an array of size N integer , Give Q querues and in each query given a number x .
print count of that number in arraay.

consrains :
1 <= N <= 10^5
1 <= a[i] <= 10^7
1 <= Q <= 10^5

*/

#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e7+ 10;
int  has_arr[N];

int main()
{
     /*
     int n;
     cin >> n;
     int arr[n];
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     int q;
     cin >> q;
     while (q--)
     {
          int x, count = 0;
          cin >> x;
          for (int i = 0; i < n; i++)
          {
               if (arr[i] == x)
               {
                    count++;
               }
          }
          cout << count << endl;
     }
     */
     // Time complexity.
     // o(N) + o(Q*N)  = o(N) cause Q and N are equal . so it will take time for input 10^10 . 
     // it won't work for 1 sec , only 10^7 can execute on online plateforms.
     // To reduce this we will use precompution , Hasing a form of pre-compution.


     int n;
     cin >> n;
     int arr[n];
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
          has_arr[arr[i]]++;   // For hasing . we are already counting value of count. at which index value is present
     }
     int q;
     cin >> q;
     while (q--)
     {
          int x;
          cin >> x;
          cout<<has_arr[x]<<endl;
     }
     // Time complexity = o(N) + o(Q) = 2* o(N) = 2 * 10^5 

     return 0;
}