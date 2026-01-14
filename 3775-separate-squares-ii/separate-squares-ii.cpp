class Solution {
public:
    struct Event {
        long long y, x1, x2;
        int type; // +1 add, -1 remove
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    struct SegTree {
        int n;
        vector<int> cover;
        vector<long long> length;
        vector<long long> xs;

        SegTree(const vector<long long>& coords) {
            xs = coords;
            n = xs.size() - 1;
            cover.assign(4 * n, 0);
            length.assign(4 * n, 0);
        }

        void pull(int idx, int l, int r) {
            if (cover[idx] > 0) {
                length[idx] = xs[r + 1] - xs[l];
            } else if (l == r) {
                length[idx] = 0;
            } else {
                length[idx] = length[idx * 2] + length[idx * 2 + 1];
            }
        }

        void update(int idx, int l, int r, int ql, int qr, int v) {
            if (ql <= l && r <= qr) {
                cover[idx] += v;
                pull(idx, l, r);
                return;
            }
            int m = (l + r) / 2;
            if (ql <= m) update(idx * 2, l, m, ql, qr, v);
            if (qr > m) update(idx * 2 + 1, m + 1, r, ql, qr, v);
            pull(idx, l, r);
        }

        void update(int l, int r, int v) {
            if (l <= r) update(1, 0, n - 1, l, r, v);
        }

        long long query() const {
            return length[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<long long> xs;

        for (auto& s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, +1});
            events.push_back({y + l, x, x + l, -1});
            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto xid = [&](long long x) {
            return int(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
        };

        sort(events.begin(), events.end());
        SegTree st(xs);

        struct Strip {
            long long y0, y1, width;
        };
        vector<Strip> strips;

        long long prevY = events[0].y;
        int i = 0;

        while (i < events.size()) {
            long long curY = events[i].y;
            long long w = st.query();
            if (curY > prevY && w > 0) {
                strips.push_back({prevY, curY, w});
            }

            while (i < events.size() && events[i].y == curY) {
                int l = xid(events[i].x1);
                int r = xid(events[i].x2) - 1;
                st.update(l, r, events[i].type);
                i++;
            }
            prevY = curY;
        }

        long double totalArea = 0;
        for (auto& s : strips) {
            totalArea += (long double)s.width * (s.y1 - s.y0);
        }

        long double half = totalArea / 2.0;
        long double acc = 0;

        for (auto& s : strips) {
            long double area = (long double)s.width * (s.y1 - s.y0);
            if (acc + area >= half) {
                long double dy = (half - acc) / s.width;
                return (double)(s.y0 + dy);
            }
            acc += area;
        }

        return 0.0; 
    }
};
