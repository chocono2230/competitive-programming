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

int main() {
  int n;
  ll s;
  cin >> n >> s;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  ll sum = reduce(ALL(a));
  s %= sum;
  rep(i, n) a.push_back(a.at(i));
  vector<ll> sv(n * 2 + 1, 0);
  rep(i, n * 2) sv.at(i + 1) = sv.at(i) + a.at(i);
  // rep(i, sv.size()) cerr << sv.at(i) << " ";
  // cerr << endl;
  rep(i, n) {
    int ng = n * 2 + 2, ok = i;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      auto fc = [&]() { return sv.at(mid) - sv.at(i) <= s; };
      if (fc())
        ok = mid;
      else
        ng = mid;
    }
    // cerr << s << " " << i << " " << ok << endl;
    if (sv.at(ok) - sv.at(i) == s) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}