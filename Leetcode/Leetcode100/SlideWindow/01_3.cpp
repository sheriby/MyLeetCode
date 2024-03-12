#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0, j = 0, ans = 0;
        vector<int> hash(128, -1);
        while (j < n) {
            if (hash[s[j]] != -1) i = max(hash[s[j]] + 1, i);
            hash[s[j]] = j;
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
