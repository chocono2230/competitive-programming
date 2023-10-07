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
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a.at(i);
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  rep(i, n) {
    int now = i + 1;
    vector<int> v;
    rep(j, m) {
      if (s.at(i).at(j) == 'o')
        now += a.at(j);
      else
        v.push_back(a.at(j));
    }
    sort(ALL(v), greater<int>());
    int mx = 0;
    rep(k, n) {
      if (k == i) continue;
      int add = k + 1;
      rep(j, m) {
        if (s.at(k).at(j) == 'o') add += a.at(j);
      }
      mx = max(mx, add);
    }
    int idx = 0;
    while (now < mx) {
      now += v.at(idx++);
    }
    cout << idx << endl;
  }
  return 0;
}