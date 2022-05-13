int root(int x) { // 11_1보다 속도 개선
    if (par[x] == -1) return x; // x가 루트라면 x를 반환
    else return par[x] = root(par[x]); // x의 부모 값인 par[x]를 root로 설정
}
