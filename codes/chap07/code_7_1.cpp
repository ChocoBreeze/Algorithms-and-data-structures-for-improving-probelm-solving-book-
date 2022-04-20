// 동전 금액
// 가장 큰 동전부터 개수 카운팅
#include <iostream>
#include <vector>
using namespace std;

// 동전 금액
const vector<int> value = {500, 100, 50, 10, 5, 1};

int main() {
    int X;
    vector<int> a(6);
    cin >> X;
    for (int i = 0; i < 6; ++i) cin >> a[i];

    // 탐욕법
    int result = 0;
    for (int i = 0; i < 6; ++i) {
        // 개수 제한이 없는 경우 최대 개수
        int add = X / value[i];

        // 개수 제한 고려
        if (add > a[i]) add = a[i];

        // 남은 금액 계산 후 답에 사용한 동전 
        X -= value[i] * add;
        result += add;
    }
    cout << result << endl;
}
