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
  string s;
  cin >> s;
  int co = 0;
  rep(i, s.size()) {
    if (s.at(i) != 'a') break;
    co++;
  }
  if (co == s.size()) {
    cout << "Yes" << endl;
    return 0;
  }
  reverse(ALL(s));
  int co2 = 0;
  rep(i, s.size()) {
    if (s.at(i) != 'a') break;
    co2++;
  }
  if (co > co2) {
    cout << "No" << endl;
    return 0;
  }
  reverse(ALL(s));
  string t;
  int n = s.size();
  rep2(i, co, n - co2) { t.push_back(s.at(i)); }
  auto t2 = t;
  reverse(ALL(t));
  if (t == t2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}