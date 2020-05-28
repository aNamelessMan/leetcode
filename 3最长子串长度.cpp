   /*
执行用时 :48 ms, 在所有 C++ 提交中击败了37.84% 的用户
内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
   #include<bits/stdc++.h>
   #include <string>
   #include <iostream>

   using namespace std;
    int lengthOfLongestSubstring(string s) {
        int bit[128];

        int max = 0;
        int count = 0;
        int l = s.length();
        int asc = -1;
        for(int i = 0;i < l;++i){

        for(int i = 0;i < 128;++i){
            bit[i] = 0;
        }
        count = 0;

            for(int j = i;j < l;++j){
                asc = s[j];
                if(bit[asc] == 1){
                    break;
                }else{
                    count++;
                    if(count > max)max = count;
                    bit[asc] = 1;
                }
            }
        }
        return max;
    }
    int main(){
        int l = lengthOfLongestSubstring(" ");
        cout << l << endl;
    }
