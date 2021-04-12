#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

// 解答错误
class Solution {
public:
    unordered_set<string> getPar(int n) {
        unordered_set<string> res;
        if (n == 1) {
            res.insert("()");
            return res;
        }

        unordered_set<string> oldRes = getPar(n - 1);
        for (auto& it : oldRes) {
            res.insert(it + "()");
            res.insert("()" + it);
            res.insert("(" + it + ")");
        }
        return res;
    }

    vector<string> generateParenthesis(int n) {
        unordered_set<string> resSet = getPar(n);
        vector<string> resVct;
        resVct.insert(resVct.end(), resSet.begin(), resSet.end());
        return resVct;
    }
};
