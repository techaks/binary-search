class Solution {
public:
    typedef long long ll;
    bool possible(vector<int>& ranks, ll mid, int cars) {
        ll temp = 0;
        for (int rank : ranks) {
            temp += sqrt(mid / rank);
        }

        return temp >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1;
        int n = ranks.size();
        int maxR = *max_element(begin(ranks), end(ranks));
        ll r = 1LL * maxR * cars * cars;
        ll res = -1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (possible(ranks, mid, cars)) {
                res = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return res;
    }
};