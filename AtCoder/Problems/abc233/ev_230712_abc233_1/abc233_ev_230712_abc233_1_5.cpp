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
  string x;
  cin >> x;
  vector<ll> co(x.size(), 0);
  ll sum = 0;
  for (auto c : x) {
    sum += c - '0';
  }
  rrep(i, co.size()) {
    co.at(i) += sum;
    ll add = co.at(i) / 10;
    if (i != 0) co.at(i - 1) = add;
    if (i != 0) co.at(i) %= 10;
    sum -= x.at(i) - '0';
  }
  for (auto now : co) cout << now;
  cout << endl;
  return 0;
}