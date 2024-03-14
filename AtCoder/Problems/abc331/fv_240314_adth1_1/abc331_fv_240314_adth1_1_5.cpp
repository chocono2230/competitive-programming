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

struct DynamicMint {
  int mod;
  ll x;
  DynamicMint(int mod = 0, ll x = 0) : mod(mod), x(x) {
    if (mod != 0) {
      x = (x % mod + mod) % mod;
    }
  }
  bool operator==(const DynamicMint &a) const { return x == a.x; }
  DynamicMint operator-() const { return DynamicMint(mod, -x); }
  DynamicMint &operator+=(const DynamicMint a) {
    if (mod == 0) {
      x = a.x;
      mod = a.mod;
      return *this;
    }
    if (a.mod == 0) return *this;
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  DynamicMint &operator-=(const DynamicMint a) {
    if (mod == 0) {
      x = a.x;
      mod = a.mod;
      return *this;
    }
    if (a.mod == 0) return *this;
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  DynamicMint &operator*=(const DynamicMint a) {
    if (mod == 0) {
      x = a.x;
      mod = a.mod;
      return *this;
    }
    if (a.mod == 0) return *this;
    (x *= a.x) %= mod;
    return *this;
  }
  DynamicMint operator+(const DynamicMint a) const {
    DynamicMint res(*this);
    return res += a;
  }
  DynamicMint operator-(const DynamicMint a) const {
    DynamicMint res(*this);
    return res -= a;
  }
  DynamicMint operator*(const DynamicMint a) const {
    DynamicMint res(*this);
    return res *= a;
  }
  DynamicMint pow(ll t) const {
    if (!t) return 1;
    DynamicMint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  DynamicMint inv() const { return pow(mod - 2); }
  DynamicMint &operator/=(const DynamicMint a) {
    if (mod == 0) {
      x = a.x;
      mod = a.mod;
      return *this;
    }
    if (a.mod == 0) return *this;
    return (*this) *= a.inv();
  }
  DynamicMint operator/(const DynamicMint a) const {
    DynamicMint res(*this);
    return res /= a;
  }
};

vector<int> P = {1812741443, 1327780303, 1666641469, 1706014279};
vector<int> X = {};

using dm = DynamicMint;
using pp = pair<DynamicMint, DynamicMint>;
struct S {
  pp hl1;
  pp hl2;
  pp hl3;
  pp hl4;
  S() {}
  S(pp hl1, pp hl2, pp hl3, pp hl4) : hl1(hl1), hl2(hl2), hl3(hl3), hl4(hl4) {}
};

S op(S l, S r) {
  pp hl1 = pp(dm(l.hl1.first.mod, 0), dm(l.hl1.first.mod, l.hl1.second.x));
  pp hl2 = pp(dm(l.hl2.first.mod, 0), dm(l.hl2.first.mod, l.hl2.second.x));
  pp hl3 = pp(dm(l.hl3.first.mod, 0), dm(l.hl3.first.mod, l.hl3.second.x));
  pp hl4 = pp(dm(l.hl4.first.mod, 0), dm(l.hl4.first.mod, l.hl4.second.x));
  hl1.second = l.hl1.second * r.hl1.second;
  hl1.first = l.hl1.first * r.hl1.second + r.hl1.first;
  hl2.second = l.hl2.second * r.hl2.second;
  hl2.first = l.hl2.first * r.hl2.second + r.hl2.first;
  hl3.second = l.hl3.second * r.hl3.second;
  hl3.first = l.hl3.first * r.hl3.second + r.hl3.first;
  hl4.second = l.hl4.second * r.hl4.second;
  hl4.first = l.hl4.first * r.hl4.second + r.hl4.first;
  return S(hl1, hl2, hl3, hl4);
}
S e() { return S(); }

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  random_device rnd;
  rep(i, 4) {
    while (1) {
      int x = rnd() % P.at(i);
      if (x <= 1) continue;
      X.push_back(x);
      break;
    }
  }
  segtree<S, op, e> sg1(n), sg2(n);
  auto set = [&](int idx) {
    int now = s.at(idx);
    pp hl1 = pp(dm(P.at(0), now), dm(P.at(0), X.at(0)));
    pp hl2 = pp(dm(P.at(1), now), dm(P.at(1), X.at(1)));
    pp hl3 = pp(dm(P.at(2), now), dm(P.at(2), X.at(2)));
    pp hl4 = pp(dm(P.at(3), now), dm(P.at(3), X.at(3)));
    S ss(hl1, hl2, hl3, hl4);
    sg1.set(idx, ss);
    sg2.set(n - idx - 1, ss);
  };
  rep(i, n) { set(i); }
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      s.at(x) = c;
      set(x);
      continue;
    }
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int l2 = n - l - 1, r2 = n - r - 1;
    auto s1 = sg1.prod(l, r + 1);
    auto s2 = sg2.prod(r2, l2 + 1);
    // cerr << s1.hl1.first.x << " " << s1.hl1.first.mod << " " <<
    // s1.hl1.second.x
    //      << " " << s1.hl1.second.mod << endl;
    // cerr << s2.hl1.first.x << " " << s2.hl1.first.mod << " " <<
    // s2.hl1.second.x
    //      << " " << s2.hl1.second.mod << endl;
    bool f = !(s1.hl1.first == s2.hl1.first);
    f |= !(s1.hl2.first == s2.hl2.first);
    f |= !(s1.hl3.first == s2.hl3.first);
    f |= !(s1.hl4.first == s2.hl4.first);
    // cerr << (s1.hl1.first == s2.hl1.first) << " ";
    // cerr << (s1.hl2.first == s2.hl2.first) << " ";
    // cerr << (s1.hl3.first == s2.hl3.first) << " ";
    // cerr << (s1.hl4.first == s2.hl4.first) << " ";
    // cerr << endl;
    if (f)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }

  return 0;
}