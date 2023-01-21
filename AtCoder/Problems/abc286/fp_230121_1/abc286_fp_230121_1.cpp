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

vector<bool> make_prime_bool_vec(int lim) {
  vector<bool> chk(lim + 1, true);
  chk.at(0) = chk.at(1) = false;
  rep2(i, 2, chk.size()) {
    if (chk.at(i) == false) continue;
    for (int j = i + i; j < chk.size(); j += i) chk.at(j) = false;
  }
  return chk;
}

int main() {
  auto tt = make_prime_bool_vec(30);
  vector<ll> v;
  rep2(i, 2, 24) {
    if (tt.at(i)) {
      if (i == 2 || i == 3)
        v.push_back(i * i);
      else
        v.push_back(i);
    }
  }
  vector<int> a(108);
  int idx = 0;
  for (auto now : v) {
    int mx = idx + now;
    rep2(i, idx, mx) {
      a.at(i) = i + 1;
      if (i == mx - 1) a.at(i) = idx;
      a.at(i)++;
    }
    idx = mx;
  }
  int m = a.size();
  cout << m << endl;
  rep(i, m) {
    if (i != 0) cout << " ";
    cout << a.at(i);
  }
  cout << endl;

  vector<int> b(m);
  rep(i, m) {
    cin >> b.at(i);
    b.at(i)--;
  }

  // vector<int> b;
  // idx = 0;
  // for (auto now : v) {
  //   int mx = idx + now;
  //   deque<int> q;
  //   rep2(i, idx, mx) {
  //     q.push_back(i + 1);
  //     if (i == mx - 1) q.back() = idx;
  //     q.back()++;
  //   }
  //   rep(i, 0) {
  //     q.push_back(q.front());
  //     q.pop_front();
  //   }
  //   for (auto z : q) b.push_back(z);
  //   idx = mx;
  // }
  // rep(i, m) b.at(i)--;
  // rep(i, m) {
  //   if (i != 0) cout << " ";
  //   cout << b.at(i);
  // }
  // cout << endl;

  idx = 0;
  vector<ll> p;
  int ss = 0;
  for (auto now : v) {
    int mx = idx + now;
    ll add = b.at(mx - 1) - idx;
    if (add == -1) add += now;
    // cerr << mx << ":" << add << ":" << v.at(ss++) << endl;
    p.push_back(add);
    idx = mx;
  }
  auto [rf, rs] = crt(p, v);
  cout << rf + 1 << endl;
  return 0;
}