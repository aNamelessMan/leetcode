#include <bits/stdc++.h>

using namespace std;

// ...这题也不用双指针吧，遍历一遍遇到空格就输出换行就行了

int main() {
    string input;
    getline(cin, input);

    int n = input.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && input[j] != ' ') {
            j++;
        }
        while (i < j) {
            // i为每个单词的头部，j为每个单词的尾后
            // 每次循环时，头部是已知的，因此只需用j找到尾后
            // （空格 或 input.end(）)即可
            cout << input[i++];
        }
        cout << endl;
        i = j;
    }
}
