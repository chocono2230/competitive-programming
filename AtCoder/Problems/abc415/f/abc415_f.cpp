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

struct S {
  int maxlen = 0;
  int llen = 0;
  int rlen = 0;
  char lchar = 0;
  char rchar = 0;
  bool lrsame = false;
  S() {}
  S(int maxlen, int llen, int rlen, char lchar, char rchar, bool lrsame)
      : maxlen(maxlen),
        llen(llen),
        rlen(rlen),
        lchar(lchar),
        rchar(rchar),
        lrsame(lrsame) {}
  void print() {
    cerr << maxlen << " " << llen << " " << rlen << " " << lchar << " " << rchar
         << " " << lrsame << endl;
  }
};

S op(const S l, const S r) {
  if (l.maxlen == -1) return r;
  if (r.maxlen == -1) return l;
  int midlen = 0;
  if (l.rchar == r.lchar) {
    midlen = l.rlen + r.llen;
  }
  int nxmax = max({l.maxlen, r.maxlen, midlen});
  char nxlchar = l.lchar;
  char nxrchar = r.rchar;
  bool nxlrsame = (l.lrsame && r.lrsame && l.rchar == r.lchar);
  int nxllen = l.llen;
  if (l.lrsame && l.rchar == r.lchar) nxllen = midlen;
  int nxrlen = r.rlen;
  if (r.lrsame && l.rchar == r.lchar) nxrlen = midlen;
  return S(nxmax, nxllen, nxrlen, nxlchar, nxrchar, nxlrsame);
}

S e() {
  S s;
  s.maxlen = -1;
  return s;
}

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  segtree<S, op, e> seg(n);
  auto fc = [&](int i) { seg.set(i, S(1, 1, 1, s.at(i), s.at(i), true)); };
  rep(i, n) { fc(i); }
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int i;
      char x;
      cin >> i >> x;
      i--;
      s.at(i) = x;
      fc(i);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      // cerr << l << " " << r << " " << endl;
      auto s = seg.prod(l, r);
      // s.print();
      cout << s.maxlen << endl;
    }
  }
  return 0;
}