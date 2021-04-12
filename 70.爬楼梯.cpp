// https://leetcode-cn.com/problems/climbing-stairs/

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    // 递归法+备忘录:0ms,6.1M
    int climb(int n, vector<int>& visited)
    {
        if (visited[n] == 0) {
            visited[n] = climb(n - 1, visited) + climb(n - 2, visited);
        }

        return visited[n];
    }

    int climbStairs(int n) {
        vector<int> visited(n + 2, 0);
        visited[1] = 1;
        visited[2] = 2;
        return climb(n, visited);
    }
};

class Solution {
public:
    // dp table+备忘录:0ms, 6.1M
    int climbStairs(int n) {
        vector<int> dp(n + 2, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};