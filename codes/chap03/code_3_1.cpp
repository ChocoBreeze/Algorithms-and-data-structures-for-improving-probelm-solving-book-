// 선형 탐색(list에서 해당 원소가 있는지 확인)
// 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    bool exist = false;
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) { // 발견하면 flag 설정
            exist = true;
        }
    }
    
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
