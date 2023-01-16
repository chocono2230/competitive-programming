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

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

int op_alp(int a, int b) { return a + b; }
int e_alp() { return 0; }

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  segtree<int, op, e> seg(n - 1);
  vector vs(26, segtree<int, op_alp, e_alp>(n));
  map<char, int> mp;
  rep(i, n) {
    mp[s.at(i)]++;
    vs.at(s.at(i) - 'a').set(i, 1);
    if (i + 1 < n) {
      if (s.at(i) > s.at(i + 1)) seg.set(i, 1);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int pos;
      cin >> pos;
      pos--;
      char x;
      cin >> x;
      if (pos != 0) seg.set(pos - 1, 0);
      if (pos != n - 1) seg.set(pos, 0);
      vs.at(s.at(pos) - 'a').set(pos, 0);
      mp[s.at(pos)]--;
      s.at(pos) = x;
      mp[s.at(pos)]++;
      vs.at(s.at(pos) - 'a').set(pos, 1);
      if (pos != 0 && s.at(pos - 1) > s.at(pos)) seg.set(pos - 1, 1);
      if (pos != n - 1 && s.at(pos) > s.at(pos + 1)) seg.set(pos, 1);
      continue;
    }
    int l, r;
    cin >> l >> r;
    l--;
    if (seg.prod(l, r - 1) == 1) {
      cout << "No" << endl;
      continue;
    }
    bool f = false;
    char p = s.at(l), q = s.at(r - 1);
    for (char c = p + 1; c < q; c++) {
      int co = vs.at(c - 'a').prod(l, r);
      if (mp[c] > co) {
        f = true;
        break;
      }
      assert(mp[c] == co);
    }
    if (!f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}