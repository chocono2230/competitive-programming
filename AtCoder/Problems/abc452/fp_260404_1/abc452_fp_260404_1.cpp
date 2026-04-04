#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
  }
  const auto fc = [&](ll k) {
    fenwick_tree<ll> fw(n);
    int r = 0;
    ll now = 0, res = 0;
    rep(l, n) {
      if (r < l) r = l;
      while (r < n) {
        int add = fw.sum(a.at(r), n);
        if (now + add > k) break;
        now += add;
        fw.add(a.at(r), 1);
        r++;
      }
      res += r - l;
      now -= fw.sum(0, a.at(l));
      fw.add(a.at(l), -1);
    }
    return res;
  };
  cout << fc(k) - (k == 0 ? 0 : fc(k - 1)) << endl;
  return 0;
}