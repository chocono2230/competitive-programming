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

// DynamicMint +*-/ other には非対応。暗黙キャスト注意
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

  // for ordered map
  bool operator<(const DynamicMint &a) const {
    if (mod != a.mod) return mod < a.mod;
    return x < a.x;
  }
};

struct RollingHash {
  const int PXSIZE = 4;
  using Key = tuple<DynamicMint, DynamicMint, DynamicMint, DynamicMint>;
  using Value = int;
  map<Key, Value> mp;
  vector<pair<int, int>> px;
  random_device rd;

  int randomNumber() {
    const int sz = 1000000000;
    int res = abs((int)rd());
    if (res < sz) res += sz;
    return res;
  }

  RollingHash() {
    auto fc = [](int x) {
      for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
      }
      return true;
    };
    while ((int)px.size() != PXSIZE) {
      int p = randomNumber();
      auto flg = fc(p);
      if (!flg) continue;
      int x = randomNumber();
      px.push_back({p, x});
    }
  }

  Key zeroHash() {
    vector<DynamicMint> res;
    for (auto [p, _] : px) {
      DynamicMint now(p, 0);
      res.push_back(now);
    }
    return {res.at(0), res.at(1), res.at(2), res.at(3)};
  }

  Key hash(const vector<int> &v) {
    vector<DynamicMint> res;
    for (auto [p, x] : px) {
      DynamicMint mx(p, x);
      DynamicMint now(p, 0);
      for (auto n : v) {
        now *= mx;
        now += DynamicMint(p, n);
      }
      res.push_back(now);
    }
    return {res.at(0), res.at(1), res.at(2), res.at(3)};
  }
  Key hash(const Key &p, int add) {
    vector<DynamicMint> ps;
    ps.push_back(get<0>(p));
    ps.push_back(get<1>(p));
    ps.push_back(get<2>(p));
    ps.push_back(get<3>(p));
    vector<DynamicMint> res;
    rep(i, PXSIZE) {
      auto [p, x] = px.at(i);
      DynamicMint now = ps.at(i);
      now *= DynamicMint(p, x);
      now += DynamicMint(p, add);
      res.push_back(now);
    }
    return {res.at(0), res.at(1), res.at(2), res.at(3)};
  }
  Key hash(const string &s) {
    vector<int> v(s.size());
    rep(i, s.size()) v.at(i) = s.at(i);
    return hash(v);
  }
};

int main() {
  int n;
  cin >> n;
  vector<string> vs(n);
  rep(i, n) cin >> vs.at(i);
  RollingHash rh;
  ll ans = 0;
  for (auto s : vs) {
    auto now = rh.zeroHash();
    for (auto c : s) {
      auto nx = rh.hash(now, c);
      ans += rh.mp[nx];
      rh.mp[nx]++;
      now = nx;
    }
  }
  cout << ans << endl;
  return 0;
}