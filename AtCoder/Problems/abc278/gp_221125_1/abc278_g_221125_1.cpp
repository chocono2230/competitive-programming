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

int rc(int n, int d) {
  static vector<int> memo(2005, -1);
  if (memo.at(n) != -1) return memo.at(n);
  if (d > n) return 0;
  vector<bool> chk(2005, false);
  rep(i, n - d + 1) {
    int l = i, r = n - (d + i);
    int p = rc(l, d) ^ rc(r, d);
    chk.at(p) = true;
  }
  int res = 0;
  rep(i, chk.size()) {
    if (!chk.at(i)) break;
    res++;
  }
  return memo.at(n) = res;
}

pair<int, int> inout(int x, int y) {
  x++;
  cout << x << " " << y << endl;
  int a, b;
  cin >> a >> b;
  a--;
  return {a, b};
}

void solve(int n, int d) {
  int r = rc(n, d);
  vector<bool> arr(n, false);
  auto upd = [&](int s) {
    rep2(i, s, s + d) {
      if (arr.at(i)) exit(1);
      arr.at(i) = true;
    }
  };
  if (r == 0) {
    cout << "Second" << endl;
    int fa, fb;
    cin >> fa >> fb;
    fa--;
    if (fa == -1 && fb == 0) return;
    if (fa == -2 && fb == -1) return;
    upd(fa);
  } else {
    cout << "First" << endl;
  }
  while (1) {
    int st = -1;
    rep(i, n) {
      if (!arr.at(i)) {
        st = i;
        break;
      }
    }
    assert(st != -1);
    int add = 0, xs = 0;
    vector<pair<int, int>> v;
    rep2(i, st, n) {
      if (!arr.at(i))
        add++;
      else {
        if (add != 0) {
          v.push_back({i - add, add});
          int r = rc(add, d);
          // cerr << "XR " << r << endl;
          xs ^= r;
        }
        add = 0;
      }
    }
    if (add != 0) {
      v.push_back({n - add, add});
      int r = rc(add, d);
      // cerr << "XR " << r << endl;
      xs ^= r;
    }
    int ans = -1;
    // cerr << "XS " << xs << endl;
    for (auto [a, b] : v) {
      // cerr << "T" << a << " " << b << endl;
      rep(i, b) {
        int l = i, r = b - d - i;
        if (r < 0) break;
        // cerr << "P" << l << " " << r << endl;
        if ((xs ^ rc(b, d) ^ rc(l, d) ^ rc(r, d)) == 0) {
          ans = a + i;
          break;
        }
      }
      if (ans != -1) {
        break;
      }
    }
    // cerr << "X" << ans << endl;
    upd(ans);
    auto [rf, rs] = inout(ans, d);
    if (rf == -1 && rs == 0) return;
    if (rf == -2 && rs == -1) return;
    upd(rf);
  }
}

int main() {
  int n, l, r;
  cin >> n >> l >> r;
  if (l == r) {
    solve(n, l);
    return 0;
  }

  cout << "First" << endl;
  int f = -1, s = -1;
  rep2(i, l, r + 1) {
    if ((n - i) % 2 != 0) continue;
    f = (n - i) / 2, s = i;
    break;
  }
  int ss = f + s;
  int rf = -1, rs = -1;
  tie(rf, rs) = inout(f, s);
  if (rf == -1 && rs == 0) return 0;
  if (rf == -2 && rs == -1) return 0;
  while (1) {
    int nf = -1, ns = rs;
    if (rf < ss) {
      nf = ss + rf;
    } else {
      nf = rf - ss;
    }
    tie(rf, rs) = inout(nf, ns);
    if (rf == -1 && rs == 0) return 0;
    if (rf == -2 && rs == -1) return 0;
  }
  return 0;
}