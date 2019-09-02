#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string s = "0123456789";
    unordered_map<int, vector<pair<int, int>>> ans;
    do {
        int a = stoi(s.substr(0, 5)), b = stoi(s.substr(5));
        if (a % b == 0)
            ans[a / b].push_back({a, b});
    } while (next_permutation(s.begin(), s.end()));
    for (int ii = 0; cin >> N && N != 0; ++ii) {
        printf("%s", ii > 0 ? "\n" : "");
        if (ans.find(N) == ans.end())
            printf("There are no solutions for %d.\n", N);
        else
            for (auto& i : ans[N])
                printf("%05d / %05d = %d\n", i.first, i.second, N);
    }
    return 0;
}
