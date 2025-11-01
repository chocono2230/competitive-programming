#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

// 動的mod
// 同じmodではない場合の挙動は未定義
// mod 0 は単位元としての挙動をする(セグ木対応)
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

// ローリングハッシュ+セグ木+動的modについてはabc331-F参照
// ローリングハッシュ単体はABC353-E参考
struct RollingHash {
  const int PXSIZE = 4;
  using Key = tuple<DynamicMint, DynamicMint, DynamicMint, DynamicMint>;
  using Value = int;
  map<Key, Value> mp;
  Key reset0, reset1;
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
  void setReset(int sz) {
    vector<DynamicMint> ps0(PXSIZE), ps1(PXSIZE);
    rep(i, PXSIZE) {
      auto [p, x] = px.at(i);
      auto p0 = DynamicMint(p, 2);
      auto p1 = DynamicMint(p, 3);
      rep(i, sz) { p0 *= DynamicMint(p, x); }
      rep(i, sz) { p1 *= DynamicMint(p, x); }
      ps0.at(i) = p0;
      ps1.at(i) = p1;
    }
    reset0 = {ps0.at(0), ps0.at(1), ps0.at(2), ps0.at(3)};
    reset1 = {ps1.at(0), ps1.at(1), ps1.at(2), ps1.at(3)};
  }
  Key hash(const Key &p, int add, int pop) {
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
      ps.at(i) = now;
    }
    vector<DynamicMint> rs0, rs1;
    rs0.push_back(get<0>(reset0));
    rs0.push_back(get<1>(reset0));
    rs0.push_back(get<2>(reset0));
    rs0.push_back(get<3>(reset0));
    rs1.push_back(get<0>(reset1));
    rs1.push_back(get<1>(reset1));
    rs1.push_back(get<2>(reset1));
    rs1.push_back(get<3>(reset1));
    rep(i, PXSIZE) {
      DynamicMint now = ps.at(i);
      if (pop == 0) {
        now -= rs0.at(i);
      } else {
        now -= rs1.at(i);
      }
      res.push_back(now);
    }
    return {res.at(0), res.at(1), res.at(2), res.at(3)};
  }
  Key hash(const string &s) {
    vector<int> v(s.size());
    rep(i, s.size()) v.at(i) = s.at(i);
    return hash(v);
  }
  int opr(string a, string b) {
    auto target = zeroHash();
    auto now = zeroHash();
    rep(i, b.size()) {
      int add = 2;
      if (b.at(i) == '1') add = 3;
      target = hash(target, add);
      add = 2;
      if (a.at(i) == '1') add = 3;
      now = hash(now, add);
    }
    rep(i, a.size()) {
      if (target == now) return i;
      if (a.at(i) == '0') {
        now = hash(now, 2, 0);
      } else {
        now = hash(now, 3, 1);
      }
    }
    return -1;
  }
};

int main() {
  int t;
  cin >> t;
  RollingHash rh;
  while (t--) {
    string a, b;
    cin >> a >> b;
    rh.setReset(a.size());
    cout << rh.opr(a, b) << endl;
  }

  return 0;
}