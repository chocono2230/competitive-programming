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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  dsu uf(n);
  vector<int> a(n);
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
  }
  int st = -1;
  rep(i, n) {
    if (uf.same(i, a.at(i))) {
      st = i;
      break;
    }
    uf.merge(i, a.at(i));
  }
  vector<int> ans;
  int now = a.at(st);
  while (now != st) {
    ans.push_back(now);
    now = a.at(now);
  }
  ans.push_back(now);
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}