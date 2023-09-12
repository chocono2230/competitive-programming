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
  int h, w, n;
  cin >> h >> w >> n;
  vector<tuple<int, int, int, int>> abcd(n);
  rep(i, n) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    abcd.at(i) = {a, b, c, d};
  }
  auto fc = [=](int mode, int idx) {
    if (mode == 0) return idx;
    if (mode == 1) return idx + 2;
    if (mode == 2) return idx + 2 + h;
    if (mode == 3) return idx + 2 + h + w;
    if (mode == 4) return idx + 2 + h + w + n;
    return -1;
  };
  mf_graph<int> gr(2 + h + w + n + n);
  rep(i, h) { gr.add_edge(fc(0, 0), fc(1, i), 1); }
  rep(i, w) { gr.add_edge(fc(2, i), fc(0, 1), 1); }
  rep(i, n) { gr.add_edge(fc(3, i), fc(4, i), 1); }
  rep(idx, n) {
    auto [a, b, c, d] = abcd.at(idx);
    rep2(i, a, c) { gr.add_edge(fc(1, i), fc(3, idx), 1); }
    rep2(i, b, d) { gr.add_edge(fc(4, idx), fc(2, i), 1); }
  }
  int r = gr.flow(fc(0, 0), fc(0, 1));
  cout << r << endl;
  return 0;
}