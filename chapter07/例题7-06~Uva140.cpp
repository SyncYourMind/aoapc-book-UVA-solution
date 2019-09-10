#include <bits/stdc++.h>
using namespace std;
map<char, vector<char>> graph;//存储每个结点的邻近结点
string input, ans;
void init() {//读取每个结点的邻近结点
    graph.clear();
    input += ';';//在字符串后添加一个分号
    for (int i = 0, j = 0; i < input.size(); i = j + 1) {//遍历输入的字符串
        j = input.find(';', i);//找到分号的位置
        for (char c : input.substr(i + 2, j - i - 2)) {//添加邻近结点
            graph[input[i]].push_back(c);
            graph[c].push_back(input[i]);
        }
    }
    input = "";
    for (auto& i : graph)//input存储排序后的所有结点编号
        input += i.first;
}
int main() {
    while (cin >> input && input != "#") {
        init();
        int width = INT_MAX;//存储最终的最小带宽
        do {
            unordered_map<char, int> position;//存储当前排列中每个结点的下标
            for (int i = 0; i < input.size(); ++i)
                position[input[i]] = i;
            int w = 0;
            for (auto& i : graph) {//遍历每个结点
                int wi = 0;
                for (char c : i.second)//遍历每个结点的邻近结点
                    wi = max(wi, abs(position[c] - position[i.first]));
                w = max(w, wi);//更新该结点的带宽
            }
            if (width > w) {//求解带宽最小的排列
                ans = input;
                width = w;
            }
        } while (next_permutation(input.begin(), input.end()));
        for (char c : ans)
            printf("%c ", c);
        printf("-> %d\n", width);
    }
    return 0;
}
