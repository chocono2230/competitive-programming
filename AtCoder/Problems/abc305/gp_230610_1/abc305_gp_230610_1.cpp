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
using mint = modint998244353;

// 行列積
vector<vector<mint>> matrix_mul(const vector<vector<mint>> &p,
                                const vector<vector<mint>> &q) {
  const int n = p.size();
  vector res(n, vector<mint>(n, 0));
  rep(k, n) rep(i, n) rep(j, n) {
    res.at(i).at(j) += p.at(i).at(k) * q.at(k).at(j);
  }
  return res;
}

// 行列累乗
vector<vector<mint>> matrix_exp(const vector<vector<mint>> &now, ll lv) {
  const int n = now.size();
  if (lv == 0) {
    vector res(n, vector<mint>(n, 0));
    rep(i, n) res.at(i).at(i) = 1;
    return res;
  }
  if (lv == 1) return now;
  if (lv % 2 == 1) return matrix_mul(now, matrix_exp(now, lv - 1));
  auto r = matrix_exp(now, lv / 2);
  return matrix_mul(r, r);
}

int main() {
  ll n;
  int m;
  cin >> n >> m;
  vector<string> s(m);
  int mxs = 0;
  rep(i, m) {
    cin >> s.at(i);
    mxs = max(mxs, (int)s.at(i).size());
  }
  ll z = min(n, (ll)mxs);
  vector<mint> st(1 << z, 0);
  rep(bit, 1 << z) {
    string add(z, 'a');
    rep(i, z) {
      if ((bit & (1 << i)) != 0) add.at(i) = 'b';
    }
    bool f = false;
    for (const auto &ss : s) {
      if (add.find(ss) != string::npos) {
        f = true;
        break;
      }
    }
    if (!f) {
      st.at(bit) = 1;
    }
  }
  if (z == n) {
    mint ans = reduce(ALL(st));
    cout << ans.val() << endl;
    return 0;
  }

  vector dp(1 << mxs, vector<mint>(1 << mxs, 0));
  auto tobit = [&](const string &s) -> int {
    int res = 0;
    rrep(i, s.size()) {
      res *= 2;
      if (s.at(i) == 'b') res++;
    }
    return res;
  };
  rep(bit, 1 << mxs) {
    string now(mxs, 'a');
    rep(i, mxs) {
      if ((bit & (1 << i)) != 0) now.at(i) = 'b';
    }
    auto ff = [&](const string &t) -> void {
      for (const auto &ss : s) {
        if (t.find(ss) != string::npos) return;
      }
      int idx = tobit(t);
      dp.at(bit).at(idx) = 1;
    };
    auto nx = now.substr(1) + "a";
    ff(nx);
    nx.back() = 'b';
    ff(nx);
  }
  // rep(i, dp.size()) {
  //   rep(j, dp.at(i).size()) cerr << dp.at(i).at(j).val() << " ";
  //   cerr << endl;
  // }
  // cerr << endl;
  // rep(i, st.size()) cerr << st.at(i).val() << " ";
  // cerr << endl << endl;

  dp = matrix_exp(dp, n - mxs);
  // rep(i, dp.size()) {
  //   rep(j, dp.at(i).size()) cerr << dp.at(i).at(j).val() << " ";
  //   cerr << endl;
  // }
  // cerr << endl;
  mint ans = 0;
  rep(i, st.size()) rep(k, 1 << mxs) { ans += st.at(k) * dp.at(k).at(i); }
  cout << ans.val() << endl;
  // rep(i, n - mxs) {
  //   vector<mint> nxt(st.size(), 0);
  //   rep(i, st.size()) rep(k, 1 << mxs) {
  //     nxt.at(i) += st.at(k) * dp.at(k).at(i);
  //   }
  //   swap(nxt, st);
  //   cerr << i + mxs + 1 << endl;
  //   rep(i, st.size()) cerr << st.at(i).val() << " ";
  //   cerr << endl;
  //   cerr << reduce(ALL(st)).val() << endl;
  // }
  return 0;
}