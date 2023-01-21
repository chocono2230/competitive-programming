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

pair<ll, ll> op(pair<ll, ll> l, pair<ll, ll> r) {
  if (l.first < r.first)
    return l;
  else if (l.first > r.first)
    return r;
  if (l.second > r.second) return l;
  return r;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  const ll INF = 1e18;
  vector gr(n, vector<pair<ll, ll>>(n, {INF, 0}));
  rep(i, n) rep(j, n) {
    if (s.at(i).at(j) == 'N') continue;
    gr.at(i).at(j) = {1, a.at(j)};
  }
  rep(i, n) { gr.at(i).at(i) = {0, 0}; }
  // rep(i, n) {
  //   rep(j, n) cerr << (gr.at(i).at(j).first == INF ? -1 :
  //   gr.at(i).at(j).first)
  //                  << ":" << gr.at(i).at(j).second << "  ";
  //   cerr << endl;
  // }
  // cerr << endl;
  rep(k, n) rep(i, n) rep(j, n) {
    auto p = gr.at(i).at(k);
    p.first += gr.at(k).at(j).first;
    p.second += gr.at(k).at(j).second;
    gr.at(i).at(j) = op(gr.at(i).at(j), p);
  }
  // rep(i, n) {
  //   rep(j, n) cerr << gr.at(i).at(j).first << ":" << gr.at(i).at(j).second
  //                  << "  ";
  //   cerr << endl;
  // }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    auto ans = gr.at(u).at(v);
    if (ans.first == INF) {
      cout << "Impossible" << endl;
    } else {
      cout << ans.first << " " << ans.second + a.at(u) << endl;
    }
  }
  return 0;
}