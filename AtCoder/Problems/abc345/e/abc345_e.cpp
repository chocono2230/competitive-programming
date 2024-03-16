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

const ll INF = 1e18;
ll op(ll l, ll r) { return max(l, r); };
ll e() { return -INF; }

int main() {
  int n, k;
  cin >> n >> k;
  vector<segtree<ll, op, e>> segs(k + 1, segtree<ll, op, e>(n));
  vector log(k + 1, vector<pair<int, ll>>());
  // auto pr = [&]() {
  //   rep(i, k + 1) {
  //     rep(j, n) cerr << (segs.at(i).get(j) == e() ? -1 : segs.at(i).get(j))
  //                    << " ";
  //     cerr << endl;
  //   }
  //   cerr << "-------" << endl;
  // };
  rep(idx, n) {
    ll c, v;
    cin >> c >> v;
    c--;
    vector<pair<int, ll>> memo;
    rrep(p, k) {
      int i = (idx - p + k + 1) % (k + 1);
      ll mx = op(segs.at(i).prod(0, c), segs.at(i).prod(c + 1, n));
      if (mx == e()) continue;
      mx += v;
      int ni = (idx - (p + 1) + (k + 1) * 2) % (k + 1);
      ll px = segs.at(ni).get(c);
      if (mx > px) {
        if (p == k - 1) {
          memo.push_back({c, mx});
        } else {
          segs.at(ni).set(c, mx);
          log.at(ni).push_back({c, px});
        }
      }
    }
    if (idx <= k) {
      int i = 0;
      ll mx = (segs.at(i).get(c), v);
      segs.at(i).set(c, mx);
      log.at(i).push_back({c, mx});
    }
    set<int> se;
    int ri = (idx + 1) % (k + 1);
    for (auto [i, mx] : log.at(ri)) {
      if (se.find(i) != se.end()) continue;
      se.insert(i);
      segs.at(ri).set(i, mx);
    }
    log.at(ri).clear();
    for (auto [c, mx] : memo) {
      mx = op(mx, segs.at(ri).get(c));
      segs.at(ri).set(c, mx);
      log.at(ri).push_back({c, mx});
    }
    // pr();
  }
  int ri = (n + 1) % k + 1;
  ll ans = segs.at(ri).all_prod();
  if (ans == -INF) ans = -1;
  cout << ans << endl;
  return 0;
}