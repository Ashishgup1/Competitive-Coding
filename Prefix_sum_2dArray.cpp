/*

Given an array of N*N integers. given Q queries and in each queary given a , b , c and d 
print sum of square represented by (a ,b) as top left point and  (c ,d) as  bottom right point.

Constraints.
1 <= N <= 10^3
1 <= a[i][j] <= 10^9
1 <= Q <= 10^5
1 <= a ,b ,c <= N

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 10 ^ 3 + 10;
long long int arr[N][N];
long long int pre_arr[N][N];

int main()
{
     //      int n;
     //      cin >> n;
     //      for (int i = 1; i <= n; i++)
     //      {
     //           for (int j = 1; j <= n; j++)
     //           {
     //                cin >> arr[i][j];
     //           }
     //      }
     //      int q;
     //      cin >> q;
     //      while (q--)
     //      {
     //           int a, b, c, d;
     //           cin >> a >> b >> c >> d;
     //           long long int sum = 0;
     //           for (int i = a; i <= c; i++)
     //           {
     //                for (int j = b; j <= d; j++)
     //                {
     //                     sum = sum + arr[i][j];
     //                }
     //           }
     //           cout << sum << endl;
     //      }
     /// Time complexity is o(N^2) + o(Q*N^2) = 10^5 * 10^6  = 10^11 , not possible for 1 sec/ input.

     int n;
     cin >> n;
     for (int i = 1; i <= n; i++)
     {
          for (int j = 1; j <= n; j++)
          {
               cin >> arr[i][j];
               pre_arr[i][j] = arr[i][j] + pre_arr[i - 1][j] + pre_arr[i][j - 1] - pre_arr[i - 1][j - 1];
          }
     }

     int q;
     cin >> q;
     while (q--)
     {
          int a, b, c, d;
          cin >> a >> b >> c >> d;
          long long int sum = 0;

          cout << pre_arr[c][d] - pre_arr[a - 1][d] - pre_arr[c][b - 1] + pre_arr[a - 1][b - 1] << endl;
     }
      // Time complexity is o(N) + o(Q) = o(N).
     return 0;
}