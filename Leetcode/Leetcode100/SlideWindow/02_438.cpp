#include <algorithm>
#include <iostream>
#include <vector>
#define Int(x) x - 'a'
using namespace std;

class Solution {
   public:
    // abaacbabc abc
    vector<int> findAnagrams(string s, string p) {
        int len = s.size(), sublen = p.size();
        vector<int> res;
        int map[26] = {0};
        for (int i = 0; i < sublen; i++) map[Int(p[i])]++;

        int start = -1, r = 0;
        while (r < len) {
            if (map[Int(s[r])]) {
                map[Int(s[r])]--;
                if (start == -1) start = r;

                if (allZero(map, sublen)) {
                    res.push_back(start);
                    map[Int(s[start])]++;
                    if (sublen > 1)
                        start++;
                    else
                        start = -1;
                }
                r++;
            } else {
                if (start == -1) {
                    r++;
                    continue;
                }
                while (start < r) {
                    map[Int(s[start])]++;
                    if (s[start++] == s[r]) break;
                                }
                if (!map[Int(s[r])]) {
                    start = -1;
                    r++;
                }
            }
        }
        return res;
    }

   private:
    bool allZero(int* arr, int len) {
        for (int i = 0; i < len; i++)
            if (arr[i]) return false;
        return true;
    }
};