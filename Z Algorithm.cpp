// Logic = https://cp-algorithms.com/string/z-function.html

// The Z-function for this string is an array of length n where the i-th element
// is equal to the greatest number of characters starting from the position i
// that coincide with the first characters of s.

vector<int> z_function(string &s) {
    int n = s.size();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }

    return z;
}

// Sample Problem 1: http://codeforces.com/problemset/problem/127/D
// Sample Solution 1: http://codeforces.com/contest/127/submission/39791421

// Sample Problem 2: http://codeforces.com/contest/432/problem/D
// Sample Solution 2: http://codeforces.com/contest/432/submission/39791526
