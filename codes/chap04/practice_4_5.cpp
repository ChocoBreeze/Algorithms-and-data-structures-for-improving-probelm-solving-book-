// 10진수 표기로 각 자리 수가 7, 5, 3 중 하나이고 7, 5, 3이 모두 한 번은 등장하는 정수를 753수라 부르기로 하자.
// 양의 정수 K가 주어졌을 때, K 이하의 753수가 몇 개 존재하는지 구하는 알고리즘을 설계하라(K의 자리수를 d라 할 때, 최대 허용 범위 : O(3^d))
// N: 입력
// cur: 현재 값
// use: 7, 5, 3 중 어느 것을 썼는지
// counter: 개수 세기
void func(long long N, long long cur, int use, long long &counter){
    if (cur > N) return; // base case
    if (use == 0b111) ++counter;

    // 7 붙이기
    func(N, cur * 10 + 7, use | 0b001, counter);

    // 5 붙이기
    func(N, cur * 10 + 5, use | 0b010, counter);

    // 3 붙이기
    func(N, cur * 10 + 3, use | 0b100, counter);
}

int main() {
    long long N;
    cin >> N;
    long long counter = 0;
    func(N, 0, 0, counter);
    cout << counter << endl;
}
