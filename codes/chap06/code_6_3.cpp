// 나이 맞히기 O(logN)
#include <iostream>
using namespace std;

int main() {
    cout << "Start Game!" << endl;

    // A씨의 나이 후보 구간을 [left, right)로 표시
    int left = 20, right = 36;

    // 후보가 하나가 될 때까지 반복
    while (right - left > 1) {
        int mid = left + (right - left) / 2; //구간 한가운데
        // mid = (left + right) / 2 --> overflow

        // mid 이상인지 물어서 yes/no 답 받기
        cout << "Is the age less than " << mid << " ? (yes / no)" << endl;
        string ans;
        cin >> ans;

        // 입력값에 따라 범위 줄이기
        if (ans == "yes") right = mid;
        else left = mid;
    }

    // 정답
    cout << "The age is " << left << "!" << endl;
}
