#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len < 2) return len;

        int left = 0, right = 1, max_seq = 1;
        while (right < len) {
            bool find = false;
            for (int i = left; i < right; i++) {
                if (s[i] == s[right]) {
                    left = i + 1;
                    find = true;
                    break;
                }
            }
            if (!find) max_seq = max(max_seq, right - left + 1);
            right++;
        }
        return max_seq;
    }
};