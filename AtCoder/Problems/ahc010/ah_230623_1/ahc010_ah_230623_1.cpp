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

const int N = 30;
vector BASE(N, vector<int>(N, 0));
const int di[] = {0, -1, 0, 1}, dj[] = {-1, 0, 1, 0};
const vector<vector<int>> to = {
    {1, 0, -1, -1}, {3, -1, -1, 0}, {-1, -1, 3, 2}, {-1, 2, 1, -1},
    {1, 0, 3, 2},   {3, 2, 1, 0},   {2, -1, 0, -1}, {-1, 3, -1, 1},
};

const clock_t start_time = clock();
double TIME_LIMIT = 1.95;
double time_from_clock() {
  return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 202306231,
                       w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

double xor_shift() {
  double b = xor128() % LLONG_MAX;
  return b / LLONG_MAX;
}

pair<int, int> calc_score(vector<vector<int>> &table) {
  vector<int> chk(N * N * 4, -1);
  auto i2c = [&](int i, int j, int k) { return k + j * 4 + i * 4 * N; };
  int tot = 0;
  int mx = 0, smx = 0;
  int connect_sum = 0;
  rep(si, N) rep(sj, N) {
    bool dd = false;
    rep(sk, 4) {
      if (chk.at(i2c(si, sj, sk)) != -1) continue;
      auto fc = [&](bool db = false) -> pair<int, int> {
        int i = si, j = sj, k = sk, length = 0;
        auto rs = [&](pair<int, int> x) -> pair<int, int> {
          if (db) return {0, 0};
          return x;
        };
        while (1) {
          if (chk.at(i2c(i, j, k)) != -1) return rs({0, length});
          chk.at(i2c(i, j, k)) = tot;
          int nxk = to.at(table.at(i).at(j)).at(k);
          if (nxk == -1) return rs({0, max(0, length - 1)});
          i += di[nxk];
          j += dj[nxk];
          if (i < 0 || i >= N || j < 0 || j >= N) return rs({0, length});
          k = (nxk + 2) % 4;
          length++;
          if (i == si && j == sj && k == sk) return rs({length, length});
        }
      };
      auto r = fc(dd);
      if (r.first != 0) dd = true;
      if (r.first > mx) {
        smx = mx;
        mx = r.first;
      } else if (r.first > smx) {
        smx = r.first;
      }
      connect_sum += r.second;
      tot++;
    }
  }
  return {mx * smx, connect_sum};
}

void input() {
  rep(i, N) {
    string s;
    cin >> s;
    rep(j, N) { BASE.at(i).at(j) = s.at(j) - '0'; }
  }
}

pair<int, int> output(vector<vector<int>> &table) {
  string out;
  rep(i, N) rep(j, N) {
    out.push_back('0');
    if (BASE.at(i).at(j) == table.at(i).at(j)) continue;
    if (BASE.at(i).at(j) >= 4) {
      out.back()++;
      continue;
    }
    rep(z, 3) {
      out.back()++;
      int idx = (BASE.at(i).at(j) + (z + 1)) % 4;
      if (idx == table.at(i).at(j)) break;
    }
  }
  cout << out << endl;
  if (local) {
    return calc_score(table);
  }
  return {0, 0};
}

void random_shuffle(vector<int> &p) {
  rrep2(i, 1, p.size()) {
    int z = xor128() % (i + 1);
    swap(p.at(i), p.at(z));
  }
}

// dir はout基準の方向
bool is_connect(int now, int nx, int dir) {
  bool f = false;
  rep(i, 4) {
    if (to[now][i] == dir) f = true;
  }
  if (!f) return false;
  dir = (dir + 2) % 4;
  return to[nx][dir] != -1;
}

int main() {
  input();

  int dbg_loop = 0;
  auto mx_score = calc_score(BASE);
  auto mx_ans = BASE;
  output(BASE);
  while (time_from_clock() < TIME_LIMIT) {
    dbg_loop++;
    auto table = mx_ans;

    auto fc = [&](vector<pair<int, int>> &targets) {
      int si = targets.front().first, sj = targets.front().second;
      int sk = 0;
      rep(z, 4) {
        if (to.at(table.at(si).at(sj)).at(z) != -1) {
          sk = z;
          break;
        }
      }
      int i = si, j = sj, k = sk;
      int ta_idx = 1;
      int res = 0;
      set<pair<int, int>> se;
      se.insert({si, sj});
      while (1) {
        int ti, tj;
        tie(ti, tj) = targets.at(ta_idx);
        auto calc_dist = [&](int idx) -> int {
          int ni = i + di[idx], nj = j + dj[idx];
          if (ni < 0 || N <= ni || nj < 0 || N <= nj) return 1001001001;
          return abs(ni - ti) + abs(nj - tj);
        };

        if (table.at(i).at(j) >= 6) {
          if (to.at(table.at(i).at(j)).at(k) == -1) {
            int z = table.at(i).at(j) - 6;
            table.at(i).at(j) = 6 + (1 - z);
          }
        } else if (table.at(i).at(j) >= 4) {
          int z = table.at(i).at(j) - 4;
          int r = to.at(z + 4).at(k);
          int r2 = to.at((1 - z) + 4).at(k);
          if (calc_dist(r) > calc_dist(r2)) {
            table.at(i).at(j) = 4 + (1 - z);
          }
        } else {
          int mn = 1001001001;
          int nx = 0;
          rep(p, 4) {
            int r = to.at(p).at(k);
            if (r == -1) continue;
            auto cl = calc_dist(r);
            if (cl < mn || (cl == mn && xor128() % 2 == 0)) {
              mn = cl;
              nx = p;
            }
          }
          table.at(i).at(j) = nx;
        }

        int nxk = to.at(table.at(i).at(j)).at(k);
        if (nxk == -1) return -1;
        i += di[nxk];
        j += dj[nxk];
        if (se.find({i, j}) != se.end()) return -1;
        se.insert({i, j});
        if (i < 0 || i >= N || j < 0 || j >= N) return -1;
        k = (nxk + 2) % 4;
        res++;
        if (i == si && j == sj) {
          if (k == sk) return res;
          return -1;
        }
        if (ti == i && tj == j) {
          ta_idx++;
          ta_idx %= 4;
        }
      }
    };

    auto make_ta = [](int mnh, int mxh, int mnw, int mxw) {
      int midh = (mnh + mxh) / 2, midw = (mnw + mxw) / 2;
      vector<pair<int, int>> res;
      res.push_back({(mnh + midh) / 2, (mnw + midw) / 2});
      res.push_back({(mnh + midh) / 2, (mxw + midw) / 2});
      res.push_back({(mxh + midh) / 2, (mxw + midw) / 2});
      res.push_back({(mxh + midh) / 2, (mnw + midw) / 2});
      rep(i, 4) {
        res.at(i).first += (xor128() % 5) - 2;
        res.at(i).second += (xor128() % 5) - 2;
      }
      return res;
    };

    int mh = N / 2, mw = N / 2;
    vector<pair<int, int>> v1, v2;
    if (xor128() % 2 == 0) {
      v1 = make_ta(0, mh, 0, N);
      v2 = make_ta(mh, N, 0, N);
    } else {
      v1 = make_ta(0, N, 0, mw);
      v2 = make_ta(0, N, mw, N);
    }
    fc(v1);
    fc(v2);

    auto sc = calc_score(table);

    if (sc > mx_score) {
      mx_score = sc;
      mx_ans = table;
    }
  }

  auto score = output(mx_ans);
  if (local) {
    cerr << "artifacts:score:" << score.first << endl;
    cerr << "artifacts:time:" << time_from_clock() << endl;
    cerr << "artifacts:loop:" << dbg_loop << endl;
    cerr << "artifacts:connect:" << score.second << endl;
  }
  return 0;
}
