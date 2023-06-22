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

#ifdef CHOCONO_LOCAL
const bool local = true;
#else
const bool local = false;
#endif

const double TIME_LIMIT = 3 - 0.25;
const int SZ = 5000;
const int WS = 20000 / SZ;
const int CE = SZ / 2;
const double temp_start = 100;
const double temp_end = 1;

int N, K;
vector<int> A(10);
vector<pair<int, int>> XY;
vector xytable(0, vector<int>());

const clock_t start_time = clock();
double time_from_clock() {
  return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 2306223, w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

pair<int, int> xy2idx(int x, int y) {
  auto fc = [](int z) -> int {
    z += 10000;
    return z / WS;
  };
  return {fc(x), fc(y)};
}

pair<int, int> idx2xy(int i, int j) {
  auto fc = [](int z) -> int {
    z *= WS;
    z -= 10000;
    return z;
  };
  return {fc(i), fc(j)};
}

ll calc_score(vector<int> &score_count) {
  assert(reduce(ALL(score_count)) == N);
  int sum = 0, base = 0;
  rep2(i, 1, 11) {
    sum += min(score_count.at(i), A.at(i - 1));
    base += A.at(i - 1);
  }
  return round(1e6 * ((double)sum / base));
}

void output(map<int, vector<int>> &ans_h, map<int, vector<int>> &ans_w) {
  cout << ans_h.size() + ans_w.size() - 2 << endl;
  const int ss = 1e9;
  int s = 0;
  s = 0;
  for (auto &p : ans_h) {
    if (s++ == 0) continue;
    cout << p.first << " " << -ss << " " << p.first - 1 << " " << ss << endl;
  }
  s = 0;
  for (auto &p : ans_w) {
    if (s++ == 0) continue;
    cout << -ss << " " << p.first << " " << ss << " " << p.first - 1 << endl;
  }
}

int main() {
  cin >> N >> K;
  XY.resize(N);
  rep(i, 10) cin >> A.at(i);
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    XY.at(i) = {x, y};
  }
  xytable.resize(SZ, vector<int>(SZ, 0));
  for (auto [x, y] : XY) {
    auto p = xy2idx(x, y);
    xytable.at(p.first).at(p.second)++;
  }
  vector<int> ans_h, ans_w;
  rep(i, K / 2) {
    rep(_i, 10) {
      int idx = xor128() % SZ;
      auto p = idx2xy(0, idx);
      auto itr = lower_bound(ALL(ans_h), p.second);
      if (itr == ans_h.end() || *itr != p.second) {
        ans_h.insert(itr, p.second);
        break;
      }
    }
  }
  rep(i, K / 2) {
    rep(_i, 10) {
      int idx = xor128() % SZ;
      auto p = idx2xy(0, idx);
      auto itr = lower_bound(ALL(ans_w), p.second);
      if (itr == ans_w.end() || *itr != p.second) {
        ans_w.insert(itr, p.second);
        break;
      }
    }
  }
  sort(ALL(ans_h));
  sort(ALL(ans_w));

  map<int, vector<int>> hm, wm;
  hm[-10000] = {};
  wm[-10000] = {};
  for (auto now : ans_h) hm[now] = {};
  for (auto now : ans_w) wm[now] = {};
  vector<pair<int, int>> xy2z(N);
  auto make_v = [&](map<int, vector<int>> &zm, vector<int> &p, bool f) {
    rep(i, p.size()) {
      auto itr = zm.upper_bound(p.at(i));
      assert(itr != zm.begin());
      itr--;
      itr->second.push_back(i);
      if (!f)
        xy2z.at(i).first = itr->first;
      else
        xy2z.at(i).second = itr->first;
    }
  };
  [&] {
    vector<int> v(N);
    rep(i, N) v.at(i) = XY.at(i).first;
    make_v(hm, v, false);
    rep(i, N) v.at(i) = XY.at(i).second;
    make_v(wm, v, true);
  }();
  map<pair<int, int>, int> score_map;
  vector<int> score_count(10005, 0);
  score_count.at(0) = N;
  for (auto [x, y] : xy2z) {
    score_count.at(score_map[{x, y}])--;
    score_map[{x, y}]++;
    score_count.at(score_map[{x, y}])++;
  }

  output(hm, wm);
  ll mx_score = calc_score(score_count);

  int dbg_loop_count = 0;
  int dbg_update_count = 0;

  double loop_start_time = time_from_clock();
  double now_time = loop_start_time;
  while (now_time < TIME_LIMIT) {
    double dist_now_time =
        (now_time - loop_start_time) / (TIME_LIMIT - loop_start_time);
    double temp_now =
        temp_start * (1 - dist_now_time) + temp_end * (dist_now_time);
    [&] {
      dbg_loop_count++;
      auto erf = [&](map<int, vector<int>> &mp, bool f, int rd,
                     bool back = false) -> int {
        auto itr = mp.begin();
        if (back) {
          itr = mp.lower_bound(rd);
          assert(itr->first == rd);
        } else {
          rd++;
          rep(i, rd) itr++;
        }
        auto pitr = itr;
        assert(pitr != mp.begin());
        pitr--;
        for (auto now : itr->second) {
          auto [x, y] = xy2z.at(now);
          score_count.at(score_map[{x, y}])--;
          score_map[{x, y}]--;
          score_count.at(score_map[{x, y}])++;
          if (!f)
            xy2z.at(now).first = pitr->first;
          else
            xy2z.at(now).second = pitr->first;
          tie(x, y) = xy2z.at(now);
          score_count.at(score_map[{x, y}])--;
          score_map[{x, y}]++;
          score_count.at(score_map[{x, y}])++;
          pitr->second.push_back(now);
        }
        int res = itr->first;
        mp.erase(itr);
        return res;
      };
      auto adf = [&](map<int, vector<int>> &mp, bool f, int rd) -> void {
        auto pitr = mp.lower_bound(rd);
        pitr--;
        mp[rd] = {};
        vector<int> nxpi;
        for (auto now : pitr->second) {
          auto [x, y] = xy2z.at(now);
          score_count.at(score_map[{x, y}])--;
          score_map[{x, y}]--;
          score_count.at(score_map[{x, y}])++;
          auto [xx, yy] = XY.at(now);
          int ta = xx;
          if (f) ta = yy;
          if (rd <= ta) {
            mp[rd].push_back(now);
            if (!f)
              xy2z.at(now).first = rd;
            else
              xy2z.at(now).second = rd;
          } else {
            nxpi.push_back(now);
          }
          tie(x, y) = xy2z.at(now);
          score_count.at(score_map[{x, y}])--;
          score_map[{x, y}]++;
          score_count.at(score_map[{x, y}])++;
        }
        pitr->second = nxpi;
      };
      int mode = xor128() % 3;
      vector<tuple<int, int, int>> event;
      if (mode <= 1 && hm.size() + wm.size() != 0) {
        if (xor128() % 2 == 0 && hm.size() != 0) {
          int rd = xor128() % (hm.size() - 1);
          int r = erf(hm, false, rd);
          event.push_back({0, 0, r});
        } else {
          int rd = xor128() % (wm.size() - 1);
          int r = erf(wm, true, rd);
          event.push_back({0, 1, r});
        }
      }
      if (mode % 2 == 0 && (int)hm.size() + (int)wm.size() - 2 != K) {
        if (xor128() % 2 == 0) {
          int rd = -1;
          rep(_i, 10) {
            int idx = xor128() % SZ;
            auto p = idx2xy(0, idx);
            auto itr = hm.lower_bound(p.second);
            if (itr == hm.end() || itr->first != p.second) {
              rd = p.second;
              break;
            }
          }
          if (rd == -1) {
            mode &= 1;
          } else {
            event.push_back({1, 0, rd});
            adf(hm, false, rd);
          }
        } else {
          int rd = -1;
          rep(_i, 10) {
            int idx = xor128() % SZ;
            auto p = idx2xy(0, idx);
            auto itr = wm.lower_bound(p.second);
            if (itr == wm.end() || itr->first != p.second) {
              rd = p.second;
              break;
            }
          }
          if (rd == -1) {
            mode &= 1;
          } else {
            event.push_back({1, 1, rd});
            adf(wm, true, rd);
          }
        }
      }
      ll sc = calc_score(score_count);
      double p = exp((sc - mx_score) / temp_now);
      if (p > (xor128() % LLONG_MAX) / (double)LLONG_MAX) {
        mx_score = sc;
        if (local) {
          dbg_update_count++;
          if (dbg_loop_count % 100 == 0) {
            output(hm, wm);
          }
        }
      } else {
        while (!event.empty()) {
          auto [c, d, e] = event.back();
          event.pop_back();
          if (c == 0) {
            if (d == 0) {
              adf(hm, false, e);
            } else {
              adf(wm, true, e);
            }
          } else {
            if (d == 0) {
              assert(hm.lower_bound(e)->first == e);
              erf(hm, false, e, true);
            } else {
              erf(wm, true, e, true);
            }
          }
        }
      }
    }();
    now_time = time_from_clock();
  }

  output(hm, wm);
  if (local) {
    auto r = calc_score(score_count);
    cerr << "artifacts:score:" << r << endl;
    cerr << "artifacts:loop:" << dbg_loop_count << endl;
    cerr << "artifacts:update:" << dbg_update_count << endl;
    double t = time_from_clock();
    cerr << "artifacts:time:" << t << endl;
  }
  return 0;
}