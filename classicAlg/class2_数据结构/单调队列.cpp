#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k;

    deque<pair<int, int>> q_min;
    deque<pair<int, int>> q_max;

    vector<int> res_min;
    vector<int> res_max;
    for (int i = 0; i < k - 1; i++) {
        cin >> t;
        while (!q_min.empty() && q_min.back().second >= t) {
            q_min.pop_back();
        }
        q_min.push_back({i, t});

        while (!q_max.empty() && q_max.back().second <= t) {
            q_max.pop_back();
        }
        q_max.push_back({i, t});
    }
    for (int i = k - 1; i < n; i++) {
        cin >> t;
        while (!q_min.empty() && q_min.back().second >= t) {
            q_min.pop_back();
        }
        q_min.push_back({i, t});

        while (!q_max.empty() && q_max.back().second <= t) {
            q_max.pop_back();
        }
        q_max.push_back({i, t});

        while (!q_min.empty() && q_min.front().first < i - (k - 1)) {
            q_min.pop_front();
        }
        res_min.push_back(q_min.front().second);

        while (!q_max.empty() && q_max.front().first < i - (k - 1)) {
            q_max.pop_front();
        }
        res_max.push_back(q_max.front().second);
    }

    for (int i : res_min) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : res_max) {
        cout << i << " ";
    }
    cout << endl;
}
