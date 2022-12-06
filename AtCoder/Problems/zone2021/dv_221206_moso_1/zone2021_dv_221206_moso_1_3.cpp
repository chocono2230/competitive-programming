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
  deque<char> q;
  bool f = false;
  string s;
  cin >> s;
  for (auto c : s) {
    if (c == 'R') {
      f = !f;
    } else {
      if (!f) {
        if (q.size() != 0 && q.back() == c) {
          q.pop_back();
        } else {
          q.push_back(c);
        }
      } else {
        if (q.size() != 0 && q.front() == c) {
          q.pop_front();
        } else {
          q.push_front(c);
        }
      }
    }
  }
  if (f) reverse(ALL(q));
  rep(i, q.size()) { cout << q.at(i); }
  cout << endl;
  return 0;
}