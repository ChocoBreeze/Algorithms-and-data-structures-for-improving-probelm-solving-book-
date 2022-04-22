int root(int x) {
    if (par[x] == -1) return x; // x가 root이면 x를 반환
    else return root(par[x]); // x가 root가 아니라면 재귀적으로 부모 vertex으로 진행
}
