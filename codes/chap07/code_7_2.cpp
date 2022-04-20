// interval scheduling problem
// O(NlogN)
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 구간
typedef pair<int,int> Interval;

// 구간에 대해 종료 시각을 기준으로 비교하는 함수
bool cmp(const Interval &a, const Interval &b) {
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;
    vector<Interval> inter(N);
    for (int i = 0; i < N; ++i)
        cin >> inter[i].first >> inter[i].second;

    // 정렬 - 종료 시간이 빠른 것이 먼저 오도록 --> O(NlogN)
    sort(inter.begin(), inter.end(), cmp);

    // 탐욕법 --> O(N)
    int res = 0;
    int current_end_time = 0;
    for (int i = 0; i < N; ++i) {
        // 이전에 고른 구간과 겹치면 제외
        if (inter[i].first < current_end_time) continue;

        ++res;
        current_end_time = inter[i].second;
    }
    cout << res << endl;
}
