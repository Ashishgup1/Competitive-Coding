// In STL there are lots of inbuild algorithm like max element , min element etc .

#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     cin >> n;
     vector<int> v(n);
     for (int i = 0; i < n; i++)
     {
          cin >> v[i];
     }
     // Min or max_element algos always retruen adress.
     auto p = min_element(v.begin(), v.end()); // min_element takse 2 argument , starting and end.
     cout << *(p) << endl;
     int p1 = *max_element(v.begin(), v.end());
     cout << p1 << endl;

     // accumulate algo gives us sum of array or vector.
     int init_sum = 0;
     int sum = accumulate(v.begin(), v.end(), init_sum); // its take 3 argus , start , end , initial sum which we need to provide.
     cout << sum << endl;

     // Count function return number of count in vector/array.
     int ct = count(v.begin(), v.end(), 4); // its take 3 argus , start , end , and that element which count is required.
     cout << ct << endl;

     // Find Function used to find an element and its return pointer or iterator.
     auto it = find(v.begin(), v.end(), 10); // its take 3 argus , start , end and that value which is to be find.
     if (it != v.end())
     {
          cout << *it;
     }
     else
     {
          cout << "Element not Found" << endl;
     }

     // Reverse function used to reverse an string , array or vector.
     for (auto t : v)
     {
          cout << t << " ";
     }
     cout << endl;
     reverse(v.begin(), v.end()); // Reverse function take two argus , start and end. And it reverse that vector.
     for (auto t : v)
     {
          cout << t << " ";
     }
     cout << endl;

     //  In String Case.
     string s = "abcdefghi";
     cout<<s.size()<<endl;
     for (auto t : s)
     {
          cout << t << " ";
     }
     cout << endl;
     reverse(s.begin(), s.end());     // It will Also reverse the string
     for (auto t : s)
     {
          cout << t << " ";
     }
     cout << endl;

     return 0;

}
