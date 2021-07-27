// Precomputation technique used for reduce time complexit.
// In this we calculate result for every possible input brfore test cases and store then.
// then simpley pass thoses value which wil be call in Test Cases.

/* 
Q- Given T test cases in each case
tese case a number N . Print its factorial for each test cases % M , where M = 10^9+7.

constraints.
1<= T <= 10^5
1 <= N <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

const long long int N = 1e5 + 10; // For pre-computation.
long long int fact[N];

int main()
{
     // int t;
     // cin >> t;
     // while (t--)
     // {
     //      int n;
     //      cin >> n;
         
     //      long long int fact = 1;
     //      for (int i = 2; i <= n; i++)
     //      {
     //           fact = (fact * i) % M ;
     //      }
     //      cout << fact << endl;
     // }
     // Time complexity of above code is o(T*N) , T and N are equal (10^5) , so complexity is o(N^2).
     // The problem of this code is it will not run for big digit . total time taken is 10^10,
     // this will not run in  per second . on online coading we have to complie input max 10^7 input  per second.
     //
     //  there for we will calculate value for each input 1 to 10^5 in array of size [10^5] and store them earlier the program begain.

     fact[0] = fact[1] = 1;
     for (int i = 2; i <= N; i++)
     {
          fact[i] = fact[i-1] * i;      
     }
     int t;
     cin >> t;
     while (t--)
     {
          int n;
          cin >> n;       
          cout << fact[n] % M<< endl;
     }
     // Old time complwsity = o(N^2);
     // This time complexity =  for storing every factorial o(N) + for every testcases o(T) = o(N).

     return 0;
}