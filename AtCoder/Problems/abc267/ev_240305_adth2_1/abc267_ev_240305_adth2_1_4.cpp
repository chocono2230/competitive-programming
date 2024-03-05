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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  set<pair<ll, int>> se;
  vector<ll> co(n, 0);
  rep(i, n) {
    ll add = 0;
    for (auto now : gr.at(i)) {
      add += a.at(now);
    }
    se.insert({add, i});
    co.at(i) = add;
  }
  ll ans = 0;
  rep(i, n) {
    auto itr = se.begin();
    ans = max(ans, itr->first);
    int now = itr->second;
    se.erase(itr);
    co.at(now) = -1;
    for (auto nx : gr.at(now)) {
      if (co.at(nx) == -1) continue;
      pair<ll, int> p(co.at(nx), nx);
      se.erase(p);
      co.at(nx) -= a.at(now);
      p.first -= a.at(now);
      se.insert(p);
    }
  }
  cout << ans << endl;
  return 0;
}