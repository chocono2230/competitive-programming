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
  int h, w, n;
  cin >> h >> w >> n;
  vector tb(h, vector(w, false));
  map<int, set<int>> uz, vz;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tb.at(a).at(b) = true;
  }

  ll ans = 0;
  const int INF = 1001001001;
  rep(i, h) rep(j, w) {
    int u = i + j;
    int v = i - j;
    if (tb.at(i).at(j)) {
      uz[u].insert(v);
      vz[v].insert(u);
      continue;
    }
    int add = min(i + 1, j + 1);
    int mh = INF;
    if (!uz[u].empty()) {
      mh = min(mh, abs(*uz[u].begin() - v));
    }
    if (!vz[v].empty()) {
      mh = min(mh, abs(*vz[v].begin() - u));
    }
    // cerr << i << " " << j << " " << add << " " << mh << endl;
    add = min(add, mh);
    ans += add;
  }

  cout << ans << endl;
  return 0;
}