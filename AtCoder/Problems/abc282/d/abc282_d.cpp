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

bool dfs(vector<vector<int>> &gr, vector<int> &chk, vector<int> &co, int &es,
         int now) {
  bool res = false;
  es += gr.at(now).size();
  for (auto nx : gr.at(now)) {
    if (chk.at(nx) == -1) {
      chk.at(nx) = 1 - chk.at(now);
      co.at(1 - chk.at(now))++;
      res |= dfs(gr, chk, co, es, nx);
      if (res) break;
    } else {
      if (chk.at(nx) == chk.at(now)) {
        res = true;
        break;
      }
    }
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  vector<int> chk(n, -1);
  ll ss = 0;
  ll ans = 0;
  rep(i, n) {
    if (chk.at(i) != -1) continue;
    vector<int> co(2, 0);
    co.front() = 1;
    chk.at(i) = 0;
    int es = 0;
    auto r = dfs(gr, chk, co, es, i);
    if (r) {
      cout << 0 << endl;
      return 0;
    }
    // cerr << co.front() << " " << co.back() << endl;
    ans += (ll)co.front() * co.back();
    ans -= es / 2;
    ans += (ll)(co.front() + co.back()) * ss;
    ss += (co.front() + co.back());
  }
  cout << ans << endl;
  return 0;
}