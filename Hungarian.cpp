//Ref - https://codeforces.com/contest/1107/submission/49215548

lli hungarian(vector<vector<lli>> cost) // cost is 1-based
{
  lli n = (lli)cost.size() - 1;
  lli m = (lli)cost[0].size() - 1;
  vector<lli> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
  for (lli i = 1; i <= n; ++i) {
    p[0] = i;
    lli j0 = 0;
    vector<lli> minv(m + 1, INF);
    vector<char> used(m + 1, false);
    do {
      used[j0] = true;
      lli i0 = p[j0], delta = INF, j1;
      for (lli j = 1; j <= m; ++j)
        if (!used[j]) {
          lli cur = cost[i0][j] - u[i0] - v[j];
          if (cur < minv[j])
            minv[j] = cur, way[j] = j0;
          if (minv[j] < delta)
            delta = minv[j], j1 = j;
        }
      for (lli j = 0; j <= m; ++j)
        if (used[j])
          u[p[j]] += delta, v[j] -= delta;
        else
          minv[j] -= delta;
      j0 = j1;
    } while (p[j0] != 0);
    do {
      lli j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while (j0);
  }
  vector<lli> assignment(n + 1);
  for (lli j = 1; j <= m; ++j)
    assignment[p[j]] = j;
  lli ret = 0;
  for (lli i = 1; i <= n; ++i)
  {
    assert(assignment[i]);
    ret += cost[i][assignment[i]];
  }

  return ret;
}