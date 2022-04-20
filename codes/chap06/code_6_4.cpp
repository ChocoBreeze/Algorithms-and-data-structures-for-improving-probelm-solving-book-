// 합이 K 이상인 범위에서 최소값 구하기
// O(NlogN)
#include <iostream>
#include <vector>
#include <algorithm> // sort(), lower_bound()
using namespace std;
const int INF = 20000000; // 충분히 큰 값

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // 잠정 최솟값을 저장하는 변수
    int min_value = INF;

    // b 정렬 -- std::lower_bound 쓰기 위해서
    sort(b.begin(), b.end());

    // b에 무한대를 추가
    // 그 결과 iter = b.end()가 되지 않음.
    b.push_back(INF);

    // a를 고정한 후 풀기
    for (int i = 0; i < N; ++i) {
        // b에서 K - a[i] 이상 범위의 최솟값을 가리키는 iterator
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

        // iterator가 가리키는 값을 추출
        int val = *iter;

        // min_value와 비교
        if (a[i] + val < min_value) {
            min_value = a[i] + val;
        }
    }
    cout << min_value << endl;
}
