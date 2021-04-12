// https://leetcode-cn.com/problems/climbing-stairs/

class Solution {
public:
    // 递归法+备忘录
    int climb(int n, unordered_map<int, int>& mp)
    {
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }

        int step1 = 0;
        if (mp.find(n - 1) != mp.end()) {
            step1 = mp[n - 1];
        } else {
            step1 = climb(n - 1, mp);
            mp[n - 1] = step1;
        }

        int step2 = 0;
        if (mp.find(n - 2) != mp.end()) {
            step2 = mp[n - 2];
        } else {
            step2 = climb(n - 2, mp);
            mp[n - 2] = step2;
        }

        return step1 + step2;
    }
    int climbStairs(int n) {
        unordered_map<int, int> mp;
        mp[1] = 1;
        mp[2] = 2;
        return climb(n, mp);
    }
};