// 배열 --> std::vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {4, 3, 12, 7, 11, 1, 9, 8, 14, 6};

    // 0번 요소
    cout << a[0] << endl;

    // 2번 요소
    cout << a[2] << endl;

    // 2번 요소 변경
    a[2] = 5;

    // 2번 요소
    cout << a[2] << endl;
}
