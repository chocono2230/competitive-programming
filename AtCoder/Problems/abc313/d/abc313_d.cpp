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

int inout(const vector<int> &v, int k) {
  cout << "?";
  assert(v.size() == k);
  for (auto x : v) cout << " " << x + 1;
  cout << endl;
  int in;
  cin >> in;
  if (in == -1) exit(1);
  return in;
}

void oo(const vector<int> &ans) {
  cout << "!";
  for (auto now : ans) cout << " " << now;
  cout << endl;
  return;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ans(n, -1);
  vector<int> v(k, 0);
  if (k == 1) {
    rep(i, n) {
      v.at(0) = i;
      int r = inout(v, k);
      v.at(i) = r;
    }
    oo(ans);
    return 0;
  }

  vector<int> p(n, 0);
  vector gr(n, vector<pair<int, int>>());
  if (n % 2 == 1) {
    rep(i, n) {
      rep(j, k) { v.at(j) = (i + j) % n; }
      p.at(i) = inout(v, k);
    }
    rep(i, n) {
      int nx = (i + k) % n;
      int dd = (p.at(i) ^ p.at((i + 1) % n));
      gr.at(i).push_back({nx, dd});
      gr.at(nx).push_back({i, dd});
    }
    int now = 0, bf = -1, z = 0;
    while (bf == -1 || now != 0) {
      ans.at(now) = z;
      for (auto [nx, d] : gr.at(now)) {
        if (nx == bf) continue;
        z = (z ^ d);
        bf = now;
        now = nx;
        break;
      }
    }
    if (reduce(ALL(ans)) % 2 != reduce(ALL(p)) % 2) {
      int now = 0, bf = -1, z = 1;
      while (bf == -1 || now != 0) {
        ans.at(now) = z;
        for (auto [nx, d] : gr.at(now)) {
          if (nx == bf) continue;
          z = (z ^ d);
          bf = now;
          now = nx;
          break;
        }
      }
    }
    oo(ans);
    return 0;
  }

  rep(i, n - 1) {
    v.at(0) = 0;
    rep2(j, 1, k) { v.at(j) = (i + (j - 1)) % (n - 1) + 1; }
    p.at(i) = inout(v, k);
  }
  ans.at(0) = reduce(ALL(p)) % 2;
  rep(i, n - 1) {
    int nx = (i + k) % (n - 1) + 1;
    int dd = (p.at(i) ^ p.at((i + 1) % (n - 1)));
    gr.at(i + 1).push_back({nx, dd});
    gr.at(nx).push_back({i + 1, dd});
  }
  int now = 1, bf = -1, z = 0;
  while (bf == -1 || now != 1) {
    ans.at(now) = z;
    for (auto [nx, d] : gr.at(now)) {
      if (nx == bf) continue;
      z = (z ^ d);
      bf = now;
      now = nx;
      break;
    }
  }
  rep(j, k) { v.at(j) = j + 1; }
  p.back() = inout(v, k);
  int s = 0;
  rep(j, k) {
    s += ans.at(j + 1);
    s %= 2;
  }
  oo(ans);
  if (s != p.back()) {
    int now = 1, bf = -1, z = 1;
    while (bf == -1 || now != 1) {
      ans.at(now) = z;
      for (auto [nx, d] : gr.at(now)) {
        if (nx == bf) continue;
        z = (z ^ d);
        bf = now;
        now = nx;
        break;
      }
    }
  }
  oo(ans);

  return 0;
}