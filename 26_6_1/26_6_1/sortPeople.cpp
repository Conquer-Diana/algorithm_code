#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

//按身高排序————这道题本身并没有体现贪心思想，只是其中的一个解法思想要在下一题《优势洗牌》中使用
//给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。
//
//对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。
//
//请按身高 降序 顺序返回对应的名字数组 names 。
//
//示例 1：
//输入：names = ["Mary", "John", "Emma"], heights = [180, 165, 170]
//输出：["Mary", "Emma", "John"]
//解释：Mary 最高，接着是 Emma 和 John 。
//
//示例 2：
//输入：names = ["Alice", "Bob", "Bob"], heights = [155, 185, 150]
//输出：["Bob", "Alice", "Bob"]
//解释：第一个 Bob 最高，然后是 Alice 和第二个 Bob 。
//
//提示：
//n == names.length == heights.length
//1 <= n <= 103
//1 <= names[i].length <= 20
//1 <= heights[i] <= 105
//names[i] 由大小写英文字母组成
//heights 中的所有值互不相同

//3种解法
//1.新创建vector<pair<int, string>>，然后按身高降序排序，最后按顺序提取出姓名即可
class Solution_1 {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> hash;
        int n = names.size();
        for (int i = 0; i < n; i++)
            hash.push_back({ heights[i],names[i] });

        sort(hash.begin(), hash.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
            });

        vector<string> ret;
        for (auto& c : hash)
            ret.push_back(c.second);

        return ret;
    }
};

//2.哈希表
//将身高姓名存入hash表，然后对身高数组单独排序，在hash表中按身高查找姓名即可
class Solution_2 {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int, string> hash;
        for (int i = 0; i < n; i++)
            hash[heights[i]] = names[i];

        sort(heights.begin(), heights.end(), greater<int>());

        vector<string> ret;
        for (auto h : heights)
            ret.push_back(hash[h]);

        return ret;
    }
};

//3.创建下标数组，然后用lamda表达式重写改变排序方法来排序下标，随后从排序好的下标数组中提取名字
//这种思想将要在下一题《优势洗牌》中使用
class Solution_3 {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> index(n);
        for (int i = 0; i < n; i++)
            index[i] = i;

        sort(index.begin(), index.end(), [&](int i, int j) {
            return heights[i] > heights[j];
            });

        vector<string> ret;
        for (int i = 0; i < n; i++)
            ret.push_back(names[index[i]]);

        return ret;
    }
};