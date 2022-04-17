// 쌍의 합이 K 이상인 값 중에서 최소인 값 찾기
#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;   

int main() {
    
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];
    
    
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // K 미만이면 skip
            if (a[i] + b[j] < K) continue;

            // K 이상이고 기존 최소값보다 작은 경우 갱신
            if (a[i] + b[j] < min_value) {
                min_value = a[i] + b[j];
            }
        }
    }
    
    // 결과
    cout << min_value << endl;
}
