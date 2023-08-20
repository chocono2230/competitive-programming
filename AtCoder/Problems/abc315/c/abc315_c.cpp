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

int main() {
  int n;
  cin >> n;
  map<int, vector<int>> mp;
  rep(i, n) {
    int f, s;
    cin >> f >> s;
    mp[f].push_back(s);
  }
  vector<int> mxs;
  int ans = 0;
  for (auto &[idx, v] : mp) {
    sort(ALL(v));
    mxs.push_back(v.back());
    if (v.size() <= 1) continue;
    ans = max(ans, v.back() + (v.at(v.size() - 2) / 2));
  }
  if (mxs.size() >= 2) {
    sort(ALL(mxs));
    ans = max(ans, mxs.back() + mxs.at(mxs.size() - 2));
  }
  cout << ans << endl;
  return 0;
}