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
  vector<int> a(n);
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
  }
  int q;
  cin >> q;
  int bsize = sqrt(q) + 1;
  vector moq((n + bsize - 1) / bsize, vector<tuple<int, int, int>>());
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--;
    int bidx = l / bsize;
    moq.at(bidx).push_back({r, l, i});
  }
  rep(i, moq.size()) {
    if (!moq.empty()) sort(ALL(moq.at(i)));
  }

  vector<int> ans(q, 0);
  for (const auto &v : moq) {
    if (v.empty()) continue;
    int l = get<1>(v.front()), r = get<1>(v.front());
    int now = 0;
    vector<int> tb(n, 0);
    auto fadd = [&](int x) -> void {
      tb.at(x)++;
      if (tb.at(x) % 2 == 0) now++;
    };
    auto fsub = [&](int x) -> void {
      if (tb.at(x) % 2 == 0) now--;
      tb.at(x)--;
    };
    for (auto [qr, ql, qi] : v) {
      while (r < qr) {
        r++;
        fadd(a.at(r - 1));
      }
      assert(r == qr);
      while (ql < l) {
        l--;
        fadd(a.at(l));
      }
      while (l < ql) {
        fsub(a.at(l));
        l++;
      }
      ans.at(qi) = now;
    }
  }
  for (auto now : ans) cout << now << endl;

  return 0;
}