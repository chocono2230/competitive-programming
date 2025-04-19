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
  vector a(m, vector<int>(0));
  rep(i, m) {
    int sz;
    cin >> sz;
    rep(j, sz) {
      int in;
      cin >> in;
      in--;
      a.at(i).push_back(in);
    }
  }
  vector<int> tn(n);
  rep(i, n) {
    int in;
    cin >> in;
    tn.at(in - 1) = i;
  }
  vector<int> add(n, 0);
  rep(i, m) {
    int mx = 0;
    for (auto now : a.at(i)) {
      mx = max(mx, tn.at(now));
    }
    add.at(mx)++;
  }
  int ans = 0;
  rep(i, n) {
    ans += add.at(i);
    cout << ans << endl;
  }
  return 0;
}