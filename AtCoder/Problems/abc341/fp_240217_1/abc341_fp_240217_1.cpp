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
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  vector<int> w(n);
  rep(i, n) cin >> w.at(i);
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> dp(n, -1);
  auto fc = [&](const auto &self, int now) -> ll {
    if (dp.at(now) != -1) return dp.at(now);
    vector sd(gr.at(now).size() + 1, vector<ll>(w.at(now), 0));
    rep(i, gr.at(now).size()) {
      int nx = gr.at(now).at(i);
      int dj = w.at(nx);
      rep(j, sd.at(i).size()) {
        sd.at(i + 1).at(j) = max(sd.at(i + 1).at(j), sd.at(i).at(j));
        if (j + dj >= w.at(now)) continue;
        int nj = j + dj;
        ll nw = sd.at(i).at(j) + self(self, nx);
        if (nw <= sd.at(i + 1).at(nj)) continue;
        sd.at(i + 1).at(nj) = nw;
      }
    }
    return dp.at(now) = sd.back().back() + 1;
  };
  ll ans = 0;
  rep(i, n) { ans += fc(fc, i) * a.at(i); }
  cout << ans << endl;
  return 0;
}