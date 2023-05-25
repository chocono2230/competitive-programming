#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int dfs(vector<int> &arr, int lv, int now) {
  int res = (1 << 30);
  if (arr.empty()) return res;
  if (arr.size() == 1) {
    return now;
  }
  if (lv == -1) {
    return now;
  }
  vector<int> v0, v1;
  rep(i, arr.size()) {
    if ((arr.at(i) & (1 << lv)) == 0)
      v0.push_back(arr.at(i));
    else
      v1.push_back(arr.at(i));
  }
  if (v0.empty()) return dfs(v1, lv - 1, now);
  if (v1.empty()) return dfs(v0, lv - 1, now);
  res = min(res, dfs(v0, lv - 1, now | (1 << lv)));
  res = min(res, dfs(v1, lv - 1, now | (1 << lv)));
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  set<int> se;
  rep(i, n) se.insert(a.at(i));
  a.clear();
  for (auto now : se) a.push_back(now);
  cout << dfs(a, 29, 0) << endl;
  return 0;
}