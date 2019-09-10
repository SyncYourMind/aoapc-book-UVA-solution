#include <bits/stdc++.h>
using namespace std;
int n, l;
bool f(string& s) {//回溯
    if (n == 0)//n为0时表示找到了结果，返回true
        return true;
    for (int i = 0; i < l; ++i) {//枚举'A'到'A'+L字符
        s += 'A' + i;
        //从后向前查找与最新加入的字符相同的字符
        for (int j = s.rfind('A' + i, s.size() - 2); j >= s.size() - 2 - j && j != string::npos; j = s.rfind('A' + i, j - 1))
            if (s.substr(j + 1) == s.substr(j + j + 2 - s.size(), s.size() - 1 - j))//出现了重复的子串
                goto loop;//删去最后的字符
        --n;
        if (f(s))//处理下个位置
            return true;
    loop:
        s.pop_back();
    }
    return false;
}
int main() {
    while (cin >> n >> l && n != 0) {
        string s = "";
        f(s);
        for (int i = 0, group = 0; i < s.size(); ++i) {//group表示组号
            if (i != 0 && i % 4 == 0)
                putchar((++group) % 16 == 0 ? '\n' : ' ');
            putchar(s[i]);
        }
        printf("\n%d\n", s.size());
    }
    return 0;
}
