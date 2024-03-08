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

const int PS = 4;

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

struct S {
  array<DynamicMint, PS> vh;
  array<DynamicMint, PS> vp;
  S() {}
  S(array<DynamicMint, PS> vh, array<DynamicMint, PS> vp) : vh(vh), vp(vp) {}
};

S op(S l, S r) {
  S res;
  rep(i, PS) {
    res.vh.at(i) = l.vh.at(i) + r.vh.at(i) * l.vp.at(i);
    res.vp.at(i) = l.vp.at(i) * r.vp.at(i);
  }
  return res;
}
S e() {
  S res;
  rep(i, PS) {
    res.vh.at(i) = DynamicMint();
    res.vp.at(i) = DynamicMint();
  }
  return res;
}

vector<pair<int, int>> create_px(int sz) {
  auto fc = [](int x) {
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) return false;
    }
    return true;
  };

  auto d = random_device();
  vector<pair<int, int>> px;
  rep(i, 2000000000) {
    int p = d();
    p = abs(p);
    auto r = fc(p);
    if (r) {
      int x = abs((int)d()) % p;
      px.push_back({p, x});
      if ((int)px.size() == sz) break;
    }
  }
  assert((int)px.size() == sz);
  return px;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> px = create_px(PS);
  segtree<S, op, e> s1(n), s2(n);
  string s;
  cin >> s;

  auto set = [&](int i, char z) {
    S s;
    rep(idx, PS) {
      int mod = px.at(idx).first;
      int x = px.at(idx).second;
      s.vp.at(idx) = DynamicMint(mod, x);
      s.vh.at(idx) = DynamicMint(mod, z);
    }
    s1.set(i, s);
    int j = n - i - 1;
    s2.set(j, s);
  };
  rep(i, n) {
    int z = s.at(i);
    set(i, z);
  }

  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int i;
      char c;
      cin >> i >> c;
      i--;
      set(i, c);
      continue;
    }
    int l, r;
    cin >> l >> r;
    l--;
    auto r1 = s1.prod(l, r);
    auto r2 = s2.prod(n - r, n - l);
    bool f = false;
    rep(i, PS) {
      if (r1.vh.at(i) != r2.vh.at(i)) {
        f = true;
        break;
      }
    }
    if (!f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}