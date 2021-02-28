#include <bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了97.26% 的用户
// 内存消耗：9.7 MB, 在所有 C++ 提交中击败了65.93%
//同LC54    代码有点繁琐，但是很好理解
void iter(vector<vector<int>>& matrix, int is, int js, int ir, int jr, vector<int> &res){
    int i = is, j = js;
    if(is == ir && js == jr){//只有一个元素
        res.push_back(matrix[is][js]);
        return;
    }else if(is == ir){//只有一行
        while(j <= jr){
            res.push_back(matrix[i][j]);
            j++;
        }
    }else if(js == jr){//只有一列
        while(i <= ir){
            res.push_back(matrix[i][j]);
            i++;
        }
    }else{//普通情况
        while(j < jr){
            res.push_back(matrix[i][j]);
            j++;
        }
        while(i < ir){
            res.push_back(matrix[i][j]);
            i++;
        }
        while(j > js){
            res.push_back(matrix[i][j]);;
            j--;
        }
        while(i > is){
            res.push_back(matrix[i][j]);
            i--;
        }
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    if(m == 0)return res;
    int n = matrix[0].size();
    int is = 0, js = 0, ir = m - 1, jr = n - 1;
    while(is <= ir && js <= jr){
        iter(matrix, is, js, ir, jr, res);
        is++; js++;
        ir--; jr--;
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}