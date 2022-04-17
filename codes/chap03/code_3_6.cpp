// N개의 숫자들에서 부분합으로 W를 만들 수 있는지 확인
// O(N2^N)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    // bit는 2^N개 존재하는 부분 집합 전체를 대상으로 동작
    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit) // 1 ~ 2^N
    {
        int sum = 0; 
        for (int i = 0; i < N; ++i) {
            // i 번째 요소가 부분 집합에 포함된다면 더하기
            if (bit & (1 << i)) { 
                sum += a[i];
            }
        }
        
        // sum과 W 일치하는지
        if (sum == W) exist = true;
    }
    
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
