#include <bits/stdc++.h>
using namespace std;
unordered_set<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};//素数表
void f(int A[], int n, int index) {
    if (index == n + 1) {//边界条件
        if (prime.find(A[1] + A[n]) != prime.end()) {//A[n]+A[1]是素数
            for (int i = 1; i <= n; ++i)//输出
                printf("%d%s", A[i], i == n ? "" : " ");
            puts("");
        }
        return;
    }
    for (int i = 1; i <= n; ++i)//遍历数字1~n
        if (find(A + 1, A + index, i) == A + index && prime.find(A[index - 1] + i) != prime.end()) {//如果数字i没取过，且与邻近数字之和是素数
            A[index] = i;
            f(A, n, index + 1);//继续递归
        }
}
int main() {
    int n, A[20];
    for (int ii = 1; cin >> n; ++ii) {
        printf("%sCase %d:\n", ii > 1 ? "\n" : "", ii);
        iota(A, A + n + 1, 0);//将数组A值置位0~n
        f(A, n, 2);
    }
    return 0;
}
