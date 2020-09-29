#include "headers.h"

///*
//3. 无重复字符的最长子串
//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//示例 1:
//输入: "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//
//示例 2:
//输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//
//示例 3:
//输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//
//思路：滑动窗口法
//*/
//int lengthOfLongestSubstring(const string &s) {
//    int length = s.size();
//    if (length < 2)
//        return length;
//
//    vector<int> chr_cnt(256, 0);
//    int start = 0, stop = 1; // 滑动窗口的开头和结尾
//    ++chr_cnt[s[start]];
//    int res = 1;
//    while (stop < length) {
//        ++chr_cnt[s[stop]];
//        while (chr_cnt[s[stop]] > 1) // 当窗口内的字符出现重复时，右滑开头
//        {
//            --chr_cnt[s[start]];
//            ++start;
//        }
//        res = std::max(res, stop - start + 1);
//        ++stop;
//    }
//    return res;
//}

// // 最长回文子串（动态规划）
// string longestPalindromeDP(const string &s)
// {
//     int maxl = 1, start = 0;
//     int sz = s.length();
//     bool dp[1005][1005];
//     memset(dp, 0, sizeof(bool) * 1005 * 1005);
//     for (int i = 0; i < sz; i++)
//     {
//         dp[i][i] = 1;
//     }
//     int i, j;
//     for (i = 1; i < sz; i++)
//     {
//         for (j = 0; j + i < sz; j++)
//         {
//             if (i == 1)
//             {
//                 if (s[j] == s[j + 1])
//                 {
//                     dp[j][j + i] = 1;
//                     if (i + 1 > maxl)
//                     {
//                         maxl = i + 1;
//                         start = j;
//                     }
//                 }
//             }
//             else
//             {
//                 if (dp[j + 1][j + i - 1] && s[j] == s[j + i])
//                 {
//                     dp[j][j + i] = 1;
//                     if (i + 1 > maxl)
//                     {
//                         maxl = i + 1;
//                         start = j;
//                     }
//                 }
//             }
//         }
//     }
//     return s.substr(start, maxl);
// }

// // 最长回文子串（中心拓展法）
// string longestPalindrome(const string &s)
// {
//     static auto expandFromCenter = [](const string &s, int center1, int center2) -> int {
//         int l = center1, r = center2;
//         int sz = s.length();
//         while (l >= 0 && r < sz && s[l] == s[r])
//         {
//             l--;
//             r++;
//         }
//         return r - l - 1;
//     };

//     int start = 0, tlen = 0;
//     for (int i = 0, sz = s.length(); i < sz; i++)
//     {
//         int len1 = expandFromCenter(s, i, i);
//         int len2 = expandFromCenter(s, i, i + 1);
//         int len = (len1 > len2) ? len1 : len2;
//         if (len > tlen)
//         {
//             tlen = len;
//             if (len % 2 == 0)
//             {
//                 start = i - (len / 2 - 1);
//             }
//             else
//             {
//                 start = i - len / 2;
//             }
//         }
//     }
//     return s.substr(start, tlen);
// }

// //将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：
// //P   A   H   N
// //A P L S I I G
// //Y   I   R
// //之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"
// string convert(const string &s, int numRows)
// {
//     if (s.length() == numRows || numRows == 1)
//         return s;
//     if (numRows == 2)
//     {
//         ostringstream oss1, oss2;
//         for (int i = 0, sz = s.length(); i < sz; i++)
//         {
//             if (i % 2 == 0)
//                 oss1 << s[i];
//             else
//                 oss2 << s[i];
//         }
//         string res;
//         res += oss1.str();
//         res += oss2.str();
//         return res;
//     }
//     vector<ostringstream *> svec;
//     for (int i = 0; i < numRows; i++)
//     {
//         svec.push_back(new ostringstream());
//     }
//     vector<ostringstream *> rsvec;
//     for (int i = svec.size() - 2; i > 0; i--)
//     {
//         rsvec.push_back(svec[i]);
//     }
//     int one_z = 2 * numRows - 2;
//     int pos = 0;
//     string one, left;
//     int tail = -1;
//     for (int i = 0, sz = s.length(); i < sz; i = i + one_z)
//     {
//         if (i + one_z > sz)
//         {
//             tail = i;
//             break;
//         }
//         one = s.substr(i, one_z);
//         left = one.substr(numRows);
//         for (int j = 0; j < numRows; j++)
//         {
//             (*(svec[j])) << one[j];
//         }
//         for (int k = 0, leftsz = left.length(); k < leftsz; k++)
//         {
//             (*(rsvec[k])) << left[k];
//         }
//     }
//     if (tail != -1)
//     {
//         one = s.substr(tail);
//         if (one.length() > numRows)
//         {
//             left = one.substr(numRows);
//             for (int j = 0; j < numRows; j++)
//             {
//                 (*(svec[j])) << one[j];
//             }
//             for (int k = 0, leftsz = left.length(); k < leftsz; k++)
//             {
//                 (*(rsvec[k])) << left[k];
//             }
//         }
//         else
//         {
//             for (int j = 0; j < one.length(); j++)
//             {
//                 (*(svec[j])) << one[j];
//             }
//         }
//     }
//     string res;
//     for (auto oss : svec)
//     {
//         res += (*oss).str();
//         delete oss;
//     }
//     return res;
// }

// int my_atoi(const string &str)
// {
//     auto is_num = [](char ch) -> bool {
//         if (ch - '0' >= 0 && ch - '0' <= 9)
//             return true;
//         else
//             return false;
//     };

//     if (str.length() == 0) // 长度为0
//         return 0;
//     int i;
//     for (i = 0; i < str.length(); i++) // 找到第一个非空字符
//     {
//         if (str[i] != ' ')
//             break;
//     }
//     if (i == str.length()) // 都是空格
//         return 0;
//     if (str[i] != '+' && str[i] != '-') // 第一个非空字符不是数字或正负号
//         if (!is_num(str[i]))
//             return 0;
//     int res = 0;
//     bool isNe = false;
//     if (str[i] == '-') // 第一个非空字符是负号
//     {
//         isNe = true;
//         i++;
//     }
//     else if (str[i] == '+') // 第一个字符是正号
//     {
//         i++;
//     }
//     if (i >= str.length() || !is_num(str[i])) // 正负号后面无字符或不是数字
//         return 0;
//     int next_num = 0;
//     for (; i < str.length(); i++)
//     {
//         if (!is_num(str[i]))
//             break;
//         else
//         {
//             next_num = str[i] - '0';
//             if (res > INT_MAX / 10) // res = res * 10 + next_num > INT_MAX => res > (INT_MAX - next_num) / 10 => res > INT_MAX / 10
//             {
//                 return isNe ? INT_MIN : INT_MAX;
//             }
//             else if (res == INT_MAX / 10)
//             {
//                 if (!isNe)
//                 {
//                     if (next_num > 7 || (i + 1 < str.length() && is_num(str[i + 1])))
//                         return INT_MAX;
//                     else // 正数不超过INT_MAX
//                         return res * 10 + next_num;
//                 }
//                 else
//                 {
//                     if (str[i] - '0' > 8 || (i + 1 < str.length() && is_num(str[i + 1])))
//                         return INT_MIN;
//                     else // 负数不超过INT_MIN
//                         return 0 - res * 10 - next_num;
//                 }
//             }
//             res = res * 10 + next_num;
//         }
//     }
//     return isNe ? -res : res;
// }

// bool isMatch(const string &s, const string &p)
// {
//     auto isNum = [](char ch) -> bool {
//         if (ch >= 'a' && ch <= 'z')
//             return true;
//         else
//             return false;
//     };

//     if (s.length() == 0 && p.length() != 0 || s.length() != 0 && p.length() == 0)
//         return false;
//     else if (s.length() == 0 && p.length() == 0)
//         return true;
//     int si = 0, pi = 0;
//     char ppre = '\0', scur = '\0', pcur = '\0';
//     while (si < s.length() && pi < p.length())
//     {
//         scur = s[si];
//         ppre = pcur;
//         pcur = p[pi];
//         if (isNum(pcur) && pi + 1 < p.length() && p[pi + 1] != '*' || isNum(pcur) && pi + 1 >= p.length())
//         {
//             if (pcur != scur)
//                 return false;
//             si++;
//             pi++;
//         }
//         else if (isNum(pcur) && pi + 1 < p.length() && p[pi + 1] == '*')
//         {
//             if (pcur != scur)
//                 pi += 2;
//             else
//             {
//                 si++;
//                 pi++;
//             }
//         }
//         else if (pcur == '.')
//         {
//             si++;
//             pi++;
//         }
//         else if (pcur == '*')
//         {
//             if (scur == ppre || ppre == '.')
//                 si++;
//             else
//             {
//                 pi++;
//             }
//         }
//     }
//     if (si == s.length() && pi == p.length() || si == s.length() && pi + 1 == p.length() && p[pi] == '*')
//         return true;
//     return false;
// }

// bool isMatchRE(const string &s, const string &p)
// {
//     regex r(p);
//     return regex_match(s, r);
// }

// bool isMatchRecursive(string s, string p)
// {
//     // case 1：p为空
//     if (p.empty())
//         return s.empty();
//     // case 2：p长度为1
//     if (p.length() == 1)
//         return (s.length() == 1) && (s[0] == p[0] || p[0] == '.');
//     // case 3：p的第二个字符不为*
//     if (p[1] != '*')
//     {
//         if (s.empty())
//             return false;
//         return (p[0] == s[0] || p[0] == '.') && isMatchRecursive(s.substr(1), p.substr(1));
//     }
//     // case 4：p的第二个字符为*，第一个字符和s的第一个匹配
//     while (!s.empty() && (p[0] == s[0] || p[0] == '.'))
//     {
//         if (isMatchRecursive(s, p.substr(2)))
//             return true;
//         s = s.substr(1);
//     }
//     // case 5：p的第二个字符为*，但是第一个字符和s的第一个不匹配
//     return isMatchRecursive(s, p.substr(2));
// }

// bool isMatchRecursiveConcise(string s, string p)
// {
//     // case 1：p为空
//     if (p.empty())
//         return s.empty();
//     // case 2：p的第二个字符为*
//     if (p.length() > 1 && p[1] == '*')
//     {
//         return isMatchRecursiveConcise(s, p.substr(2)) || (!p.empty() && (p[0] == s[0] || p[0] == '.') && isMatchRecursiveConcise(s.substr(1), p));
//     }
//     // case 3：p的第二个字符不为*
//     else
//     {
//         return !p.empty() && (p[0] == s[0] || p[0] == '.') && isMatchRecursiveConcise(s.substr(1), p.substr(1));
//     }
// }

// bool isMatchDP(string s, string p)
// {
//     /*
//     sp[i][j]代表s[0:i)与p[0:j)匹配：
//     1.sp[i][j]=sp[i-1][j-1],当s[i-1]==p[j-1]||p[j-1]=='.';
//     2.sp[i][j]=sp[i][j-2],当p[j-1]=='*'，并且重复0次时；
//     3.sp[i][j]=sp[i-1][j],当s[i-1]==p[j-2]||p[j-2]=='.'，p[j-1]=='*'，并且重复一次以上时
//     */
//     int m = s.size(), n = p.size();
//     vector<vector<bool>> sp(m + 1, vector<bool>(n + 1, false));
//     sp[0][0] = true;
//     for (int i = 0; i <= m; ++i)
//     {
//         for (int j = 1; j <= n; ++j)
//         {
//             if (j > 1 && p[j - 1] == '*')
//             {
//                 sp[i][j] = sp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && sp[i - 1][j]);
//             }
//             else
//             {
//                 sp[i][j] = i > 0 && sp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//             }
//         }
//     }
//     return sp[m][n];
// }

// int romanToInt(const string &s)
// {
//     unordered_map<char, int> um;
//     um['I'] = 1;
//     um['V'] = 5;
//     um['X'] = 10;
//     um['L'] = 50;
//     um['C'] = 100;
//     um['D'] = 500;
//     um['M'] = 1000;

//     char cur = '\0', next = '\0';
//     int res = 0, t = 0;
//     for (int i = 0; i < s.length();)
//     {
//         cur = s[i];
//         if (i + 1 < s.length())
//             next = s[i + 1];
//         else
//             next = '\0';
//         if (cur == 'I' && next == 'V')
//         {
//             t = 4;
//             i += 2;
//         }
//         else if (cur == 'I' && next == 'X')
//         {
//             t = 9;
//             i += 2;
//         }
//         else if (cur == 'X' && next == 'L')
//         {
//             t = 40;
//             i += 2;
//         }
//         else if (cur == 'X' && next == 'C')
//         {
//             t = 90;
//             i += 2;
//         }
//         else if (cur == 'C' && next == 'D')
//         {
//             t = 400;
//             i += 2;
//         }
//         else if (cur == 'C' && next == 'M')
//         {
//             t = 900;
//             i += 2;
//         }
//         else
//         {
//             t = um[cur];
//             i++;
//         }
//         res += t;
//     }
//     return res;
// }

// vector<vector<int>> threeSum(vector<int> nums)
// {
//     auto isDu = [](vector<int> l, vector<int> &r) -> bool {
//         for (auto &num : r)
//         {
//             auto iter = std::find(std::begin(l), std::end(l), num);
//             if (iter == std::end(l))
//                 return false;
//             else
//                 l.erase(iter);
//         }
//         return true;
//     };

//     int i, j, k, len = nums.size();
//     vector<vector<int>> res;
//     for (i = 0; i < len; i++)
//     {
//         for (j = i + 1; j < len; j++)
//         {
//             for (k = j + 1; k < len; k++)
//             {
//                 if (nums[i] + nums[j] + nums[k] == 0)
//                 {
//                     bool isC = false;
//                     vector<int> t = {nums[i], nums[j], nums[k]};
//                     for (auto &item : res)
//                     {
//                         if (isDu(item, t))
//                         {
//                             isC = true;
//                             break;
//                         }
//                     }
//                     if (!isC)
//                         res.push_back(t);
//                 }
//             }
//         }
//     }
//     return res;
// }

// vector<vector<int>> threeSumBetter(vector<int> nums)
// {
//     vector<vector<int>> res;
//     std::sort(nums.begin(), nums.end());  // 无序变有序
//     for (int i = 0; i < nums.size(); i++) // 固定一个数
//     {
//         if (nums[i] > 0) // 意味着后面的数都是正数，不可能和为零了
//             break;
//         if (i > 0 && nums[i - 1] == nums[i]) // 相同的数不固定两次
//             continue;
//         int target = 0 - nums[i];
//         int b = i + 1, e = nums.size() - 1;
//         while (b < e) // 双指针法
//         {
//             if (nums[b] + nums[e] == target)
//             {
//                 res.push_back({nums[i], nums[b], nums[e]});
//                 // 跳过重复的数
//                 while (b < e && nums[b] == nums[b + 1])
//                     ++b;
//                 while (b < e && nums[e] == nums[e - 1])
//                     --e;
//                 ++b;
//                 --e;
//             }
//             else if (nums[b] + nums[e] < target) // 比目标数小，增大左指针
//                 ++b;
//             else // 比目标数大，减小右指针
//                 --e;
//         }
//     }
//     return res;
// }

// int threeSumClosest(vector<int> nums, int target)
// {
//     int curr_closet = INT_MAX;
//     int temp = 0;
//     std::sort(nums.begin(), nums.end());  // 无序变有序
//     for (int i = 0; i < nums.size(); i++) // 固定一个数
//     {
//         if (i > 0 && nums[i - 1] == nums[i]) // 相同的数不固定两次
//             continue;
//         int tar = target - nums[i];
//         int b = i + 1, e = nums.size() - 1;
//         while (b < e) // 双指针法
//         {
//             temp = nums[b] + nums[e];
//             if (nums[b] + nums[e] == tar)
//             {
//                 return target;
//             }
//             else if (nums[b] + nums[e] < tar) // 比目标数小，增大左指针
//             {
//                 ++b;
//             }
//             else // 比目标数大，减小右指针
//             {
//                 --e;
//             }
//             if (curr_closet == INT_MAX || std::abs(curr_closet - target) > std::abs(temp + nums[i] - target))
//                 curr_closet = temp + nums[i];
//         }
//     }
//     return curr_closet;
// }

// string intToRoman(int num)
// {
//     map<int, string> irmap = {
//         {1, "I"},
//         {4, "IV"},
//         {5, "V"},
//         {9, "IX"},
//         {10, "X"},
//         {40, "XL"},
//         {50, "L"},
//         {90, "XC"},
//         {100, "C"},
//         {400, "CD"},
//         {500, "D"},
//         {900, "CM"},
//         {1000, "M"}};
//     /*for (auto &item : irmap)
//     {
//       cout << item.first << " " << item.second << endl;
//     }
//     return "";*/
//     /*for (auto b = irmap.rbegin(), e = irmap.rend(); b != e; b++)
//     {
//       cout << b->first << " " << b->second << endl;
//     }
//     return "";*/
//     string res;
//     int i = 0, temp = 0;
//     for (auto b = irmap.rbegin(), e = irmap.rend(); b != e; b++)
//     {
//         if ((temp = num / (b->first)) > 0)
//         {
//             for (i = 0; i < temp; i++)
//             {
//                 res.append(b->second);
//             }
//             num %= b->first;
//         }
//     }
//     return res;
// }

// void letterCombinationsDFS(const string &digits, string d2l[], int level, string &out, vector<string> &res)
// {
//     if (level == digits.length())
//         res.push_back(out);
//     else
//     {
//         for (auto &c : d2l[digits[level] - '0'])
//         {
//             out.push_back(c);
//             letterCombinationsDFS(digits, d2l, level + 1, out, res);
//             out.pop_back();
//         }
//     }
// }

// vector<string> letterCombinations(string digits)
// {
//     string d2l[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//     vector<string> res;
//     if (digits.empty())
//         return res;
//     string out;
//     letterCombinationsDFS(digits, d2l, 0, out, res);
//     return res;
// }

// vector<vector<int>> fourSum(vector<int> &nums, int target)
// {
//     vector<vector<int>> res;
//     if (nums.size() < 4)
//         return res;
//     if (nums.size() == 4)
//     {
//         if (std::accumulate(nums.begin(), nums.end(), 0) == target)
//         {
//             res.push_back(nums);
//         }
//         return res;
//     }
//     std::sort(nums.begin(), nums.end());
//     int target_t, b, e;
//     for (int i = 0; i < nums.size() - 3; i++) // 固定一个数
//     {
//         if (i > 0 && nums[i] == nums[i - 1]) // 相同数去重
//             continue;
//         // 由于是有序，加上最后三个数还小于target，说明当前数太小
//         if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target)
//             continue;
//         // 由于是有序，连续四个数都大于target，说明当前数后面的数的和都大于target
//         if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
//             break;
//         for (int j = i + 1; j < nums.size() - 2; j++) // 固定第二个数
//         {
//             if (j > i + 1 && nums[j] == nums[j - 1]) // 相同数去重
//                 continue;
//             // 由于是有序，固定的两个数加上最后两个数还小于target，说明当前数太小
//             if (nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2] < target)
//                 continue;
//             // 由于是有序，连续四个数都大于target，说明当前数后面的数的和都大于target
//             if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
//                 break;
//             target_t = target - nums[i] - nums[j];
//             b = j + 1;
//             e = nums.size() - 1;
//             while (b < e) // 双指针法
//             {
//                 if (nums[b] + nums[e] == target_t)
//                 {
//                     res.push_back({nums[i], nums[j], nums[b], nums[e]});
//                     while (b < e && nums[b] == nums[b + 1])
//                         b++;
//                     while (b < e && nums[e] == nums[e - 1])
//                         e--;
//                     b++;
//                     e--;
//                 }
//                 else if (nums[b] + nums[e] < target_t)
//                     b++;
//                 else
//                     e--;
//             }
//         }
//     }
//     return res;
// }

// void generateParenthesisDFS(int left, int right, string s, vector<string> &res)
// {
//     if (left == 0 && right == 0)
//         res.push_back(s);
//     else if (left > right)
//         return;
//     else
//     {
//         if (left > 0)
//             generateParenthesisDFS(left - 1, right, s + "(", res);
//         if (right > 0)
//             generateParenthesisDFS(left, right - 1, s + ")", res);
//     }
// }

// vector<string> generateParenthesis(int n)
// {
//     /*
//     给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//     例如，给出 n = 3，生成结果为：
//     [
//       "((()))",
//       "(()())",
//       "(())()",
//       "()(())",
//       "()()()"
//     ]
//     */
//     vector<string> res;
//     generateParenthesisDFS(n, n, "", res);
//     return res;
// }

// ListNode *mergeKLists(vector<ListNode *> &lists)
// {
//     /*
//     合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//     示例:
//     输入:
//     [
//       1->4->5,
//       1->3->4,
//       2->6
//     ]
//     输出: 1->1->2->3->4->4->5->6
//     */
//     auto cmp = [](ListNode *a, ListNode *b) -> bool {
//         return a->val > b->val;
//     };

//     ListNode *head = new ListNode(0); // 多余节点，用作头结点，最后删除
//     ListNode *node = head, *temp = nullptr;
//     // 优先队列，优先级高的先出队列，使用"<"比较，默认升序，即顶部为最大值，使用泛型<存储类型，底层容器，比较函数类型>自定义比较方式
//     priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> qu(cmp);
//     for (auto &list : lists)
//     {
//         if (list != nullptr)
//             qu.push(list);
//     }
//     while (!qu.empty())
//     {
//         temp = qu.top();
//         qu.pop();
//         if (temp->next)
//             qu.push(temp->next);
//         node->next = temp;
//         node = node->next;
//     }
//     node->next = nullptr;
//     temp = head->next;
//     delete head;
//     return temp;
// }

// int divide(int dividend, int divisor)
// {
//     /*
//     给定两个整数，被除数 dividend 和除数 divisor。
//     将两数相除，要求不使用乘法、除法和 mod 运算符。
//     返回被除数 dividend 除以除数 divisor 得到的商。
//     1.被除数和除数均为 32 位有符号整数。
//     2.除数不为 0。
//     3.假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
//     */

//     if (divisor == 1)
//         return dividend;
//     // 当被除数为INT_MIN，除数为-1时，结果为INT_MAX+1，溢出
//     if (divisor == -1)
//     {
//         if (dividend == INT_MIN)
//             return INT_MAX;
//         else
//             return 0 - dividend;
//     }
//     long long ddd = dividend;
//     long long ds = divisor;
//     bool isPos = true;
//     if (ddd < 0)
//     {
//         ddd = 0 - ddd;
//         if (ds < 0)
//             ds = 0 - ds;
//         else
//             isPos = false;
//     }
//     else
//     {
//         if (ds < 0)
//         {
//             ds = 0 - ds;
//             isPos = false;
//         }
//     }
//     long long res = 0, cnt, temp;
//     // 左移除数n位，直到找到不大于被除数的最大数m，则说明被除数至少包含2^n个除数，然后减去这个m，继续上述流程
//     while (ds <= ddd)
//     {
//         cnt = 1;
//         temp = ds;
//         while (temp <= ddd)
//         {
//             temp = temp << 1;
//             cnt = cnt << 1;
//         }
//         res += (cnt >> 1);
//         ddd -= (temp >> 1);
//     }
//     return isPos ? static_cast<int>(res) : (0 - static_cast<int>(res));
// }

// void findSubstringDFS(vector<string> &words, string s, vector<string> &res)
// {
//     if (words.empty())
//         res.push_back(s);
//     /*vector<string> temp = words;
//     for (int i = 0; i < words.size(); i++)
//     {
//       temp.erase(temp.begin() + i);
//       findSubstringDFS(temp, s + words[i], res);
//       temp.insert(temp.begin() + i, words[i]);
//     }*/
//     string t;
//     for (int i = 0; i < words.size(); i++)
//     {
//         t = words[i];
//         words.erase(words.begin() + i);
//         findSubstringDFS(words, s + t, res);
//         words.insert(words.begin() + i, t);
//     }
// }

// vector<string> findSubstringDFS(vector<string> &words)
// {
//     set<string> res;
//     vector<int> t;
//     for (int i = 0; i < words.size(); i++)
//     {
//         t.push_back(i);
//     }
//     string s;
//     do
//     {
//         for (auto &i : t)
//             s.append(words[i]);
//         res.insert(s);
//         s.clear();
//     } while (next_permutation(t.begin(), t.end()));
//     return vector<string>(res.begin(), res.end());
// }

// vector<int> findSubstring(string s, vector<string> &words)
// {
//     /*
//     给定一个字符串 s 和一些长度相同的单词 words。在 s 中找出可以恰好串联 words 中所有单词的子串的起始位置。
//     注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
//     示例 1:
//     输入:
//     s = "barfoothefoobarman",
//     words = ["foo","bar"]
//     输出: [0,9]
//     解释: 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
//     输出的顺序不重要, [9,0] 也是有效答案。
//     示例 2:
//     输入:
//     s = "wordgoodstudentgoodword",
//     words = ["word","student"]
//     输出: []
//     */

//     /*vector<string> res;
//     findSubstringDFS(words, "", res);*/
//     if (s.empty() || words.empty())
//         return vector<int>();
//     vector<string> res = findSubstringDFS(words);
//     set<int> t;
//     for (auto &si : res)
//     {
//         string st = s;
//         int pre = 0;
//         while (true)
//         {
//             auto pos = st.find(si);
//             if (pos != string::npos)
//                 t.insert(pre + pos);
//             else
//                 break;
//             st = st.substr(pos + 1);
//             pre = pre + pos + 1;
//         }
//     }
//     return vector<int>(t.begin(), t.end());
// }

// vector<int> findSubstringBetter(const string s, const vector<string> &words)
// {
//     vector<int> res;
//     if (s.empty() || words.empty())
//         return res;
//     // 用于记下words中单词及其对应个数
//     unordered_map<string, int> wm1;
//     for (auto &word : words)
//         wm1[word]++;
//     int n = words.size(), sz = words[0].size();
//     // 逐个字符扫描，以当前字符开始的子序列是否符合要求
//     for (int i = 0, slen = s.size(); i <= slen - n * sz; i++)
//     {
//         int j = 0;
//         // 用于记录当前子序列的单词匹配情况
//         unordered_map<string, int> wm2;
//         // 共需要判断words.size()个单词
//         for (; j < n; j++)
//         {
//             // 取一个单词
//             string t = s.substr(i + j * sz, sz);
//             // 不属于words，则停止
//             if (wm1.find(t) == wm1.end())
//                 break;
//             wm2[t]++;
//             // 属于words但是多了，也停止
//             if (wm2[t] > wm1[t])
//                 break;
//         }
//         // 当前子序列刚好是words的一个串联
//         if (j == n)
//             res.push_back(i);
//     }
//     return res;
// }

// vector<int> findSubstringLinear(const string s, const vector<string> &words)
// {
//     vector<int> res;
//     if (s.empty() || words.empty())
//         return res;
//     // 用于记下words中单词及其对应个数
//     unordered_map<string, int> wm1;
//     for (auto &word : words)
//         wm1[word]++;
//     int cnt = words.size(), sz = words[0].size(), slen = s.size();
//     /*
//     逐个单词扫描：
//     0, sz, 2*sz, 3*sz...
//     1, 1+sz, 1+2*sz...
//     ...
//     sz-1, sz-1+sz...
//     然后采用类似滑动窗口机制，left为窗口左边界，窗口内含至多words.size()个单词，
//     当窗口内不匹配时，滑动left一个单词位，继续往下匹配
//     */
//     for (int i = 0; i < sz; i++)
//     {
//         int left = i, count = 0; // 左边界，已匹配个数
//         // 用于记录单词序列的匹配情况
//         unordered_map<string, int> wm2;
//         // 逐个单词扫描
//         for (int j = i; j <= slen - sz; j += sz)
//         {
//             string t = s.substr(j, sz); // 取一个单词
//             if (wm1.count(t))           // 匹配上了
//             {
//                 wm2[t]++;
//                 if (wm2[t] <= wm1[t]) // 不超过wm1中对应单词个数，已匹配个数加一
//                     count++;
//                 else // 否则，left向右滑动一个单词位，直到不超过wm1中对应单词个数
//                 {
//                     while (wm2[t] > wm1[t])
//                     {
//                         string left_str = s.substr(left, sz); // 取窗口最左单词，移出窗口
//                         wm2[left_str]--;
//                         if (wm2[left_str] < wm1[left_str]) // 说明移出的单词导致已匹配的单词个数减少
//                             count--;
//                         left += sz; // 窗口向右滑动一个单词位
//                     }
//                 }
//                 // 完全匹配上了
//                 if (count == cnt)
//                 {
//                     res.push_back(left);
//                     // left向右滑动一个单词位
//                     wm2[s.substr(left, sz)]--;
//                     count--;
//                     left += sz;
//                 }
//             }
//             else // 没有匹配上，说明中间出现不属于words的单词，导致中断匹配，所以窗口重置为中断单词的下一个单词开始
//             {
//                 wm2.clear();
//                 count = 0;
//                 left = j + sz;
//             }
//         }
//     }
//     return res;
// }

// int longestValidParentheses(const string &s)
// {
//     /*
//     给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

//     示例 1:
//     输入: "(()"
//     输出: 2
//     解释: 最长有效括号子串为 "()"

//     示例 2:
//     输入: ")()())"
//     输出: 4
//     解释: 最长有效括号子串为 "()()"
//     */

//     int res = 0, start = 0;
//     stack<int> st;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '(')
//             st.push(i);
//         else if (s[i] == ')')
//         {
//             if (st.empty())
//                 start = i + 1;
//             else
//             {
//                 st.pop();
//                 res = st.empty() ? std::max(res, i - start + 1) : std::max(res, i - st.top());
//             }
//         }
//     }
//     return res;
// }

// int longestValidParenthesesDP(const string &s)
// {
//     if (s.size() < 2)
//         return 0;
//     // dp[i]表示刚好在s[i]以前（包括s[i]在内）的最长括号长度
//     vector<int> dp(s.size(), 0);
//     for (int i = 1; i < s.size(); i++)
//     {
//         // 如果s[i]=='('，则dp[i]=0，因为若字符串是以左括号结束，则不可能为有效的

//         // 1.形如“...()”时，i的前一个点i-1匹配：
//         if (s[i] == ')' && s[i - 1] == '(' && i - 2 >= 0)
//             dp[i] = dp[i - 2] + 2;
//         // 2.形如“(...)”时，i的对称点i-dp[i-1]-1匹配：
//         else if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(')
//         {
//             dp[i] = dp[i - 1] + 2;
//             // 对称点之前还有长度
//             if (i - dp[i - 1] - 2 >= 0)
//                 dp[i] += dp[i - dp[i - 1] - 2];
//         }
//     }
//     int res = 0;
//     for (const auto &i : dp)
//     {
//         if (i > res)
//             res = i;
//     }
//     return res;
// }

// int search(vector<int> &nums, int target)
// {
//     /*
//     假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//     (例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//     搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//     你可以假设数组中不存在重复的元素。
//     你的算法时间复杂度必须是 O(logn) 级别。
//     示例 1:
//     输入: nums = [4,5,6,7,0,1,2], target = 0
//     输出: 4
//     示例 2:
//     输入: nums = [4,5,6,7,0,1,2], target = 3
//     输出: -1
//     */
//     if (nums.size() < 1)
//         return -1;
//     if (nums.size() == 1)
//     {
//         if (nums[0] == target)
//             return 0;
//         return -1;
//     }
//     int start = 0, end = nums.size() - 1;
//     int middle;
//     // 旋转之后，变成两个递增序列，分别在另个序列中使用二分搜索
//     while (start <= end)
//     {
//         middle = start + (end - start) / 2;
//         if (nums[middle] == target)
//             return middle;
//         // 说明start，middle属于同一递增序列
//         if (nums[start] <= nums[middle])
//         {
//             if (nums[start] <= target && nums[middle] > target)
//                 end = middle - 1;
//             else
//                 start = middle + 1;
//         }
//         // 说明middle，end属于同一递增序列
//         else
//         {
//             if (nums[middle] < target && nums[end] >= target)
//                 start = middle + 1;
//             else
//                 end = middle - 1;
//         }
//     }
//     return -1;
// }

// vector<int> searchRange(vector<int> &nums, int target)
// {
//     /*
//     类似std::equal_range

//     给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//     你的算法时间复杂度必须是 O(log n) 级别。
//     如果数组中不存在目标值，返回 [-1, -1]。
//     示例 1:
//     输入: nums = [5,7,7,8,8,10], target = 8
//     输出: [3,4]
//     示例 2:
//     输入: nums = [5,7,7,8,8,10], target = 6
//     输出: [-1,-1]
//     */
//     int len = nums.size();
//     int b = 0, e = len - 1, m;
//     int start = len;
//     // 寻找开始位置
//     while (b <= e)
//     {
//         m = (b + e) / 2;
//         if (nums[m] < target)
//         {
//             b = b + 1;
//         }
//         else
//         {
//             if (nums[m] == target && m < start)
//                 start = m;
//             e = m - 1;
//         }
//     }
//     int end = -1;
//     b = 0, e = len - 1;
//     // 寻找结束位置
//     while (b <= e)
//     {
//         m = (b + e) / 2;
//         if (nums[m] < target)
//         {
//             b = b + 1;
//         }
//         else
//         {
//             if (nums[m] == target && m > end)
//             {
//                 end = m;
//                 b = m + 1;
//             }
//             else
//                 e = m - 1;
//         }
//     }
//     if (start != len)
//         return {start, end};
//     else
//         return {-1, -1};
// }

// void combinationSumDFS(vector<int> &c, int start, int target, vector<int> &temp, vector<vector<int>> &res)
// {
//     if (target < 0)
//         return;
//     if (target == 0)
//     {
//         res.push_back(temp);
//         return;
//     }
//     else
//     {
//         for (int i = start; i < c.size(); i++)
//         {
//             temp.push_back(c[i]);
//             combinationSumDFS(c, i, target - c[i], temp, res);
//             temp.pop_back();
//         }
//     }
// }

// vector<vector<int>> combinationSum(vector<int> &candidates, int target)
// {
//     /*
//     给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//     candidates 中的数字可以无限制重复被选取。
//     说明：
//     所有数字（包括 target）都是正整数。
//     解集不能包含重复的组合。
//     示例 1:
//     输入: candidates = [2,3,6,7], target = 7,
//     所求解集为:
//     [
//     [7],
//     [2,2,3]
//     ]
//     示例 2:
//     输入: candidates = [2,3,5], target = 8,
//     所求解集为:
//     [
//     [2,2,2,2],
//     [2,3,3],
//     [3,5]
//     ]
//     */
//     if (candidates.empty())
//         return vector<vector<int>>();
//     vector<vector<int>> res;
//     std::sort(candidates.begin(), candidates.end());
//     vector<int> temp;
//     combinationSumDFS(candidates, 0, target, temp, res);
//     return res;
// }

// void combinationSum2DFS(vector<int> &c, int start, int target, vector<int> &temp, vector<vector<int>> &res)
// {
//     if (target < 0)
//         return;
//     if (target == 0)
//     {
//         res.push_back(temp);
//         return;
//     }
//     else
//     {
//         for (int i = start; i < c.size(); i++)
//         {
//             if (i > start && c[i] == c[i - 1])
//                 continue;
//             temp.push_back(c[i]);
//             combinationSum2DFS(c, i + 1, target - c[i], temp, res);
//             temp.pop_back();
//         }
//     }
// }

// vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
// {
//     /*
//     给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//     candidates 中的每个数字在每个组合中只能使用一次。
//     说明：
//     所有数字（包括目标数）都是正整数。
//     解集不能包含重复的组合。
//     示例 1:
//     输入: candidates = [10,1,2,7,6,1,5], target = 8,
//     所求解集为:
//     [
//     [1, 7],
//     [1, 2, 5],
//     [2, 6],
//     [1, 1, 6]
//     ]
//     示例 2:
//     输入: candidates = [2,5,2,1,2], target = 5,
//     所求解集为:
//     [
//     [1,2,2],
//     [5]
//     ]
//     */
//     if (candidates.empty())
//         return vector<vector<int>>();
//     vector<vector<int>> res;
//     std::sort(candidates.begin(), candidates.end());
//     vector<int> temp;
//     combinationSum2DFS(candidates, 0, target, temp, res);
//     return res;
// }

// string multiplyOneDigit(const string &num, char digit)
// {
//     if (digit == '0')
//         return "0";
//     int d = digit - '0';
//     int carry = 0, temp;
//     string res;
//     for (int i = num.size() - 1; i >= 0; i--)
//     {
//         temp = d * (num[i] - '0');
//         temp += carry;
//         res = (char)((temp % 10) + '0') + res;
//         carry = temp / 10;
//     }
//     if (carry != 0)
//         res = (char)(carry + '0') + res;
//     return res;
// }

// string add(const string &n1, const string &n2)
// {
//     if (n1 == "0")
//         return n2;
//     if (n2 == "0")
//         return n1;
//     string res;
//     int i = n1.size() - 1, j = n2.size() - 1;
//     int carry = 0, temp;
//     while (i >= 0 && j >= 0)
//     {
//         temp = (n1[i] - '0') + (n2[j] - '0') + carry;
//         carry = temp / 10;
//         res = (char)((temp % 10) + '0') + res;
//         i--;
//         j--;
//     }
//     if (i != -1)
//     {
//         if (carry == 0)
//             return n1.substr(0, i + 1) + res;
//         else
//         {
//             while (i >= 0)
//             {
//                 temp = (n1[i] - '0') + carry;
//                 carry = temp / 10;
//                 res = (char)((temp % 10) + '0') + res;
//                 i--;
//             }
//             if (carry != 0)
//                 res = (char)(carry + '0') + res;
//             return res;
//         }
//     }
//     if (j != -1)
//     {
//         if (carry == 0)
//             return n2.substr(0, j + 1) + res;
//         else
//         {
//             while (j >= 0)
//             {
//                 temp = (n2[j] - '0') + carry;
//                 carry = temp / 10;
//                 res = (char)((temp % 10) + '0') + res;
//                 j--;
//             }
//             if (carry != 0)
//                 res = (char)(carry + '0') + res;
//             return res;
//         }
//     }
//     if (carry != 0)
//         res = (char)(carry + '0') + res;
//     return res;
// }

// string multiply(string num1, string num2)
// {
//     if (num1 == "0" || num2 == "0")
//         return "0";
//     string res = "0";
//     string temp;
//     int zeroCnt = 0;
//     for (int i = num1.size() - 1; i >= 0; i--)
//     {
//         temp = multiplyOneDigit(num2, num1[i]);
//         temp += string(zeroCnt++, '0');
//         res = add(res, temp);
//     }
//     return res;
// }

// double myPow(double x, int n)
// {
//     if (n == 0)
//         return 1;
//     if (n < 0)
//     {
//         if (n == INT_MIN)
//             return 1.0 / (myPow(x, INT_MAX) * x);
//         else
//             return 1.0 / myPow(x, -n);
//     }
//     double half = myPow(x, n >> 1);
//     if (n % 2 == 0)
//         return half * half;
//     else
//         return half * half * x;
// }

// double myPowBitwise(double x, int n)
// {
//     /*
//     Consider the binary representation of n.
//     For example, if it is "10001011", then x^n = x^(1+2+8+128) = x^1 * x^2 * x^8 * x^128.
//     Thus, we don't want to loop n times to calculate x^n.
//     To speed up, we loop through each bit, if the i-th bit is 1, then we add x^(1 << i) to the result.
//     Since (1 << i) is a power of 2, x^(1<<(i+1)) = square(x^(1<<i)).
//     The loop executes for a maximum of log(n) times.
//     */
//     if (n == 0)
//         return 1;
//     if (n < 0)
//     {
//         if (n == INT_MIN)
//             return 1.0 / (myPowBitwise(x, INT_MAX) * x);
//         else
//             return 1.0 / myPowBitwise(x, -n);
//     }
//     double res = 1.0;
//     for (; n > 0; x *= x, n >>= 1)
//     {
//         if ((n & 1) > 0)
//             res *= x;
//     }
//     return res;
// }

// int firstMissingPositive(vector<int> &nums)
// {
//     /*
//     给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
//     示例 1:
//     输入: [1,2,0]
//     输出: 3
//     示例 2:
//     输入: [3,4,-1,1]
//     输出: 2
//     示例 3:
//     输入: [7,8,9,11,12]
//     输出: 1
//     说明:
//     你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
//     */
//     if (nums.empty())
//         return 1;
//     // 思路：数nums[i]存放在nums[i] - 1位置上，即下标0位置上存1，1位置上存2...
//     for (int i = 0, sz = nums.size(); i < sz; i++)
//     {
//         if (nums[i] > 0)
//         {
//             // 不断交换，直至归位或为负数或超过数组大小
//             while (nums[i] > 0 && nums[i] <= sz && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
//                 swap(nums[i], nums[nums[i] - 1]);
//         }
//     }
//     for (int i = 0, sz = nums.size(); i < sz; i++)
//     {
//         if (nums[i] != i + 1)
//             return i + 1;
//     }
//     // 说明都已归位并按顺序排好，返回数组中最后一个的下一个数
//     return nums.size() + 1;
// }

// int firstMissingPositiveFaster(vector<int> &nums)
// {
//     if (nums.empty())
//         return 1;
//     // 以空间换取时间，数n如果能够存在n - 1处，则对应位置1
//     vector<int> mark(nums.size());
//     for (int i = 0, sz = nums.size(); i < sz; i++)
//     {
//         if (nums[i] > 0 && nums[i] <= sz)
//             mark[nums[i] - 1] = 1;
//     }
//     for (int i = 0, sz = nums.size(); i < sz; i++)
//     {
//         if (!mark[i])
//             return i + 1;
//     }
//     return nums.size() + 1;
// }

// int trap(vector<int> &height)
// {
//     /*
//     给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//     示例:
//     输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//     输出: 6
//     */
//     if (height.size() <= 2)
//         return 0;
//     int len = height.size();
//     int *max_right = new int[len];           // 从右往左扫描，记录从右边到目前位置的最高柱子高度
//     int maxR = 0, maxL = height[0], sum = 0; // 从右往左最高柱子高度，从左往右最高柱子高度，存储的水
//     // 从右往左扫描，记录从右边到目前位置的最高柱子高度
//     for (int i = len - 1; i >= 0; i--)
//     {
//         if (height[i] > maxR)
//         {
//             max_right[i] = maxR = height[i];
//         }
//         else
//         {
//             max_right[i] = maxR;
//         }
//     }
//     // 从右往左扫描，更新最高柱子高度的同时，计算存储的水量
//     for (int i = 1; i < len; i++)
//     {
//         if (height[i] > maxL)
//         {
//             maxL = height[i];
//         }
//         // 水位高度：min（左边最高柱子高度， 右边最高柱子高度）- 当前高度
//         // 水量：max（水位高度，0），为0时即当前高度高于最高柱子高度，则存不下水
//         sum += max(min(maxL, max_right[i]) - height[i], 0);
//     }
//     delete[] max_right;
//     return sum;
// }

// int jump(vector<int> &nums)
// {
//     /*
//     给定一个非负整数数组，你最初位于数组的第一个位置。
//     数组中的每个元素代表你在该位置可以跳跃的最大长度。
//     你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//     示例:
//     输入: [2,3,1,1,4]
//     输出: 2
//     解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
//     说明:
//     假设你总是可以到达数组的最后一个位置。
//     */

//     // 思路：贪心算法，贪心能够到达的最远的距离
//     int sz = nums.size(), res = 0, i = 0;
//     int cur_max = 0, pre_max; // 当前能够到达的最远距离，之前能够到达的最远距离
//     while (cur_max < sz - 1)
//     {
//         ++res;
//         pre_max = cur_max;
//         // 在之前能够到达的最远距离下，寻找并更新当前能够到达的最远距离
//         for (; i <= pre_max; ++i)
//         {
//             // 寻找并更新当前能够到达的最远距离
//             cur_max = max(cur_max, i + nums[i]);
//         }
//     }
//     return res;
// }

// void solveNQueuesDFS(int n, vector<int> &pos, int row, vector<vector<string>> &res)
// {
//     if (row == n) // 深搜达到最底层，即搜索完所有行
//     {
//         vector<string> out(n, string(n, '.')); // 初始化输出棋盘
//         for (int i = 0; i < n; i++)            // 根据pos数组放置皇后
//         {
//             out[i][pos[i]] = 'Q';
//         }
//         res.push_back(out);
//     }
//     else
//     {
//         // 深度搜索该行的所有列是否能够放置
//         for (int col = 0; col < n; col++)
//         {
//             bool is_ok = true; // 该列是否能够放置标志
//             for (int r = 0; r < row; r++)
//             {
//                 // 判断是否行冲突或对角冲突
//                 if (pos[r] == col || std::abs(r - row) == abs(col - pos[r]))
//                 {
//                     is_ok = false;
//                     break;
//                 }
//             }
//             if (is_ok) // 该列能够放置
//             {
//                 pos[row] = col;
//                 solveNQueuesDFS(n, pos, row + 1, res); // 继续搜索下一行
//                 pos[row] = -1;
//             }
//         }
//     }
// }

// vector<vector<string>> solveNQueens(int n)
// {
//     /*
//     N皇后问题
//     */
//     vector<vector<string>> res;
//     if (n <= 0)
//         return res;
//     vector<int> pos_r_c(n, -1); // pos_r_c[i]表示第i行的皇后所放置的列号
//     solveNQueuesDFS(n, pos_r_c, 0, res);
//     return res;
// }

// template <typename T>
// pair<T, T> minmax(const vector<T> &input_sequence, size_t start, size_t stop)
// {
//     /*
//     二分法求最小最大值。
//     input_sequence：输入序列
//     start：起始下标
//     stop：终止下标
//     return：（最小值，最大值）
//     */
//     if (input_sequence.empty())
//         throw runtime_error("input sequence\'s length should greater than 0.");
//     if (start > stop || start > input_sequence.size() - 1)
//         throw out_of_range("index is out of range.");
//     if (input_sequence.size() == 1)
//         return pair<T, T>(input_sequence[0], input_sequence[0]);

//     if (start == stop)
//         return pair<T, T>(input_sequence[start], input_sequence[start]);
//     if (stop - start == 1)
//     {
//         if (input_sequence[start] > input_sequence[stop])
//             return pair<T, T>(input_sequence[stop], input_sequence[start]);
//         else
//             return pair<T, T>(input_sequence[start], input_sequence[stop]);
//     }

//     size_t middle = (start + stop) / 2;
//     pair<T, T> left_result = minmax(input_sequence, start, middle);
//     pair<T, T> right_result = minmax(input_sequence, middle + 1, stop);
//     T minmin = left_result.first > right_result.first ? right_result.first : left_result.first;
//     T maxmax = left_result.second < right_result.second ? right_result.second : left_result.second;
//     return pair<T, T>(minmin, maxmax);
// }

// template <typename T>
// void heapPermute(vector<T> &seqs, size_t n, vector<vector<T>> &res)
// {
//     if (n == 0)
//     {
//         res.push_back(seqs);
//         return;
//     }

//     for (size_t i = 0; i <= n; i++)
//     {
//         heapPermute(seqs, n - 1, res);
//         using std::swap;
//         if (n % 2 == 0)
//             swap(seqs[0], seqs[n]);
//         else
//             swap(seqs[i], seqs[n]);
//     }
// }

// template <typename T>
// vector<vector<T>> heapPermutation(vector<T> &seqs)
// {
//     if (seqs.empty())
//         throw runtime_error("input sequence is empty.");
//     if (seqs.size() == 1)
//         return vector<vector<T>>({seqs});
//     vector<vector<T>> res;
//     heapPermute(seqs, seqs.size() - 1, res);
//     return res;
// }

// void selectSort(vector<int> &a)
// {
//     size_t length = a.size();
//     int t;
//     size_t minIndex;
//     for (size_t i = 0; i < length - 1; i++)
//     {
//         minIndex = i;
//         for (size_t j = i + 1; j < length; j++)
//         {
//             if (a[j] < a[minIndex])
//             {
//                 t = a[j];
//                 a[j] = a[minIndex];
//                 a[minIndex] = t;
//             }
//         }
//     }
// }

// template <typename T>
// void merge(vector<T> &seqs, size_t start, size_t middle, size_t end)
// {
//     vector<T> temp(end - start + 1);
//     size_t i = start, j = middle + 1, k = 0;
//     while (i <= middle && j <= end)
//     {
//         if (seqs[i] > seqs[j])
//         {
//             temp[k++] = seqs[j++];
//         }
//         else
//         {
//             temp[k++] = seqs[i++];
//         }
//     }
//     while (i <= middle)
//     {
//         temp[k++] = seqs[i++];
//     }
//     while (j <= end)
//     {
//         temp[k++] = seqs[j++];
//     }
//     for (size_t i = 0, length = temp.size(); i < length; i++)
//     {
//         seqs[start++] = temp[i];
//     }
// }

// template <typename T>
// void mergesort(vector<T> &seqs, size_t start, size_t end)
// {
//     if (start < end)
//     {
//         size_t middle = (start + end) / 2;
//         mergesort(seqs, start, middle);
//         mergesort(seqs, middle + 1, end);
//         merge(seqs, start, middle, end);
//     }
// }

// template <typename T>
// size_t partition(vector<T> &seqs, size_t left, size_t right)
// {
//     size_t i = left, j = right;
//     T pivot_val = seqs[left];
//     while (i < j)
//     {
//         while (i < j && seqs[j] >= pivot_val)
//         {
//             j--;
//         }
//         seqs[i] = seqs[j];
//         while (i < j && seqs[i] < pivot_val)
//         {
//             i++;
//         }
//         seqs[j] = seqs[i];
//     }
//     seqs[i] = pivot_val;
//     return i;
// }

// template <typename T>
// void quicksort(vector<T> &seqs, size_t left, size_t right)
// {
//     size_t pivot = partition(seqs, left, right);

//     if (left < pivot)
//         quicksort(seqs, left, pivot - 1);
//     if (right > pivot)
//         quicksort(seqs, pivot + 1, right);
// }

// /*
// 一个机器人位于一个mxn网格的左上角。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角。
// 问总共有多少条不同的路径？
// */
// int uniquePaths(int m, int n)
// {
//     vector<vector<int>> map(m + 1, vector<int>(n + 1, 1));
//     for (int i = 2; i <= m; i++)
//     {
//         for (int j = 2; j <= n; j++)
//         {
//             // 动态规划
//             map[i][j] = map[i - 1][j] + map[i][j - 1];
//         }
//     }
//     return map[m][n];
// }

// /*
// 带有障碍的uniquePaths，障碍为1，非障碍为0
// */
// int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
// {
//     if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
//         return 0;
//     int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//     vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
//     dp[0][1] = 1;
//     for (int i = 1; i <= m; ++i)
//     {
//         for (int j = 1; j <= n; ++j)
//         {
//             if (obstacleGrid[i - 1][j - 1] != 0)
//                 continue;
//             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         }
//     }
//     return dp[m][n];
// }

// /*
// 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
// 思路：每次选取右上角元素
// 1）如果等于目标，返回
// 2）如果小于目标，则该元素所在行左侧所有元素都小于目标，去掉该行
// 3）如果大于目标，则该元素所在列下面所有元素都大于目标，去掉该列
//  */
// bool Find(int target, vector<vector<int>> &array)
// {
//     if (array.empty() || array[0].empty())
//         return false;

//     int rows = array.size(), cols = array[0].size();
//     int row = 0, col = cols - 1;
//     while (row < rows && col >= 0)
//     {
//         int temp = array[row][col];
//         if (temp == target)
//         {
//             return true;
//         }
//         else if (temp > target)
//         {
//             col--;
//         }
//         else
//         {
//             row++;
//         }
//     }
//     return false;
// }

// /*
// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
// 思路：
// 1）统计空格，计算插入后长度
// 2）双指针，pre指向原始长度，end指向新长度
// 3）从后向前扫描字符串
// 4）分情况：
//   a.pre为空格，填充end位置为%20
//   b.pre不是空格，填充end为pre
// */
// void replaceSpace(char *str, int length)
// {
//     if (str == nullptr || length <= 0)
//         return;

//     int old_len = 0, space_cnt = 0;
//     int i = 0;
//     while (str[i] != '\0')
//     {
//         old_len++;
//         if (str[i] == ' ')
//         {
//             space_cnt++;
//         }
//         i++;
//     }

//     int new_len = old_len + space_cnt * 2;
//     if (length < new_len)
//         return;

//     int pre = old_len, end = new_len;
//     while (pre >= 0 && pre < end)
//     {
//         if (str[pre] == ' ')
//         {
//             str[end--] = '0';
//             str[end--] = '2';
//             str[end--] = '%';
//         }
//         else
//         {
//             str[end--] = str[pre];
//         }
//         pre--;
//     }
// }

// /*
// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回
// 思路：
// 1）前序遍历的第一个元素为root
// 2）根据root，在中序遍历找到对应root
// 3）根据中序遍历中的root，将中序遍历划分为左边部分和右边部分，即左子树和右子树
// 4）根据中序遍历得到的左子树和右子树长度，对前序遍历的元素进行划分，同样得到左子树和右子树
// 5）根据前序遍历的左子树和右子树，以及中序遍历的左子树和右子树，递归构建
// */
// TreeNode *construct(const vector<int> &pre, const vector<int> &vin, int pre_start, int pre_stop, int vin_start, int vin_stop)
// {
//     // 前序遍历第一个元素为根
//     int root_val = pre[pre_start];
//     TreeNode *root = new TreeNode(root_val);

//     // 递归终止条件
//     if (pre_start == pre_stop && vin_start == vin_stop && pre[pre_start] == vin[vin_start])
//         return root;

//     // 在中序遍历中寻找根
//     int root_in_vin = vin_start;
//     for (; root_in_vin <= vin_stop; root_in_vin++)
//     {
//         if (vin[root_in_vin] == root_val)
//             break;
//     }

//     // 根据中序遍历得到的根下标，计算左子树元素个数
//     int left_len = root_in_vin - vin_start;
//     // 根据左子树元素个数，计算前序遍历中左子树结束位置
//     int left_pre_stop = pre_start + left_len;
//     if (left_len > 0)
//     {
//         // 递归构建左子树
//         root->left = construct(pre, vin, pre_start + 1, left_pre_stop, vin_start, root_in_vin - 1);
//     }
//     if (left_len < pre_stop - pre_start)
//     {
//         // 递归构建右子树
//         root->right = construct(pre, vin, left_pre_stop + 1, pre_stop, root_in_vin + 1, vin_stop);
//     }
//     return root;
// }
// TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
// {
//     if (pre.empty() || vin.empty() || pre.size() != vin.size())
//         return nullptr;
//     return construct(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
// }

// /*
// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
// NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
// 思路：
// 1）二分查找，双指针
// 2）middle元素大于left元素，left = middle
// 3）middle元素小于right元素，right = middle
// 4）当left和right相邻时，right元素即为最小
// 5）特殊情况，三者相同时，无法区分，只能顺序查找
// */
// int minNumberInRotateArray(const vector<int> &rotateArray)
// {
//     if (rotateArray.empty())
//         return 0;

//     int start = 0, stop = rotateArray.size() - 1;
//     if (rotateArray[start] < rotateArray[stop]) // 数组全部有序
//         return rotateArray[start];

//     while (rotateArray[start] >= rotateArray[stop])
//     {
//         if (stop - start == 1) // 终止条件
//             break;
//         int middle = (start + stop) / 2;
//         if (rotateArray[start] == rotateArray[middle] && rotateArray[start] == rotateArray[stop])
//             return [=, &rotateArray]() // 特殊情况处理
//             {
//                 int ret = rotateArray[start];
//                 for (int i = start + 1; i <= stop; i++)
//                 {
//                     if (rotateArray[i] < ret)
//                         ret = rotateArray[i];
//                 }
//                 return ret;
//             }();

//         if (rotateArray[middle] >= rotateArray[start])
//             start = middle;
//         else if (rotateArray[middle] <= rotateArray[stop])
//             stop = middle;
//     }
//     return rotateArray[stop];
// }

// /*
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
// 思路：
// 1）1级台阶1中跳法，2级台阶2种跳法
// 2）n级台阶，设有f(n)种跳法，由于每次最多条2级，讨论：
//   a.最开始跳一级，则剩下n-1级，有f(n-1)种跳法；
//   b.最开始跳两级，则剩下n-2级，有f(n-2)种跳法；
// 3）斐波那契数列变形
// */
// int jumpFloor(int number)
// {
//     if (number <= 2)
//         return number;

//     int pre = 1, next = 2;
//     int ret;
//     while (number - 2 > 0)
//     {
//         ret = pre + next;
//         pre = next;
//         next = ret;
//         number--;
//     }
//     return ret;
// }
// /*
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法。
// 思路：
// 1）数学归纳法可知f(n) = 2 ^ (n - 1)
// 2）移位计算
// */
// /*
// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
// 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
// 思路：
// 1）当n = 1，只有一种方法（竖着）
// 2）当n = 2，两种方法（竖着两个和横着两个）
// 3）当n > 2，讨论：
//   a.竖着放，则剩余2*(n-1)，有f(n-1)种放法；
//   b.横着放，那么下面的那个也只能横着放，剩余2*(n-2)，有f(n-2)种放法；
// 3）同青蛙跳，斐波那契数列变形
// */

// /*
// 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
// 思路：
// 1）n-1的二进制中的从右往左的第一个1变成0，并且后面的0全变成1，例子：1100 - 1 = 1011
// 2）n = n & (n - 1)，消除了从右往左的第一个1，例子：1100 & 1011 = 1000
// 3）重复操作直至n为0
// */
// int NumberOf1(int n)
// {
//     int cnt = 0;
//     while (n)
//     {
//         cnt++;
//         n &= (n - 1);
//     }
//     return cnt;
// }

// /*
// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
// 思路：
// 1）先在A中找到和B的根相同的节点
// 2）以此根为开始，比较是否有B的子树
// 3）如果未找到，继续1），否则返回true
// */
// bool check(TreeNode *pRoot1, TreeNode *pRoot2) // 判断以pRoot1为根的子树是否含有目标子树pRoot2
// {
//     if (pRoot2 == nullptr)
//         return true;

//     if (pRoot1 == nullptr)
//         return false;

//     if (pRoot1->val != pRoot2->val)
//         return false;

//     return check(pRoot1->left, pRoot2->left) && check(pRoot1->right, pRoot2->right);
// }
// bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
// {
//     if (pRoot1 == nullptr || pRoot2 == nullptr)
//         return false;

//     bool ret = false;
//     if (pRoot1->val == pRoot2->val) // 找到一个根和目标子树根一样的节点
//         ret = check(pRoot1, pRoot2);

//     // 递归搜寻左子树和右子树
//     if (ret == false)
//         ret = HasSubtree(pRoot1->left, pRoot2);

//     if (ret == false)
//         ret = HasSubtree(pRoot1->right, pRoot2);

//     return ret;
// }

// /*
// 题目描述
// 操作给定的二叉树，将其变换为源二叉树的镜像。
// 输入描述:
// 二叉树的镜像定义：源二叉树
//       8
//        /  \
//       6   10
//      / \  / \
//     5  7 9 11
//     镜像二叉树
//       8
//        /  \
//       10   6
//      / \  / \
//     11 9 7  5
// 思路：递归交换左右子节点
// */
// void Mirror(TreeNode *pRoot)
// {
//     if (pRoot == nullptr)
//         return;

//     TreeNode *t = pRoot->left;
//     pRoot->left = pRoot->right;
//     pRoot->right = t;

//     if (pRoot->left != nullptr)
//     {
//         Mirror(pRoot->left);
//     }
//     if (pRoot->right != nullptr)
//     {
//         Mirror(pRoot->right);
//     }
// }

// /*
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
// 例如，如果输入如下4 X 4矩阵：
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
// 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
// 思路：
// 1）按顺时针的一个一个的圈打印
// 2）每个圈的起始点为(start, start)，start从0开始，终止条件为start * 2 < rows和cols
// 3）打印圈时，圈的行或列从头一直打到尾，意味着下一个起点不包括上一个的终点
// 4）最后一圈可能会退化成一行或两行或只有一个元素，所以要分情况讨论
// */
// vector<int> printMatrix(const vector<vector<int>> &matrix)
// {
//     if (matrix.size() == 0 || matrix[0].size() == 0)
//         return vector<int>();

//     int rows = matrix.size(), cols = matrix[0].size();

//     vector<int> res;
//     res.reserve(rows * cols);

//     auto &m = matrix;
//     int start = 0;
//     while (rows > start * 2 && cols > start * 2) // 循环打印一个一个圈
//     {
//         int endRow = rows - start - 1;
//         int endCol = cols - start - 1;

//         for (int i = start; i <= endCol; i++) // 打印圈的上面一行（总是会打印）
//         {
//             res.push_back(m[start][i]);
//         }

//         if (endRow > start) // 打印圈的右边一列（当至少两行时才打印）
//         {
//             for (int i = start + 1; i <= endRow; i++)
//             {
//                 res.push_back(m[i][endCol]);
//             }
//         }

//         if (endRow > start && endCol > start) // 打印圈的下面一行（至少两行两列时打印）
//         {
//             for (int i = endCol - 1; i >= start; i--)
//             {
//                 res.push_back(m[endRow][i]);
//             }
//         }

//         if (endRow - 1 > start && endCol > start) // 打印圈的左边一列（至少三行两列才打印）
//         {
//             for (int i = endRow - 1; i >= start + 1; i--)
//             {
//                 res.push_back(m[i][start]);
//             }
//         }

//         start++;
//     }
//     return res;
// }

// /*
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
// 思路：
// 1）二叉搜索树的性质，左子树不大于根节点，右子树不小于根节点
// 2）后序遍历，根在最后
// 3）找到根，然后找不大于根的元素作为左子树，另一部分为右子树，并验证
// 4）递归验证
// */
// bool check(const vector<int> &seq, int start, int stop)
// {
//     if (start == stop)
//     {
//         return true;
//     }

//     int root = seq[stop]; // 找到根

//     int smaller = start;
//     for (; smaller < stop; smaller++) // 找到第一个大于根的元素，那么前面的就是左子树
//     {
//         if (seq[smaller] > root)
//             break;
//     }

//     int bigger = smaller;
//     for (; bigger < stop; bigger++) // 判断后面的是不是都不小于根，否则不符合二叉搜索树性质
//     {
//         if (seq[bigger] < root)
//             return false;
//     }

//     bool left = true;
//     if (smaller > start) // 递归左子树
//     {
//         left = check(seq, start, smaller - 1);
//     }

//     bool right = true;
//     if (smaller < stop) // 递归右子树
//     {
//         right = check(seq, smaller, stop - 1);
//     }

//     return left && right;
// }
// bool VerifySquenceOfBST(vector<int> seq)
// {
//     if (seq.empty())
//         return false;

//     int len = seq.size();
//     return check(seq, 0, len - 1);
// }

// /*
// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
// （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
// 思路：
// 1）在原始链表中复制各个节点，复制的节点在被复制节点的后面，也就是交替出现
// 2）修改复制节点的随机指针，复制节点的随机指针指向被复制节点的随机指针所指节点的复制节点
// 3）分离出复制好的链表
// */

// RandomListNode *Clone(RandomListNode *pHead)
// {
//     if (pHead == nullptr)
//         return nullptr;

//     RandomListNode *p = pHead;

//     while (p != nullptr) // 复制节点
//     {
//         RandomListNode *t = new RandomListNode(p->label);
//         t->next = p->next;
//         p->next = t;
//         p = t->next;
//     }

//     while (p != nullptr) // 修改复制节点的随机指针
//     {
//         if (p->random != nullptr)
//         {
//             p->next->random = p->random->next;
//         }
//         p = p->next->next;
//     }

//     RandomListNode *head = p->next;
//     RandomListNode *t = head;
//     while (p != nullptr) // 分离
//     {
//         p->next = t->next;
//         if (t->next == nullptr)
//             break;
//         t->next = t->next->next;
//         p = p->next;
//         t = t->next;
//     }

//     return head;
// }

// /*
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
// 思路：
// 1）中序遍历
// 2）遍历过程中修改指针
// */
// void ConvertRecursively(TreeNode *p, TreeNode **last)
// {
//     if (p == nullptr)
//     {
//         return;
//     }

//     if (p->left != nullptr) // 左子树遍历
//     {
//         ConvertRecursively(p->left, last);
//     }

//     p->left = *last; // 修改根节点上一个节点指向
//     if (*last != nullptr)
//     {
//         (*last)->right = p; // 修改左子树遍历最后一个节点的下一个节点指向
//     }

//     *last = p; // 当前根节点成为最后一个节点

//     if (p->right != nullptr) // 右子树遍历
//     {
//         ConvertRecursively(p->right, last);
//     }
// }
// TreeNode *Convert(TreeNode *pRootOfTree)
// {
//     if (pRootOfTree == nullptr || (pRootOfTree->left == nullptr && pRootOfTree->right == nullptr))
//     {
//         return pRootOfTree;
//     }

//     TreeNode *lastNode = nullptr; // 左子树遍历完后的最后一个节点
//     ConvertRecursively(pRootOfTree, &lastNode);

//     TreeNode *head = lastNode;
//     while (head->left != nullptr) // 从最后一个节点往前得到头节点
//     {
//         head = head->left;
//     }

//     return head;
// }

// /*
// 题目描述
// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
// 输入描述:
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
// 思路：
// 1）第一个字符和后面所有字符交换
// 2）固定第一个字符，求后面字符的排列
// 3）递归调用
// */
// void PermutationRecursively(set<string> &res, string &t, int startIdx)
// {
//     if (startIdx == t.size())
//         res.insert(t);

//     for (int i = startIdx; i < t.size(); i++)
//     {
//         char tc = t[startIdx];
//         t[startIdx] = t[i];
//         t[i] = tc;

//         PermutationRecursively(res, t, startIdx + 1);

//         tc = t[startIdx];
//         t[startIdx] = t[i];
//         t[i] = tc;
//     }
// }
// vector<string> Permutation(string str)
// {
//     if (str.empty())
//         return vector<string>();
//     if (str.size() == 1)
//         return vector<string>{str};

//     set<string> res; // set去重
//     string temp = str;
//     PermutationRecursively(res, temp, 0);

//     return vector<string>(res.begin(), res.end());
// }

// /*
// 输入n个整数，找出其中最小的K个数。
// 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
// 思路1：利用partition函数，使得前k小的元素放在0~k-1处（不一定有序）
// 思路2：利用优先队列（最大堆）
// */
// vector<int> GetLeastNumbers_Solution_1(vector<int> input, int k)
// {
//     if (input.empty() || k < 1 || input.size() < k)
//         return vector<int>();

//     if (input.size() == k)
//     {
//         return input;
//     }

//     int start = 0, stop = input.size() - 1;
//     int idx = partition(input, start, stop);
//     while (idx != k - 1)
//     {
//         if (idx > k - 1)
//         {
//             stop = idx - 1;
//             idx = partition(input, start, stop);
//         }
//         else
//         {
//             start = idx + 1;
//             idx = partition(input, start, stop);
//         }
//     }
//     return vector<int>(input.begin(), input.begin() + k);
// }
// vector<int> GetLeastNumbers_Solution_2(vector<int> input, int k)
// {
//     if (input.empty() || k < 1 || input.size() < k)
//         return vector<int>();

//     if (input.size() == k)
//         return input;

//     priority_queue<int> max_heap;
//     for (int i : input)
//     {
//         if (max_heap.size() < k)
//             max_heap.push(i);
//         else
//         {
//             if (max_heap.top() > i)
//             {
//                 max_heap.pop();
//                 max_heap.push(i);
//             }
//         }
//     }
//     vector<int> res;
//     res.reserve(max_heap.size());
//     while (!max_heap.empty())
//     {
//         res.push_back(max_heap.top());
//         max_heap.pop();
//     }
//     return res;
// }

// /*
// 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
// ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
// */
// int NumberOf1(string s)
// {
//     if (s.empty())
//         return 0;

//     int first = s[0] - '0';
//     unsigned int len = s.size();

//     if (len == 1 && first == 0)
//         return 0;
//     if (len == 1 && first > 0)
//         return 1;

//     // 最高位
//     int numFirst = 0;
//     if (first > 1)
//         numFirst = static_cast<int>(pow(10, len - 1));
//     else if (first == 1)
//         numFirst = stoi(s.substr(1)) + 1;

//     // 其余位
//     int numOther = first * (len - 1) * static_cast<int>(pow(10, len - 2));

//     // 递归
//     int numRecur = NumberOf1(s.substr(1));

//     return numFirst + numOther + numRecur;
// }
// int NumberOf1Between1AndN_Solution_1(int n)
// {
//     if (n <= 0)
//         return 0;
//     if (n < 10)
//         return 1;

//     string snum = to_string(n);
//     return NumberOf1(snum);
// }
// // https://www.cnblogs.com/xuanxufeng/p/6854105.html
// int NumberOf1Between1AndN_Solution_2(int n)
// {
//     int ones = 0;
//     for (long m = 1; m <= n; m *= 10)
//         ones += (n / m + 8) / 10 * m + (n / m % 10 == 1 ? n % m + 1 : 0);
//     return ones;
// }

// /*
// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
// 思路：两个数a和b组合，如果ab<ba，那么a放在b的前面
// */
// string PrintMinNumber(vector<int> numbers)
// {
//     if (numbers.empty())
//         return string();
//     if (numbers.size() == 1)
//         return to_string(numbers[0]);

//     vector<string> vec;
//     vec.reserve(numbers.size());
//     for (int i : numbers)
//         vec.push_back(to_string(i));
//     sort(vec.begin(), vec.end(),
//          [](const string &lhs, const string &rhs) {
//              return (lhs + rhs) < (rhs + lhs);
//          });
//     ostringstream oss;
//     for (const string &s : vec)
//         oss << s;
//     return oss.str();
// }

// /*
// 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
// 例如6、8都是丑数，但14不是，因为它包含质因子7。
// 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
// 思路：
// 1）按从小到大求出各个丑数
// 2）当前丑数肯定是前面某个丑数*2或*3或*5得到的
// 3）用3个指针记录前面的*2或*3或*5的丑数
// 4）选择*2或*3或*5的丑数的最小的那个作为当前丑数
// */
// int GetUglyNumber_Solution(int index)
// {
//     if (index <= 0)
//         throw runtime_error("invalid input");
//     if (index == 1)
//         return 1;

//     vector<int> nums;
//     nums.reserve(index);
//     nums[0] = 1;

//     int num2 = 0, num3 = 0, num5 = 0; // 下标，分别记录*2或*3或*5的上一个丑数的下标
//     int idx = 1;

//     auto minThree = [](int a, int b, int c) -> int {
//         int min_val = a < b ? a : b;
//         return min_val < c ? min_val : c;
//     };

//     while (idx < index)
//     {
//         nums[idx] = minThree(nums[num2] * 2, nums[num3] * 3, nums[num5] * 5);
//         while (nums[num2] * 2 <= nums[idx])
//             num2++;
//         while (nums[num3] * 3 <= nums[idx])
//             num3++;
//         while (nums[num5] * 5 <= nums[idx])
//             num5++;
//         ++idx;
//     }

//     return nums[index - 1];
// }

// /*
// 题目描述
// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
// */
// void InversePairsMergeSort(vector<int> &data, vector<int> &temp, int &res, int start, int stop)
// {
//     if (start == stop)
//         return;
//     int middle = (start + stop) / 2;
//     InversePairsMergeSort(data, temp, res, start, middle);
//     InversePairsMergeSort(data, temp, res, middle + 1, stop);

//     // 此处相当于merge
//     int i = middle, j = stop;
//     int tempIdx = stop;
//     while (i >= start && j > middle)
//     {
//         if (data[i] > data[j])
//         {
//             res += j - middle;
//             res %= 1000000007;
//             temp[tempIdx--] = data[i];
//             i--;
//         }
//         else
//         {
//             temp[tempIdx--] = data[j];
//             j--;
//         }
//     }
//     while (i >= start)
//     {
//         temp[tempIdx--] = data[i];
//         i--;
//     }
//     while (j > middle)
//     {
//         temp[tempIdx--] = data[j];
//         j--;
//     }
//     for (int t = start; t <= stop; t++)
//         data[t] = temp[t];
// }
// int InversePairs(vector<int> data)
// {
//     if (data.empty() || data.size() == 1)
//         return 0;
//     int res = 0;
//     vector<int> temp(data);
//     InversePairsMergeSort(data, temp, res, 0, data.size() - 1);
//     return res;
// }

// /*
// 输入两个链表，找出它们的第一个公共结点。
// 思路：
// 1）从公共节点开始至末尾，两个链表应该是重合的，只需要判断两指针相同即可
// 2）链表长度不一致，可以将长的链表先next一下直到和短链一样长
// 3）接下来两个链表同时遍历直至相同即可
// */
// ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
// {
//     if (pHead1 == nullptr || pHead2 == nullptr)
//         return nullptr;

//     auto getListLength = [](ListNode *head) -> int {
//         int len = 0;
//         ListNode *pnode = head;
//         while (pnode != nullptr)
//         {
//             pnode = pnode->next;
//             ++len;
//         }
//         return len;
//     };

//     int len1 = getListLength(pHead1), len2 = getListLength(pHead2); // 获取长度
//     if (len1 < len2)
//     {
//         using std::swap;
//         swap(len1, len2);
//         swap(pHead1, pHead2);
//     }

//     int len_diff = len1 - len2;
//     ListNode *p1 = pHead1, *p2 = pHead2;
//     for (int i = 0; i < len_diff; i++) // 长链变短链
//     {
//         p1 = p1->next;
//     }

//     while (p1 != p2 && p1 != nullptr && p2 != nullptr) // 找到第一个相同节点
//     {
//         p1 = p1->next;
//         p2 = p2->next;
//     }
//     if (pHead1 == nullptr || pHead2 == nullptr)
//         return nullptr;
//     else
//         return p1;
// }

// /*
// 统计一个数字在排序数组中出现的次数。
// 思路：
// 1）二分搜索
// 2）分别找出左边界和右边界
// */
// int GetNumberOfKLeftIdx(const vector<int> &data, int k, int start, int stop)
// {
//     if (start > stop)
//         return -1;

//     int middle = (start + stop) / 2;
//     if (data[middle] == k)
//     {
//         if (middle == 0 || data[middle - 1] < k) // 找到左边界
//             return middle;
//         else
//             return GetNumberOfKLeftIdx(data, k, start, middle - 1);
//     }
//     else if (data[middle] < k)
//         return GetNumberOfKLeftIdx(data, k, middle + 1, stop);
//     else
//         return GetNumberOfKLeftIdx(data, k, start, middle - 1);
// }
// int GetNumberOfKRightIdx(const vector<int> &data, int k, int start, int stop)
// {
//     if (start > stop)
//         return -1;

//     int middle = (start + stop) / 2;
//     if (data[middle] == k)
//     {
//         if (middle == data.size() - 1 || data[middle + 1] > k) // 找到右边界
//             return middle;
//         else
//             return GetNumberOfKRightIdx(data, k, middle + 1, stop);
//     }
//     else if (data[middle] < k)
//         return GetNumberOfKRightIdx(data, k, middle + 1, stop);
//     else
//         return GetNumberOfKRightIdx(data, k, start, middle - 1);
// }
// int GetNumberOfK(vector<int> data, int k)
// {
//     if (data.empty() || (data.size() == 1 && data[0] != k))
//         return 0;
//     if (data.size() == 1 && data[0] == k)
//         return 1;

//     int left_idx = GetNumberOfKLeftIdx(data, k, 0, data.size() - 1);
//     int right_idx = GetNumberOfKRightIdx(data, k, 0, data.size() - 1);

//     if (left_idx != -1 && right_idx != -1)
//         return right_idx - left_idx + 1;
//     else
//         return 0;
// }

// /*
// 输入一棵二叉树，求该树的深度。
// 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
// 思路：后序遍历
// */

// int TreeDepth(TreeNode *pRoot)
// {
//     if (pRoot == nullptr)
//         return 0;

//     int left_depth = TreeDepth(pRoot->left);
//     int right_depth = TreeDepth(pRoot->right);

//     return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
// }

// /*
// 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
// 思路：
// 1）后序遍历得到左右子树的深度
// 2）在根处判断是否失衡
// */
// int IsBalanced_Solution_Recursively(TreeNode *p, bool &res)
// {
//     // 提前结束递归
//     if (res == false)
//         return 0;

//     if (p == nullptr)
//         return 0;

//     int left_depth = IsBalanced_Solution_Recursively(p->left, res);

//     // 提前结束递归
//     if (res == false)
//         return 0;

//     int right_depth = IsBalanced_Solution_Recursively(p->right, res);

//     // 提前结束递归
//     if (res == false)
//         return 0;

//     // 判断是否失衡
//     if (left_depth - right_depth > 1 || left_depth - right_depth < -1)
//     {
//         res = false;
//         return 0;
//     }
//     else
//         return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
// }
// bool IsBalanced_Solution(TreeNode *pRoot)
// {
//     if (pRoot == nullptr)
//         return true;
//     bool res = true;
//     IsBalanced_Solution_Recursively(pRoot, res);
//     return res;
// }

// /*
// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
// 思路：
// 1）如果只有一个数字出现一次，则将所有的数字异或以后就可以得到该数字
// 2）想办法将数组分割成两部分，每部分只包含一个只出现一次的数字
// */
// void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
// {
//     if (data.size() < 2)
//         return;
//     if (data.size() == 2)
//     {
//         *num1 = data[0];
//         *num2 = data[1];
//         return;
//     }

//     int res = 0;
//     for (int i : data) // 所有数字异或
//         res ^= i;

//     int right1_idx = 0; // 从右至左第一个1的位置
//     while ((res & 0x01) != 1)
//     {
//         res >>= 1;
//         ++right1_idx;
//     }

//     // 查看某个数从右至左的第一个1的位置是否和上述的位置一致，这样就分成两部分了
//     auto check1 = [right1_idx](int t) -> bool {
//         for (int i = 0; i < right1_idx; i++)
//             t >>= 1;
//         return t & 0x01;
//     };

//     *num1 = *num2 = 0;
//     for (int i : data)
//     {
//         if (check1(i))
//             *num1 ^= i;
//         else
//             *num2 ^= i;
//     }
// }

// /*
// 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
// 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
// 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
// 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
// 思路：双指针法
// */
// vector<vector<int>> FindContinuousSequence(int sum)
// {
//     if (sum < 2)
//         return vector<vector<int>>();

//     vector<vector<int>> res;
//     auto pushResult = [&res](int start, int stop) -> void {
//         vector<int> t;
//         t.reserve(stop - start + 1);
//         for (; start <= stop; ++start)
//             t.push_back(start);
//         res.push_back(t);
//     };

//     int start = 1, stop = 2; // 分别代表序列开头和结尾
//     int sum_t = 3;
//     while (start <= (sum + 1) / 2) // 至少两个数，则循环条件start + stop(start + 1) <= sum
//     {
//         if (sum_t == sum)
//         {
//             pushResult(start, stop);
//             sum_t -= start;
//             ++start;
//         }
//         else if (sum_t < sum)
//         {
//             ++stop;
//             sum_t += stop;
//         }
//         else
//         {
//             sum_t -= start;
//             ++start;
//         }
//     }
//     return res;
// }

// /*
// 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
// 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
// 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
// Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
// 思路：
// 1）先翻转整个字符串
// 2）再逐个单词翻转
// */
// string ReverseSentence(string str)
// {
//     if (str.empty() || str.size() == 1)
//         return str;

//     auto reverse = [](string &s, int start, int stop) -> void {
//         while (start < stop)
//         {
//             using std::swap;
//             swap(s[start], s[stop]);
//             ++start;
//             --stop;
//         }
//     };

//     reverse(str, 0, str.size() - 1); // 整体翻转

//     int start = 0, stop = 0;
//     while (start < str.size())
//     {
//         if (str[stop] == ' ') // 逐个单词翻转
//         {
//             reverse(str, start, stop - 1);
//             start = stop = stop + 1;
//         }
//         else if (stop == str.size() - 1) // 最后一个单词
//         {
//             reverse(str, start, stop);
//             break;
//         }
//         else
//             ++stop;
//     }
//     return str;
// }

// /*
// 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
// 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
// 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
// 思路：
// 1）按k分成两部分
// 2）分别对这两部分进行翻转
// 3）整体翻转
// */
// string LeftRotateString(string str, int n)
// {
//     if (str.empty() || str.size() == 1 || n <= 0 || n % str.size() == 0)
//         return str;

//     auto reverse = [](string &s, int start, int stop) -> void {
//         while (start < stop)
//         {
//             using std::swap;
//             swap(s[start], s[stop]);
//             ++start;
//             --stop;
//         }
//     };

//     int cnt = n % str.size() - 1;
//     reverse(str, 0, cnt);
//     reverse(str, cnt + 1, str.size() - 1);
//     reverse(str, 0, str.size() - 1);
//     return str;
// }

// /*
// 约瑟夫问题：n个人围成一圈，从0到n - 1，然后从第0个人开始，数到m - 1，出列，如此循环。
// 求最后剩余的人是最开始的哪个人？
// 思路：
// 1）设f(n, m)表示n个人每m个人出列后剩余的最后一人的编号，第一个出列的人为k = (m - 1) % n；
// 2）接下来求f(n - 1, m)。剩余的人k + 1, k + 2, ..., n, 0, 1, 2, ..., k - 1重新编号为0 ~ n-2，存在映射关系f(x) = (x + k + 1) % n，x表示映射后的值，f(x)表示映射前的值；
// 3）带入k得f(x) = (x + m) % n，实际上x是f(n - 1, m)下的编号，f(x)为f(n, m)下的编号；
// 4）则f(n, m) = (f(n - 1, m) + m) % n;
// */
// int LastRemaining_Solution(int n, int m)
// {
//     /*
//           ┌ 0,                    n == 1
//     f(n, m) = |
//           └ (f(n - 1, m) + m) % n, n >1
//     */

//     /*if (n < 1 || m < 1)
//       return -1;
//     int pre = 0;
//     if (n == 1)
//       return 0;
//     return (LastRemaining_Solution(n - 1, m) + m) % n;*/

//     if (n < 1 || m < 1)
//         return -1;
//     int pre = 0;
//     for (int i = 2; i <= n; i++)
//         pre = (pre + m) % i;
//     return pre;
// }

// /*
// 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
// 思路：采用位运算
// 1）先不考虑进位，两数逐位相加，有0+0=0、1+0=1、0+1=1、1+1=0，即异或
// 2）计算进位，只有1+1才会有进位，则先与，再左移一位
// 3）将上述两个结果加起来，即重复1、2步骤
// */
// int Add(int num1, int num2)
// {
//     int sum, carry;
//     do
//     {
//         sum = num1 ^ num2;
//         carry = (num1 & num2) << 1;
//         num1 = sum;
//         num2 = carry;
//     } while (carry);
//     return sum;
// }

// /*
// 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
// 不能使用除法。
// 思路：
// 1）分两步计算，在A[i]处分成两部分
// 2）先计算左部分A[0]*A[1]*...*A[i-1]，并且A[0]*A[1]可由A[0]得到，A[0]*A[1]*A[2]可由A[0]*A[1]得到，以此类推
// 3）再计算右部分A[i+1]*...*A[n-1]，计算方法同上
// */
// vector<int> multiply(const vector<int> &A)
// {
//     if (A.empty())
//         return vector<int>();
//     if (A.size() == 1)
//         return {0};

//     int len = A.size();
//     vector<int> B(len, 1);

//     for (int i = 1; i < len; i++) // 计算左部分
//     {
//         B[i] = B[i - 1] * A[i - 1];
//     }

//     int temp = 1;
//     for (int i = len - 2; i >= 0; i--) // 计算右部分，并同时乘上左部分
//     {
//         temp *= A[i + 1];
//         B[i] *= temp;
//     }

//     return B;
// }

// /*
// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
// 思路：
// 1）先确定环的长度
//   a.找到环中的一个节点（用快慢两指针，快指针追上慢指针时即为环内节点）
//   b.遍历一下，当回到初始节点时即得到长度
// 2）双指针，一个指针先走环的长度，然后同时走，最后相遇点即是入口节点
// */
// ListNode *EntryNodeOfLoop(ListNode *pHead)
// {
//     // 寻找环中的一个节点
//     auto FindNodeInLoop = [](ListNode *p) -> ListNode * {
//         if (p == nullptr || p->next == nullptr)
//             return nullptr;

//         // 快慢指针法
//         ListNode *slow = p, *fast = slow->next;
//         while (slow != nullptr && fast != nullptr)
//         {
//             if (slow == fast) // 快指针追上慢指针
//                 return slow;

//             slow = slow->next; // 慢指针走一步
//             fast = fast->next;
//             if (fast != nullptr) // 快指针走两步
//                 fast = fast->next;
//         }
//         return nullptr;
//     };

//     ListNode *p = FindNodeInLoop(pHead);
//     if (p == nullptr)
//         return nullptr;

//     int loop_len = 1;
//     ListNode *t = p->next;
//     while (t != p) // 获取环的长度
//     {
//         t = t->next;
//         ++loop_len;
//     }

//     ListNode *pre = pHead, *nxt = pre;
//     for (int i = 0; i < loop_len; i++) // 一个指针先走环的长度
//         nxt = nxt->next;

//     while (pre != nxt) // 指针相遇即得到结果
//     {
//         pre = pre->next;
//         nxt = nxt->next;
//     }

//     return pre;
// }

// /*
// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
// 思路：
// 1）如果该节点有右子树，那么下一个节点就是右子树的最左节点
// 2）如果该节点是其父节点的左子节点，那么下一个节点就是其父节点
// 3）如果该节点是其父节点的右子节点，那么需要向父节点不断回溯，直至找到某个节点是其父节点的左子节点，下一个节点就是该节点的父节点
// */
// TreeLinkNode *GetNext(TreeLinkNode *pNode)
// {
//     if (pNode == nullptr)
//         return nullptr;

//     if (pNode->right != nullptr) // 情况1）
//     {
//         TreeLinkNode *t = pNode->right;
//         while (t->left != nullptr)
//             t = t->left;
//         return t;
//     }
//     else if (pNode->next != nullptr && pNode == pNode->next->left) // 情况2）
//     {
//         return pNode->next;
//     }
//     else if (pNode->next != nullptr && pNode == pNode->next->right) // 情况3）
//     {
//         TreeLinkNode *now = pNode, *parent = pNode->next;
//         while (parent != nullptr)
//         {
//             if (parent->left == now)
//                 return parent;
//             now = parent;
//             parent = now->next;
//         }
//         return nullptr;
//     }
//     else
//         return nullptr;
// }

// /*
// 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
// 思路：
// 1）使用前序遍历（根左右）和对称的前序遍历（根右左）
// 2）并且考虑空节点，这样两种遍历出来的结果才会真的不一样，否则可能会有一样的结果
// */
// bool isSymmetricalRecursively(TreeNode *p1, TreeNode *p2)
// {
//     if (p1 == nullptr && p2 == nullptr)
//         return true;

//     if (p1 == nullptr || p2 == nullptr)
//         return false;

//     if (p1->val != p2->val)
//         return false;

//     return isSymmetricalRecursively(p1->left, p2->right) && isSymmetricalRecursively(p1->right, p2->left);
// }
// bool isSymmetrical(TreeNode *pRoot)
// {
//     if (pRoot == nullptr || (pRoot->left == nullptr && pRoot->right == nullptr))
//         return true;

//     return isSymmetricalRecursively(pRoot, pRoot);
// }

// /*
// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
// 思路：
// 1）使用队列
// 2）使用两个变量，一个变量记录本层的待打印节点数，另一个变量记录下一层的节点数
// */
// vector<vector<int>> PrintTreePerLevel(TreeNode *pRoot)
// {
//     if (pRoot == nullptr)
//         return vector<vector<int>>();

//     vector<vector<int>> res;
//     vector<int> temp;
//     queue<TreeNode *> qu;
//     int now_level = 1, next_level = 0;

//     qu.push(pRoot);
//     while (qu.empty() == false)
//     {
//         TreeNode *t = qu.front();
//         qu.pop();
//         temp.push_back(t->val);
//         --now_level;

//         if (t->left != nullptr)
//         {
//             qu.push(t->left);
//             ++next_level;
//         }
//         if (t->right != nullptr)
//         {
//             qu.push(t->right);
//             ++next_level;
//         }

//         if (now_level == 0)
//         {
//             now_level = next_level;
//             next_level = 0;
//             res.push_back(temp);
//             temp.clear();
//         }
//     }
//     return res;
// }

// /*
// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
// 思路：
// 1）双栈法
// 2）当前层为奇数层时，子节点按从左往右进入另一个栈
// 3）当前层为偶数层时，子节点按从右往左进入另一个栈
// 4）每结束一层两栈切换
// */
// vector<vector<int>> PrintTreeZigZag(TreeNode *pRoot)
// {
//     if (pRoot == nullptr)
//         return vector<vector<int>>();

//     vector<vector<int>> res;
//     vector<int> temp;
//     stack<TreeNode *> st[2]; // 双栈
//     int now = 0, next = 1;   // 当前栈标识，下一层栈标识

//     st[now].push(pRoot);
//     while (!st[0].empty() || !st[1].empty())
//     {
//         TreeNode *t = st[now].top();
//         temp.push_back(t->val);
//         st[now].pop();

//         if (next == 1) // 当前层为奇数层时，子节点从左到右入下一层栈
//         {
//             if (t->left != nullptr)
//                 st[next].push(t->left);
//             if (t->right != nullptr)
//                 st[next].push(t->right);
//         }
//         else // 当前层为偶数层时，子节点从右往左入下一层栈
//         {
//             if (t->right != nullptr)
//                 st[next].push(t->right);
//             if (t->left != nullptr)
//                 st[next].push(t->left);
//         }

//         if (st[now].empty())
//         {
//             res.push_back(temp);
//             temp.clear();
//             // 切换栈标识
//             now = 1 - now;
//             next = 1 - next;
//         }
//     }

//     return res;
// }

// /*
// 请实现两个函数，分别用来序列化和反序列化二叉树
// 思路：
// 1）使用前序遍历进行序列化，这样从根节点开始，并且需要考虑空节点
// 2）反序列化时，最开始的节点就是根节点，然后递归进行构建
// */
// string str_temp;
// void SerializeRecursively(TreeNode *p, ostream &out)
// {
//     if (p == nullptr)
//     {
//         out << "$,";
//         return;
//     }
//     out << p->val << ',';
//     SerializeRecursively(p->left, out);
//     SerializeRecursively(p->right, out);
// }
// char *Serialize(TreeNode *root)
// {
//     if (root == nullptr)
//         return nullptr;

//     ostringstream oss;
//     SerializeRecursively(root, oss);
//     ::str_temp = oss.str();

//     return const_cast<char *>(::str_temp.c_str());
// }
// bool ReadNodeData(char **str, int *data)
// {
//     if (**str == NULL || **str == '\0')
//         return false;

//     if (**str == '$')
//     {
//         *str += 2;
//         cout << '$' << endl;
//         return false;
//     }

//     string t;
//     while (**str != ',')
//     {
//         t.push_back(**str);
//         ++(*str);
//     }
//     ++(*str);
//     *data = stoi(t);
//     cout << *data << endl;
//     return true;
// }
// void DeserializeRecursively(TreeNode **pp, char **str)
// {
//     int data;
//     if (ReadNodeData(str, &data))
//     {
//         *pp = new TreeNode(data);
//         DeserializeRecursively(&((*pp)->left), str);
//         DeserializeRecursively(&((*pp)->right), str);
//     }
// }
// TreeNode *Deserialize(char *str)
// {
//     if (str == nullptr || *str == '\0')
//         return nullptr;

//     TreeNode *pRoot = nullptr;
//     DeserializeRecursively(&pRoot, &str);
//     return pRoot;
// }

// /*
// 给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
// 思路：由于是二叉搜索树，所以中序遍历得到第k个节点即可
// */
// void KthNodeRecursively(TreeNode *p, int &k, TreeNode *&target)
// {
//     if (p->left != nullptr)
//         KthNodeRecursively(p->left, k, target);

//     if (target == nullptr)
//     {
//         if (k == 1)
//             target = p;
//         --k;
//     }

//     if (target == nullptr && p->right != nullptr)
//         KthNodeRecursively(p->right, k, target);
// }
// TreeNode *KthNode(TreeNode *pRoot, int k)
// {
//     if (pRoot == nullptr || k <= 0)
//         return nullptr;

//     TreeNode *target = nullptr;
//     KthNodeRecursively(pRoot, k, target);
//     return target;
// }

// /*
// 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
// 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
// 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
// {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
// {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
// 思路：
// 1）使用一个双端队列，保存当前窗口的一个子窗口，这个子窗口满足这样一个要求
//   a.保存的是下标
//   b.保存的下标是连续的
//   c.保存的第一个元素是当前窗口的最大元素的下标，然后继续保存直到窗口末端
// 2）每次移动窗口更新上述数据结构
// 3）注意最左元素可能不在新窗口中了，需要剔除，因此保存的是下标
// */
// vector<int> maxInWindows(const vector<int> &num, unsigned int size)
// {
//     if (num.size() < size || size < 1)
//         return {};

//     vector<int> res;
//     deque<int> idx;
//     for (size_t i = 0; i < size; i++)
//     {
//         while (!idx.empty() && num[i] >= num[idx.back()])
//             idx.pop_back();

//         idx.push_back(i);
//     }

//     for (size_t i = size; i < num.size(); i++)
//     {
//         res.push_back(num[idx.front()]);
//         while (!idx.empty() && num[i] >= num[idx.back()])
//             idx.pop_back();
//         if (!idx.empty() && idx.front() <= static_cast<int>(i - size))
//             idx.pop_front();
//         idx.push_back(i);
//     }
//     res.push_back(num[idx.front()]);
//     return res;
// }

// /*
// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
// 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
// 如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
// 例如
// a b c e
// s f c s
// a d e e
// 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
// 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
// 思路：回溯法
// */
// void hasPathRecursively(char *matrix, int rows, int cols, int row, int col, char *str, int str_idx, bool &res, bool *is_visited)
// {
//     if (res == true)
//         return;
//     if (*(str + str_idx) == '\0')
//     {
//         res = true;
//         return;
//     }

//     if (row >= 0 && row < rows && col >= 0 && col < cols && *(is_visited + row * cols + col) == false && *(matrix + row * cols + col) == *(str + str_idx))
//     {
//         *(is_visited + row * cols + col) = true;
//         hasPathRecursively(matrix, rows, cols, row + 1, col, str, str_idx + 1, res, is_visited);
//         hasPathRecursively(matrix, rows, cols, row - 1, col, str, str_idx + 1, res, is_visited);
//         hasPathRecursively(matrix, rows, cols, row, col + 1, str, str_idx + 1, res, is_visited);
//         hasPathRecursively(matrix, rows, cols, row, col - 1, str, str_idx + 1, res, is_visited);
//         if (res == false)
//             *(is_visited + row * cols + col) = false;
//     }
// }
// bool hasPath(char *matrix, int rows, int cols, char *str)
// {
//     if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
//         return false;

//     bool *is_visited = new bool[rows * cols];
//     for (int i = 0; i < rows * cols; i++)
//         *(is_visited + i) = false;

//     bool res = false;
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (res == true)
//             {
//                 delete is_visited;
//                 return true;
//             }
//             hasPathRecursively(matrix, rows, cols, i, j, str, 0, res, is_visited);
//         }
//     }
//     delete is_visited;
//     return res;
// }

// /*
// 地上有一个m行和n列的方格。
// 一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
// 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
// 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
// 思路：回溯法
// */
// void movingCountRecursively(int threshold, int rows, int cols, int row, int col, bool *is_visited)
// {
//     static auto getIdxDigitBitSum = [](int idx) -> int {
//         int sum = 0;
//         while (idx != 0)
//         {
//             sum += idx % 10;
//             idx /= 10;
//         }
//         return sum;
//     };

//     if (row >= 0 && row < rows && col >= 0 && col < cols && *(is_visited + row * cols + col) == false && getIdxDigitBitSum(row) + getIdxDigitBitSum(col) <= threshold)
//     {
//         *(is_visited + row * cols + col) = true;
//         movingCountRecursively(threshold, rows, cols, row + 1, col, is_visited);
//         movingCountRecursively(threshold, rows, cols, row - 1, col, is_visited);
//         movingCountRecursively(threshold, rows, cols, row, col - 1, is_visited);
//         movingCountRecursively(threshold, rows, cols, row, col + 1, is_visited);
//     }
// }
// int movingCount(int threshold, int rows, int cols)
// {
//     if (threshold < 0 || rows < 1 || cols < 1)
//         return 0;

//     bool *is_visited = new bool[rows * cols];
//     for (int i = 0; i < rows * cols; i++)
//         is_visited[i] = false;

//     movingCountRecursively(threshold, rows, cols, 0, 0, is_visited);

//     int res = 0;
//     for (int i = 0; i < rows * cols; i++)
//     {
//         if (is_visited[i] == true)
//             ++res;
//     }
//     delete is_visited;
//     return res;
// }

// /*
// 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
// 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；
// 此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；
// 两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
// 请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。
// 最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
// 思路：
// 1）用一个vector来保存各个目录名
// 2）处理.和..
//   a.对于.直接忽略
//   b.对于..弹出一个目录名，并且判断是否到了根目录/
// 3）用/拼接各个目录
// */
// string simplifyPath(string path)
// {
//     auto getOneDir = [](const string &path, size_t &idx) -> string {
//         while (idx < path.size() && path[idx] == '/')
//             ++idx;

//         if (idx == path.size())
//             return string();

//         size_t dir_start = idx;
//         while (idx < path.size() && path[idx] != '/')
//             ++idx;

//         return path.substr(dir_start, idx - dir_start);
//     };

//     if (path.size() <= 1)
//         return path;

//     vector<string> dirs;
//     size_t idx = 0;
//     while (idx < path.size())
//     {
//         string one_dir = getOneDir(path, idx);
//         if (one_dir.empty())
//             break;
//         else if (one_dir == ".")
//             continue;
//         else if (one_dir == "..")
//         {
//             if (!dirs.empty())
//                 dirs.pop_back();
//         }
//         else
//             dirs.push_back(one_dir);
//     }

//     if (dirs.empty())
//         return "/";

//     string res;
//     for (auto dir : dirs)
//     {
//         res.append("/");
//         res.append(dir);
//     }
//     return res;
// }

// /*
// 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
// 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。（拷贝原数组）
// 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。（分为行和列，分别记录该行该列是否有0）
// 你能想出一个常数空间的解决方案吗？
// 思路：
// 1）使用第一行和第一列来记录除第一行和第一列以外的该行或该列是否有0，有的话置为0
// 2）如果第一列或第一行本身有0，使用另外两个变量来保存
// */
// void setZeroes(vector<vector<int>> &matrix)
// {
//     if (matrix.empty() || matrix[0].empty())
//         return;

//     auto rows = matrix.size();
//     auto cols = matrix[0].size();

//     // 第一行是否有0
//     auto first_row_zero = false;
//     // 第一列是否有0
//     auto first_col_zero = false;

//     for (auto i = 0; i < rows; i++)
//     {
//         for (auto j = 0; j < cols; j++)
//         {
//             if (i == 0 && matrix[i][j] == 0)
//                 first_row_zero = true;
//             if (j == 0 && matrix[i][j] == 0)
//                 first_col_zero = true;
//             if (matrix[i][j] == 0)
//             {
//                 matrix[i][0] = 0; // 将所在行的第一个元素置为0
//                 matrix[0][j] = 0; // 将所在列的第一个元素置为0
//             }
//         }
//     }

//     for (auto i = 1; i < rows; i++)
//     {
//         for (auto j = 1; j < cols; j++)
//         {
//             // 根据所在行或列的第一个元素是否为0决定是否置为0
//             if (matrix[i][0] == 0 || matrix[0][j] == 0)
//                 matrix[i][j] = 0;
//         }
//     }

//     if (first_row_zero) // 将第一行置为0
//     {
//         for (auto j = 0; j < cols; j++)
//             matrix[0][j] = 0;
//     }

//     if (first_col_zero) // 将第一列置为0
//     {
//         for (auto i = 0; i < rows; i++)
//             matrix[i][0] = 0;
//     }
// }

// /*
// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
// 每行中的整数从左到右按升序排列。
// 每行的第一个整数大于前一行的最后一个整数。
// 思路：
// 1）也就是说按一维展开是升序序列
// 2）二分搜索，将一维坐标k转换成二维坐标(x, y)。（x = k / cols, y = k % cols）
// */
// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     if (matrix.empty() || matrix[0].empty())
//         return false;

//     auto rows = matrix.size();
//     auto cols = matrix[0].size();
//     auto one_dim_size = rows * cols;
//     int start = 0;
//     int stop = one_dim_size - 1;

//     while (start < stop)
//     {
//         auto middle = (start + stop) / 2;
//         auto t = matrix[middle / cols][middle % cols];
//         if (t == target)
//             return true;
//         else if (t < target)
//             start = middle + 1;
//         else
//             stop = middle - 1;
//     }

//     if (start == stop && matrix[start / cols][start % cols] == target)
//         return true;
//     return false;
// }

// /*
// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
// 注意:
// 不能使用代码库中的排序函数来解决这道题。
// 思路：
// 1）三指针法，一个指向开头p0，代表0，一个指向结尾p2，代表2，一个指向当前元素p
// 2）如果当前元素是0，和*p0交换，++p0；如果当前元素是2，和*p2交换，--p2；否则++p
// 3）当p>p2结束
// */
// void sortColors(vector<int> &nums)
// {
//     if (nums.size() <= 1)
//         return;

//     using std::swap;

//     int p0 = 0, p2 = nums.size() - 1, p = 0;
//     while (p <= p2)
//     {
//         if (nums[p] == 0)
//         {
//             swap(nums[p], nums[p0]);
//             ++p0;
//             if (p < p0) // 推进p，p前面的已经都是0
//                 p = p0;
//         }
//         else if (nums[p] == 2)
//         {
//             swap(nums[p], nums[p2]);
//             --p2;
//         }
//         else
//             ++p;
//     }
// }

// /*
// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
// 示例:
// 输入: n = 4, k = 2
// 输出:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// */
// void combineRecursively(vector<vector<int>> &res, vector<int> &temp, int n, int start, int k)
// {
//     if (k == 0)
//     {
//         res.push_back(temp);
//         return;
//     }

//     for (int i = start; i <= n && (i + k - 1) <= n; i++)
//     {
//         temp.push_back(i);
//         combineRecursively(res, temp, n, i + 1, k - 1);
//         temp.pop_back();
//     }
// }
// vector<vector<int>> combine(int n, int k)
// {
//     if (n < 1 || k < 1 || k > n)
//         return {{}};

//     if (n == k && k == 1)
//         return {{1}};

//     vector<vector<int>> res;
//     vector<int> temp;

//     combineRecursively(res, temp, n, 1, k);

//     return res;
// }

// /*
// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
// 说明：解集不能包含重复的子集。
// 示例:
// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
// 思路：
// 1）初始为{ {} }
// 2）然后每次对集合中的每个集合插入一个元素
// */
// vector<vector<int>> subsets(vector<int> &nums)
// {
//     if (nums.empty())
//         return {{}};

//     vector<vector<int>> res;
//     res.reserve(static_cast<size_t>(std::pow(2, nums.size())));
//     res.push_back({});
//     for (auto num : nums)
//     {
//         auto length = res.size();
//         for (size_t i = 0; i < length; i++)
//         {
//             auto t = res[i];
//             t.push_back(num);
//             res.push_back(t);
//         }
//     }

//     return res;
// }

// /*
// 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
// 示例 1:
// 给定 nums = [1,1,1,2,2,3],
// 函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
// 你不需要考虑数组中超出新长度后面的元素。
// 示例 2:
// 给定 nums = [0,0,1,1,1,1,2,3,3],
// 函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
// 你不需要考虑数组中超出新长度后面的元素。
// */
// int removeDuplicates(vector<int> &nums)
// {
//     if (nums.size() < 2)
//         return nums.size();
//     int len = 2;
//     for (int i = 2; i < nums.size(); i++)
//     {
//         if (nums[i] != nums[len - 2])
//             nums[len++] = nums[i];
//     }
//     return len;
// }

// /*
// 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
// 你应当保留两个分区中每个节点的初始相对位置。
// 示例:
// 输入: head = 1->4->3->2->5->2, x = 3
// 输出: 1->2->2->4->3->5
// 思路：
// 1）设置两个链表，一个为小于x的节点组成的，另一个不小于x的节点组成
// 2）连接两个链表即可
// */
// ListNode *partition(ListNode *head, int x)
// {
//     if (head == nullptr || head->next == nullptr)
//         return head;

//     ListNode less_list(-1), great_list(-1);
//     ListNode *less_p = &less_list, *great_p = &great_list;
//     while (head != nullptr)
//     {
//         if (head->val < x)
//         {
//             less_p->next = head;
//             less_p = less_p->next;
//         }
//         else
//         {
//             great_p->next = head;
//             great_p = great_p->next;
//         }
//         head = head->next;
//     }
//     great_p->next = nullptr;
//     less_p->next = great_list.next;
//     return less_list.next;
// }

// /*
// 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
// 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
// 示例 1:
// 输入: 2
// 输出: [0,1,3,2]
// 解释:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// 对于给定的 n，其格雷编码序列并不唯一。
// 例如，[0,2,3,1] 也是一个有效的格雷编码序列。
// 00 - 0
// 10 - 2
// 11 - 3
// 01 - 1
// 示例 2:
// 输入: 0
// 输出: [0]
// 解释: 我们定义格雷编码序列必须以 0 开头。
//    给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
//    因此，当 n = 0 时，其格雷编码序列为 [0]。
// 思路：
// 关键是搞清楚格雷编码的生成过程, G(i) = i ^ (i >> 1);
// 如 n = 3:
//   G(0) = 0 ^ 0 = 000 ^ 000 = 000,
//   G(1) = 1 ^ 0 = 001 ^ 000 = 001
//   G(2) = 2 ^ 1 = 010 ^ 001 = 011
//   G(3) = 3 ^ 1 = 011 ^ 001 = 010
//   G(4) = 4 ^ 2 = 100 ^ 010 = 110
//   G(5) = 5 ^ 2 = 101 ^ 010 = 111
//   G(6) = 6 ^ 3 = 110 ^ 011 = 101
//   G(7) = 7 ^ 3 = 111 ^ 011 = 100
// */
// vector<int> grayCode(int n)
// {
//     vector<int> res;
//     int length = 1 << n;
//     res.reserve(length);
//     for (int i = 0; i < length; i++)
//         res.push_back(i ^ (i >> 1));
//     return res;
// }

// /*
// 一条包含字母 A-Z 的消息通过以下方式进行了编码：
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// 给定一个只包含数字的非空字符串，请计算解码方法的总数。
// 示例 1:
// 输入: "12"
// 输出: 2
// 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
// 示例 2:
// 输入: "226"
// 输出: 3
// 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
// 思路：
// 1）字符串中的字符，要么按一位解释，要么按两位解释，类似青蛙跳，使用DP算法来解
// 2）和青蛙跳相比，约束条件更多
//   a.0不能单独解码
//   b.两位解码时，第一位要么是1；或者，第一位为2，第二位0~6（即在10~26范围里）
// 3）举个例子：
//   121205
//   解码到'5'时，f(6) = f(5) + f(4)，f(x)代表到x位时的总数，也就是说
//   121205为12120 5和1212 05的解码总数加起来（最多只能连续解码两位）
//   a.解码一位，由于'5'不为'0'，所以12120 5这种解码通过（注意并不会在12120的解码方法上再增加一种，只是和它解码方法一样多）
//   b.解码两位，由于'05'并不是‘10’~'26'中的，所以1212 05这种解码方法不行
// */
// int numDecodings(const string &s)
// {
//     int length = s.size();
//     if (s.empty() || (length == 1 && s[0] == '0'))
//         return 0;
//     if (length == 1)
//         return 1;

//     vector<int> dp(length, 0);

//     // dp[0]
//     dp[0] = (s[0] == '0' ? 0 : 1);

//     // dp[1]
//     dp[1] = 0;
//     if (s[0] != '0' && s[1] != '0')
//         ++dp[1];
//     if (s[0] == '1' || s[0] == '2' && s[1] <= '6')
//         ++dp[1];

//     // dp[3] ~ dp[length - 1]
//     for (int i = 2; i < length; i++)
//     {
//         dp[i] = (s[i] == '0' ? 0 : dp[i - 1]);                 // 解码一位
//         if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') // 解码两位
//             dp[i] += dp[i - 2];
//     }
//     return dp.back();

//     /*dp[0] = 1;
//     for (int i = 0; i < length; i++)
//     {
//       dp[i + 1] = (s[i] == '0' ? 0 : dp[i]);
//       if (i > 0 && (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6'))
//         dp[i + 1] += dp[i - 1];
//     }
//     return dp.back();*/
// }

// /*
// 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
// 说明:
// 1 ≤ m ≤ n ≤ 链表长度。
// 示例:
// 输入: 1->2->3->4->5->nullptr, m = 2, n = 4
// 输出: 1->4->3->2->5->nullptr
// 思路：
// 1）从第一个节点开始遍历，遍历到第m个节点，记录第m个节点之前的节点和当前节点
// 2）从第m个节点开始翻转，直到第n个节点
// 3）根据记录的信息连接翻转后的链表
// */
// ListNode *reverseBetween(ListNode *head, int m, int n)
// {
//     if (head == nullptr || m < 1 || n < 1 || m == n || m > n)
//         return head;

//     if (head->next == nullptr)
//         return head;

//     unique_ptr<ListNode> dummy(new ListNode(-1)); // 增加一个节点，用于处理m=1的情况
//     dummy->next = head;
//     int cnt = 1;                                       // 当前节点数
//     ListNode *pre = dummy.get(), *now = pre->next;     // 前一个节点，现在的节点
//     ListNode *pre_m_node = nullptr, *m_node = nullptr; // 第m个节点的前一个节点，第m个节点
//     while (cnt <= n && now != nullptr)
//     {
//         if (cnt == m) // 到达第m个节点，记录信息
//         {
//             pre_m_node = pre;
//             m_node = now;
//         }

//         if (cnt > m) // m节点的后一个节点开始进行翻转
//         {
//             ListNode *nxt = now->next;
//             now->next = pre;
//             pre = now;
//             now = nxt;
//             ++cnt;
//         }
//         else // 继续遍历直到第m个节点
//         {
//             pre = now;
//             now = now->next;
//             ++cnt;
//         }
//     }
//     // 重新连接翻转后的链表
//     m_node->next = now;
//     pre_m_node->next = pre;

//     return dummy->next;
// }

// /*
// 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
// 示例:
// 输入: "25525511135"
// 输出: ["255.255.11.135", "255.255.111.35"]
// 思路：递归
// */
// void restoreIpAddressesRecursively(vector<string> &res, vector<string> &ip, const string &s, int idx)
// {
//     if (ip.size() < 4 && idx >= s.size())
//         return;

//     if (ip.size() == 4)
//     {
//         if (idx >= s.size())
//         {
//             string t(ip[0]);
//             for (int i = 1; i < 4; i++)
//             {
//                 t.push_back('.');
//                 t.append(ip[i]);
//             }
//             res.push_back(std::move(t));
//         }
//         return;
//     }

//     if (idx + 1 <= s.size())
//     {
//         ip.push_back(s.substr(idx, 1));
//         restoreIpAddressesRecursively(res, ip, s, idx + 1);
//         ip.pop_back();
//     }
//     if (idx + 2 <= s.size())
//     {
//         string st = s.substr(idx, 2);
//         int t = std::stoi(st);
//         if (t >= 10)
//         {
//             ip.push_back(std::move(st));
//             restoreIpAddressesRecursively(res, ip, s, idx + 2);
//             ip.pop_back();
//         }
//     }
//     if (idx + 3 <= s.size())
//     {
//         string st = s.substr(idx, 3);
//         int t = std::stoi(st);
//         if (t <= 255 && t >= 100)
//         {
//             ip.push_back(std::move(st));
//             restoreIpAddressesRecursively(res, ip, s, idx + 3);
//             ip.pop_back();
//         }
//     }
// }
// vector<string> restoreIpAddresses(string s)
// {
//     int length = s.size();
//     vector<string> res;
//     if (length < 4 || length > 12)
//         return res;

//     vector<string> ip;
//     ip.reserve(4);
//     restoreIpAddressesRecursively(res, ip, s, 0);

//     return res;
// }

// /*
// 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
// 示例:
// 输入: 3
// 输出: 5
// 解释:
// 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

//    1         3     3      2      1
//   \       /     /      / \      \
//    3     2     1      1   3      2
//   /     /       \                 \
//    2     1         2                 3
// 思路：
// 1）动态规划
// 2）假设n个节点存在二叉排序树的个数是G(n)，令f(i)为以i为根的二叉搜索树的个数，即有:G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)
// 3）n为根节点，当i为根节点时，其左子树节点个数为[1,2,3,...,i-1]，右子树节点个数为[i+1,i+2,...n]，所以当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，即f(i) = G(i-1)*G(n-i)
// 4）上面两式可得:G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)
// */
// int numTrees(int n)
// {
//     if (n <= 1)
//         return 1;

//     vector<int> res(n + 1, 0);
//     res[0] = res[1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         for (int j = 0; j <= i - 1; j++)
//         {
//             res[i] += res[j] * res[i - 1 - j];
//         }
//     }
//     return res[n];
// }

// /*
// 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
// 示例:
// 输入: 3
// 输出:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// 解释:
// 以上的输出对应以下 5 种不同结构的二叉搜索树：
//    1         3     3      2      1
//   \       /     /      / \      \
//    3     2     1      1   3      2
//   /     /       \                 \
//    2     1         2                 3
// 思路：
// 1）动态规划的思想
// 2）在原来的结果中，插入一个新节点
//   a.新节点大于所有的节点
//   b.新节点作为根，旧树挂在左边
//   c.新节点插入旧树右侧（原因见a），右侧可能有子树，一层一层插入
// */
// TreeNode *copyTree(TreeNode *root) // 先根遍历拷贝树
// {
//     if (root == nullptr)
//         return nullptr;
//     else
//     {
//         TreeNode *dup = new TreeNode(root->val);
//         dup->left = copyTree(root->left);
//         dup->right = copyTree(root->right);
//         return dup;
//     }
// }
// vector<TreeNode *> generateTrees(int n)
// {
//     if (n < 1)
//         return vector<TreeNode *>();

//     if (n == 1)
//         return vector<TreeNode *>({new TreeNode(1)});

//     vector<TreeNode *> res;
//     res.push_back(new TreeNode(1)); // 初始只有一棵树，并且只有一个节点      1

//     int pre_length = 0, now_length; // 用于确定上一次的结果区间（res包含了所有的结果，但本次只需要上次的结果）
//     for (int i = 2; i <= n; i++)    // 每次插入一个新的节点
//     {
//         now_length = res.size();
//         for (int j = pre_length; j < now_length; j++) // 根据上一次的结果，对每棵树进行插入
//         {
//             TreeNode *t = new TreeNode(i); // 新节点作为根
//             t->left = res[j];              // 旧树直接挂在左侧（不用拷贝，整颗旧树直接利用就行）
//             res.push_back(t);

//             TreeNode *now = res[j];
//             while (now->right != nullptr) // 插入右侧，逐层插入
//             {
//                 t = new TreeNode(i);
//                 TreeNode *t_right = now->right;
//                 now->right = nullptr;               // 在需要插入的地方断开
//                 TreeNode *up = copyTree(res[j]);    // 拷贝得到新节点插入需要的上半部分树
//                 TreeNode *down = copyTree(t_right); // 拷贝得到新节点插入需要的下半部分树
//                 now->right = t_right;               // 拷贝完毕，恢复旧树的连接
//                 TreeNode *t_now = up;
//                 while (t_now->right != nullptr) // 在拷贝的上半部分树中找到插入点（最右侧）
//                     t_now = t_now->right;
//                 t_now->right = t;  // 在拷贝的上半部分树中插入新节点
//                 t->left = down;    // 将拷贝的下半部分树挂在新节点左侧
//                 res.push_back(up); // 完成新节点插入，得到一颗新树

//                 now = now->right;
//             }
//             // 新节点插入旧树的最右侧
//             t = new TreeNode(i);
//             TreeNode *up = copyTree(res[j]);
//             TreeNode *t_now = up;
//             while (t_now->right != nullptr)
//                 t_now = t_now->right;
//             t_now->right = t;
//             res.push_back(up);
//         }
//         pre_length = now_length;
//     }

//     return vector<TreeNode *>(res.begin() + pre_length, res.end());
// }
// // 动态规划+递归
// //vector<TreeNode*> generateTrees(int n) {
// //    if (n == 0)
// //        return vector<TreeNode*>{};
// //    return generateTreesRecursively(1, n);
// //}
// //vector<TreeNode*> generateTreesRecursively(int begin, int end)
// //{
// //    vector<TreeNode*> res;
// //    if (begin > end)
// //    {
// //        res.push_back(nullptr);
// //        return res;
// //    }
// //    for (int i = begin; i <= end; ++i) // 在节点值为i处断开
// //    {
// //        // 递归求解所有可能的左子树
// //        vector<TreeNode*> left_trees = generateTreesRecursively(begin, i - 1);
// //        // 递归求解所有可能的右子树
// //        vector<TreeNode*> right_trees = generateTreesRecursively(i + 1, end);
// //        // 将这些所有可能的左右子树在节点值为i处重新拼接起来
// //        for (auto l : left_trees)
// //        {
// //            for (auto r : right_trees)
// //            {
// //                TreeNode* root = new TreeNode(i);
// //                root->left = l;
// //                root->right = r;
// //                res.push_back(root);
// //            }
// //        }
// //
// //    }
// //    return res;
// //}
// // 列出所有的结果，有重合
// //TreeNode *copyTree(TreeNode *root)
// //{
// //    if (root == nullptr)
// //        return nullptr;
// //    else
// //    {
// //        TreeNode *dup = new TreeNode(root->val);
// //        dup->left = copyTree(root->left);
// //        dup->right = copyTree(root->right);
// //        return dup;
// //    }
// //}
// //pair<TreeNode *, int> insertTree(TreeNode* root, int val)
// //{
// //    TreeNode *t = root;
// //    TreeNode *pre = t;
// //    int side = 0;
// //    while (t != nullptr)
// //    {
// //        pre = t;
// //        if (val > t->val)
// //            t = t->right;
// //        else
// //            t = t->left;
// //    }
// //    if (pre->val < val)
// //        side = 1;
// //    return { pre, side };
// //}
// //void generateTreesRecursively(vector<TreeNode *> &res, const vector<int> &vals, vector<bool> &visited, TreeNode* root, int depth)
// //{
// //    int length = vals.size();
// //    if (depth == length - 1)
// //    {
// //        res.push_back(copyTree(root));
// //        return;
// //    }
// //    for (int i = 0; i < length; i++)
// //    {
// //        if (visited[i])
// //            continue;
// //
// //        visited[i] = true;
// //
// //        auto insert_pos = insertTree(root, vals[i]);
// //        TreeNode *child = new TreeNode(vals[i]);
// //        if (insert_pos.second == 0)
// //            insert_pos.first->left = child;
// //        else
// //            insert_pos.first->right = child;
// //
// //        generateTreesRecursively(res, vals, visited, root, depth + 1);
// //
// //        delete child;
// //        if (insert_pos.second == 0)
// //            insert_pos.first->left = nullptr;
// //        else
// //            insert_pos.first->right = nullptr;
// //
// //        visited[i] = false;
// //    }
// //}
// //vector<TreeNode*> generateTrees(int n)
// //{
// //    if (n < 1)
// //        return vector<TreeNode *>();
// //
// //    if (n == 1)
// //        return vector<TreeNode *>({ new TreeNode(1) });
// //
// //    vector<TreeNode *> res;
// //    vector<int> vals;
// //    vals.reserve(n);
// //    for (int i = 1; i <= n; i++)
// //    {
// //        vals.push_back(i);
// //    }
// //    vector<bool> visited(n, false);
// //
// //    for (int i = 0; i < n; i++)
// //    {
// //        visited[i] = true;
// //        TreeNode *root = new TreeNode(vals[i]);
// //        generateTreesRecursively(res, vals, visited, root, 0);
// //        delete root;
// //        visited[i] = false;
// //    }
// //
// //    return res;
// //}

// /*
// 根据一棵树的中序遍历与后序遍历构造二叉树。
// 注意:
// 你可以假设树中没有重复的元素。
// 例如，给出
// 中序遍历 inorder = [9,3,15,20,7]
// 后序遍历 postorder = [9,15,7,20,3]
// 返回如下的二叉树：
//   3
//    / \
//   9  20
//   /  \
//    15   7
// */
// TreeNode *buildTreeRecursively(unordered_map<int, int> &in_map,
//                                const vector<int> &inorder, const vector<int> &postorder,
//                                int in_start, int in_stop, int post_start, int post_stop)
// {
//     // 根节点的值
//     int root = postorder[post_stop];
//     TreeNode *proot = new TreeNode(root);

//     // 到达叶子节点
//     if (in_start == in_stop && post_start == post_stop)
//         return proot;

//     // 在中序序列中找到根节点下标
//     int in_root_idx = in_map[root];

//     // 计算右子树长度
//     int right_tree_len = in_stop - in_root_idx;
//     // 计算右子树在后序序列中的起始下标
//     int right_tree_post_start = post_stop - right_tree_len;

//     // 存在右子树
//     if (right_tree_len > 0)
//     {
//         proot->right = buildTreeRecursively(in_map, inorder, postorder,
//                                             in_root_idx + 1, in_stop, right_tree_post_start, post_stop - 1);
//     }
//     // 存在左子树
//     if (right_tree_post_start - post_start > 0)
//     {
//         proot->left = buildTreeRecursively(in_map, inorder, postorder,
//                                            in_start, in_root_idx - 1, post_start, right_tree_post_start - 1);
//     }
//     // 左右子树构建完毕，返回根节点
//     return proot;
// }
// TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
// {
//     if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
//         return nullptr;

//     unordered_map<int, int> in_map; // 使用哈希表加速中序序列中特定元素下标的查找
//     for (int i = 0; i < inorder.size(); i++)
//     {
//         in_map.insert({inorder[i], i});
//     }

//     return buildTreeRecursively(in_map, inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
// }

// /*
// 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
// 示例:
// 给定的有序链表： [-10, -3, 0, 5, 9],
// 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
//     0
//    / \
//    -3   9
//    /   /
//  -10  5
// 思路：
// 1）双指针，快指针走两步，慢指针走一步，每次都到中位数
// 2）以中位数分割，左边的作为左子树，右边的作为右子树
// 3）递归
// */
// TreeNode *sortedListToBSTRecursively(ListNode *head, ListNode *tail)
// {
//     // 空树，返回空
//     if (head == nullptr || head == tail)
//         return nullptr;

//     // 只有一个节点，那么是叶子节点
//     if (head->next == tail)
//         return new TreeNode(head->val);

//     // 找到中间节点
//     ListNode *slow = head, *fast = head;
//     while (fast != tail && fast->next != tail)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // 中间节点作为根节点
//     TreeNode *proot = new TreeNode(slow->val);
//     // 左边节点构建左子树
//     proot->left = sortedListToBSTRecursively(head, slow);
//     // 右边节点构建右子树
//     proot->right = sortedListToBSTRecursively(slow->next, tail);
//     // 返回根节点
//     return proot;
// }
// TreeNode *sortedListToBST(ListNode *head)
// {
//     if (head == nullptr)
//         return nullptr;

//     if (head->next == nullptr)
//         return new TreeNode(head->val);

//     return sortedListToBSTRecursively(head, nullptr);
// }

// /*
// 给定一个二叉树，原地将它展开为链表。
// 例如，给定二叉树
//   1
//    / \
//   2   5
//  / \   \
// 3   4   6
// 将其展开为：
// 1
//  \
//   2
//    \
//   3
//    \
//     4
//      \
//     5
//      \
//       6
// 思路：
// 1）right置为下一个节点，left置空
// 2）如果直接采用前序遍历，会丢失右子树信息，考虑使用后序遍历
// 3）后序遍历处理完左右子树以后
//   a.root->right = root->left（修改之前先保存右子节点）
//   b.root->left = nullptr
//   c.从root出发，得到链表的最后一个节点
//   d.将最后一个节点的后一个节点指向root的原右子节点
// */
// void flatten(TreeNode *root)
// {
//     if (root == nullptr)
//         return;

//     flatten(root->left);
//     flatten(root->right);

//     TreeNode *temp = root->right;  // 保存右子节点
//     root->right = root->left;      // 链接后一个节点
//     root->left = nullptr;          // 左子节点置空
//     while (root->right != nullptr) // 找到链表的最后一个节点
//         root = root->right;
//     root->right = temp; // 链接左右两个链表
// }
// /*
// 思路2：
// 1）中序遍历，每次返回最后一个节点
// 2）保存当前根的左右子节点
// 3）从左子树遍历回来以后，当前根节点的right指向原来的左子树，left置空
// 4）从右子树遍历回来以后，上次左子树遍历得到的最后一个节点指向原来的右子树
// */
// TreeNode *flattenRecursively(TreeNode *root)
// {
//     if (root == nullptr)
//         return nullptr;

//     if (root->left == nullptr && root->right == nullptr)
//         return root;

//     TreeNode *l = root->left;
//     TreeNode *r = root->right;
//     TreeNode *llast = nullptr;
//     TreeNode *rlast = nullptr;

//     if (l != nullptr)
//     {
//         llast = flattenRecursively(l);
//         root->right = l;
//         root->left = nullptr;
//     }

//     if (r != nullptr)
//     {
//         rlast = flattenRecursively(r);
//         if (llast != nullptr)
//         {
//             llast->right = r;
//         }
//         else
//         {
//             root->right = r;
//         }
//     }

//     if (rlast != nullptr)
//         return rlast;
//     else
//         return llast;
// }
// void flatten1(TreeNode *root)
// {
//     flattenRecursively(root);
// }

// /*
// 给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
// 初始状态下，所有 next 指针都被设置为 NULL。
// 思路：
// 1）递归
// 2）从根节点开始
//   a.连接根节点左子节点和右子节点
//   b.如果根节点有右侧节点，连接根节点右子节点和右侧节点的左子节点
// */
// Node *connect(Node *root)
// {
//     if (root == nullptr)
//         return root;

//     if (root->left != nullptr) // 连接根节点的左右子节点
//         root->left->next = root->right;

//     if (root->next != nullptr && root->right != nullptr) // 连接根节点右节点和根节点右侧节点的左子节点
//         root->right->next = root->next->left;

//     connect(root->left);
//     connect(root->right);

//     return root;
// }
// /*
// 思路2：非递归，但原理同上
// */
// Node *connect1(Node *root)
// {
//     if (root == nullptr)
//         return nullptr;

//     Node *pre = root;      // 用于遍历上一层链表节点
//     Node *now = pre->left; // 保存本层的头节点
//     Node *t = nullptr;     // 保存本根节点的右子节点，用于连接本根节点下一个节点的左子节点

//     while (pre->left != nullptr && pre->right != nullptr)
//     {
//         // 连接根节点右节点和根节点右侧节点的左子节点
//         if (t != nullptr)
//             t->next = pre->left;

//         // 连接根节点的左右子节点
//         pre->left->next = pre->right;
//         t = pre->right;

//         pre = pre->next;
//         if (pre == nullptr)
//         {
//             t = nullptr;
//             pre = now;
//             now = pre->left;
//         }
//     }

//     return root;
// }

// /*
// 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
// 例如，给定三角形：
// [
//    [2],
//   [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
// 说明：
// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
// 思路：动态规划，自顶向下
// */
// int minimumTotal(vector<vector<int>> &triangle)
// {
//     int rows = triangle.size();
//     if (rows < 1)
//         throw runtime_error("bad input!");

//     for (int row = 1; row < rows; ++row)
//     {
//         for (int col = 0, cols = triangle[row].size(); col < cols; ++col)
//         {
//             if (col == 0)
//             {
//                 triangle[row][col] += triangle[row - 1][col];
//             }
//             else if (col == cols - 1)
//             {
//                 triangle[row][col] += triangle[row - 1][col - 1];
//             }
//             else
//             {
//                 triangle[row][col] += std::min(triangle[row - 1][col], triangle[row - 1][col - 1]);
//             }
//         }
//     }

//     int ret = triangle[rows - 1][0];
//     for (int col = 1, cols = triangle[rows - 1].size(); col < cols; ++col)
//     {
//         if (triangle[rows - 1][col] < ret)
//             ret = triangle[rows - 1][col];
//     }

//     return ret;
// }
// /*
// 思路2：动态规划，自底向上
// */
// int minimumTotal1(vector<vector<int>> &triangle)
// {
//     int rows = triangle.size();
//     if (rows < 1)
//         throw runtime_error("bad input!");

//     vector<int> dp(rows + 1, 0);

//     for (int row = rows - 1; row >= 0; --row)
//     {
//         for (int col = 0; col <= row; ++col)
//         {
//             dp[col] = std::min(dp[col], dp[col + 1]) + triangle[row][col];
//         }
//     }

//     return dp[0];
// }

// /*
// 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
// 每次转换只能改变一个字母。
// 转换过程中的中间单词必须是字典中的单词。
// 说明:
// 如果不存在这样的转换序列，返回 0。
// 所有单词具有相同的长度。
// 所有单词只由小写字母组成。
// 字典中不存在重复的单词。
// 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

// 示例 1:
// 输入:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// 输出: 5
// 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",返回它的长度 5。

// 示例 2:
// 输入:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// 输出: 0
// 解释: endWord "cog" 不在字典中，所以无法进行转换。

// 思路：
// 1）对字典建立哈希表，加快查找速度
// 2）设定开始集合与结束集合（都是哈希表），实现从开始集合到结束集合的转换
// 3）对开始集合的每个字符串，先从字典中清除（完成了一次转换），然后改变每一位（a-z，进行下一次转换），接着
//     a.查找字典，如果在字典中存在，加入中间集合（哈希表），即转换需要在字典中
//     b.如果在结束集合中存在，得到结果并返回
// 4）比较中间集合和最终集合的大小（期望从小集合到大集合的转换）
//     a.中间集合较小，接下来是中间集合到结束集合的转换
//     b.中间集合较大，接下来是结束集合到中间集合的转换
// */
// int ladderLength(string beginWord, string endWord, vector<string> &wordList)
// {
//     // 建立字典
//     unordered_set<string> wordDict(wordList.begin(), wordList.end());
//     // 结束单词不在字典中，直接返回
//     if (wordDict.find(endWord) == wordDict.end())
//     {
//         return 0;
//     }

//     unordered_set<string> beginSet{beginWord}; // 开始集合
//     unordered_set<string> endSet{endWord};     // 结束集合
//     int step = 1;                              // 最短转换序列长度
//     for (; !beginSet.empty();)
//     {
//         unordered_set<string> tempSet; // 中间集合
//         ++step;
//         for (const auto &s : beginSet) // 从字典中移除开始集合中的元素，即完成一次转换
//         {
//             wordDict.erase(s);
//         }
//         for (const auto &s : beginSet) // 对开始集合的每个字符串
//         {
//             for (int i = 0; i < s.size(); ++i) // 对每个字符串的每个字符
//             {
//                 string str = s;
//                 for (char c = 'a'; c <= 'z'; ++c) // 改变每个字符为a-z，即进行下一次可能的所有转换
//                 {
//                     str[i] = c;
//                     if (wordDict.find(str) == wordDict.end()) // 在字典中查找是否存在，即转换需要在字典中存在
//                     {
//                         continue;
//                     }
//                     if (endSet.find(str) != endSet.end()) // 在结束集合中存在，返回结果
//                     {
//                         return step;
//                     }
//                     tempSet.insert(str); // 插入中间集合
//                 }
//             }
//         }
//         if (tempSet.size() < endSet.size()) // 中间集合更小，那么就进行中间集合到结束集合的转换
//         {
//             beginSet = std::move(tempSet);
//         }
//         else // 中间集合更大，那么就进行结束集合到中间集合的转换
//         {
//             beginSet = endSet;
//             endSet = std::move(tempSet);
//         }
//     }
//     return 0;
// }

// /*
// 给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）。图中的每个节点都包含它的值 val（Int） 和其邻居的列表（list[Node]）。
// 提示：
// 节点数介于 1 到 100 之间。
// 无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
// 由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
// 必须将给定节点的拷贝作为对克隆图的引用返回。
// 思路：
// 1）图的遍历
// 2）由于是无向连通图，可能有环，需要记录下所有已经拷贝过的节点，防止重复拷贝
// */
// UndirectedGraphNode *cloneGraphRecursively(unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &node_map,
//                                            UndirectedGraphNode *node)
// {
//     auto iter = node_map.find(node);
//     if (iter != node_map.end()) // 已经有拷贝，直接返回拷贝
//     {
//         return iter->second;
//     }
//     else // 没有拷贝
//     {
//         // 进行拷贝
//         UndirectedGraphNode *t = new UndirectedGraphNode();
//         t->val = node->val;
//         // 记录下已拷贝和拷贝节点
//         node_map[node] = t;
//         (t->neighbors).reserve((node->neighbors).size());
//         // 图的搜索
//         for (const auto &neigh : node->neighbors)
//         {
//             (t->neighbors).emplace_back(cloneGraphRecursively(node_map, neigh));
//         }
//         return t;
//     }
// }
// UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
// {
//     if (node == nullptr)
//         return node;
//     if ((node->neighbors).empty())
//         return new UndirectedGraphNode(node->val, {});

//     // 旧节点到新节点的哈希表，为了防止重复拷贝
//     unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> node_map;
//     return cloneGraphRecursively(node_map, node);
// }

// /*
// 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
// 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
// 说明:
// 如果题目有解，该答案即为唯一答案。
// 输入数组均为非空数组，且长度相同。
// 输入数组中的元素均为非负数。

// 示例:
// 输入:
// gas  = [1,2,3,4,5]
// cost = [3,4,5,1,2]
// 输出: 3
// 解释:
// 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
// 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
// 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
// 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
// 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
// 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
// 因此，3 可为起始索引。
// 思路：
// 1）所有站储备的总油量>=消耗的总油量，即总的剩余油量>=0
// 2）从站点0开始出发，计算从当前站到下一站后剩余的油量
//     a.如果剩余油量<0，说明从之前的起点出发，不足以到达当前站点的下一站，那么起点只能更改为当前站点的下一站，并重新开始计算剩余油量
//     b.如果剩余油量>=0，说明从之前的起点出发，可以到达当前站点的下一站，继续往下计算
// */
// int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
// {
//     // 总的剩余油量，当前站点到下一个站点后的剩余油量，起点
//     int rest = 0, run = 0, start = 0;
//     for (int i = 0; i < gas.size(); ++i)
//     {
//         run += (gas[i] - cost[i]);
//         rest += (gas[i] - cost[i]);
//         if (run < 0) // 从之前的起点出发，不足以到达当前站点的下一站
//         {
//             start = i + 1; // 起点更改为当前站点的下一站
//             run = 0;
//         }
//     }
//     return rest < 0 ? -1 : start;
// }
// /*
// 思路2：
// 1）所有站储备的总油量>=消耗的总油量，即总的剩余油量>=0
// 2）双指针法
//     a.一个指针cur从0开始，从前往后走
//     b.一个指针start作为出发点，也从0开始，从后往前走
// 3）当cur往后走发现剩余油量不够，那么start就得往前走，即更换起点以期望油量足够
// */
// int canCompleteCircuit1(vector<int> &gas, vector<int> &cost)
// {
//     int cur = 0;            // 往后走的指针
//     int start = gas.size(); // 起点指针，往前走（初始为总站数，其实就是和cur一样，为0）
//     int total_left = 0;     // 总剩余油量

//     do
//     {
//         if (total_left + gas[cur] - cost[cur] >= 0)
//         {
//             total_left += (gas[cur] - cost[cur]);
//             ++cur;
//         }
//         else
//         {
//             --start;
//             total_left += (gas[start] - cost[start]);
//         }
//     } while (cur != start);

//     return total_left >= 0 ? start % gas.size() : -1;
// }

// /*
// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

// 示例 1:
// 输入: [2,2,3,2]
// 输出: 3

// 示例 2:
// 输入: [0,1,0,1,0,1,99]
// 输出: 99
// 思路：
// 1）位运算
// 2）对输入的所有数据累加每一位的1的个数
// 3）如果该位累加的结果是3的倍数，说明都是重复的3个数，把该位置为0，否则置为1
// */
// int singleNumber(vector<int> &nums)
// {
//     int res = 0;
//     for (int i = 0; i < 32; ++i) // 对于每一位
//     {
//         int sum = 0;
//         for (int j = 0; j < nums.size(); ++j) // 累加所有数据的该位的1的个数
//         {
//             sum += (nums[j] >> i) & 1;
//         }
//         res |= (sum % 3) << i; // 3的倍数置为0，否则置为1
//     }
//     return res;
// }
// /*
// 思路2：https://blog.csdn.net/qq_41231926/article/details/85758627
// 1）位运算
// 2）对于某一位b，3次重复后置为0，那么需要一个2位的计数器b2b1
//     a.b为0
//         00 + 0 = 00
//         01 + 0 = 01
//         10 + 0 = 10
//     b.b为1
//         00 + 1 = 01
//         01 + 1 = 10
//         10 + 1 = 00
// 3）b为0时保持不变
// 4）b1为1，当且仅当b1=0，且b=1
//    b2为1，当且仅当b1=1，且b=1
//    ...
//    bm为1，当且仅当bm-1=bm-2=bm-3=...=b1=1，且b=1
// 5）当计数到达3次以后，即b2b1=11时，需要将b2和b1置零
// 6）以上讨论的是某一位计数的情况，那么32位的话，需要32个两位的计数器，由于每一位的计数操作独立，所以需要两个32位计数器就行了
// */
// int singleNumber1(vector<int> &nums)
// {
//     // b1，b2，置零掩码
//     int x1 = 0, x2 = 0, mask = 0;
//     for (int num : nums)
//     {
//         x2 ^= x1 & num;    // b2为1，当且仅当b1 = 1，且b = 1
//         x1 ^= num;         // b1为1，当且仅当b=1
//         mask = ~(x1 & x2); // b1和b2都为1，需要置零，计算掩码
//         x2 &= mask;
//         x1 &= mask;
//     }
//     return x1;
// }

// /*
// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
// 说明：
// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。

// 示例 1：
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

// 示例 2：
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。注意你可以重复使用字典中的单词。

// 示例 3：
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false

// 思路：
// 1）动态规划
// 2）用f(i)表示s[0:i)是否可以被拆分
//     a.f(0) = true
//     b.f(i) = true, s.t. f(j) = true && s[j:i) ∈ dict s.t. j >= 0 && j < i
// 3）由于词典的最大长度固定，假设为m，那么j的搜索范围为[i-m:i)
// */
// bool wordBreak(const string &s, const vector<string> &wordDict)
// {
//     if (s.empty() || wordDict.empty())
//         return false;

//     unordered_set<string> dict(wordDict.begin(), wordDict.end()); // 创建哈希表，加快单词查找速度
//     int length = s.size();

//     int max_word_len = wordDict[0].size(); // 词典中最长的单词长度
//     for (int i = 1, sz = wordDict.size(); i < sz; ++i)
//     {
//         int sz_t = wordDict[i].size();
//         if (sz_t > max_word_len)
//             max_word_len = sz_t;
//     }

//     vector<bool> dp(length + 1, false);
//     dp[0] = true;
//     for (int i = 1; i <= length; ++i) // 动态规划填表
//     {
//         for (int j = std::max(i - max_word_len, 0); j < i; ++j) // 当前可拆分=之前某处可拆分+之前某处到当前位置的子字符串存在于字典
//         {
//             if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
//             {
//                 dp[i] = true;
//                 break;
//             }
//         }
//     }

//     return dp[length];
// }

// /*
// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
// 示例 1:
// 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
// 示例 2:
// 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
// 思路：
// 1）原地重排，不借助其他数据结构
// 2）快慢指针找到中点，分成了两部分
// 3）对后半部分原地翻转
// 4）将翻转后的后半部分与前半部分交替连接起来
// */
// void reorderList(ListNode *head)
// {
//     // 空指针、一个节点、两个节点时不用重排
//     if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
//         return;

//     // 快慢指针寻找中点
//     ListNode *slow = head->next, *fast = slow->next;
//     while (fast != nullptr && fast->next != nullptr)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     ListNode *nxt = slow->next; // 后半部分的头节点
//     slow->next = nullptr;       // 前半部分尾节点的处理

//     // 翻转后半部分
//     ListNode *pre_t = nxt;
//     ListNode *nxt_t = pre_t->next;
//     while (nxt_t != nullptr)
//     {
//         ListNode *t = nxt_t->next;
//         nxt_t->next = pre_t;
//         pre_t = nxt_t;
//         nxt_t = t;
//     }
//     nxt->next = nullptr; // 翻转之后的尾节点的处理
//     nxt = pre_t;         // 翻转后的后半部分头节点

//     // 交替连接起来
//     ListNode *pre = head;
//     while (nxt != nullptr)
//     {
//         ListNode *t = nxt;
//         nxt = nxt->next;
//         t->next = pre->next;
//         pre->next = t;
//         pre = pre->next->next;
//     }
// }

// // 给定一个二叉树，返回它的 前序 遍历。
// vector<int> preorderTraversal(TreeNode *root)
// {
//     vector<int> res;
//     if (root == nullptr)
//         return res;

//     stack<TreeNode *> st;
//     TreeNode *p = root;
//     while (p != nullptr)
//     {
//         res.push_back(p->val);
//         if (p->right != nullptr)
//             st.push(p->right);
//         if (p->left != nullptr)
//         {
//             p = p->left;
//         }
//         else
//         {
//             if (st.empty())
//             {
//                 p = nullptr;
//             }
//             else
//             {
//                 p = st.top();
//                 st.pop();
//             }
//         }
//     }

//     return res;
// }

// /*
// 对链表进行插入排序。
// 从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
// 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
// 插入排序算法：
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
// 重复直到所有输入数据插入完为止。
// 示例 1：
// 输入: 4->2->1->3
// 输出: 1->2->3->4
// 示例 2：
// 输入: -1->5->3->4->0
// 输出: -1->0->3->4->5
// */
// ListNode *insertionSortList(ListNode *head)
// {
//     if (head == nullptr || head->next == nullptr)
//         return head;

//     ListNode **sorted_head = &head;           // 已排序头节点
//     ListNode *sorted_tail = head;             // 已排序尾节点
//     ListNode *to_be_sorted_head = head->next; // 待排序头节点
//     (*sorted_head)->next = nullptr;

//     while (to_be_sorted_head != nullptr)
//     {
//         ListNode *temp_next = to_be_sorted_head->next;
//         if ((*sorted_head)->val >= to_be_sorted_head->val) // 插入已排序头节点之前
//         {
//             to_be_sorted_head->next = *sorted_head;
//             *sorted_head = to_be_sorted_head;
//         }
//         else
//         {
//             if (sorted_tail->val < to_be_sorted_head->val) // 插入已排序尾节点之后
//             {
//                 to_be_sorted_head->next = nullptr;
//                 sorted_tail->next = to_be_sorted_head;
//                 sorted_tail = to_be_sorted_head;
//             }
//             else // 插入已排序序列中间
//             {
//                 ListNode *pre = *sorted_head;
//                 ListNode *now = pre->next;
//                 while (now != nullptr && now->val < to_be_sorted_head->val)
//                 {
//                     pre = now;
//                     now = now->next;
//                 }
//                 to_be_sorted_head->next = now;
//                 pre->next = to_be_sorted_head;
//             }
//         }
//         to_be_sorted_head = temp_next;
//     }

//     return *sorted_head;
// }

// /*
// 单向链表排序
// 思路：归并排序
// */
// ListNode *Merge(ListNode *start1, ListNode *start2)
// {
//     ListNode *dummy = new ListNode(INT_MIN);
//     ListNode *p = dummy;
//     while (start1 != nullptr && start2 != nullptr)
//     {
//         if (start1->val < start2->val)
//         {
//             p->next = start1;
//             start1 = start1->next;
//         }
//         else
//         {
//             p->next = start2;
//             start2 = start2->next;
//         }
//         p = p->next;
//     }
//     if (start1 == nullptr)
//         p->next = start2;
//     if (start2 == nullptr)
//         p->next = start1;
//     ListNode *ret = dummy->next;
//     delete dummy;
//     return ret;
// }
// ListNode *MergeSort(ListNode *p)
// {
//     if (p == nullptr || p->next == nullptr)
//         return p;

//     ListNode *slow = p, *fast = slow->next->next;
//     while (fast != nullptr && fast->next != nullptr)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     ListNode *left = p;
//     ListNode *right = slow->next;
//     slow->next = nullptr;
//     ListNode *start1 = MergeSort(left);
//     ListNode *start2 = MergeSort(right);

//     return Merge(start1, start2);
// }
// ListNode *sortList(ListNode *head)
// {
//     if (head == nullptr || head->next == nullptr)
//         return head;

//     return MergeSort(head);
// }

// /*
// 峰值元素是指其值大于左右相邻值的元素。
// 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
// 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
// 你可以假设 nums[-1] = nums[n] = -∞。

// 示例 1:
// 输入: nums = [1,2,3,1]
// 输出: 2
// 解释: 3 是峰值元素，你的函数应该返回其索引 2。

// 示例 2:
// 输入: nums = [1,2,1,3,5,6,4]
// 输出: 1 或 5
// 解释: 你的函数可以返回索引 1，其峰值元素为 2；
//      或者返回索引 5， 其峰值元素为 6。
// 说明:
// 你的解法应该是 O(logN) 时间复杂度的。
// 思路：
// 1）如果第0个元素是峰值，必有nums[n] < nums[0] && nums[0] > nums[1]
// 2）如果第1个元素是峰值，必有nums[0] < nums[1] && nums[1] > nums[2]
// 3）如果第2个元素是峰值，必有nums[1] < nums[2] && nums[2] > nums[1]
// ...
// 4）并且nums[i] ≠ nums[i+1]，也就是说，如果i之前的都不是峰值，那么nums[0]~nums[i]是递增序列，只需要判断nums[i] > nums[i + 1]就可以知道nums[i]是不是峰值
// 5）那么可以使用二分法
//     a.如果nums[middle] > nums[middle + 1]，那么nums[middle]前面的（包括自己）肯定存在峰值
//     b.如果nums[middle] <= nums[middle + 1]，那么nums[middle]不可能为峰值，峰值肯定在nums[middle]后面
// */
// int findPeakElement(const vector<int> &nums)
// {
//     if (nums.size() == 1)
//         return 0;

//     int start = 0, stop = nums.size() - 1;
//     while (start < stop)
//     {
//         int middle = (start + stop) / 2;

//         if (nums[middle] <= nums[middle + 1])
//             start = middle + 1;
//         else
//             stop = middle;
//     }
//     return start;
// }

// /*
// 所有 DNA 由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。
// 编写一个函数来查找 DNA 分子中所有出现超过一次的10个字母长的序列（子串）。
// 示例:
// 输入: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// 输出: ["AAAAACCCCC", "CCCCCAAAAA"]
// 思路1：
// 1）遍历所有10个字符长的子串
// 2）用哈希表存储已出现的子串
// 3）再次遇到时，加入结果集
// */
// vector<string> findRepeatedDnaSequences(const string &s)
// {
//     int len = s.size();
//     if (len <= 10)
//         return vector<string>();

//     unordered_set<string> res;
//     unordered_set<string> m;
//     string t;
//     for (int i = 0, length = len - 9; i < length; ++i)
//     {
//         t = s.substr(i, 10);
//         if (m.find(t) == m.end())
//         {
//             m.insert(t);
//         }
//         else
//         {
//             res.insert(std::move(t));
//         }
//     }

//     return vector<string>(res.begin(), res.end());
// }
// /*
// 思路2：
// 1）只有A，C，G 和 T共四个字符，考虑将10个字符长的子串转化为数字
//     a.四个字符用两位二进制可表示，那么10个字符的子串可以用20位二进制表示
//     b.那么可以用2^20长的bool数组作为哈希表存储所有情况
// 2）同思路1，遍历所有的10字符长的子串，只不过转换成20位二进制进行哈希
// */
// vector<string> findRepeatedDnaSequences1(const string &s)
// {
//     int len = s.size();
//     if (len <= 10)
//         return vector<string>();

//     auto toInt = [](char c) -> int {
//         if (c == 'A')
//             return 0;
//         if (c == 'C')
//             return 1;
//         if (c == 'G')
//             return 2;
//         return 3;
//     };

//     vector<string> res;
//     vector<bool> m(1 << 20, false);
//     vector<bool> inserted(1 << 20, false);
//     int mask = (1 << 20) - 1; // 类似于掩码，用来保留低20位

//     int temp = 0;
//     // 构造初始的10字符对应的20位二进制
//     for (int i = 0; i < 10; i++)
//         temp = (temp << 2 | toInt(s[i]));
//     m[temp] = true;

//     for (int i = 10; i < len; i++)
//     {
//         // 基于前一个，构造下一个10字符对应的20位二进制
//         // 先左移2位，然后加上新字符对应的二进制，最后与掩码相与得到新的20位
//         temp = (temp << 2 | toInt(s[i])) & mask;

//         if (m[temp] == true)
//         {
//             if (inserted[temp] == false)
//             {
//                 res.emplace_back(s.substr(i - 9, 10));
//                 inserted[temp] = true;
//             }
//         }
//         else
//         {
//             m[temp] = true;
//         }
//     }
//     return res;
// }

// /*
// 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
// 示例:
// 输入: [1,2,3,null,5,null,4]
// 输出: [1, 3, 4]
// 解释:
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// 思路：层次遍历，将每层最右边节点值存入结果即可
// */
// vector<int> rightSideView(TreeNode *root)
// {
//     vector<int> res;
//     if (root == nullptr)
//         return res;

//     queue<TreeNode *> qu;
//     qu.push(root);
//     while (!qu.empty())
//     {
//         res.push_back(qu.back()->val);
//         int size = qu.size();
//         while (size > 0)
//         {
//             TreeNode *node = qu.front();
//             qu.pop();
//             if (node->left != nullptr)
//                 qu.push(node->left);
//             if (node->right != nullptr)
//                 qu.push(node->right);
//             --size;
//         }
//     }
//     return res;
// }

// /*
// 现在你总共有 n 门课需要选，记为 0 到 n-1。
// 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
// 给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

// 示例 1:
// 输入: 2, [[1,0]]
// 输出: true
// 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。

// 示例 2:
// 输入: 2, [[1,0],[0,1]]
// 输出: false
// 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。

// 说明:
// 输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
// 你可以假定输入的先决条件中没有重复的边。

// 提示:
// 这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
// 通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
// 拓扑排序也可以通过 BFS 完成。
// 思路：
// 1）拓扑排序
// 2）步骤：
//     a.选一个入度为零的点，输出
//     b.去除该点的所有出边
//     c.重复直至所有点输出
// */
// bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
// {
//     if (prerequisites.size() == 0)
//         return true;

//     vector<int> in_degrees(numCourses, 0); // 所有课程的入度表
//     vector<vector<int>> adj(numCourses);   // 该课程作为前驱时，连接的所有后继课程表

//     for (const auto &prereq : prerequisites)
//     {
//         ++in_degrees[prereq[0]];             // 入度加一
//         adj[prereq[1]].push_back(prereq[0]); // 将 该课程 加入 该课程的先决课程 的后继课程表中
//     }

//     queue<int> q;
//     for (int i = 0; i < numCourses; ++i) // 找出所有入度为零的课程
//         if (in_degrees[i] == 0)
//             q.push(i);

//     int counter = 0;
//     while (!q.empty())
//     {
//         int curtop = q.front();
//         q.pop();
//         ++counter;
//         // 将入度为零的课程的出边去掉，也就是该课程的所有后继课程的入度减一
//         for (int successor : adj[curtop])
//         {
//             --in_degrees[successor];
//             if (in_degrees[successor] == 0)
//                 q.push(successor);
//         }
//     }

//     return counter == numCourses;
// }

// /*
// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

// 示例: 
// 输入: s = 7, nums = [2,3,1,2,4,3]
// 输出: 2
// 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

// 思路：滑动窗口
// */
// int minSubArrayLen(int s, const vector<int> &nums)
// {
//     int n = nums.size(), start = 0, sum = 0, min_len = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         sum += nums[i];
//         while (sum >= s)
//         {
//             min_len = min(min_len, i - start + 1);
//             sum -= nums[start++];
//         }
//     }
//     return min_len == INT_MAX ? 0 : min_len;
// }

// /*
// 现在你总共有 n 门课需要选，记为 0 到 n-1。
// 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
// 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
// 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

// 示例 1:
// 输入: 2, [[1,0]]
// 输出: [0,1]
// 解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。

// 示例 2:
// 输入: 4, [[1,0],[2,0],[3,1],[3,2]]
// 输出: [0,1,2,3] or [0,2,1,3]
// 解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
//      因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
// */
// vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
// {
//     vector<int> res;
//     if (numCourses <= 0)
//         return res;

//     vector<int> in_degrees(numCourses, 0);
//     vector<vector<int>> adj(numCourses);

//     for (const auto &prereq : prerequisites)
//     {
//         ++in_degrees[prereq[0]];
//         adj[prereq[1]].push_back(prereq[0]);
//     }

//     queue<int> q;
//     for (int i = 0; i < numCourses; ++i)
//         if (in_degrees[i] == 0)
//             q.push(i);

//     while (!q.empty())
//     {
//         int curtop = q.front();
//         q.pop();
//         res.push_back(curtop);
//         for (int successor : adj[curtop])
//         {
//             --in_degrees[successor];
//             if (in_degrees[successor] == 0)
//                 q.push(successor);
//         }
//     }

//     return res.size() == numCourses ? res : vector<int>();
// }

// /*
// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
// 这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
// 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

// 示例 1:
// 输入: [2,3,2]
// 输出: 3
// 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

// 示例 2:
// 输入: [1,2,3,1]
// 输出: 4
// 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//      偷窃到的最高金额 = 1 + 3 = 4 。
// 思路：
// 1）动态规划
//     a.设sum[i]表示从第0家偷盗到第i家（包括i）的总金额
//     b.递推关系式：sum[i] = max(sum[i - 1], sum[i - 2] + nums[i])
// 2）由于第0家和最后一家是挨着的，所以第0家和最后一家只能偷其中一家
// */
// int rob(const vector<int> &nums)
// {
//     int len = nums.size();
//     if (len <= 0)
//         return 0;
//     if (len == 1)
//         return nums[0];
//     if (len == 2)
//         return std::max(nums[0], nums[1]);

//     // 偷第一家
//     vector<int> rob_first(len, 0);
//     rob_first[0] = nums[0];
//     rob_first[1] = std::max(nums[0], nums[1]);
//     for (int i = 2; i < len - 1; i++) // 最后一家不偷
//     {
//         rob_first[i] = std::max(rob_first[i - 1], rob_first[i - 2] + nums[i]);
//     }

//     // 不偷第一家
//     vector<int> rob_no_first(len, 0);
//     rob_no_first[0] = 0;
//     rob_no_first[1] = nums[1];
//     rob_no_first[2] = std::max(nums[1], nums[2]);
//     for (int i = 3; i < len; i++) // 最后一家偷
//     {
//         rob_no_first[i] = std::max(rob_no_first[i - 1], rob_no_first[i - 2] + nums[i]);
//     }

//     return std::max(rob_first[len - 2], rob_no_first[len - 1]);
// }

// /*
// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
// 说明：
// 所有数字都是正整数。
// 解集不能包含重复的组合。 

// 示例 1:
// 输入: k = 3, n = 7
// 输出: [[1,2,4]]

// 示例 2:
// 输入: k = 3, n = 9
// 输出: [[1,2,6], [1,3,5], [2,3,4]]
// */
// void combinationSum3Recursively(vector<vector<int>> &res, vector<int> &temp, int k, int n, int cur)
// {
//     if (k == 0)
//     {
//         if (n == 0)
//             res.emplace_back(temp);
//         return;
//     }

//     for (int i = cur; i < 10; i++)
//     {
//         temp.emplace_back(i);
//         combinationSum3Recursively(res, temp, k - 1, n - i, i + 1);
//         temp.pop_back();
//     }
// }
// vector<vector<int>> combinationSum3(int k, int n)
// {
//     vector<vector<int>> res;
//     if (k <= 0 || n <= 0)
//         return res;

//     vector<int> temp;
//     combinationSum3Recursively(res, temp, k, n, 1);
//     return res;
// }

// /*
// 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

// 示例 1:
// 输入: nums = [1,2,3,1], k = 3, t = 0
// 输出: true

// 示例 2:
// 输入: nums = [1,0,1,1], k = 1, t = 2
// 输出: true

// 示例 3:
// 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
// 输出: false
// */
// bool containsNearbyAlmostDuplicate(const vector<int> &nums, int k, int t)
// {
//     if (k < 1 || t < 0 || nums.size() <= 1)
//         return false;

//     for (int ik = 1; ik <= k; ++ik)
//     {
//         for (int i = 0, j = i + ik; j < nums.size(); ++i, ++j)
//         {
//             if (std::abs(static_cast<long long>(nums[i]) - static_cast<long long>(nums[j])) <= t)
//                 return true;
//         }
//     }
//     return false;
// }

// /*
// 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

// 示例:
// 输入:
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// 输出: 4

// 思路：
// 1）动态规划
// 2）过程：
//     a.令f(i,j)表示以点(i,j)为右下角时最大正方形的边长
//     b.递推关系式：当(i,j)为1时，f(i,j) = min(f(i-1, j-1), f(i-1, j), f(i, j-1)) + 1
// */
// int maximalSquare(vector<vector<char>> &matrix)
// {
//     int rows = matrix.size();
//     if (rows == 0)
//         return 0;
//     int cols = matrix[0].size();
//     if (cols == 0)
//         return 0;

//     int res = 0;
//     vector<vector<int>> dp(rows, vector<int>(cols, 0));
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (i == 0 || j == 0)
//                 dp[i][j] = matrix[i][j] - '0';
//             else if (matrix[i][j] == '1')
//             {
//                 dp[i][j] = 1 + std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1]));
//             }
//             res = std::max(res, dp[i][j]);
//         }
//     }
//     return res * res;
// }

// /*
// 给出一个完全二叉树，求出该树的节点个数。
// 说明：
// 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
// 若最底层为第 h 层，则该层包含 1~ 2^h 个节点。

// 示例:
// 输入:
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6
// 输出: 6
// 思路：
// 1）根据性质，如果所有节点都有两个子节点（除叶子节点），并且叶子节点都在同一层，那么就是满二叉树，节点个数为2^h - 1
// 2）先判断左右子树深度是否一样，如果一样，说明是满的
// */
// int countNodes(TreeNode *root)
// {
//     if (root == nullptr)
//         return 0;

//     int l = 0, r = 0;
//     TreeNode *left = root, *right = root;
//     while (left != nullptr)
//     {
//         ++l;
//         left = left->left;
//     }
//     while (right != nullptr)
//     {
//         ++r;
//         right = right->right;
//     }
//     if (l == r) // 左右深度一致，利用公式求解
//         return (0x01 << l) - 1;
//     return countNodes(root->left) + countNodes(root->right) + 1;
// }

// /*
// 实现一个基本的计算器来计算一个简单的字符串表达式的值。
// 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

// 示例 1:
// 输入: "3+2*2"
// 输出: 7

// 示例 2:
// 输入: " 3/2 "
// 输出: 1

// 示例 3:
// 输入: " 3+5 / 2 "
// 输出: 5

// 说明：
// 你可以假设所给定的表达式都是有效的。
// 请不要使用内置的库函数 eval。
// */
// int calculate(const string &s)
// {
//     deque<long long> nums;
//     deque<char> ops;

//     int idx = 0;
//     while (idx < s.size())
//     {
//         while (idx < s.size() && s[idx] == ' ')
//             ++idx;
//         if (idx >= s.size())
//             break;

//         if (s[idx] == '+' || s[idx] == '-' || s[idx] == '*' || s[idx] == '/')
//         {
//             ops.push_back(s[idx]);
//             ++idx;
//             continue;
//         }

//         long long num = 0;
//         while (idx < s.size() && s[idx] <= '9' && s[idx] >= '0')
//         {
//             num = num * 10 + (s[idx] - '0');
//             ++idx;
//         }
//         nums.push_back(num);

//         if (!ops.empty() && (ops.back() == '/' || ops.back() == '*'))
//         {
//             long long t2 = nums.back();
//             nums.pop_back();
//             long long t1 = nums.back();
//             nums.pop_back();
//             if (ops.back() == '/')
//                 nums.push_back(t1 / t2);
//             else if (ops.back() == '*')
//                 nums.push_back(t1 * t2);
//             ops.pop_back();
//         }
//     }

//     while (!ops.empty())
//     {
//         long long t = nums.front();
//         nums.pop_front();
//         if (ops.front() == '+')
//             t += nums.front();
//         else
//             t -= nums.front();
//         nums.pop_front();
//         nums.push_front(t);
//         ops.pop_front();
//     }

//     return static_cast<int>(nums.front());
// }

// /*
// 给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

// 示例 1:
// 输入: [0,1,2,4,5,7]
// 输出: ["0->2","4->5","7"]
// 解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。

// 示例 2:
// 输入: [0,2,3,4,6,8,9]
// 输出: ["0","2->4","6","8->9"]
// 解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
// */
// vector<string> summaryRanges(const vector<int> &nums)
// {
//     int length = nums.size();
//     if (length <= 0)
//         return vector<string>();
//     if (length == 1)
//         return {std::to_string(nums[0])};

//     vector<string> res;
//     long long start = nums[0];
//     long long pre = start;
//     for (int i = 1; i < length; ++i)
//     {
//         if (nums[i] - pre == 1)
//         {
//             pre = nums[i];
//         }
//         else
//         {
//             if (pre == start)
//                 res.push_back(std::to_string(start));
//             else
//                 res.push_back(std::to_string(start) + "->" + std::to_string(pre));

//             start = nums[i];
//             pre = start;
//         }
//     }
//     if (pre == start)
//         res.push_back(std::to_string(start));
//     else
//         res.push_back(std::to_string(start) + "->" + std::to_string(pre));
//     return res;
// }

// /*
// 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

// 示例 1:
// 输入: [3,2,3]
// 输出: [3]

// 示例 2:
// 输入: [1,1,1,3,3,2,2,2]
// 输出: [1,2]

// 思路：
// 1）摩尔投票法。该算法用于1/2情况，它说：“在任何数组中，出现次数大于该数组长度一半的值只能有一个。”
// 2）那么，改进一下用于1/3。可以这么说：“在任何数组中，出现次数大于该数组长度1/3的值最多只有两个。”
// */
// vector<int> majorityElement(vector<int> &nums)
// {
//     if (nums.size() < 2)
//         return nums;

//     int maj_1 = INT_MIN, maj_2 = INT_MIN;
//     int maj_1_cnt = 0, maj_2_cnt = 0;
//     for (int num : nums)
//     {
//         if ((maj_1_cnt == 0 || maj_1 == num) && num != maj_2)
//         {
//             ++maj_1_cnt;
//             maj_1 = num;
//         }
//         else if (maj_2_cnt == 0 || maj_2 == num)
//         {
//             ++maj_2_cnt;
//             maj_2 = num;
//         }
//         else
//         {
//             --maj_1_cnt;
//             --maj_2_cnt;
//         }
//     }

//     vector<int> res;
//     int cnt = 0;
//     for (int num : nums)
//     {
//         if (num == maj_1)
//             ++cnt;
//     }
//     if (cnt > nums.size() / 3)
//         res.push_back(maj_1);

//     cnt = 0;
//     for (int num : nums)
//     {
//         if (num == maj_2)
//             ++cnt;
//     }
//     if (cnt > nums.size() / 3 && maj_2 != maj_1)
//         res.push_back(maj_2);
//     return res;
// }

// /*
// 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
// 说明：
// 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

// 示例 1:
// 输入: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// 输出: 1

// 示例 2:
// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// 输出: 3

// 进阶：
// 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
// */
// void kthSmallestRecursively(TreeNode *p, int &k, int &res)
// {
//     if (k == 0 || p == nullptr)
//         return;

//     kthSmallestRecursively(p->left, k, res);
//     --k;
//     if (k == 0)
//     {
//         res = p->val;
//         return;
//     }
//     kthSmallestRecursively(p->right, k, res);
// }
// int kthSmallest(TreeNode *root, int k)
// {
//     int res = -1;
//     kthSmallestRecursively(root, k, res);
//     return res;
// }

// /*
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科中最近公共祖先的定义为：
// “对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

// 说明:
// 所有节点的值都是唯一的。
// p、q 为不同节点且均存在于给定的二叉树中。
// */
// void lowestCommonAncestorGetPath(TreeNode *p, TreeNode *target, bool &found, vector<TreeNode *> &path)
// {
//     if (p == nullptr || found)
//         return;
//     if (p == target)
//     {
//         path.push_back(p);
//         found = true;
//         return;
//     }

//     path.push_back(p);
//     lowestCommonAncestorGetPath(p->left, target, found, path);
//     if (found)
//         return;
//     lowestCommonAncestorGetPath(p->right, target, found, path);
//     if (found)
//         return;
//     path.pop_back();
// }
// TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
// {
//     if (root == nullptr || p == nullptr || q == nullptr)
//         return nullptr;
//     if (p == q)
//         return p;

//     vector<TreeNode *> path_p, path_q;
//     bool found_p = false, found_q = false;
//     lowestCommonAncestorGetPath(root, p, found_p, path_p);
//     lowestCommonAncestorGetPath(root, q, found_q, path_q);

//     int len = std::min(path_p.size(), path_q.size());
//     TreeNode *res = nullptr;
//     for (int i = 0; i < len; i++)
//     {
//         if (path_p[i] != path_q[i])
//             return res;
//         else
//             res = path_p[i];
//     }
//     return res;
// }
// TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
// {
//     /*
//     注意p,q必然存在树内, 且所有节点的值唯一!!!
//     递归思想, 对以root为根的(子)树进行查找p和q, 如果root == null || p || q 直接返回root
//     表示对于当前树的查找已经完毕, 否则对左右子树进行查找, 根据左右子树的返回值判断:
//     1. 左右子树的返回值都不为null, 由于值唯一左右子树的返回值就是p和q, 此时root为LCA
//     2. 如果左右子树返回值只有一个不为null, 说明只有p和q存在与左或右子树中, 最先找到的那个节点为LCA
//     3. 左右子树返回值均为null, p和q均不在树中, 返回null
//     */
//     if (root == nullptr || root == p || root == q)
//         return root;

//     TreeNode *left = lowestCommonAncestor2(root->left, p, q);
//     TreeNode *right = lowestCommonAncestor2(root->right, p, q);
//     if (left == nullptr && right == nullptr)
//         return nullptr;
//     else if (left != nullptr && right != nullptr)
//         return root;
//     else
//         return left == nullptr ? right : left;
// }

// /*
// 给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

// 示例:
// 输入: [1,2,3,4]
// 输出: [24,12,8,6]
// 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

// 进阶：
// 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

// 思路：
// 1）先从左到右计算除当前位置外左边的乘积
// 2）然后从右往左计算除当前位置之外右边的乘积，同时和上一步计算的左边乘积相乘即可
// */
// vector<int> productExceptSelf(const vector<int> &nums)
// {
//     vector<int> res(nums.size(), 1);
//     int left = 1, right = 1;
//     // 先从左到右计算除当前位置外左边的乘积
//     for (int i = 0; i < nums.size(); i++)
//     {
//         res[i] = left;
//         left *= nums[i];
//     }
//     // 从右往左计算除当前位置之外右边的乘积，同时和上一步计算的左边乘积相乘
//     for (int i = nums.size() - 1; i >= 0; i--)
//     {
//         res[i] *= right;
//         right *= nums[i];
//     }
//     return res;
// }

// /*
// 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

// 示例 1:
// 输入: "2-1-1"
// 输出: [0, 2]
// 解释:
// ((2-1)-1) = 0
// (2-(1-1)) = 2

// 示例 2:
// 输入: "2*3-4*5"
// 输出: [-34, -14, -10, -10, 10]
// 解释:
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10

// 思路：分治法
// */
// vector<int> diffWaysToCompute(const string &input)
// {
//     vector<int> res;
//     // 遍历所有可能的分法（按运算符分割）
//     for (int i = 0; i < input.size(); ++i)
//     {
//         char c = input[i];
//         // 在运算符处分成左右两个子问题求解
//         if (c == '+' || c == '-' || c == '*')
//         {
//             // 左子问题的所有可能加括号后的结果
//             vector<int> res1 = diffWaysToCompute(input.substr(0, i));
//             // 右子问题的所有可能加括号后的结果
//             vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
//             // 组合左右子问题的结果得到未分割前的结果
//             for (int r1 : res1)
//             {
//                 for (int r2 : res2)
//                 {
//                     if (c == '+')
//                         res.push_back(r1 + r2);
//                     else if (c == '-')
//                         res.push_back(r1 - r2);
//                     else if (c == '*')
//                         res.push_back(r1 * r2);
//                 }
//             }
//         }
//     }
//     // 无运算符，意味着这是一个数
//     if (res.empty())
//         res.push_back(std::stoi(input));
//     return res;
// }

// /*
// 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

// 示例 1:
// 输入: n = 12
// 输出: 3
// 解释: 12 = 4 + 4 + 4.

// 示例 2:
// 输入: n = 13
// 输出: 2
// 解释: 13 = 4 + 9.

// 思路：动态规划
// */
// int numSquares(int n)
// {
//     vector<int> dp(n + 1, INT_MAX);
//     dp[0] = 0;
//     for (int num = 1; num <= n; ++num) // 从1开始至n打表
//     {
//         for (int root = 1; root * root <= num; ++root) // 尝试num-1, num-4, num-9, ...
//         {
//             // 将num分解成 root*root 和 num-root*root，由于dp[num-root*root]已经计算出来了，那么dp[num]=dp[num-root*root]+1
//             dp[num] = min(dp[num], dp[num - root * root] + 1);
//         }
//     }
//     return dp[n];
// }
// // 思路2：四平方定理，一个正整数可以表示成不超过4个平方数的和
// int numSquares2(int n)
// {
//     if (n <= 0)
//         return 0;

//     auto check1 = [](int n) -> bool // 能否表示成一个平方数
//     {
//         int tem = sqrt(n);
//         return tem * tem == n;
//     };
//     auto check2 = [&check1](int n) -> bool // 能否表示成两个平方数的和
//     {
//         for (int i = 1; i * i < n; i++)
//             if (check1(n - i * i))
//                 return true;
//         return false;
//     };
//     auto check3 = [&check2](int n) -> bool // 能否表示成三个平方数的和
//     {
//         for (int i = 1; i * i < n; i++)
//             if (check2(n - i * i))
//                 return true;
//         return false;
//     };

//     if (check1(n))
//         return 1;
//     else if (check2(n))
//         return 2;
//     else if (check3(n))
//         return 3;
//     else
//         return 4;
// }

// /*
// 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

// 示例 1:
// 输入: [1,3,4,2,2]
// 输出: 2

// 示例 2:
// 输入: [3,1,3,4,2]
// 输出: 3

// 说明：
// 不能更改原数组（假设数组是只读的）。
// 只能使用额外的 O(1) 的空间。
// 时间复杂度小于 O(n^2) 。
// 数组中只有一个重复的数字，但它可能不止重复出现一次。

// 思路：类似寻找有环链表的环入口
// 例如：
//     下标   0,1,2,3,4
//     数组  [1,3,4,2,2]
//     从下标0开始遍历下标和数组得：
//               __
//              ↓  |
//     0->1->3->2->4
// */
// int findDuplicate(const vector<int> &nums)
// {
//     if (nums.size() < 2)
//         return -1;
//     if (nums.size() == 2)
//         return nums[1];

//     // 快慢指针使两个指针进入环中
//     int slow = 0, fast = 0;
//     do
//     {
//         slow = nums[slow];
//         fast = nums[nums[fast]];
//     } while (slow != fast);

//     // 然后从头开始，直到相遇
//     int res = 0;
//     while (res != slow)
//     {
//         res = nums[res];
//         slow = nums[slow];
//     }
//     return res;
// }

// /*
// 根据百度百科，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。
// 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
// 每个细胞具有一个初始状态 live（1）即为活细胞， 或 dead（0）即为死细胞。
// 每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
// 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
// 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
// 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
// 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
// 根据当前状态，写一个函数来计算面板上细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

// 示例:
// 输入:
// [
//   [0,1,0],
//   [0,0,1],
//   [1,1,1],
//   [0,0,0]
// ]
// 输出:
// [
//   [0,0,0],
//   [1,0,1],
//   [0,1,1],
//   [0,1,0]
// ]

// 进阶:
// 你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
// 本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？

// 思路：
// 状态0： 死细胞转为死细胞
// 状态1： 活细胞转为活细胞
// 状态2： 活细胞转为死细胞
// 状态3： 死细胞转为活细胞
// 我们先对原数组进行逐个扫描，对于每一个位置，扫描其周围八个位置，如果遇到状态1或2，就计数器累加1，
// 扫完8个邻居，如果少于两个活细胞或者大于三个活细胞，而且当前位置是活细胞的话，标记状态2，
// 如果正好有三个活细胞且当前是死细胞的话，标记状态3。
// 最后我们对所有状态对2取余，那么状态0和2就变成死细胞，状态1和3就是活细胞，达成目的。
// */
// void gameOfLife(vector<vector<int>> &board)
// {
//     int rows = board.size();
//     if (rows == 0)
//         return;
//     int cols = board[0].size();
//     if (cols == 0)
//         return;

//     int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
//     int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
//     for (int row = 0; row < rows; ++row)
//     {
//         for (int col = 0; col < cols; ++col)
//         {
//             int cnt = 0;
//             for (int i = 0; i < 8; ++i)
//             {
//                 int x = row + dx[i], y = col + dy[i];
//                 if (x >= 0 && x < rows && y >= 0 && y < cols && (board[x][y] == 1 || board[x][y] == 2))
//                     ++cnt;
//             }
//             if (board[row][col] == 1 && (cnt < 2 || cnt > 3))
//                 board[row][col] = 2;
//             else if (board[row][col] == 0 && cnt == 3)
//                 board[row][col] = 3;
//         }
//     }
//     for (int row = 0; row < rows; ++row)
//     {
//         for (int col = 0; col < cols; ++col)
//         {
//             board[row][col] %= 2;
//         }
//     }
// }

// /*
// 你正在和你的朋友玩 猜数字（Bulls and Cows）游戏：你写下一个数字让你的朋友猜。
// 每次他猜测后，你给他一个提示，告诉他有多少位数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）。
// 你的朋友将会根据提示继续猜，直到猜出秘密数字。
// 请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 A 表示公牛，用 B 表示奶牛。
// 请注意秘密数字和朋友的猜测数都可能含有重复数字。

// 示例 1:
// 输入: secret = "1807", guess = "7810"
// 输出: "1A3B"
// 解释: 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。

// 示例 2:
// 输入: secret = "1123", guess = "0111"
// 输出: "1A1B"
// 解释: 朋友猜测数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
// 说明: 你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。

// 思路：由于都是数字，可以用数组进行哈希
// */
// string getHint(const string &secret, const string &guess)
// {
//     int secret_map[10], guess_map[10];
//     memset(secret_map, 0, sizeof(secret_map));
//     memset(guess_map, 0, sizeof(guess_map));

//     int bulls = 0;
//     for (int i = 0; i < guess.size(); i++)
//     {
//         char secret_char = secret[i], guess_char = guess[i];
//         if (secret_char == guess_char)
//         {
//             ++bulls;
//         }
//         else
//         {
//             ++secret_map[secret_char - '0'];
//             ++guess_map[guess_char - '0'];
//         }
//     }

//     int cows = 0;
//     for (int i = 0; i < 10; i++)
//     {
//         cows += std::min(secret_map[i], guess_map[i]);
//     }

//     return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
// }

// /*
// 给定一个无序的整数数组，找到其中最长上升子序列的长度。

// 示例:
// 输入: [10,9,2,5,3,7,101,18]
// 输出: 4
// 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

// 说明:
// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
// 你算法的时间复杂度应该为 O(n^2) 。
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

// 思路：O(n^2)
// 1）动态规划
// 2）dp[i]表示[0, i]的最长上升子序列的长度
// 3）那么dp[i] = max(dp[i], dp[j] + 1)，j∈[0, i-1] && nums[i] > nums[j]
// 4）也就是说，前面的第j个数可以上升到第i个数（现在的数），那么dp[i] = dp[j] + 1
// */
// int lengthOfLIS(const vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 2)
//         return length;

//     vector<int> dp(length, 1);
//     int res = 1;
//     for (int i = 1; i < length; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (nums[j] < nums[i])
//                 dp[i] = std::max(dp[i], dp[j] + 1);
//         }
//         if (dp[i] > res)
//             res = dp[i];
//     }
//     return res;
// }
// /*
// 思路2：O(nlogn)
// 1）辅助数组近似代表最长上升子序列
// 2）从左到右扫描数组，对于当前数字：
//     a.当前数字大于辅助数组最大元素（即最后一个元素），那么可以将该数加入辅助数组中，辅助数组长度增加
//     b.否则在辅助数组中二分查找，找到可以插入该数的位置并进行覆盖插入，辅助数组长度不变
// */
// int lengthOfLIS2(const vector<int> &nums)
// {
//     vector<int> arr;
//     for (int num : nums)
//     {
//         if (arr.empty() || num > arr.back()) // 加入辅助数组
//             arr.push_back(num);
//         else // 二分查找，进行覆盖插入
//         {
//             //int low = 0;
//             //int high = arr.size();
//             //while (low < high)
//             //{
//             //    int mid = (low + high) / 2;
//             //    if (arr[mid] < num)
//             //        low = mid + 1;
//             //    else
//             //        high = mid;
//             //}
//             //arr[low] = num;

//             // 找到第一个大于或等于该元素的位置进行覆盖插入
//             *(std::lower_bound(arr.begin(), arr.end(), num)) = num;
//         }
//     }

//     return arr.size();
// }

// /*
// 累加数是一个字符串，组成它的数字可以形成累加序列。
// 一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
// 给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
// 说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

// 示例 1:
// 输入: "112358"
// 输出: true
// 解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

// 示例 2:
// 输入: "199100199"
// 输出: true
// 解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
// 进阶:
// 你如何处理一个溢出的过大的整数输入?

// 思路：
// 1）DFS+剪枝
// 2）第一个数的长度为len1，第二个数的长度为len2，那么第三个数为前两个数相加，长度为max(len1,len2)或max(len1,len2)+1
// 3）如果某数以0打头，并且长度大于1，则剪枝
// 4）注意最开始的第一个数和第二个数，最长为整个字符串长度一半
// */
// bool isAdditiveNumberRecursively(unsigned long long first, int first_start, unsigned long long second, int second_start, const string &num, int third_start)
// {
//     if (third_start >= num.size())
//         return true;

//     int len = std::max(second_start - first_start, third_start - second_start);
//     for (int len3 = len; len3 <= len + 1; len3++)
//     {
//         if (num[third_start] == '0' && len3 > 1) // 剪枝
//             return false;
//         unsigned long long third = std::stoull(num.substr(third_start, len3));
//         if (first + second == third && isAdditiveNumberRecursively(second, second_start, third, third_start, num, third_start + len3))
//             return true;
//     }
//     return false;
// }
// bool isAdditiveNumber(const string &num)
// {
//     if (num.size() < 3)
//         return false;

//     for (int len1 = 1; len1 <= num.size() / 2; len1++) // 第一个数长度最长为一半
//     {
//         unsigned long long first = std::stoull(num.substr(0, len1));
//         for (int len2 = 1; len1 + len2 < num.size(); len2++) // 第二个数长度
//         {
//             if (num[len1] == '0' && len2 > 1) // 剪枝
//                 break;
//             unsigned long long second = std::stoull(num.substr(len1, len2));
//             if (isAdditiveNumberRecursively(first, 0, second, len1, num, len1 + len2))
//                 return true;
//         }
//     }
//     return false;
// }

// /*
// 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

// 示例:
// 输入: [1,2,3,0,2]
// 输出: 3
// 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

// 思路：
// 1）动态规划
// 2）状态：买入、卖出、冷冻期（卖出后）、休息（啥都不干）
// 3）用dp[n][k]表示第n天持有（k=1）或不持有（k=0）股票时的利润
// 4）状态转移方程：
//     a.dp[n][1]=max(dp[n-1][1], dp[n-2][0]-prices[n])
//       第n天持有    前一天就持有  大前天不持有（卖出），隔一天（冷冻期）后买入
//     b.dp[n][0]=max(dp[n-1][0], dp[n-1][1]+prices[n])
//      第n天不持有   前一天就不持有  前一天持有，今天卖出
// 5）dp[n][1]、dp[n][0]、dp[n-2][0]可简化成变量
// 6）参考链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-lab
// */
// int maxProfit(const vector<int> &prices)
// {
//     int length = prices.size();
//     if (length <= 1)
//         return 0;

//     int dp_n_0 = 0, dp_n_1 = INT_MIN;
//     int dp_pre_pre_0 = 0;
//     for (int i = 0; i < length; i++)
//     {
//         int temp = dp_n_0;
//         dp_n_0 = std::max(dp_n_0, dp_n_1 + prices[i]);
//         dp_n_1 = std::max(dp_n_1, dp_pre_pre_0 - prices[i]);
//         dp_pre_pre_0 = temp;
//     }
//     return dp_n_0;
// }

// /*
// 对于一个具有树特征的无向图，我们可选择任何一个节点作为根。
// 图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。
// 给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。
// 格式
// 该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。
// 你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。

// 示例 1:
// 输入: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
//         0
//         |
//         1
//        / \
//       2   3
// 输出: [1]

// 示例 2:
// 输入: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5

// 输出: [3, 4]

// 说明:
// 根据树的定义，树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
// 树的高度是指根节点和叶子节点之间最长向下路径上边的数量。

// 思路：
// 1）拓扑排序的思想
// 2）越靠近树的叶子的节点越不可能为根节点，意味着如果逐步把那些叶子去除的话，最后的节点便是根节点
// */
// vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
// {
//     vector<int> res;
//     if (n < 3) // 边界情况
//     {
//         for (int i = 0; i < n; i++)
//         {
//             res.push_back(i);
//         }
//         return res;
//     }

//     vector<int> degrees(n, 0);                  // 度数表，只要有顶点和它相连，度数加一
//     vector<vector<int>> adjs(n, vector<int>()); // 邻接矩阵，只要有顶点和它相连，将相连顶点加入

//     for (const auto &edge : edges) // 初始化度数表和邻接矩阵
//     {
//         ++degrees[edge[0]];
//         ++degrees[edge[1]];
//         adjs[edge[0]].push_back(edge[1]);
//         adjs[edge[1]].push_back(edge[0]);
//     }

//     queue<int> del_vertices; // 保存需要移除的度数为1的顶点（即叶子）
//     for (int i = 0; i < n; i++)
//     {
//         if (degrees[i] == 1)
//             del_vertices.push(i);
//     }

//     while (n > 2) // 根最多为两个
//     {
//         int cnt = del_vertices.size();
//         n -= cnt;                     // 得到剩余顶点
//         for (int i = 0; i < cnt; i++) // 移除目前待移除队列中的所有顶点
//         {
//             int vertex = del_vertices.front();
//             del_vertices.pop();
//             --degrees[vertex]; // 需要移除的顶点度数减一
//             for (int v : adjs[vertex])
//             {
//                 --degrees[v];        // 与之相连的顶点的度数也减一（重复减去已移除顶点的度数不影响）
//                 if (degrees[v] == 0) // 度数为0，说明只有一个根，并且这个根就是它
//                 {
//                     res.push_back(v);
//                     return res;
//                 }
//                 if (degrees[v] == 1) // 度数为1，加入待移除队列
//                     del_vertices.push(v);
//             }
//         }
//     }

//     while (del_vertices.empty() == false) // 两个根
//     {
//         res.push_back(del_vertices.front());
//         del_vertices.pop();
//     }
//     return res;
// }

// /*
// 编写一段程序来查找第 n 个超级丑数。
// 超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

// 示例:
// 输入: n = 12, primes = [2,7,13,19]
// 输出: 32
// 解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。

// 说明:
// 1 是任何给定 primes 的超级丑数。
//  给定 primes 中的数字以升序排列。
// 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
// 第 n 个超级丑数确保在 32 位有符整数范围内。

// 思路：和丑数的思路一致，只不过2，3，5换成了指定的序列
// */
// int nthSuperUglyNumber(int n, const vector<int> &primes)
// {
//     if (n == 1)
//         return 1;

//     vector<int> nums(n, 1);
//     // 原来的3个指针换成了指定序列长度的指针
//     vector<int> indices(primes.size(), 0);

//     int idx = 1;
//     while (idx < n)
//     {
//         // 取最小的那个
//         int cur = primes[0] * nums[indices[0]];
//         for (int i = 1; i < indices.size(); i++)
//         {
//             int t = primes[i] * nums[indices[i]];
//             if (t < cur)
//                 cur = t;
//         }
//         nums[idx] = cur;
//         // 更新每个数对应的指针
//         for (int i = 0; i < indices.size(); i++)
//         {
//             while (primes[i] * nums[indices[i]] <= cur)
//                 ++indices[i];
//         }
//         ++idx;
//     }
//     return nums[n - 1];
// }
// // 思路2：保存中间结果，减少循环
// int nthSuperUglyNumber2(int n, const vector<int> &primes)
// {
//     if (n == 1)
//         return 1;

//     int m = primes.size();
//     vector<int> nums(n, INT_MAX); //输出的丑数
//     vector<int> indices(m, 0);    //每一个prime对应的要找到的丑数的位置
//     vector<int> vals(m, 1);       //每一个prime的下一个数的最优位置

//     nums[0] = 1; //第一个丑数是1
//     for (int idx = 1; idx < n; idx++)
//     {
//         for (int i = 0; i < m; i++)
//         {
//             if (vals[i] == nums[idx - 1])
//                 vals[i] = nums[indices[i]++] * primes[i];
//             nums[idx] = std::min(nums[idx], vals[i]);
//         }
//     }
//     return nums[n - 1];
// }

// /*
// 给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。
// 你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

// 示例 1:
// 输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
// 输出: 16
// 解释: 这两个单词为 "abcw", "xtfn"。

// 示例 2:
// 输入: ["a","ab","abc","d","cd","bcd","abcd"]
// 输出: 4
// 解释: 这两个单词为 "ab", "cd"。

// 示例 3:
// 输入: ["a","aa","aaa","aaaa"]
// 输出: 0
// 解释: 不存在这样的两个单词。
// */
// int maxProduct(vector<string> &words)
// {
//     int length = words.size();
//     if (length < 2)
//         return 0;

//     // 都是小写字母，那么可以用一个26位的数字代表
//     auto str2bit = [](const string &word) -> int {
//         int res = 0;
//         for (char c : word)
//         {
//             res |= (0x01 << (c - 'a'));
//         }
//         return res;
//     };

//     vector<int> bit_words(length, 0);
//     for (int i = 0; i < length; i++)
//     {
//         bit_words[i] = str2bit(words[i]);
//     }

//     int res = 0;
//     for (int i = 0; i < length; i++)
//     {
//         for (int j = i + 1; j < length; j++)
//         {
//             int t = words[i].size() * words[j].size();
//             if (t > res && !(bit_words[i] & bit_words[j]))
//                 res = t;
//         }
//     }
//     return res;
// }

// /*
// 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

// 示例 1:
// 输入: coins = [1, 2, 5], amount = 11
// 输出: 3
// 解释: 11 = 5 + 5 + 1

// 示例 2:
// 输入: coins = [2], amount = 3
// 输出: -1

// 说明:
// 你可以认为每种硬币的数量是无限的。

// 思路：
// 1）动态规划
// 2）类似背包问题
// 3）令dp[i]表示总金额为i时最少硬币的个数，dp[0]=0
// 4）从dp[1]开始，计算到dp[amount]
// 5）转移方程：
//     for coin in coins:
//         dp[i] = min(dp[i], dp[i - coin] + 1)
// 6）也就是，i可以分成coin和i-coin
// */
// int coinChange(vector<int> &coins, int amount)
// {
//     if (amount == 0)
//         return 0;
//     if (coins.empty() || amount < 0)
//         return -1;

//     vector<int> dp(amount + 1, INT_MAX);
//     dp[0] = 0;
//     for (int i = 1; i <= amount; i++)
//     {
//         for (int coin : coins)
//         {
//             if (coin > i) // 当前硬币面值超过了当前计算的总金额，那么跳过
//                 continue;
//             if (dp[i - coin] != INT_MAX) // dp[i - coin]已经计算了，否则无法将当前金额i分成coin和i-coin
//                 dp[i] = std::min(dp[i], dp[i - coin] + 1);
//         }
//     }
//     if (dp[amount] == INT_MAX)
//         return -1;
//     return dp[amount];
// }
// /*
// 思路2：
// 1）递归求解
// 2）先按面值从大到小排序，我们期望面值越大的硬币个数能够尽量多一些
// 3）递归时，从面值最大的递归到最小的，递归过程中：
//     a.如果余额刚好能够整除当前面值，更新结果，回溯
//     b.如果不能整除，那么令i=余额/面值，然后i递减至0，进行递归。目的是在尽可能满足2）的目标下，又能够覆盖所有可能情况（当前面值从i~0，都覆盖了）
// */
// void coinChangeRecursively(vector<int> &coins, int amount, int idx, int cnt, int &res)
// {
//     if (idx >= coins.size() || cnt > res)
//         return;
//     if (amount % coins[idx] == 0) // 余额刚好能够整除当前面值
//     {
//         res = std::min(res, cnt + amount / coins[idx]);
//         return;
//     }

//     for (int i = amount / coins[idx]; i >= 0; --i)
//     {
//         /* 剪枝
//         i是递减的，i越小，cnt+i就越小，乍看上去像是“提前”剪枝了
//         其实不然，当前面值大于接下来的面值。如果i继续减小，那么需要更多的小面值
//         */
//         if (cnt + i > res)
//             break;
//         coinChangeRecursively(coins, amount - i * coins[idx], idx + 1, cnt + i, res);
//     }
// }
// int coinChange2(vector<int> &coins, int amount)
// {
//     if (amount == 0)
//         return 0;
//     if (coins.empty() || amount < 0)
//         return -1;

//     std::sort(coins.begin(), coins.end(), greater<int>());

//     int res = INT_MAX;
//     coinChangeRecursively(coins, amount, 0, 0, res);
//     if (res == INT_MAX)
//         return -1;
//     return res;
// }

// /*
// 给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

// 示例 1:
// 输入: nums = [1, 5, 1, 1, 6, 4]
// 输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]

// 示例 2:
// 输入: nums = [1, 3, 2, 2, 3, 1]
// 输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]

// 说明:
// 你可以假设所有输入都会得到有效的结果。

// 进阶:
// 你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

// 思路：排序，分成两部分，然后把两部分转置（目的是为了防止两个相同的数放在一起），然后交替填充
// */
// void wiggleSort(vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 2)
//         return;

//     std::sort(nums.begin(), nums.end());

//     vector<int> res;
//     res.reserve(length);
//     int middle = (length - 1) / 2;
//     int left = middle, right = length - 1;
//     while (left >= 0)
//     {
//         res.push_back(nums[left--]);
//         if (right > middle)
//             res.push_back(nums[right--]);
//     }
//     nums = std::move(res);
// }

// /*
// 序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
// 例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。
// 给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。
// 每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。
// 你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。

// 示例 1:
// 输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
// 输出: true

// 示例 2:
// 输入: "1,#"
// 输出: false

// 示例 3:
// 输入: "9,#,#,1"
// 输出: false

// 思路：递归建树
// */
// bool isValidSerializationRecursively(const vector<bool> &pre, int cur, int &last)
// {
//     if (cur >= pre.size())
//     {
//         last = pre.size() - 1;
//         return true;
//     }

//     if (cur <= pre.size() - 2 && pre[cur] != true && pre[cur + 1] != true)
//     {
//         int last_ = INT_MIN;
//         if (isValidSerializationRecursively(pre, cur + 1, last_))
//         {
//             if (isValidSerializationRecursively(pre, last_ + 1, last_))
//             {
//                 last = last_;
//                 return true;
//             }
//             return false;
//         }
//         return false;
//     }
//     else if (cur <= pre.size() - 3 && pre[cur] != true && pre[cur + 1] == true && pre[cur + 2] != true)
//     {
//         int last_ = INT_MIN;
//         if (isValidSerializationRecursively(pre, cur + 2, last_))
//         {
//             last = last_;
//             return true;
//         }
//         return false;
//     }
//     else if (cur <= pre.size() - 3 && pre[cur] != true && pre[cur + 1] == true && pre[cur + 2] == true)
//     {
//         last = cur + 2;
//         return true;
//     }
//     else if (pre[cur] == true)
//     {
//         last = cur;
//         return true;
//     }
//     return false;
// }
// bool isValidSerialization(string &preorder)
// {
//     int length = preorder.size();
//     if (length == 0)
//         return false;

//     preorder.push_back(',');
//     vector<bool> pre;
//     int start = 0, idx = 0;
//     while (idx < length)
//     {
//         while (idx < length && preorder[idx] != ',')
//             ++idx;
//         if (idx - start == 1 && preorder[start] == '#')
//             pre.push_back(true);
//         else
//             pre.push_back(false);
//         ++idx;
//         start = idx;
//     }

//     int len = pre.size();
//     if (len == 1)
//     {
//         if (pre[0] == true)
//             return true;
//         return false;
//     }
//     if (len < 3)
//         return false;
//     if (pre[len - 2] != true || pre[len - 1] != true)
//         return false;

//     int last_ = INT_MIN;
//     return isValidSerializationRecursively(pre, 0, last_) && last_ == pre.size() - 1;
// }
// // 思路2：堆栈模拟，遇到“数字,#,#”就归约成#
// bool isValidSerialization2(string &preorder)
// {
//     int length = preorder.size();
//     if (length == 0)
//         return false;

//     preorder.push_back(',');
//     vector<bool> pre;
//     int start = 0, idx = 0;
//     while (idx < length)
//     {
//         while (idx < length && preorder[idx] != ',')
//             ++idx;
//         if (idx - start == 1 && preorder[start] == '#')
//         {
//             while (!pre.empty())
//             {
//                 int len = pre.size();
//                 if (len == 1)
//                 {
//                     if (pre[len - 1] == true)
//                         return false;
//                     break;
//                 }
//                 if (len >= 2)
//                 {
//                     if (pre[len - 1] == true)
//                     {
//                         if (pre[len - 2] == false)
//                         {
//                             pre.pop_back();
//                             pre.pop_back();
//                         }
//                         else
//                             return false;
//                     }
//                     else
//                         break;
//                 }
//             }
//             pre.push_back(true);
//         }
//         else
//             pre.push_back(false);
//         ++idx;
//         start = idx;
//     }

//     return pre.size() == 1 && pre[0] == true;
// }
// // 思路3：根据二叉树的性质
// bool isValidSerialization3(string &preorder)
// {
//     int length = preorder.size();
//     if (length == 0)
//         return false;

//     preorder.push_back(',');
//     int start = 0, idx = 0;
//     int leaf_cnt = 0, nonleaf_cnt = 0; // 叶子节点个数，内部节点个数
//     while (idx < length)
//     {
//         while (idx < length && preorder[idx] != ',')
//             ++idx;

//         if (idx - start == 1 && preorder[start] == '#') // 叶子节点
//             ++leaf_cnt;
//         else // 非叶子节点
//             ++nonleaf_cnt;

//         // 在遍历到最后一个节点之前，叶子节点的个数不超过内部节点个数
//         if (idx != preorder.size() - 1 && leaf_cnt > nonleaf_cnt)
//             return false;

//         ++idx;
//         start = idx;
//     }

//     // 遍历完整个序列以后，叶子节点个数 = 内部节点个数 + 1
//     if (leaf_cnt != nonleaf_cnt + 1)
//         return false;

//     // 最后一个节点应该是叶子节点，否则不可能是前序遍历
//     return preorder[preorder.size() - 2] == '#';
// }

// /*
// 0-1背包问题
// */
// int knapsack(const vector<int> &weights, const vector<int> &values, int max_weight)
// {
//     if (weights.empty() || values.empty() || weights.size() != values.size() || max_weight <= 0)
//         return 0;

//     int length = values.size();
//     vector<vector<int>> dp(length + 1, vector<int>(max_weight + 1, 0));
//     // dp[i][j]表示选择到第i个物品，背包重量为j时的最大价值
//     for (int i = 1; i < length + 1; i++)
//     {
//         for (int j = 1; j < max_weight + 1; j++)
//         {
//             // 当前物品重量大于当前背包重量，即放不下，那么当前最大价值和 上一个物品 时一致
//             if (weights[i - 1] > j)
//                 dp[i][j] = dp[i - 1][j];
//             // 放得下，那么当前最大价值为 不放下当前物品 以及 放下当前物品 两者中的最大值
//             else
//                 dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
//         }
//     }
//     return dp[length][max_weight];
// }

// /*
// 给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。
// 所有这些机票都属于一个从JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 出发。
// 说明:
// 如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。
// 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
// 所有的机场都用三个大写字母表示（机场代码）。
// 假定所有机票至少存在一种合理的行程。

// 示例 1:
// 输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// 输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]

// 示例 2:
// 输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// 输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// 解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。

// 思路：深搜
// */
// void findItineraryRecursively(unordered_map<string, map<string, int>> &m, int n, const string &airport, vector<string> &res)
// {
//     if (res.size() == n)
//         return;

//     res.push_back(airport); // 加入当前站
//     if (res.size() == n)    // 当前总站数达到要求
//         return;

//     auto iter_m = m.find(airport); // 根据当前站查找下一站
//     if (iter_m != m.end())
//     {
//         auto &airports = iter_m->second;
//         for (auto &port : airports) // 遍历所有可能的下一站
//         {
//             if (port.second > 0) // 下一站的机票数不为零才继续递归
//             {
//                 --port.second;
//                 findItineraryRecursively(m, n, port.first, res);
//                 if (res.size() == n) // 当前总站数达到要求，剪枝
//                     return;
//                 ++port.second;
//             }
//         }
//     }
//     res.pop_back(); // 当前站退出，进行回溯
// }
// vector<string> findItinerary(const vector<vector<string>> &tickets)
// {
//     if (tickets.empty())
//         return {};

//     // 可能有重复机票
//     // {起点：{下一站：重复次数}}
//     // 使用map可以完成排序
//     unordered_map<string, map<string, int>> m;
//     for (const auto &ticket : tickets)
//     {
//         ++m[ticket[0]][ticket[1]];
//     }

//     vector<string> res;
//     // n张机票，最后结果为n+1个站，找到第一个满足条件为n+1的结果就返回
//     findItineraryRecursively(m, tickets.size() + 1, "JFK", res);
//     return res;
// }

// /*
// 给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
// 数学表达式如下:
// 如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
// 使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。

// 示例 1:
// 输入: [1,2,3,4,5]
// 输出: true

// 示例 2:
// 输入: [5,4,3,2,1]
// 输出: false
// */
// bool increasingTriplet(const vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 3)
//         return false;

//     int num1 = nums[0], num2 = INT_MIN;
//     for (int i = 1; i < length; i++)
//     {
//         int t = nums[i];
//         if (t > num1)
//         {
//             if (num2 == INT_MIN || t < num2)
//             {
//                 num2 = t;
//             }
//             else if (t > num2)
//                 return true;
//         }
//         else if (t < num1)
//         {
//             num1 = t;
//         }
//     }
//     return false;
// }

// /*
// 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
// 这个地区只有一个入口，我们称之为“根”。
// 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
// 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

// 示例 1:
// 输入: [3,2,3,null,3,null,1]
//      3
//     / \
//    2   3
//     \   \
//      3   1

// 输出: 7
// 解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

// 示例 2:
// 输入: [3,4,5,1,3,null,1]

//      3
//     / \
//    4   5
//   / \   \
//  1   3   1

// 输出: 9
// 解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

// 思路：深搜（会超时）
// */
// //int robRecursively(TreeNode *p, bool is_parent_rob)
// //{
// //    if (p == nullptr)
// //        return 0;
// //
// //    int t1 = robRecursively(p->left, false);
// //    int t2 = robRecursively(p->right, false);
// //    int t = t1 + t2;
// //    if (is_parent_rob)
// //    {
// //        return t;
// //    }
// //    else
// //    {
// //        int t1 = robRecursively(p->left, true);
// //        int t2 = robRecursively(p->right, true);
// //        return std::max(t, t1 + t2 + p->val);
// //    }
// //}
// //int rob(TreeNode *root)
// //{
// //    if (root == nullptr)
// //        return 0;
// //    if (root->left == nullptr && root->right == nullptr)
// //        return root->val;
// //
// //    int t1 = robRecursively(root, true);
// //    int t2 = robRecursively(root, false);
// //
// //    return std::max(t1, t2);
// //}
// /*
// 思路2：
// 1）动态规划
// 2）分情况：
//     a.当前节点打劫，那么左右子节点不能打劫，即dp[p][1] = dp[l][0] + dp[r][0] + p->val
//     b.当前节点不打劫，那么左右子节点可以选择打劫或不打劫，即dp[p][0] = max( max(dp[l][0], dp[l][1]), max(dp[r][0], dp[r][1]) )
// */
// pair<int, int> robRecursively(TreeNode *root)
// {
//     pair<int, int> result(0, 0), left(0, 0), right(0, 0);
//     if (root->left)
//         left = robRecursively(root->left);
//     if (root->right)
//         right = robRecursively(root->right);

//     result.first = max(left.first, left.second) + max(right.first, right.second);
//     result.second = left.first + right.first + root->val;
//     return result;
// }
// int rob(TreeNode *root)
// {
//     if (!root)
//         return 0;

//     // first代表不打劫当前节点，second代表打劫当前节点
//     pair<int, int> result = robRecursively(root);
//     return max(result.first, result.second);
// }

// /*
// 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

// 示例 1:
// 输入: 2
// 输出: [0,1,1]

// 示例 2:
// 输入: 5
// 输出: [0,1,1,2,1,2]

// 进阶:
// 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
// 要求算法的空间复杂度为O(n)。
// 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。

// 思路：
// 1）位运算
// 2）去掉当前数num的最后一个1后得到num_，那么res[num] = res[num_] + 1
// */
// vector<int> countBits(int num)
// {
//     if (num < 0)
//         return {};
//     if (num == 0)
//         return {0};

//     vector<int> res(num + 1, 0);

//     for (int i = 1; i <= num; i++)
//     {
//         res[i] = res[i ^ (i & -i)] + 1;
//     }

//     return res;
// }
// /*
// 思路2：
// 1）找规律
//     0：0000 -> 0

//     1：0001 -> 1 = cnt[0] + 1

//     2：0010 -> 1 = cnt[0] + 1 // 2~3的值为0~1的值加一
//     3：0011 -> 2 = cnt[1] + 1

//     4：0100 -> 1 = cnt[0] + 1 // 4~7的值为0~3的值加一
//     5：0101 -> 2 = cnt[1] + 1
//     6：0110 -> 2 = cnt[2] + 1
//     7：0111 -> 3 = cnt[3] + 1

//     8：1000 -> 1 = cnt[0] + 1 // 8~15的值为0~7的值加一
// */
// vector<int> countBits2(int num)
// {
//     if (num < 0)
//         return {};
//     if (num == 0)
//         return {0};

//     vector<int> res(num + 1, 0);

//     int offset = 1;
//     for (int i = 1; i <= num; i++)
//     {
//         if (offset << 1 == i)
//             offset <<= 1;
//         res[i] = res[i - offset] + 1;
//     }

//     return res;
// }

// /*
// 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

// 示例 1:
// 输入: 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1。

// 示例 2:
// 输入: 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
// 说明: 你可以假设 n 不小于 2 且不大于 58。

// 思路：动态规划 https://leetcode-cn.com/problems/integer-break/solution/tan-xin-xuan-ze-xing-zhi-de-jian-dan-zheng-ming-py
// */
// int integerBreak(int n)
// {
//     vector<int> dp(n + 1, -1);
//     dp[1] = 1;

//     for (int i = 2; i <= n; i++)
//     {
//         for (int j = 1; j <= i - 1; j++)
//         {
//             dp[i] = std::max(dp[i], std::max(j * (i - j), j * dp[i - j]));
//         }
//     }
//     return dp[n];
// }

// /*
// 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

// 示例 1:
// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]

// 示例 2:
// 输入: nums = [1], k = 1
// 输出: [1]

// 说明：
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
//  */
// vector<int> topKFrequent(const vector<int> &nums, int k)
// {
//     vector<int> res;
//     if (nums.empty() || k < 1)
//         return res;

//     unordered_map<int, int> m;
//     for (int num : nums)
//         ++m[num];

//     vector<pair<int, int>> t;
//     for (const auto &item : m)
//         t.push_back({item.second, item.first});

//     std::sort(t.begin(), t.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
//         return a.first > b.first;
//     });

//     for (int i = 0; i < k; i++)
//         res.push_back(t[i].second);

//     // auto Comp = [](const pair<int, int> &a, const pair<int, int> &b) {
//     //     return a.first < b.first;
//     // };
//     // multiset<pair<int, int>, decltype(Comp)> topk(Comp);
//     // for (const auto &item : m)
//     // {
//     //     if (topk.size() < k)
//     //         topk.insert({item.second, item.first});
//     //     else
//     //     {
//     //         if (topk.begin()->first < item.second)
//     //         {
//     //             topk.erase(topk.begin());
//     //             topk.insert({item.second, item.first});
//     //         }
//     //     }
//     // }
//     // for (const auto &t : topk)
//     //     res.push_back(t.second);

//     return res;
// }

// /*
// 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。

// 示例:
// 输入: 2
// 输出: 91
// 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字

// 思路：
// n=1: res=10
// n=2: res=9 * 9 + 10 = 91 # 两位数第一位只能为1-9，第二位只能为非第一位的数，加上一位数的所有结果
// n=3: res=9 * 9 * 8 + 91 = 739 # 三位数第一位只能为1-9，第二位只能为非第一位的数，第三位只能为非前两位的数，加上两位数的所有结果
// n=4: res=9 * 9 * 8 * 7 + 739 = 5275 # 同上推法
//  */
// int countNumbersWithUniqueDigits(int n)
// {
//     if (n < 0)
//         return 0;
//     if (n == 0)
//         return 1;

//     int res = 10;
//     int muls = 9;
//     // n>=10的结果和n==10时一致，因为位数为10位以上时，至少存在两个相同的数字
//     for (int i = 1; i < n && i < 10; i++)
//     {
//         muls *= 10 - i;
//         res += muls;
//     }
//     return res;
// }

// /*
// 有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
// 如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
// 你允许：
// 装满任意一个水壶
// 清空任意一个水壶
// 从一个水壶向另外一个水壶倒水，直到装满或者倒空

// 示例 1: (From the famous "Die Hard" example)
// 输入: x = 3, y = 5, z = 4
// 输出: True

// 示例 2:
// 输入: x = 2, y = 6, z = 5
// 输出: False

// 思路：裴蜀定理（x和y的最大公约数能否被z整除）
//  */
// bool canMeasureWater(int x, int y, int z)
// {
//     if (z == 0 || x + y == z || x == z || y == z)
//         return true;
//     if (x + y < z)
//         return false;

//     int t;
//     while ((t = x % y) != 0)
//     {
//         x = y;
//         y = t;
//     }
//     return z % y == 0;
// }

// /*
// 给出一个由无重复的正整数组成的集合，找出其中最大的整除子集，子集中任意一对 (Si，Sj) 都要满足：Si % Sj = 0 或 Sj % Si = 0。
// 如果有多个目标子集，返回其中任何一个均可。
//  
// 示例 1:
// 输入: [1,2,3]
// 输出: [1,2] (当然, [1,3] 也正确)

// 示例 2:
// 输入: [1,2,4,8]
// 输出: [1,2,4,8]

// 思路：
// 1）排序+动态规划
// 2）题目要求子集，并且Si % Sj = 0 或 Sj % Si = 0，那么结果与顺序无关，可以先排序，使小的在前面，计算Si % Sj = 0，其中i > j即可
// 3）动态规划：
//     a.令dp[i]表示到i（包括i）的最大子集
//     b.那么dp[i] = max(dp[i], dp[j] + 1)，其中0 <= j < i && nums[i] % nums[j] == 0
//     c.结果是子集，令pre[i]表示当前数的前一个数的下标
//     d.最后扫描dp，得到最大的子集长度，然后根据pre得到整个子集
//  */
// vector<int> largestDivisibleSubset(vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 2)
//         return nums;

//     // 排序
//     std::sort(nums.begin(), nums.end());

//     vector<int> dp(length, 1), pre(length, -1);
//     int max_len = 1, max_idx = 0; // 最大子集长度，最大子集的最后一个数的下标
//     for (int i = 1; i < length; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             // dp更新
//             if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
//             {
//                 dp[i] = dp[j] + 1;
//                 pre[i] = j;
//             }
//         }
//         if (dp[i] > max_len)
//         {
//             max_len = dp[i];
//             max_idx = i;
//         }
//     }

//     vector<int> res;
//     while (max_idx != -1) // 根据pre回溯得到结果
//     {
//         res.push_back(nums[max_idx]);
//         max_idx = pre[max_idx];
//     }
//     return res;
// }

// /*
// 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

// 示例 1:
// 输入: a = 2, b = [3]
// 输出: 8

// 示例 2:
// 输入: a = 2, b = [1,0]
// 输出: 1024

// 思路：a^b%c == ((a^b1%c)^10%c * a^b2%c)%c, where b1*10+b2=b
//  */
// int pow_(int x, int n)
// {
//     if (n == 0)
//         return 1;
//     if (n == 1)
//         return x % 1337;

//     int res = pow_(x, n / 2);

//     int x_2 = res * res % 1337;
//     if (n % 2 == 0)
//         return x_2;
//     else
//         return (x_2 * (x % 1337)) % 1337;
// }
// int superPow(int a, vector<int> &b)
// {
//     if (a == 0 || a == 1)
//         return a;

//     int res = 1;
//     for (int i : b)
//     {
//         res = (pow_(res, 10) * pow_(a, i)) % 1337;
//     }
//     return res;
// }

// /*
// 给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。
// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。
// 找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。

// 示例 1:
// 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// 输出: [1,2],[1,4],[1,6]
// 解释: 返回序列中的前 3 对数：
//      [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

// 示例 2:
// 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// 输出: [1,1],[1,1]
// 解释: 返回序列中的前 2 对数：
//      [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

// 示例 3:
// 输入: nums1 = [1,2], nums2 = [3], k = 3
// 输出: [1,3],[2,3]
// 解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]

// 思路：将所有组合求出，然后按两数和进行排序，最后取前k个
//  */
// vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
// {
//     int length1 = nums1.size(), length2 = nums2.size();
//     if (length1 == 0 || length2 == 0 || k <= 0)
//         return vector<vector<int>>();

//     vector<vector<int>> pairs;
//     pairs.reserve(length1 * length2);
//     for (int num1 : nums1)
//         for (int num2 : nums2)
//             pairs.push_back({num1, num2});

//     if (length1 * length2 <= k)
//         return pairs;

//     std::nth_element(pairs.begin(), pairs.begin() + k - 1, pairs.end(), [](const vector<int> &a, const vector<int> &b) {
//         return a[0] + a[1] < b[0] + b[1];
//     });

//     return vector<vector<int>>(pairs.begin(), pairs.begin() + k);
// }
// // 思路2：使用大根堆。维持一个大小为k的大根堆，遍历所有组合，如果当前组合小于堆顶，堆顶出堆然后当前组合入堆
// vector<vector<int>> kSmallestPairs2(vector<int> &nums1, vector<int> &nums2, int k)
// {
//     int length1 = nums1.size(), length2 = nums2.size();
//     if (length1 == 0 || length2 == 0 || k <= 0)
//         return vector<vector<int>>();

//     vector<vector<int>> res;
//     int n = std::min(k, length1 * length2);
//     res.reserve(n);

//     auto comp = [](const vector<int> &a, const vector<int> &b) {
//         return a[0] + a[1] < b[0] + b[1];
//     };

//     priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> qu(comp);
//     for (int i = 0; i < length1; i++)
//     {
//         for (int j = 0; j < length2; j++)
//         {
//             if (qu.size() < n)
//                 qu.push({nums1[i], nums2[j]});
//             else if (nums1[i] + nums2[j] < qu.top()[0] + qu.top()[1])
//             {
//                 qu.pop();
//                 qu.push({nums1[i], nums2[j]});
//             }
//         }
//     }

//     while (!qu.empty())
//     {
//         res.push_back(qu.top());
//         qu.pop();
//     }

//     return res;
// }
// /*
// 思路3：使用小根堆。
// 1）由于两个数组都是升序排列，那么所有组合按下标构成的二维数组，从左到右，从上到下依次递增的
//     对于当前元素，下一个最小元素在下边或右边
// 2）维护一个大小为k的小根堆，初始时先把第一列（nums2的下标保持为0）入堆
// 3）每次取出最小，并加入最小元素右边的元素（nums2的下标加一）
//  */
// vector<vector<int>> kSmallestPairs3(vector<int> &nums1, vector<int> &nums2, int k)
// {
//     if (nums1.empty() || nums2.empty())
//         return vector<vector<int>>();

//     auto Cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) {
//         return (nums1[a.first] + nums2[a.second]) > (nums1[b.first] + nums2[b.second]);
//     };

//     priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(Cmp)> pq(Cmp);
//     for (int i = 0; i < nums1.size() && i < k; i++)
//         pq.push({i, 0});

//     vector<vector<int>> result;
//     while (result.size() < k && !pq.empty())
//     {
//         auto min = pq.top();
//         pq.pop();
//         result.push_back({nums1[min.first], nums2[min.second]});

//         if (min.second < nums2.size() - 1)
//             pq.push({min.first, min.second + 1});
//     }
//     return result;
// }

// /*
// 我们正在玩一个猜数游戏，游戏规则如下：
// 我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。
// 每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。
// 然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。

// 示例:
// n = 10, 我选择了8.
// 第一轮: 你猜我选择的数字是5，我会告诉你，我的数字更大一些，然后你需要支付5块。
// 第二轮: 你猜是7，我告诉你，我的数字更大一些，你支付7块。
// 第三轮: 你猜是9，我告诉你，我的数字更小一些，你支付9块。
// 游戏结束。8 就是我选的数字。
// 你最终要支付 5 + 7 + 9 = 21 块钱。
// 给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。

// 思路：动态规划（https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/solution/cai-shu-zi-da-xiao-ii-by-leetcode）
//  */
// int getMoneyAmount(int n)
// {
//     if (n <= 1)
//         return 0;

//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//     for (int len = 2; len <= n; len++)
//     {
//         for (int i = 1; i <= n - len + 1; i++)
//         {
//             int min = INT_MAX;
//             for (int t = i + (len - 1) / 2; t < i + len - 1; t++)
//             {
//                 min = std::min(min, std::max(dp[i][t - 1], dp[t + 1][i + len - 1]) + t);
//             }
//             dp[i][i + len - 1] = min;
//         }
//     }

//     // for (const auto row : dp)
//     //     printContainer(row);

//     return dp[1][n];
// }

// /*
// 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。
// 例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。
// 相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
// 给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

// 示例 1:
// 输入: [1,7,4,9,2,5]
// 输出: 6
// 解释: 整个序列均为摆动序列。

// 示例 2:
// 输入: [1,17,5,10,13,15,10,5,16,8]
// 输出: 7
// 解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。

// 示例 3:
// 输入: [1,2,3,4,5,6,7,8,9]
// 输出: 2
// 进阶:
// 你能否用 O(n) 时间复杂度完成此题?
//  */
// int wiggleMaxLength(const vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 2)
//         return length;

//     // 计算差值
//     vector<int> diff;
//     diff.reserve(length - 1);
//     for (int i = 1; i < length; i++)
//         diff.push_back(nums[i] - nums[i - 1]);

//     int res = 0;
//     int pre = -1;         // 0代表负差值，1代表正差值，-1代表未知
//     bool all_zero = true; // 所有差值都是0
//     // 统计差值的跳变（正负或者是负正）次数
//     for (int i = 0; i < length - 1; i++)
//     {
//         if (diff[i] == 0) // 差值为0，跳过
//             continue;

//         all_zero = false;
//         if (pre == -1) // 找到第一个非零差值
//             pre = diff[i] < 0 ? 0 : 1;
//         else
//         {
//             int cur = diff[i] < 0 ? 0 : 1;
//             if (cur == 1 - pre) // 发生跳变
//             {
//                 ++res;
//                 pre = 1 - pre;
//             }
//         }
//     }

//     if (all_zero) // 差值都是0，那么结果只能为1
//         return 1;
//     return res + 2; // 统计的是差值的跳变，最后要返回的是子序列
// }

// /*
// 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

// 示例:
// nums = [1, 2, 3]
// target = 4
// 所有可能的组合为：
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// 请注意，顺序不同的序列被视作不同的组合。
// 因此输出为 7。

// 进阶：
// 如果给定的数组中含有负数会怎么样？
// 问题会产生什么变化？
// 我们需要在题目中添加什么限制来允许负数的出现？

// 思路：深度搜索（超时）
//  */
// void combinationSum4Recursively(vector<int> &nums, int target, int start, int &res)
// {
//     if (target < 0)
//         return;
//     if (target == 0)
//     {
//         ++res;
//         return;
//     }

//     for (int i = start; i < nums.size(); i++)
//         combinationSum4Recursively(nums, target - nums[i], start, res);
// }
// int combinationSum4(vector<int> &nums, int target)
// {
//     if (nums.size() == 0)
//         return 0;

//     std::sort(nums.begin(), nums.end());

//     int res = 0;
//     combinationSum4Recursively(nums, target, 0, res);
//     return res;
// }
// // 思路2：动态规划
// int combinationSum4_2(vector<int> &nums, int target)
// {
//     if (nums.size() == 0)
//         return 0;

//     vector<int> dp(target + 1, 0);
//     dp[0] = 1;
//     for (int i = 1; i < target + 1; i++)
//     {
//         for (int num : nums)
//         {
//             if (num <= i)
//             {
//                 unsigned long long t = static_cast<unsigned long long>(dp[i]) + dp[i - num];
//                 if (t > INT_MAX)
//                     break;
//                 dp[i] += dp[i - num]; // dp[i]=sum(dp[i-num]) num∈nums && num<=i
//             }
//         }
//     }
//     // printContainer(dp);
//     return dp[target];
// }

// /*
// 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
// 请注意，它是排序后的第k小元素，而不是第k个元素。

// 示例:
// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,
// 返回 13。

// 说明:
// 你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n^2 。

// 思路：小根堆
//  */
// int kthSmallest(vector<vector<int>> &matrix, int k)
// {
//     int rows = matrix.size();
//     if (rows == 0)
//         throw runtime_error("matrix is invalid");
//     int cols = matrix[0].size();
//     if (cols == 0)
//         throw runtime_error("matrix is invalid");

//     if (k == 1)
//         return matrix[0][0];
//     if (k == rows * cols)
//         return matrix[rows - 1][cols - 1];

//     using Pij = pair<int, int>;
//     auto comp = [&matrix](const Pij &a, const Pij &b) {
//         return matrix[a.first][a.second] > matrix[b.first][b.second];
//     };

//     priority_queue<Pij, vector<Pij>, decltype(comp)> qu(comp);
//     for (int row = 0, len = std::min(rows, k); row < len; row++)
//         qu.push({row, 0});

//     int res;
//     while (k > 0 && !qu.empty())
//     {
//         Pij t = qu.top();
//         res = matrix[t.first][t.second];
//         qu.pop();
//         if (t.second < cols - 1)
//             qu.push({t.first, t.second + 1});
//         --k;
//     }

//     return res;
// }
// // 思路2：二分查找
// int kthSmallest2(vector<vector<int>> &matrix, int k)
// {
//     int n = matrix.size();
//     if (n == 1)
//         return matrix[0][0];
//     if (k == n * n)
//         return matrix[n - 1][n - 1];

//     int low = matrix[0][0], high = matrix[n - 1][n - 1], mid;
//     int cnt;
//     while (high - low >= 0) // 二分查找定位中位数
//     {
//         mid = (low + high) / 2;
//         cnt = 0;
//         int i = 0, j = n - 1;
//         while (i < n && j >= 0) // 找出不超过中位数的元素个数cnt（遍历每行，定位列，累计数量）
//         {
//             if (matrix[i][j] <= mid)
//             {
//                 cnt += j + 1;
//                 ++i;
//             }
//             else
//                 --j;
//         }
//         // 根据cnt和k的大小更新二分查找端点
//         if (cnt < k)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }
//     return low;
// }

// // 蓄水池抽样算法(https://www.cnblogs.com/snowInPluto/p/5996269.html)
// vector<int> reservoirSampling(ListNode *head, int k)
// {
//     vector<int> res;
//     res.reserve(k);

//     ListNode *p = head;
//     for (int i = 0; i < k; i++)
//     {
//         res.push_back(p->val);
//         p = p->next;
//     }

//     int i = 1;
//     while (p != nullptr)
//     {
//         int idx = std::rand() % (k + i);
//         if (idx < k)
//             res[idx] = p->val;
//         ++i;
//         p = p->next;
//     }

//     return res;
// }

// // /*
// // 给定一个用字符串表示的整数的嵌套列表，实现一个解析它的语法分析器。
// // 列表中的每个元素只可能是整数或整数嵌套列表
// // 提示：你可以假定这些字符串都是格式良好的：
// // 字符串非空
// // 字符串不包含空格
// // 字符串只包含数字0-9, [, - ,, ]

// // 示例 1：
// // 给定 s = "324",
// // 你应该返回一个 NestedInteger 对象，其中只包含整数值 324。

// // 示例 2：
// // 给定 s = "[123,[456,[789]]]",
// // 返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
// // 1. 一个 integer 包含值 123
// // 2. 一个包含两个元素的嵌套列表：
// //     i.  一个 integer 包含值 456
// //     ii. 一个包含一个元素的嵌套列表
// //          a. 一个 integer 包含值 789

// // 思路：使用栈
// //  */
// // NestedInteger deserialize(const string &s)
// // {
// //     int idx = 0;
// //     stack<NestedInteger *> st;
// //     while (idx < s.size())
// //     {
// //         if (s[idx] == '[')
// //         {
// //             ++idx;
// //             st.push(new NestedInteger());
// //             st.push(nullptr); // 空指针指示这是一个 列表NestedInteger
// //         }
// //         else if (s[idx] == ',')
// //         {
// //             ++idx;
// //             continue;
// //         }
// //         else if (s[idx] == ']') // 将栈内从 [ 到 ] 的所有 NestedInteger 放入空指针指示的 列表NestedInteger 中
// //         {
// //             ++idx;
// //             stack<NestedInteger *> t; // 将逆序的从 [ 到 ] 的所有 NestedInteger 通过另一个栈转为正序
// //             while (!st.empty() && st.top() != nullptr)
// //             {
// //                 t.push(st.top());
// //                 st.pop();
// //             }
// //             st.pop(); // 弹出空指针
// //             while (!t.empty())
// //             {
// //                 st.top()->add(*t.top());
// //                 delete t.top();
// //                 t.pop();
// //             }
// //         }
// //         else
// //         {
// //             int start = idx;
// //             while (idx < s.size() && (s[idx] == '-' || s[idx] >= '0' && s[idx] <= '9'))
// //                 ++idx;
// //             st.push(new NestedInteger(std::stoi(s.substr(start, idx - start))));
// //         }
// //     }

// //     NestedInteger res = *st.top();
// //     delete st.top();
// //     return res;
// // }
// // // 改进，栈中只保存 列表NestedInteger
// // NestedInteger deserialize2(const string &s)
// // {
// //     if (s[0] != '[')
// //         return NestedInteger(stoi(s));

// //     int idx = 0;
// //     stack<NestedInteger> st;
// //     while (idx < s.size())
// //     {
// //         if (s[idx] == '[')
// //         {
// //             ++idx;
// //             st.push(NestedInteger());
// //         }
// //         else if (s[idx] == ',')
// //         {
// //             ++idx;
// //             continue;
// //         }
// //         else if (s[idx] == ']') // 将子 列表NestedInteger 加入父 列表NestedInteger 中
// //         {
// //             ++idx;
// //             if (st.size() > 1)
// //             {
// //                 NestedInteger t = st.top();
// //                 st.pop();
// //                 st.top().add(t);
// //             }
// //         }
// //         else // 数字NestedInteger 直接加入 列表NestedInteger 中
// //         {
// //             int start = idx;
// //             while (idx < s.size() && (s[idx] == '-' || s[idx] >= '0' && s[idx] <= '9'))
// //                 ++idx;
// //             st.top().add(NestedInteger(std::stoi(s.substr(start, idx - start))));
// //         }
// //     }

// //     return st.top();
// // }

// /*
// 给定一个整数 n, 返回从 1 到 n 的字典顺序。

// 例如，
// 给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
// 请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。

// 思路：转字符串，然后排序
//  */
// vector<int> lexicalOrder(int n)
// {
//     if (n < 1)
//         return vector<int>();

//     vector<string> vec;
//     vec.reserve(n);
//     for (int i = 1; i <= n; i++)
//         vec.emplace_back(std::to_string(i));

//     std::sort(vec.begin(), vec.end());

//     vector<int> res;
//     res.reserve(n);
//     for (const string &s : vec)
//         res.emplace_back(std::stoi(s));
//     return res;
// }
// /*
// 思路2：递归深搜，直接生成
//  */
// void lexicalOrderRecursively(int cur, int n, vector<int> &res)
// {
//     //根节点横向展开
//     for (int i = 0; i < 10; i++)
//     {
//         int tmp = cur * 10 + i;
//         if (tmp > n)
//             break;
//         res.push_back(tmp);
//         //根节点纵向展开
//         lexicalOrderRecursively(tmp, n, res);
//     }
// }
// vector<int> lexicalOrder2(int n)
// {
//     vector<int> res;
//     //按照不同的树根节点展开
//     for (int i = 1; i < 10; i++)
//     {
//         if (i > n)
//             break;
//         res.push_back(i);
//         lexicalOrderRecursively(i, n, res);
//     }
//     return res;
// }

// /*
// 假设我们以下述方式将我们的文件系统抽象成一个字符串:
// 字符串 "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" 表示:
// dir
//     subdir1
//     subdir2
//         file.ext
// 目录 dir 包含一个空的子目录 subdir1 和一个包含一个文件 file.ext 的子目录 subdir2 。

// 字符串 "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" 表示:
// dir
//     subdir1
//         file1.ext
//         subsubdir1
//     subdir2
//         subsubdir2
//             file2.ext
// 目录 dir 包含两个子目录 subdir1 和 subdir2。 
// subdir1 包含一个文件 file1.ext 和一个空的二级子目录 subsubdir1。
// subdir2 包含一个二级子目录 subsubdir2 ，其中包含一个文件 file2.ext。

// 我们致力于寻找我们文件系统中文件的最长 (按字符的数量统计) 绝对路径。
// 例如，在上述的第二个例子中，最长路径为 "dir/subdir2/subsubdir2/file2.ext"，其长度为 32 (不包含双引号)。
// 给定一个以上述格式表示文件系统的字符串，返回文件系统中文件的最长绝对路径的长度。 如果系统中没有文件，返回 0。
// 说明:
// 文件名至少存在一个 . 和一个扩展名。
// 目录或者子目录的名字不能包含 .。
// 要求时间复杂度为 O(n) ，其中 n 是输入字符串的大小。
// 请注意，如果存在路径 aaaaaaaaaaaaaaaaaaaaa/sth.png 的话，那么  a/aa/aaa/file1.txt 就不是一个最长的路径。
// */
// void replace_(string &s, const string &a, const string &b)
// {
//     /*
//     将字符串s中的所有a替换成b
//     */
//     auto pos = s.find(a);
//     while (pos != string::npos)
//     {
//         s.replace(pos, a.size(), b);
//         pos = s.find(a, pos + b.size());
//     }
// }
// int lengthLongestPath(string &input)
// {
//     if (input.empty())
//         return 0;

//     bool find_file = false; // 是否找到文件
//     int res = 0;
//     int len = 0; // 当前路径长度
//     int i = 0;

//     input = '\n' + input;
//     // 将测试用例的 "\n    " 替换成统一的 "\n\t"
//     replace_(input, "\n    ", "\n\t");

//     // 用栈模拟深搜
//     stack<pair<int, int>> st; // <tab数，字符串长度>，tab数是否相同意味着是否处于同一目录（层）
//     while (i < input.size())
//     {
//         bool is_file = false; // 当前字符串是否是文件
//         int tab_cnt = 0;

//         ++i; // 跳过当前\n

//         while (i < input.size() && input[i] == '\t') // 计算\t的个数，并跳过
//         {
//             ++i;
//             ++tab_cnt;
//         }

//         // 处理当前字符串
//         int word_len = 0;
//         while (i < input.size() && input[i] != '\n')
//         {
//             if (input[i] == '.') // 说明是一个文件
//             {
//                 find_file = true;
//                 is_file = true;
//             }
//             ++word_len;
//             ++i;
//         }

//         //如果当前栈顶的tab数大于或等于当前tab数，需要回溯到父目录
//         while (!st.empty() && st.top().first >= tab_cnt)
//         {
//             len -= st.top().second;
//             st.pop();
//         }
//         // 是/word，不是word，别忘了/
//         len += (word_len + 1);
//         // 将当前字符串入栈
//         st.push({tab_cnt, word_len + 1});
//         // 更新结果
//         if (is_file)
//             res = std::max(len, res);
//     }
//     return find_file ? std::max(res, len) - 1 : 0;
// }

// /*
// 给定一个从1 到 n 排序的整数列表。
// 首先，从左到右，从第一个数字开始，每隔一个数字进行删除，直到列表的末尾。
// 第二步，在剩下的数字中，从右到左，从倒数第一个数字开始，每隔一个数字进行删除，直到列表开头。
// 我们不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
// 返回长度为 n 的列表中，最后剩下的数字。

// 示例：
// 输入:
// n = 9,
// 1 2 3 4 5 6 7 8 9
// 2 4 6 8
// 2 6
// 6
// 输出:
// 6

// 思路：模拟法（超时）
// */
// int lastRemaining(int n)
// {
//     if (n == 1)
//         return 1;

//     list<int> lst;
//     for (int i = 1; i <= n; i++)
//         lst.push_back(i);

//     int direction = 0;
//     while (lst.size() > 1)
//     {
//         if (direction == 0)
//         {
//             auto iter = lst.begin();
//             while (iter != lst.end())
//             {
//                 iter = lst.erase(iter);
//                 if (iter != lst.end())
//                     ++iter;
//             }
//             direction = 1 - direction;
//         }
//         else
//         {
//             auto iter = lst.rbegin();
//             while (iter != lst.rend())
//             {
//                 iter = list<int>::reverse_iterator(lst.erase((++iter).base()));
//                 if (iter != lst.rend())
//                     ++iter;
//             }
//             direction = 1 - direction;
//         }
//     }

//     return *lst.begin();
// }
// // 思路：找规律。。。（f(n) + f(2n) / 2 = n + 1）
// int lastRemaining2(int n)
// {
//     return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
// }

// /*
// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
// 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
// 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

// 示例 1:
// s = "abc", t = "ahbgdc"
// 返回 true.

// 示例 2:
// s = "axc", t = "ahbgdc"
// 返回 false.

// 后续挑战 :
// 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
// */
// bool isSubsequence(const string &s, const string &t)
// {
//     if (s.empty())
//         return true;
//     if (t.empty())
//         return false;

//     int idx_s = 0, idx_t = 0;
//     while (idx_s < s.size() && idx_t < t.size())
//     {
//         if (s[idx_s] == t[idx_t])
//         {
//             ++idx_s;
//             ++idx_t;
//         }
//         else
//             ++idx_t;
//     }
//     if (idx_s >= s.size())
//         return true;
//     return false;
// }

// /*
// UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
// 对于 1 字节的字符，字节的第一位设为0，后面7位为这个符号的unicode码。
// 对于 n 字节的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为0，后面字节的前两位一律设为10。剩下的没有提及的二进制位，全部为这个符号的unicode码。
// 这是 UTF-8 编码的工作方式：

//    Char. number range  |        UTF-8 octet sequence
//       (hexadecimal)    |              (binary)
//    --------------------+---------------------------------------------
//    0000 0000-0000 007F | 0xxxxxxx
//    0000 0080-0000 07FF | 110xxxxx 10xxxxxx
//    0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
//    0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
// 给定一个表示数据的整数数组，返回它是否为有效的 utf-8 编码。

// 注意:
// 输入是整数数组。只有每个整数的最低 8 个有效位用来存储数据。这意味着每个整数只表示 1 字节的数据。

// 示例 1:
// data = [197, 130, 1], 表示 8 位的序列: 11000101 10000010 00000001.
// 返回 true 。
// 这是有效的 utf-8 编码，为一个2字节字符，跟着一个1字节字符。

// 示例 2:
// data = [235, 140, 4], 表示 8 位的序列: 11101011 10001100 00000100.
// 返回 false 。
// 前 3 位都是 1 ，第 4 位为 0 表示它是一个3字节字符。
// 下一个字节是开头为 10 的延续字节，这是正确的。
// 但第二个延续字节不以 10 开头，所以是不符合规则的。
// */
// bool validUtf8(const vector<int> &data)
// {
//     if (data.empty())
//         return true;

//     int length = data.size();
//     int idx = 0;
//     while (idx < length)
//     {
//         int c = data[idx];
//         if ((c & 0b10000000) == 0)
//             ++idx;
//         else
//         {
//             int cnt;
//             if ((c & 0b11100000) == 0b11000000)
//                 cnt = 1;
//             else if ((c & 0b11110000) == 0b11100000)
//                 cnt = 2;
//             else if ((c & 0b11111000) == 0b11110000)
//                 cnt = 3;
//             else
//                 return false;

//             ++idx;
//             for (; idx < length && cnt > 0; --cnt, ++idx)
//             {
//                 if ((data[idx] & 0b11000000) != 0b10000000)
//                     return false;
//             }
//             if (cnt > 0)
//                 return false;
//         }
//     }
//     return true;
// }

// /*
// 给定一个经过编码的字符串，返回它解码后的字符串。
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

// 示例:
// s = "3[a]2[bc]", 返回 "aaabcbc".
// s = "3[a2[c]]", 返回 "accaccacc".
// s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

// 思路：双栈法
// */
// string decodeString(const string &s)
// {
//     if (s.empty())
//         return string();

//     int length = s.size();
//     int idx = 0;
//     stack<int> st_cnt;
//     stack<ostringstream> st_str;
//     st_cnt.push(1);
//     st_str.push(ostringstream());
//     while (idx < length)
//     {

//         int start = idx;
//         if (std::isdigit(s[idx])) // 解析数字，入栈st_cnt，同时入栈st_str一个空字符串
//         {
//             int cnt = 0;
//             while (idx < length && std::isdigit(s[idx]))
//             {
//                 cnt = cnt * 10 + (s[idx] - '0');
//                 ++idx;
//             }
//             st_cnt.push(cnt);
//             st_str.push(ostringstream());
//         }
//         else if (s[idx] == '[')
//         {
//             ++idx;
//         }
//         else if (s[idx] == ']') // 解析到]，取栈顶st_cnt得到cnt，取栈顶st_str得到str，重复str指定的cnt次数后，加入st_str栈顶字符串中
//         {
//             int cnt = st_cnt.top();
//             st_cnt.pop();

//             string str = st_str.top().str();
//             st_str.pop();

//             for (int i = 0; i < cnt; i++)
//                 st_str.top() << str;

//             ++idx;
//         }
//         else // 解析字母，将字母加入st_str栈顶的字符串中
//         {
//             while (idx < length && std::isalpha(s[idx]))
//             {
//                 st_str.top() << s[idx];
//                 ++idx;
//             }
//         }
//     }
//     return st_str.top().str();
// }

// /*
// 找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

// 示例 1:
// 输入:
// s = "aaabb", k = 3
// 输出:
// 3
// 最长子串为 "aaa" ，其中 'a' 重复了 3 次。

// 示例 2:
// 输入:
// s = "ababbc", k = 2
// 输出:
// 5
// 最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

// 思路：递归拆分子串，分治。
// 先统计出每个字符出现的频次，维护一对双指针，从首尾开始统计，
// 从首尾往中间排除，如果出现次数小于k则不可能出现在最终子串中，排除并挪动指针，然后得到临时子串，
// 依次从头遍历，一旦发现出现频次小于k的字符，以该字符为分割线，分别递归求其最大值返回。
// */
// int longestSubstringRecursively(const string &s, int k, int left, int right)
// {
//     if (right - left + 1 < k)
//         return 0;

//     //数组代替哈希表，记录每个字符出现的频率
//     int char_cnt_map[26] = {0};
//     for (int i = left; i <= right; i++)
//         ++char_cnt_map[s[i] - 'a'];

//     // 双指针排除首尾不符合要求的字符
//     while (right - left + 1 >= k && char_cnt_map[s[left] - 'a'] < k)
//         ++left;
//     while (right - left + 1 >= k && char_cnt_map[s[right] - 'a'] < k)
//         --right;
//     if (right - left + 1 < k)
//         return 0;

//     // 在子串中遍历，得到不符合的字符，并以该字符分割，递归计算分割后左右子串的最大值
//     for (int i = left; i <= right; ++i)
//     {
//         if (char_cnt_map[s[i] - 'a'] < k)
//             return std::max(longestSubstringRecursively(s, k, left, i - 1), longestSubstringRecursively(s, k, i + 1, right));
//     }

//     // 子串中的字符都符合要求，直接返回
//     return right - left + 1;
// }
// int longestSubstring(const string &s, int k)
// {
//     int length = s.size();
//     if (length == 0 || k > length)
//         return 0;
//     if (k < 2)
//         return length;

//     return longestSubstringRecursively(s, k, 0, length - 1);
// }

// /*
// 给定一个长度为 n 的整数数组 A 。
// 假设 Bk 是数组 A 顺时针旋转 k 个位置后的数组，我们定义 A 的“旋转函数” F 为：
// F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]。
// 计算F(0), F(1), ..., F(n-1)中的最大值。
// 注意:
// 可以认为 n 的值小于 105。

// 示例:
// A = [4, 3, 2, 6]
// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
// 所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。

// 思路：暴力模拟法（超时）
// */
// int maxRotateFunction(vector<int> &A)
// {
//     int length = A.size();
//     if (length < 2)
//         return 0;

//     int res = INT_MIN;
//     for (int i = 0; i < length; i++)
//     {
//         int t = 0;
//         int n = i;
//         for (int j = 0; j < length; j++)
//         {
//             t += A[j] * (n % length);
//             ++n;
//         }
//         res = std::max(res, t);
//     }
//     return res;
// }
// /*
// 思路：找规律
// 记录第一次的结果，发现每次向右移动时，最大下标对应的值变为0了,然后其他位置每个数都增加了自己（即最后增加了：数组总和-最大下标对应的值）
// 示例:
// A = [4, 3, 2, 6]
// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
//     第一次
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
//     最大下标对应的6变为0，其他位置的系数都加了1：(0 * 4) + (1 * 3) + (2 * 2) -> (1 * 4) + (2 * 3) + (3 * 2)
// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
//     最大下标对应的2变为0，其他位置的系数都加了1：(0 * 6) + (1 * 4) + (2 * 3) -> (1 * 6) + (2 * 4) + (3 * 3)
// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
//     同理
// */
// int maxRotateFunction2(vector<int> &A)
// {
//     int length = A.size();
//     if (length < 2)
//         return 0;

//     long long int res = INT_MIN, cur = 0, sum = 0;
//     for (int i = 0; i < length; i++)
//     {
//         cur += A[i] * i;
//         sum += A[i];
//     }
//     res = cur;
//     for (int i = length - 1; i > 0; i--)
//     {
//         cur -= (length - 1) * A[i];
//         cur += sum - A[i];
//         res = std::max(res, cur);
//     }
//     return res;
// }

// /*
// 给定一个正整数 n，你可以做如下操作：
// 1. 如果 n 是偶数，则用 n / 2替换 n。
// 2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
// n 变为 1 所需的最小替换次数是多少？

// 示例 1:
// 输入:
// 8
// 输出:
// 3
// 解释:
// 8 -> 4 -> 2 -> 1

// 示例 2:
// 输入:
// 7
// 输出:
// 4
// 解释:
// 7 -> 8 -> 4 -> 2 -> 1
// 或
// 7 -> 6 -> 3 -> 2 -> 1

// 思路：递归
// */
// int integerReplacement(int n)
// {
//     if (n == 1)
//         return 0;
//     if (n == INT_MAX) // n为INT_MAX时，+1会溢出
//         return 32;

//     if (n % 2 == 0)
//         return integerReplacement(n >> 1) + 1;
//     else
//         return std::min(integerReplacement(n - 1), integerReplacement(n + 1)) + 1;
// }
// /*
// 思路2：位运算，除法的次数尽可能的多
// 1）为偶数，直接右移一位
// 2）为奇数，
//     a.当为3时，单独处理，为3时，+1最后结果为3，而-1最后结果为2
//     b.如果其二进制结尾是01的话，肯定是奇数，-1就可以
//     c.但是如果是11的话，-1以后，只能做一次除法操作，但是+1之后，可以连续做两次除法操作
// */
// int integerReplacement2(int n)
// {
//     long long int temp = n;
//     int count = 0;
//     while (temp != 1)
//     {
//         if ((temp & 3) == 3 && temp != 3)
//             ++temp;
//         else if ((temp & 1) == 1)
//             --temp;
//         else
//             temp >>= 1;
//         ++count;
//     }
//     return count;
// }

// /*
// 给出方程式 A / B = k, 其中 A 和 B 均为代表字符串的变量， k 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回 -1.0。

// 示例 :
// 给定 a / b = 2.0, b / c = 3.0
// 问题: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
// 返回 [6.0, 0.5, -1.0, 1.0, -1.0 ]
// 输入为: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries(方程式，方程式结果，问题方程式)， 
// 其中 equations.size() == values.size()，即方程式的长度与方程式结果长度相等（程式与结果一一对应），并且结果值均为正数。
// 以上为方程式的描述。 返回vector<double>类型。
// 基于上述例子，输入如下：
// equations(方程式) = [ ["a", "b"], ["b", "c"] ],
// values(方程式结果) = [2.0, 3.0],
// queries(问题方程式) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
// 输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果。

// 思路：转换问题为在图中查找两点之间的“距离”
// 1）a/b=c对应图中 a->b=c 和 b->a=1/c
// 2）先扫描得到所有的不同字符串，然后每个字符串对应一个下标
// 3）根据字符串数量，创建对应大小的邻接矩阵，然后遍历建图
// 4）最后查询时，直接在图中深搜查找两点之间的“距离”
// */
// void calcEquationRecursively(const vector<vector<double>> &graph, vector<bool> &flag, int src, int dst, double temp, double &ret)
// {
//     if (src == dst) // 找到目标点
//     {
//         ret = temp;
//         return;
//     }
//     if (graph[src][dst] != LONG_LONG_MAX) // 剪枝。在图中已存在，直接计算返回
//     {
//         ret = temp * graph[src][dst];
//         return;
//     }

//     for (int i = 0; i < flag.size(); i++) // 深搜遍历
//     {
//         if (flag[i] == false && graph[src][i] != LONG_LONG_MAX)
//         {
//             flag[i] = true;
//             calcEquationRecursively(graph, flag, i, dst, temp * graph[src][i], ret);
//             if (ret != -1) // 剪枝
//                 return;
//             flag[i] = false;
//         }
//     }
// }
// vector<double> calcEquation(const vector<vector<string>> &equations, const vector<double> &values, const vector<vector<string>> &queries)
// {
//     if (equations.empty() || queries.empty())
//         return {};

//     int str_cnt = 0;
//     unordered_map<string, int> str_idx_map;
//     for (const auto &eq : equations) // 扫描并建立字符串和下标对应关系
//     {
//         if (str_idx_map.count(eq[0]) == 0)
//         {
//             str_idx_map[eq[0]] = str_cnt;
//             ++str_cnt;
//         }
//         if (str_idx_map.count(eq[1]) == 0)
//         {
//             str_idx_map[eq[1]] = str_cnt;
//             ++str_cnt;
//         }
//     }
//     vector<vector<double>> graph(str_cnt, vector<double>(str_cnt, LONG_LONG_MAX));
//     for (int i = 0, length = equations.size(); i < length; ++i) // 建图
//     {
//         int row = str_idx_map[equations[i][0]];
//         int col = str_idx_map[equations[i][1]];
//         graph[row][col] = values[i];
//         graph[col][row] = 1 / values[i];
//     }

//     vector<double> res;
//     res.reserve(queries.size());
//     for (const auto &qu : queries)
//     {
//         const string &src = qu[0];
//         const string &dst = qu[1];
//         // 图中不存在对应字符
//         if (str_idx_map.count(src) == 0 || str_idx_map.count(dst) == 0)
//             res.push_back(-1);
//         // 起点和终点一致
//         else if (src == dst)
//             res.push_back(1);
//         // 图的深搜遍历
//         else
//         {
//             double ret = -1, temp = 1;
//             vector<bool> flag(str_cnt, false);
//             int src_idx = str_idx_map[src];
//             flag[src_idx] = true;
//             int dst_idx = str_idx_map[dst];
//             calcEquationRecursively(graph, flag, src_idx, dst_idx, temp, ret);
//             res.push_back(ret);
//             if (ret != -1) // 计算结果存入图中，可供后续使用
//             {
//                 graph[src_idx][dst_idx] = ret;
//                 graph[dst_idx][src_idx] = 1 / ret;
//             }
//         }
//     }
//     return res;
// }
// // 同上，不过使用floyd算法计算所有点之间的“距离”
// vector<double> calcEquation2(const vector<vector<string>> &equations, const vector<double> &values, const vector<vector<string>> &queries)
// {
//     if (equations.empty() || queries.empty())
//         return {};

//     int str_cnt = 0;
//     unordered_map<string, int> str_idx_map;
//     for (const auto &eq : equations) // 扫描并建立字符串和下标对应关系
//     {
//         if (str_idx_map.count(eq[0]) == 0)
//         {
//             str_idx_map[eq[0]] = str_cnt;
//             ++str_cnt;
//         }
//         if (str_idx_map.count(eq[1]) == 0)
//         {
//             str_idx_map[eq[1]] = str_cnt;
//             ++str_cnt;
//         }
//     }
//     vector<vector<double>> graph(str_cnt, vector<double>(str_cnt, LONG_LONG_MAX));
//     for (int i = 0; i < str_cnt; i++)
//         graph[i][i] = 1;
//     for (int i = 0, length = equations.size(); i < length; ++i) // 建图
//     {
//         int row = str_idx_map[equations[i][0]];
//         int col = str_idx_map[equations[i][1]];
//         graph[row][col] = values[i];
//         graph[col][row] = 1 / values[i];
//     }

//     // Floyd算法
//     for (int k = 0; k < str_cnt; ++k)
//         for (int i = 0; i < str_cnt; ++i)
//             for (int j = 0; j < str_cnt; ++j)
//                 if (graph[i][j] == LONG_LONG_MAX && graph[i][k] != LONG_LONG_MAX && graph[k][j] != LONG_LONG_MAX)
//                     graph[i][j] = graph[i][k] * graph[k][j];

//     vector<double> res;
//     res.reserve(queries.size());
//     for (const auto &qu : queries)
//     {
//         const string &src = qu[0];
//         const string &dst = qu[1];
//         // 图中不存在对应字符
//         if (str_idx_map.count(src) == 0 || str_idx_map.count(dst) == 0)
//             res.push_back(-1);
//         // 起点和终点一致
//         else if (src == dst)
//             res.push_back(1);
//         // 查图
//         else
//         {
//             int src_idx = str_idx_map[src];
//             int dst_idx = str_idx_map[dst];
//             if (graph[src_idx][dst_idx] != LONG_LONG_MAX)
//                 res.push_back(graph[src_idx][dst_idx]);
//             else
//                 res.push_back(-1);
//         }
//     }
//     return res;
// }

// /*
// 给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
// 注意:
// num 的长度小于 10002 且 ≥ k。
// num 不会包含任何前导零。

// 示例 1 :
// 输入: num = "1432219", k = 3
// 输出: "1219"
// 解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。

// 示例 2 :
// 输入: num = "10200", k = 1
// 输出: "200"
// 解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

// 示例 3 :
// 输入: num = "10", k = 2
// 输出: "0"
// 解释: 从原数字移除所有的数字，剩余为空就是0。

// 思路：贪心。尽可能移除高位的较大的数
// 1）由于后面的数可能大于前面的数，用一个栈从左至右按递增保存每位数字
// 2）由于栈顶是最大的，将当前数字和栈顶比较，如果栈顶更大，那么移除栈顶直至k次或栈为空
//     目的是移除num[i]>num[j]，i<j,使得num[i]<=num[j]
// 3）由于结果前导无零，如果当前是0并且栈为空，意味着0是前导0，不予以入栈
// */
// string removeKdigits(const string &num, int k)
// {
//     if (k <= 0)
//         return num;
//     int length = num.size();
//     if (length <= k || length == 0)
//         return "0";

//     string st;
//     st.push_back(num[0]);
//     for (int i = 1; i < length; i++)
//     {
//         char cur = num[i];
//         // 尽可能移除高位大的数
//         while (!st.empty() && k > 0 && st.back() > cur)
//         {
//             --k;
//             st.pop_back();
//         }
//         // 当前不是0；
//         // 当前是0，但栈不为空（不是前导0）
//         if (cur != '0' || !st.empty())
//             st.push_back(cur);
//     }
//     while (k > 0) // 栈是递增的，直接移除末尾
//     {
//         --k;
//         st.pop_back();
//     }
//     if (st.empty())
//         return "0";
//     return st;
// }

// /*
// 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。
// 注意：
// 总人数少于1100人。

// 示例
// 输入:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// 输出:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

// 思路：先排序，后插入
// 先对原数组按 h 降序、k 升序排序。然后遍历数组，根据元素的 k 值进行「插队操作」：直接把元素插入数组下标为 k 的位置。
// 这样排序的理由是：
// k 值表示排在这个人前面且身高大于或等于 h 的人数，按 h 降序排序可以确定身高更高者的人数
// 按 k 降序排序则先处理排在更前面的数，避免更多的元素交换操作
// 例子：
// 先排序
// [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]
// 再一个一个插入。
// [7,0]
// [7,0], [7,1]
// [7,0], [6,1], [7,1]
// [5,0], [7,0], [6,1], [7,1]
// [5,0], [7,0], [5,2], [6,1], [7,1]
// [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
// */
// vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
// {
//     std::sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
//         if (a[0] > b[0])
//             return true;
//         if (a[0] == b[0] && a[1] < b[1])
//             return true;
//         return false;
//     });

//     vector<vector<int>> res;
//     for (const auto &e : people)
//         res.insert(res.begin() + e[1], e);

//     return res;
// }

// /*
// 数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。
// 如果满足以下条件，则称子数组(P, Q)为等差数组：
// 元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。
// 函数要返回数组 A 中所有为等差数组的子数组个数。

// 示例:
// A = [1, 2, 3, 4]
// 返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。

// 思路：
// 例子：
// 数列            长度->子数列个数
// 1，2，3            3->1
// 1，2，3，4         4->3
// 1，2，3，4，5      5->6
// 1，2，3，4，5，6   6->10

// 1，...，n         n->(m+1)m/2，m=m-2
// 统计处出每个不相同的最长等差数列的长度，然后按上面的公式计算出每个的结果，最后加起来
// */
// int numberOfArithmeticSlices(const vector<int> &A)
// {
//     int length = A.size();
//     if (length < 3)
//         return 0;

//     int res = 0;
//     int diff = A[1] - A[0]; // 当前等差数列的差
//     int len = 0;            // 当前等差数列的长度
//     for (int i = 2; i < length; i++)
//     {
//         if (A[i] - A[i - 1] == diff)
//             ++len;
//         else
//         {
//             if (len > 0) // 上一个等差数列的最长长度已得到，按公式计算
//                 res += (len * len + len) / 2;

//             diff = A[i] - A[i - 1];
//             len = 0;
//         }
//     }
//     if (len > 0)
//         res += (len * len + len) / 2;

//     return res;
// }
// /*
// 思路：
// 例子：
// 数列            长度->子数列个数   前后差值
// 1，2，3            3->1            0
// 1，2，3，4         4->3            3-1=2
// 1，2，3，4，5      5->6            6-3=3
// 1，2，3，4，5，6   6->10           10-6=4

// 1，...，n         n->(m+1)m/2，m=m-2   m
// 计算每个等差数列过程中，等差数列长度加一，就加上差值（也就是在遍历过程中计算，而不是遍历完后计算）
// */
// int numberOfArithmeticSlices2(const vector<int> &A)
// {
//     int length = A.size();
//     if (length < 3)
//         return 0;

//     int start = 0, res = 0; // 等差数列起始位置，结果
//     for (int i = 2; i < length; i++)
//     {
//         // 在当前等差数列中，长度每增加1，就加上对应差值
//         if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
//             res += i - start - 1;
//         // 新的等差数列，重置起始位置
//         else
//             start = i - 1;
//     }
//     return res;
// }

// /*
// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
// 注意:
// 每个数组中的元素不会超过 100
// 数组的大小不会超过 200

// 示例 1:
// 输入: [1, 5, 11, 5]
// 输出: true
// 解释: 数组可以分割成 [1, 5, 5] 和 [11].

// 示例 2:
// 输入: [1, 2, 3, 5]
// 输出: false
// 解释: 数组不能分割成两个元素和相等的子集.

// 思路：转换成0-1背包问题。dp
// 1）在数组中挑选一个子集，使得子集和为数组和的一半
// 2）dp[i][j]表示在区间[0, i]挑选完i（选或不选）后，子集和是否等于j
// 3）递推关系式：dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
//                             不选i            选i
// */
// bool canPartition(vector<int> &nums)
// {
//     int sum = 0;
//     for (int num : nums)
//         sum += num;
//     if (sum & 1) //奇数不符合条件
//         return false;

//     int half = sum >> 1; // 目标是子集和为总和的一半
//     vector<vector<bool>> dp(nums.size(), vector<bool>(half + 1, false));
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = 0; j <= half; j++)
//         {
//             if (i == 0) // 当i==0时单独处理
//                 dp[i][j] = (nums[i] == j);
//             else // 递推式
//                 dp[i][j] = dp[i - 1][j] || (j - nums[i] >= 0 ? dp[i - 1][j - nums[i]] : false);
//         }
//     }
//     return dp[nums.size() - 1][half];
// }
// // 思路2：dp优化。求解dp第i行dp[i][?]的时候，只需要知道第i-1行dp[i-1][?]的值即可，直接开一个一维数组空间保存前一行的值就ok了
// bool canPartition2(vector<int> &nums)
// {
//     int sum = 0;
//     for (int num : nums)
//         sum += num;
//     if (sum & 1) //奇数不符合条件
//         return false;

//     int half = sum >> 1; // 目标是子集和为总和的一半
//     vector<bool> dp(half + 1, false);
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = half; j >= nums[i]; j--) // 从后往前，因为前面的元素我们已经求过了
//         {
//             if (i == 0)
//                 dp[j] = (nums[i] == j); // i==0要单独求
//             else
//                 dp[j] = dp[j] || dp[j - nums[i]];
//         }
//     }
//     return dp[half];
// }
// // 思路3：递归+剪枝
// bool canPartitionRecursively(int i, int cur, int sum, vector<int> &nums)
// {
//     //i是在上一层中遍历到的位置，在这一层中无需遍历
//     //由于数组已经经过排序，比i大的数都已经在之前的递归中尝试过
//     //所以在当前递归中，只需要遍历比i小的数
//     //cur是从数组中选取的几个数之和，它的值小于sum
//     //在当前层中主要是遍历数组与cur相加，然后根据cur的状态进行不同的操作

//     //这边也是倒序遍历
//     for (int j = i - 1; j >= 0; j--)
//     {
//         //逐步逼近
//         if (cur + nums[j] > sum)
//             continue;
//         if (cur + nums[j] == sum)
//             return true;
//         //递归查找
//         if (canPartitionRecursively(j, cur + nums[j], sum, nums))
//             return true;
//     }
//     return false;
// }
// bool canPartition3(vector<int> &nums)
// {
//     long sum = 0;
//     //计算数组的总数
//     for (int x : nums)
//         sum += x;
//     //总和不能是奇数
//     if (sum % 2)
//         return false;

//     sum /= 2;

//     //排序
//     sort(nums.begin(), nums.end());

//     //如果最大的数大于总和的一半，返回false
//     if (nums.back() > sum)
//         return false;
//     if (nums.back() == sum)
//         return true;

//     //倒序遍历数组
//     for (int i = nums.size() - 1; i >= 0; i--)
//     {
//         //判断当前的数值是否等于sum有意义吗
//         //数组已经排序好了，如果最大的数小于sum
//         //其他的数肯定不用再判断了
//         if (canPartitionRecursively(i, nums[i], sum, nums))
//             return true;
//     }
//     return false;
// }

// /*
// 给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
// 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
// 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
// 提示：
// 输出坐标的顺序不重要
// m 和 n 都小于150

// 示例：
// 给定下面的 5x5 矩阵:
//   太平洋 ~   ~   ~   ~   ~
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * 大西洋
// 返回:
// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).

// 思路：深搜
// 1）建立两个矩阵Atlantic和Pacific, 当Atlantic[i][j]和Pacific[i][j]同时为true时表示该位置可以同时到达Atlantic和Pacific
// 2）便历时的技巧为: 只需要从四个边界开始遍历即可(类似泛洪的思想, 只要可以从边界出发到达, 就说明该位置的水可以流向对应的海洋)
// */
// void pacificAtlanticRecursively(const vector<vector<int>> &m, int row, int col, vector<vector<bool>> &visited, int pre)
// {
//     // 逆向深搜，当前点要高于（大于等于）之前的点
//     if (row < 0 || col < 0 || row >= m.size() || col >= m[0].size() || visited[row][col] || m[row][col] < pre)
//         return;
//     visited[row][col] = true;
//     pacificAtlanticRecursively(m, row + 1, col, visited, m[row][col]);
//     pacificAtlanticRecursively(m, row - 1, col, visited, m[row][col]);
//     pacificAtlanticRecursively(m, row, col + 1, visited, m[row][col]);
//     pacificAtlanticRecursively(m, row, col - 1, visited, m[row][col]);
// }
// vector<vector<int>> pacificAtlantic(const vector<vector<int>> &matrix)
// {
//     vector<vector<int>> res;
//     int m = matrix.size();
//     if (m < 1)
//         return res;
//     int n = matrix[0].size();

//     vector<vector<bool>> Pacific(m, vector<bool>(n, false));
//     vector<vector<bool>> Atlantic(m, vector<bool>(n, false));
//     for (int i = 0; i < m; ++i)
//     {
//         // 左边界（太平洋）
//         pacificAtlanticRecursively(matrix, i, 0, Pacific, matrix[i][0]);
//         // 右边界（大西洋）
//         pacificAtlanticRecursively(matrix, i, n - 1, Atlantic, matrix[i][n - 1]);
//     }
//     for (int i = 0; i < n; ++i)
//     {
//         // 上边界（太平洋）
//         pacificAtlanticRecursively(matrix, 0, i, Pacific, matrix[0][i]);
//         // 下边界（大西洋）
//         pacificAtlanticRecursively(matrix, m - 1, i, Atlantic, matrix[m - 1][i]);
//     }

//     for (int i = 0; i < m; ++i)
//         for (int j = 0; j < n; ++j)
//             if (Pacific[i][j] && Atlantic[i][j]) // 两个都能到达
//                 res.emplace_back(vector<int>{i, j});

//     return res;
// }

// /*
// 给定一个二维的甲板， 请计算其中有多少艘战舰。 战舰用 'X'表示，空位用 '.'表示。 你需要遵守以下规则：
// 给你一个有效的甲板，仅由战舰或者空位组成。
// 战舰只能水平或者垂直放置。换句话说,战舰只能由 1xN (1 行, N 列)组成，或者 Nx1 (N 行, 1 列)组成，其中N可以是任意大小。
// 两艘战舰之间至少有一个水平或垂直的空位分隔 - 即没有相邻的战舰。

// 示例 :
// X..X
// ...X
// ...X
// 在上面的甲板中有2艘战舰。

// 无效样例 :
// ...X
// XXXX
// ...X
// 你不会收到这样的无效甲板 - 因为战舰之间至少会有一个空位将它们分开。

// 进阶:
// 你可以用一次扫描算法，只使用O(1)额外空间，并且不修改甲板的值来解决这个问题吗？

// 思路：
// X..X
// ...X
// ...X
// 左上角的x是一艘战舰，右边的三个x组成另一艘战舰
// 1）将战舰分成两部分，头部和身体
// 2）从左至右，从上到下扫描，最先扫描到的是头部，即它的上边和左边都是空位，进行计数，否则是身体，不计数
// */
// int countBattleships(const vector<vector<char>> &board)
// {
//     if (board.empty() || board[0].empty())
//         return 0;

//     int m = board.size(), n = board[0].size(), res = 0;
//     for (int i = 0; i < m; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             if (board[i][j] == '.') // 空位跳过
//                 continue;
//             // 该位置是战舰的身体，即上边和左边有相连部分
//             if (i > 0 && board[i - 1][j] == 'X' || (j > 0 && board[i][j - 1] == 'X'))
//                 continue;
//             // 该位置是战舰的头部
//             ++res;
//         }
//     }
//     return res;
// }

// /*
// 给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。
// 找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。
// 你能在O(n)的时间解决这个问题吗？

// 示例:
// 输入: [3, 10, 5, 25, 2, 8]
// 输出: 28
// 解释: 最大的结果是 5 ^ 25 = 28.

// 思路：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/solution/li-yong-yi-huo-yun-suan-de-xing-zhi-tan-xin-suan-f
// */
// int findMaximumXOR(vector<int> &nums)
// {
//     int mask = 0;
//     int res = 0;
//     for (int i = 30; i >= 0; i--)
//     {
//         mask = mask | (1 << i); // 获取前缀的掩码

//         unordered_set<int> prefixes;
//         for (auto num : nums) // 获取所有数的前缀，存入哈希表
//             prefixes.insert(num & mask);

//         int temp = res | (1 << i); // 假设当前位为1
//         for (auto prefix : prefixes) // 当前位能否为1？
//         {
//             if (prefixes.find(prefix ^ temp) != prefixes.end()) // 异或后能在哈希表中，当前位能为1
//             {
//                 res = temp;
//                 break;
//             }
//         }
//     }
//     return res;
// }

// /*
// 给定一个非空字符串，其中包含字母顺序打乱的英文单词表示的数字0-9。按升序输出原始的数字。
// 注意:
// 输入只包含小写英文字母。
// 输入保证合法并可以转换为原始的数字，这意味着像 "abc" 或 "zerone" 的输入是不允许的。
// 输入字符串的长度小于 50,000

// 示例 1:
// 输入: "owoztneoer"
// 输出: "012" (zeroonetwo)

// 示例 2:
// 输入: "fviefuro"
// 输出: "45" (fourfive)

// 思路：递归深搜（超时）
// */
// bool originalDigitsRecursively(vector<int> cnts, const vector<string> &nums, int num, string &res)
// {
//     bool all_used = true;
//     for (int cnt : cnts)
//         if (cnt > 0)
//             all_used = false;
//     if (all_used)
//         return true;

//     for (; num <= 9; ++num)
//     {
//         int i = 0;
//         for (i = 0; i < nums[num].size(); i++)
//         {
//             if (cnts[nums[num][i] - 'a'] > 0)
//                 --cnts[nums[num][i] - 'a'];
//             else
//                 break;
//         }
//         if (i < nums[num].size())
//         {
//             for (i = i - 1; i >= 0; --i)
//                 ++cnts[nums[num][i] - 'a'];
//             continue;
//         }
//         res.push_back(num + '0');
//         if (originalDigitsRecursively(cnts, nums, num, res))
//             return true;
//         res.pop_back();
//         for (i = 0; i < nums[num].size(); i++)
//             ++cnts[nums[num][i] - 'a'];
//     }
//     return false;
// }
// string originalDigits(const string &s)
// {
//     if (s.empty())
//         return {};

//     vector<int> chr_cnt_map(26, 0);
//     for (char c : s)
//         ++chr_cnt_map[c - 'a'];

//     vector<string> num_set{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
//     string res;
//     originalDigitsRecursively(chr_cnt_map, num_set, 0, res);
//     return res;
// }
// // 思路2：找出每个单词的特征字符，然后按特征字符得出对应的数字
// string originalDigits2(const string &s)
// {
//     // building hashmap letter -> its frequency
//     int cnts[26] = {0};
//     for (char letter : s)
//         ++cnts[letter - 'a'];

//     // building hashmap digit -> its frequency
//     int out[10] = {0};
//     // letter "z" is present only in "zero"
//     out[0] = cnts['z' - 'a'];
//     // letter "w" is present only in "two"
//     out[2] = cnts['w' - 'a'];
//     // letter "u" is present only in "four"
//     out[4] = cnts['u' - 'a'];
//     // letter "x" is present only in "six"
//     out[6] = cnts['x' - 'a'];
//     // letter "g" is present only in "eight"
//     out[8] = cnts['g' - 'a'];
//     // letter "h" is present only in "three" and "eight"
//     out[3] = cnts['h' - 'a'] - out[8];
//     // letter "f" is present only in "five" and "four"
//     out[5] = cnts['f' - 'a'] - out[4];
//     // letter "s" is present only in "seven" and "six"
//     out[7] = cnts['s' - 'a'] - out[6];
//     // letter "i" is present in "nine", "five", "six", and "eight"
//     out[9] = cnts['i' - 'a'] - out[5] - out[6] - out[8];
//     // letter "n" is present in "one", "nine", and "seven"
//     out[1] = cnts['n' - 'a'] - out[7] - 2 * out[9];

//     // building output string
//     string res;
//     for (int i = 0; i < 10; i++)
//         for (int j = 0; j < out[i]; j++)
//             res.push_back(i + '0');

//     return res;
// }

// /*
// 给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。
// 注意:
// 字符串长度 和 k 不会超过 104。

// 示例 1:
// 输入:
// s = "ABAB", k = 2
// 输出:
// 4
// 解释:
// 用两个'A'替换为两个'B',反之亦然。

// 示例 2:
// 输入:
// s = "AABABBA", k = 1
// 输出:
// 4
// 解释:
// 将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
// 子串 "BBBB" 有最长重复字母, 答案为 4。

// 思路：滑动窗口，双指针
// 1）假设窗口长度为len，窗口中个数最多的字符的个数为max_count，那么len-max_count如果刚好等于k，就刚好可以全部替换
// 2）也就是说，左指针向右滑动的条件是len-max_count>k
// 3）这里有个优化，不需要每次都去重新更新max_count
//     比如说"AAABCDEDFG" k=2，这个case，一开始A出现3次,max_count=3，但是当指针移到D时发现不行了，要移动left指针了。
//     此时count['A']-=1，但是不需要把max_count更新为2。为什么呢？
//     因为根据我们的算法，当max_count和k一定时，区间最大长度也就定了。
//     当我们找到一个max_count之后，我们就能说我们找到了一个长度为d=max_count+k的合法区间，所以最终答案一定不小于d。
//     所以，当发现继续向右扩展right不合法的时候，我们不需要不断地右移left，只需要保持区间长度为d向右滑动即可。
//     如果有某个合法区间大于d，一定在某个时刻存在count[t]+1>max_count，这时再去更新max_count即可。
// */
// int characterReplacement(string s, int k)
// {
//     int max_count = 0, l = 0, r;
//     vector<int> count(128, 0);
//     for (r = 0; r < s.size(); r++)
//     {
//         max_count = std::max(max_count, ++count[s[r]]);
//         if (r - l + 1 - max_count > k)
//             count[s[l++]]--;
//     }
//     return r - l;
// }

// /*
// 我们想要使用一棵四叉树来储存一个 N x N 的布尔值网络。
// 网络中每一格的值只会是真或假。树的根结点代表整个网络。
// 对于每个结点, 它将被分等成四个孩子结点直到这个区域内的值都是相同的.
// 每个结点还有另外两个布尔变量: isLeaf 和 val。isLeaf 当这个节点是一个叶子结点时为真。val 变量储存叶子结点所代表的区域的值。
// 你的任务是使用一个四叉树表示给定的网络。

// 提示：
// N 将小于 1000 且确保是 2 的整次幂。
// 如果你想了解更多关于四叉树的知识，你可以参考这个 https://en.wikipedia.org/wiki/Quadtree 页面。
// */
// Node *constructRecursively(vector<vector<int>> &grid, int x, int y, int n)
// {
//     for (int i = x; i < x + n; i++)
//         for (int j = y; j < y + n; j++)
//             if (grid[i][j] != grid[x][y])
//             {
//                 //发现正方形区域内的值存在不同，说明不是叶节点，调用递归得到子节点
//                 Node *root = new Node(true, false, nullptr, nullptr, nullptr, nullptr);
//                 root->topLeft = constructRecursively(grid, x, y, n / 2);
//                 root->topRight = constructRecursively(grid, x, y + n / 2, n / 2);
//                 root->bottomLeft = constructRecursively(grid, x + n / 2, y, n / 2);
//                 root->bottomRight = constructRecursively(grid, x + n / 2, y + n / 2, n / 2);
//                 return root;
//             }

//     return new Node(grid[x][y] != 0, true, nullptr, nullptr, nullptr, nullptr);
// }
// Node *construct(vector<vector<int>> &grid)
// {
//     if (grid.size() == 0)
//         return nullptr;
//     return constructRecursively(grid, 0, 0, grid.size());
// }

// /*
// 您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。
// 这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。
// 扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。

// 示例:
// 输入:
//  1---2---3---4---5---6--NULL
//          |
//          7---8---9---10--NULL
//              |
//              11--12--NULL
// 输出:
// 1-2-3-7-8-11-12-9-10-4-5-6-NULL

// 思路：递归深搜
// */
// Node *flattenRecursively(Node *p) // 返回p为头的链表的最后一个节点
// {
//     Node *pre = p, *nxt = p->next;
//     while (p != nullptr) // 遍历链表
//     {
//         if (p->child != nullptr) // 找到具有子链的节点
//         {
//             nxt = p->next; // 记录下一个节点

//             Node *last = flattenRecursively(p->child); // 递归

//             // 将递归返回的子链拼接到本链
//             p->next = p->child;
//             p->child->prev = p;
//             p->child = nullptr;
//             last->next = nxt;
//             if (nxt != nullptr) // 拼接子链在本链中间（不是最后）
//                 nxt->prev = last;
//             else // 本链的最后一个节点是拼接子链后的最后一个节点
//                 return last;
//         }
//         else
//             nxt = p->next;
//         pre = p;
//         p = nxt;
//     }
//     return pre;
// }
// Node *flatten(Node *head)
// {
//     if (head == nullptr)
//         return head;

//     Node *p = head, *nxt = p->next;
//     while (p != nullptr)
//     {
//         if (p->child != nullptr)
//         {
//             nxt = p->next;
//             Node *last = flattenRecursively(p->child);
//             p->next = p->child;
//             p->child->prev = p;
//             p->child = nullptr;
//             last->next = nxt;
//             if (nxt != nullptr)
//                 nxt->prev = last;
//         }
//         else
//             nxt = p->next;
//         p = nxt;
//     }
//     return head;
// }
// // 思路2：看成一棵二叉树。左子树是child，右子树是next，并且有指向父节点的指针prev。先根遍历
// void flattenRecursively2(Node *p, Node *&pre_node)
// {
//     pre_node->next = p;
//     p->prev = pre_node;
//     pre_node = p;

//     Node *child = p->child;
//     p->child = nullptr;
//     Node *next = p->next;

//     if (child != nullptr)
//         flattenRecursively2(child, pre_node);
//     if (next != nullptr)
//         flattenRecursively2(next, pre_node);
// }
// Node *flatten2(Node *head)
// {
//     if (head == nullptr)
//         return nullptr;

//     Node *dummy = new Node();
//     Node *&pre_node = dummy;
//     flattenRecursively2(head, pre_node);
//     pre_node->next = nullptr;
//     delete head->prev;
//     head->prev = nullptr;
//     return head;
// }

// /*
// 一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。
// 假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。
// 例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。
// 与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
// 现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。
// 如果无法实现目标变化，请返回 -1。

// 注意:
// 起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
// 所有的目标基因序列必须是合法的。
// 假定起始基因序列与目标基因序列是不一样的。

// 示例 1:
// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]
// 返回值: 1

// 示例 2:
// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
// 返回值: 2

// 示例 3:
// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
// 返回值: 3

// 思路：
// 1）广度优先搜索
// 2）将开始字符串加入开始集合
// 3）针对开始集合中每一个字符串，更改该字符串中每一个字符，并检查更改是否合法，如果合法，加入中间集合
// 4）用中间集合替换掉开始集合，这就完成了一次转换
// 5）不断重复直至找到结束字符串
// */
// int minMutation(string start, string end, vector<string> &bank)
// {
//     if (bank.empty())
//         return -1;

//     // 建立哈希表
//     unordered_set<string> dict(bank.begin(), bank.end());
//     if (dict.count(end) == 0)
//         return -1;
//     if (start == end)
//         return 0;
//     // 基因中每一位可能的值，用来进行变异
//     vector<char> GENE({'A', 'T', 'C', 'G'});
//     // 已经访问过的基因
//     unordered_set<string> visited;
//     // 队列模拟广度优先搜索
//     queue<string> Q;

//     int res = 0;

//     // 开始基因加入开始集合
//     Q.push(start);
//     visited.insert(start);

//     while (!Q.empty())
//     {
//         int size = Q.size();
//         while (size--) // 对开始集合中的每一个基因
//         {
//             auto curword(std::move(Q.front()));
//             Q.pop();
//             for (int i = 0; i < 8; ++i) // 对每一个基因的每一位
//             {
//                 string tmp(curword);
//                 char origin = tmp[i];
//                 for (auto j : GENE) // 更改该位（即进行一次变异）
//                 {
//                     if (origin == j)
//                         continue;

//                     tmp[i] = j;

//                     if (tmp == end) // 变异后得到目标基因，返回结果
//                         return res + 1;

//                     // 变异后的基因不合法（不在基因库或者已经访问过），跳过
//                     if (dict.count(tmp) == 0 || visited.count(tmp) > 0)
//                         continue;

//                     // 加入队列，即完成一次合法变异
//                     visited.insert(tmp);
//                     Q.push(tmp);
//                 }
//             }
//         }
//         ++res;
//     }
//     return -1;
// }

// /*
// 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
// 注意:
// 可以认为区间的终点总是大于它的起点。
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

// 示例 1:
// 输入: [ [1,2], [2,3], [3,4], [1,3] ]
// 输出: 1
// 解释: 移除 [1,3] 后，剩下的区间没有重叠。

// 示例 2:
// 输入: [ [1,2], [1,2], [1,2] ]
// 输出: 2
// 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

// 示例 3:
// 输入: [ [1,2], [2,3] ]
// 输出: 0
// 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

// 思路：贪心算法（https://leetcode-cn.com/problems/non-overlapping-intervals/solution/tan-xin-suan-fa-zhi-qu-jian-diao-du-wen-ti-by-labu）
// 1）从区间集合 intvs 中选择一个区间 x，这个 x 是在当前所有区间中结束最早的（end 最小）。
// 2）把所有与 x 区间相交的区间从区间集合 intvs 中删除。
// 3）重复步骤 1 和 2，直到 intvs 为空为止。之前选出的那些 x 就是最大不相交子集。
// */
// int eraseOverlapIntervals(vector<vector<int>> &intervals)
// {
//     int length = intervals.size();
//     if (length == 0)
//         return 0;

//     // 按结束端点升序排序
//     std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
//         return a[1] < b[1];
//     });

//     int not_overlap_cnt = 1;       // 不重叠的区间数量
//     int pre_end = intervals[0][1]; // 不重叠区间中上一个区间的结束端点
//     for (int i = 1; i < length; i++)
//     {
//         // 当前区间的起始端点不小于上一个区间的结束端点，说明当前区间可以加入不重叠区间中
//         if (intervals[i][0] >= pre_end)
//         {
//             pre_end = intervals[i][1];
//             ++not_overlap_cnt;
//         }
//     }

//     // 返回需要移除的区间数
//     return length - not_overlap_cnt;
// }

// /*
// 给定一组区间，对于每一个区间 i，检查是否存在一个区间 j，它的起始点大于或等于区间 i 的终点，这可以称为 j 在 i 的“右侧”。
// 对于任何区间，你需要存储的满足条件的区间 j 的最小索引，这意味着区间 j 有最小的起始点可以使其成为“右侧”区间。如果区间 j 不存在，则将区间 i 存储为 -1。最后，你需要输出一个值为存储的区间值的数组。
// 注意:
// 你可以假设区间的终点总是大于它的起始点。
// 你可以假定这些区间都不具有相同的起始点。

// 示例 1:
// 输入: [ [1,2] ]
// 输出: [-1]
// 解释:集合中只有一个区间，所以输出-1。

// 示例 2:
// 输入: [ [3,4], [2,3], [1,2] ]
// 输出: [-1, 0, 1]
// 解释:对于[3,4]，没有满足条件的“右侧”区间。
// 对于[2,3]，区间[3,4]具有最小的“右”起点;
// 对于[1,2]，区间[2,3]具有最小的“右”起点。

// 示例 3:
// 输入: [ [1,4], [2,3], [3,4] ]
// 输出: [-1, 2, -1]
// 解释:对于区间[1,4]和[3,4]，没有满足条件的“右侧”区间。
// 对于[2,3]，区间[3,4]有最小的“右”起点。

// 思路：按区间起点升序排序，排序时保留下标，然后遍历即可（虽然未超时，但是运行时间很长）
// */
// vector<int> findRightInterval(vector<vector<int>> &intervals)
// {
//     int length = intervals.size();
//     if (length == 0)
//         return {};
//     if (length == 1)
//         return {-1};

//     // 保留下标
//     vector<pair<vector<int> *, int>> intvl_idx;
//     intvl_idx.reserve(length);
//     for (int i = 0; i < length; i++)
//         intvl_idx.push_back({&intervals[i], i});

//     // 按区间的起点升序排序
//     std::sort(intvl_idx.begin(), intvl_idx.end(), [](const pair<vector<int> *, int> &a, const pair<vector<int> *, int> &b) {
//         return (*(a.first))[0] < (*(b.first))[0];
//     });

//     // 对于当前区间，向右搜索满足条件的区间即可
//     vector<int> res(length, -1);
//     for (int i = 0; i < length; i++)
//     {
//         int end = (*(intvl_idx[i].first))[1];
//         for (int j = i + 1; j < length; j++)
//         {
//             if ((*(intvl_idx[j].first))[0] >= end)
//             {
//                 res[intvl_idx[i].second] = intvl_idx[j].second;
//                 break;
//             }
//         }
//     }
//     return res;
// }
// // 思路2：同上。对原来每个区间，在排序后的区间中二分查找
// vector<int> findRightInterval2(vector<vector<int>> &intervals)
// {
//     int length = intervals.size();
//     if (length == 0)
//         return {};
//     if (length == 1)
//         return {-1};

//     // 保留下标
//     vector<pair<vector<int> *, int>> intvl_idx;
//     intvl_idx.reserve(length);
//     for (int i = 0; i < length; i++)
//         intvl_idx.push_back({&intervals[i], i});

//     // 按区间的起点升序排序
//     std::sort(intvl_idx.begin(), intvl_idx.end(), [](const pair<vector<int> *, int> &a, const pair<vector<int> *, int> &b) {
//         return (*(a.first))[0] < (*(b.first))[0];
//     });

//     vector<int> res;
//     res.reserve(length);
//     for (int i = 0; i < length; i++)
//     {
//         int end = intervals[i][1];
//         // 二分查找起点大于当前终点的区间
//         auto iter = std::lower_bound(intvl_idx.begin(), intvl_idx.end(), end, [](const pair<vector<int> *, int> &a, int end) {
//             return (*(a.first))[0] < end;
//         });
//         if (iter == intvl_idx.end())
//             res.push_back(-1);
//         else
//             res.push_back((*iter).second);
//     }

//     return res;
// }
// // 思路3：同上。对排序后的区间，向右二分搜索
// vector<int> findRightInterval3(vector<vector<int>> &intervals)
// {
//     int length = intervals.size();
//     if (length == 0)
//         return {};
//     if (length == 1)
//         return {-1};

//     // 保留下标
//     vector<pair<vector<int> *, int>> intvl_idx;
//     intvl_idx.reserve(length);
//     for (int i = 0; i < length; i++)
//         intvl_idx.push_back({&intervals[i], i});

//     // 按区间的起点升序排序
//     std::sort(intvl_idx.begin(), intvl_idx.end(), [](const pair<vector<int> *, int> &a, const pair<vector<int> *, int> &b) {
//         return (*(a.first))[0] < (*(b.first))[0];
//     });

//     // 对于当前区间，向右二分搜索满足条件的区间即可
//     vector<int> res(length, -1);
//     for (int i = 0; i < length; i++)
//     {
//         int end = (*(intvl_idx[i].first))[1];
//         auto iter = std::lower_bound(intvl_idx.begin() + i + 1, intvl_idx.end(), end, [](const pair<vector<int> *, int> &a, int end) {
//             return (*(a.first))[0] < end;
//         });
//         if (iter != intvl_idx.end())
//             res[intvl_idx[i].second] = (*iter).second;
//     }
//     return res;
// }

// /*
// 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
// 找到所有出现两次的元素。
// 你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

// 示例：
// 输入:
// [4,3,2,7,8,2,3,1]
// 输出:
// [2,3]

// 思路：归位法，将对应数归位到对应下标
// */
// vector<int> findDuplicates(vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 2)
//         return {};

//     vector<int> res;
//     for (int i = 0; i < length; i++)
//     {
//         // 当前数等于当前下标，不用处理
//         if (nums[i] == i + 1 || nums[i] == -1)
//             continue;
//         else
//         {
//             // 进行归位操作
//             while (nums[i] != i + 1 && nums[i] != -1)
//             {
//                 // 发现重复
//                 if (nums[i] == nums[nums[i] - 1])
//                 {
//                     res.push_back(nums[i]);
//                     nums[i] = -1; // 用特殊值取代重复的数字，重复的数字只保留一个
//                     break;
//                 }
//                 using std::swap;
//                 swap(nums[i], nums[nums[i] - 1]);
//             }
//         }
//     }
//     return res;
// }
// // 思路2：同样是归位，但是只是标记一下，并不实际操作
// vector<int> findDuplicates2(vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 2)
//         return {};

//     vector<int> res;
//     for (int i = 0; i < length; i++)
//     {
//         // 如果当前数对应下标的数为负数，代表之前已经有数归位到该下标归位了，即发生了重复
//         if (nums[std::abs(nums[i]) - 1] < 0)
//             res.push_back(std::abs(nums[i]));

//         // 当前数应该放到对应下标处，但是不实际交换，只是将对应下标的数标记为负数，代表已经归位了
//         nums[std::abs(nums[i]) - 1] = -std::abs(nums[std::abs(nums[i]) - 1]);
//     }
//     return res;
// }

// /*
// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
// 一般来说，删除节点可分为两个步骤：
// 首先找到需要删除的节点；
// 如果找到了，删除它。
// 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

// 示例:
// root = [5,3,6,2,4,null,7]
// key = 3

//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
// 给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
// 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

//     5
//    / \
//   4   6
//  /     \
// 2       7
// 另一个正确答案是 [5,2,6,null,4,null,7]。

//     5
//    / \
//   2   6
//    \   \
//     4   7
// */
// TreeNode *deleteNode(TreeNode *root, int key)
// {
//     if (root == nullptr)
//         return nullptr;

//     // 找节点，并保存节点在它的父节点的位置
//     TreeNode *p = root, **pp = nullptr;
//     while (p != nullptr)
//     {
//         if (p->val == key)
//             break;
//         else if (p->val < key)
//         {
//             pp = &(p->right);
//             p = p->right;
//         }
//         else
//         {
//             pp = &(p->left);
//             p = p->left;
//         }
//     }

//     // 未找到
//     if (p == nullptr)
//         return root;

//     TreeNode *left = p->left, *right = p->right;
//     delete p; // 删除节点

//     TreeNode *res;
//     if (left == nullptr) // 节点的左子树为空
//     {
//         if (pp != nullptr) // 有父节点，将右子树挂到父节点上
//         {
//             *pp = right;
//             res = root;
//         }
//         else // 无父节点，返回右子树
//             res = right;
//     }
//     else // 节点的左子树不为空
//     {
//         // 寻找左子树的最右节点，将节点的右子树挂在最右节点的右边
//         TreeNode *t = left;
//         while (t->right != nullptr)
//             t = t->right;
//         t->right = right;

//         if (pp != nullptr) // 有父节点，将左子树挂到父节点上
//         {
//             *pp = left;
//             res = root;
//         }
//         else // 无父节点，返回左子树
//             res = left;
//     }
//     return res;
// }

// /*
// 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

// 示例 1:
// 输入:
// "tree"
// 输出:
// "eert"
// 解释:
// 'e'出现两次，'r'和't'都只出现一次。
// 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。

// 示例 2:
// 输入:
// "cccaaa"
// 输出:
// "cccaaa"
// 解释:
// 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
// 注意"cacaca"是不正确的，因为相同的字母必须放在一起。

// 示例 3:
// 输入:
// "Aabb"
// 输出:
// "bbAa"
// 解释:
// 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
// 注意'A'和'a'被认为是两种不同的字符。
// */
// string frequencySort(const string &s)
// {
//     if (s.empty())
//         return {};

//     // 统计频率
//     unordered_map<char, int> chr_cnt_map;
//     for (char c : s)
//         ++chr_cnt_map[c];

//     // 按频率排序
//     vector<pair<int, char>> cnt_chr_vec;
//     cnt_chr_vec.reserve(chr_cnt_map.size());
//     for (const auto &kv : chr_cnt_map)
//         cnt_chr_vec.emplace_back(make_pair(kv.second, kv.first));
//     std::sort(cnt_chr_vec.begin(), cnt_chr_vec.end(), [](const pair<int, char> &a, const pair<int, char> &b) {
//         return a.first > b.first;
//     });

//     // 生成结果
//     ostringstream oss;
//     for (const auto &p : cnt_chr_vec)
//         oss << string(p.first, p.second);

//     return oss.str();
// }

// /*
// 在二维空间中有许多球形的气球。
// 对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
// 由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。
// 开始坐标总是小于结束坐标。平面内最多存在10^4个气球。
// 一支弓箭可以沿着x轴从不同点完全垂直地射出。
// 在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。
// 可以射出的弓箭的数量没有限制。
// 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

// Example:
// 输入:
// [[10,16], [2,8], [1,6], [7,12]]
// 输出:
// 2
// 解释:
// 对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。

// 思路：统计非重叠区间的个数
// */
// int findMinArrowShots(vector<vector<int>> &points)
// {
//     int length = points.size();
//     if (length == 0)
//         return 0;

//     std::sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
//         return a[1] < b[1];
//     });

//     int res = 1;
//     int pre_end = points[0][1];
//     for (int i = 1; i < length; i++)
//     {
//         if (points[i][0] > pre_end)
//         {
//             ++res;
//             pre_end = points[i][1];
//         }
//     }

//     return res;
// }

// /*
// 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

// 例如:
// 输入:
// A = [ 1, 2]
// B = [-2,-1]
// C = [-1, 2]
// D = [ 0, 2]
// 输出:
// 2
// 解释:
// 两个元组如下:
// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

// 思路：暴力法（超时）
// */
// int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
// {
//     int length = A.size();
//     if (length == 0)
//         return 0;

//     std::sort(A.begin(), A.end());
//     std::sort(B.begin(), B.end());
//     std::sort(C.begin(), C.end());
//     std::sort(D.begin(), D.end());

//     int res = 0;
//     for (int i = 0; i < length; i++)
//     {
//         int ti = 0 - A[i];
//         for (int j = 0; j < length; j++)
//         {
//             int tj = ti - B[j];
//             for (int k = 0; k < length; k++)
//             {
//                 int tk = tj - C[k];
//                 auto iters = std::equal_range(D.begin(), D.end(), tk);
//                 res += iters.second - iters.first;
//             }
//         }
//     }
//     return res;
// }
// /*
// 思路2：利用哈希表加速
// */
// int fourSumCount2(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
// {
//     int res = 0;
//     unordered_map<int, int> map;

//     for (const auto &a : A)
//         for (const auto &b : B)
//             ++map[a + b];

//     for (const auto &c : C)
//     {
//         for (const auto &d : D)
//         {
//             int t = -(c + d);
//             if (map.count(t) != 0)
//                 res += map[t];
//         }
//     }

//     return res;
// }

// /*
// 给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。
// 设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。
// 注意：n 的值小于15000。

// 示例1:
// 输入: [1, 2, 3, 4]
// 输出: False
// 解释: 序列中不存在132模式的子序列。

// 示例 2:
// 输入: [3, 1, 4, 2]
// 输出: True
// 解释: 序列中有 1 个132模式的子序列： [1, 4, 2].

// 示例 3:
// 输入: [-1, 3, 2, 0]
// 输出: True
// 解释: 序列中有 3 个132模式的的子序列: [-1, 3, 2], [-1, 3, 0] 和 [-1, 2, 0].

// 思路：单调栈（https://www.jianshu.com/p/43bb5204bc6f）（https://blog.csdn.net/Prasnip_/article/details/83690038）
// 1）从右往左扫描，记录最大值aj以及次大值ak
// 2）扫描过程中，对于当前ai，如果ai<ak，返回true，否则更新aj和ak
// */
// bool find132pattern(const vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 3)
//         return false;

//     stack<int> aj;    // 记录从右往左扫描过程中的最大值
//     int ak = INT_MIN; // 记录用更大的值更新aj时的次大值
//     for (int i = length - 1; i >= 0; i--)
//     {
//         int ai = nums[i];
//         if (ai < ak) // ak是次大值，如果ai<ak，说明找到
//             return true;

//         // 否则，用ai更新aj和ak
//         while (!aj.empty() && ai > aj.top())
//         {
//             ak = aj.top();
//             aj.pop();
//         }
//         aj.push(nums[i]);
//     }
//     return false;
// }

// /*
// 给定一个含有正整数和负整数的环形数组 nums。
// 如果某个索引中的数 k 为正数，则向前移动 k 个索引。
// 相反，如果是负数 (-k)，则向后移动 k 个索引。
// 因为数组是环形的，所以可以假设最后一个元素的下一个元素是第一个元素，而第一个元素的前一个元素是最后一个元素。
// 确定 nums 中是否存在循环（或周期）。
// 循环必须在相同的索引处开始和结束并且循环长度 > 1。
// 此外，一个循环中的所有运动都必须沿着同一方向进行。
// 换句话说，一个循环中不能同时包括向前的运动和向后的运动。

// 示例 1：
// 输入：[2,-1,1,2,2]
// 输出：true
// 解释：存在循环，按索引 0 -> 2 -> 3 -> 0 。循环长度为 3 。

// 示例 2：
// 输入：[-1,2]
// 输出：false
// 解释：按索引 1 -> 1 -> 1 ... 的运动无法构成循环，因为循环的长度为 1 。根据定义，循环的长度必须大于 1 。

// 示例 3:
// 输入：[-2,1,-1,-2,-2]
// 输出：false
// 解释：按索引 1 -> 2 -> 1 -> ... 的运动无法构成循环，因为按索引 1 -> 2 的运动是向前的运动，而按索引 2 -> 1 的运动是向后的运动。
// 一个循环中的所有运动都必须沿着同一方向进行。

// 提示：
// -1000 ≤ nums[i] ≤ 1000
// nums[i] ≠ 0
// 1 ≤ nums.length ≤ 5000

// 进阶：
// 你能写出时间时间复杂度为 O(n) 和额外空间复杂度为 O(1) 的算法吗？

// 思路：模拟法。遍历所有可能情况（https://www.cnblogs.com/grandyang/p/7658128.html）
// */
// bool circularArrayLoop(const vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 2)
//         return false;

//     vector<int> visit(length, 0); // 是否遍历标识
//     int color = 1;                // 对于每一次遍历，着一种颜色
//     for (int i = 0; i < length; i++)
//     {
//         if (visit[i] == 0) // 未着色
//         {
//             int j = i;
//             // 遍历着色
//             while (visit[j] == 0 && nums[j] * nums[i] > 0)
//             {
//                 visit[j] = color;
//                 j = ((j + nums[j]) % length + length) % length;
//             }
//             // 着的是同一种颜色并且循环长度大于1，返回true
//             if (visit[j] == color && ((j + nums[j]) % length + length) % length != j)
//                 return true;
//         }
//         color++; // 换一种颜色
//     }
//     return false;
// }

// /*
// 给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。 您可以假设数组的长度最多为10000。

// 例如:
// 输入:
// [1,2,3]
// 输出:
// 2
// 说明：
// 只有两个动作是必要的（记得每一步仅可使其中一个元素加1或减1）：
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]

// 思路：找中位数。所有数往总位数靠能够得到最小的移动数量
// */
// int minMoves2(vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 2)
//         return 0;

//     nth_element(nums.begin(), nums.begin() + length / 2, nums.end());
//     int mid = nums[length / 2];
//     int res = 0;
//     for (int num : nums)
//         res += std::abs(num - mid);
//     return res;
// }

// /*
// 在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到 100 的玩家，即为胜者。
// 如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？
// 例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。
// 给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？
// 你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。

// 示例：
// 输入：
// maxChoosableInteger = 10
// desiredTotal = 11
// 输出：
// false
// 解释：
// 无论第一个玩家选择哪个整数，他都会失败。
// 第一个玩家可以选择从 1 到 10 的整数。
// 如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
// 第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
// 同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。

// 思路：记忆化搜索
// */
// bool canWin(int length, int nowTarget, int used, unordered_map<int, bool> &myMap)
// {
//     //由于maxChoosableInteger 不会大于 20，所以可以使用一个int型的各个位标记是否使用
//     //myMap[used]用于标记在使用used（二进制各个位真值代表某个元素是否已经使用，比如used = “1101”代表使用了1，3，4）情况本次挑选是否能赢

//     if (myMap.count(used)) //如果之前搜索过
//         return myMap[used];

//     //穷举当前可选的元素
//     for (int i = 0; i < length; ++i)
//     {
//         int cur = (1 << i);    //第i位表示选择[1,2,3, maxChoosableInteger]选择i + 1这个值
//         if ((cur & used) == 0) //这个值没有使用过
//         {
//             //nowTarget <= i + 1是代表已经达到预期值
//             //nowTarget - (i + 1)表示选择了i + 1
//             //cur | used 代表使用i + 1，将used的第i位（从第到高）标记为1
//             //!canWin(length, total - (i + 1), cur | used, myMap)表示的是对方选择输了
//             if (nowTarget <= i + 1 || !canWin(length, nowTarget - (i + 1), cur | used, myMap))
//             {
//                 myMap[used] = true;
//                 return true;
//             }
//         }
//     }
//     myMap[used] = false;
//     return false;
// }
// bool canIWin(int maxChoosableInteger, int desiredTotal)
// {
//     //第一种特殊情况，第一个人选一次即可到达预期值
//     if (maxChoosableInteger >= desiredTotal)
//         return true;
//     //第二种特殊情况，所有元素的和都小于预期值，则永远无法赢
//     if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
//         return false;

//     unordered_map<int, bool> myMap;
//     return canWin(maxChoosableInteger, desiredTotal, 0, myMap);
// }

// /*
// 把字符串 s 看作是“abcdefghijklmnopqrstuvwxyz”的无限环绕字符串，
// 所以 s 看起来是这样的："...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....". 
// 现在我们有了另一个字符串 p 。
// 你需要的是找出 s 中有多少个唯一的 p 的非空子串，尤其是当你的输入是字符串 p ，你需要输出字符串 s 中 p 的不同的非空子串的数目。 
// 注意: p 仅由小写的英文字母组成，p 的大小可能超过 10000。

// 示例 1:
// 输入: "a"
// 输出: 1
// 解释: 字符串 S 中只有一个"a"子字符。

// 示例 2:
// 输入: "cac"
// 输出: 2
// 解释: 字符串 S 中的字符串“cac”只有两个子串“a”、“c”。.

// 示例 3:
// 输入: "zab"
// 输出: 6
// 解释: 在字符串 S 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。.

// 思路：
// 1）统计的是 字符串中连续子字符串 中的 连续子串数目，注意...za...也是连续的
// 2）注意到字符串中一个连续子串可能包含另一个连续子串
//     比如abcdcd，子串abcd包含了后面的子串cd，统计abcd的连续子串数目时，也间接统计了cd的数目
// 3）为了解决上面的问题，使用结尾字符和连续子串的长度来标定一个连续子串
//     比如abcdcd的连续子串abcd用dp['d']=4来标记，另一个子串cd用dp['d']=2来标记，最后dp['d']=max(4,2)=4
// 4）最后累加dp即可
// */
// int findSubstringInWraproundString(const string &p)
// {
//     if (p.empty())
//         return 0;

//     int n = p.size();
//     vector<int> dp(26, 0);
//     int len = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (i > 0 && (p[i] - p[i - 1] == 1 || p[i] - p[i - 1] == -25))
//             ++len;
//         else
//             len = 1;
//         dp[p[i] - 'a'] = std::max(dp[p[i] - 'a'], len);
//     }
//     return accumulate(dp.begin(), dp.end(), 0);
// }

// /*
// 编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址。
// IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；
// 同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。
// IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。
// 比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。
// 而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。
// 所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。
// 然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。
// 同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。
// 说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。

// 示例 1:
// 输入: "172.16.254.1"
// 输出: "IPv4"
// 解释: 这是一个有效的 IPv4 地址, 所以返回 "IPv4"。

// 示例 2:
// 输入: "2001:0db8:85a3:0:0:8A2E:0370:7334"
// 输出: "IPv6"
// 解释: 这是一个有效的 IPv6 地址, 所以返回 "IPv6"。

// 示例 3:
// 输入: "256.256.256.256"
// 输出: "Neither"
// 解释: 这个地址既不是 IPv4 也不是 IPv6 地址。
// */
// string validIPAddress(const string &IP)
// {
//     int length = IP.size();
//     if (length < 7 || length > 39)
//         return "Neither";
//     if (IP.front() == '.' || IP.front() == ':' || IP.back() == '.' || IP.back() == ':')
//         return "Neither";

//     vector<string> strs;
//     bool is4 = false, is6 = false;
//     int start = 0, idx = 0;
//     while (idx < length)
//     {
//         if (is4)
//         {
//             while (idx < length && IP[idx] != '.' && IP[idx] != ':')
//                 ++idx;
//             if (idx < length)
//                 if (IP[idx] == ':')
//                     return "Neither";
//             strs.emplace_back(IP.substr(start, idx - start));
//             ++idx;
//             start = idx;
//         }
//         else if (is6)
//         {
//             while (idx < length && IP[idx] != '.' && IP[idx] != ':')
//                 ++idx;
//             if (idx < length)
//                 if (IP[idx] == '.')
//                     return "Neither";
//             strs.emplace_back(IP.substr(start, idx - start));
//             ++idx;
//             start = idx;
//         }
//         else
//         {
//             while (idx < length && IP[idx] != '.' && IP[idx] != ':')
//                 ++idx;
//             if (idx < length)
//                 if (IP[idx] == '.')
//                     is4 = true;
//                 else
//                     is6 = true;
//             strs.emplace_back(IP.substr(start, idx - start));
//             ++idx;
//             start = idx;
//         }
//     }

//     if (is4)
//     {
//         if (strs.size() != 4)
//             return "Neither";
//         for (const auto &str : strs)
//         {
//             if (str.empty() || str.size() > 3)
//                 return "Neither";
//             else if (str.size() == 1)
//             {
//                 if (!std::isdigit(str[0]))
//                     return "Neither";
//             }
//             else
//             {
//                 if (str[0] == '0')
//                     return "Neither";

//                 int n = 0;
//                 for (char c : str)
//                 {
//                     if (std::isdigit(c))
//                         n = n * 10 + c - '0';
//                     else
//                         return "Neither";
//                 }
//                 if (n > 255)
//                     return "Neither";
//             }
//         }
//         return "IPv4";
//     }
//     else if (is6)
//     {
//         if (strs.size() != 8)
//             return "Neither";
//         for (const auto &str : strs)
//         {
//             if (str.empty() || str.size() > 4)
//                 return "Neither";
//             for (char c : str)
//                 if (!isxdigit(c))
//                     return "Neither";
//         }
//         return "IPv6";
//     }
//     else
//         return "Neither";
// }

// /*
// 已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。
// 不要使用系统的 Math.random() 方法。

// 示例 1:
// 输入: 1
// 输出: [7]

// 示例 2:
// 输入: 2
// 输出: [8,4]

// 示例 3:
// 输入: 3
// 输出: [8,1,10]
//  
// 提示:
// rand7 已定义。
// 传入参数: n 表示 rand10 的调用次数。

// 进阶:
// rand7()调用次数的 期望值 是多少 ?
// 你能否尽量少调用 rand7() ?

// 思路：拒绝采样
// Implement randM() using randN() when M > N:
// Step 1: Use randN() to generate randX(), where X >= M.
// In this problem, I use 7 * (rand7() - 1) + (rand7() - 1) to generate rand49() - 1.
// Step 2: Use randX() to generate randM().
// In this problem, I use rand49() to generate rand40() then generate rand10.
// */
// int rand7()
// {
//     random_device rd;
//     static default_random_engine e(rd());
//     uniform_int_distribution<int> uid(1, 7);
//     return uid(e);
// }
// int rand10()
// {
//     while (true)
//     {
//         int num = (rand7() - 1) * 7 + rand7() - 1; // [0, 48]
//         if (num < 40)                              // [0, 39]
//             return num % 10 + 1;                   // [0, 9] + 1 -> [1, 10]
//     }
// }

// /*
// 还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。
// 输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

// 示例 1:
// 输入: [1,1,2,2,2]
// 输出: true
// 解释: 能拼成一个边长为2的正方形，每边两根火柴。

// 示例 2:
// 输入: [3,3,3,3,4]
// 输出: false
// 解释: 不能用所有火柴拼成一个正方形。

// 注意:
// 给定的火柴长度和在 0 到 10^9之间。
// 火柴数组的长度不超过15。

// 思路：深搜+剪枝（超时）
// 1）用一个数组存储3条边
// 2）递归所有情况，直到3条边都得到总长的四分之一
// */
// bool makesquareRecursively(const vector<int> &nums, const unsigned long long int &edge_len, vector<bool> &used, vector<unsigned long long int> &edges)
// {
//     if (edges[0] == edge_len && edges[0] == edges[1] && edges[1] == edges[2])
//         return true;

//     auto maxval = std::max_element(edges.begin(), edges.end());
//     if ((*maxval) > edge_len)
//         return false;

//     for (int i = nums.size() - 1; i >= 0; --i)
//     {
//         if (!used[i])
//         {
//             used[i] = true;
//             for (int j = 0; j < 3; ++j)
//             {
//                 if (edges[j] == edge_len)
//                     continue;
//                 edges[j] += nums[i];
//                 if (makesquareRecursively(nums, edge_len, used, edges))
//                     return true;
//                 edges[j] -= nums[i];
//             }
//             used[i] = false;
//         }
//     }
//     return false;
// }
// bool makesquare(vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 4)
//         return false;

//     std::sort(nums.begin(), nums.end());
//     unsigned long long int total_length = std::accumulate(nums.begin(), nums.end(), 0ULL);
//     if (total_length % 4 != 0 || total_length / 4 < nums.back())
//         return false;

//     vector<bool> used(length, false);
//     vector<unsigned long long int> edges(3, 0);
//     return makesquareRecursively(nums, total_length / 4, used, edges);
// }
// /*
// 思路：深搜
// 依次构建3条边，直到3条边都得到总长的四分之一
// */
// bool makesquareRecursively2(const vector<int> &nums, vector<bool> &used, const unsigned long long int &edge_len, unsigned long long int cur_len, int cur_idx)
// {
//     if (cur_len > edge_len)
//         return false;
//     if (cur_len == edge_len)
//         return true;

//     // 从左到右搜索
//     for (int i = cur_idx; i < nums.size(); i++)
//     {
//         if (!used[i])
//         {
//             used[i] = true;
//             if (makesquareRecursively2(nums, used, edge_len, cur_len + nums[i], i + 1))
//                 return true;
//             used[i] = false;
//         }
//     }
//     return false;
// }
// bool makesquare2(vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 4)
//         return false;

//     // 降序排序
//     std::sort(nums.begin(), nums.end(), greater<int>());
//     // 累计总长
//     unsigned long long int total_length = std::accumulate(nums.begin(), nums.end(), 0ULL);
//     // 得到边长
//     unsigned long long int edge_len = total_length / 4;
//     // 总长不能被4整除 或 最长火柴大于边长，则不能构成正方形
//     if (total_length % 4 != 0 || edge_len < nums.front())
//         return false;

//     // 标记
//     vector<bool> used(length, false);
//     // 依次构建3条边
//     for (int i = 0; i < 3; i++)
//         if (!makesquareRecursively2(nums, used, edge_len, 0, 0))
//             return false;

//     return true;
// }

// /*
// 在计算机界中，我们总是追求用有限的资源获取最大的收益。
// 现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
// 你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

// 注意:
// 给定 0 和 1 的数量都不会超过 100。
// 给定字符串数组的长度不会超过 600。

// 示例 1:
// 输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
// 输出: 4
// 解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。

// 示例 2:
// 输入: Array = {"10", "0", "1"}, m = 1, n = 1
// 输出: 2
// 解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。

// 思路：动态规划
// 这个题最重要的是找到物品 和 容量。
// 换个思路：
// A:如果题目是给你一个序列，里面存的是由0组成的字符串，每个字符串的长度不一定，但是都由0组成，给你m个0.求这m个0最多可以装多少个字符串？
// B:如果题目给你一个序列，里面存了好多个字符串，每个字符串代表一个物品，长度越长代表物品越沉，背包最大承载量为100，求最多能装多少个物品？
// 这就熟悉了->01背包
// 题目就是换了个思路，两维了。一方面要考虑0的情况，一方面要考虑1的情况。
// 物品没有变，是strs
// 容量有两个，m和n，要都满足。
// 动态转移方程
// for(0..strs.size)
//  for(m...0)
//   for(n...0)
//     dp[i][j] = max(dp[i][j], dp[i-0数量][j-1数量]+1)
// */
// int findMaxForm(vector<string> &strs, int m, int n)
// {
//     if (strs.empty() || (m <= 0 && n <= 0))
//         return 0;

//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//     for (const auto &str : strs)
//     {
//         int zero_cnt = 0, one_cnt = 0;
//         for (auto ch : str)
//         {
//             if (ch == '0')
//                 ++zero_cnt;
//             else
//                 ++one_cnt;
//         }

//         for (int i = m; i >= zero_cnt; --i)
//         {
//             for (int j = n; j >= one_cnt; --j)
//             {
//                 dp[i][j] = std::max(dp[i][j], dp[i - zero_cnt][j - one_cnt] + 1);
//             }
//         }
//     }
//     return dp[m][n];
// }
// /*
// 思路：更像是一种贪心算法, 优先选择长度较小的
// */
// int findMaxForm(vector<string> &strs, int m, int n)
// {
//     int length = strs.size();
//     if (length == 0 || (m <= 0 && n <= 0))
//         return 0;

//     std::sort(strs.begin(), strs.end());
//     std::stable_sort(strs.begin(), strs.end(), [](const string &a, const string &b) {
//         return a.size() < b.size();
//     });

//     vector<vector<int>> cnt_0_1;
//     cnt_0_1.reserve(length);
//     for (const auto &str : strs)
//     {
//         int cnt_0 = 0, cnt_1 = 0;
//         for (auto c : str)
//             if (c == '0')
//                 ++cnt_0;
//             else
//                 ++cnt_1;

//         cnt_0_1.emplace_back(vector<int>{cnt_0, cnt_1});
//     }

//     int res = INT_MIN;
//     for (int i = 0; i < length; i++)
//     {
//         int cur_max = 0;
//         int cnt_total = m + n;
//         int cnt_0 = m, cnt_1 = n;
//         for (int j = i; j < length; j++)
//         {
//             //总的剩余字符个数
//             cnt_total -= strs[j].size();

//             // 长度有余
//             if (cnt_total >= 0)
//             {
//                 //0剩下的个数
//                 cnt_0 -= cnt_0_1[j][0];
//                 //1剩下的个数
//                 cnt_1 -= cnt_0_1[j][1];
//                 // 0 和 1 数量足够
//                 if (cnt_0 >= 0 && cnt_1 >= 0)
//                     ++cur_max;
//                 // 0 or 1 数量不够, 进行还原
//                 else
//                 {
//                     cnt_total += strs[j].size();
//                     cnt_0 += cnt_0_1[j][0];
//                     cnt_1 += cnt_0_1[j][1];
//                     continue;
//                 }
//             }
//             // 长度不够, 后面只会更长
//             else
//                 break;
//         }
//         res = std::max(res, cur_max);
//     }
//     return res;
// }

// /*
// 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
// 计算一个数组中，任意两个数之间汉明距离的总和。

// 示例:
// 输入: 4, 14, 2
// 输出: 6
// 解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
// 所以答案为：
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
// 注意:
// 数组中元素的范围为从 0到 10^9。
// 数组的长度不超过 10^4。

// 思路：问题转化
// 1）所有数两两的海明距离总和
// 2）转化为所有二进制位上两两不同的数的个数
// 3）转化为 二进制位长度*当前位上0和1不同的数的个数
// 4）转化为 二进制位长度*(当前位上为0的数的个数*当前位上为1的数的个数)
// */
// int totalHammingDistance(const vector<int> &nums)
// {
//     int length = nums.size();
//     if (length < 2)
//         return 0;

//     constexpr int total_bit_len = sizeof(int) * 8; // int的二进制位数
//     unsigned int mask = 0x01;                      // 掩码，用于取得某位是否为1
//     int res = 0;
//     for (int i = 0; i < total_bit_len; ++i) // 遍历所有二进制位数
//     {
//         int cnt_one = 0;
//         for (auto num : nums) // 遍历所有数，获得当前二进制位为1的数的个数
//         {
//             if (num & mask) // 当前数的该二进制位是否为1？
//                 ++cnt_one;
//         }

//         mask <<= 1;
//         res += cnt_one * (length - cnt_one); // 当前位的海明距离为 1的个数*0的个数
//     }
//     return res;
// }

// /*
// 神奇的字符串 S 只包含 '1' 和 '2'，并遵守以下规则：
// 字符串 S 是神奇的，因为串联字符 '1' 和 '2' 的连续出现次数会生成字符串 S 本身。
// 字符串 S 的前几个元素如下：S = “1221121221221121122 ......”
// 如果我们将 S 中连续的 1 和 2 进行分组，它将变成：
// 1 22 11 2 1 22 1 22 11 2 11 22 ......
// 并且每个组中 '1' 或 '2' 的出现次数分别是：
// 1 2 2 1 1 2 1 2 2 1 2 2 ......
// 你可以看到上面的出现次数就是 S 本身。
// 给定一个整数 N 作为输入，返回神奇字符串 S 中前 N 个数字中的 '1' 的数目。
// 注意：N 不会超过 100,000。

// 示例：
// 输入：6
// 输出：3
// 解释：神奇字符串 S 的前 6 个元素是 “122112”，它包含三个 1，因此返回 3。

// 思路：按题目要求生成S，然后统计即可
// */
// int magicalString(int n)
// {
//     if (n <= 0)
//         return 0;
//     if (n < 4)
//         return 1;

//     string S = "122";
//     bool turn_one = true; // 是否生成1
//     int idx = 2;          // 当前下标
//     int res = 1;
//     while (idx <= n - 1)
//     {
//         if (S[idx] == '1') // 当前是1
//         {
//             ++res;
//             if (turn_one) // 是生成1，那么加一个1
//                 S.push_back('1');
//             else // 生成2，那么加一个2
//                 S.push_back('2');
//         }
//         else // 当前是2
//         {
//             if (turn_one) // 是生成1，加两个1
//                 S += "11";
//             else // 生成2，加两个2
//                 S += "22";
//         }
//         turn_one = !turn_one; // 本次生成1，那么下次生成2，反之亦然
//         ++idx;
//     }
//     return res;
// }

// /*
// 给定一个表示分数的非负整数数组。
// 玩家1从数组任意一端拿取一个分数，
// 随后玩家2继续从剩余数组任意一端拿取分数，然后玩家1拿，……。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。
// 直到没有剩余分数可取时游戏结束。
// 最终获得分数总和最多的玩家获胜。
// 给定一个表示分数的数组，预测玩家1是否会成为赢家。
// 你可以假设每个玩家的玩法都会使他的分数最大化。

// 示例 1:
// 输入: [1, 5, 2]
// 输出: False
// 解释: 一开始，玩家1可以从1和2中进行选择。
// 如果他选择2（或者1），那么玩家2可以从1（或者2）和5中进行选择。如果玩家2选择了5，那么玩家1则只剩下1（或者2）可选。
// 所以，玩家1的最终分数为 1 + 2 = 3，而玩家2为 5。
// 因此，玩家1永远不会成为赢家，返回 False。

// 示例 2:
// 输入: [1, 5, 233, 7]
// 输出: True
// 解释: 玩家1一开始选择1。然后玩家2必须从5和7中进行选择。无论玩家2选择了哪个，玩家1都可以选择233。
// 最终，玩家1（234分）比玩家2（12分）获得更多的分数，所以返回 True，表示玩家1可以成为赢家。

// 注意:
// 1 <= 给定的数组长度 <= 20.
// 数组里所有分数都为非负数且不会大于10000000。
// 如果最终两个玩家的分数相等，那么玩家1仍为赢家。

// 思路：递归
// */
// int PredictTheWinnerRecursively(const vector<int> &nums, int start, int stop)
// {
//     if (start == stop) // 只有一个数时，玩家1先手直接选择它
//         return nums[start];
//     else if (start + 1 == stop) // 有两个数时，玩家1先手选择最大的那个
//         return std::max(nums[start], nums[stop]);

//     // 有多个数时，不论玩家1还是玩家2，都会选择最大的那个
//     // 假设玩家1选择了头部最大的之后，剩余的最大的还是头部，那么玩家2为了自己最大化，那么会选择头部
//     // 再轮到玩家1时，挑玩家2挑完后的最大的
//     return std::max(nums[start] + std::min(PredictTheWinnerRecursively(nums, start + 1, stop - 1), PredictTheWinnerRecursively(nums, start + 2, stop)),
//                     nums[stop] + std::min(PredictTheWinnerRecursively(nums, start + 1, stop - 1), PredictTheWinnerRecursively(nums, start, stop - 2)));
// }
// bool PredictTheWinner(const vector<int> &nums)
// {
//     if (nums.size() == 1)
//         return true;

//     // 计算总和
//     int sum = std::accumulate(nums.begin(), nums.end(), 0);
//     // 计算玩家1先手获得的总和
//     int sum1 = PredictTheWinnerRecursively(nums, 0, nums.size() - 1);
//     // 玩家1得总和不小于玩家2的总和则胜利
//     return sum1 >= (sum - sum1);
// }
// // 思路2：动态规划
// bool PredictTheWinner2(const vector<int> &nums)
// {
//     int length = nums.size();
//     // 偶数直接返回true，因为假设玩家1先手挑失败了，那么换一头挑就会赢
//     if (length == 1 || length % 2 == 0)
//         return true;

//     int sum = 0;
//     // dp[i][j]表示在区间[i, j]玩家1选手取得的总和
//     vector<vector<int>> dp(length, vector<int>(length, 0));

//     for (int i = 0; i < length; i++) // 只有一个数，那么玩家1先手选它
//     {
//         dp[i][i] = nums[i];
//         sum += nums[i];
//     }

//     for (int i = 1; i < length; i++) // 两个数，那么玩家1先手选最大的那个
//         dp[i - 1][i] = std::max(nums[i - 1], nums[i]);

//     for (int len = 2; len < length; len++)
//     {
//         for (int start = 0; start + len < length; start++)
//         {
//             int stop = start + len;
//             // 每个玩家都想拿最大的
//             // 本次玩家1拿最大的，接着玩家2也拿最大的，再轮到玩家1只能拿玩家2拿完后的最大值
//             dp[start][stop] = std::max(nums[start] + std::min(dp[start + 1][stop - 1], dp[start + 2][stop]),
//                                        // 玩家1拿走头，玩家2能选头和尾，然后玩家1再选，但由于玩家2拿走了最大，那么玩家1再选只能获得较小的那个
//                                        nums[stop] + std::min(dp[start + 1][stop - 1], dp[start][stop - 2]));
//         }
//     }
//     return dp[0][length - 1] >= sum - dp[0][length - 1];
// }

// /*
// 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

// 示例:
// 输入: [4, 6, 7, 7]
// 输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

// 说明:
// 给定数组的长度不会超过15。
// 数组中的整数范围是 [-100,100]。
// 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。

// 思路：递归深搜（注意去重）
// */
// void findSubsequencesRecursively(const vector<int> &nums, int start, vector<int> &out, vector<vector<int>> &res)
// {
//     if (out.size() >= 2)
//         res.push_back(out);

//     unordered_set<int> st;
//     for (int i = start; i < nums.size(); ++i)
//     {
//         // 已访问过相同的元素 或 不是递增的 跳过
//         if (st.count(nums[i]) || !out.empty() && out.back() > nums[i])
//             continue;

//         out.push_back(nums[i]);
//         st.insert(nums[i]);
//         findSubsequencesRecursively(nums, i + 1, out, res);
//         out.pop_back();
//     }
// }
// vector<vector<int>> findSubsequences(const vector<int> &nums)
// {
//     vector<vector<int>> res;
//     vector<int> out;
//     findSubsequencesRecursively(nums, 0, out, res);
//     return res;
// }

// /*
// 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
// 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

// 示例 1:
// 输入: nums: [1, 1, 1, 1, 1], S: 3
// 输出: 5
// 解释:
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
// 一共有5种方法让最终目标和为3。
// 注意:
// 数组的长度不会超过20，并且数组中的值全为正数。
// 初始的数组的和不会超过1000。
// 保证返回的最终结果为32位整数。

// 思路：遍历递归（超时）
// */
// void findTargetSumWaysRecursively(const vector<int> &nums, const int &S, int idx, int cur_sum, int &res)
// {
//     if (idx >= nums.size())
//     {
//         if (cur_sum == S)
//             ++res;
//         return;
//     }
//     findTargetSumWaysRecursively(nums, S, idx + 1, cur_sum + nums[idx], res);
//     findTargetSumWaysRecursively(nums, S, idx + 1, cur_sum - nums[idx], res);
// }
// int findTargetSumWays(const vector<int> &nums, int S)
// {
//     int length = nums.size();
//     if (length == 0)
//         return 0;

//     int res = 0;
//     findTargetSumWaysRecursively(nums, S, 0, 0, res);
//     return res;
// }
// // 思路2：生成所有情况（超时）
// int findTargetSumWays2(const vector<int> &nums, int S)
// {
//     int length = nums.size();
//     if (length == 0)
//         return 0;

//     vector<vector<int>> subtotals(2, vector<int>{});
//     subtotals[0].push_back(0);
//     int idx = 0;
//     for (int num : nums)
//     {
//         for (int sub : subtotals[idx])
//         {
//             subtotals[1 - idx].push_back(sub + num);
//             subtotals[1 - idx].push_back(sub - num);
//         }
//         subtotals[idx].clear();
//         idx = 1 - idx;
//     }
//     int res = 0;
//     for (int s : subtotals[idx])
//         if (s == S)
//             ++res;
//     return res;
// }
// /*
// 思路3：问题转化
// 原问题等同于： 找到nums一个正子集和一个负子集，使得总和等于target
// 我们假设P是正子集，N是负子集
// 例如： 假设nums = [1, 2, 3, 4, 5]，target = 3，一个可能的解决方案是+1-2+3-4+5 = 3 这里正子集P = [1, 3, 5]和负子集N = [2, 4]
// 那么让我们看看如何将其转换为子集求和问题：
//                   sum(P) - sum(N) = target
// sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
//                        2 * sum(P) = target + sum(nums)
// 因此，原来的问题已转化为一个求子集的和问题： 找到nums的一个子集 P，使得sum(P) = (target + sum(nums)) / 2
// 这是一个01背包问题
// */
// int findTargetSumWays3(const vector<int> &nums, int S)
// {
//     int length = nums.size();
//     if (length == 0)
//         return 0;

//     int sum = std::accumulate(nums.begin(), nums.end(), 0);
//     if (S > sum || (S + sum) % 2 != 0)
//         return 0;

//     int target = (S + sum) / 2;
//     vector<int> dp(target + 1, 0); // dp[i]表示当子集和为i时有多少种选法
//     dp[0] = 1;                     // 子集和为0时有1种选法，即什么也不选
//     for (int num : nums)           // 优化空间的01背包
//         for (int t = target; t >= num; --t)
//             dp[t] += dp[t - num]; // dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i]] 选择到第i件物品子集和为j的选法数=不选i+选i

//     return dp[target];
// }

// /*
// 在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄，他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。
// 现在，给出提莫对艾希的攻击时间序列和提莫攻击的中毒持续时间，你需要输出艾希的中毒状态总时长。
// 你可以认为提莫在给定的时间点进行攻击，并立即使艾希处于中毒状态。

// 示例1:
// 输入: [1,4], 2
// 输出: 4
// 原因: 在第 1 秒开始时，提莫开始对艾希进行攻击并使其立即中毒。中毒状态会维持 2 秒钟，直到第 2 秒钟结束。
// 在第 4 秒开始时，提莫再次攻击艾希，使得艾希获得另外 2 秒的中毒时间。
// 所以最终输出 4 秒。

// 示例2:
// 输入: [1,2], 2
// 输出: 3
// 原因: 在第 1 秒开始时，提莫开始对艾希进行攻击并使其立即中毒。中毒状态会维持 2 秒钟，直到第 2 秒钟结束。
// 但是在第 2 秒开始时，提莫再次攻击了已经处于中毒状态的艾希。
// 由于中毒状态不可叠加，提莫在第 2 秒开始时的这次攻击会在第 3 秒钟结束。
// 所以最终输出 3。

// 注意：
// 你可以假定时间序列数组的总长度不超过 10000。
// 你可以假定提莫攻击时间序列中的数字和提莫攻击的中毒持续时间都是非负整数，并且不超过 10,000,000。

// 思路：模拟法，计算连续重叠区间长度
// */
// int findPoisonedDuration(const vector<int> &timeSeries, int duration)
// {
//     int length = timeSeries.size();
//     if (length == 0 || duration == 0)
//         return 0;

//     int start = timeSeries[0];
//     int stop = timeSeries[0] + duration;
//     int res = 0;
//     for (int i = 1; i < length; i++)
//     {
//         if (stop >= timeSeries[i])
//             stop = timeSeries[i] + duration;
//         else
//         {
//             res += stop - start;
//             start = timeSeries[i];
//             stop = start + duration;
//         }
//     }
//     res += stop - start;

//     return res;
// }
// // 思路2：优化法
// int findPoisonedDuration2(const vector<int> &timeSeries, int duration)
// {
//     int length = timeSeries.size();
//     if (length == 0 || duration == 0)
//         return 0;

//     int res = duration;
//     for (int i = 1; i < length; i++)
//         res += std::min(duration, timeSeries[i] - timeSeries[i - 1]);

//     return res;
// }

///*
//给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
//
//示例:
//输入:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//输出:  [1,2,4,7,5,3,6,8,9]
//
//说明:
//给定矩阵中的元素总数不会超过 100000 。
//
//思路：找规律，然后模拟
//*/
//vector<int> findDiagonalOrder(const vector<vector<int>> &matrix)
//{
//    // 空数组处理
//    int rows = matrix.size();
//    if (rows == 0)
//        return {};
//    int cols = matrix[0].size();
//    if (cols == 0)
//        return {};
//
//    // 只有一行或一列的时候
//    if (rows == 1)
//        return matrix[0];
//    if (cols == 1)
//    {
//        vector<int> res;
//        res.reserve(rows);
//        for (int row = 0; row < rows; row++)
//            res.push_back(matrix[row][0]);
//        return res;
//    }
//
//    vector<int> res;
//    res.reserve(rows * cols);
//    res.push_back(matrix[0][0]);
//    int is_up = true; // 当前对角线是往上走还是往下走
//    int row = 0, col = 0;
//    while (true)
//    {
//        if (is_up) // 往上走
//        {
//            if (row - 1 < 0 || col + 1 > cols - 1) // 走到顶了，转换为往下走
//            {
//                if (col + 1 <= cols - 1) // 如果能往右走，则往右走
//                    ++col;
//                else if (row + 1 <= rows - 1) // 如果能往下走，则往下走
//                    ++row;
//                else // 都不行，结束
//                    break;
//                is_up = false;
//            }
//            else // 往上走时，行变小，列变大
//            {
//                --row;
//                ++col;
//            }
//        }
//        else // 往下走
//        {
//            if (row + 1 > rows - 1 || col - 1 < 0) // 走到顶了，转换为往上走
//            {
//                if (row + 1 <= rows - 1) // 如果能往下走，则往下走
//                    ++row;
//                else if (col + 1 <= cols - 1) // 如果能往右走，则往右走
//                    ++col;
//                else // 都不行，结束
//                    break;
//                is_up = true;
//            }
//            else // 往下走时，行变大，列变小
//            {
//                ++row;
//                --col;
//            }
//        }
//        res.push_back(matrix[row][col]);
//    }
//    return res;
//}
//
///*
//给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
//数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。
//如果不存在，则输出 -1。
//
//示例 1:
//输入: [1,2,1]
//输出: [2,-1,2]
//解释: 第一个 1 的下一个更大的数是 2；
//数字 2 找不到下一个更大的数；
//第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
//
//注意: 输入数组的长度不会超过 10000。
//
//思路：单调栈(https://leetcode-cn.com/problems/next-greater-element-ii/solution/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-2/)
//1）寻找右边第一个比自己大的数
//2）从后向前构建单调递减栈（栈底到栈顶越来越小）
//3）由于是循环，可以将原数组复制一份放在原数组后面
//4）例子：{2, 1, 2, 4, 3}
//           _________
//          |  _______|  
//     _____| |  ___  | |
//    |  _| | | |  _| | |
//    | | | | | | | | | |
//    2 1 2 4 3 2 1 2 4 3
//    4 2 4 * 4
//*/
//vector<int> nextGreaterElements(const vector<int> &nums)
//{
//    int length = nums.size();
//    if (length == 0)
//        return {};
//    else if (length == 1)
//        return {-1};
//
//    vector<int> res(length);
//    stack<int> st;
//    for (int i = length * 2 - 1; i >= 0; i--)
//    {
//        int idx = i % length;
//        while (!st.empty() && st.top() <= nums[idx])
//            st.pop();
//
//        res[idx] = st.empty() ? -1 : st.top();
//        st.push(nums[idx]);
//    }
//    return res;
//}

//// 单调栈汇总
//vector<int> nextGreater(const vector<int> &nums)
//{
//    // 特殊情况处理
//    int length = nums.size();
//    if (length == 0)
//        return {};
//    else if (length == 1)
//        return {-1};
//
//    vector<int> res(length);
//    stack<int> st;
//    // 从后往前扫描
//    for (int i = length - 1; i >= 0; i--)
//    {
//        // 构建单调递减栈
//        while (!st.empty() && st.top() <= nums[i])
//            st.pop();
//        res[i] = st.empty() ? -1 : st.top();
//        st.push(nums[i]);
//    }
//    return res;
//}
//vector<int> nextSmaller(const vector<int> &nums)
//{
//    // 特殊情况处理
//    int length = nums.size();
//    if (length == 0)
//        return {};
//    else if (length == 1)
//        return {-1};
//
//    vector<int> res(length);
//    stack<int> st;
//    // 从后往前扫描
//    for (int i = length - 1; i >= 0; i--)
//    {
//        // 构建单调递增栈
//        while (!st.empty() && st.top() >= nums[i])
//            st.pop();
//        res[i] = st.empty() ? -1 : st.top();
//        st.push(nums[i]);
//    }
//    return res;
//}
//vector<int> previousGreater(const vector<int> &nums)
//{
//    // 特殊情况处理
//    int length = nums.size();
//    if (length == 0)
//        return {};
//    else if (length == 1)
//        return {-1};
//
//    vector<int> res(length);
//    stack<int> st;
//    // 从前往后扫描
//    for (int i = 0; i < length; i++)
//    {
//        // 构建单调递减栈
//        while (!st.empty() && st.top() <= nums[i])
//            st.pop();
//        res[i] = st.empty() ? -1 : st.top();
//        st.push(nums[i]);
//    }
//    return res;
//}
//vector<int> previousSmaller(const vector<int> &nums)
//{
//    // 特殊情况处理
//    int length = nums.size();
//    if (length == 0)
//        return {};
//    else if (length == 1)
//        return {-1};
//
//    vector<int> res(length);
//    stack<int> st;
//    // 从前往后扫描
//    for (int i = 0; i < length; i++)
//    {
//        // 构建单调递增栈
//        while (!st.empty() && st.top() >= nums[i])
//            st.pop();
//        res[i] = st.empty() ? -1 : st.top();
//        st.push(nums[i]);
//    }
//    return res;
//}

///*
//给出二叉树的根，找出出现次数最多的子树元素和。
//一个结点的子树元素和定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
//然后求出出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的元素（不限顺序）。
//
//示例 1
//输入:
//
//  5
// /  \
//2   -3
//返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。
//
//示例 2
//输入:
//
//  5
// /  \
//2   -5
//返回 [2]，只有 2 出现两次，-5 只出现 1 次。
//
//提示： 假设任意子树元素和均可以用 32 位有符号整数表示。
//
//思路：前序遍历
//*/
//int findFrequentTreeSumRecursively(TreeNode *p, unordered_map<int, int> &sum_cnt, int &max_cnt)
//{
//    if (p->left == nullptr && p->right == nullptr)
//    {
//        ++sum_cnt[p->val];
//        max_cnt = std::max(max_cnt, sum_cnt[p->val]);
//        return p->val;
//    }
//
//    int sum = p->val;
//    if (p->left != nullptr)
//        sum += findFrequentTreeSumRecursively(p->left, sum_cnt, max_cnt);
//    if (p->right != nullptr)
//        sum += findFrequentTreeSumRecursively(p->right, sum_cnt, max_cnt);
//    ++sum_cnt[sum];
//    max_cnt = std::max(max_cnt, sum_cnt[sum]);
//
//    return sum;
//}
//vector<int> findFrequentTreeSum(TreeNode *root)
//{
//    if (root == nullptr)
//        return {};
//
//    unordered_map<int, int> sum_cnt;
//    int max_cnt = INT_MIN;
//    findFrequentTreeSumRecursively(root, sum_cnt, max_cnt);
//
//    vector<int> res;
//    for (const auto &p : sum_cnt)
//    {
//        if (p.second == max_cnt)
//            res.push_back(p.first);
//    }
//
//    return res;
//}
//
///*
//给定一个二叉树，在树的最后一行找到最左边的值。
//
//示例 1:
//输入:
//
//    2
//   / \
//  1   3
//
//输出:
//1
//
//示例 2:
//输入:
//        1
//       / \
//      2   3
//     /   / \
//    4   5   6
//       /
//      7
//输出:
//7
//
//注意: 您可以假设树（即给定的根节点）不为 NULL。
//*/
//int findBottomLeftValue(TreeNode *root)
//{
//    if (root->left == nullptr && root->right == nullptr)
//        return root->val;
//
//    int res = -1;
//    int width = 1;
//    queue<TreeNode *> qu;
//    qu.push(root);
//    while (!qu.empty())
//    {
//        int len = width;
//        width = 0;
//        for (int i = 0; i < len; ++i)
//        {
//            TreeNode *t = qu.front();
//            qu.pop();
//            if (i == 0)
//                res = t->val;
//            if (t->left != nullptr)
//            {
//                qu.push(t->left);
//                ++width;
//            }
//            if (t->right != nullptr)
//            {
//                qu.push(t->right);
//                ++width;
//            }
//        }
//    }
//    return res;
//}

///*
//您需要在二叉树的每一行中找到最大的值。
//
//示例：
//
//输入:
//
//          1
//         / \
//        3   2
//       / \   \
//      5   3   9
//
//输出: [1, 3, 9]
//*/
//vector<int> largestValues(TreeNode *root)
//{
//    if (root == nullptr)
//        return {};
//
//    vector<int> res;
//    queue<TreeNode *> qu;
//    int width = 1;
//    qu.push(root);
//    res.push_back(root->val);
//    while (!qu.empty())
//    {
//        int len = width;
//        width = 0;
//        int max_val = INT_MIN;
//        for (int i = 0; i < len; ++i)
//        {
//            TreeNode *t = qu.front();
//            qu.pop();
//
//            if (t->left != nullptr)
//            {
//                qu.push(t->left);
//                max_val = std::max(max_val, t->left->val);
//                ++width;
//            }
//            if (t->right != nullptr)
//            {
//                qu.push(t->right);
//                max_val = std::max(max_val, t->right->val);
//                ++width;
//            }
//        }
//        res.push_back(max_val);
//    }
//    res.pop_back();
//
//    return res;
//}

///*
//给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
//
//示例 1:
//输入:
//"bbbab"
//输出:
//4
//一个可能的最长回文子序列为 "bbbb"。
//
//示例 2:
//输入:
//"cbbd"
//输出:
//2
//一个可能的最长回文子序列为 "bb"。
//
//思路：动态规划
//1）dp[i][j]表示s[i:j]中最长回文子串的长度
//2）递推公式：
//    a.dp[i]j]=dp[i+1][j-1]+2，s[i]==s[j]
//    b.dp[i][j]=max(dp[i+1][j], dp[i][j-1])，s[i]!=s[j]
//*/
//int longestPalindromeSubseq(const string &s)
//{
//    int length = s.size();
//    if (length < 2)
//        return length;
//
//    vector<vector<int>> dp(length, vector<int>(length, 0));
//    for (int i = 0; i < length; i++) // 一个字符的时候长度为1
//        dp[i][i] = 1;
//
//    for (int len = 1; len < length; len++) // 字符长度逐渐增加
//    {
//        for (int start = 0; start + len < length; start++)
//        {
//            if (s[start] == s[start + len])
//                dp[start][start + len] = dp[start + 1][start + len - 1] + 2;
//            else
//                dp[start][start + len] = std::max(dp[start + 1][start + len], dp[start][start + len - 1]);
//        }
//    }
//
//    return dp[0][length - 1];
//}

///*
//给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 
//
//示例 1:
//输入: amount = 5, coins = [1, 2, 5]
//输出: 4
//解释: 有四种方式可以凑成总金额:
//5=5
//5=2+2+1
//5=2+1+1+1
//5=1+1+1+1+1
//
//示例 2:
//输入: amount = 3, coins = [2]
//输出: 0
//解释: 只用面额2的硬币不能凑成总金额3。
//
//示例 3:
//输入: amount = 10, coins = [10]
//输出: 1
//
//注意:
//你可以假设：
//0 <= amount (总金额) <= 5000
//1 <= coin (硬币面额) <= 5000
//硬币种类不超过 500 种
//结果符合 32 位符号整数
//
//思路：完全背包问题（优化空间）
//1）dp[j]表示总额为j时的组合数
//2）dp[0]=1，金额为0时，只有一种拿法，即社么也不拿
//3）伪代码：
//    for i in [0, n-1]:
//        for j in [coins[i], amount]:
//            dp[j]=dp[j]+dp[j-coins[i]]
//*/
//int change(int amount, const vector<int> &coins)
//{
//    if (amount == 0)
//        return 1;
//    if (amount != 0 && coins.empty())
//        return 0;
//
//    int length = coins.size();
//    vector<int> dp(amount + 1, 0);
//    dp[0] = 1;
//    for (int i = 0; i < length; ++i)
//    {
//        for (int j = coins[i]; j <= amount; ++j)
//        {
//            dp[j] = dp[j] + dp[j - coins[i]];
//        }
//    }
//
//    return dp[amount];
//}

///*
//给定字符串列表，你需要从它们中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。
//子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。
//输入将是一个字符串列表，输出是最长特殊序列的长度。如果最长特殊序列不存在，返回 -1 。
//
//示例：
//输入: "aba", "cdc", "eae"
//输出: 3
//
//提示：
//所有给定的字符串长度不会超过 10 。
//给定字符串列表的长度将在 [2, 50 ] 之间。
//
//思路：
//1）先按字符串长度降序排序
//2）如果最长串只有一个，那么最长特殊序列就是它
//3）否则，从最长串开始，判断该字符串是不是其他比它长的字符串的子序列，如果不是，那么该字符串就是结果
//*/
//int findLUSlength(vector<string> &strs)
//{
//    int length = strs.size();
//    if (length == 0)
//        return 0;
//    if (length == 1)
//        return strs[0].size();
//
//    // 按长度降序排序
//    std::sort(strs.begin(), strs.end(), [](const string &a, const string &b)
//              {
//                  return a.size() > b.size();
//              });
//
//    // a是不是b的是一个子序列
//    auto isSub = [](const string &a, const string &b)
//    {
//        auto i = a.begin();
//        auto j = b.begin();
//        while (j != b.end() && i != a.end())
//        {
//            if (*i == *j)
//            {
//                i++;
//            }
//            j++;
//        }
//        return i == a.end();
//    };
//
//    for (int i = 0; i < length; i++) // 从最长串开始
//    {
//        bool found = true;
//        // 寻找比它长的串
//        for (int j = 0; j < length && strs[j].size() >= strs[i].size(); j++)
//        {
//            // 判断该串是不是比它长的串的子序列
//            if (i != j && isSub(strs[i], strs[j]))
//            {
//                found = false;
//                break;
//            }
//        }
//        if (found)
//            return strs[i].size();
//    }
//    return -1;
//}
//
///*
//给定一个包含非负数的数组和一个目标整数 k，
//编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。
//
//示例 1:
//输入: [23,2,4,6,7], k = 6
//输出: True
//解释: [2,4] 是一个大小为 2 的子数组，并且和为 6。
//
//示例 2:
//输入: [23,2,6,4,7], k = 6
//输出: True
//解释: [23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
//
//说明:
//数组的长度不会超过10,000。
//你可以认为所有数字总和在 32 位有符号整数范围内。
//
//思路：
//1）枚举所有子数组，从长度为2开始到整个数组
//2）dp[i][j]表示[i:j]的子数组的和
//3）递推关系：dp[i][j]=dp[i][j-1]+nums[j]
//3）超内存
//*/
//bool checkSubarraySum(const vector<int> &nums, int k)
//{
//    int length = nums.size();
//    if (length < 2)
//        return false;
//
//    vector<vector<int>> dp(length, vector<int>(length, 0));
//    for (int i = 0; i < length; i++)
//        dp[i][i] = nums[i];
//
//    for (int len = 1; len < length; len++)
//    {
//        for (int start = 0; start + len < length; start++)
//        {
//            dp[start][start + len] = dp[start][start + len - 1] + nums[start + len];
//            if (k == 0 && dp[start][start + len] == 0)
//                return true;
//            else if (k != 0 && dp[start][start + len] % k == 0)
//                return true;
//        }
//    }
//    return false;
//}
//// 思路2：同上，优化了空间
//bool checkSubarraySum2(const vector<int> &nums, int k)
//{
//    int length = nums.size();
//    if (length < 2)
//        return false;
//
//    vector<int> dp(nums.begin(), nums.end());
//    for (int len = 1; len < length; len++)
//    {
//        for (int idx = length - 1; idx - len >= 0; idx--)
//        {
//            dp[idx] = dp[idx - 1] + nums[idx];
//            if (k == 0 && dp[idx] == 0)
//                return true;
//            else if (k != 0 && dp[idx] % k == 0)
//                return true;
//        }
//    }
//    return false;
//}
///*
//思路3：
//1）用sums[i]表示[0:i)，i>=0的子数组和
//2）我们希望找到[i:j]，j>i的和为n*k，即sums[j]-sums[i]+nums[j]=n*k
//3）根据%的性质:
//    (sums[j]-sums[i]+nums[j])%k==0
//            (sums[j]+nums[j])%k==sums[i]%k
//                    sums[j+1]%k==sums[i]%k
//4）也就是说，我们用一个集合存储子数组和对k的余数，如果当前子数组和对k的余数已经存在集合中，那么直接返回true
//*/
//bool checkSubarraySum3(vector<int> &nums, int k)
//{
//    int length = nums.size();
//    if (length < 2)
//        return false;
//
//    unordered_set<int> s;
//    int pre = 0;
//    int sum = 0;
//    for (int i = 0; i < length; i++)
//    {
//        sum += nums[i];
//        int mod = (k == 0 ? sum : sum % k);
//        if (s.count(mod))
//            return true;
//        s.insert(pre);
//        pre = mod;
//    }
//    return false;
//}

///*
//给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。
//如果答案不止一个，返回长度最长且字典顺序最小的字符串。
//如果答案不存在，则返回空字符串。
//
//示例 1:
//输入:
//s = "abpcplea", d = ["ale","apple","monkey","plea"]
//输出:
//"apple"
//
//示例 2:
//输入:
//s = "abpcplea", d = ["a","b","c"]
//输出:
//"a"
//
//说明:
//所有输入的字符串只包含小写字母。
//字典的大小不会超过 1000。
//所有输入的字符串长度不会超过 1000。
//
//思路：
//1）按长度降序排序，如果长度相同，按字典序排序
//2）然后从头开始判断是否符合
//*/
//string findLongestWord(const string &s, vector<string> &d)
//{
//    if (d.empty() || s.empty())
//        return {};
//
//    std::sort(d.begin(), d.end(), [](const string &a, const string &b)
//              {
//                  if (a.size() == b.size())
//                      return a < b;
//                  return a.size() > b.size();
//              });
//
//    for (int i = 0; i < d.size(); i++)
//    {
//        if (d[i].size() > s.size())
//            continue;
//
//        auto s_iter = s.begin();
//        auto d_iter = d[i].begin();
//        while (s_iter != s.end() && d_iter != d[i].end())
//        {
//            if (*s_iter == *d_iter)
//                ++d_iter;
//            ++s_iter;
//        }
//        if (d_iter == d[i].end())
//            return d[i];
//    }
//    return {};
//}
///*
//思路2：直接遍历一遍字典，按题目要求判断即可
//*/
//string findLongestWord2(const string &s, vector<string> &d)
//{
//    if (d.empty() || s.empty())
//        return {};
//
//    string res;
//    for (int i = 0; i < d.size(); i++)
//    {
//        if (d[i].size() > s.size())
//            continue;
//
//        auto s_iter = s.begin();
//        auto d_iter = d[i].begin();
//        while (s_iter != s.end() && d_iter != d[i].end())
//        {
//            if (*s_iter == *d_iter)
//                ++d_iter;
//            ++s_iter;
//        }
//        if (d_iter == d[i].end())
//        {
//            if (d[i].size() > res.size())
//                res = d[i];
//            else if (d[i].size() == res.size())
//                res = d[i] < res ? d[i] : res;
//        }
//    }
//    return res;
//}
//
///*
//给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组（的长度）。
//
//示例 1:
//输入: [0,1]
//输出: 2
//说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
//
//示例 2:
//输入: [0,1,0]
//输出: 2
//说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
// 
//注意: 给定的二进制数组的长度不会超过50000。
//
//思路：
//1）遍历所有长度，统计每种长度中1的个数
//2）判断该长度是否符合要求
//3）超时
//*/
//int findMaxLength(const vector<int> &nums)
//{
//    int length = nums.size();
//    if (length < 2)
//        return 0;
//
//    int res = 0;
//    vector<int> dp = nums; // 长度为一时1的个数
//    for (int len = 2; len <= length; len++) // 遍历所有长度
//    {
//        for (int stop = length - 1; stop - len + 1 >= 0; stop--)
//        {
//            if (nums[stop] == 1)
//                dp[stop] = dp[stop - 1] + 1;
//            else
//                dp[stop] = dp[stop - 1];
//            if (2 * dp[stop] == len) // 是否符合要求
//                res = len;
//        }
//    }
//
//    return res;
//}
///*
//思路：利用差分的思想，遇到1加1，遇到0加0，如果两次差分相同，意味着这两次中间的1和0个数一样
//（https://leetcode-cn.com/problems/contiguous-array/solution/lian-xu-shu-zu-by-leetcode/）
//*/
//int findMaxLength2(const vector<int> &nums)
//{
//    int length = nums.size();
//    if (length < 2)
//        return 0;
//
//    unordered_map<int, int> sum_idx;
//    sum_idx[0] = -1;
//    int sum = 0;
//    int res = INT_MIN;
//    for (int i = 0; i < length; i++)
//    {
//        sum += (nums[i] == 1 ? 1 : -1);
//        if (sum_idx.count(sum))
//            res = std::max(res, i - sum_idx[sum]);
//        else
//            sum_idx[sum] = i;
//    }
//    return res;
//}

///*
//假设有从 1 到 N 的 N 个整数，
//如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N) 满足如下两个条件中的一个，
//我们就称这个数组为一个优美的排列。条件：
//第 i 位的数字能被 i 整除
//i 能被第 i 位上的数字整除
//现在给定一个整数 N，请问可以构造多少个优美的排列？
//
//示例1:
//输入: 2
//输出: 2
//解释:
//第 1 个优美的排列是 [1, 2]:
//  第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
//  第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除
//第 2 个优美的排列是 [2, 1]:
//  第 1 个位置（i=1）上的数字是2，2能被 i（i=1）整除
//  第 2 个位置（i=2）上的数字是1，i（i=2）能被 1 整除
//
//说明:
//N 是一个正整数，并且不会超过15。
//
//思路：回溯+剪枝（https://leetcode-cn.com/problems/beautiful-arrangement/solution/you-mei-de-pai-lie-by-leetcode/）
//1）用一个数组标记元素是否使用过
//2）对于当前位置，从未使用过的元素中选一个，如果符合条件，将该元素放在该位置（标记已使用）
//3）递归下一个位置
//*/
//void countArrangementRecursively(vector<bool> &visited, const int &N, int idx, int &res)
//{
//    if (idx > N)
//    {
//        ++res;
//        return;
//    }
//
//    for (int i = 1; i <= N; i++)
//    {
//        if (visited[i])
//            continue;
//        if (idx % i == 0 || i % idx == 0)
//        {
//            visited[i] = true;
//            countArrangementRecursively(visited, N, idx + 1, res);
//            visited[i] = false;
//        }
//    }
//}
//int countArrangement(int N)
//{
//    if (N < 1)
//        return 0;
//    if (N == 1)
//        return 1;
//
//    int res = 0;
//    vector<bool> visited(N + 1, false);
//    countArrangementRecursively(visited, N, 1, res);
//    return res;
//}

///*
//让我们一起来玩扫雷游戏！
//给定一个代表游戏板的二维字符矩阵。 
//'M' 代表一个未挖出的地雷，
//'E' 代表一个未挖出的空方块，
//'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，
//数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，
//'X' 则表示一个已挖出的地雷。
//现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
//如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
//如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露。
//如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
//如果在此次点击中，若无更多方块可被揭露，则返回面板。
//
//示例 1：
//输入:
//[['E', 'E', 'E', 'E', 'E'],
// ['E', 'E', 'M', 'E', 'E'],
// ['E', 'E', 'E', 'E', 'E'],
// ['E', 'E', 'E', 'E', 'E']]
//Click : [3,0]
//输出:
//[['B', '1', 'E', '1', 'B'],
// ['B', '1', 'M', '1', 'B'],
// ['B', '1', '1', '1', 'B'],
// ['B', 'B', 'B', 'B', 'B']]
//
//示例 2：
//输入:
//[['B', '1', 'E', '1', 'B'],
// ['B', '1', 'M', '1', 'B'],
// ['B', '1', '1', '1', 'B'],
// ['B', 'B', 'B', 'B', 'B']]
//Click : [1,2]
//输出:
//[['B', '1', 'E', '1', 'B'],
// ['B', '1', 'X', '1', 'B'],
// ['B', '1', '1', '1', 'B'],
// ['B', 'B', 'B', 'B', 'B']]
//
//注意：
//输入矩阵的宽和高的范围为 [1,50]。
//点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
//输入面板不会是游戏结束的状态（即有地雷已被挖出）。
//简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。
//*/
//
//int checkMines(const vector<vector<char>> &board, const vector<vector<int>> &cords, const int &rows, const int &cols, const int &row, const int &col)
//{
//    int mine_cnt = 0;
//    for (const auto &cord : cords)
//    {
//        int r = row + cord[0];
//        int c = col + cord[1];
//        if (r < 0 || r >= rows || c < 0 || c >= cols)
//            continue;
//
//        if (board[r][c] == 'M')
//            ++mine_cnt;
//    }
//    return mine_cnt;
//}
//void updateBoardRecursively(vector<vector<char>> &board, const vector<vector<int>> &cords, const int &rows, const int &cols, int row, int col)
//{
//    if (row < 0 || row >= rows || col < 0 || col >= cols)
//        return;
//
//    if (board[row][col] != 'E')
//        return;
//
//    int mine_cnt = checkMines(board, cords, rows, cols, row, col);
//    if (mine_cnt > 0)
//    {
//        board[row][col] = (mine_cnt + '0');
//        return;
//    }
//
//    board[row][col] = 'B';
//    for (const auto &cord : cords)
//    {
//        updateBoardRecursively(board, cords, rows, cols, row + cord[0], col + cord[1]);
//    }
//}
//vector<vector<char>> updateBoard(vector<vector<char>> &board, const vector<int> &click)
//{
//    int rows = board.size();
//    if (rows == 0)
//        return board;
//    int cols = board[0].size();
//    if (cols == 0)
//        return board;
//    if (click.size() != 2)
//        return board;
//
//    int click_row = click[0], click_col = click[1];
//    if (click_row < 0 || click_row >= rows || click_col < 0 || click_col >= cols)
//        return board;
//
//    if (board[click_row][click_col] == 'M')
//    {
//        board[click_row][click_col] = 'X';
//        return board;
//    }
//
//    if (board[click_row][click_col] == 'E')
//    {
//        static const vector<vector<int>> cords = {{-1, -1}, {-1, 0}, {-1, 1}, {0 ,1}, {1, 1}, {1, 0}, {1, -1}, {0 ,-1}};
//        updateBoardRecursively(board, cords, rows, cols, click_row, click_col);
//    }
//
//    return board;
//}

///*
//给定两个表示复数的字符串。
//返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。
//
//示例 1:
//输入: "1+1i", "1+1i"
//输出: "0+2i"
//解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
//
//示例 2:
//输入: "1+-1i", "1+-1i"
//输出: "0+-2i"
//解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
//
//注意:
//输入字符串不包含额外的空格。
//输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。
//*/
//string complexNumberMultiply(const string &a, const string &b)
//{
//    auto a_real_idx = a.find('+');
//    int a_real = std::stoi(a.substr(0, a_real_idx));
//    int a_img = std::stoi(a.substr(a_real_idx + 1, a.size() - 1 - a_real_idx - 1));
//    auto b_real_idx = b.find('+');
//    int b_real = std::stoi(b.substr(0, b_real_idx));
//    int b_img = std::stoi(b.substr(b_real_idx + 1, b.size() - 1 - b_real_idx - 1));
//
//    complex<int> a_{a_real, a_img}, b_{b_real, b_img};
//    auto res = a_ * b_;
//    ostringstream oss;
//    oss << res.real() << '+' << res.imag() << 'i';
//    return oss.str();
//}
//
///*
//给定一个 24 小时制（小时:分钟）的时间列表，找出列表中任意两个时间的最小时间差并已分钟数表示。
//
//示例 1：
//输入: ["23:59","00:00"]
//输出: 1
//
//备注:
//列表中时间数在 2~20000 之间。
//每个时间取值在 00:00~23:59 之间。
//*/
//int findMinDifference(const vector<string> &timePoints)
//{
//    int length = timePoints.size();
//    vector<int> mins;
//    mins.reserve(length);
//    for (const auto &tp : timePoints) // 转换成分钟
//    {
//        int min = ((tp[0] - '0') * 10 + tp[1] - '0') * 60 + ((tp[3] - '0') * 10 + tp[4] - '0');
//        mins.push_back(min);
//    }
//
//    std::sort(mins.begin(), mins.end()); // 按时间先后排序
//
//    int res = INT_MAX;
//    for (int i = 1; i < length; i++) // 计算相邻时间差
//        res = std::min(res, mins[i] - mins[i - 1]);
//    // 注意第一个和最后一个的时间差也要计算
//    res = std::min(res, mins.front() + 24 * 60 - mins.back());
//
//    return res;
//}
//
///*
//给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。
//
//示例 1:
//输入: [1,1,2,3,3,4,4,8,8]
//输出: 2
//
//示例 2:
//输入: [3,3,7,7,10,11,11]
//输出: 10
//
//注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。
//
//思路：不能用位运算。考虑二分查找
//1）数组有序，意味着相同的元素紧挨在一起
//2）说明只出现一次的数一定在一个奇数区间中
//3）二分
//*/
//int singleNonDuplicate(const vector<int> &nums)
//{
//    int left = 0, right = nums.size() - 1;
//    while (left < right)
//    {
//        int mid = (left + right) / 2;
//        if (mid - 1 >= left && nums[mid] == nums[mid - 1])
//        {
//            if ((mid - left + 1) % 2 == 0)
//                left = mid + 1;
//            else
//                right = mid;
//        }
//        else if (mid + 1 <= right && nums[mid] == nums[mid + 1])
//        {
//            if ((right - mid + 1) % 2 == 0)
//                right = mid - 1;
//            else
//                left = mid;
//        }
//        else
//            return nums[mid];
//    }
//    return nums[left];
//}
//
///*
//给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
//两个相邻元素间的距离为 1 。
//
//示例 1:
//输入:
//0 0 0
//0 1 0
//0 0 0
//输出:
//0 0 0
//0 1 0
//0 0 0
//
//示例 2:
//输入:
//0 0 0
//0 1 0
//1 1 1
//输出:
//0 0 0
//0 1 0
//1 2 1
//
//注意:
//给定矩阵的元素个数不超过 10000。
//给定矩阵中至少有一个元素是 0。
//矩阵中的元素只在四个方向上相邻: 上、下、左、右。
//
//思路：深搜
//1）先把那些与0直接相邻的1找出来，并标记为-1
//2）把那些不与0直接相邻的1找出来标记为-2
//3）然后针对每一个-1，从它开始，递归更新那些不与0直接相邻的1：
//    a.如果为-2，更新距离值
//    b.如果当前距离值比原来更大，返回
//    c.如果当前距离值比原来更小，更新距离值为当前距离值
//4）最后把所有-1替换回1
//*/
//bool checkZeroAdj(const vector<vector<int>> &matrix, const vector<vector<int>> &cords, const int &rows, const int &cols, int row, int col)
//{
//    // 判断当前的1是否有0直接和它相连
//    for (const auto &cord : cords)
//    {
//        int r = row + cord[0], c = col + cord[1];
//        if (r < 0 || r > rows - 1 || c < 0 || c > cols - 1)
//            continue;
//        if (matrix[r][c] == 0)
//            return true;
//    }
//    return false;
//}
//void updateMatrixRecursively(vector<vector<int>> &res, const vector<vector<int>> &cords, const int &rows, const int &cols, int row, int col, int cnt)
//{
//    if (row < 0 || row > rows - 1 || col < 0 || col > cols - 1)
//        return;
//
//    if (res[row][col] == 0 || res[row][col] == -1)
//        return;
//
//    // 如果当前距离值比原来更大，返回
//    if (res[row][col] != -2 && cnt >= res[row][col])
//        return;
//
//    // 如果为-2，更新距离值
//    // 如果当前距离值比原来更小，更新距离值为当前距离值
//    res[row][col] = cnt;
//    for (const auto &cord : cords)
//    {
//        int r = row + cord[0], c = col + cord[1];
//        updateMatrixRecursively(res, cords, rows, cols, r, c, cnt + 1);
//    }
//}
//vector<vector<int>> updateMatrix(const vector<vector<int>> &matrix)
//{
//    int rows = matrix.size();
//    if (rows == 0)
//        return matrix;
//    int cols = matrix[0].size();
//    if (cols == 0)
//        return matrix;
//
//    static const vector<vector<int>> cords = {{-1, 0}, {0 ,1}, {1, 0}, {0, -1}};
//    vector<vector<int>> res(rows, vector<int>(cols, 0));
//    for (int row = 0; row < rows; row++)
//        for (int col = 0; col < cols; col++)
//            if (matrix[row][col] == 1)
//            {
//                // 先把那些与0直接相邻的1找出来，并标记为-1
//                if (checkZeroAdj(matrix, cords, rows, cols, row, col))
//                    res[row][col] = -1;
//                // 把那些不与0直接相邻的1找出来标记为-2
//                else
//                    res[row][col] = -2;
//            }
//
//    for (int row = 0; row < rows; row++)
//        for (int col = 0; col < cols; col++)
//            if (res[row][col] == -1)
//            {
//                // 递归更新那些不与0直接相邻的1
//                for (const auto &cord : cords)
//                {
//                    int r = row + cord[0], c = col + cord[1];
//                    updateMatrixRecursively(res, cords, rows, cols, r, c, 2);
//                }
//            }
//    // 把所有-1替换回1
//    for (int row = 0; row < rows; row++)
//        for (int col = 0; col < cols; col++)
//            if (res[row][col] == -1)
//                res[row][col] = 1;
//
//    return res;
//}
//
//// 思路2：动态规划
//vector<vector<int>> updateMatrix2(const vector<vector<int>> &matrix)
//{
//    int rows = matrix.size();
//    if (rows == 0)
//        return matrix;
//    int cols = matrix[0].size();
//    if (cols == 0)
//        return matrix;
//
//    vector<vector<int>> res(rows, vector<int>(cols, INT_MAX - 1));
//    // 计算左上
//    for (int i = 0; i < rows; i++)
//        for (int j = 0; j < cols; j++)
//        {
//            if (matrix[i][j] == 0)
//                res[i][j] = 0;
//            else
//            {
//                if (i > 0)
//                    res[i][j] = std::min(res[i][j], res[i - 1][j] + 1);
//                if (j > 0)
//                    res[i][j] = std::min(res[i][j], res[i][j - 1] + 1);
//            }
//        }
//    // 计算右下
//    for (int i = rows - 1; i >= 0; i--)
//        for (int j = cols - 1; j >= 0; j--)
//        {
//            if (matrix[i][j] != 0)
//            {
//                if (i < rows - 1)
//                    res[i][j] = std::min(res[i][j], res[i + 1][j] + 1);
//                if (j < cols - 1)
//                    res[i][j] = std::min(res[i][j], res[i][j + 1] + 1);
//            }
//        }
//
//    return res;
//}
//// 思路3：广搜
//vector<vector<int>> updateMatrix3(const vector<vector<int>> &matrix)
//{
//    int rows = matrix.size();
//    if (rows == 0)
//        return matrix;
//    int cols = matrix[0].size();
//    if (cols == 0)
//        return matrix;
//
//    static const vector<vector<int>> cords = {{-1, 0}, {0 ,1}, {1, 0}, {0, -1}};
//    queue<pair<int, int>> q;
//    vector<vector<int>> res(rows, vector<int>(cols, 0));
//    for (int i = 0; i < rows; ++i)
//        for (int j = 0; j < cols; ++j)
//            if (matrix[i][j] == 0) // 将所有0的坐标加入队列
//                q.push(make_pair(i, j));
//            else
//                res[i][j] = INT_MAX;
//
//    while (!q.empty()) // 广搜
//    {
//        pair<int, int> cor = q.front(); 
//        q.pop();
//        for (int k = 0; k < 4; ++k)
//        {
//            int y = cor.first + cords[k][0];
//            int x = cor.second + cords[k][1];
//            if (y < 0 || x < 0 || y >= rows || x >= cols || res[y][x] <= res[cor.first][cor.second])
//                continue;
//            res[y][x] = res[cor.first][cor.second] + 1;
//            q.push(make_pair(y, x));
//        }
//    }
//    return res;
//}

///*
//547.朋友圈
//班上有 N 名学生。
//其中有些人是朋友，有些则不是。
//他们的友谊具有是传递性。
//如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。
//所谓的朋友圈，是指所有朋友的集合。
//给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
//如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
//你必须输出所有学生中的已知的朋友圈总数。
//
//示例 1:
//输入:
//[[1,1,0],
// [1,1,0],
// [0,0,1]]
//输出: 2
//说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
//第2个学生自己在一个朋友圈。所以返回2。
//
//示例 2:
//输入:
//[[1,1,0],
// [1,1,1],
// [0,1,1]]
//输出: 1
//说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
//
//注意：
//N 在[1,200]的范围内。
//对于所有学生，有M[i][i] = 1。
//如果有M[i][j] = 1，则有M[j][i] = 1。
//
//思路：传递闭包（Floyd-Warshall算法），时间复杂度O(n^3)
//*/
//int findCircleNum(vector<vector<int>> &M)
//{
//    int N = M.size();
//    if (N == 1)
//        return 1;
//
//    for (int k = 0; k < N; k++)
//    {
//        for (int i = 0; i < N; i++)
//        {
//            for (int j = 0; j < N; j++)
//            {
//                if (M[i][j] == 1 || (M[i][k] == 1 && M[k][j] == 1))
//                    M[i][j] = 1;
//            }
//        }
//    }
//
//    vector<bool> visited(N, false);
//    int res = 0;
//    for (int i = 0; i < N; i++)
//    {
//        if (visited[i])
//            continue;
//        visited[i] = true;
//        for (int j = i + 1; j < N; j++)
//        {
//            if (visited[j])
//                continue;
//            if (M[i][j] == 1)
//                visited[j] = true;
//        }
//        ++res;
//    }
//    return res;
//}
///*
//思路2：递归深搜（比思路1要快）
//*/
//void findCircleNumRecursively(const vector<vector<int>> &M, vector<bool> &visited, int i)
//{
//    for (int j = 0; j < visited.size(); j++)
//    {
//        if (!visited[j] && M[i][j] == 1)
//        {
//            visited[j] = true;
//            findCircleNumRecursively(M, visited, j);
//        }
//    }
//}
//int findCircleNum2(vector<vector<int>> &M)
//{
//    int N = M.size();
//    if (N == 1)
//        return 1;
//
//    vector<bool> visited(N, false);
//    int res = 0;
//    for (int i = 0; i < N; i++)
//    {
//        if (!visited[i])
//        {
//            visited[i] = true;
//            findCircleNumRecursively(M, visited, i);
//            ++res;
//        }
//    }
//    return res;
//}
///*
//思路3：并查集（union-find set）
//https://www.cnblogs.com/cyjb/p/UnionFindSets.html
//*/
//int usetFind(vector<int> &uset, int i)
//{
//    int root = i;
//    while (root != uset[root]) // 找到i所在朋友圈的根
//        root = uset[root];
//    int parent;
//    while (i != root) // 压缩路径，令每个子节点直接指向根
//    {
//        parent = uset[i]; // 保存当前节点的父节点
//        uset[i] = root; // 当前节点的父节点直接指向根
//        i = parent; // 处理保存的父节点
//    }
//    return root;
//}
//void usetUnion(vector<int> &uset, vector<int> &rank, int i, int j, int &res)
//{
//    // 分别找到i和j所在朋友圈的根
//    int root_i = usetFind(uset, i);
//    int root_j = usetFind(uset, j);
//
//    // 如果根不同，说明不在同一个朋友圈，那么将他们所在朋友圈合并成一个
//    if (root_i != root_j)
//    {
//        // 将深度小的合并到深度大的
//        if (rank[root_i] > rank[root_j])
//            uset[root_j] = root_i;
//        else
//        {
//            uset[root_i] = root_j;
//            if (rank[root_i] == rank[root_j])
//                ++rank[root_j];
//        }
//        --res; // 合并后朋友圈个数少一个
//    }
//}
//int findCircleNum3(vector<vector<int>> &M)
//{
//    int N = M.size();
//    if (N == 1)
//        return 1;
//
//    vector<int> uset; // 并查集
//    uset.reserve(N);
//    for (int i = 0; i < N; i++) // 初始时每个人一个朋友圈，每个人都是自己朋友圈的根
//        uset.push_back(i);
//    vector<int> rank(N, 0); // 代表每个朋友圈的深度
//
//    int res = N;
//    // 遍历矩阵的右上角或左下角就行了
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = i + 1; j < N; j++)
//        {
//            // 将i和j所在的朋友圈合并
//            if (M[i][j] == 1)
//                usetUnion(uset, rank, i, j, res);
//        }
//    }
//    return res;
//}
//
///*
//553.做优除法
//给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。
//但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。
//你需要找出怎么添加括号，才能得到最大的结果，并且返回相应的字符串格式的表达式。你的表达式不应该含有冗余的括号。
//
//示例：
//输入: [1000,100,10,2]
//输出: "1000/(100/10/2)"
//解释:
//1000/(100/10/2) = 1000/((100/10)/2) = 200
//但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
//因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。
//其他用例:
//1000/(100/10)/2 = 50
//1000/(100/(10/2)) = 50
//1000/100/10/2 = 0.5
//1000/100/(10/2) = 2
//
//说明:
//输入数组的长度在 [1, 10] 之间。
//数组中每个元素的大小都在 [2, 1000] 之间。
//每个测试用例只有一个最优除法解。
//
//思路：水题（要使结果最大，分母最大，分子最小，那么把除第一个数后面的数括起来就行）
//*/
//string optimalDivision(const vector<int> &nums)
//{
//    int length = nums.size();
//    if (length == 1)
//        return std::to_string(nums[0]);
//    if (length == 2)
//        return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);
//
//    ostringstream oss;
//    oss << nums[0] << "/(" << nums[1];
//    for (int i = 2; i < length; i++)
//        oss << '/' << nums[i];
//    oss << ')';
//    return oss.str();
//}

///*
//554.砖墙
//你的面前有一堵方形的、由多行砖块组成的砖墙。 
//这些砖块高度相同但是宽度不同。
//你现在要画一条自顶向下的、穿过最少砖块的垂线。
//砖墙由行的列表表示。
//每一行都是一个代表从左至右每块砖的宽度的整数列表。
//如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。
//你需要找出怎样画才能使这条线穿过的砖块数量最少，并且返回穿过的砖块数量。
//你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。
//
//示例：
//输入: [[1,2,2,1],
//      [3,1,2],
//      [1,3,2],
//      [2,4],
//      [3,1,2],
//      [1,3,1,1]]
//输出: 2
//
//提示：
//每一行砖块的宽度之和应该相等，并且不能超过 INT_MAX。
//每一行砖块的数量在 [1,10,000] 范围内， 墙的高度在 [1,10,000] 范围内， 总的砖块数量不超过 20,000。
//
//思路：
//1）统计每一行砖块累加的宽度
//2）找出具有相同宽度的最大行数
//3）穿过最少=总行数-最大行数
//*/
//int leastBricks(const vector<vector<int>> &wall)
//{
//    int rows = wall.size();
//
//    unordered_map<int, int> width_cnt;
//    for (int row = 0; row < rows; row++)
//    {
//        int cols = wall[row].size();
//        if (cols == 1) // 该行只有一块砖，因为垂线不能在两端，所以不统计
//            continue;
//
//        // 统计每一行累加宽度
//        int width = wall[row][0];
//        ++width_cnt[width];
//        for (int col = 1; col < cols - 1; col++)
//        {
//            width += wall[row][col];
//            ++width_cnt[width];
//        }
//    }
//
//    // 为空说明每一行只有一块砖，因为垂线不能在两端，所以需要穿过所有行
//    if (width_cnt.empty())
//        return rows;
//
//    // 找出最多行数
//    int max_cnt = std::numeric_limits<int>::min();
//    for (const auto &wc : width_cnt)
//    {
//        if (wc.second > max_cnt)
//            max_cnt = wc.second;
//    }
//
//    return rows - max_cnt;
//}
//
///*
//556. 下一个更大元素 III
//给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。
//如果不存在这样的32位整数，则返回-1。
//
//示例 1:
//输入: 12
//输出: 21
//
//示例 2:
//输入: 21
//输出: -1
//
//思路：
//1）将整数转换成字符串
//2）求该字符串的下一个排列
//3）转换成整数，判断是否符合要求
//*/
//int nextGreaterElement(int n)
//{
//    if (n >= 0 && n <= 9)
//        return -1;
//
//    string s = std::to_string(n);
//    if (next_permutation(s.begin(), s.end()))
//    {
//        long long t = std::stoll(s);
//        if (t > std::numeric_limits<int>::max())
//            return -1;
//        if (t > n)
//            return t;
//    }
//    return -1;
//}
//// 不使用库函数
//int nextGreaterElement2(int n)
//{
//    if (n >= 0 && n <= 9)
//        return -1;
//
//    string s = std::to_string(n);
//    int length = s.size();
//    for (int i = length - 2; i >= 0; i--)
//    {
//        if (s[i] < s[i + 1]) // 从后往前寻找 后一个数大于前一个数 的数对s[i],s[i+1]
//        {
//            for (int j = length - 1; j > i; j--) 
//            {
//                if (s[j] > s[i]) // 从后往前寻找第一个大于s[i]的数s[j]
//                {
//                    std::swap(s[j], s[i]); // 交换s[i]和s[j]
//                    std::reverse(s.begin() + i + 1, s.end()); // 翻转区间[i+1,end)
//                    long long t = std::stoll(s);
//                    if (t > std::numeric_limits<int>::max())
//                        return -1;
//                    if (t > n)
//                        return t;
//                }
//            }
//        }
//    }
//    return -1;
//}

///*
//560. 和为K的子数组
//给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
//
//示例 1 :
//输入:nums = [1,1,1], k = 2
//输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
//
//说明 :
//数组的长度为 [1, 20,000]。
//数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
//
//思路：二维数组保存之前子数组的和（超内存）
//*/
//int subarraySum(const vector<int> &nums, int k)
//{
//    int length = nums.size();
//    if (length == 1 && nums[0] != k)
//        return 0;
//
//    int res = 0;
//    vector<vector<int>> dp(length, vector<int>(length, 0));
//    for (int i = 0; i < length; i++)
//    {
//        dp[i][i] = nums[i];
//        if (dp[i][i] == k)
//            ++res;
//    }
//
//    for (int len = 2; len <= length; len++)
//    {
//        for (int stop = length - 1; stop - len + 1 >= 0; stop--)
//        {
//            dp[stop - len + 1][stop] = dp[stop - len + 1][stop - 1] + nums[stop];
//            if (dp[stop - len + 1][stop] == k)
//                ++res;
//        }
//    }
//
//    return res;
//}
//// 思路2：一维数组保存之前子数组的和（通过，但是运行时间长）
//int subarraySum2(const vector<int> &nums, int k)
//{
//    int length = nums.size();
//    if (length == 1 && nums[0] != k)
//        return 0;
//
//    int res = 0;
//    vector<int> sums(length + 1, 0);
//    for (int i = 1; i <= length; i++)
//        sums[i] = sums[i - 1] + nums[i - 1];
//
//    for (int start = 0; start < length; start++)
//    {
//        for (int stop = start; stop < length; stop++)
//        {
//            if (sums[stop + 1] - sums[start] == k)
//                ++res;
//        }
//    }
//
//    return res;
//}
///*
//思路3：
//1）设sum[i]表示[0,i]的总和，那么如果sum[j]-sum[i]==k，0<=i<=j<=length-1，说明[i+1,j]的和为k
//2）变换一下，如果sum[j]-k==sum[i]，也说明[i+1,j]的和为k
//3）那么用一个哈希表m存储:（到目前为止的总和，总和出现的次数）
//4）计算完当前总和sum后，在m中寻找sum-k，如果找到，结果加上sum-k出现的次数
//*/
//int subarraySum3(const vector<int> &nums, int k)
//{
//    unordered_map<int, int> m;
//    m[0] = 1;
//    int res = 0, sum = 0;
//    for (int num : nums)
//    {
//        sum += num;
//        if (m.count(sum - k))
//            res += m[sum - k];
//        ++m[sum];
//    }
//    return res;
//}
//
///*
//565. 数组嵌套
//索引从0开始长度为N的数组A，包含0到N - 1的所有整数。
//找到并返回最大的集合S，S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。
//假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。
//
//示例 1:
//输入: A = [5,4,0,3,1,6,2]
//输出: 4
//解释:
//A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
//其中一种最长的 S[K]:
//S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
//
//注意:
//N是[1, 20,000]之间的整数。
//A中不含有重复的元素。
//A中的元素大小在[0, N-1]之间。
//
//思路：用一个标记数组标记已经访问过的循环
//*/
//int arrayNesting(const vector<int> &nums)
//{
//    int length = nums.size();
//    if (length == 0)
//        return 0;
//
//    vector<bool> visited(length, false);
//    int res = std::numeric_limits<int>::min();
//    for (int i = 0; i < length; i++)
//    {
//        if (visited[i])
//            continue;
//
//        int cnt = 1;
//        int t = nums[i];
//        visited[i] = true;
//        while (t != i)
//        {
//            visited[t] = true;
//            t = nums[t];
//            ++cnt;
//        }
//        if (cnt > res)
//            res = cnt;
//    }
//
//    return res;
//}
//// 思路2：优化空间，直接在原数组上标记
//int arrayNesting2(vector<int> &nums)
//{
//    int length = nums.size();
//    if (length == 0)
//        return 0;
//
//    int res = std::numeric_limits<int>::min();
//    for (int i = 0; i < length; i++)
//    {
//        if (nums[i] == -1)
//            continue;
//
//        int cnt = 1;
//        int t = nums[i];
//        nums[i] = -1;
//        while (t != i)
//        {
//            int tt = t;
//            t = nums[t];
//            nums[tt] = -1;
//            ++cnt;
//        }
//        if (cnt > res)
//            res = cnt;
//    }
//
//    return res;
//}

///*
//567. 字符串的排列
//给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
//换句话说，第一个字符串的排列之一是第二个字符串的子串。
//
//示例1
//输入: s1 = "ab" s2 = "eidbaooo"
//输出: True
//解释: s2 包含 s1 的排列之一 ("ba").
//
//示例2:
//输入: s1= "ab" s2 = "eidboaoo"
//输出: False
//
//注意：
//输入的字符串只包含小写字母
//两个字符串的长度都在 [1, 10,000] 之间
//
//思路：哈希统计s1各个字符出现的频率，然后在s2中滑动窗口寻找即可
//*/
//bool checkInclusion(const string s1, const string s2)
//{
//    int length1 = s1.size();
//    int length2 = s2.size();
//    if (length1 == length2 && length1 == 1)
//    {
//        if (s1[0] == s2[0])
//            return true;
//        return false;
//    }
//    if (length1 > length2)
//        return false;
//
//    vector<int> m1(26, 0);
//    vector<int> m2(26, 0);
//    // 统计s1和初始的s2滑动窗口中的字符频率
//    for (int i = 0; i < length1; i++)
//    {
//        ++m1[s1[i] - 'a'];
//        ++m2[s2[i] - 'a'];
//    }
//
//    if (m1 == m2)
//        return true;
//
//    // 滑动窗口进行匹配（每次进入一个新字符和退出一个旧字符）
//    for (int stop = length1; stop < length2; stop++)
//    {
//        --m2[s2[stop - length1] - 'a'];
//        ++m2[s2[stop] - 'a'];
//        if (m1 == m2)
//            return true;
//    }
//    return false;
//}
//// 思路2：优化匹配时间
//bool checkInclusion2(const string s1, const string s2)
//{
//    int length1 = s1.size();
//    int length2 = s2.size();
//    if (length1 == length2 && length1 == 1)
//    {
//        if (s1[0] == s2[0])
//            return true;
//        return false;
//    }
//    if (length1 > length2)
//        return false;
//
//    vector<int> m1(26, 0);
//    vector<int> m2(26, 0);
//    for (int i = 0; i < length1; i++)
//    {
//        ++m1[s1[i] - 'a'];
//        ++m2[s2[i] - 'a'];
//    }
//
//    int cnt = 0; // 表示有多少个字符的频率是匹配的
//    for (int i = 0; i < 26; i++)
//        if (m1[i] == m2[i])
//            ++cnt;
//
//    for (int stop = length1; stop < length2; stop++)
//    {
//        if (cnt == 26) // 26个字符的频率都匹配，返回true
//            return true;
//
//        int in = s2[stop] - 'a'; // 当前要进入滑动窗口的字符
//        int out = s2[stop - length1] - 'a'; // 当前要退出滑动窗口的字符
//
//        ++m2[in];
//        if (m2[in] == m1[in]) // 进入的字符使得新的字符频率匹配了
//            ++cnt;
//        else if (m2[in] == m1[in] + 1) // 进入的字符使得原来匹配的字符频率不匹配了
//            --cnt;
//
//        --m2[out];
//        if (m2[out] == m1[out]) // 退出的字符使得新的字符频率匹配了
//            ++cnt;
//        else if (m2[out] == m1[out] - 1) // 退出的字符使得原来匹配的字符频率不匹配了
//            --cnt;
//    }
//    return cnt == 26;
//}
//
///*
//576.出界的路径
//给定一个 m × n 的网格和一个球。
//球的起始坐标为 (i,j) ，你可以将球移到相邻的单元格内，或者往上、下、左、右四个方向上移动使球穿过网格边界。
//但是，你最多可以移动 N 次。找出可以将球移出边界的路径数量。
//答案可能非常大，返回 结果 mod 109 + 7 的值。
//
//示例 1：
//输入: m = 2, n = 2, N = 2, i = 0, j = 0
//输出: 6
//
//示例 2：
//输入: m = 1, n = 3, N = 3, i = 0, j = 1
//输出: 12
//
//说明:
//球一旦出界，就不能再被移动回网格内。
//网格的长度和高度在 [1,50] 的范围内。
//N 在 [0,50] 的范围内。
//
//思路：动态规划（https://leetcode-cn.com/problems/out-of-boundary-paths/solution/chu-jie-de-lu-jing-shu-by-leetcode/）
//*/
//int findPaths(int m, int n, int N, int i, int j)
//{
//    if (N == 0)
//        return 0;
//
//    // 宽高各加2方便处理边界值
//    vector<vector<vector<long>>> dp(N, vector<vector<long>>(m + 2, vector<long>(n + 2, 0)));
//
//    // 初始点(i,j)变成了(i+1,j+1)，并且移动0次最多有一种移法
//    dp[0][i + 1][j + 1] = 1;
//
//    // 当初始点在边界的时候，移动一次的结果
//    long res = 0;
//    if (i == 0)
//        res++;
//    if (i == m - 1)
//        res++;
//    if (j == 0)
//        res++;
//    if (j == n - 1)
//        res++;
//
//    for (int t = 1; t < N; t++) // 移动一次已经处理，还可以移动N-1次
//    {
//        for (int mi = 1; mi <= m; mi++)
//        {
//            for (int ni = 1; ni <= n; ni++)
//            {
//                // 递推关系式
//                dp[t][mi][ni] = dp[t - 1][mi - 1][ni] + dp[t - 1][mi + 1][ni]
//                    + dp[t - 1][mi][ni - 1] + dp[t - 1][mi][ni + 1];
//                dp[t][mi][ni] %= 1000000007;
//
//                // 处理边界情况
//                if (mi == 1)
//                    res += dp[t][mi][ni];
//                if (mi == m)
//                    res += dp[t][mi][ni];
//                if (ni == 1)
//                    res += dp[t][mi][ni];
//                if (ni == n)
//                    res += dp[t][mi][ni];
//                res %= 1000000007;
//            }
//        }
//    }
//    return static_cast<int>(res);
//}

///*
//583.两个字符串的删除操作
//给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
//
//示例 1:
//输入: "sea", "eat"
//输出: 2
//解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
//
//说明:
//给定单词的长度不超过500。
//给定单词中的字符只含有小写字母。
//
//思路：广度优先搜索（超时）
//*/
//int minDistance(const string &word1, const string &word2)
//{
//    if (word1 == word2)
//        return 0;
//
//    int len1 = word1.size(), len2 = word2.size();
//    if (len1 == 0)
//        return len2;
//    if (len2 == 0)
//        return len1;
//
//    int steps = 0;
//    string t1 = word1, t2 = word2;
//    if (len1 < len2)
//    {
//        t1.swap(t2);
//        std::swap(len1, len2);
//    }
//
//    unordered_set<string> s1;
//    for (int i = 0; i < len1; i++)
//        s1.insert(t1.substr(0, i) + t1.substr(i + 1));
//    ++steps;
//
//    while (len1 - steps >= len2)
//    {
//        if (len1 - steps == len2 && s1.count(t2))
//            return steps;
//
//        unordered_set<string> s_t;
//        for (const auto &s : s1)
//        {
//            for (int i = 0; i < s.size(); i++)
//            {
//                s_t.insert(s.substr(0, i) + s.substr(i + 1));
//            }
//        }
//        s1 = std::move(s_t);
//
//        ++steps;
//    }
//
//    unordered_set<string> s2;
//    for (int i = 0; i < len2; i++)
//        s2.insert(t2.substr(0, i) + t2.substr(i + 1));
//    ++steps;
//
//    while (steps < len1 + len2)
//    {
//        unordered_set<string> s1_t;
//        for (const auto &s : s1)
//        {
//            if (s2.count(s))
//                return steps;
//            for (int i = 0; i < s.size(); i++)
//            {
//                s1_t.insert(s.substr(0, i) + s.substr(i + 1));
//            }
//        }
//        s1 = std::move(s1_t);
//        ++steps;
//
//        unordered_set<string> s2_t;
//        for (const auto &s : s2)
//        {
//            for (int i = 0; i < s.size(); i++)
//            {
//                s2_t.insert(s.substr(0, i) + s.substr(i + 1));
//            }
//        }
//        s2 = std::move(s2_t);
//        ++steps;
//    }
//
//    return steps;
//}
//// 思路2：最长公共子序列
//int minDistance2(const string &word1, const string &word2)
//{
//    if (word1 == word2)
//        return 0;
//
//    int len1 = word1.size(), len2 = word2.size();
//    if (len1 == 0)
//        return len2;
//    if (len2 == 0)
//        return len1;
//
//    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
//    for (int i = 1; i <= len1; i++)
//    {
//        for (int j = 1; j <= len2; j++)
//        {
//            if (word1[i - 1] == word2[j - 1])
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//            else
//                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
//        }
//    }
//    return len1 + len2 - 2 * dp[len1][len2];
//}
///* 
//思路3：
//1）dp[i][j]直接表示两个字符串分别到i和j时，最小删除的字符数（步数）
//2）递推式：
//    a.dp[i][j]=dp[i-1][j-1], s1[i-1]==s2[j-1]（字符相等，那么不删除）
//    b.dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1, s1[i-1]!=s2[j-1]（字符不等，要删除，选一个步数小的，然后+1表示删除了）
//3）由于每次只用到了上次的，所以可以优化空间
//*/
//int minDistance3(const string &word1, const string &word2)
//{
//    if (word1 == word2)
//        return 0;
//
//    int len1 = word1.size(), len2 = word2.size();
//    if (len1 == 0)
//        return len2;
//    if (len2 == 0)
//        return len1;
//
//    vector<int> dp(len2 + 1);
//    for (int i = 0; i <= len2; i++)
//        dp[i] = i;
//    for (int i = 1; i <= len1; i++)
//    {
//        vector<int> t(len2 + 1, 0);
//        t[0] = i;
//        for (int j = 1; j <= len2; j++)
//        {
//            if (word1[i - 1] == word2[j - 1])
//                t[j] = dp[j - 1];
//            else
//                t[j] = std::min(dp[j], t[j - 1]) + 1;
//        }
//        dp = std::move(t);
//    }
//    return dp[len2];
//}
//
///*
//592. 分数加减运算
//给定一个表示分数加减运算表达式的字符串，你需要返回一个字符串形式的计算结果。 
//这个结果应该是不可约分的分数，即最简分数。 
//如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。
//所以在上述例子中, 2 应该被转换为 2/1。
//
//示例 1:
//输入:"-1/2+1/2"
//输出: "0/1"
//
// 示例 2:
//输入:"-1/2+1/2+1/3"
//输出: "1/3"
//
//示例 3:
//输入:"1/3-1/2"
//输出: "-1/6"
//
//示例 4:
//输入:"5/3+1/3"
//输出: "2/1"
//
//说明:
//输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。 
//输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，则 '+' 会被省略掉。
//输入只包含合法的最简分数，每个分数的分子与分母的范围是  [1,10]。 如果分母是1，意味着这个分数实际上是一个整数。
//输入的分数个数范围是 [1,10]。
//最终结果的分子与分母保证是 32 位整数范围内的有效整数。
//*/
//class Fraction
//{
//public:
//    int numerator_, denominator_;
//
//    Fraction() : numerator_(0), denominator_(1) {}
//    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {}
//
//    Fraction operator+(Fraction rhs)
//    {
//        if (rhs.numerator_ == 0)
//            return *this;
//        if (this->numerator_ == 0)
//            return rhs;
//
//        if (rhs.denominator_ == this->denominator_)
//        {
//            int numerator = rhs.numerator_ + this->numerator_;
//            int denominator = this->denominator_;
//            if (numerator % denominator == 0)
//            {
//                numerator = numerator / denominator;
//                denominator = 1;
//            }
//            return Fraction{numerator, denominator};
//        }
//        else
//        {
//            int numerator = this->numerator_ * rhs.denominator_ + rhs.numerator_ * this->denominator_;
//            int denominator = rhs.denominator_ * this->denominator_;
//            if (numerator % denominator == 0)
//            {
//                numerator = numerator / denominator;
//                denominator = 1;
//            }
//            return Fraction{numerator, denominator};
//        }
//    }
//};
//
//string fractionAddition(const string &expression)
//{
//    int length = expression.size();
//    if (length == 0)
//        return {};
//
//    Fraction sum;
//    bool is_neg = false;
//    int idx = 0;
//    if (expression[idx] == '-')
//    {
//        is_neg = true;
//        ++idx;
//    }
//    while (idx < length)
//    {
//        int numerator = 0;
//        while (expression[idx] != '/')
//        {
//            numerator = numerator * 10 + (expression[idx] - '0');
//            ++idx;
//        }
//        ++idx;
//        
//        int denominator = 0;
//        while (idx < length && !(expression[idx] == '+' || expression[idx] == '-'))
//        {
//            denominator = denominator * 10 + (expression[idx] - '0');
//            ++idx;
//        }
//
//        if (is_neg)
//            sum = sum + Fraction{-1 * numerator, denominator};
//        else
//            sum = sum + Fraction{numerator, denominator};
//        
//        if (idx >= length)
//            break;
//
//        if (expression[idx] == '-')
//            is_neg = true;
//        else
//            is_neg = false;
//        ++idx;
//    }
//
//    auto gcd = [](int a, int b)
//    {
//        int t;
//        while (b != 0)
//        {
//            t = a % b;
//            a = b;
//            b = t;
//        }
//        return a;
//    };
//
//    int t = gcd(std::abs(sum.numerator_), sum.denominator_);
//    return std::to_string(sum.numerator_ / t) + '/' + std::to_string(sum.denominator_ / t);
//}

///*
//593. 有效的正方形
//给定二维空间中四点的坐标，返回四点是否可以构造一个正方形。
//一个点的坐标（x，y）由一个有两个整数的整数数组表示。
//
//示例:
//输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
//输出: True
//
//注意:
//所有输入整数都在 [-10000，10000] 范围内。
//一个有效的正方形有四个等长的正长和四个等角（90度角）。
//输入点没有顺序。
//*/
//bool validSquare(const vector<int> &p1, const vector<int> &p2, const vector<int> &p3, const vector<int> &p4)
//{
//    set<long long> lens;
//
//    vector<vector<int>> pts = {p1, p2, p3, p4};
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = i + 1; j < 4; j++)
//        {
//            lens.insert(static_cast<long long>((pts[i][0] - pts[j][0])) * (pts[i][0] - pts[j][0]) 
//                        + static_cast<long long>((pts[i][1] - pts[j][1])) * (pts[i][1] - pts[j][1]));
//        }
//    }
//
//    vector<long long> lens_(lens.begin(), lens.end());
//    if (lens_.size() != 2)
//        return false;
//    if (lens_[0] * 2 != lens_[1])
//        return false;
//    return true;
//}
//
///*
//给定一个目录信息列表，包括目录路径，以及该目录中的所有包含内容的文件，您需要找到文件系统中的所有重复文件组的路径。
//一组重复的文件至少包括二个具有完全相同内容的文件。
//
//输入列表中的单个目录信息字符串的格式如下：
//"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
//这意味着有 n 个文件（f1.txt, f2.txt ... fn.txt 的内容分别是 f1_content, f2_content ... fn_content）在目录 root/d1/d2/.../dm 下。
//注意：n>=1 且 m>=0。如果 m=0，则表示该目录是根目录。
//该输出是重复文件路径组的列表。对于每个组，它包含具有相同内容的文件的所有文件路径。文件路径是具有下列格式的字符串：
//"directory_path/file_name.txt"
//
//示例 1：
//输入：
//["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
//输出：
//[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
//
//注：
//最终输出不需要顺序。
//您可以假设目录名、文件名和文件内容只有字母和数字，并且文件内容的长度在 [1，50] 的范围内。
//给定的文件数量在 [1，20000] 个范围内。
//您可以假设在同一目录中没有任何文件或目录共享相同的名称。
//您可以假设每个给定的目录信息代表一个唯一的目录。目录路径和文件信息用一个空格分隔。
//
//超越竞赛的后续行动：
//假设您有一个真正的文件系统，您将如何搜索文件？广度搜索还是宽度搜索？
//如果文件内容非常大（GB级别），您将如何修改您的解决方案？
//如果每次只能读取 1 kb 的文件，您将如何修改解决方案？
//修改后的解决方案的时间复杂度是多少？其中最耗时的部分和消耗内存的部分是什么？如何优化？
//如何确保您发现的重复文件不是误报？
//*/
//vector<vector<string>> findDuplicate(const vector<string> &paths)
//{
//    int length = paths.size();
//    if (length == 0)
//        return {};
//
//    unordered_map<string, vector<string>> content_names;
//    for (const auto &path : paths)
//    {
//        vector<string> parts;
//        istringstream iss(path);
//        string part;
//        while (iss >> part)
//            parts.push_back(std::move(part));
//        const string &dir_name = parts.front();
//        for (int i = 1; i < parts.size(); i++)
//        {
//            auto idx = parts[i].find_first_of('(');
//            content_names[parts[i].substr(idx + 1, parts[i].size() - (idx + 1) - 1)]
//                .push_back(dir_name + '/' + parts[i].substr(0, idx));
//        }
//    }
//
//    vector<vector<string>> res;
//    for (auto &kv : content_names)
//    {
//        if (kv.second.size() > 1)
//            res.push_back(std::move(kv.second));
//    }
//    return res;
//}

///*
//611.有效三角形的个数
//给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。
//
//示例 1:
//输入: [2,2,3,4]
//输出: 3
//解释:
//有效的组合是:
//2,3,4 (使用第一个 2)
//2,3,4 (使用第二个 2)
//2,2,3
//
//注意:
//数组长度不超过1000。
//数组里整数的范围为 [0, 1000]。
//
//思路：暴力法（超时）
//*/
//int triangleNumber(vector<int> &nums)
//{
//    int len = nums.size();
//    if (len < 3)
//        return 0;
//
//    auto isTri = [](int a, int b, int c)
//    {
//        if (a + b > c && a + c > b && b + c > a)
//            return true;
//        return false;
//    };
//
//    int res = 0;
//    for (int i = 0; i + 2 < len; i++)
//    {
//        for (int j = i + 1; j + 1 < len; j++)
//        {
//            for (int k = j + 1; k < len; k++)
//            {
//                if (isTri(nums[i], nums[j], nums[k]))
//                    ++res;
//            }
//        }
//    }
//
//    return res;
//}
///*
//思路2：
//1）升序排序
//2）排好序的a,b,c，当且仅当啊+b>c时构成三角形
//3）固定两条边，二分查找第三条边
//*/
//int triangleNumber2(vector<int> &nums)
//{
//    int len = nums.size();
//    if (len < 3)
//        return 0;
//
//    std::sort(nums.begin(), nums.end());
//
//    int res = 0;
//    for (int i = 0; i + 2 < len; i++)
//    {
//        for (int j = i + 1; j + 1 < len; j++)
//        {
//            auto iter = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
//            res += iter - (nums.begin() + j + 1);
//        }
//    }
//
//    return res;
//}
///*
//思路3：
//1）排序
//2）固定最长边longest
//3）双指针查找l，r：
//    a.如果num[l] + nums[r] > longest，说明[l,r）共r-l个都满足，然后r--
//    b.如果num[l] + nums[r] <= longest，l++
//*/
//int triangleNumber3(vector<int> &nums)
//{
//    int len = nums.size();
//    if (len < 3)
//        return 0;
//
//    std::sort(nums.begin(), nums.end());
//
//    int res = 0;
//    for (int i = len - 1; i >= 2; i--)
//    {
//        int longest = nums[i];
//        int l = 0, r = i - 1;
//        while (l < r)
//        {
//            if (nums[l] + nums[r] > longest)
//            {
//                res += r - l;
//                --r;
//            }
//            else
//                ++l;
//        }
//    }
//
//    return res;
//}
//
///*
//621. 任务调度器
//给定一个用字符数组表示的 CPU 需要执行的任务列表。
//其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。
//任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。
//CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
//然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
//你需要计算完成所有任务所需要的最短时间。
//
//示例 1：
//输入: tasks = ["A","A","A","B","B","B"], n = 2
//输出: 8
//执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
//
//注：
//任务的总个数为 [1, 10000]。
//n 的取值范围为 [0, 100]。
//
//思路：https://leetcode-cn.com/problems/task-scheduler/solution/python-xiang-jie-by-jalan/
//*/
//int leastInterval(vector<char> &tasks, int n)
//{
//    int length = tasks.size();
//    if (length == 0)
//        return 0;
//
//    array<int, 26> cnts = {0};
//    for (char c : tasks)
//        ++cnts[c - 'A'];
//
//    std::sort(cnts.begin(), cnts.end());
//
//    int max_task = cnts[25];
//    int dup_max_task_cnt = 0;
//    for (int i = 25; i >= 0; i--)
//    {
//        if (cnts[i] != max_task)
//            break;
//        ++dup_max_task_cnt;
//    }
//
//    return std::max((max_task - 1) * (n + 1) + dup_max_task_cnt, length);
//}

///*
//给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。
//添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。
//将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。
//如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。
//
//示例 1:
//输入:
//二叉树如下所示:
//       4
//     /   \
//    2     6
//   / \   /
//  3   1 5
//v = 1
//d = 2
//输出:
//       4
//      / \
//     1   1
//    /     \
//   2       6
//  / \     /
// 3   1   5
//
//示例 2:
//输入:
//二叉树如下所示:
//      4
//     /
//    2
//   / \
//  3   1
//v = 1
//d = 3
//输出:
//      4
//     /
//    2
//   / \
//  1   1
// /     \
//3       1
//
//注意:
//输入的深度值 d 的范围是：[1，二叉树最大深度 + 1]。
//输入的二叉树至少有一个节点。
//*/
//TreeNode *addOneRow(TreeNode *root, int v, int d)
//{
//    if (d == 1)
//    {
//        TreeNode *p = new TreeNode(v);
//        p->left = root;
//        return p;
//    }
//
//    --d;
//    queue<TreeNode *> qu;
//    qu.push(root);
//    --d;
//    while (d > 0)
//    {
//        for (int i = qu.size() - 1; i >= 0; i--)
//        {
//            TreeNode *t = qu.front();
//            qu.pop();
//            if (t->left != nullptr)
//                qu.push(t->left);
//            if (t->right != nullptr)
//                qu.push(t->right);
//        }
//        --d;
//    }
//
//    for (int i = qu.size() - 1; i >= 0; i--)
//    {
//        TreeNode *t = qu.front();
//        qu.pop();
//
//        TreeNode *t_l = t->left, *t_r = t->right;
//        t->left = new TreeNode(v);
//        t->left->left = t_l;
//        t->right = new TreeNode(v);
//        t->right->right = t_r;
//    }
//    return root;
//}

///*
//636. 函数的独占时间
//给出一个非抢占单线程CPU的 n 个函数运行日志，找到函数的独占时间。
//每个函数都有一个唯一的 Id，从 0 到 n-1，函数可能会递归调用或者被其他函数调用。
//日志是具有以下格式的字符串：function_id：start_or_end：timestamp。
//例如："0:start:0" 表示函数 0 从 0 时刻开始运行。"0:end:0" 表示函数 0 在 0 时刻结束。
//函数的独占时间定义是在该方法中花费的时间，调用其他函数花费的时间不算该函数的独占时间。
//你需要根据函数的 Id 有序地返回每个函数的独占时间。
//
//示例 1:
//输入:
//n = 2
//logs =
//["0:start:0",
// "1:start:2",
// "1:end:5",
// "0:end:6"]
//输出:[3, 4]
//说明：
//函数 0 在时刻 0 开始，在执行了  2个时间单位结束于时刻 1。
//现在函数 0 调用函数 1，函数 1 在时刻 2 开始，执行 4 个时间单位后结束于时刻 5。
//函数 0 再次在时刻 6 开始执行，并在时刻 6 结束运行，从而执行了 1 个时间单位。
//所以函数 0 总共的执行了 2 +1 =3 个时间单位，函数 1 总共执行了 4 个时间单位。
//
//说明：
//输入的日志会根据时间戳排序，而不是根据日志Id排序。
//你的输出会根据函数Id排序，也就意味着你的输出数组中序号为 0 的元素相当于函数 0 的执行时间。
//两个函数不会在同时开始或结束。
//函数允许被递归调用，直到运行结束。
//1 <= n <= 100
//
//思路：用栈模拟函数调用
//*/
//vector<int> exclusiveTime(int n, const vector<string> &logs)
//{
//    int length = logs.size();
//    if (length == 0)
//        return {};
//
//    vector<int> res(n, 0);
//    using FuncStart = pair<int, int>;
//    stack<FuncStart> st;
//    for (const auto &log : logs)
//    {
//        auto idx1 = log.find_first_of(':');
//        auto idx2 = log.find_last_of(':');
//        int id = std::stoi(log.substr(0, idx1));
//        string status = log.substr(idx1 + 1, idx2 - idx1 - 1);
//        int time = std::stoi(log.substr(idx2 + 1));
//
//        if (status == "start") // 统计父函数到调用子函数之前，父函数执行的时间
//        {
//            if (!st.empty())
//                res[st.top().first] += time - st.top().second;
//            st.push({id, time});
//        }
//        else if (status == "end") // 完成一次完整的子函数调用，统计子函数执行的时间，并且父函数的起始时间调到该子函数执行完之后的时间
//        {
//            res[id] += time - st.top().second + 1;
//            st.pop();
//            if (!st.empty())
//                st.top().second = time + 1;
//        }
//    }
//    return res;
//}
//
///*
//638. 大礼包
//在LeetCode商店中， 有许多在售的物品。
//然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品。
//现给定每个物品的价格，每个大礼包包含物品的清单，以及待购物品清单。请输出确切完成待购清单的最低花费。
//每个大礼包的由一个数组中的一组数据描述，最后一个数字代表大礼包的价格，其他数字分别表示内含的其他种类物品的数量。
//任意大礼包可无限次购买。
//
//示例 1:
//输入: [2,5], [[3,0,5],[1,2,10]], [3,2]
//输出: 14
//解释:
//有A和B两种物品，价格分别为¥2和¥5。
//大礼包1，你可以以¥5的价格购买3A和0B。
//大礼包2， 你可以以¥10的价格购买1A和2B。
//你需要购买3个A和2个B， 所以你付了¥10购买了1A和2B（大礼包2），以及¥4购买2A。
//
//示例 2:
//输入: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
//输出: 11
//解释:
//A，B，C的价格分别为¥2，¥3，¥4.
//你可以用¥4购买1A和1B，也可以用¥9购买2A，2B和1C。
//你需要买1A，2B和1C，所以你付了¥4买了1A和1B（大礼包1），以及¥3购买1B， ¥4购买1C。
//你不可以购买超出待购清单的物品，尽管购买大礼包2更加便宜。
//
//说明:
//最多6种物品， 100种大礼包。
//每种物品，你最多只需要购买6个。
//你不可以购买超出待购清单的物品，即使更便宜。
//
//思路：递归深搜
//*/
//void shoppingOffersRecursively(const vector<int> &price, const vector<vector<int>> &special, vector<int> &needs, int sum, int &res)
//{
//    // 选礼包
//    for (int i = 0; i < special.size(); ++i)
//    {
//        // 当前礼包的容量是否符合要求
//        bool is_special_ok = true;
//        for (int j = 0; j < needs.size(); ++j)
//        {
//            if (needs[j] < special[i][j])
//            {
//                is_special_ok = false;
//                break;
//            }
//        }
//        if (!is_special_ok)
//            continue;
//
//        // 当前的礼包价格是否比已知的最小值还小（剪枝）
//        int special_prize = special[i][needs.size()];
//        if (sum + special_prize < res)
//        {
//            // 选该礼包
//            for (int k = 0; k < needs.size(); ++k)
//                needs[k] -= special[i][k];
//
//            // 递归深搜
//            shoppingOffersRecursively(price, special, needs, sum + special_prize, res);
//
//            // 递归返回，还原
//            for (int k = 0; k < needs.size(); ++k)
//                needs[k] += special[i][k];
//        }
//    }
//
//    // 不选礼包，直接单件购买
//    for (int i = 0; i < needs.size(); ++i)
//    {
//        sum += needs[i] * price[i];
//        if (sum > res) 
//            return;
//    }
//    res = sum;
//}
//int shoppingOffers(const vector<int> &price, const vector<vector<int>> &special, vector<int> &needs)
//{
//    int res = std::numeric_limits<int>::max();
//    shoppingOffersRecursively(price, special, needs, 0, res);
//    return res;
//}

///*
//640. 求解方程
//求解一个给定的方程，将x以字符串"x=#value"的形式返回。该方程仅包含'+'，' - '操作，变量 x 和其对应系数。
//如果方程没有解，请返回“No solution”。
//如果方程有无限解，则返回“Infinite solutions”。
//如果方程中只有一个解，要保证返回值 x 是一个整数。
//
//示例 1：
//输入: "x+5-3+x=6+x-2"
//输出: "x=2"
//
//示例 2:
//输入: "x=x"
//输出: "Infinite solutions"
//
//示例 3:
//输入: "2x=x"
//输出: "x=0"
//
//示例 4:
//输入: "2x+3x-6x=x+2"
//输出: "x=-1"
//
//示例 5:
//输入: "x=x+2"
//输出: "No solution"
//*/
//string solveEquation(const string &equation)
//{
//    auto eq_idx = equation.find('=');
//    string left = equation.substr(0, eq_idx);
//    string right = equation.substr(eq_idx + 1);
//
//    auto compute = [](const string &s, int &factors, int &nums)
//    {
//        int i = 0;
//        bool is_neg = false;
//        while (i < s.size())
//        {
//            if (s[i] == '-')
//            {
//                is_neg = true;
//                ++i;
//            }
//            else if (s[i] == '+')
//                ++i;
//
//            int num = 0;
//            while (std::isdigit(s[i]))
//            {
//                num = num * 10 + (s[i] - '0');
//                ++i;
//            }
//
//            if (s[i] == 'x')
//            {
//                if (num == 0 && !(i > 0 && s[i - 1] == '0'))
//                    num = 1;
//                if (is_neg)
//                    num = -num;
//                factors += num;
//                ++i;
//            }
//            else
//            {
//                if (is_neg)
//                    num = -num;
//                nums += num;
//            }
//            is_neg = false;
//        }
//    };
//
//    int factors_left = 0, nums_left = 0;
//    compute(left, factors_left, nums_left);
//    int factors_right = 0, nums_right = 0;
//    compute(right, factors_right, nums_right);
//
//    int factors = factors_left - factors_right;
//    int nums = nums_right - nums_left;
//
//    if (factors == 0 && nums == 0)
//        return "Infinite solutions";
//    else if (factors == 0 && nums != 0)
//        return "No solution";
//    else
//        return "x=" + std::to_string(nums / factors);
//}

///*
//646.最长数对链
//给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。
//现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。
//给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
//
//示例 :
//输入: [[1,2], [2,3], [3,4]]
//输出: 2
//解释: 最长的数对链是 [1,2] -> [3,4]
//
//注意：
//给出数对的个数在 [1, 1000] 范围内。
//
//思路：贪心算法，类似活动安排问题
//*/
//int findLongestChain(vector<vector<int>> &pairs)
//{
//    int length = pairs.size();
//    if (length < 2)
//        return length;
//
//    std::sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
//              {
//                  return a.back() < b.back();
//              });
//
//    int res = 1;
//    int last_right = pairs[0].back();
//    for (int i = 1; i < length; i++)
//    {
//        if (pairs[i].front() <= last_right)
//            continue;
//
//        last_right = pairs[i].back();
//        ++res;
//    }
//
//    return res;
//}
//
///*
//647. 回文子串
//给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
//具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
//
//示例 1:
//输入: "abc"
//输出: 3
//解释: 三个回文子串: "a", "b", "c".
//
//示例 2:
//输入: "aaa"
//输出: 6
//说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
//
//注意:
//输入的字符串长度不会超过1000。
//
//思路：带记忆地遍历所有子串
//*/
//int countSubstrings(const string &s)
//{
//    int length = s.size();
//    if (length < 2)
//        return length;
//
//    int res = 0;
//    vector<vector<bool>> flags(length, vector<bool>(length, false));
//    for (int i = 0; i < length; i++)
//    {
//        flags[i][i] = true;
//        ++res;
//    }
//    for (int i = 0; i < length - 1; i++)
//    {
//        if (s[i] == s[i + 1])
//        {
//            flags[i][i + 1] = true;
//            ++res;
//        }
//    }
//
//    for (int len = 2; len < length; len++)
//    {
//        for (int start = 0; start + len < length; start++)
//        {
//            if (s[start] == s[start + len] && flags[start + 1][start + len - 1])
//            {
//                flags[start][start + len] = true;
//                ++res;
//            }
//        }
//    }
//
//    return res;
//}
//// 思路2：中心扩展法
//int countSubstrings2(const string &s)
//{
//    int length = s.size();
//    if (length < 2)
//        return length;
//
//    int res = 0;
//
//    // 奇数长度的子串
//    for (int i = 0; i < length; ++i)
//    {
//        int l = i - 1, r = i + 1;
//        ++res;
//        while (l >= 0 && r < length)
//        {
//            if (s[l] == s[r])
//            {
//                ++res;
//                ++r;
//                --l;
//            }
//            else
//                break;
//        }
//    }
//    // 偶数长度的子串
//    for (int i = 0; i < length - 1; ++i)
//    {
//        int l = i - 1, r = i + 2;
//        if (s[i] == s[i + 1])
//            ++res;
//        else
//            continue;
//        while (l >= 0 && r < length)
//        {
//            if (s[l] == s[r])
//            {
//                ++res;
//                ++r;
//                --l;
//            }
//            else
//                break;
//        }
//    }
//    return res;
//}

///*
//648. 单词替换
//在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。
//例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
//现在，给定一个由许多词根组成的词典和一个句子。
//你需要将句子中的所有继承词用词根替换掉。
//如果继承词有许多可以形成它的词根，则用最短的词根替换它。
//你需要输出替换之后的句子。
//
//示例 1:
//输入: dict(词典) = ["cat", "bat", "rat"]
//sentence(句子) = "the cattle was rattled by the battery"
//输出: "the cat was rat by the bat"
//
//注:
//输入只包含小写字母。
//1 <= 字典单词数 <=1000
//1 <=  句中词语数 <= 1000
//1 <= 词根长度 <= 100
//1 <= 句中词语长度 <= 1000
//
//思路：前缀树
//*/
//string replaceWords(vector<string> &dict, const string &sentence)
//{
//    int length = sentence.size();
//    if (length == 0)
//        return {};
//
//    Trie tree;
//    for (const string &s : dict)
//        tree.insert(s);
//
//    ostringstream oss;
//    istringstream iss(sentence);
//    string s;
//    while (iss >> s)
//    {
//        string ret = tree.searchPrefixIn(s);
//        if (!ret.empty())
//            oss << ret << ' ';
//        else
//            oss << s << ' ';
//    }
//
//    string res = oss.str();
//    res.pop_back();
//    return res;
//}
//
///*
//649. Dota2 参议院
//Dota2 的世界里有两个阵营：Radiant(天辉)和 Dire(夜魇)
//Dota2 参议院由来自两派的参议员组成。
//现在参议院希望对一个 Dota2 游戏里的改变作出决定。
//他们以一个基于轮为过程的投票进行。在每一轮中，每一位参议员都可以行使两项权利中的一项：
//禁止一名参议员的权利：
//    参议员可以让另一位参议员在这一轮和随后的几轮中丧失所有的权利。
//宣布胜利：
//     如果参议员发现有权利投票的参议员都是同一个阵营的，他可以宣布胜利并决定在游戏中的有关变化。
//给定一个字符串代表每个参议员的阵营。字母 “R” 和 “D” 分别代表了 Radiant（天辉）和 Dire（夜魇）。
//然后，如果有 n 个参议员，给定字符串的大小将是 n。
//以轮为基础的过程从给定顺序的第一个参议员开始到最后一个参议员结束。
//这一过程将持续到投票结束。
//所有失去权利的参议员将在过程中被跳过。
//假设每一位参议员都足够聪明，会为自己的政党做出最好的策略，你需要预测哪一方最终会宣布胜利并在 Dota2 游戏中决定改变。
//输出应该是 Radiant 或 Dire。
//
//示例 1:
//输入: "RD"
//输出: "Radiant"
//解释:  第一个参议员来自  Radiant 阵营并且他可以使用第一项权利让第二个参议员失去权力，因此第二个参议员将被跳过因为他没有任何权利。然后在第二轮的时候，第一个参议员可以宣布胜利，因为他是唯一一个有投票权的人
//
//示例 2:
//输入: "RDD"
//输出: "Dire"
//解释:
//第一轮中,第一个来自 Radiant 阵营的参议员可以使用第一项权利禁止第二个参议员的权利
//第二个来自 Dire 阵营的参议员会被跳过因为他的权利被禁止
//第三个来自 Dire 阵营的参议员可以使用他的第一项权利禁止第一个参议员的权利
//因此在第二轮只剩下第三个参议员拥有投票的权利,于是他可以宣布胜利
//
//注意:
//给定字符串的长度在 [1, 10,000] 之间
//*/
//string predictPartyVictory(string &senate)
//{
//    int length = senate.size();
//    bool R = true, D = true;
//    // 标记变量，当person > 0的时候，此时R方有权利把D方的成员淘汰掉
//    // 当person < 0的时候，D方有权利把R方的成员淘汰掉
//    int person = 0;
//    while (R && D)
//    {
//        // 当遇到双方成员的时候置为true，表示当前还有人员存在
//        // 当R或D为false，表示一方已经没有成员存在了，胜负已分，结束循环
//        R = false; 
//        D = false;
//        for (int i = 0; i < length; ++i)
//        {
//            if (senate[i] == 'R')
//            {
//                R = true;
//                if (person < 0)
//                    senate[i] = 'X';
//                ++person;
//            }
//            else if (senate[i] == 'D')
//            {
//                D = true;
//                if (person > 0) 
//                    senate[i] = 'X';
//                --person;
//            }
//        }
//    }
//    return person > 0 ? "Radiant" : "Dire";
//}

///*
//650. 只有两个键的键盘
//最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：
//Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
//Paste (粘贴) : 你可以粘贴你上一次复制的字符。
//给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。输出能够打印出 n 个 'A' 的最少操作次数。
//
//示例 1:
//输入: 3
//输出: 3
//解释:
//最初, 我们只有一个字符 'A'。
//第 1 步, 我们使用 Copy All 操作。
//第 2 步, 我们使用 Paste 操作来获得 'AA'。
//第 3 步, 我们使用 Paste 操作来获得 'AAA'。
//
//说明:
//n 的取值范围是 [1, 1000] 。
//
//思路：贪心法
//1）尽可能拷贝长的串，然后粘贴，这样次数最少
//2）能够拷贝目前串的前提是，剩余的串长度是目前串长度的倍数，否则只能粘贴
//*/
//int minSteps(int n)
//{
//    if (n == 1)
//        return 0;
//
//    // 当前串长度, 能够粘贴的串的长度, 拷贝粘贴总次数
//    int total_len = 1, paste_len = 1, res = 1;
//    // 是否允许拷贝标识符
//    bool allow_copy = false;
//    while (n != total_len)
//    {
//        // 只有 允许拷贝 并且 剩余串长度是当前串长度的倍数 时才拷贝
//        if (allow_copy == true && (n - total_len) % total_len == 0)
//        {
//            paste_len = total_len;
//            allow_copy = false;
//        }
//        // 粘贴
//        else
//        {
//            total_len += paste_len;
//            allow_copy = true;
//        }
//        ++res;
//    }
//    return res;
//}
//
///*
//652. 寻找重复的子树
//给定一棵二叉树，返回所有重复的子树。
//对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
//两棵树重复是指它们具有相同的结构以及相同的结点值。
//
//示例 1：
//        1
//       / \
//      2   3
//     /   / \
//    4   2   4
//       /
//      4
//下面是两个重复的子树：
//      2
//     /
//    4
//和
//    4
//因此，你需要以列表的形式返回上述重复子树的根结点。
//
//思路：暴力法（超时）
//1）先遍历得到所有节点
//2）然后固定一个节点，在所有节点中寻找和它相同的左右子树
//*/
//bool compareTree(TreeNode *p1, TreeNode *p2)
//{
//    if (p1 == nullptr && p2 != nullptr || p1 != nullptr && p2 == nullptr)
//        return false;
//    if (p1 == nullptr && p2 == nullptr)
//        return true;
//
//    if (p1->val != p2->val)
//        return false;
//
//    if (compareTree(p1->left, p2->left) == false)
//        return false;
//    if (compareTree(p1->right, p2->right) == false)
//        return false;
//
//    return true;
//}
//void preOrderTree(TreeNode *p, vector<TreeNode *> &nodes)
//{
//    if (p == nullptr)
//        return;
//
//    nodes.push_back(p);
//    preOrderTree(p->left, nodes);
//    preOrderTree(p->right, nodes);
//}
//vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
//{
//    if (root == nullptr)
//        return {};
//
//    vector<TreeNode *> nodes;
//    preOrderTree(root, nodes);
//
//    int length = nodes.size();
//    vector<bool> visited(length, false);
//    vector<TreeNode *> res;
//    for (int i = 0; i < length; i++)
//    {
//        if (visited[i])
//            continue;
//        visited[i] = true;
//        bool hasSame = false;
//        for (int j = i + 1; j < length; j++)
//        {
//            if (visited[j])
//                continue;
//
//            if (compareTree(nodes[i], nodes[j]))
//            {
//                visited[j] = true;
//                hasSame = true;
//            }
//        }
//        if (hasSame)
//            res.push_back(nodes[i]);
//    }
//    return res;
//}
///*
//思路2：
//1）先根遍历，遍历过程中序列化二叉树
//2）维护一个哈希表，保存 {以每个节点为根的二叉树的序列化字符串:重复次数}
//3）重复次数超过1，则加入结果集
//*/
//string findDuplicateSubtreesRecursively(TreeNode *root, unordered_map<string, int> &m, vector<TreeNode *> &res)
//{
//    if (root == nullptr)
//        return "$";
//
//    // 以该节点为根的二叉树序列化字符串
//    string s = std::to_string(root->val) + ","
//        + findDuplicateSubtreesRecursively(root->left, m, res) + ","
//        + findDuplicateSubtreesRecursively(root->right, m, res);
//
//    // 重复次数+1
//    ++m[s];
//    // 重复次数超过1，加入结果集
//    if (m[s] == 2)
//        res.push_back(root);
//
//    return s;
//}
//vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
//{
//    if (root == nullptr)
//        return {};
//
//    vector<TreeNode *> res;
//    unordered_map<string, int> m;
//    findDuplicateSubtreesRecursively(root, m, res);
//
//    return res;
//}

///*
//654. 最大二叉树
//给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
//二叉树的根是数组中的最大元素。
//左子树是通过数组中最大值左边部分构造出的最大二叉树。
//右子树是通过数组中最大值右边部分构造出的最大二叉树。
//通过给定的数组构建最大二叉树，并且输出这个树的根节点。
//
//示例 ：
//输入：[3,2,1,6,0,5]
//输出：返回下面这棵树的根节点：
//
//      6
//    /   \
//   3     5
//    \    /
//     2  0
//       \
//        1
//
//提示：
//给定的数组的大小在 [1, 1000] 之间。
//
//思路：递归构建
//*/
//TreeNode *constructMaximumBinaryTreeRecursively(const vector<int> &nums, int start, int stop)
//{
//    // 叶子节点
//    if (start == stop)
//        return new TreeNode(nums[start]);
//
//    // 寻找最大值及其下标
//    int max_val = nums[start];
//    int max_idx = start;
//    for (int i = start + 1; i <= stop; i++)
//    {
//        if (nums[i] > max_val)
//        {
//            max_val = nums[i];
//            max_idx = i;
//        }
//    }
//
//    // 递归构建
//    TreeNode *p = new TreeNode(max_val);
//    if (max_idx != start)
//        p->left = constructMaximumBinaryTreeRecursively(nums, start, max_idx - 1);
//    if (max_idx != stop)
//        p->right = constructMaximumBinaryTreeRecursively(nums, max_idx + 1, stop);
//    return p;
//}
//TreeNode *constructMaximumBinaryTree(const vector<int> &nums)
//{
//    if (nums.empty())
//        return nullptr;
//
//    return constructMaximumBinaryTreeRecursively(nums, 0, nums.size() - 1);
//}
//
///*
//655. 输出二叉树
//在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：
//行数 m 应当等于给定二叉树的高度。
//列数 n 应当总是奇数。
//根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。
//根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。
//你应该将左子树输出在左下部分，右子树输出在右下部分。
//左下和右下部分应当有相同的大小。
//即使一个子树为空而另一个非空，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。
//然而，如果两个子树都为空则不需要为它们留出任何空间。
//每个未使用的空间应包含一个空的字符串""。
//使用相同的规则输出子树。
//
//示例 1:
//输入:
//     1
//    /
//   2
//输出:
//[["", "1", ""],
// ["2", "", ""]]
//
//示例 2:
//输入:
//     1
//    / \
//   2   3
//    \
//     4
//输出:
//[["", "", "", "1", "", "", ""],
// ["", "2", "", "", "", "3", ""],
// ["", "", "4", "", "", "", ""]]
//
//示例 3:
//输入:
//      1
//     / \
//    2   5
//   /
//  3
// /
//4
//输出:
//[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
// ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
// ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
// ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
//
//注意: 二叉树的高度在范围 [1, 10] 中。
//
//思路：
//1）先得到树的深度
//2）根据深度构造m*n的容器
//3）然后前序遍历构造
//*/
//int getTreeDepth(TreeNode *p) // 获取树的深度
//{
//    if (p == nullptr)
//        return 0;
//
//    return std::max(getTreeDepth(p->left), getTreeDepth(p->right)) + 1;
//}
//void printTreeRecursively(TreeNode *p, int row, int start, int stop, vector<vector<string>> &res)
//{
//    if (p == nullptr)
//        return;
//
//    int mid = (start + stop) / 2; // 得到中点位置
//    res[row][mid] = std::to_string(p->val); // 放置根节点
//    printTreeRecursively(p->left, row + 1, start, mid - 1, res); // 递归左侧
//    printTreeRecursively(p->right, row + 1, mid + 1, stop, res); // 递归右侧
//}
//vector<vector<string>> printTree(TreeNode *root)
//{
//    if (root == nullptr)
//        return {};
//
//    int depth = getTreeDepth(root);
//    int rows = depth, cols = (0x01 << depth) - 1;
//    vector<vector<string>> res(rows, vector<string>(cols));
//    printTreeRecursively(root, 0, 0, cols - 1, res);
//
//    return res;
//}

///*
//658. 找到 K 个最接近的元素
//给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。
//返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。
//
//示例 1:
//输入: [1,2,3,4,5], k=4, x=3
//输出: [1,2,3,4]
//
//示例 2:
//输入: [1,2,3,4,5], k=4, x=-1
//输出: [1,2,3,4]
//
//说明:
//k 的值为正数，且总是小于给定排序数组的长度。
//数组不为空，且长度不超过 10^4
//数组里的每个元素与 x 的绝对值不超过 10^4
//
//更新(2017/9/19):
//这个参数 arr 已经被改变为一个整数数组（而不是整数列表）。 请重新加载代码定义以获取最新更改。
//
//思路：
//1）先确定最靠近x的数的下标idx
//2）那么结果区间的起始下标一定在[idx - k, idx]
//3）遍历取最接近区间即可
//*/
//vector<int> findClosestElements(vector<int> &arr, int k, int x)
//{
//    if (x <= arr.front())
//        return vector<int>(arr.begin(), arr.begin() + k);
//    if (x >= arr.back())
//        return vector<int>(arr.end() - k, arr.end());
//
//    // 确定最靠近x的数的下标idx
//    int idx = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
//    // 区间起始下标（包含）
//    int start = std::max(idx - k, 0);
//    // 区间终止下标（不包含）
//    int stop = start + k;
//    // 结果区间的起始和终止下标
//    int res_start = start, res_stop = stop;
//    // 前后相邻两个区间的差值，最小差值
//    int diff = 0, min_diff = 0;
//    // 遍历
//    while (start <= idx && stop < arr.size())
//    {
//        // 后区间相对于前区间，删去了开头元素，加入了结尾的下一个元素
//        // 前后区间差值 = 后区间 - 前区间 = -前区间第一个元素与x的差值绝对值 + 前区间最后一个元素的下一个元素与x的差值绝对值
//        diff += std::abs(x - arr[stop]) - std::abs(x - arr[start]);
//        if (diff < min_diff) // 更新差值
//        {
//            min_diff = diff;
//            res_start = start + 1;
//            res_stop = stop + 1;
//        }
//        ++start;
//        ++stop;
//    }
//
//    return vector<int>(arr.begin() + res_start, arr.begin() + res_stop);
//}
///*
//思路2：直接二分搜索
//（https://leetcode-cn.com/problems/find-k-closest-elements/solution/pai-chu-fa-shuang-zhi-zhen-er-fen-fa-python-dai-ma/）
//*/
//vector<int> findClosestElements2(vector<int> &arr, int k, int x)
//{
//    int left = 0;
//    int right = arr.size() - k;
//    while (left < right)
//    {
//        int mid = (left + right) / 2;
//        if ((x - arr[mid]) > (arr[mid + k] - x))
//            left = mid + 1;
//        else
//            right = mid;
//    }
//    return vector<int>(arr.begin() + left, arr.begin() + left + k);
//}
//
///*
//659. 分割数组为连续子序列
//输入一个按升序排序的整数数组（可能包含重复数字），你需要将它们分割成几个子序列，其中每个子序列至少包含三个连续整数。
//返回你是否能做出这样的分割？
//
//示例 1：
//输入: [1,2,3,3,4,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 :
//1, 2, 3
//3, 4, 5
//
//示例 2：
//输入: [1,2,3,3,4,4,5,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 :
//1, 2, 3, 4, 5
//3, 4, 5
// 
//示例 3：
//输入: [1,2,3,4,4,5]
//输出: False
//
//提示：
//输入的数组长度范围为 [1, 10000]
//
//思路：贪心算法
//（https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/solution/fen-ge-shu-zu-wei-lian-xu-zi-xu-lie-by-leetcode/）
//*/
//bool isPossible(vector<int> &nums)
//{
//    unordered_map<int, int> numsCntMap; // numsCntMap[num]表示的是num剩余的个数
//    unordered_map<int, int> numsEndCntMap; // numsEndCntMap[num]表示的时以num结尾的连续子序列（长度不小于3）个数
//    // 统计各个元素出现的次数
//    for (auto num : nums)
//        ++numsCntMap[num];
//
//    // 开始访问各个元素
//    for (auto num : nums)
//    {
//        if (numsCntMap[num] == 0) //此元素没有剩余，已经被使用完了
//            continue;
//
//        --numsCntMap[num]; // 剩余个数自减
//        if (numsEndCntMap.count(num - 1) && numsEndCntMap[num - 1] > 0)
//        {
//            // 存在以num - 1结尾的连续子序列（长度不小于3），则将num放入
//            numsEndCntMap[num - 1] -= 1; // 以num - 1结尾的连续子序列（长度不小于3）自减，因为被num放入使用了一个
//            numsEndCntMap[num] += 1; // 以num结尾的连续子序列（长度不小于3）自增，刚刚创建了一个
//        }
//        else if (numsCntMap.count(num + 1) && numsCntMap[num + 1] > 0 && numsCntMap.count(num + 2) && numsCntMap[num + 2] > 0)
//        {
//            // 否则查找后面两个元素，凑出一个合法的序列
//            numsCntMap[num + 1] -= 1;
//            numsCntMap[num + 2] -= 1;
//            numsEndCntMap[num + 2] += 1;
//        }
//        else
//        {
//            //两种方法都不行，则凑不出，比如[1,2,3,4,4,5]中的第二个4，
//            return false;
//        }
//    }
//    return true;
//}

///*
//662. 二叉树最大宽度
//给定一个二叉树，编写一个函数来获取这个树的最大宽度。
//树的宽度是所有层中的最大宽度。
//这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。
//每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
//
//示例 1:
//输入:
//
//           1
//         /   \
//        3     2
//       / \     \
//      5   3     9
//
//输出: 4
//解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
//
//示例 2:
//输入:
//
//          1
//         /
//        3
//       / \
//      5   3
//
//输出: 2
//解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
//
//示例 3:
//输入:
//
//          1
//         / \
//        3   2
//       /
//      5
//
//输出: 2
//解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
//
//示例 4:
//输入:
//
//          1
//         / \
//        3   2
//       /     \
//      5       9
//     /         \
//    6           7
//输出: 8
//解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
//
//注意: 答案在32位有符号整数的表示范围内。
//
//思路：（超时）
//1）宽度优先搜索
//2）用双端队列记录每层的所有节点，包括空节点
//3）在每层中搜索第一个非空节点以及倒数第一个非空节点，两者之差为该层宽度
//*/
//int widthOfBinaryTree(TreeNode *root)
//{
//    if (root == nullptr)
//        return 0;
//
//    int res = 1;
//    deque<TreeNode *> qu;
//    qu.push_back(root);
//    while (true)
//    {
//        bool all_null = true;
//        for (int i = 0, length = qu.size(); i < length; i++)
//        {
//            auto t = qu.front();
//            qu.pop_front();
//            if (t == nullptr)
//            {
//                qu.push_back(nullptr);
//                qu.push_back(nullptr);
//                continue;
//            }
//            all_null = false;
//            qu.push_back(t->left);
//            qu.push_back(t->right);
//        }
//
//        if (all_null)
//            break;
//
//        auto first_not_null = std::find_if(qu.begin(), qu.end(), [](TreeNode *a) { return a != nullptr; });
//        auto last_not_null = std::find_if(qu.rbegin(), qu.rend(), [](TreeNode *a) { return a != nullptr; });
//        int t = last_not_null.base() - first_not_null;
//        if (t > res)
//            res = t;
//    }
//
//    return res;
//}
//// 思路2：深搜，给每个节点编号，记录每层的最左侧节点
//void widthOfBinaryTreeRecursively(TreeNode *p, int level, unsigned long long idx, vector<unsigned long long> &left_idx, int &res)
//{
//    if (p == nullptr)
//        return;
//
//    // 新的层，把最左侧节点保存
//    if (level > left_idx.size())
//        left_idx.push_back(idx);
//
//    res = std::max(static_cast<unsigned long long>(res), idx - left_idx[level - 1] + 1);
//
//    // 递归左节点
//    widthOfBinaryTreeRecursively(p->left, level + 1, idx * 2, left_idx, res);
//    // 递归右节点
//    widthOfBinaryTreeRecursively(p->right, level + 1, idx * 2 + 1, left_idx, res);
//}
//int widthOfBinaryTree2(TreeNode *root)
//{
//    if (root == nullptr)
//        return 0;
//
//    vector<unsigned long long> left_idx;
//    int res = 0;
//    widthOfBinaryTreeRecursively(root, 1, 1, left_idx, res);
//    return res;
//}
//// 思路3：改进思路1，给每个节点编号
//int widthOfBinaryTree3(TreeNode *root)
//{
//    if (root == nullptr)
//        return 0;
//
//    int res = 1;
//    deque<TreeNode *> qu;
//    deque<unsigned long long> idx;
//    qu.push_back(root);
//    idx.push_back(1);
//    while (!qu.empty())
//    {
//        res = std::max(static_cast<unsigned long long>(res), idx.back() - idx.front() + 1);
//        for (int i = 0, length = qu.size(); i < length; i++)
//        {
//            auto p = qu.front();
//            auto index = idx.front();
//            qu.pop_front();
//            idx.pop_front();
//
//            if (p->left != nullptr)
//            {
//                qu.push_back(p->left);
//                idx.push_back(index * 2);
//            }
//            if (p->right != nullptr)
//            {
//                qu.push_back(p->right);
//                idx.push_back(index * 2 + 1);
//            }
//        }
//    }
//
//    return res;
//}
//
///*
//667. 优美的排列 II
//给定两个整数 n 和 k，你需要实现一个数组，这个数组包含从 1 到 n 的 n 个不同整数，同时满足以下条件：
//① 如果这个数组是 [a1, a2, a3, ... , an] ，那么数组 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数；.
//② 如果存在多种答案，你只需实现并返回其中任意一种.
//
//示例 1:
//输入: n = 3, k = 1
//输出: [1, 2, 3]
//解释: [1, 2, 3] 包含 3 个范围在 1-3 的不同整数， 并且 [1, 1] 中有且仅有 1 个不同整数 : 1
// 
//示例 2:
//输入: n = 3, k = 2
//输出: [1, 3, 2]
//解释: [1, 3, 2] 包含 3 个范围在 1-3 的不同整数， 并且 [2, 1] 中有且仅有 2 个不同整数: 1 和 2
// 
//提示:
// n 和 k 满足条件 1 <= k < n <= 10^4.
//*/
//vector<int> constructArray(int n, int k)
//{
//    vector<int> res;
//    res.reserve(n);
//    int small = 1, big = n;
//    int is_small_turn = 1;
//    for (int i = 0; i < k; i++)
//    {
//        if (is_small_turn)
//            res.push_back(small++);
//        else
//            res.push_back(big--);
//        is_small_turn = 1 - is_small_turn;
//    }
//
//    int left_size = n - res.size();
//    if (is_small_turn)
//    {
//        for (int i = 0; i < left_size; i++)
//            res.push_back(big--);
//    }
//    else
//    {
//        for (int i = 0; i < left_size; i++)
//            res.push_back(small++);
//    }
//
//    return res;
//}
//
///*
//670. 最大交换
//给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
//
//示例 1 :
//输入: 2736
//输出: 7236
//解释: 交换数字2和数字7。
//
//示例 2 :
//输入: 9973
//输出: 9973
//解释: 不需要交换。
//
//注意:
//给定数字的范围是 [0, 108]
//
//思路：
//1）数字num转字符串s
//2）对于位于i处的元素s[i]，在右边[i+1, length)寻找最大的元素s[j]，并且s[j]>s[i]且s[j]靠近右侧
//    比如1993的位于0处的元素1，寻找的结果为2处的9，而不是1处的9
//*/
//int maximumSwap(int num)
//{
//    if (num <= 10)
//        return num;
//
//    string n = std::to_string(num);
//    int length = n.size();
//
//    vector<int> indices(length, -1);
//    int max_idx = length - 1;
//    indices.back() = max_idx;
//    for (int i = length - 2; i >= 0; i--)
//    {
//        if (n[i] == n[max_idx])
//            continue;
//        if (n[i] > n[max_idx])
//        {
//            max_idx = i;
//            continue;
//        }
//
//        indices[i] = max_idx;
//    }
//
//    for (int i = 0; i < length; i++)
//    {
//        if (indices[i] != -1)
//        {
//            std::swap(n[i], n[indices[i]]);
//            break;
//        }
//    }
//
//    return std::stoi(n);
//}
//
///*
//672. 灯泡开关 Ⅱ
//现有一个房间，墙上挂有 n 只已经打开的灯泡和 4 个按钮。在进行了 m 次未知操作后，你需要返回这 n 只灯泡可能有多少种不同的状态。
//假设这 n 只灯泡被编号为 [1, 2, 3 ..., n]，这 4 个按钮的功能如下：
//将所有灯泡的状态反转（即开变为关，关变为开）
//将编号为偶数的灯泡的状态反转
//将编号为奇数的灯泡的状态反转
//将编号为 3k+1 的灯泡的状态反转（k = 0, 1, 2, ...)
//
//示例 1:
//输入: n = 1, m = 1.
//输出: 2
//说明: 状态为: [开], [关]
//
//示例 2:
//输入: n = 2, m = 1.
//输出: 3
//说明: 状态为: [开, 关], [关, 开], [关, 关]
//
//示例 3:
//输入: n = 3, m = 1.
//输出: 4
//说明: 状态为: [关, 开, 关], [开, 关, 开], [关, 关, 关], [关, 开, 开].
//
//注意： n 和 m 都属于 [0, 1000].
//
//思路：找规律（https://leetcode-cn.com/problems/bulb-switcher-ii/solution/deng-pao-kai-guan-ii-by-leetcode/）
//*/
//int flipLights(int n, int m)
//{
//    switch (n)
//    {
//    case 0:
//        return 0;
//    case 1:
//        return (m > 0) + 1;
//    case 2:
//        return (m > 1) + (m > 0) * 2 + 1;
//    }
//    switch (m)
//    {
//    case 0:
//        return 1;
//    case 1:
//        return 4;
//    case 2:
//        return 7;
//    }
//    return 8;
//}

///*
//673. 最长递增子序列的个数
//给定一个未排序的整数数组，找到最长递增子序列的个数。
//
//示例 1:
//输入: [1,3,5,4,7]
//输出: 2
//解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
//
//示例 2:
//输入: [2,2,2,2,2]
//输出: 5
//解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
//注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
//
//思路：递归深搜（超时）
//*/
//void findNumberOfLISRecursively(const vector<int> &nums, int idx, int cur_len, int &max_len, int &res)
//{
//    if (idx >= nums.size() - 1)
//    {
//        if (cur_len > max_len)
//        {
//            max_len = cur_len;
//            res = 1;
//        }
//        else if (cur_len == max_len)
//            ++res;
//        return;
//    }
//
//    for (int i = idx + 1; i < nums.size(); i++)
//    {
//        if (nums[i] > nums[idx])
//            findNumberOfLISRecursively(nums, i, cur_len + 1, max_len, res);
//    }
//
//    if (cur_len > max_len)
//    {
//        max_len = cur_len;
//        res = 1;
//    }
//    else if (cur_len == max_len)
//        ++res;
//}
//int findNumberOfLIS(const vector<int> &nums)
//{
//    int length = nums.size();
//    if (length <= 1)
//        return length;
//
//    int res = 0, max_len = std::numeric_limits<int>::min();
//    for (int i = 0; i < length; i++)
//        findNumberOfLISRecursively(nums, i, 1, max_len, res);
//
//    return res;
//}
///*
//思路2：动态规划
//1）用lens[i]表示以nums[i]结尾（包括）的最长递增子序列（LIS）的长度，cnts[i]表示以nums[i]结尾的LIS的个数
//2）针对每一个j∈[0, length)，考察i∈[0, j)，如果nums[i] < nums[j]，说明可以把nums[j]附加到以nums[i]结尾的所有LIS上：
//    a.如果lens[i] + 1 > lens[j]，说明附加之后，相比于原来以nums[j]结尾的LIS的长度，产生了更长的长度，更新lens[j]为lens[i] + 1，并且cnts[j]就是cnts[i]
//    b.如果lens[i] + 1 == lens[j]，说明附加之后，并没有产生更长的长度，但是增加了新的个数，所以cnts[j] += cnts[i]
//    c.否则，说明附加之后，还没有原来的lens[j]长，什么也不做
//3）遍历lens找出最长长度
//4）累计所有cnts中长度等于最长长度的个数
//*/
//int findNumberOfLIS2(const vector<int> &nums)
//{
//    int length = nums.size();
//    if (length <= 1)
//        return length;
//
//    vector<int> lens(length, 1), cnts(length, 1);
//    for (int j = 1; j < length; j++)
//    {
//        for (int i = 0; i < j; i++)
//        {
//            if (nums[j] > nums[i])
//            {
//                if (lens[i] + 1 > lens[j])
//                {
//                    lens[j] = lens[i] + 1;
//                    cnts[j] = cnts[i];
//                }
//                else if (lens[i] + 1 == lens[j])
//                {
//                    cnts[j] += cnts[i];
//                }
//            }
//        }
//    }
//
//    int max_len = 0;
//    for (int len : lens)
//        if (len > max_len)
//            max_len = len;
//
//    int res = 0;
//    for (int i = 0; i < length; i++)
//    {
//        if (lens[i] == max_len)
//            res += cnts[i];
//    }
//
//    return res;
//}

///*
//678. 有效的括号字符串
//给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：
//任何左括号 ( 必须有相应的右括号 )。
//任何右括号 ) 必须有相应的左括号 ( 。
//左括号 ( 必须在对应的右括号之前 )。
//* 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
//一个空字符串也被视为有效字符串。
//
//示例 1:
//输入: "()"
//输出: True
//
//示例 2:
//输入: "(*)"
//输出: True
//
//示例 3:
//输入: "(*))"
//输出: True
//
//注意:
//字符串大小将在 [1，100] 范围内。
//
//思路：递归深搜（能通过，不过耗时很长）
//*/
//bool checkValidStringRecursively(const string &s, int idx, int left_cnt)
//{
//    if (left_cnt < 0) // 左括号个数小于0，说明有右括号在左括号之前，不符合要求
//        return false;
//
//    if (idx >= s.size())
//    {
//        if (left_cnt == 0) // 左括号刚好为0，说明左右括号刚好匹配
//            return true;
//        return false;
//    }
//
//    if (s[idx] == '(') // 左括号，左括号个数加一
//        return checkValidStringRecursively(s, idx + 1, left_cnt + 1);
//    else if (s[idx] == ')') // 右括号，左括号个数减一，表示匹配掉一个左括号
//        return checkValidStringRecursively(s, idx + 1, left_cnt - 1);
//    else if (s[idx] == '*') // *号，递归所有情况
//        return checkValidStringRecursively(s, idx + 1, left_cnt + 1)
//        || checkValidStringRecursively(s, idx + 1, left_cnt - 1)
//        || checkValidStringRecursively(s, idx + 1, left_cnt);
//    else
//        return false;
//}
//bool checkValidString(const string &s)
//{
//    if (s.empty())
//        return true;
//
//    return checkValidStringRecursively(s, 0, 0);
//}
///*
//思路2：贪心算法（https://leetcode-cn.com/problems/valid-parenthesis-string/solution/you-xiao-de-gua-hao-zi-fu-chuan-by-leetcode/）
//*/
//bool checkValidString2(const string &s)
//{
//    if (s.empty())
//        return true;
//
//    int low = 0; //low代表*作为右括号或空字符串时左括号的数量（最少左括号）
//    int high = 0; //high代表*作为左括号时左括号的数量（最多左括号）
//    for (int i = 0; i < s.length(); i++)
//    {
//        char c = s[i];
//        if (c == '(')
//        {
//            low++;
//            high++;
//        }
//        else if (c == ')')
//        {
//            if (low > 0)
//                low--;
//            high--;
//        }
//        else if (c == '*')
//        {
//            if (low > 0)
//                low--;
//            high++;
//        }
//        else
//            return false;
//
//        if (high < 0) // 将*都视为左括号时，high依旧小于0，说明右括号太多了，直接返回false
//            return false;
//    }
//    return low == 0;
//}
///*
//思路3：堆栈模拟
//1）两个栈分别将"("和"*"的序号压入栈中
//2）每次遇到右括号，首先检测左括号栈中是否为空，不为空则弹出元素，否则弹出star栈
//3）最后考虑left和star栈可能存在元素，判断此时栈中元素的序号大小，如果left栈中的序号大于star中的则表明 存在"*("此种情况，直接false
//*/
//bool checkValidString3(string s)
//{
//    if (s.empty())
//        return true;
//
//    stack<int> left, star;
//    for (int i = 0; i < s.size(); i++)
//    {
//        if (s[i] == '(')
//            left.push(i);
//        else if (s[i] == '*')
//            star.push(i);
//        else
//        {
//            if (left.empty() && star.empty())
//                return false;
//            if (!left.empty())
//                left.pop();
//            else
//                star.pop();
//        }
//    }
//    while (!left.empty() && !star.empty())
//    {
//        if (left.top() > star.top())
//            return false;
//        left.pop();
//        star.pop();
//    }
//    return left.empty();
//}

///*
//684. 冗余连接
//在本问题中, 树指的是一个连通且无环的无向图。
//输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。
//附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。
//结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。
//返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。
//
//示例 1：
//输入: [[1,2], [1,3], [2,3]]
//输出: [2,3]
//解释: 给定的无向图为:
//  1
// / \
//2 - 3
//
//示例 2：
//输入: [[1,2], [2,3], [3,4], [1,4], [1,5]]
//输出: [1,4]
//解释: 给定的无向图为:
//5 - 1 - 2
//    |   |
//    4 - 3
//
//注意:
//输入的二维数组大小在 3 到 1000。
//二维数组中的整数在1到N之间，其中N是输入数组的大小。
//
//更新(2017-09-26):
//我们已经重新检查了问题描述及测试用例，明确图是无向 图。对于有向图详见冗余连接II。对于造成任何不便，我们深感歉意。
//
//思路：并查集
//1）初始每个顶点属于自己的集合，集合的代表也是自己
//2）对于每一条边的两个顶点，查询并查集，得到两个顶点所在集合的代表
//    a.如果两个代表一致，说明它们属于同一集合，出现了回环，返回该条边作为结果
//    b.如果不一致，说明两个顶点不在同一集合中，不存在回环，那么合并两个集合
//*/
//int usetFind(vector<int> &uset, int i)
//{
//    int root = i;
//    while (root != uset[root])
//        root = uset[root];
//    int parent;
//    while (i != root)
//    {
//        parent = uset[i];
//        uset[i] = root;
//        i = parent;
//    }
//    return root;
//}
//bool usetUnion(vector<int> &uset, vector<int> &rank, int i, int j)
//{
//    int root_i = usetFind(uset, i);
//    int root_j = usetFind(uset, j);
//
//    if (root_i != root_j)
//    {
//        if (rank[root_i] > rank[root_j])
//            uset[root_j] = root_i;
//        else
//        {
//            uset[root_i] = root_j;
//            if (rank[root_i] == rank[root_j])
//                ++rank[root_j];
//        }
//        return true;
//    }
//    else
//        return false;
//}
//vector<int> findRedundantConnection(const vector<vector<int>> &edges)
//{
//    int length = edges.size();
//    if (length < 3)
//        return {};
//    if (length == 3)
//        return edges[2];
//
//    vector<int> uset;
//    uset.reserve(length);
//    for (int i = 0; i < length; i++)
//        uset.push_back(i);
//    vector<int> rank(length, 0);
//
//    for (const auto &edge : edges)
//        if (!usetUnion(uset, rank, edge[0] - 1, edge[1] - 1))
//            return edge;
//    return {};
//}
//
///*
//688. “马”在棋盘上的概率
//已知一个 NxN 的国际象棋棋盘，棋盘的行号和列号都是从 0 开始。即最左上角的格子记为 (0, 0)，最右下角的记为 (N-1, N-1)。 
//现有一个 “马”（也译作 “骑士”）位于 (r, c) ，并打算进行 K 次移动。 
//如下图所示，国际象棋的 “马” 每一步先沿水平或垂直方向移动 2 个格子，然后向与之相垂直的方向再移动 1 个格子，共有 8 个可选的位置。
//现在 “马” 每一步都从可选的位置（包括棋盘外部的）中独立随机地选择一个进行移动，直到移动了 K 次或跳到了棋盘外面。
//求移动结束后，“马” 仍留在棋盘上的概率。
//
//示例：
//输入: 3, 2, 0, 0
//输出: 0.0625
//
//解释:
//输入的数据依次为 N, K, r, c
//第 1 步时，有且只有 2 种走法令 “马” 可以留在棋盘上（跳到（1,2）或（2,1））。对于以上的两种情况，各自在第2步均有且只有2种走法令 “马” 仍然留在棋盘上。
//所以 “马” 在结束后仍在棋盘上的概率为 0.0625。
//
//注意：
//N 的取值范围为 [1, 25]
//K 的取值范围为 [0, 100]
//开始时，“马” 总是位于棋盘上
//
//思路：动态规划
//1）令 f[r][c][steps] 代表马在位置 (r, c) 移动了 steps 次以后还留在棋盘上的概率，根据马的移动方式，我们有以下递归：
//    f[r][c][steps] = \sum_{dr, dc} f[r+dr][c+dc][steps-1] / 8.0
//2）根据题目我们可以知道 (dr, dc)(dr,dc) 的可能数据对是 (2, 1), (2, -1), (-2, 1), (−2,−1), (1,2), (1,−2), (−1,2),(−1,−2)。
//3）我们将使用二维的 dp 和 dp2 来存储我们的数据，而不是使用三维数组 f。dp2 代表 f[][][steps]，dp 代表 f[][][steps-1]。
//*/
//double knightProbability(int N, int K, int r, int c)
//{
//    if (N == 1 && K > 1)
//        return 0;
//    if (K == 0)
//        return 1;
//
//    static const vector<vector<int>> dr_dc = {{2,1}, {2,-1}, {-2,1}, {-2, -1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};
//    vector<vector<double>> dp(N, vector<double>(N, 0));
//    dp[r][c] = 1;
//    for (int k = 0; k < K; k++)
//    {
//        vector<vector<double>> dp2(N, vector<double>(N, 0));
//        for (int r = 0; r < N; r++)
//        {
//            for (int c = 0; c < N; c++)
//            {
//                for (const auto &drdc : dr_dc)
//                {
//                    int row = r + drdc[0];
//                    int col = c + drdc[1];
//                    if (row >= 0 && row < N && col >= 0 && col < N)
//                        dp2[r][c] += dp[row][col] / 8.0;
//                }
//            }
//        }
//        dp = std::move(dp2);
//    }
//
//    double res = 0;
//    for (int r = 0; r < N; r++)
//        for (int c = 0; c < N; c++)
//            res += dp[r][c];
//
//    return res;
//}

///*
//692. 前K个高频单词
//给一非空的单词列表，返回前 k 个出现次数最多的单词。
//返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
//
//示例 1：
//输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//输出: ["i", "love"]
//解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//    注意，按字母顺序 "i" 在 "love" 之前。
// 
//示例 2：
//输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
//输出: ["the", "is", "sunny", "day"]
//解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//    出现次数依次为 4, 3, 2 和 1 次。
// 
//注意：
//假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
//输入的单词均由小写字母组成。
//
//扩展练习：
//尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。
//*/
//vector<string> topKFrequent(const vector<string> &words, int k)
//{
//    int length = words.size();
//    if (length == 0)
//        return {};
//    if (length == 1)
//        return words;
//
//    unordered_map<string, int> m;
//    for (const auto &word : words)
//        ++m[word];
//
//    using IterType = unordered_map<string, int>::iterator;
//    vector<IterType> iters;
//    iters.reserve(m.size());
//    for (auto it = m.begin(); it != m.end(); ++it)
//        iters.push_back(it);
//
//    std::sort(iters.begin(), iters.end(), [](IterType a, IterType b)
//              {
//                  if (a->second == b->second)
//                      return a->first < b->first;
//                  return a->second > b->second;
//              });
//
//    vector<string> res;
//    res.reserve(k);
//    for (int i = 0; i < k; i++)
//        res.push_back(iters[i]->first);
//
//    return res;
//}
//
///*
//695. 岛屿的最大面积
//给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。
//你可以假设二维矩阵的四个边缘都被水包围着。
//找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
//
//示例 1:
//[[0,0,1,0,0,0,0,1,0,0,0,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,1,1,0,1,0,0,0,0,0,0,0,0],
// [0,1,0,0,1,1,0,0,1,0,1,0,0],
// [0,1,0,0,1,1,0,0,1,1,1,0,0],
// [0,0,0,0,0,0,0,0,0,0,1,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
//
//示例 2:
//[[0,0,0,0,0,0,0,0]]
//对于上面这个给定的矩阵, 返回 0。
//
//注意: 给定的矩阵grid 的长度和宽度都不超过 50。
//*/
//void maxAreaOfIslandRecursively(vector<vector<int>> &grid, const int &rows, const int &cols, int row, int col, int &area)
//{
//    if (row < 0 || row >= rows || col < 0 || col >= cols)
//        return;
//
//    if (grid[row][col] == 1)
//    {
//        ++area;
//        grid[row][col] = 0;
//
//        static const vector<vector<int>> cords = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//        for (const auto &cord : cords)
//            maxAreaOfIslandRecursively(grid, rows, cols, row + cord[0], col + cord[1], area);
//    }
//}
//int maxAreaOfIsland(vector<vector<int>> &grid)
//{
//    int rows = grid.size();
//    if (rows == 0)
//        return 0;
//    int cols = grid[0].size();
//    if (cols == 0)
//        return 0;
//
//    int res = 0;
//    for (int row = 0; row < rows; row++)
//    {
//        for (int col = 0; col < cols; col++)
//        {
//            if (grid[row][col] == 1)
//            {
//                int area = 0;
//                maxAreaOfIslandRecursively(grid, rows, cols, row, col, area);
//                if (area > res)
//                    res = area;
//            }
//        }
//    }
//    return res;
//}

///*
//698. 划分为k个相等的子集
//给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
//
//示例 1：
//输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
//输出： True
//说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
//
//注意:
//1 <= k <= len(nums) <= 16
//0 < nums[i] < 10000
//
//思路：
//1）分成k个和相等的子集，那么每个子集的和为sum(nums)/k
//2）递归深搜
//*/
//bool canPartitionKSubsetsRecursively(const vector<int> &nums, vector<bool> &visited, int idx, const int &sub_sum, int cur_sum, int k)
//{
//    if (k == 0)
//        return true;
//    if (cur_sum == 0)
//        return canPartitionKSubsetsRecursively(nums, visited, 0, sub_sum, sub_sum, k - 1);
//
//    for (int i = idx; i < nums.size(); i++)
//    {
//        if (visited[i])
//            continue;
//
//        visited[i] = true;
//        if (cur_sum - nums[i] >= 0 && canPartitionKSubsetsRecursively(nums, visited, i + 1, sub_sum, cur_sum - nums[i], k))
//            return true;
//        visited[i] = false;
//    }
//    return false;
//}
//bool canPartitionKSubsets(vector<int> &nums, int k)
//{
//    if (k == 1)
//        return true;
//
//    int sum = std::accumulate(nums.begin(), nums.end(), 0);
//    if (sum % k != 0)
//        return false;
//
//    int sub_sum = sum / k;
//    vector<bool> visited(nums.size(), false);
//    return canPartitionKSubsetsRecursively(nums, visited, 0, sub_sum, sub_sum, k);
//}
//
///*
//701. 二叉搜索树中的插入操作
//给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。
//注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。
//
//例如, 
//给定二叉搜索树:
//
//        4
//       / \
//      2   7
//     / \
//    1   3
//和 插入的值: 5
//你可以返回这个二叉搜索树:
//         4
//       /   \
//      2     7
//     / \   /
//    1   3 5
//或者这个树也是有效的:
//         5
//       /   \
//      2     7
//     / \
//    1   3
//         \
//          4
//*/
//TreeNode *insertIntoBST(TreeNode *root, int val)
//{
//    if (root == nullptr)
//        return new TreeNode(val);
//    
//    TreeNode *p = root;
//    while (true)
//    {
//        if (p->val > val)
//        {
//            if (p->left == nullptr)
//            {
//                p->left = new TreeNode(val);
//                break;
//            }
//            else
//                p = p->left;
//        }
//        else
//        {
//            if (p->right == nullptr)
//            {
//                p->right = new TreeNode(val);
//                break;
//            }
//            else
//                p = p->right;
//        }
//    }
//
//    return root;
//}

///*
//712. 两个字符串的最小ASCII删除和
//给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。
//
//示例 1:
//输入: s1 = "sea", s2 = "eat"
//输出: 231
//解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
//在 "eat" 中删除 "t" 并将 116 加入总和。
//结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
//
//示例 2:
//输入: s1 = "delete", s2 = "leet"
//输出: 403
//解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
//将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
//结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
//如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
//
//注意:
//0 < s1.length, s2.length <= 1000。
//所有字符串中的字符ASCII值在[97, 122]之间。
//
//思路：动态规划（https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/solution/liang-ge-zi-fu-chuan-de-zui-xiao-asciishan-chu-he-/）
//1）令dp[i][j]表示s1[i:]和s2[j:]两个字符串相等时所需删除字符的ASCII值的最小和
//2）如果s1[i] == s2[j]表示两字符相等，不删除，那么dp[i][j] = dp[i + 1][j + 1]
//3）否则，删除使得ASCII值最小的那个，dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j])
//*/
//int minimumDeleteSum(const string &s1, const string &s2)
//{
//    if (s1.empty())
//        return std::accumulate(s2.begin(), s2.end(), 0);
//    if (s2.empty())
//        return std::accumulate(s1.begin(), s1.end(), 0);
//
//    int length1 = s1.size(), length2 = s2.size();
//    vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
//    for (int i = length1 - 1; i >= 0; i--)
//        dp[i][length2] = dp[i + 1][length2] + s1[i];
//    for (int i = length2 - 1; i >= 0; i--)
//        dp[length1][i] = dp[length1][i + 1] + s2[i];
//
//    for (int i = length1 - 1; i >= 0; i--)
//    {
//        for (int j = length2 - 1; j >= 0; j--)
//        {
//            if (s1[i] == s2[j])
//                dp[i][j] = dp[i + 1][j + 1];
//            else
//                dp[i][j] = std::min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
//        }
//    }
//
//    return dp[0][0];
//}
//
///*
//713. 乘积小于K的子数组
//给定一个正整数数组 nums。
//找出该数组内乘积小于 k 的连续的子数组的个数。
//
//示例 1:
//输入: nums = [10,5,2,6], k = 100
//输出: 8
//解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
//需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
//
//说明:
//0 < nums.length <= 50000
//0 < nums[i] < 1000
//0 <= k < 10^6
//
//思路：双指针法（https://leetcode-cn.com/problems/subarray-product-less-than-k/solution/cheng-ji-xiao-yu-kde-zi-shu-zu-by-leetcode/）
//1）令右指针从开始到结束遍历一遍，并且右指针向右，就乘上新的数
//2）对于当前的右指针以及乘积，确定左指针的位置（左指针向右移动，则除掉一个数），使得乘积小于k
//*/
//int numSubarrayProductLessThanK(vector<int> &nums, int k)
//{
//    if (k <= 1) 
//        return 0;
//
//    int prod = 1, ans = 0, left = 0;
//    for (int right = 0; right < nums.size(); right++)
//    {
//        prod *= nums[right];
//        while (prod >= k) 
//            prod /= nums[left++];
//        ans += right - left + 1;
//    }
//    return ans;
//}

///*
//714.买卖股票的最佳时机含手续费
//给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。
//你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
//返回获得利润的最大值。
//
//示例 1:
//输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
//输出: 8
//解释: 能够达到的最大利润:
//在此处买入 prices[0] = 1
//在此处卖出 prices[3] = 8
//在此处买入 prices[4] = 4
//在此处卖出 prices[5] = 9
//总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
//
//注意:
//0 < prices.length <= 50000.
//0 < prices[i] < 50000.
//0 <= fee < 50000.
//
//思路：动态规划
//1）dp[i][j]表示第i天持有（j=1）和不持有（j=0）时达到的最大利润
//2）状态转移方程：
//    a.dp[i][1]=max(dp[i-1][1], dp[i-1][0]-prices[i])
//    b.dp[i][0]=max(dp[i-1][[0], dp[i-1][1]+prices[i]-fee)
//*/
//int maxProfit(const vector<int> &prices, int fee)
//{
//    int dp_1 = -99999, dp_0 = 0;
//    for (int i = 0; i < prices.size(); i++)
//    {
//        int t_1 = std::max(dp_1, dp_0 - prices[i]);
//        int t_0 = std::max(dp_0, dp_1 + prices[i] - fee);
//        dp_1 = t_1;
//        dp_0 = t_0;
//    }
//    return dp_0;
//}
//
///*
//718. 最长重复子数组
//给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
//
//示例 1:
//输入:
//A: [1,2,3,2,1]
//B: [3,2,1,4,7]
//输出: 3
//解释:
//长度最长的公共子数组是 [3, 2, 1]。
//
//说明:
//1 <= len(A), len(B) <= 1000
//0 <= A[i], B[i] < 100
//
//思路：动态规划
//1）dp[i][j]表示A[0:i)和B[0:j)的重复子数组的长度
//2）状态转移方程：
//    dp[i][j] = dp[i - 1][j - 1] + 1，当A[i - 1] == B[j - 1]
//3）最终结果为dp数组中最大的值
//*/
//int findLength(const vector<int> &A, const vector<int> &B)
//{
//    int length1 = A.size(), length2 = B.size();
//    int res = 0;
//    vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
//    for (int i = 1; i <= length1; i++)
//    {
//        for (int j = 1; j <= length2; j++)
//        {
//            if (A[i - 1] == B[j - 1])
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//            if (dp[i][j] > res)
//                res = dp[i][j];
//        }
//    }
//
//    return res;
//}

///*
//721. 账户合并
//给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，
//其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该帐户的邮箱地址。
//现在，我们想合并这些帐户。如果两个帐户都有一些共同的邮件地址，则两个帐户必定属于同一个人。
//请注意，即使两个帐户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。
//一个人最初可以拥有任意数量的帐户，但其所有帐户都具有相同的名称。
//合并帐户后，按以下格式返回帐户：
//每个帐户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。
//accounts 本身可以以任意顺序返回。
//
//例子 1:
//Input:
//accounts = [["John", "johnsmith@mail.com", "john00@mail.com"],
//["John", "johnnybravo@mail.com"],
//["John", "johnsmith@mail.com", "john_newyork@mail.com"],
//["Mary", "mary@mail.com"]]
//Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
//["John", "johnnybravo@mail.com"],
//["Mary", "mary@mail.com"]]
//Explanation:
//  第一个和第三个 John 是同一个人，因为他们有共同的电子邮件 "johnsmith@mail.com"。
//  第二个 John 和 Mary 是不同的人，因为他们的电子邮件地址没有被其他帐户使用。
//  我们可以以任何顺序返回这些列表，例如答案[['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
//  ['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']]仍然会被接受。
//
//注意：
//accounts的长度将在[1，1000]的范围内。
//accounts[i]的长度将在[1，10]的范围内。
//accounts[i][j]的长度将在[1，30]的范围内。
//*/
//int usetFind(vector<int> &uset, int i)
//{
//    int root = i;
//    while (root != uset[root])
//        root = uset[root];
//    int parent;
//    while (i != root)
//    {
//        parent = uset[i];
//        uset[i] = root;
//        i = parent;
//    }
//    return root;
//}
//void usetUnion(vector<int> &uset, vector<int> &rank, int i, int j)
//{
//    int root_i = usetFind(uset, i);
//    int root_j = usetFind(uset, j);
//
//    if (root_i != root_j)
//    {
//        if (rank[root_i] > rank[root_j])
//            uset[root_j] = root_i;
//        else
//        {
//            uset[root_i] = root_j;
//            if (rank[root_i] == rank[root_j])
//                ++rank[root_j];
//        }
//    }
//}
//vector<vector<string>> accountsMerge(const vector<vector<string>> &accounts)
//{
//    int length = accounts.size();
//    if (length == 1)
//        return accounts;
//
//    vector<int> uset(length);
//    vector<int> rank(length, 0);
//    for (int i = 0; i < length; i++)
//        uset[i] = i;
//
//    map<string, int> email_idx;
//    for (int i = 1; i < accounts[0].size(); i++)
//        email_idx[accounts[0][i]] = 0;
//
//    for (int i = 1; i < length; i++)
//    {
//        for (int j = 1; j < accounts[i].size(); j++)
//        {
//            const string &email = accounts[i][j];
//            if (email_idx.count(email))
//                usetUnion(uset, rank, email_idx[email], i);
//            else
//                email_idx[email] = i;
//        }
//    }
//
//    unordered_map<int, vector<string>> idx_emails;
//    for (const auto &kv : email_idx)
//    {
//        int root_idx = usetFind(uset, kv.second);
//        if (!idx_emails.count(root_idx))
//            idx_emails[root_idx].push_back(accounts[root_idx][0]);
//        idx_emails[root_idx].push_back(kv.first);
//    }
//
//    vector<vector<string>> res;
//    for (auto &kv : idx_emails)
//        res.push_back(std::move(kv.second));
//
//    return res;
//}
//
////722. 删除注释
////给一个 C++ 程序，删除程序中的注释。这个程序source是一个数组，其中source[i]表示第i行源码。 这表示每行源码由\n分隔。
////在 C++ 中有两种注释风格，行内注释和块注释。
////字符串// 表示行注释，表示//和其右侧的其余字符应该被忽略。
////字符串/* 表示一个块注释，它表示直到*/的下一个（非重叠）出现的所有字符都应该被忽略。（阅读顺序为从左到右）非重叠是指，字符串/*/并没有结束块注释，因为注释的结尾与开头相重叠。
////第一个有效注释优先于其他注释：如果字符串//出现在块注释中会被忽略。 同样，如果字符串/*出现在行或块注释中也会被忽略。
////如果一行在删除注释之后变为空字符串，那么不要输出该行。即，答案列表中的每个字符串都是非空的。
////样例中没有控制字符，单引号或双引号字符。比如，source = "string s = "/* Not a comment. */";" 不会出现在测试样例里。（此外，没有其他内容（如定义或宏）会干扰注释。）
////我们保证每一个块注释最终都会被闭合， 所以在行或块注释之外的/*总是开始新的注释。
////最后，隐式换行符可以通过块注释删除。 有关详细信息，请参阅下面的示例。
////从源代码中删除注释后，需要以相同的格式返回源代码。
////
////示例 1:
////输入:
////source = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]
////示例代码可以编排成这样:
/////*Test program */
////int main()
////{
////    // variable declaration 
////    int a, b, c;
////    /* This is a test
////       multiline
////       comment for
////       testing */
////    a = b + c;
////}
////输出: ["int main()", "{ ", "  ", "int a, b, c;", "a = b + c;", "}"]
////编排后 :
////    int main()
////{
////
////    int a, b, c;
////    a = b + c;
////}
////解释:
////第 1 行和第 6 - 9 行的字符串 /* 表示块注释。第 4 行的字符串 // 表示行注释。
////
////示例 2:
////输入:
////source = ["a/*comment", "line", "more_comment*/b"]
////输出 : ["ab"]
////解释 : 原始的 source 字符串是 "a/*comment\nline\nmore_comment*/b", 其中我们用粗体显示了换行符。删除注释后，隐含的换行符被删除，留下字符串 "ab" 用换行符分隔成数组时就是["ab"].
////
////注意 :
////    source的长度范围为[1, 100].
////    source[i]的长度范围为[0, 80].
////    每个块注释都会被闭合。
////    给定的源码中不会有单引号、双引号或其他控制字符。
//vector<string> removeComments(vector<string> &source)
//{
//    int length = source.size();
//    if (length == 0)
//        return {};
//
//    // 行号，块注释开始，行注释开始
//    int line_no = 0, block_comment_start = string::npos, line_comment_start = string::npos;
//    while (line_no < length)
//    {
//        string &line = source[line_no];
//        while (true)
//        {
//            block_comment_start = line.find("/*");
//            line_comment_start = line.find("//");
//            // 没有块或行注释
//            if (block_comment_start == string::npos && line_comment_start == string::npos)
//            {
//                ++line_no;
//                break;
//            }
//            // 只有行注释，没有块注释
//            // 块和行注释都有，但是行注释比块注释出现更早
//            else if (line_comment_start != string::npos
//                     && (block_comment_start == string::npos
//                         || block_comment_start != string::npos && line_comment_start < block_comment_start))
//            {
//                line = line.substr(0, line_comment_start);
//                ++line_no;
//                break;
//            }
//            // 只有块注释，没有行注释
//            // 块和行注释都有，但是块注释比行注释出现更早
//            else if (block_comment_start != string::npos
//                     && (line_comment_start == string::npos
//                         || line_comment_start != string::npos && line_comment_start > block_comment_start))
//            {
//                // 当前行寻找块注释的闭合位置
//                int block_comment_stop = line.find("*/", block_comment_start);
//                // 找到了
//                if (block_comment_stop != string::npos)
//                {
//                    // 非重叠情况，直接去掉块注释，接着继续处理本行，因为本行后面可能还有注释
//                    if (block_comment_stop - block_comment_start > 1)
//                    {
//                        line = line.substr(0, block_comment_start) + line.substr(block_comment_stop + 2);
//                        continue;
//                    }
//                    // 重叠情况
//                    else if (block_comment_stop - block_comment_start == 1)
//                    {
//                        // 在本行 中重叠位置之后 找 非重叠的块注释闭合位置
//                        int next_stop = line.find("*/", block_comment_stop + 2);
//                        // 找到了，直接去掉块注释，接着继续处理本行，因为本行后面可能还有注释
//                        if (next_stop != string::npos)
//                        {
//                            line = line.substr(0, block_comment_start) + line.substr(next_stop + 2);
//                            continue;
//                        }
//                    }
//                }
//
//                // 本行中没找到符合要求的块注释闭合位置，开始在其他行寻找
//                int i = line_no + 1;
//                while (i < length)
//                {
//                    block_comment_stop = source[i].find("*/");
//                    if (block_comment_stop == string::npos)
//                        source[i].clear();
//                    else
//                        break;
//                    ++i;
//                }
//                // 找到后，去掉块注释，并且把 块注释所在行里的非注释数据 合并到 当前行，这样就去掉了换行
//                source[i] = line.substr(0, block_comment_start) + source[i].substr(block_comment_stop + 2);
//                line.clear();
//                line_no = i;
//                break;
//            }
//        }
//    }
//
//    vector<string> res;
//    for (auto &line : source)
//        if (!line.empty())
//            res.push_back(std::move(line));
//    return res;
//}

///*
//725. 分隔链表
//给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
//每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
//这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
//返回一个符合上述规则的链表的列表。
//举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
//
//示例 1：
//输入:
//root = [1, 2, 3], k = 5
//输出: [[1],[2],[3],[],[]]
//解释:
//输入输出各部分都应该是链表，而不是数组。
//例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。
//第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
//最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
//
//示例 2：
//输入:
//root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
//输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
//解释:
//输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
// 
//提示:
//root 的长度范围： [0, 1000].
//输入的每个节点的大小范围：[0, 999].
//k 的取值范围： [1, 50].
//*/
//vector<ListNode *> splitListToParts(ListNode *root, int k)
//{
//    vector<ListNode *> lst;
//    auto p = root;
//    while (p != nullptr)
//    {
//        lst.push_back(p);
//        p = p->next;
//    }
//
//    int length = lst.size();
//
//    if (length <= k)
//    {
//        vector<ListNode *> res(k, nullptr);
//        for (int i = 0; i < length; i++)
//        {
//            res[i] = lst[i];
//            res[i]->next = nullptr;
//        }
//        return res;
//    }
//    else
//    {
//        int sub_len = length / k, leftover = length % k;
//        vector<ListNode *> res;
//        int idx = 0;
//        for (int i = 0; i < k; i++)
//        {
//            res.push_back(lst[idx]);
//            if (leftover > 0)
//            {
//                idx += sub_len + 1;
//                --leftover;
//            }
//            else
//                idx += sub_len;
//            lst[idx - 1]->next = nullptr;
//        }
//        return res;
//    }
//}

///*
//给定一个整数数组 asteroids，表示在同一行的行星。
//对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。
//找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。
//两颗移动方向相同的行星，永远不会发生碰撞。
//
//示例 1:
//输入:
//asteroids = [5, 10, -5]
//输出: [5, 10]
//解释:
//10 和 -5 碰撞后只剩下 10。 5 和 10 永远不会发生碰撞。
//
//示例 2:
//输入:
//asteroids = [8, -8]
//输出: []
//解释:
//8 和 -8 碰撞后，两者都发生爆炸。
//
//示例 3:
//输入:
//asteroids = [10, 2, -5]
//输出: [10]
//解释:
//2 和 -5 发生碰撞后剩下 -5。10 和 -5 发生碰撞后剩下 10。
//
//示例 4:
//输入:
//asteroids = [-2, -1, 1, 2]
//输出: [-2, -1, 1, 2]
//解释:
//-2 和 -1 向左移动，而 1 和 2 向右移动。
//由于移动方向相同的行星不会发生碰撞，所以最终没有行星发生碰撞。
//
//说明:
//数组 asteroids 的长度不超过 10000。
//每一颗行星的大小都是非零整数，范围是 [-1000, 1000] 。
//
//思路：模拟法（使用链表）
//*/
//vector<int> asteroidCollision2(const vector<int> &asteroids)
//{
//    int length = asteroids.size();
//    if (length < 2)
//        return asteroids;
//
//    list<int> lst(asteroids.begin(), asteroids.end());
//    vector<int> res;
//    auto iter_start = lst.begin();
//    while (!lst.empty())
//    {
//        // 寻找向左移动的行星
//        auto iter_neg = std::find_if(iter_start, lst.end(), [](int a) { return a < 0; });
//
//        // 没有向左的，结束
//        if (iter_neg == lst.end())
//            break;
//
//        // 是第一个，那么它永远不会和其他行星相撞，加入结果，并且从链表中移除
//        if (iter_neg == lst.begin())
//        {
//            res.push_back(*iter_neg);
//            iter_start = lst.erase(iter_neg);
//            continue;
//        }
//
//        // 尝试和它左边的向右移动的行星相撞
//        auto iter_pre = iter_neg;
//        --iter_pre;
//        // 如果它左边的行星质量较小，那么它左边的行星爆炸
//        while (iter_pre != lst.begin() && *iter_pre < std::abs(*iter_neg))
//            iter_pre = --lst.erase(iter_pre);
//        // 处理它左边的行星是第一颗并且质量比它小的情况
//        if (iter_pre == lst.begin())
//        {
//            if (*iter_pre < std::abs(*iter_neg))
//            {
//                iter_start = lst.erase(iter_pre);
//                continue;
//            }
//        }
//        // 质量相同
//        if (*iter_pre == std::abs(*iter_neg))
//        {
//            lst.erase(iter_pre);
//            iter_start = lst.erase(iter_neg);
//            continue;
//        }
//        // 它左边质量更大，那么它自己爆炸
//        else
//        {
//            iter_start = lst.erase(iter_neg);
//            continue;
//        }
//    }
//    // 把剩余的所有向右的行星加入结果
//    for (int a : lst)
//        res.push_back(a);
//    return res;
//}
///*
//思路：模拟法（使用堆栈）
//*/
//vector<int> asteroidCollision(const vector<int> &asteroids)
//{
//    int length = asteroids.size();
//    if (length < 2)
//        return asteroids;
//
//    stack<int> st;
//    vector<int> res;
//    for (int a : asteroids)
//    {
//        if (a < 0 && st.empty())
//        {
//            res.push_back(a);
//            continue;
//        }
//
//        if (a > 0)
//            st.push(a);
//        else
//        {
//            while (!st.empty() && st.top() < -a)
//                st.pop();
//            if (st.empty())
//                res.push_back(a);
//            else if (st.top() == -a)
//                st.pop();
//        }
//    }
//    stack<int> st_t;
//    while (!st.empty())
//    {
//        st_t.push(st.top());
//        st.pop();
//    }
//    while (!st_t.empty())
//    {
//        res.push_back(st_t.top());
//        st_t.pop();
//    }
//    return res;
//}

///*
//738. 单调递增的数字
//给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
//（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
//
//示例 1:
//输入: N = 10
//输出: 9
//
//示例 2:
//输入: N = 1234
//输出: 1234
//
//示例 3:
//输入: N = 332
//输出: 299
//说明: N 是在 [0, 10^9] 范围内的一个整数。
//
//思路：
//1）将数字转换成字符串s
//2）在s中寻找第一个s[i]>s[j]，0<=i<j<length
//3）从i开始往前寻找k，使得s[k]!=s[i]，0<=k<=i
//4）k处的字符减一，然后k后面的变成9
//例子：
//1247776456 -> 12477 76 456 -> 124 7776 456 -> 124 6999999
//*/
//int monotoneIncreasingDigits(int N)
//{
//    if (N <= 9)
//        return N;
//
//    string s = std::to_string(N);
//    int length = s.size();
//    int dec_stop = 1;
//    for (; dec_stop < length; dec_stop++)
//    {
//        if (s[dec_stop] < s[dec_stop - 1])
//            break;
//    }
//    if (dec_stop == length)
//        return N;
//
//    char target = s[dec_stop - 1];
//    int dec_start = dec_stop - 2;
//    for (; dec_start >= 0; dec_start--)
//    {
//        if (s[dec_start] != target)
//            break;
//    }
//    ++dec_start;
//    s[dec_start] -= 1;
//    for (int i = dec_start + 1; i < length; i++)
//        s[i] = '9';
//
//    return std::stoi(s);
//}
//
///*
//739. 每日温度
//根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。
//如果之后都不会升高，请在该位置用 0 来代替。
//例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
//提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
//
//思路：单调栈
//*/
//vector<int> dailyTemperatures(const vector<int> &T)
//{
//    int length = T.size();
//    if (length == 1)
//        return {0};
//
//    stack<int> st;
//    vector<int> res(length, 0);
//    for (int i = length - 1; i >= 0; i--)
//    {
//        while (!st.empty() && T[i] >= T[st.top()])
//            st.pop();
//        if (!st.empty())
//            res[i] = st.top() - i;
//        st.push(i);
//    }
//    return res;
//}

///*
//740.删除与获得点数
//给定一个整数数组 nums ，你可以对它进行一些操作。
//每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。
//开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
//
//示例 1:
//输入: nums = [3, 4, 2]
//输出: 6
//解释:
//删除 4 来获得 4 个点数，因此 3 也被删除。
//之后，删除 2 来获得 2 个点数。总共获得 6 个点数。
//
//示例 2:
//输入: nums = [2, 2, 3, 3, 3, 4]
//输出: 9
//解释:
//删除 3 来获得 3 个点数，接着要删除两个 2 和 4 。
//之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
//总共获得 9 个点数。
//
//注意:
//nums的长度最大为20000。
//每个整数nums[i]的大小都在[1, 10000]范围内。
//
//思路：问题转化+动态规划
//1）将nums转化为另一个数组num_cnt，其中下标为数字，值为该数字对应的个数
//2）类似于“213.打家劫舍Ⅱ”，得到类似的递推关系式：dp[num] = max(dp[num - 1], dp[num - 2] + num * num_cnt[num])
//*/
//int deleteAndEarn(const vector<int> &nums)
//{
//    int length = nums.size();
//    if (length == 0)
//        return 0;
//    if (length == 1)
//        return nums[0];
//
//    int max_val = *std::max_element(nums.begin(), nums.end());
//    vector<int> num_cnt(max_val + 1, 0);
//    for (int num : nums)
//        ++num_cnt[num];
//
//    vector<int> dp(max_val + 1, 0);
//    dp[1] = num_cnt[1];
//    for (int i = 2; i < max_val + 1; i++)
//        dp[i] = std::max(dp[i - 1], dp[i - 2] + i * num_cnt[i]);
//
//    return dp[max_val];
//}
//
///*
//743. 网络延迟时间
//有 N 个网络节点，标记为 1 到 N。
//给定一个列表 times，表示信号经过有向边的传递时间。 times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w 是一个信号从源节点传递到目标节点的时间。
//现在，我们向当前的节点 K 发送了一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1。
//
//注意:
//N 的范围在 [1, 100] 之间。
//K 的范围在 [1, N] 之间。
//times 的长度在 [1, 6000] 之间。
//所有的边 times[i] = (u, v, w) 都有 1 <= u, v <= N 且 0 <= w <= 100。
//
//思路：最短路径算法（Floyd，也可以用其他方法）
//*/
//int networkDelayTime(const vector<vector<int>> &times, int N, int K)
//{
//    vector<vector<long long>> graph(N + 1, vector<long long>(N + 1, INT_MAX));
//    for (int i = 1; i <= N; i++)
//        graph[i][i] = 0;
//    for (const auto &time : times)
//        graph[time[0]][time[1]] = time[2];
//
//    for (int k = 1; k <= N; k++) // k放最外层
//        for (int i = 1; i <= N; i++)
//            for (int j = 1; j <= N; j++)
//                if (graph[i][j] > graph[i][k] + graph[k][j])
//                    graph[i][j] = graph[i][k] + graph[k][j];
//
//    int res = -1;
//    for (int i = 1; i <= N; i++)
//    {
//        if (graph[K][i] == INT_MAX)
//            return -1;
//        if (graph[K][i] > res)
//            res = graph[K][i];
//    }
//    return res;
//}

///*
//752. 打开转盘锁
//你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
//每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
//锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
//列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
//字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
//
//示例 1:
//输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
//输出：6
//解释：
//可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
//注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
//因为当拨动到 "0102" 时这个锁就会被锁定。
//
//示例 2:
//输入: deadends = ["8888"], target = "0009"
//输出：1
//解释：
//把最后一位反向旋转一次即可 "0000" -> "0009"。
//
//示例 3:
//输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
//输出：-1
//解释：
//无法旋转到目标数字且不被锁定。
//
//示例 4:
//输入: deadends = ["0000"], target = "8888"
//输出：-1
// 
//提示：
//死亡列表 deadends 的长度范围为 [1, 500]。
//目标数字 target 不会在 deadends 之中。
//每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
//
//思路：双端BFS
//*/
//int openLock(const vector<string> &deadends, const string &target)
//{
//    unordered_set<string> deads(deadends.begin(), deadends.end());
//    if (deads.count("0000"))
//        return -1;
//    if (target == "0000")
//        return 0;
//
//    unordered_set<string> src = {"0000"}, dest = {target};
//    int step = 0;
//    while (!src.empty() && !dest.empty())
//    {
//        ++step;
//        unordered_set<string> temp;
//        for (string str : src)
//        {
//            for (int i = 0; i < 4; i++)
//            {
//                char c = str[i];
//                for (int j = -1; j < 2; j += 2)
//                {
//                    str[i] += j;
//                    if (str[i] > '9')
//                        str[i] = '0';
//                    if (str[i] < '0')
//                        str[i] = '9';
//                    if (!deads.count(str))
//                    {
//                        if (dest.count(str))
//                            return step;
//                        temp.insert(str);
//                    }
//                    str[i] = c;
//                }
//            }
//        }
//        if (dest.size() < temp.size())
//        {
//            src = dest;
//            dest = std::move(temp);
//        }
//        else
//            src = std::move(temp);
//    }
//    return -1;
//}
//
///*
//756. 金字塔转换矩阵
//现在，我们用一些方块来堆砌一个金字塔。 每个方块用仅包含一个字母的字符串表示，例如 “Z”。
//使用三元组表示金字塔的堆砌规则如下：
//(A, B, C) 表示，“C”为顶层方块，方块“A”、“B”分别作为方块“C”下一层的的左、右子块。当且仅当(A, B, C)是被允许的三元组，我们才可以将其堆砌上。
//初始时，给定金字塔的基层 bottom，用一个字符串表示。一个允许的三元组列表 allowed，每个三元组用一个长度为 3 的字符串表示。
//如果可以由基层一直堆到塔尖返回true，否则返回false。
//
//示例 1:
//输入: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
//输出: true
//解析:
//可以堆砌成这样的金字塔:
//    A
//   / \
//  D   E
// / \ / \
//X   Y   Z
//因为符合('X', 'Y', 'D'), ('Y', 'Z', 'E') 和 ('D', 'E', 'A') 三种规则。
//
//示例 2:
//输入: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
//输出: false
//解析:
//无法一直堆到塔尖。
//
//注意, 允许存在三元组(A, B, C)和 (A, B, D) ，其中 C != D.
//
//注意：
//bottom 的长度范围在 [2, 8]。
//allowed 的长度范围在[0, 200]。
//方块的标记字母范围为{'A', 'B', 'C', 'D', 'E', 'F', 'G'}。
//
//思路：BFS（广搜）超时
//*/
//void pyramidTransitionRecursively(const vector<vector<char>> &next, string &cur, int idx, unordered_set<string> &temp)
//{
//    if (idx >= next.size())
//    {
//        temp.insert(cur);
//        return;
//    }
//
//    for (char c : next[idx])
//    {
//        cur.push_back(c);
//        pyramidTransitionRecursively(next, cur, idx + 1, temp);
//        cur.pop_back();
//    }
//}
//bool pyramidTransition(const string &bottom, const vector<string> &allowed)
//{
//    if (allowed.size() == 0)
//        return false;
//
//    unordered_map<string, vector<char>> m;
//    for (const auto &allow : allowed)
//        m[allow.substr(0, 2)].push_back(allow[2]);
//
//    int step = bottom.size() - 1;
//    unordered_set<string> source = {bottom};
//    while (step > 0)
//    {
//        --step;
//        unordered_set<string> temp;
//        for (string level : source)
//        {
//            vector<vector<char>> next;
//            bool is_ok = true;
//            for (int i = 0; i < level.size() - 1; i++)
//            {
//                string t = level.substr(i, 2);
//                if (!m.count(t))
//                {
//                    is_ok = false;
//                    break;
//                }
//                next.push_back(m[t]);
//            }
//            if (!is_ok)
//                continue;
//            else
//            {
//                string cur;
//                pyramidTransitionRecursively(next, cur, 0, temp);
//            }
//        }
//        if (temp.empty())
//            return false;
//        source = std::move(temp);
//    }
//    return true;
//}
//// 思路2：深搜
//bool pyramidTransitionRecusively2(unordered_map<string, vector<char>> &m, const string &bottom)
//{
//    if (bottom.size() == 1)
//        return true;
//
//    vector<vector<char>> next;
//    for (int i = 0; i < bottom.size() - 1; i++)
//    {
//        string t = bottom.substr(i, 2);
//        if (!m.count(t))
//            return false;
//        next.push_back(m[t]);
//    }
//
//    string cur;
//    unordered_set<string> temp;
//    pyramidTransitionRecursively(next, cur, 0, temp);
//    for (const auto &parent : temp)
//        if (pyramidTransitionRecusively2(m, parent))
//            return true;
//    return false;
//}
//bool pyramidTransition2(const string &bottom, const vector<string> &allowed)
//{
//    if (allowed.size() == 0)
//        return false;
//
//    unordered_map<string, vector<char>> m;
//    for (const auto &allow : allowed)
//        m[allow.substr(0, 2)].push_back(allow[2]);
//
//    return pyramidTransitionRecusively2(m, bottom);
//}

///*
//763.划分字母区间
//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
//
//示例 1:
//输入: S = "ababcbacadefegdehijhklij"
//输出: [9,7,8]
//解释:
//划分结果为 "ababcbaca", "defegde", "hijhklij"。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
//
//注意:
//S的长度在[1, 500]之间。
//S只包含小写字母'a'到'z'。
//
//思路：
//1）先扫描一遍，记录每个字符最后出现的下标
//2）分段，根据当前字符得到最后出现的下标，然后扫描当前下标到最后下标中的字符，同时更新最后下标
//*/
//vector<int> partitionLabels(const string &S)
//{
//    int length = S.size();
//    if (length == 1)
//        return {1};
//
//    vector<int> chr_lstidx(26, -1);
//    for (int i = 0; i < length; i++)
//        chr_lstidx[S[i] - 'a'] = i;
//
//    vector<int> res;
//    int idx = 0;
//    int pre_stop = -1;
//    while (idx < length)
//    {
//        int stop = chr_lstidx[S[idx] - 'a'];
//        if (stop == idx)
//        {
//            res.push_back(1);
//            pre_stop = stop;
//            ++idx;
//        }
//        else
//        {
//            for (++idx; idx < stop; ++idx)
//            {
//                if (chr_lstidx[S[idx] - 'a'] > stop)
//                    stop = chr_lstidx[S[idx] - 'a'];
//            }
//            res.push_back(stop - pre_stop);
//            pre_stop = stop;
//            ++idx;
//        }
//    }
//    return res;
//}
//
///*
//764. 最大加号标志
//在一个大小在 (0, 0) 到 (N-1, N-1) 的2D网格 grid 中，除了在 mines 中给出的单元为 0，其他每个单元都是 1。
//网格中包含 1 的最大的轴对齐加号标志是多少阶？返回加号标志的阶数。如果未找到加号标志，则返回 0。
//一个 k" 阶由 1 组成的“轴对称”加号标志具有中心网格  grid[x][y] = 1 ，以及4个从中心向上、向下、向左、向右延伸，长度为 k-1，由 1 组成的臂。
//下面给出 k" 阶“轴对称”加号标志的示例。注意，只有加号标志的所有网格要求为 1，别的网格可能为 0 也可能为 1。
//
//k 阶轴对称加号标志示例:
//阶 1:
//000
//010
//000
//阶 2:
//00000
//00100
//01110
//00100
//00000
//阶 3:
//0000000
//0001000
//0001000
//0111110
//0001000
//0001000
//0000000
// 
//示例 1：
//输入: N = 5, mines = [[4, 2]]
//输出: 2
//解释:
//11111
//11111
//11111
//11111
//11011
//在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
// 
//示例 2：
//输入: N = 2, mines = []
//输出: 1
//解释:
//11
//11
//没有 2 阶加号标志，有 1 阶加号标志。
//
//示例 3：
//输入: N = 1, mines = [[0, 0]]
//输出: 0
//解释:
//0
//没有加号标志，返回 0 。
//
//提示：
//整数N 的范围： [1, 500].
//mines 的最大长度为 5000.
//mines[i] 是长度为2的由2个 [0, N-1] 中的数组成.
//(另外,使用 C, C++, 或者 C# 编程将以稍小的时间限制进行​​判断.)
//
//思路1：
//1）用四个二维数组记录当前位置左上右下四个方向连续1的个数
//2）那么当前位置的阶就是左上右下四个方向1的个数的最小值
//3）最后结果就是左右位置的阶的最大值
//*/
//int orderOfLargestPlusSign(int N, const vector<vector<int>> &mines)
//{
//    if (mines.empty())
//        return N % 2 == 0 ? N / 2 : (N + 1) / 2;
//
//    vector<vector<int>> m(N, vector<int>(N, 1));
//    for (const auto &mine : mines)
//        m[mine[0]][mine[1]] = 0;
//
//    vector<vector<int>> len_left(N + 1, vector<int>(N + 1, 0));
//    auto len_up = len_left, len_rigth = len_left, len_down = len_left;
//    for (int row = 1; row <= N; row++)
//    {
//        for (int col = 1; col <= N; col++)
//        {
//            if (m[row - 1][col - 1] == 1)
//            {
//                len_left[row][col] = len_left[row][col - 1] + 1;
//                len_up[row][col] = len_up[row - 1][col] + 1;
//            }
//            if (m[N - row][N - col] == 1)
//            {
//                len_rigth[N - row][N - col] = len_rigth[N - row][N - col + 1] + 1;
//                len_down[N - row][N - col] = len_down[N - row + 1][N - col] + 1;
//            }
//        }
//    }
//    int res = 0;
//    for (int row = 0; row < N; row++)
//        for (int col = 0; col < N; col++)
//            res = std::max(res, std::min({len_left[row + 1][col + 1], 
//                                          len_up[row + 1][col + 1], 
//                                          len_rigth[row][col], 
//                                          len_down[row][col]}));
//
//    return res;
//}
///*
//思路2：
//1）要求是“+”字形，那么遍历所有的“+”的中心，即对角线元素
//2）以中心元素所在行和列开始，求左上右下四个方向连续1的个数，并更新
//*/
//int orderOfLargestPlusSign2(int N, const vector<vector<int>> &mines)
//{
//    vector<vector<int>> grid(N, vector<int>(N, N)); //初始化所有点都为N
//    for (const auto &mine : mines)
//        grid[mine[0]][mine[1]] = 0;
//
//    for (int k = 0; k < N; ++k) //k代表第k行，第k列
//    { 
//        int leftOne = 0, rightOne = 0, upOne = 0, downOne = 0; //分别代表上下左右四个方向连续的连续非0的个数
//        for (int i = 0, j = N - 1; i < N; ++i, --j)
//        {
//            //第k行的左边扫描
//            leftOne = (grid[k][i] == 0 ? 0 : leftOne + 1);
//            grid[k][i] = min(grid[k][i], leftOne);
//            //第k行的右边扫描
//            rightOne = (grid[k][j] == 0 ? 0 : rightOne + 1);
//            grid[k][j] = min(grid[k][j], rightOne);
//            //第k列的上边扫描
//            upOne = (grid[i][k] == 0 ? 0 : upOne + 1);
//            grid[i][k] = min(grid[i][k], upOne);
//            //第k列的下边扫描
//            downOne = (grid[j][k] == 0 ? 0 : downOne + 1);
//            grid[j][k] = min(grid[j][k], downOne);
//        }
//    }
//
//    //最后寻找最大值
//    int maxRes = 0;
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < N; ++j)
//        {
//            maxRes = max(maxRes, grid[i][j]);
//        }
//    }
//    return maxRes;
//}

///*
//767. 重构字符串
//给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
//若可行，输出任意可行的结果。若不可行，返回空字符串。
//
//示例 1:
//输入: S = "aab"
//输出: "aba"
//
//示例 2:
//输入: S = "aaab"
//输出: ""
//
//注意:
//S 只包含小写字母并且长度在[1, 500]区间内。
//
//思路：
//1）统计每个字符及其个数
//2）每次取个数最多的两个字符进行构造
//*/
//string reorganizeString(const string &S)
//{
//    int length = S.size();
//    if (length < 2)
//        return S;
//
//    // 统计字符及其个数
//    unordered_map<char, int> chr_cnt;
//    for (char c : S)
//        ++chr_cnt[c];
//    // 只有一个字符，并且其个数大于1
//    if (chr_cnt.size() == 1)
//        return {};
//
//    using Iter = unordered_map<char, int>::iterator;
//    vector<Iter> vec;
//    vec.reserve(chr_cnt.size());
//    for (auto iter = chr_cnt.begin(); iter != chr_cnt.end(); ++iter)
//        vec.push_back(iter);
//    // 按个数从大到小排序
//    std::sort(vec.begin(), vec.end(), [](Iter a, Iter b)
//              {
//                  return a->second > b->second;
//              });
//
//    string res;
//    res.reserve(length);
//    // 每次取个数最大的两个字符进行构造
//    while (vec[0]->second > 0)
//    {
//        if (vec[1]->second == 0) // 个数第二大的为0
//        {
//            if (vec[0]->second == 1) // 个数第一大的刚好是1，说明只剩1个，直接加入
//            {
//                res.push_back(vec[0]->first);
//                break;
//            }
//            else // 个数第一大的大于1，肯定不行
//                return {};
//        }
//        else if (vec[0]->second == vec[1]->second) // 个数第一大和第二大的相同，一对一全部构造完
//        {
//            for (int i = 0; i < vec[0]->second; i++)
//            {
//                res.push_back(vec[0]->first);
//                res.push_back(vec[1]->first);
//            }
//            vec[0]->second = 0;
//            vec[1]->second = 0;
//        }
//        else // 个数第一大的大于个数第二大的，一对一构造，剩余的进入下一次迭代（注意个数第一大的字符放在前面，这样就不会和剩余的相邻）
//        {
//            for (int i = 0; i < vec[1]->second; i++)
//            {
//                res.push_back(vec[0]->first);
//                res.push_back(vec[1]->first);
//            }
//            vec[0]->second -= vec[1]->second;
//            vec[1]->second = 0;
//        }
//        // 重新排序
//        std::sort(vec.begin(), vec.end(), [](Iter a, Iter b)
//                  {
//                      return a->second > b->second;
//                  });
//    }
//    return res;
//}
//
///*
//769. 最多能完成排序的块
//数组arr是[0, 1, ..., arr.length - 1]的一种排列，我们将这个数组分割成几个“块”，并将这些块分别进行排序。
//之后再连接起来，使得连接的结果和按升序排序后的原数组相同。
//我们最多能将数组分成多少块？
//
//示例 1:
//输入: arr = [4,3,2,1,0]
//输出: 1
//解释:
//将数组分成2块或者更多块，都无法得到所需的结果。
//例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。
//
//示例 2:
//输入: arr = [1,0,2,3,4]
//输出: 4
//解释:
//我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
//然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。
//
//注意:
//arr 的长度在 [1, 10] 之间。
//arr[i]是 [0, 1, ..., arr.length - 1]的一种排列。
//
//思路：类似 763.划分字母区间
//*/
//int maxChunksToSorted(const vector<int> &arr)
//{
//    int length = arr.size();
//    if (length == 1)
//        return 1;
//
//    int res = 0;
//    int pre_stop = -1;
//    int stop = 0;
//    while (stop < length)
//    {
//        if (stop == arr[stop])
//        {
//            ++res;
//            pre_stop = stop;
//            ++stop;
//        }
//        else
//        {
//            stop = arr[stop];
//            for (int i = pre_stop + 2; i <= stop; i++)
//            {
//                if (arr[i] > stop)
//                    stop = arr[i];
//            }
//            ++res;
//            pre_stop = stop;
//            ++stop;
//        }
//    }
//    return res;
//}
//// 思路2：从左往右遍历，当遍历到第i个位置时，如果可以切分为块，那前i个位置的最大值一定等于i
//int maxChunksToSorted2(const vector<int> &arr)
//{
//    int length = arr.size(), res = 0, max_val = 0;
//    for (int i = 0; i < length; i++)
//    {
//        max_val = std::max(max_val, arr[i]);
//        if (max_val == i)
//            res++;
//    }
//    return res;
//}

///*
//775. 全局倒置与局部倒置
//数组 A 是 [0, 1, ..., N - 1] 的一种排列，N 是数组 A 的长度。
//全局倒置指的是 i,j 满足 0 <= i < j < N 并且 A[i] > A[j] ，局部倒置指的是 i 满足 0 <= i < N 并且 A[i] > A[i+1] 。
//当数组 A 中全局倒置的数量等于局部倒置的数量时，返回 true 。
//
//示例 1:
//输入: A = [1,0,2]
//输出: true
//解释: 有 1 个全局倒置，和 1 个局部倒置。
//
//示例 2:
//输入: A = [1,2,0]
//输出: false
//解释: 有 2 个全局倒置，和 1 个局部倒置。
//
//注意:
//A 是 [0, 1, ..., A.length - 1] 的一种排列
//A 的长度在 [1, 5000]之间
//这个问题的时间限制已经减少了。
//
//思路：
//1）全局倒置就是逆序对
//2）统计逆序对的个数和局部倒置的个数，然后比较
//*/
//void merge(vector<int> &B, int start, int middle, int stop, int &global)
//{
//    vector<int> t(stop - start + 1);
//    int idx1 = start, idx2 = middle + 1, idx = 0;
//    while (idx1 <= middle && idx2 <= stop)
//    {
//        if (B[idx1] > B[idx2])
//        {
//            global += idx2 - idx1;
//            t[idx++] = B[idx2];
//            ++idx2;
//        }
//        else
//        {
//            t[idx++] = B[idx1];
//            ++idx1;
//        }
//    }
//
//    if (idx1 > middle)
//    {
//        while (idx2 <= stop)
//            t[idx++] = B[idx2++];
//    }
//    else
//    {
//        while (idx1 <= middle)
//            t[idx++] = B[idx1++];
//    }
//
//    idx = 0;
//    for (int i = start; i <= stop; i++)
//        B[i] = t[idx++];
//}
//void mergeSort(vector<int> &B, int start, int stop, int &global)
//{
//    if (start >= stop)
//        return;
//
//    int middle = (start + stop) / 2;
//    mergeSort(B, start, middle, global);
//    mergeSort(B, middle + 1, stop, global);
//    merge(B, start, middle, stop, global);
//}
//bool isIdealPermutation(vector<int> &A)
//{
//    int length = A.size();
//    if (length <= 2)
//        return true;
//
//    int local = 0;
//    for (int i = 0; i < length - 1; i++)
//    {
//        if (A[i] > A[i + 1])
//            ++local;
//    }
//
//    int global = 0;
//    auto &B = A;
//    mergeSort(B, 0, length - 1, global);
//
//    return local == global;
//}
///*
//思路2：
//1）局部倒置也是全局倒置，全局倒置个数>=局部倒置个数
//2）要让它们相等，那只能是相邻位置交换，并且每个位置最多交换一次，意味着||i-A[i]||<=1，如果>1，就变成了全局倒置
//*/
//bool isIdealPermutation2(vector<int> &A)
//{
//    int length = A.size();
//    if (length <= 2)
//        return true;
//
//    for (int i = 0; i < length; i++)
//    {
//        if (std::abs(i - A[i]) > 1)
//            return false;
//    }
//    return true;
//}
//
///*
//777. 在LR字符串中交换相邻字符
//在一个由 'L' , 'R' 和 'X' 三个字符组成的字符串（例如"RXXLRXRXL"）中进行移动操作。
//一次移动操作指用一个"LX"替换一个"XL"，或者用一个"XR"替换一个"RX"。
//现给定起始字符串start和结束字符串end，请编写代码，当且仅当存在一系列移动操作使得start可以转换成end时， 返回True。
//
//示例 :
//输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
//输出: True
//解释:
//我们可以通过以下几步将start转换成end:
//RXXLRXRXL ->
//XRXLRXRXL ->
//XRLXRXRXL ->
//XRLXXRRXL ->
//XRLXXRRLX
//
//注意:
//1 <= len(start) = len(end) <= 10000。
//start和end中的字符串仅限于'L', 'R'和'X'。
//
//思路：广度优先搜索（超时）
//*/
//bool canTransform(const string &start, const string &end)
//{
//    if (start == end)
//        return true;
//
//    unordered_set<string> begin = {start}, target = {end};
//    bool is_reversed = false;
//    while (!begin.empty() && !target.empty())
//    {
//        unordered_set<string> t;
//        for (string s : begin)
//        {
//            for (int i = 0; i < s.size() - 1; i++)
//            {
//                if (!is_reversed)
//                {
//                    if (s[i] == 'X' && s[i + 1] == 'L')
//                    {
//                        std::swap(s[i], s[i + 1]);
//                        if (target.count(s))
//                            return true;
//                        t.insert(s);
//                        std::swap(s[i], s[i + 1]);
//                    }
//                    else if (s[i] == 'R' && s[i + 1] == 'X')
//                    {
//                        std::swap(s[i], s[i + 1]);
//                        if (target.count(s))
//                            return true;
//                        t.insert(s);
//                        std::swap(s[i], s[i + 1]);
//                    }
//                }
//                else
//                {
//                    if (s[i] == 'L' && s[i + 1] == 'X')
//                    {
//                        std::swap(s[i], s[i + 1]);
//                        if (target.count(s))
//                            return true;
//                        t.insert(s);
//                        std::swap(s[i], s[i + 1]);
//                    }
//                    else if (s[i] == 'X' && s[i + 1] == 'R')
//                    {
//                        std::swap(s[i], s[i + 1]);
//                        if (target.count(s))
//                            return true;
//                        t.insert(s);
//                        std::swap(s[i], s[i + 1]);
//                    }
//                }
//            }
//        }
//
//        if (t.size() < target.size())
//            begin = std::move(t);
//        else
//        {
//            begin = std::move(target);
//            target = std::move(t);
//            is_reversed = !is_reversed;
//        }
//    }
//    return false;
//}
///*
//1.把所有的X去除，两个字符串应该是相等的
//2.定义两个指针，从头开始对比，遇到X直接跳过，因为根据题意，X可以和R，L交换位置。
//    a.当两个指针分别遇到第一个非X的字符时，对比，如果不同，不存在移动操作，因为LR是不能互相换位的。
//    b.两指针都遇到R字符时，如果start字符串的指针位置比end靠后，不存在，因为移动操作只能使R右移。
//    c.两指针都遇到L字符时，如果start字符串的指针位置比end靠前，不存在，因为移动操作只能使L左移。
//*/
//bool canTransform2(const string &start, const string &end)
//{
//    int i = 0, j = 0;
//    int length1 = start.size(), length2 = end.size();
//    while (i < length1 && j < length2)
//    {
//        while (i < length1 && start[i] == 'X')
//            ++i;
//        if (i == length1)
//            break;
//        while (j < length2 && end[j] == 'X')
//            ++j;
//        if (j == length2)
//            break;
//
//        if (start[i] != end[j])
//            return false;
//
//        if (start[i] == 'L' && i < j)
//            return false;
//
//        if (start[i] == 'R' && i > j)
//            return false;
//        ++i;
//        ++j;
//    }
//
//    if (i == length1)
//        for (; j < length2; j++)
//            if (end[j] != 'X')
//                return false;
//
//    if (j == length2)
//        for (; i < length1; i++)
//            if (start[i] != 'X')
//                return false;
//
//    return true;
//}

///*
//779. 第K个语法符号
//在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。
//给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）
//
//例子:
//输入: N = 1, K = 1
//输出: 0
//
//输入: N = 2, K = 1
//输出: 0
//
//输入: N = 2, K = 2
//输出: 1
//
//输入: N = 4, K = 5
//输出: 1
//
//解释:
//第一行: 0
//第二行: 01
//第三行: 0110
//第四行: 01101001
//
//注意：
//N 的范围 [1, 30].
//K 的范围 [1, 2^(N-1)].
//
//思路：https://leetcode-cn.com/problems/k-th-symbol-in-grammar/solution/di-kge-yu-fa-fu-hao-by-ikaruga-2/
//*/
//int kthGrammar(int N, int K)
//{
//    if (N == 1) 
//        return 0;
//    return (kthGrammar(N - 1, (K - 1) / 2 + 1) == 0) ? ((K - 1) % 2) : 1 - ((K - 1) % 2);
//}
//// 思路2：https://leetcode-cn.com/problems/k-th-symbol-in-grammar/solution/di-gui-zhi-jie-fen-xi-di-n-xing-di-k-ge-shu-de-she/
//int kthGrammar(int N, int K)
//{
//    if (N == 1) 
//        return 0;
//    if (N == 2) 
//        return K == 1 ? 0 : 1;
//
//    // 计算上一行的长度（本行长度折半）
//    int pre_len = (1 << (N - 1)) / 2;
//
//    if (K <= pre_len)
//        // 位于前半段，则等价于上一行同样位置的值
//        return kthGrammar(N - 1, K);
//    else
//        // 位于后半段，则等价于上一行相应位置的值取反
//        // 返回值非 0 即 1，因此直接用 1 去减即可
//        return 1 - kthGrammar(N - 1, K - pre_len);
//}
//
///*
//781. 森林中的兔子
//森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。我们将这些回答放在 answers 数组里。
//返回森林中兔子的最少数量。
//
//示例:
//输入: answers = [1, 1, 2]
//输出: 5
//解释:
//两只回答了 "1" 的兔子可能有相同的颜色，设为红色。
//之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
//设回答了 "2" 的兔子为蓝色。
//此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。
//因此森林中兔子的最少数量是 5: 3 只回答的和 2 只没有回答的。
//
//输入: answers = [10, 10, 10]
//输出: 11
//
//输入: answers = []
//输出: 0
//
//说明:
//answers 的长度最大为1000。
//answers[i] 是在 [0, 999] 范围内的整数。
//
//思路：
//1）统计不同回答的个数
//2）对于一个回答answer，如果有answer+1个，说明有answer+1只兔子同颜色，如果超过，那么每answer+1个组成另外一种颜色
//*/
//int numRabbits(const vector<int> &answers)
//{
//    int length = answers.size();
//    if (length == 0)
//        return 0;
//    if (length == 1)
//        return answers.back() + 1;
//
//    unordered_map<int, int> ans_cnt;
//    for (int answer : answers)
//        ++ans_cnt[answer];
//
//    int res = 0;
//    for (const auto &kv : ans_cnt)
//    {
//        int answer = kv.first, cnt = kv.second;
//        if (cnt % (answer + 1) == 0) // 刚好可以构成cnt/(answer+1)种颜色，每种颜色有answer+1只兔子
//            res += (answer + 1) * (cnt / (answer + 1)); // res += cnt;
//        else // 构成cnt/(answer+1)+1种颜色，每种颜色有answer+1只兔子
//            res += (answer + 1) * (cnt / (answer + 1) + 1);
//    }
//    return res;
//}

///*
//785. 判断二分图
//给定一个无向图graph，当这个图为二分图时返回true。
//如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。
//graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。
//这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。
//
//示例 1:
//输入: [[1,3], [0,2], [1,3], [0,2]]
//输出: true
//解释:
//无向图如下:
//0----1
//|    |
//|    |
//3----2
//我们可以将节点分成两组: {0, 2} 和 {1, 3}。
//
//示例 2:
//输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
//输出: false
//解释:
//无向图如下:
//0----1
//| \  |
//|  \ |
//3----2
//我们不能将节点分割成两个独立的子集。
//
//注意:
//graph 的长度范围为 [1, 100]。
//graph[i] 中的元素的范围为 [0, graph.length - 1]。
//graph[i] 不会包含 i 或者有重复的值。
//图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。
//
//思路：染色，广度优先搜索
//*/
//bool isBipartiteRecursively(const vector<vector<int>> &graph, vector<int> &vertices, vector<bool> &visited, int vertex, int A_or_B)
//{
//    if (visited[vertex])
//        return true;
//
//    for (int ver : graph[vertex])
//    {
//        if (vertices[ver] != -1 && vertices[ver] != 1 - A_or_B)
//            return false;
//        vertices[ver] = 1 - A_or_B;
//    }
//    visited[vertex] = true;
//
//    for (int ver : graph[vertex])
//    {
//        if (isBipartiteRecursively(graph, vertices, visited, ver, 1 - A_or_B) == false)
//            return false;
//    }
//    return true;
//}
//bool isBipartite(const vector<vector<int>> &graph)
//{
//    int length = graph.size();
//    if (length == 1)
//    {
//        if (graph[0].empty())
//            return true;
//        return false;
//    }
//    if (length == 2)
//        return true;
//
//    vector<int> vertices(length, -1);
//    vector<bool> visited(length, false);
//    for (int i = 0; i < length; i++)
//    {
//        if (graph[i].empty())
//            visited[i] = true;
//    }
//
//    for (int i = 0; i < length; i++)
//    {
//        if (!visited[i])
//        {
//            if (isBipartiteRecursively(graph, vertices, visited, i, 0) == false)
//                return false;
//        }
//    }
//
//    return true;
//}
//思路：染色，深度优先搜索
//bool isBipartiteRecursively(const vector<vector<int>> &graph, vector<int> &colors, int vertex, int color)
//{
//    if (colors[vertex] != -1 && colors[vertex] != color)
//        return false;
//    if (colors[vertex] != -1 && colors[vertex] == color)
//        return true;
//
//    colors[vertex] = color;
//    for (int vtx : graph[vertex])
//    {
//        if (isBipartiteRecursively(graph, colors, vtx, 1 - color) == false)
//            return false;
//    }
//    return true;
//}
//bool isBipartite(const vector<vector<int>> &graph)
//{
//    int length = graph.size();
//    vector<int> colors(length, -1);
//    for (int i = 0; i < length; i++)
//    {
//        if (colors[i] == -1)
//        {
//            if (isBipartiteRecursively(graph, colors, i, 0) == false)
//                return false;
//        }
//    }
//
//    return true;
//}

///*
//787. K 站中转内最便宜的航班
//有 n 个城市通过 m 个航班连接。每个航班都从城市 u 开始，以价格 w 抵达 v。
//现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到从 src 到 dst 最多经过 k 站中转的最便宜的价格。
//如果没有这样的路线，则输出 -1。
//
//示例 1:
//输入:
//n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
//src = 0, dst = 2, k = 1
//输出: 200
//解释:
//从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
//
//示例 2:
//输入:
//n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
//src = 0, dst = 2, k = 0
//输出: 500
//解释:
//从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
//
//提示：
//n 范围是 [1, 100]，城市标签从 0 到 n - 1.
//航班数量范围是 [0, n * (n - 1) / 2].
//每个航班的格式 (src, dst, price).
//每个航班的价格范围是 [1, 10000].
//k 范围是 [0, n - 1].
//航班没有重复，且不存在环路
//*/
//int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
//{
//    //dp[i][k]表示从src至多经过k站到达i的最少费用
//    vector<vector<int>> dp(n, vector<int>(K + 2, INT_MAX));
//    //初始化 src 到 src的费用为0
//    for (int k = 0; k <= K + 1; ++k)
//        dp[src][k] = 0;
//
//    //开始动态规划
//    for (int k = 1; k <= K + 1; ++k)
//    {
//        for (const auto &flight : flights)
//        {
//            //如果从src至多经过k - 1站可达flight[0]
//            if (dp[flight[0]][k - 1] != INT_MAX)
//            {
//                //更新从src至多经过k站到达flight[1]
//                dp[flight[1]][k] = std::min(dp[flight[1]][k], dp[flight[0]][k - 1] + flight[2]);
//            }
//        }
//    }
//    return dp[dst][K + 1] == INT_MAX ? -1 : dp[dst][K + 1];
//}

///*
//789. 逃脱阻碍者
//你在进行一个简化版的吃豆人游戏。你从 (0, 0) 点开始出发，你的目的地是 (target[0], target[1]) 。
//地图上有一些阻碍者，第 i 个阻碍者从 (ghosts[i][0], ghosts[i][1]) 出发。
//每一回合，你和阻碍者们*可以*同时向东，西，南，北四个方向移动，每次可以移动到距离原位置1个单位的新位置。
//如果你可以在任何阻碍者抓住你之前到达目的地（阻碍者可以采取任意行动方式），则被视为逃脱成功。
//如果你和阻碍者同时到达了一个位置（包括目的地）都不算是逃脱成功。
//当且仅当你有可能成功逃脱时，输出 True。
//
//示例 1:
//输入：
//ghosts = [[1, 0], [0, 3]]
//target = [0, 1]
//输出：true
//解释：
//你可以直接一步到达目的地(0,1)，在(1, 0)或者(0, 3)位置的阻碍者都不可能抓住你。
//
//示例 2:
//输入：
//ghosts = [[1, 0]]
//target = [2, 0]
//输出：false
//解释：
//你需要走到位于(2, 0)的目的地，但是在(1, 0)的阻碍者位于你和目的地之间。
//
//示例 3:
//输入：
//ghosts = [[2, 0]]
//target = [1, 0]
//输出：false
//解释：
//阻碍者可以和你同时达到目的地。
//
//说明：
//所有的点的坐标值的绝对值 <= 10000。
//阻碍者的数量不会超过 100。
//
//思路：
//画个抽象的示意图来解释下为神马直接比较距离即可 
//A表示起点 B表示鬼的位置 目的地为C 
//如果鬼要在中间拦截 AC上必须有一点D 使得AD = DB 
//通过三角不等式 AC = AD + DC = DB + DC >= BC 
//如果鬼可以拦截到 那么鬼最好的做法就是在终点等着 而不是去中间拦截 
//上面假设选择的是最短路径 乱走的话 相信鬼会笑的更开心
//          C
//         /  \
//        /    \
//     D /      \
//      / \      \
//     /   \      \
//    /      \     \
//   /         \    \
//  /            \   \
// A               \  \
//                     B
//*/
//bool escapeGhosts(const vector<vector<int>> &ghosts, const vector<int> &target)
//{
//    if (ghosts.empty())
//        return true;
//
//    int dist = std::abs(target[0]) + std::abs(target[1]);
//    for (const auto &ghost : ghosts)
//    {
//        if (std::abs(ghost[0] - target[0]) + std::abs(ghost[1] - target[1]) <= dist)
//            return false;
//    }
//    return true;
//}
//
///*
//790. 多米诺和托米诺平铺
//有两种形状的瓷砖：一种是 2x1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。
//
//XX  <- 多米诺
//
//XX  <- "L" 托米诺
//X
//
//给定 N 的值，有多少种方法可以平铺 2 x N 的面板？返回值 mod 10^9 + 7。
//（平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。）
//
//示例:
//输入: 3
//输出: 5
//解释:
//下面列出了五种不同的方法，不同字母代表不同瓷砖：
//XYZ XXZ XYY XXY XYY
//XYZ YYZ XZZ XYY XXY
//
//提示：
//N  的范围是 [1, 1000]
//
//思路：https://leetcode-cn.com/problems/domino-and-tromino-tiling/solution/dong-tai-gui-hua-cong-2-ge-dp-shu-zu-zheng-he-chen/
//动态规划，递推关系式：dp[n] = 2*dp[n-1] + dp[n-3]
//*/
//int numTilings(int N)
//{
//    int f1 = 5, f2 = 2, f3 = 1;
//    if (N == 1) 
//        return f3;
//    if (N == 2)
//        return f2;
//    if (N == 3) 
//        return f1;
//
//    N -= 3;
//    auto mod = 1000000007;
//    while (N-- != 0)
//    {
//        int temp = 2 * f1 % mod + f3 % mod;
//        f3 = f2;
//        f2 = f1;
//        f1 = temp % mod;
//    }
//    return f1;
//}
///*
//思路2：动态规划
//dp1是使面板填满的方法总数，dp2是使面板填充顶部缺一个角的方法总数
//
//dp1[i] = dp1[i - 1] + dp1[i - 2] + dp2[i - 1]
//加一块"一"型瓷砖     加两块"|"瓷砖          加一块"┏"型或"┓"型瓷砖
//dp1[i]   xx          dp1[i]   xx       dp1[i]   xx  or  dp1[i]   xx
//dp1[i-1] 00                   xx       dp2[i-1] x0      dp2[i-1] 0x
//         00          dp1[i-2] 00                00               00
//         00                   00                00               00
//为什么是dp1[i - 2]而不是2 * dp1[i - 2]，明明可以加两块"一"瓷砖和加两块"|"瓷砖？
//因为dp1[i - 1]时是加一块"一"型瓷砖，如果dp1[i - 2]时加两块"一"瓷砖，会存在重复，只能加两块"|"瓷砖
//
//dp2[i] = dp1[i - 2] * 2 + dp2[i - 1]
//    加一块"┛"型和"┗"型瓷砖                      加一块"|"型瓷砖
//dp2[i]    x  and  dp2[i]   x         dp2[i]   x   or   dp2[i]    x
//         xx                xx        dp2[i-1] x0       dp2[i-1] 0x
//dp1[i-2] 00       dp1[i-2] 00                 00                00
//         00                00                 00                00
//*/
//int numTilings2(int N)
//{
//    if (N <= 2) 
//        return N;
//
//    vector<long long int> dp1(N + 1, 0);
//    vector<long long int> dp2(N + 1, 0);
//    dp1[1] = 1; 
//    dp1[2] = 2;
//    dp2[2] = 2;
//    auto mod = 1000000007;
//    for (int i = 3; i <= N; i++)
//    {
//        dp1[i] = (dp1[i - 1] + dp1[i - 2] + dp2[i - 1]) % mod;
//        dp2[i] = (dp1[i - 2] * 2 + dp2[i - 1]) % mod;
//    }
//
//    return dp1[N] % mod;
//}

///*
//791. 自定义字符串排序
//字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。
//S 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。
//返回任意一种符合条件的字符串T。
//
//示例:
//输入:
//S = "cba"
//T = "abcd"
//输出: "cbad"
//解释:
//S中出现了字符 "a", "b", "c", 所以 "a", "b", "c" 的顺序应该是 "c", "b", "a".
//由于 "d" 没有在S中出现, 它可以放在T的任意位置. "dcba", "cdba", "cbda" 都是合法的输出。
//
//注意:
//S的最大长度为26，其中没有重复的字符。
//T的最大长度为200。
//S和T只包含小写字符。
//*/
//string customSortString(const string &S, string T)
//{
//    if (S.size() <= 1 || T.size() <= 1)
//        return T;
//
//    vector<int> chr_idx(26, -1);
//    for (int i = 0; i < S.size(); i++)
//    {
//        chr_idx[S[i] - 'a'] = i;
//    }
//
//    std::sort(T.begin(), T.end(), [&chr_idx](char a, char b)
//              {
//                  return chr_idx[a - 'a'] < chr_idx[b - 'a'];
//              });
//
//    return T;
//}
//
///*
//792. 匹配子序列的单词数
//给定字符串 S 和单词字典 words, 求 words[i] 中是 S 的子序列的单词个数。
//
//示例:
//输入:
//S = "abcde"
//words = ["a", "bb", "acd", "ace"]
//输出: 3
//解释: 有三个是 S 的子序列的单词: "a", "acd", "ace"。
//
//注意:
//所有在words和 S 里的单词都只由小写字母组成。
//S 的长度在 [1, 50000]。
//words 的长度在 [1, 5000]。
//words[i]的长度在[1, 50]。
//
//思路：
//1）用二维数据记录每个字母出现的下标（每个字母的下标构成的数组长度可能不一样，但是同一个字母的下标是单增的）
//2）对于每个一单词，只需要在二维数组中寻找一个递增的下标序列即可（在同一个字母中可以使用二分查找）
//*/
//int numMatchingSubseq(const string &S, const vector<string> &words)
//{
//    vector<vector<int>> chr_indices(26); // 存储字母及其出现的所有下标
//    for (int i = 0; i < S.size(); i++)
//    {
//        chr_indices[S[i] - 'a'].push_back(i);
//    }
//
//    int res = 0;
//    for (const auto &word : words) // 对每个单词
//    {
//        if (word.size() > S.size())
//            continue;
//
//        int pre_idx = -1; // 前一个下标
//        int i = 0;
//        for (; i < word.size(); i++) // 寻找一个递增的下标序列
//        {
//            auto &indices = chr_indices[word[i] - 'a'];
//            auto iter = std::upper_bound(indices.begin(), indices.end(), pre_idx);
//            if (iter == indices.end())
//                break;
//            else
//                pre_idx = *iter;
//        }
//        if (i >= word.size())
//            ++res;
//    }
//    return res;
//}
//// 思路2：暴力法（超时）
//int numMatchingSubseq2(const string &S, const vector<string> &words)
//{
//    auto isSubseq = [&S](const string &word) -> bool
//    {
//        int i = 0, j = 0;
//        while (i < S.size() && j < word.size())
//        {
//            if (S[i] == word[j])
//                ++j;
//            ++i;
//        }
//        return j >= word.size();
//    };
//
//    int res = 0;
//    for (const auto &word : words)
//        if (isSubseq(word))
//            ++res;
//
//    return res;
//}

///*
//794.有效的井字游戏
//用字符串数组作为井字游戏的游戏板 board。当且仅当在井字游戏过程中，玩家有可能将字符放置成游戏板所显示的状态时，才返回 true。
//该游戏板是一个 3 x 3 数组，由字符 " "，"X" 和 "O" 组成。字符 " " 代表一个空位。
//以下是井字游戏的规则：
//玩家轮流将字符放入空位（" "）中。
//第一个玩家总是放字符 “X”，且第二个玩家总是放字符 “O”。
//“X” 和 “O” 只允许放置在空位中，不允许对已放有字符的位置进行填充。
//当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
//当所有位置非空时，也算为游戏结束。
//如果游戏结束，玩家不允许再放置字符。
//
//示例 1:
//输入: board = ["O  ", "   ", "   "]
//输出: false
//解释: 第一个玩家总是放置“X”。
//
//示例 2:
//输入: board = ["XOX", " X ", "   "]
//输出: false
//解释: 玩家应该是轮流放置的。
//
//示例 3:
//输入: board = ["XXX", "   ", "OOO"]
//输出: false
//
//示例 4:
//输入: board = ["XOX", "O O", "XOX"]
//输出: true
//
//说明:
//游戏板 board 是长度为 3 的字符串数组，其中每个字符串 board[i] 的长度为 3。
// board[i][j] 是集合 {" ", "X", "O"} 中的一个字符。
//
//思路：直接判断
//*/
//bool validTicTacToe(const vector<string> &board)
//{
//    // X先手，那么X和O的个数要么相等，要么X比O多一个
//    int X_cnt = 0, O_cnt = 0;
//    for (const auto &row : board)
//        for (auto c : row)
//            if (c == 'X') ++X_cnt;
//            else if (c == 'O') ++O_cnt;
//    if (!(X_cnt == O_cnt || X_cnt == O_cnt + 1))
//        return false;
//
//    const string sameX = "XXX", sameO = "OOO";
//    int sameX_cnt = 0, sameO_cnt = 0;
//    // 分别统计行和列方向"XXX"和"OOO"的个数
//    for (int i = 0; i < 3; i++)
//    {
//        string row, col;
//        for (int j = 0; j < 3; j++)
//        {
//            row.push_back(board[i][j]);
//            col.push_back(board[j][i]);
//        }
//        if (row == sameX) ++sameX_cnt;
//        if (col == sameX) ++sameX_cnt;
//        if (row == sameO) ++sameO_cnt;
//        if (col == sameO) ++sameO_cnt;
//    }
//    // 分别统计对角线和反对角线方向"XXX"和"OOO"的个数
//    string diag, back_diag;
//    for (int i = 0; i < 3; i++)
//    {
//        diag.push_back(board[i][i]);
//        back_diag.push_back(board[i][2 - i]);
//    }
//    if (diag == sameX) ++sameX_cnt;
//    if (back_diag == sameX) ++sameX_cnt;
//    if (diag == sameO) ++sameO_cnt;
//    if (back_diag == sameO) ++sameO_cnt;
//
//    return sameX_cnt == 0 && sameO_cnt == 0 // 不存在"XXX"和"OOO"
//        || (sameX_cnt > sameO_cnt && X_cnt == O_cnt + 1) // "XXX"比"OOO"多，意味着先手X赢，那么X个数比O多1
//        || (sameX_cnt < sameO_cnt && X_cnt == O_cnt);// "OOO"比"XXX"多，意味着后手O赢，那么X和O的个数一样多
//}
//
///*
//795. 区间子数组个数
//给定一个元素都是正整数的数组A ，正整数 L 以及 R (L <= R)。
//求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。
//
//例如 :
//输入:
//A = [2, 1, 4, 3]
//L = 2
//R = 3
//输出: 3
//解释: 满足条件的子数组: [2], [2, 1], [3].
//
//注意:
//L, R  和 A[i] 都是整数，范围在 [0, 10^9]。
//数组 A 的长度范围在[1, 50000]。
//
//思路：区间大于等于L小于等于R的子数组个数 = 区间小于等于R的子数组个数 - 区间小于L的子数组个数
//*/
//int numSubarrayBoundedMax(const vector<int> &A, int L, int R)
//{
//    int cnt1 = 0, cnt2 = 0;
//    for (int i = 0, j = 0; i < A.size(); ++i)
//    {
//        if (A[i] <= R)
//            cnt1 += (i - j + 1);
//        else
//            j = i + 1;
//    }
//    for (int i = 0, j = 0; i < A.size(); ++i)
//    {
//        if (A[i] < L)
//            cnt2 += (i - j + 1);
//        else
//            j = i + 1;
//    }
//    return cnt1 - cnt2;
//}

///*
//797. 所有可能的路径
//给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）
//二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点
//（译者注：有向图是有方向的，即规定了a→b你就不能从b→a）空就是没有下一个结点了。
//
//示例:
//输入: [[1,2], [3], [3], []]
//输出: [[0,1,3],[0,2,3]]
//解释: 图是这样的:
//0--->1
//|    |
//v    v
//2--->3
//这有两条路: 0 -> 1 -> 3 和 0 -> 2 -> 3.
//
//提示:
//结点的数量会在范围 [2, 15] 内。
//你可以把路径以任意顺序输出，但在路径内的结点的顺序必须保证。
//*/
//void allPathsSourceTargetRecursively(const vector<vector<int>> &graph, vector<bool> &visited, int vertex, vector<int> &path, vector<vector<int>> &res)
//{
//    if (vertex == graph.size() - 1)
//    {
//        path.push_back(vertex);
//        res.push_back(path);
//        path.pop_back();
//        return;
//    }
//
//    if (visited[vertex])
//        return;
//
//    path.push_back(vertex);
//    visited[vertex] = true;
//
//    for (int vtx : graph[vertex])
//    {
//        allPathsSourceTargetRecursively(graph, visited, vtx, path, res);
//    }
//
//    path.pop_back();
//    visited[vertex] = false;
//}
//vector<vector<int>> allPathsSourceTarget(const vector<vector<int>> &graph)
//{
//    vector<vector<int>> res;
//    vector<int> path;
//    vector<bool> visited(graph.size(), false);
//    allPathsSourceTargetRecursively(graph, visited, 0, path, res);
//    return res;
//}
//
///*
//799. 香槟塔
//我们把玻璃杯摆成金字塔的形状，其中第一层有1个玻璃杯，第二层有2个，依次类推到第100层，每个玻璃杯(250ml)将盛有香槟。
//从顶层的第一个玻璃杯开始倾倒一些香槟，当顶层的杯子满了，任何溢出的香槟都会立刻等流量的流向左右两侧的玻璃杯。
//当左右两边的杯子也满了，就会等流量的流向它们左右两边的杯子，依次类推。（当最底层的玻璃杯满了，香槟会流到地板上）
//例如，在倾倒一杯香槟后，最顶层的玻璃杯满了。倾倒了两杯香槟后，第二层的两个玻璃杯各自盛放一半的香槟。
//在倒三杯香槟后，第二层的香槟满了 - 此时总共有三个满的玻璃杯。
//在倒第四杯后，第三层中间的玻璃杯盛放了一半的香槟，他两边的玻璃杯各自盛放了四分之一的香槟，如下图所示。
//现在当倾倒了非负整数杯香槟后，返回第 i 行 j 个玻璃杯所盛放的香槟占玻璃杯容积的比例（i 和 j都从0开始）。
//
//示例 1:
//输入: poured(倾倒香槟总杯数) = 1, query_glass(杯子的位置数) = 1, query_row(行数) = 1
//输出: 0.0
//解释: 我们在顶层（下标是（0，0））倒了一杯香槟后，没有溢出，因此所有在顶层以下的玻璃杯都是空的。
//
//示例 2:
//输入: poured(倾倒香槟总杯数) = 2, query_glass(杯子的位置数) = 1, query_row(行数) = 1
//输出: 0.5
//解释: 我们在顶层（下标是（0，0）倒了两杯香槟后，有一杯量的香槟将从顶层溢出，位于（1，0）的玻璃杯和（1，1）的玻璃杯平分了这一杯香槟，所以每个玻璃杯有一半的香槟。
//
//注意:
//poured 的范围[0, 10 ^ 9]。
//query_glass 和query_row 的范围 [0, 99]。
//
//思路：模拟法
//*/
//double champagneTower(int poured, int query_row, int query_glass)
//{
//    vector<vector<double>> tower(query_row + 2, vector<double>(query_row + 2, 0));
//    tower[0][0] = poured;
//    for (int r = 0; r <= query_row; ++r)
//    {
//        for (int c = 0; c <= r; ++c)
//        {
//            double champagne_to_next = (tower[r][c] - 1.0) / 2.0;
//            if (champagne_to_next > 0)
//            {
//                tower[r + 1][c] += champagne_to_next;
//                tower[r + 1][c + 1] += champagne_to_next;
//            }
//        }
//    }
//
//    return std::min(1.0, tower[query_row][query_glass]);
//}

///*
//801. 使序列递增的最小交换次数
//我们有两个长度相等且不为空的整型数组 A 和 B 。
//我们可以交换 A[i] 和 B[i] 的元素。注意这两个元素在各自的序列中应该处于相同的位置。
//在交换过一些元素之后，数组 A 和 B 都应该是严格递增的（数组严格递增的条件仅为A[0] < A[1] < A[2] < ... < A[A.length - 1]）。
//给定数组 A 和 B ，请返回使得两个数组均保持严格递增状态的最小交换次数。假设给定的输入总是有效的。
//
//示例:
//输入: A = [1,3,5,4], B = [1,2,3,7]
//输出: 1
//解释:
//交换 A[3] 和 B[3] 后，两个数组如下:
//A = [1, 3, 5, 7] ， B = [1, 2, 3, 4]
//两个数组均为严格递增的。
//
//注意:
//A, B 两个数组的长度总是相等的，且长度的范围为 [1, 1000]。
//A[i], B[i] 均为 [0, 2000]区间内的整数。
//
//思路：动态规划（https://leetcode-cn.com/problems/minimum-swaps-to-make-sequences-increasing/solution/shi-xu-lie-di-zeng-de-zui-xiao-jiao-huan-ci-shu-by/）
//（https://www.cnblogs.com/grandyang/p/9311385.html）
//*/
//int minSwap(vector<int> &A, vector<int> &B)
//{
//    int length = A.size();
//    if (length <= 1)
//        return 0;
//
//    // n: natural, s: swapped
//    int n1 = 0, s1 = 1;
//    for (int i = 1; i < length; ++i)
//    {
//        int n2 = INT_MAX, s2 = INT_MAX;
//        if (A[i - 1] < A[i] && B[i - 1] < B[i])
//        {
//            n2 = std::min(n2, n1);
//            s2 = std::min(s2, s1 + 1);
//        }
//        if (A[i - 1] < B[i] && B[i - 1] < A[i])
//        {
//            n2 = std::min(n2, s1);
//            s2 = std::min(s2, n1 + 1);
//        }
//        n1 = n2;
//        s1 = s2;
//    }
//    return std::min(n1, s1);
//}
//
///*
//802. 找到最终的安全状态
//在有向图中, 我们从某个节点和每个转向处开始, 沿着图的有向边走。
//如果我们到达的节点是终点 (即它没有连出的有向边), 我们停止。
//现在, 如果我们最后能走到终点，那么我们的起始节点是最终安全的。
//更具体地说, 存在一个自然数 K,  无论选择从哪里开始行走, 我们走了不到 K 步后必能停止在一个终点。
//哪些节点最终是安全的？ 结果返回一个有序的数组。
//该有向图有 N 个节点，标签为 0, 1, ..., N-1, 其中 N 是 graph 的节点数.  图以以下的形式给出: graph[i] 是节点 j 的一个列表，满足 (i, j) 是图的一条有向边。
//
//示例：
//输入：graph = [[1,2],[2,3],[5],[0],[5],[],[]]
//输出：[2,4,5,6]
//这里是上图的示意图。
//
//提示：
//graph 节点数不超过 10000.
//图的边数不会超过 32000.
//每个 graph[i] 被排序为不同的整数列表， 在区间 [0, graph.length - 1] 中选取。
//
//思路：
//1）找到所有的能够构成环的节点
//2）剔除这些节点便是最终结果
//3）深搜（超时）
//*/
////bool eventualSafeNodesRecursively(const vector<vector<int>> &graph, vector<bool> &visited, int vertex)
////{
////    if (visited[vertex])
////        return true;
////
////    visited[vertex] = true;
////    for (const auto &vtx : graph[vertex])
////    {
////        if (eventualSafeNodesRecursively(graph, visited, vtx))
////            return true;
////    }
////    visited[vertex] = false;
////    return false;
////}
////vector<int> eventualSafeNodes(const vector<vector<int>> &graph)
////{
////    int N = graph.size();
////    if (N == 0)
////        return {};
////    if (N == 1)
////        return {0};
////
////    vector<bool> visited(N, false);
////    vector<int> res;
////    for (int i = 0; i < N; i++)
////    {
////        if (!visited[i])
////            eventualSafeNodesRecursively(graph, visited, i);
////        if (!visited[i])
////            res.push_back(i);
////    }
////
////    return res;
////}
///*
//思路2：拓扑排序
//1）所有出度为0的节点都是安全的
//2）把所有出度为0的点去掉后，再寻找出度为0的点
//*/
//vector<int> eventualSafeNodes2(const vector<vector<int>> &graph)
//{
//    int N = graph.size();
//    if (N == 0)
//        return {};
//    if (N == 1)
//        return {0};
//
//    vector<unordered_set<int>> out(N);
//    vector<unordered_set<int>> rout(N);
//    for (int i = 0; i < N; i++)
//    {
//        for (int j : graph[i])
//        {
//            out[i].insert(j);
//            rout[j].insert(i);
//        }
//    }
//
//    queue<int> qu;
//    vector<bool> safe(N, false);
//    for (int i = 0; i < N; i++)
//    {
//        if (out[i].size() == 0)
//        {
//            qu.push(i);
//            safe[i] = true;
//        }
//    }
//
//    while (!qu.empty())
//    {
//        int vertex = qu.front();
//        qu.pop();
//        safe[vertex] = true;
//        for (int pre : rout[vertex])
//        {
//            out[pre].erase(vertex);
//            if (out[pre].empty())
//                qu.push(pre);
//        }
//    }
//
//    vector<int> res;
//    for (int i = 0; i < N; i++)
//    {
//        if (safe[i])
//            res.push_back(i);
//    }
//    return res;
//}
///*
//思路3：深搜（一个点着多种颜色）
//*/
//bool dfs(vector<vector<int>> &graph, int start, vector<int> &color)
//{
//    if (color[start] != 0)
//        return color[start] == 1;
//
//    color[start] = 2;       // mark it as unsafe because it is on the path
//    for (int next : graph[start])
//    {
//        if (!dfs(graph, next, color))
//            return false;
//    }
//    color[start] = 1;       // mark it as safe because no loop is found
//    return true;
//}
//vector<int> eventualSafeNodes(vector<vector<int>> &graph)
//{
//    int N = graph.size();
//    if (N == 0)
//        return {};
//    if (N == 1)
//        return {0};
//
//    vector<int> color(N, 0);         // 0: not visited; 1: safe; 2: unsafe.
//    vector<int> res;
//    for (int i = 0; i < N; ++i)
//    {
//        if (dfs(graph, i, color))
//        {     // the i-th node is safe
//            res.push_back(i);
//        }
//    }
//    return res;
//}

///*
//807. 保持城市天际线
//在二维数组grid中，grid[i][j]代表位于某处的建筑物的高度。 
//我们被允许增加任何数量（不同建筑物的数量可能不同）的建筑物的高度。 
//高度 0 也被认为是建筑物。
//最后，从新数组的所有四个方向（即顶部，底部，左侧和右侧）观看的“天际线”必须与原始数组的天际线相同。 
//城市的天际线是从远处观看时，由所有建筑物形成的矩形的外部轮廓。 请看下面的例子。
//建筑物高度可以增加的最大总和是多少？
//
//例子：
//输入： grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
//输出： 35
//解释：
//The grid is:
//[ [3, 0, 8, 4],
//  [2, 4, 5, 7],
//  [9, 2, 6, 3],
//  [0, 3, 1, 0] ]
//从数组竖直方向（即顶部，底部）看“天际线”是：[9, 4, 8, 7]
//从水平水平方向（即左侧，右侧）看“天际线”是：[8, 7, 9, 3]
//在不影响天际线的情况下对建筑物进行增高后，新数组如下：
//gridNew = [ [8, 4, 8, 7],
//            [7, 4, 7, 7],
//            [9, 4, 8, 7],
//            [3, 3, 3, 3] ]
//
//说明:
//1 < grid.length = grid[0].length <= 50。
// grid[i][j] 的高度范围是： [0, 100]。
//一座建筑物占据一个grid[i][j]：换言之，它们是 1 x 1 x grid[i][j] 的长方体。
//*/
//int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
//{
//    int rows = grid.size(), cols = grid[0].size();
//
//    vector<int> row_view(rows), col_view(cols);
//    for (int i = 0; i < rows; i++)
//        row_view[i] = *std::max_element(grid[i].begin(), grid[i].end());
//    for (int i = 0; i < cols; i++)
//    {
//        int max_val = grid[0][i];
//        for (int j = 1; j < rows; j++)
//        {
//            if (grid[j][i] > max_val)
//                max_val = grid[j][i];
//        }
//        col_view[i] = max_val;
//    }
//
//    int res = 0;
//    for (int i = 0; i < rows; i++)
//        for (int j = 0; j < cols; j++)
//            res += std::min(row_view[i], col_view[j]) - grid[i][j];
//    return res;
//}
//
///*
//808. 分汤
//有 A 和 B 两种类型的汤。一开始每种类型的汤有 N 毫升。有四种分配操作：
//提供 100ml 的汤A 和 0ml 的汤B。
//提供 75ml 的汤A 和 25ml 的汤B。
//提供 50ml 的汤A 和 50ml 的汤B。
//提供 25ml 的汤A 和 75ml 的汤B。
//当我们把汤分配给某人之后，汤就没有了。
//每个回合，我们将从四种概率同为0.25的操作中进行分配选择。
//如果汤的剩余量不足以完成某次操作，我们将尽可能分配。
//当两种类型的汤都分配完时，停止操作。
//注意不存在先分配100 ml汤B的操作。
//需要返回的值： 汤A先分配完的概率 + 汤A和汤B同时分配完的概率 / 2。
//
//示例:
//输入: N = 50
//输出: 0.625
//解释:
//如果我们选择前两个操作，A将首先变为空。对于第三个操作，A和B会同时变为空。对于第四个操作，B将首先变为空。
//所以A变为空的总概率加上A和B同时变为空的概率的一半是 0.25 *(1 + 1 + 0.5 + 0)= 0.625。
//
//注释:
//0 <= N <= 10^9。
//返回值在 10^-6 的范围将被认为是正确的。
//
//思路：动态规划（https://leetcode-cn.com/problems/soup-servings/solution/fen-tang-by-leetcode/）
//*/
//double soupServings(int N)
//{
//    N = N / 25 + (N % 25 > 0 ? 1 : 0);
//    if (N >= 500) 
//        return 1.0;
//
//    auto M = [](int i) { return std::max(0, i); };
//
//    vector<vector<double>> dp(N + 1, vector<double>(N + 1));
//    for (int s = 0; s <= 2 * N; ++s)
//    {
//        for (int i = 0; i <= N; ++i)
//        {
//            int j = s - i;
//            if (j < 0 || j > N) 
//                continue;
//
//            double ans = 0.0;
//            if (i == 0) 
//                ans = 1.0;
//            if (i == 0 && j == 0) 
//                ans = 0.5;
//            if (i > 0 && j > 0)
//                ans = 0.25 * (dp[M(i - 4)][j] + dp[M(i - 3)][M(j - 1)] +
//                              dp[M(i - 2)][M(j - 2)] + dp[M(i - 1)][M(j - 3)]);
//            dp[i][j] = ans;
//        }
//    }
//    return dp[N][N];
//}

///*
//809. 情感丰富的文字
//有时候人们会用重复写一些字母来表示额外的感受，比如 "hello" -> "heeellooo", "hi" -> "hiii"。
//我们将相邻字母都相同的一串字符定义为相同字母组，例如："h", "eee", "ll", "ooo"。
//对于一个给定的字符串 S ，如果另一个单词能够通过将一些字母组扩张从而使其和 S 相同，我们将这个单词定义为可扩张的（stretchy）。
//扩张操作定义如下：选择一个字母组（包含字母 c ），然后往其中添加相同的字母 c 使其长度达到 3 或以上。
//例如，以 "hello" 为例，我们可以对字母组 "o" 扩张得到 "hellooo"，但是无法以同样的方法得到 "helloo" 因为字母组 "oo" 长度小于 3。
//此外，我们可以进行另一种扩张 "ll" -> "lllll" 以获得 "helllllooo"。
//如果 S = "helllllooo"，那么查询词 "hello" 是可扩张的，因为可以对它执行这两种扩张操作使得 query = "hello" -> "hellooo" -> "helllllooo" = S。
//输入一组查询单词，输出其中可扩张的单词数量。
//
//示例：
//输入：
//S = "heeellooo"
//words = ["hello", "hi", "helo"]
//输出：1
//解释：
//我们能通过扩张 "hello" 的 "e" 和 "o" 来得到 "heeellooo"。
//我们不能通过扩张 "helo" 来得到 "heeellooo" 因为 "ll" 的长度小于 3 。
// 
//说明：
//0 <= len(S) <= 100。
//0 <= len(words) <= 100。
//0 <= len(words[i]) <= 100。
//S 和所有在 words 中的单词都只由小写字母组成。
//*/
//int expressiveWords(const string S, const vector<string> &words)
//{
//    int length = words.size();
//    if (length == 0 || S.size() == 0)
//        return 0;
//
//    map<int, int> idx_chrcnt;
//    int start = 0, i = 1;
//    for (; i < S.size(); i++)
//    {
//        if (S[i] == S[i - 1])
//            continue;
//        else
//        {
//            idx_chrcnt[start] = i - start;
//            start = i;
//        }
//    }
//    idx_chrcnt[start] = i - start;
//
//    int res = 0;
//    for (const string &word : words)
//    {
//        if (word.empty())
//            continue;
//
//        auto iter = idx_chrcnt.begin();
//        start = 0, i = 1;
//        for (; i < word.size(); i++)
//        {
//            if (word[i] == word[i - 1])
//                continue;
//            else
//            {
//                if (iter != idx_chrcnt.end() && S[iter->first] == word[start]
//                    && (i - start == iter->second || i - start < iter->second && iter->second >= 3))
//                    ++iter;
//                else
//                    break;
//                start = i;
//            }
//        }
//        if (i != word.size())
//            continue;
//        if (iter != idx_chrcnt.end() && S[iter->first] == word[start]
//            && (i - start == iter->second || i - start < iter->second && iter->second >= 3))
//        {
//            ++iter;
//            if (iter == idx_chrcnt.end())
//                ++res;
//        }
//    }
//    return res;
//}
//
///*
//813. 最大平均值和的分组
//我们将给定的数组 A 分成 K 个相邻的非空子数组 ，我们的分数由每个子数组内的平均值的总和构成。计算我们所能得到的最大分数是多少。
//注意我们必须使用 A 数组中的每一个数进行分组，并且分数不一定需要是整数。
//
//示例:
//输入:
//A = [9,1,2,3,9]
//K = 3
//输出: 20
//解释:
//A 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
//我们也可以把 A 分成[9, 1], [2], [3, 9].
//这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
//
//说明:
//1 <= A.length <= 100.
//1 <= A[i] <= 10000.
//1 <= K <= A.length.
//答案误差在 10^-6 内被视为是正确的。
//
//思路：动态规划（https://leetcode-cn.com/problems/largest-sum-of-averages/solution/zui-da-ping-jun-zhi-he-de-fen-zu-by-leetcode/）
//*/
//double largestSumOfAverages(vector<int> &A, int K)
//{
//    int N = A.size();
//    vector<double> P(N + 1);
//    for (int i = 0; i < N; ++i)
//        P[i + 1] = P[i] + A[i];
//
//    vector<double> dp(N);
//    for (int i = 0; i < N; ++i)
//        dp[i] = (P[N] - P[i]) / (N - i);
//
//    for (int k = 0; k < K - 1; ++k)
//        for (int i = 0; i < N; ++i)
//            for (int j = i + 1; j < N; ++j)
//                dp[i] = std::max(dp[i], (P[j] - P[i]) / (j - i) + dp[j]);
//
//    return dp[0];
//}
//// 思路2：动态规划（未优化空间）
//double largestSumOfAverages2(vector<int> &A, int K)
//{
//    // dp[i][k]=max(dp[j][k-1]+avg(j+1,i)), j<i
//    int length = A.size();
//    vector<vector<double>> dp(length, vector<double>(K + 1, 0));
//
//    vector<double> sums(length + 1, 0);
//    for (int i = 0; i < length; i++)
//        sums[i + 1] = sums[i] + A[i];
//
//    for (int i = 0; i < length; i++)
//        dp[i][1] = sums[i + 1] / (i + 1);
//
//    for (int k = 2; k <= K; k++)
//        for (int i = 0; i < length; i++)
//            for (int j = 0; j < i; j++)
//                dp[i][k] = std::max(dp[i][k], dp[j][k - 1] + (sums[i + 1] - sums[j + 1]) / (i - j));
//            
//    return dp[length - 1][K];
//}

///*
//814. 二叉树剪枝
//给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。
//返回移除了所有不包含 1 的子树的原二叉树。
//( 节点 X 的子树为 X 本身，以及所有 X 的后代。)
//
//示例1:
//输入: [1,null,0,0,1]
//输出: [1,null,0,null,1]
//解释:
//只有红色节点满足条件“所有不包含 1 的子树”。
//右图为返回的答案。
//
//示例2:
//输入: [1,0,1,0,0,0,1]
//输出: [1,null,1,null,1]
//
//示例3:
//输入: [1,1,0,1,1,0,1,0]
//输出: [1,1,0,1,1,null,1]
//
//说明:
//给定的二叉树最多有 100 个节点。
//每个节点的值只会为 0 或 1 。
//*/
//bool pruneTreeRecursively(TreeNode *p)
//{
//    if (p == nullptr)
//        return true;
//
//    bool is_all_zero_left = pruneTreeRecursively(p->left);
//    if (is_all_zero_left)
//        p->left = nullptr;
//    bool is_all_zero_right = pruneTreeRecursively(p->right);
//    if (is_all_zero_right)
//        p->right = nullptr;
//
//    if (is_all_zero_left && is_all_zero_right && p->val == 0)
//        return true;
//    return false;
//}
//TreeNode *pruneTree(TreeNode *root)
//{
//    if (root == nullptr)
//        return root;
//
//    if (pruneTreeRecursively(root))
//        return nullptr;
//    return root;
//}
//
///*
//816. 模糊坐标
//我们有一些二维坐标，如 "(1, 3)" 或 "(2, 0.5)"，然后我们移除所有逗号，小数点和空格，得到一个字符串S。
//返回所有可能的原始字符串到一个列表中。
//原始的坐标表示法不会存在多余的零，所以不会出现类似于"00", "0.0", "0.00", "1.0", "001", "00.01"或一些其他更小的数来表示坐标。
//此外，一个小数点前至少存在一个数，所以也不会出现“.1”形式的数字。
//最后返回的列表可以是任意顺序的。而且注意返回的两个数字中间（逗号之后）都有一个空格。
//
//示例 1:
//输入: "(123)"
//输出: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
//
//示例 2:
//输入: "(00011)"
//输出:  ["(0.001, 1)", "(0, 0.011)"]
//解释:
//0.0, 00, 0001 或 00.01 是不被允许的。
//
//示例 3:
//输入: "(0123)"
//输出: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
//
//示例 4:
//输入: "(100)"
//输出: [(10, 0)]
//解释:
//1.0 是不被允许的。
//
//提示:
//4 <= S.length <= 12.
//S[0] = "(", S[S.length - 1] = ")", 且字符串 S 中的其他元素都是数字。
//*/
//vector<string> ambiguousCoordinates(const string &S)
//{
//    auto isValid = [](const string &s, bool is_frac, int frac_idx) -> bool
//    {
//        if (!is_frac)
//        {
//            if (s[0] == '0' && s.size() > 1)
//                return false;
//            return true;
//        }
//        else
//        {
//            if (s[0] == '0' && frac_idx > 1)
//                return false;
//            auto iter = std::find_if(s.begin() + frac_idx + 1, s.end(), [](char c) { return c != '0'; });
//            if (iter == s.end())
//                return false;
//            return s.back() != '0';
//        }
//    };
//
//    auto generate = [&isValid](const string &s) -> vector<string>
//    {
//        vector<string> res;
//        if (isValid(s, false, -1))
//            res.push_back(s);
//        for (int i = 1; i < s.size(); i++)
//        {
//            string t = s.substr(0, i) + "." + s.substr(i, s.size() - i);
//            if (isValid(t, true, i))
//                res.push_back(std::move(t));
//        }
//        return res;
//    };
//
//    string str = S.substr(1, S.size() - 2);
//    int length = str.size();
//    vector<string> res;
//    for (int i = 1; i < length; i++)
//    {
//        string x = str.substr(0, i);
//        string y = str.substr(i, length - i);
//        vector<string> x_set = generate(x);
//        vector<string> y_set = generate(y);
//        for (int j = 0; j < x_set.size(); j++)
//            for (int k = 0; k < y_set.size(); k++)
//                res.push_back("(" + x_set[j] + ", " + y_set[k] + ")");
//    }
//    return res;
//}

///*
//817. 链表组件
//给定一个链表（链表结点包含一个整型值）的头结点 head。
//同时给定列表 G，该列表是上述链表中整型值的一个子集。
//返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。
//
//示例 1：
//输入:
//head: 0->1->2->3
//G = [0, 1, 3]
//输出: 2
//解释:
//链表中,0 和 1 是相连接的，且 G 中不包含 2，所以 [0, 1] 是 G 的一个组件，同理 [3] 也是一个组件，故返回 2。
//
//示例 2：
//输入:
//head: 0->1->2->3->4
//G = [0, 3, 1, 4]
//输出: 2
//解释:
//链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。
//
//注意:
//如果 N 是给定链表 head 的长度，1 <= N <= 10000。
//链表中每个结点的值所在范围为 [0, N - 1]。
//1 <= G.length <= 10000
//G 是链表中所有结点的值的一个子集.
//
//思路：https://leetcode-cn.com/problems/linked-list-components/solution/lian-biao-zu-jian-by-leetcode/
//*/
//int numComponents(ListNode *head, const vector<int> &G)
//{
//    if (head == nullptr)
//        return 0;
//
//    unordered_set<int> setG(G.begin(), G.end());
//    ListNode *p = head;
//    int res = 0;
//    while (p != nullptr)
//    {
//        if (setG.count(p->val) && (p->next == nullptr || !setG.count(p->next->val)))
//            ++res;
//        p = p->next;
//    }
//    return res;
//}
//
///*
//820. 单词的压缩编码
//给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
//例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。
//对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
//那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
//
//示例：
//输入: words = ["time", "me", "bell"]
//输出: 10
//说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
// 
//提示：
//1 <= words.length <= 2000
//1 <= words[i].length <= 7
//每个单词都是小写字母 。
//
//思路：
//1）如果一个单词是另一个单词的后缀，那么这两个单词可以进行“合并”，比如time和me，“合并”成time#
//2）使用前缀树，将所有单词逆序后插入前缀树
//3）统计前缀树每个叶子节点的深度di，最后结果就是Σ(di+1)
//*/
//void minimumLengthEncodingRecursively(Trie::TrieNode *p, int len, int &res)
//{
//    bool is_leaf = true;
//    for (int i = 0; i < 26; i++)
//    {
//        if (p->childNodes[i] != nullptr)
//        {
//            is_leaf = false;
//            minimumLengthEncodingRecursively(p->childNodes[i], len + 1, res);
//        }
//    }
//    if (is_leaf)
//        res += len + 1;
//}
//int minimumLengthEncoding(const vector<string> &words)
//{
//    Trie trie;
//    for (const auto &word : words)
//        trie.insert(string(word.rbegin(), word.rend()));
//
//    int res = 0;
//    minimumLengthEncodingRecursively(trie.root(), 0, res);
//    return res;
//}

///*
//822. 翻转卡片游戏0
//在桌子上有 N 张卡片，每张卡片的正面和背面都写着一个正数（正面与背面上的数有可能不一样）。
//我们可以先翻转任意张卡片，然后选择其中一张卡片。
//如果选中的那张卡片背面的数字 X 与任意一张卡片的正面的数字都不同，那么这个数字是我们想要的数字。
//哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？如果没有一个数字符合要求的，输出 0。
//其中, fronts[i] 和 backs[i] 分别代表第 i 张卡片的正面和背面的数字。
//如果我们通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。
//
//示例：
//输入：fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
//输出：2
//解释：假设我们翻转第二张卡片，那么在正面的数变成了 [1,3,4,4,7] ， 背面的数变成了 [1,2,4,1,3]。
//接着我们选择第二张卡片，因为现在该卡片的背面的数是 2，2 与任意卡片上正面的数都不同，所以 2 就是我们想要的数字。
// 
//提示：
//1 <= fronts.length == backs.length <= 1000
//1 <= fronts[i] <= 2000
//1 <= backs[i] <= 2000
//
//思路：
//1）如果一张牌的正反的数字是一样的，那么这个数字肯定不是结果
//2）如果一张牌的正反数字不一样，那么这张牌就有两个值，这两个值都有可能（只需要将牌翻转即可）
//3）记录下所有的正反数字一样的牌上的数字，构成集合S
//4）遍历正反数字n
//    a.如果n∈S，那么肯定不是结果
//    b.如果n不属于S。首先，n和那些正反数字一样的牌是不一样的，接着，即使n和某张牌的正面一样，由于该牌正反不一样，翻转该牌，就可以和n不一样了
//    c.所以，只要n不属于S，n都是满足要求的，然后求最小的
//*/
//int flipgame(const vector<int> &fronts, const vector<int> &backs)
//{
//    unordered_set<int> same;
//    for (int i = 0; i < fronts.size(); i++)
//    {
//        if (fronts[i] == backs[i])
//            same.insert(fronts[i]);
//    }
//
//    int res = std::numeric_limits<int>::max();
//    for (int front : fronts)
//        if (!same.count(front))
//            res = std::min(res, front);
//    for (int back : backs)
//        if (!same.count(back))
//            res = std::min(res, back);
//    return res == std::numeric_limits<int>::max() ? 0 : res;
//}
//
///*
//823. 带因子的二叉树
//给出一个含有不重复整数元素的数组，每个整数均大于 1。
//我们用这些整数来构建二叉树，每个整数可以使用任意次数。
//其中：每个非叶结点的值应等于它的两个子结点的值的乘积。
//满足条件的二叉树一共有多少个？返回的结果应模除 10 ** 9 + 7。
//
//示例 1:
//输入: A = [2, 4]
//输出: 3
//解释: 我们可以得到这些二叉树: [2], [4], [4, 2, 2]
//
//示例 2:
//输入: A = [2, 4, 5, 10]
//输出: 7
//解释: 我们可以得到这些二叉树: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
// 
//提示:
//1 <= A.length <= 1000.
//2 <= A[i] <= 10 ^ 9.
//
//思路：动态规划（https://leetcode-cn.com/problems/binary-trees-with-factors/solution/dai-yin-zi-de-er-cha-shu-by-leetcode/）
//*/
//int numFactoredBinaryTrees(vector<int> &A)
//{
//    int length = A.size();
//    if (length == 1)
//        return 1;
//
//    std::sort(A.begin(), A.end());
//    vector<unsigned long long> dp(length, 1);
//    unordered_map<int, int> num_idx;
//    for (int i = 0; i < length; i++)
//        num_idx[A[i]] = i;
//
//    int mod = 1000000007;
//    for (int i = 0; i < length; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            int parent = A[i], left_child = A[j];
//            if (parent % left_child == 0)
//            {
//                int right_child = parent / left_child;
//                if (num_idx.count(right_child))
//                {
//                    dp[i] = (dp[i] + dp[j] * dp[num_idx[right_child]]) % mod;
//                }
//            }
//        }
//    }
//
//    unsigned long long res = 0;
//    for (auto cnt : dp)
//        res += cnt;
//    return res % mod;
//}

///*
//825. 适龄的朋友
//人们会互相发送好友请求，现在给定一个包含有他们年龄的数组，ages[i] 表示第 i 个人的年龄。
//当满足以下条件时，A 不能给 B（A、B不为同一人）发送好友请求：
//age[B] <= 0.5 * age[A] + 7
//age[B] > age[A]
//age[B] > 100 && age[A] < 100
//否则，A 可以给 B 发送好友请求。
//注意如果 A 向 B 发出了请求，不等于 B 也一定会向 A 发出请求。而且，人们不会给自己发送好友请求。 
//求总共会发出多少份好友请求?
//
//示例 1:
//输入: [16,16]
//输出: 2
//解释: 二人可以互发好友申请。
//
//示例 2:
//输入: [16,17,18]
//输出: 2
//解释: 好友请求可产生于 17 -> 16, 18 -> 17.
//
//示例 3:
//输入: [20,30,100,110,120]
//输出: 3
//解释: 好友请求可产生于 110 -> 100, 120 -> 110, 120 -> 100.
// 
//说明:
//1 <= ages.length <= 20000.
//1 <= ages[i] <= 120.
//
//思路：
//1）年龄限制在1~120，意味着可以将数据规模缩小到120
//2）注意，如果年龄相同，不能自己给自己发请求。假设该年龄人数为cnt，那么每个人可以给另外cnt-1个人发请求，总共cnt*(cnt-1)个请求
//*/
//int numFriendRequests(const vector<int> &ages)
//{
//    int length = ages.size();
//    if (length == 1)
//        return 0;
//
//    vector<int> age_cnt(121, 0);
//    for (int age : ages)
//        ++age_cnt[age];
//
//    int res = 0;
//    for (int ageA = 1; ageA <= 120; ageA++)
//    {
//        if (age_cnt[ageA] == 0)
//            continue;
//        for (int ageB = 1; ageB <= 120; ageB++)
//        {
//            if (age_cnt[ageB] == 0 || ageA * 0.5 + 7 >= ageB || ageB > ageA || ageB > 100 && ageA < 100)
//                continue;
//            if (ageA != ageB)
//                res += age_cnt[ageA] * age_cnt[ageB];
//            else
//                res += age_cnt[ageA] * (age_cnt[ageA] - 1);
//        }
//    }
//    return res;
//}
//
///*
//826. 安排工作以达到最大收益
//有一些工作：difficulty[i] 表示第i个工作的难度，profit[i]表示第i个工作的收益。
//现在我们有一些工人。worker[i]是第i个工人的能力，即该工人只能完成难度小于等于worker[i]的工作。
//每一个工人都最多只能安排一个工作，但是一个工作可以完成多次。
//举个例子，如果3个工人都尝试完成一份报酬为1的同样工作，那么总收益为 $3。如果一个工人不能完成任何工作，他的收益为 $0 。
//我们能得到的最大收益是多少？
//
//示例：
//输入: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
//输出: 100
//解释: 工人被分配的工作难度是 [4,4,6,6] ，分别获得 [20,20,30,30] 的收益。
//
//提示:
//1 <= difficulty.length = profit.length <= 10000
//1 <= worker.length <= 10000
//difficulty[i], profit[i], worker[i]  的范围是 [1, 10^5]
//
//思路：
//1）按工作难度从小到大排序
//2）用数组max_profit[i]表示从最小工作难度到目前工作难度i中最大的profit
//3）对于每一个工人的工作难度diff，在1）的排好序的难度中寻找第一个大于diff的工作，该工作的前一个工作的max_profit即为所求
//*/
//int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
//{
//    int length = difficulty.size();
//    vector<int> works(length);
//    for (int i = 0; i < length; i++)
//        works[i] = i;
//
//    std::sort(works.begin(), works.end(), [&difficulty](int a, int b)
//              {
//                  return difficulty[a] < difficulty[b];
//              });
//
//    vector<int> max_profit(length);
//    max_profit[0] = profit[works[0]];
//    for (int i = 1; i < length; i++)
//        max_profit[i] = (profit[works[i]] > max_profit[i - 1]) ? profit[works[i]] : max_profit[i - 1];
//
//    unordered_map<int, int> worker_cnt;
//    for (int diff : worker)
//        ++worker_cnt[diff];
//    int res = 0;
//    for (const auto &kv : worker_cnt)
//    {
//        auto iter = std::upper_bound(works.begin(), works.end(), kv.first, [&difficulty](int val, int element)
//                                     {
//                                         return val < difficulty[element];
//                                     });
//        if (iter == works.begin())
//            continue;
//        res += max_profit[(--iter) - works.begin()] * kv.second;
//    }
//    return res;
//}
//// 思路2：https://leetcode-cn.com/problems/most-profit-assigning-work/solution/an-pai-gong-zuo-yi-da-dao-zui-da-shou-yi-by-leetco/
//int maxProfitAssignment2(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
//{
//    int length = difficulty.size();
//    vector<int> works(length);
//    for (int i = 0; i < length; i++)
//        works[i] = i;
//
//    std::sort(works.begin(), works.end(), [&difficulty](int a, int b)
//              {
//                  return difficulty[a] < difficulty[b];
//              });
//    std::sort(worker.begin(), worker.end());
//
//    int res = 0;
//    int max_profit = 0;
//    for (int i = 0, j = 0; i < worker.size(); ++i)
//    {
//        while (j < length && worker[i] >= difficulty[works[j]])
//        {
//            if (profit[works[j]] > max_profit)
//                max_profit = profit[works[j]];
//            ++j;
//        }
//        res += max_profit;
//    }
//    return res;
//}

///*
//831. 隐藏个人信息
//给你一条个人信息 string S，它可能是一个邮箱地址，也可能是一个电话号码。
//我们将隐藏它的隐私信息，通过如下规则:
//
//<u>1. 电子邮箱</u>
//定义名称 <name> 是长度大于等于 2 （length ≥ 2），并且只包含小写字母 a-z 和大写字母 A-Z 的字符串。
//电子邮箱地址由名称 <name> 开头，紧接着是符号'@'，后面接着一个名称 <name>，再接着一个点号 '.'，然后是一个名称 <name>。
//电子邮箱地址确定为有效的，并且格式是 "name1@name2.name3"。
//为了隐藏电子邮箱，所有的名称 <name> 必须被转换成小写的，并且第一个名称 <name> 的第一个字母和最后一个字母的中间的所有字母由 5 个 '*' 代替。
//
//<u>2. 电话号码</u>
//电话号码是一串包括数字 0-9，以及 {'+', '-', '(', ')', ' '} 这几个字符的字符串。你可以假设电话号码包含 10 到 13 个数字。
//电话号码的最后 10 个数字组成本地号码，在这之前的数字组成国际号码。注意，国际号码是可选的。我们只暴露最后 4 个数字并隐藏所有其他数字。
//本地号码是有格式的，并且如 "***-***-1111" 这样显示，这里的 1 表示暴露的数字。
//为了隐藏有国际号码的电话号码，像 "+111 111 111 1111"，我们以 "+***-***-***-1111" 的格式来显示。
//在本地号码前面的 '+' 号和第一个 '-' 号仅当电话号码中包含国际号码时存在。例如，一个 12 位的电话号码应当以 "+**-" 开头进行显示。
//注意：像 "("，")"，" " 这样的不相干的字符以及不符合上述格式的额外的减号或者加号都应当被删除。
//
//最后，将提供的信息正确隐藏后返回。
//
//示例 1：
//输入: "LeetCode@LeetCode.com"
//输出: "l*****e@leetcode.com"
//解释：
//所有的名称转换成小写, 第一个名称的第一个字符和最后一个字符中间由 5 个星号代替。
//因此，"leetcode" -> "l*****e"。
//
//示例 2：
//输入: "AB@qq.com"
//输出: "a*****b@qq.com"
//解释: 
//第一个名称"ab"的第一个字符和最后一个字符的中间必须有 5 个星号
//因此，"ab" -> "a*****b"。
//
//示例 3：
//输入: "1(234)567-890"
//输出: "***-***-7890"
//解释: 
//10 个数字的电话号码，那意味着所有的数字都是本地号码。
//
//示例 4：
//输入: "86-(10)12345678"
//输出: "+**-***-***-5678"
//解释: 
//12 位数字，2 个数字是国际号码另外 10 个数字是本地号码 。
// 
//注意:
//S.length <= 40。
//邮箱的长度至少是 8。
//电话号码的长度至少是 10。
//*/
//string maskPII(const string &S)
//{
//    auto idx_at = S.find('@');
//    if (idx_at != string::npos)
//    {
//        string res;
//        res.push_back(std::tolower(S[0]));
//        res += "*****";
//        res.push_back(std::tolower(S[idx_at - 1]));
//        string left = S.substr(idx_at);
//        for (auto &c : left)
//            c = std::tolower(c);
//        res += std::move(left);
//        return res;
//    }
//    else
//    {
//        string digits;
//        for (auto c : S)
//            if (std::isdigit(c))
//                digits.push_back(c);
//        string res;
//        res = "***-***-" + digits.substr(digits.size() - 4);
//        string international_digit(digits.size() - 10, '*');
//        if (international_digit.size() > 0)
//            res = "+" + std::move(international_digit) + "-" + std::move(res);
//        return res;
//    }
//}
//
///*
//833. 字符串中的查找与替换
//对于某些字符串 S，我们将执行一些替换操作，用新的字母组替换原有的字母组（不一定大小相同）。
//每个替换操作具有 3 个参数：起始索引 i，源字 x 和目标字 y。规则是如果 x 从原始字符串 S 中的位置 i 开始，那么我们将用 y 替换出现的 x。如果没有，我们什么都不做。
//举个例子，如果我们有 S = “abcd” 并且我们有一些替换操作 i = 2，x = “cd”，y = “ffff”，那么因为 “cd” 从原始字符串 S 中的位置 2 开始，我们将用 “ffff” 替换它。
//再来看 S = “abcd” 上的另一个例子，如果我们有替换操作 i = 0，x = “ab”，y = “eee”，以及另一个替换操作 i = 2，x = “ec”，y = “ffff”，那么第二个操作将不执行任何操作，因为原始字符串中 S[2] = 'c'，与 x[0] = 'e' 不匹配。
//所有这些操作同时发生。保证在替换时不会有任何重叠： S = "abc", indexes = [0, 1], sources = ["ab","bc"] 不是有效的测试用例。
//
//示例 1：
//输入：S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
//输出："eeebffff"
//解释：
//"a" 从 S 中的索引 0 开始，所以它被替换为 "eee"。
//"cd" 从 S 中的索引 2 开始，所以它被替换为 "ffff"。
//
//示例 2：
//输入：S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
//输出："eeecd"
//解释：
//"ab" 从 S 中的索引 0 开始，所以它被替换为 "eee"。
//"ec" 没有从原始的 S 中的索引 2 开始，所以它没有被替换。
// 
//提示：
//0 <= indexes.length = sources.length = targets.length <= 100
//0 < indexes[i] < S.length <= 1000
//给定输入中的所有字符都是小写字母。
//*/
//string findReplaceString(const string &S, vector<int> &indexes, vector<string> &sources, vector<string> &targets)
//{
//    if (S.empty() || indexes.empty())
//        return S;
//
//    auto string_eq = [](const string &s1, int start, const string &s2) -> bool
//    {
//        int i = 0;
//        for (; start < s1.size() && i < s2.size(); ++start, ++i)
//            if (s1[start] != s2[i])
//                break;
//        if (i == s2.size())
//            return true;
//        return false;
//    };
//
//    vector<int> indices(indexes.size());
//    for (int i = 0; i < indexes.size(); i++)
//        indices[i] = i;
//    std::sort(indices.begin(), indices.end(), [&indexes](int a, int b) { return indexes[a] < indexes[b]; });
//
//    string res;
//    int pre_stop = -1;
//    for (int i = 0; i < indices.size(); ++i)
//    {
//        int index = indices[i];
//        if (string_eq(S, indexes[index], sources[index]))
//        {
//            res += S.substr(pre_stop + 1, indexes[index] - pre_stop - 1) + std::move(targets[index]);
//            pre_stop = indexes[index] + sources[index].size() - 1;
//        }
//    }
//    if (pre_stop != S.size() - 1)
//        res += S.substr(pre_stop + 1);
//    return res;
//}

///*
//835. 图像重叠
//给出两个图像 A 和 B ，A 和 B 为大小相同的二维正方形矩阵。（并且为二进制矩阵，只包含0和1）。
//我们转换其中一个图像，向左，右，上，或下滑动任何数量的单位，并把它放在另一个图像的上面。之后，该转换的重叠是指两个图像都具有 1 的位置的数目。
//（请注意，转换不包括向任何方向旋转。）
//最大可能的重叠是什么？
//
//示例 1:
//输入：A = [[1,1,0],
//          [0,1,0],
//          [0,1,0]]
//     B = [[0,0,0],
//          [0,1,1],
//          [0,0,1]]
//输出：3
//解释: 将 A 向右移动一个单位，然后向下移动一个单位。
//
//注意: 
//1 <= A.length = A[0].length = B.length = B[0].length <= 30
//0 <= A[i][j], B[i][j] <= 1
//
//思路：https://leetcode-cn.com/problems/image-overlap/solution/tu-xiang-zhong-die-by-leetcode/
//*/
//int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
//{
//    int N = A.size();
//    vector<vector<int>> count(2 * N, vector<int>(2 * N, 0));
//    for (int i = 0; i < N; ++i)
//        for (int j = 0; j < N; ++j)
//            if (A[i][j] == 1)
//                for (int i2 = 0; i2 < N; ++i2)
//                    for (int j2 = 0; j2 < N; ++j2)
//                        if (B[i2][j2] == 1)
//                            count[i - i2 + N][j - j2 + N] += 1;
//
//    int res = 0;
//    for (const auto &row : count)
//        for (int cnt : row)
//            res = std::max(res, cnt);
//    return res;
//}
//
///*
//837. 新21点
//爱丽丝参与一个大致基于纸牌游戏 “21点” 规则的游戏，描述如下：
//爱丽丝以 0 分开始，并在她的得分少于 K 分时抽取数字。 
//抽取时，她从 [1, W] 的范围中随机获得一个整数作为分数进行累计，其中 W 是整数。 
//每次抽取都是独立的，其结果具有相同的概率。
//当爱丽丝获得不少于 K 分时，她就停止抽取数字。 爱丽丝的分数不超过 N 的概率是多少？
//
//示例 1：
//输入：N = 10, K = 1, W = 10
//输出：1.00000
//说明：爱丽丝得到一张卡，然后停止。
//
//示例 2：
//输入：N = 6, K = 1, W = 10
//输出：0.60000
//说明：爱丽丝得到一张卡，然后停止。
//在 W = 10 的 6 种可能下，她的得分不超过 N = 6 分。
//
//示例 3：
//输入：N = 21, K = 17, W = 10
//输出：0.73278
//
//提示：
//0 <= K <= N <= 10000
//1 <= W <= 10000
//如果答案与正确答案的误差不超过 10^-5，则该答案将被视为正确答案通过。
//此问题的判断限制时间已经减少。
//
//思路：https://leetcode-cn.com/problems/new-21-game/solution/xin-21dian-by-leetcode/
//*/
//double new21Game(int N, int K, int W)
//{
//    if (N >= K - 1 + W)
//        return 1;
//
//    vector<double> dp(std::max(N + 1, K + W), 0);
//    // dp[x] = the answer when Alice has x points
//    for (int k = K; k <= N; ++k)
//        dp[k] = 1.0;
//
//    double S = std::min(N - K + 1, W);
//    // S = dp[k+1] + dp[k+2] + ... + dp[k+W]
//    for (int k = K - 1; k >= 0; --k)
//    {
//        dp[k] = S / W;
//        S += dp[k] - dp[k + W];
//    }
//    return dp[0];
//}

///*
//838. 推多米诺
//一行中有 N 张多米诺骨牌，我们将每张多米诺骨牌垂直竖立。
//在开始时，我们同时把一些多米诺骨牌向左或向右推。
//每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。
//同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。
//如果同时有多米诺骨牌落在一张垂直竖立的多米诺骨牌的两边，由于受力平衡， 该骨牌仍然保持不变。
//就这个问题而言，我们会认为正在下降的多米诺骨牌不会对其它正在下降或已经下降的多米诺骨牌施加额外的力。
//给定表示初始状态的字符串 "S" 。
//如果第 i 张多米诺骨牌被推向左边，则 S[i] = 'L'；如果第 i 张多米诺骨牌被推向右边，则 S[i] = 'R'；
//如果第 i 张多米诺骨牌没有被推动，则 S[i] = '.'。
//返回表示最终状态的字符串。
//
//示例 1：
//输入：".L.R...LR..L.."
//输出："LL.RR.LLRRLL.."
//
//示例 2：
//输入："RR.L"
//输出："RR.L"
//说明：第一张多米诺骨牌没有给第二张施加额外的力。
//
//提示：
//0 <= N <= 10^5
//表示多米诺骨牌状态的字符串只含有 'L'，'R'; 以及 '.';
//
//思路：模拟法
//*/
//string pushDominoes(const string &dominoes)
//{
//    int length = dominoes.size();
//    if (length <= 1)
//        return dominoes;
//
//    string res;
//    int idx = 0, pre = 0;
//    while (idx < length)
//    {
//        // 找第一个R
//        int farest_L = -1; // 最右侧L的位置
//        while (idx < length && dominoes[idx] != 'R')
//        {
//            if (dominoes[idx] == 'L')
//                farest_L = idx;
//            ++idx;
//        }
//        if (idx == length) // 未找到R就到末尾了
//        {
//            if (farest_L == -1) // 情况为... -> ...
//                res += string(idx - pre, '.');
//            else // 情况为...L...L... -> LLLLLLLL...
//            {
//                res += string(farest_L - pre + 1, 'L');
//                res += string(idx - farest_L - 1, '.');
//            }
//            break;
//        }
//        if (farest_L == -1) // 情况为...R -> ...R
//            res += string(idx - pre, '.');
//        else // 情况为...L...L...R -> LLLLLLLL...R
//        {
//            res += string(farest_L - pre + 1, 'L');
//            res += string(idx - farest_L - 1, '.');
//        }
//        // 找到R
//        pre = idx;
//
//        // 找第一个L
//        int closest_R = pre; // 最右边的R
//        while (idx < length && dominoes[idx] != 'L')
//        {
//            if (dominoes[idx] == 'R')
//                closest_R = idx;
//            ++idx;
//        }
//        if (idx == length) // 未找到L就到末尾了
//        {
//            // 情况为R... -> RRRR
//            res += string(idx - pre, 'R');
//            break;
//        }
//        // 情况为R...R..L
//        res += string(closest_R - pre, 'R');
//        int len_RL = idx - closest_R + 1;
//        res += string(len_RL / 2, 'R');
//        if (len_RL % 2 != 0) // 情况为R...R.L
//            res.push_back('.');
//        res += string(len_RL / 2, 'L');
//        ++idx;
//        pre = idx;
//    }
//    return res;
//}
//
///*
//841. 钥匙和房间
//有 N 个房间，开始时你位于 0 号房间。
//每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。
//在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 
//钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。
//最初，除 0 号房间外的其余所有房间都被锁住。
//你可以自由地在房间之间来回走动。
//如果能进入每个房间返回 true，否则返回 false。
//
//示例 1：
//输入: [[1],[2],[3],[]]
//输出: true
//解释:
//我们从 0 号房间开始，拿到钥匙 1。
//之后我们去 1 号房间，拿到钥匙 2。
//然后我们去 2 号房间，拿到钥匙 3。
//最后我们去了 3 号房间。
//由于我们能够进入每个房间，我们返回 true。
//
//示例 2：
//输入：[[1,3],[3,0,1],[2],[0]]
//输出：false
//解释：我们不能进入 2 号房间。
//
//提示：
//1 <= rooms.length <= 1000
//0 <= rooms[i].length <= 1000
//所有房间中的钥匙数量总计不超过 3000。
//
//思路：图的深搜
//*/
//void canVisitAllRoomsRecursively(const vector<vector<int>> &rooms, vector<bool> &visited, int cur_room)
//{
//    for (int next_room : rooms[cur_room])
//    {
//        if (!visited[next_room])
//        {
//            visited[next_room] = true;
//            canVisitAllRoomsRecursively(rooms, visited, next_room);
//        }
//    }
//}
//bool canVisitAllRooms(const vector<vector<int>> &rooms)
//{
//    int length = rooms.size();
//    if (length == 1)
//        return true;
//
//    vector<bool> visited(length, false);
//    visited[0] = true;
//    canVisitAllRoomsRecursively(rooms, visited, 0);
//
//    int room_cnt = 0;
//    for (int i = 0; i < length; i++)
//    {
//        if (visited[i])
//            ++room_cnt;
//    }
//    return room_cnt == length;
//}

///*
//842. 将数组拆分成斐波那契序列
//给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。
//形式上，斐波那契式序列是一个非负整数列表 F，且满足：
//0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
//F.length >= 3；
//对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
//另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。
//返回从 S 拆分出来的所有斐波那契式的序列块，如果不能拆分则返回 []。
//
//示例 1：
//输入："123456579"
//输出：[123,456,579]
//
//示例 2：
//输入: "11235813"
//输出: [1,1,2,3,5,8,13]
//
//示例 3：
//输入: "112358130"
//输出: []
//解释: 这项任务无法完成。
//
//示例 4：
//输入："0123"
//输出：[]
//解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
//
//示例 5：
//输入: "1101111"
//输出: [110, 1, 111]
//解释: 输出 [11,0,11,11] 也同样被接受。
//
//提示：
//1 <= S.length <= 200
//字符串 S 中只含有数字。
//
//思路：暴力求解即可
//*/
//vector<int> splitIntoFibonacci(const string &S)
//{
//    int length = S.size();
//    if (length < 3)
//        return {};
//
//    for (int len1 = 1; len1 <= length / 2 + 1 && len1 < 11; len1++)
//    {
//        if (S[0] == '0' && len1 > 1)
//            break;
//
//        long long a = std::stoll(S.substr(0, len1));
//        if (a > INT_MAX)
//            break;
//        for (int len2 = 1; len2 <= length / 2 + 1 && len2 < 11; len2++)
//        {
//            if (S[len1] == '0' && len2 > 1)
//                break;
//
//            int len3 = std::max(len1, len2);
//            if (len1 + len2 > length || (length - len1 - len2) < len3)
//                break;
//
//            long long b = std::stoll(S.substr(len1, len2));
//            if (b > INT_MAX)
//                break;
//
//            bool found = false;
//            long long c;
//            if ((c = std::stoll(S.substr(len1 + len2, len3))) == a + b
//                || (++len3 < 11 && (c = std::stoll(S.substr(len1 + len2, len3))) == a + b))
//                found = true;
//
//            if (c <= INT_MAX && found)
//            {
//                vector<int> res;
//                res.push_back(a);
//                res.push_back(b);
//                res.push_back(c);
//                int index = len1 + len2 + len3;
//
//                long long one = b, two = c, three = one + two;
//                if (three > INT_MAX)
//                    break;
//                string s = std::to_string(three);
//                while (index < length)
//                {
//                    if (s == S.substr(index, s.size()))
//                    {
//                        res.push_back(three);
//                        index += s.size();
//                        one = two;
//                        two = three;
//                        three = one + two;
//                        if (three > INT_MAX)
//                            break;
//                        s = std::to_string(three);
//                    }
//                    else
//                        break;
//                }
//                if (index == length)
//                    return res;
//            }
//        }
//    }
//    return {};
//}

///*
//845. 数组中的最长山脉
//我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
//B.length >= 3
//存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
//（注意：B 可以是 A 的任意子数组，包括整个数组 A。）
//给出一个整数数组 A，返回最长 “山脉” 的长度。
//如果不含有 “山脉” 则返回 0。
//
//示例 1：
//输入：[2,1,4,7,3,2,5]
//输出：5
//解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
//
//示例 2：
//输入：[2,2,2]
//输出：0
//解释：不含 “山脉”。
// 
//提示：
//0 <= A.length <= 10000
//0 <= A[i] <= 10000
//
//思路：
//1）计算相邻两个整数的差值，存储在差值数组中
//2）根据山脉的定义可知，一个山脉必定是连续正差值接着连续负差值，即
//    ???...??? +++...+++---...--- ???...???
//              [山脉起始..山脉结束]
//3）计算最长山脉即可
//*/
//int longestMountain(const vector<int> &A)
//{
//    int len = A.size();
//    if (len < 3)
//        return 0;
//
//    int length = len - 1;
//    vector<int> diff(length); // 差值数组
//    for (int i = 0; i < length; i++)
//        diff[i] = A[i + 1] - A[i];
//
//    int inc_start; // 正差值起始位置
//    int idx = 0;
//    int res = 0;
//    while (idx < length)
//    {
//        // 寻找第一个正差值
//        while (idx < length && diff[idx] <= 0)
//            ++idx;
//        if (idx == length)
//            break;
//        inc_start = idx;
//
//        // 连续正差值
//        while (idx < length && diff[idx] > 0)
//            ++idx;
//        if (idx == length)
//            break;
//
//        // 遇到0，意味着相邻整数相等，不符合山脉要求，continue
//        if (diff[idx] == 0)
//            continue;
//
//        // 连续负差值
//        while (idx < length && diff[idx] < 0)
//            ++idx;
//
//        // 计算山脉长度
//        res = std::max(res, idx - inc_start + 1);
//    }
//    return res;
//}
//// 思路2：优化
//int longestMountain2(const vector<int> &A)
//{
//    int length = A.size();
//    if (length < 3)
//        return 0;
//    --length;
//
//    int inc_start;
//    int idx = 0;
//    int res = 0;
//    while (idx < length)
//    {
//        while (idx < length && A[idx + 1] <= A[idx])
//            ++idx;
//        if (idx == length)
//            break;
//        inc_start = idx;
//        while (idx < length && A[idx + 1] > A[idx])
//            ++idx;
//        if (idx == length)
//            break;
//        if (A[idx + 1] == A[idx])
//            continue;
//        while (idx < length && A[idx + 1] < A[idx])
//            ++idx;
//        res = std::max(res, idx - inc_start + 1);
//    }
//    return res;
//}

///*
//846. 一手顺子
//爱丽丝有一手（hand）由整数数组给定的牌。 
//现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。
//如果她可以完成分组就返回 true，否则返回 false。
//
//示例 1：
//输入：hand = [1,2,3,6,2,3,4,7,8], W = 3
//输出：true
//解释：爱丽丝的手牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
//
//示例 2：
//输入：hand = [1,2,3,4,5], W = 4
//输出：false
//解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。
// 
//提示：
//1 <= hand.length <= 10000
//0 <= hand[i] <= 10^9
//1 <= W <= hand.length
//
//思路：模拟法
//1）使用map，统计牌的张数的同时对牌进行排序
//2）然后按照要求依次构造顺子
//*/
//bool isNStraightHand(const vector<int> &hand, int W)
//{
//    if (W == 1)
//        return true;
//    int length = hand.size();
//    if (length % W != 0)
//        return false;
//
//    map<int, int> num_cnt;
//    for (int num : hand)
//        ++num_cnt[num];
//    if (num_cnt.size() < W)
//        return false;
//
//    using MapIter = map<int, int>::iterator;
//    vector<MapIter> iters;
//    iters.reserve(num_cnt.size());
//    for (auto iter = num_cnt.begin(); iter != num_cnt.end(); ++iter)
//        iters.push_back(iter);
//
//    int idx = 0;
//    while (idx < iters.size())
//    {
//        int cnt = iters[idx]->second;
//        if (cnt == 0)
//        {
//            ++idx;
//            continue;
//        }
//        iters[idx]->second = 0;
//        if (idx + W - 1 >= iters.size())
//            return false;
//        for (int i = 1; i < W; i++)
//        {
//            if (iters[idx + i]->first - iters[idx + i - 1]->first != 1 || iters[idx + i]->second < cnt)
//                return false;
//            iters[idx + i]->second -= cnt;
//        }
//        ++idx;
//    }
//    return true;
//}
///*思路2：每张牌对W取余，然后统计余数个数，构成顺子需要满足所有余数的个数相同 */
//bool isNStraightHand2(const vector<int> &hand, int W)
//{
//    if (W == 1)
//        return true;
//    int length = hand.size();
//    if (length % W != 0)
//        return false;
//
//    vector<int> W_array(W, 0);
//    for (int num : hand)
//        ++W_array[num % W];
//
//    return all_of(++W_array.begin(), W_array.end(), [&W_array](int cnt) { return cnt == W_array[0]; });
//}

///*
//848. 字母移位
//有一个由小写字母组成的字符串 S，和一个整数数组 shifts。
//我们将字母表中的下一个字母称为原字母的 移位（由于字母表是环绕的， 'z' 将会变成 'a'）。
//例如·，shift('a') = 'b'， shift('t') = 'u',， 以及 shift('z') = 'a'。
//对于每个 shifts[i] = x ， 我们会将 S 中的前 i+1 个字母移位 x 次。
//返回将所有这些移位都应用到 S 后最终得到的字符串。
//
//示例：
//输入：S = "abc", shifts = [3,5,9]
//输出："rpl"
//解释：
//我们以 "abc" 开始。
//将 S 中的第 1 个字母移位 3 次后，我们得到 "dbc"。
//再将 S 中的前 2 个字母移位 5 次后，我们得到 "igc"。
//最后将 S 中的这 3 个字母移位 9 次后，我们得到答案 "rpl"。
//
//提示：
//1 <= S.length = shifts.length <= 20000
//0 <= shifts[i] <= 10 ^ 9
//*/
//string shiftingLetters(string &S, vector<int> &shifts)
//{
//    int length = shifts.size();
//    for (int i = length - 2; i >= 0; i--)
//        shifts[i] += shifts[i + 1] % 26;
//
//    for (int i = 0; i < length; i++)
//        S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
//
//    return S;
//}

///*
//862. 和至少为 K 的最短子数组
//返回 A 的最短的非空连续子数组的长度，该子数组的和至少为 K 。
//如果没有和至少为 K 的非空子数组，返回 -1 。
//
//示例 1：
//输入：A = [1], K = 1
//输出：1
//
//示例 2：
//输入：A = [1,2], K = 4
//输出：-1
//
//示例 3：
//输入：A = [2,-1,2], K = 3
//输出：3
//
//提示：
//1 <= A.length <= 50000
//-10 ^ 5 <= A[i] <= 10 ^ 5
//1 <= K <= 10 ^ 9
//*/
//int shortestSubarray(const vector<int> &A, int K) {
//    int length = A.size();
//    if (length == 1) {
//        if (A.back() < K) {
//            return -1;
//        } else {
//            return 1;
//        }
//    }
//
//    vector<long> sums(length + 1);
//    for (int i = 0; i < length; ++i) {
//        sums[i + 1] = sums[i] + A[i];
//    }
//
//    deque<int> qu;
//    int res = length + 1;
//    for (int i = 0; i <= length; ++i) {
//        while (!qu.empty() && sums[i] <= sums[qu.back()]) {
//            qu.pop_back();
//        }
//        while (!qu.empty() && sums[i] - sums[qu.front()] >= K) {
//            res = std::min(res, i - qu.front());
//            qu.pop_front();
//        }
//        qu.push_back(i);
//    }
//
//    if (res == length + 1) {
//        return -1;
//    } else {
//        return res;
//    }
//}

///*
//m*n的办公区，'.'表示有电源，'*'表示无电源，员工需要坐在有电源的办公桌，
//同时，员工的前后左右不能有其他员工，
//求办公区最多能容纳多少员工
//其中1 <= m, n <= 8
//
//思路：压缩dp
//用位图表示一行的员工的分布，bit为1的位置表示有员工坐，否则无
//那么假设有8列，那么员工的分布的位图有00000000~11111111共256种情况，也就是256种状态
//*/
//int GetMaxStaffs(const vector<vector<char>> &pos) {
//    int rows = pos.size(), cols = pos[0].size();
//    int total_status_cnt = 1 << cols; // 每一行状态的数量
//    // dp[r][s]表示r行的第s种状态时，最多的员工数
//    vector<vector<int>> dp(rows + 1, vector<int>(total_status_cnt));
//
//    for (int row = 1; row <= rows; row++) { // 遍历每一行
//        for (int status = 0; status < total_status_cnt; status++) { // 遍历所有状态
//            bitset<8> status_bits(status); // 当前状态
//            bool is_status_ok = true; // 当前状态是否符合要求
//            // 需要满足有员工的地方有电源，员工的左右没有其他员工
//            for (int col = 0; col < cols; col++) {
//                if ((status_bits[col] && pos[row - 1][col] == '*')
//                    || (col < cols - 1 && status_bits[col] && status_bits[col + 1])) {
//                    is_status_ok = false;
//                    break;
//                }
//            }
//            if (!is_status_ok) { // 当前状态不符合要求，置为不合法，跳过
//                dp[row][status] = -1;
//                continue;
//            }
//            // 当前状态符合要求，遍历上一行的所有状态，进行dp
//            for (int last_status = 0; last_status < total_status_cnt; last_status++) {
//                if (dp[row - 1][last_status] == -1) { // 无效的跳过
//                    continue;
//                }
//                bitset<8> last_status_bits(last_status);
//                bool is_last_status_ok = true; // 上一个状态和本状态是否冲突
//                // 不冲突的条件：当前员工的前面不能有其他员工
//                for (int col = 0; col < cols; col++) {
//                    if (last_status_bits[col] && status_bits[col]) {
//                        is_last_status_ok = false;
//                        break;
//                    }
//                }
//                // 上一个状态和本状态不冲突
//                if (is_last_status_ok) {
//                    // 状态转移方程
//                    dp[row][status] = std::max(dp[row][status],
//                                               dp[row - 1][last_status] + static_cast<int>(status_bits.count()));
//                }
//            }
//        }
//    }
//
//    // 取最后一行最大的结果
//    int res = 0;
//    for (int i = 0; i < total_status_cnt; i++) {
//        if (dp[rows][i] > res) {
//            res = dp[rows][i];
//        }
//    }
//    return res;
//}

///*
//932. 漂亮数组
//对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：
//对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。
//那么数组 A 是漂亮数组。
//给定 N，返回任意漂亮数组 A（保证存在一个）。
//
//示例 1：
//输入：4
//输出：[2,1,4,3]
//
//示例 2：
//输入：5
//输出：[3,1,2,5,4]
//
//提示：
//1 <= N <= 1000
//
//思路1：带备忘录的递归
//*/
//vector<int> beautifulArrayRecursively(unordered_map<int, vector<int>> &mem, int n) {
//    if (n == 1)
//        return {1};
//
//    if (mem.count(n))
//        return mem[n];
//
//    vector<int> odds = beautifulArrayRecursively(mem, (n + 1) / 2);
//    vector<int> evens = beautifulArrayRecursively(mem, n / 2);
//    vector<int> res;
//    res.reserve(odds.size() + evens.size());
//    for (int odd : odds)
//        res.push_back(2 * odd - 1);
//    for (int even : evens)
//        res.push_back(2 * even);
//    mem[n] = res;
//    return res;
//}
//vector<int> beautifulArray(int N) {
//    unordered_map<int, vector<int>> mem;
//    mem[1] = {1};
//    return beautifulArrayRecursively(mem, N);
//}
//// 思路2：直接构造
//vector<int> beautifulArray2(int N) {
//    if (N == 1)
//        return {1};
//
//    vector<int> arr = {1};
//    while (arr.size() <= N) {
//        for (int &a : arr)
//            a = a * 2 - 1;
//        for (int i = 0, length = arr.size(); i < length; i++)
//            arr.push_back(arr[i] + 1);
//    }
//    vector<int> res;
//    for (int a : arr) {
//        if (a <= N)
//            res.push_back(a);
//    }
//    return res;
//}

///************************排序*****************************/
//template<typename Container, typename Cmp = std::less_equal<typename Container::value_type>>
//bool is_sorted(const Container &arr, Cmp cmp = std::less_equal<typename Container::value_type>()) {
//    auto length = arr.size();
//    if (length <= 1)
//        return true;
//
//    for (size_t i = 0; i < length - 1; i++) {
//        if (!cmp(arr[i], arr[i + 1]))
//            return false;
//    }
//    return true;
//}
//
///*
//冒泡排序
//时间复杂度（平均）   时间复杂度（最坏）   时间复杂度（最好）   空间复杂度   稳定性
//O(n^2)            O(n^2)           O(n)              O(1)       稳定
//*/
//template<typename Container, typename Cmp = std::less<typename Container::value_type>>
//void bubble_sort(Container &arr, Cmp cmp = std::less<typename Container::value_type>()) {
//    auto length = arr.size();
//    if (length <= 1)
//        return;
//
//    for (size_t i = 0; i < length - 1; i++) {
//        bool is_sorted = true;
//        for (size_t j = 0; j < length - i - 1; j++) {
//            if (cmp(arr[j + 1], arr[j])) {
//                std::swap(arr[j], arr[j + 1]);
//                is_sorted = false;
//            }
//        }
//        if (is_sorted)
//            break;
//    }
//}
//
///*
//选择排序
//时间复杂度（平均）   时间复杂度（最坏）   时间复杂度（最好）   空间复杂度   稳定性
//O(n^2)            O(n^2)           O(n^2)            O(1)       不稳定
//*/
//template<typename Container, typename Cmp = std::less<typename Container::value_type>>
//void select_sort(Container &arr, Cmp cmp = std::less<typename Container::value_type>()) {
//    auto length = arr.size();
//    if (length <= 1)
//        return;
//
//    for (size_t i = 0; i < length - 1; i++) {
//        size_t min_idx = i;
//        for (size_t j = i + 1; j < length; j++) {
//            if (cmp(arr[j], arr[min_idx]))
//                min_idx = j;
//        }
//        std::swap(arr[i], arr[min_idx]);
//    }
//}
//
///*
//插入排序
//时间复杂度（平均）   时间复杂度（最坏）   时间复杂度（最好）   空间复杂度   稳定性
//O(n^2)            O(n^2)           O(n)              O(1)       稳定
//*/
//template<typename Container, typename Cmp = std::less<typename Container::value_type>>
//void insert_sort(Container &arr, Cmp cmp = std::less<typename Container::value_type>()) {
//    auto length = arr.size();
//    if (length <= 1)
//        return;
//
//    for (size_t i = 0; i < length - 1; i++) {
//        auto pre_idx = i;
//        typename Container::value_type val = arr[i + 1];
//        bool stop_at_first = false;
//        while (pre_idx >= 0 && cmp(val, arr[pre_idx])) {
//            arr[pre_idx + 1] = arr[pre_idx];
//            if (pre_idx == 0) {
//                arr[0] = val;
//                stop_at_first = true;
//                break;
//            }
//            --pre_idx;
//        }
//        if (!stop_at_first && pre_idx != i)
//            arr[pre_idx + 1] = val;
//    }
//}
//
///*
//shell排序
//时间复杂度（平均）   时间复杂度（最坏）   时间复杂度（最好）   空间复杂度   稳定性
//O(n^1.3)          O(n^2)           O(n)              O(1)       不稳定
//*/
//template<typename Container, typename Cmp = std::less<typename Container::value_type>>
//void shell_sort(Container &arr, Cmp cmp = std::less<typename Container::value_type>()) {
//    auto length = arr.size();
//    if (length <= 1)
//        return;
//
//    size_t gap = 1;
//    while (gap < length / 3) // 改进版，动态间隔
//        gap = gap * 3 + 1;
//
//    // for (size_t gap = length / 2; gap > 0; gap /= 2) { // 原始的shell排序所定义的间隔
//    for (; gap > 0; gap /= 3) {
//        for (size_t i = gap; i < length; i++) {
//            typename Container::value_type val = arr[i];
//            auto pre_idx = i - gap;
//            bool stop_at_first = false;
//            while (pre_idx >= 0 && cmp(val, arr[pre_idx])) {
//                arr[pre_idx + gap] = arr[pre_idx];
//                if (pre_idx == 0 || pre_idx < gap) {
//                    arr[pre_idx] = val;
//                    stop_at_first = true;
//                    break;
//                }
//                pre_idx -= gap;
//            }
//            if (!stop_at_first && pre_idx != i - gap)
//                arr[pre_idx + gap] = val;
//        }
//    }
//}
//
///*
//归并排序
//时间复杂度（平均）   时间复杂度（最坏）   时间复杂度（最好）   空间复杂度   稳定性
//O(nlogn)          O(nlogn)         O(nlogn)          n          稳定
//*/
//template<typename Container, typename Cmp>
//void do_merge(Container &arr, size_t start, size_t middle, size_t stop, Cmp cmp) {
//    static vector<typename Container::value_type> tmp(arr.size());
//    tmp.clear();
//    size_t i = start, j = middle + 1;
//    while (i <= middle && j <= stop) {
//        if (cmp(arr[i], arr[j])) {
//            tmp.push_back(arr[i]);
//            i++;
//        } else {
//            tmp.push_back(arr[j]);
//            j++;
//        }
//    }
//    while (j <= stop) {
//        tmp.push_back(arr[j]);
//        j++;
//    }
//    while (i <= middle) {
//        tmp.push_back(arr[i]);
//        i++;
//    }
//    size_t tmp_idx = 0, arr_idx = start;
//    while (arr_idx <= stop) {
//        arr[arr_idx++] = tmp[tmp_idx++];
//    }
//}
//template<typename Container, typename Cmp>
//void do_merge_sort(Container &arr, size_t start, size_t stop, Cmp cmp) {
//    if (start >= stop)
//        return;
//
//    size_t middle = start + (stop - start) / 2;
//    do_merge_sort(arr, start, middle, cmp);
//    do_merge_sort(arr, middle + 1, stop, cmp);
//    do_merge(arr, start, middle, stop, cmp);
//}
//template<typename Container, typename Cmp = std::less<typename Container::value_type>>
//void merge_sort(Container &arr, Cmp cmp = std::less<typename Container::value_type>()) {
//    auto length = arr.size();
//    if (length <= 1)
//        return;
//
//    do_merge_sort(arr, 0, length - 1, cmp);
//}
//
///*
//快速排序
//时间复杂度（平均）   时间复杂度（最坏）   时间复杂度（最好）   空间复杂度   稳定性
//O(nlogn)          O(n^2)           O(nlogn)          O(logn)    不稳定
//*/
//template<typename Container, typename Cmp>
//size_t do_partition(Container &arr, size_t start, size_t stop, Cmp cmp) {
//    typename Container::value_type pivot_val = arr[start];
//    auto i = start, j = stop;
//    while (i < j) {
//        while (i < j && !cmp(arr[j], pivot_val))
//            j--;
//        arr[i] = arr[j];
//        while (i < j && cmp(arr[i], pivot_val))
//            i++;
//        arr[j] = arr[i];
//    }
//    arr[i] = pivot_val;
//    return i;
//}
//template<typename Container, typename Cmp>
//void do_quick_sort(Container &arr, size_t start, size_t stop, Cmp cmp) {
//    if (start >= stop)
//        return;
//
//    size_t pivot = do_partition(arr, start, stop, cmp);
//    if (pivot > start)
//        do_quick_sort(arr, start, pivot - 1, cmp);
//    if (pivot < stop)
//        do_quick_sort(arr, pivot + 1, stop, cmp);
//}
//template<typename Container, typename Cmp = std::less<typename Container::value_type>>
//void quick_sort(Container &arr, Cmp cmp = std::less<typename Container::value_type>()) {
//    auto length = arr.size();
//    if (length <= 1)
//        return;
//
//    do_quick_sort(arr, 0, length - 1, cmp);
//}
//
///*
//堆排序
//时间复杂度（平均）   时间复杂度（最坏）   时间复杂度（最好）   空间复杂度   稳定性
//O(nlogn)          O(nlogn)         O(nlogn)          O(1)       不稳定
//*/
//template<typename Container, typename Cmp = std::less<typename Container::value_type>>
//void heap_sort(Container &arr, Cmp cmp = std::less<typename Container::value_type>()) {
//    auto length = arr.size();
//    if (length <= 1)
//        return;
//
//    std::make_heap(arr.begin(), arr.end(), cmp);
//    std::sort_heap(arr.begin(), arr.end(), cmp);
//}
///************************排序*****************************/

///*
//887. 鸡蛋掉落
//你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
//每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
//你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
//每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
//你的目标是确切地知道 F 的值是多少。
//无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
//
//示例 1：
//输入：K = 1, N = 2
//输出：2
//解释：
//鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
//否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
//如果它没碎，那么我们肯定知道 F = 2 。
//因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
//
//示例 2：
//输入：K = 2, N = 6
//输出：3
//
//示例 3：
//输入：K = 3, N = 14
//输出：4
//
//提示：
//1 <= K <= 100
//1 <= N <= 10000
//*/
//int superEggDrop(int K, int N) {
//    if (K == 1)
//        return N;
//    if (N == 1)
//        return 1;
//
//    vector<vector<int>> dp(K + 1, vector<int>(N + 1));
//    for (int i = 0; i <= N; i++) {
//        dp[1][i] = i;
//    }
//
//    for (int i = 2; i <= K; i++) {
//        for (int j = 1; j <= N; j++) {
//            int res = std::numeric_limits<int>::max();
//            //for (int k = 1; k <= j; k++) {
//            //    res = std::min(res, std::max(dp[i][j - k], dp[i - 1][k - 1]) + 1);
//            //}
//
//            int l = 1, r = j, mid;
//            while (l <= r) {
//                mid = l + (r - l) / 2;
//                if (dp[i - 1][mid - 1] == dp[i][j - mid]) {
//                    res = std::min(res, dp[i - 1][mid - 1] + 1);
//                    break;
//                } else if (dp[i - 1][mid - 1] > dp[i][j - mid]) {
//                    r = mid - 1;
//                    res = std::min(res, dp[i - 1][mid - 1] + 1);
//                } else {
//                    l = mid + 1;
//                    res = std::min(res, dp[i][j - mid] + 1);
//                }
//            }
//
//            dp[i][j] = res;
//        }
//    }
//
//    return dp[K][N];
//}
//
///*
//851. 喧闹和富有
//在一组 N 个人（编号为 0, 1, 2, ..., N-1）中，每个人都有不同数目的钱，以及不同程度的安静（quietness）。
//为了方便起见，我们将编号为 x 的人简称为 "person x "。
//如果能够肯定 person x 比 person y 更有钱的话，我们会说 richer[i] = [x, y] 。注意 richer 可能只是有效观察的一个子集。
//另外，如果 person x 的安静程度为 q ，我们会说 quiet[x] = q 。
//现在，返回答案 answer ，其中 answer[x] = y 的前提是，在所有拥有的钱不少于 person x 的人中，person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。
//
//示例：
//输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
//输出：[5,5,2,5,4,5,6,7]
//解释：
//answer[0] = 5，
//person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0 有更多的钱。
//唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
//但是目前还不清楚他是否比 person 0 更有钱。
//answer[7] = 7，
//在所有拥有的钱肯定不少于 person 7 的人中(这可能包括 person 3，4，5，6 以及 7)，
//最安静(有较低安静值 quiet[x])的人是 person 7。
//其他的答案也可以用类似的推理来解释。
//
//提示：
//1 <= quiet.length = N <= 500
//0 <= quiet[i] < N，所有 quiet[i] 都不相同。
//0 <= richer.length <= N * (N-1) / 2
//0 <= richer[i][j] < N
//richer[i][0] != richer[i][1]
//richer[i] 都是不同的。
//对 richer 的观察在逻辑上是一致的。
//*/
//int loudAndRichRecursively(const vector<vector<int>> &rich, const vector<int> &quiet, int cur, vector<int> &res) {
//    if (res[cur] != -1)
//        return res[cur];
//
//    if (rich[cur].empty())
//        return cur;
//
//    int ret = cur;
//    for (int r : rich[cur]) {
//        int idx = loudAndRichRecursively(rich, quiet, r, res);
//        if (quiet[ret] > quiet[idx]) {
//            ret = idx;
//        }
//    }
//    res[cur] = ret;
//    return ret;
//}
//vector<int> loudAndRich(const vector<vector<int>> &richer, const vector<int> &quiet) {
//    int N = quiet.size();
//    if (N == 1)
//        return {0};
//
//    vector<vector<int>> rich(N);
//    for (const auto &r : richer) {
//        rich[r[1]].push_back(r[0]);
//    }
//
//    vector<int> res(N, -1);
//    for (int i = 0; i < N; i++) {
//        if (res[i] == -1) {
//            res[i] = loudAndRichRecursively(rich, quiet, i, res);
//        }
//    }
//
//    return res;
//}

///*
//7. 整数反转
//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//
//示例 1:
//输入: 123
//输出: 321
//
//示例 2:
//输入: -123
//输出: -321
//
//示例 3:
//输入: 120
//输出: 21
//
//注意:
//假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
//*/
//int reverse(int x) {
//    long long res = 0;
//    while (x != 0) {
//        res = res * 10 + x % 10;
//        x /= 10;
//    }
//
//    return res < INT_MIN || res > INT_MAX ? 0 : res;
//}

//// 原地翻转链表
//void reverse_link_list(ListNode *head) {
//    if (head == nullptr || head->next == nullptr)
//        return;
//
//    ListNode *pre = head, *cur = head->next;
//    while (cur != nullptr) {
//        ListNode *t = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = t;
//    }
//
//    ListNode *last_second_node = head->next;
//    std::swap(*head, *pre);
//    last_second_node->next = pre;
//    pre->next = nullptr;
//}

///*
//166. 分数到小数
//给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
//如果小数部分为循环小数，则将循环的部分括在括号内。
//
//示例 1:
//输入: numerator = 1, denominator = 2
//输出: "0.5"
//
//示例 2:
//输入: numerator = 2, denominator = 1
//输出: "2"
//
//示例 3:
//输入: numerator = 2, denominator = 3
//输出: "0.(6)"
//*/
//string fractionToDecimal(int numerator, int denominator) {
//    if (numerator == 0)
//        return "0";
//
//    // 符号位
//    string res = (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) ? "-" : "";
//
//    // 分子分母转正数，同时为防止溢出，转long
//    long up = std::abs(numerator);
//    long down = std::abs(denominator);
//
//    // 求得整数部分
//    long int_part = up / down;
//    res.append(std::to_string(int_part));
//
//    // 能够整除
//    long leftover = up % down;
//    if (leftover == 0)
//        return res;
//
//    // 不能整除，添加小数点
//    res.push_back('.');
//
//    // 求得小数部分
//    vector<char> decimals;
//    unordered_map<long, int> leftover2idx;
//    int idx = 0, loop_start_idx = -1;
//    while (leftover > 0) {
//        leftover *= 10;
//        // 相同余数再次出现，记录第一次出现的位置为循环小数位置
//        if (leftover2idx.count(leftover)) {
//            loop_start_idx = leftover2idx[leftover];
//            break;
//        }
//
//        leftover2idx[leftover] = idx++;
//        decimals.push_back(leftover / down + '0');
//        leftover %= down;
//    }
//    string decimal_part;
//    for (int i = 0; i < decimals.size(); i++) {
//        // 在循环小数位置前添加括号
//        if (i == loop_start_idx)
//            decimal_part.push_back('(');
//        decimal_part.push_back(decimals[i]);
//    }
//    if (loop_start_idx != -1)
//        decimal_part.push_back(')');
//
//    return std::move(res) + std::move(decimal_part);
//}

///*
//179. 最大数
//给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
//
//示例 1:
//输入: [10,2]
//输出: 210
//
//示例 2:
//输入: [3,30,34,5,9]
//输出: 9534330
//说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
//*/
//string largestNumber(const vector<int> &nums) {
//    if (nums.empty())
//        return "";
//
//    vector<string> strs;
//    strs.reserve(nums.size());
//    bool is_all_zero = true;
//    for (int num : nums) {
//        if (num != 0) {
//            is_all_zero = false;
//        }
//
//        strs.push_back(std::to_string(num));
//    }
//    if (is_all_zero) {
//        return "0";
//    }
//
//    using Iter = vector<string>::iterator;
//    vector<Iter> iters;
//    iters.reserve(strs.size());
//    for (auto it = strs.begin(); it != strs.end(); ++it) {
//        iters.push_back(it);
//    }
//
//    std::sort(iters.begin(), iters.end(), [](Iter a, Iter b) {
//        return *a + *b > *b + *a;
//    });
//
//    string res;
//    for (Iter it : iters) {
//        res.append(*it);
//    }
//
//    return res;
//}

///*
//400. 第N个数字
//在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
//注意:
//n 是正数且在32位整数范围内 ( n < 231)。
//
//示例 1:
//输入:
//3
//输出:
//3
//
//示例 2:
//输入:
//11
//输出:
//0
//说明:
//第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
//*/
//int findNthDigit(int n) {
//    if (n < 10) {
//        return n;
//    }
//
//    int digit_cnt = 1;
//    int factor = 1;
//    long long cnt = 0;
//    while (cnt + 9ll * factor * digit_cnt < n) {
//        cnt += 9ll * factor * digit_cnt;
//        factor *= 10;
//        ++digit_cnt;
//    }
//
//    int num = factor + (n - cnt - 1) / digit_cnt;
//    int idx = (n - cnt - 1) % digit_cnt;
//    return std::to_string(num)[idx] - '0';
//}

/*
437. 路径总和 III
给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
返回 3。和等于 8 的路径有:
1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
*/
// 双重DFS：第一重，获得子树的根节点；第二重，遍历子树获得路径
//void getPathSumRecursively(TreeNode *p, int sum, int &res) {
//    if (p == nullptr)
//        return;
//
//    sum -= p->val;
//    if (sum == 0)
//        ++res;
//
//    getPathSumRecursively(p->left, sum, res);
//    getPathSumRecursively(p->right, sum, res);
//}
//void pathSumRecursively(TreeNode *p, int sum, int &res) {
//    if (p == nullptr)
//        return;
//
//    getPathSumRecursively(p, sum, res);
//    pathSumRecursively(p->left, sum, res);
//    pathSumRecursively(p->right, sum, res);
//}
//int pathSum(TreeNode *root, int sum) {
//    if (root == nullptr)
//        return 0;
//
//    int res = 0;
//    pathSumRecursively(root, sum, res);
//    return res;
//}
///*
//前缀和的思想
//前缀和：根节点到当前节点的和。如果两个不同节点的前缀和相同，意味着这两个节点之间的路径和为0
//同理，如果两个节点之间相差diff，那么两个节点之间的路径和为diff
//*/
//void pathSumRecursively(TreeNode *p, const int sum, unordered_map<int, int> &presum2cnt, int presum, int &res) {
//    if (p == nullptr)
//        return;
//
//    presum += p->val; // 计算前缀和
//    if (presum2cnt.count(presum - sum)) // 如果当前节点和之前的节点相差sum，那么这两个节点之间的路径和为sum
//        res += presum2cnt[presum - sum]; // 和当前节点相差sum的节点有多少个，那么就有这么多条路径
//
//    ++presum2cnt[presum]; // 前缀和为当前值的节点个数+1
//    pathSumRecursively(p->left, sum, presum2cnt, presum, res);
//    pathSumRecursively(p->right, sum, presum2cnt, presum, res);
//    --presum2cnt[presum]; // 回溯思想
//}
//int pathSum(TreeNode *root, int sum) {
//    if (root == nullptr)
//        return 0;
//
//    int res = 0;
//    unordered_map<int, int> presum2cnt;
//    presum2cnt[0] = 1;
//    pathSumRecursively(root, sum, presum2cnt, 0, res);
//    return res;
//}

/*
438. 找到字符串中所有字母异位词
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：
字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。

示例 1:
输入:
s: "cbaebabacd" p: "abc"
输出:
[0, 6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

示例 2:
输入:
s: "abab" p: "ab"
输出:
[0, 1, 2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
*/
//vector<int> findAnagrams(const string &s, const string &p) {
//    if (p.empty())
//        return {};
//    if (p.size() > s.size())
//        return {};
//
//    unordered_map<char, int> need;
//    for (char c : p) {
//        ++need[c];
//    }
//
//    unordered_map<char, int> window;
//    int left = 0, right = 0;
//    int valid = 0;
//    vector<int> res;
//    while (right < s.size()) {
//        char c = s[right];
//        ++right;
//        if (need.count(c)) {
//            ++window[c];
//            if (window[c] == need[c]) {
//                ++valid;
//            }
//        }
//
//        while (right - left >= p.size()) {
//            if (valid == need.size()) {
//                res.push_back(left);
//            }
//
//            c = s[left];
//            ++left;
//            if (need.count(c)) {
//                if (window[c] == need[c]) {
//                    --valid;
//                }
//
//                --window[c];
//            }
//        }
//    }
//
//    return res;
//}
//vector<int> findAnagrams(const string &s, const string &p) {
//    if (p.empty())
//        return {};
//    if (p.size() > s.size())
//        return {};
//
//    int need[256] = {0};
//    for (char c : p) {
//        ++need[c];
//    }
//    int target = 0;
//    for (int i = 0; i < 256; i++) {
//        if (need[i] != 0) {
//            ++target;
//        }
//    }
//
//    int window[256] = {0};
//    int left = 0, right = 0;
//    int valid = 0;
//    vector<int> res;
//    while (right < s.size()) {
//        char c = s[right];
//        ++right;
//        if (need[c] > 0) {
//            ++window[c];
//            if (window[c] == need[c]) {
//                ++valid;
//            }
//        }
//
//        while (right - left >= p.size()) {
//            if (valid == target) {
//                res.push_back(left);
//            }
//
//            c = s[left];
//            ++left;
//            if (need[c] > 0) {
//                if (window[c] == need[c]) {
//                    --valid;
//                }
//
//                --window[c];
//            }
//        }
//    }
//
//    return res;
//}

int main(int argc, char **argv) {
    //std::cout << "sizeof(std::string): " << sizeof(std::string) << '\n';
    //std::cout << "sizeof(std::pmr::string): " << sizeof(std::pmr::string) << '\n';

    //char buffer[256] = {}; // a small buffer on the stack
    //std::fill_n(std::begin(buffer), std::size(buffer) - 1, '_');

    //const auto BufferPrinter = [](std::string_view buf, std::string_view title) {
    //    std::cout << title << ":\n";
    //    for (auto &ch : buf) {
    //        std::cout << (ch >= ' ' ? ch : '#');
    //    }
    //    std::cout << '\n';
    //};

    //BufferPrinter(buffer, "zeroed buffer");

    //std::pmr::monotonic_buffer_resource pool{std::data(buffer), std::size(buffer)};
    //std::pmr::vector<std::pmr::string> vec{&pool};
    //vec.reserve(5);

    //vec.push_back("Hello World");
    //vec.push_back("One Two Three");
    //BufferPrinter(std::string_view(buffer, std::size(buffer)), "after two short strings");

    //vec.emplace_back("This is a longer string");
    //BufferPrinter(std::string_view(buffer, std::size(buffer)), "after longer string strings");

    //vec.push_back("Four Five Six");
    //BufferPrinter(std::string_view(buffer, std::size(buffer)), "after the last string");

    //char buffer[64] = {}; // a small buffer on the stack
    //std::fill_n(std::begin(buffer), std::size(buffer) - 1, '_');
    //std::cout << buffer << '\n';

    //std::pmr::monotonic_buffer_resource pool{std::data(buffer), std::size(buffer)};

    //std::pmr::vector<char> vec{&pool};
    //for (char ch = 'a'; ch <= 'z'; ++ch)
    //    vec.push_back(ch);

    //std::cout << buffer << '\n';

    //printContainer(findAnagrams("cbaebabacd", "abc"));
    //printContainer(findAnagrams("abab", "ab"));

    //assert(findNthDigit(10) == 1);
    //assert(findNthDigit(11) == 0);
    //assert(findNthDigit(12) == 1);
    //assert(findNthDigit(13) == 1);
    //assert(findNthDigit(14) == 1);
    //assert(findNthDigit(15) == 2);
    //assert(findNthDigit(1000) == 3);
    //assert(findNthDigit(1000000000) == 1);

    //cout << largestNumber({10,2}) << endl;
    //cout << largestNumber({3,30,34,5,9}) << endl;
    //cout << largestNumber({0,0,0,0}) << endl;
    //cout << largestNumber({824,938,1399,5607,6973,5703,9609,4398,8247}) << endl;

    //cout << fractionToDecimal(1, 2) << "\n";
    //cout << fractionToDecimal(2, 1) << "\n";
    //cout << fractionToDecimal(2, 3) << "\n";
    //cout << fractionToDecimal(7, -12) << "\n";

    //ListNode *head = new ListNode(0);
    //head->next = new ListNode(1);
    //head->next->next = new ListNode(2);
    //head->next->next->next = new ListNode(3);

    //auto print_link_list = [](ListNode *head) {
    //    ListNode *p = head;
    //    while (p != nullptr) {
    //        cout << p->val << " ";
    //        p = p->next;
    //    }
    //};

    //print_link_list(head);
    //cout << "\n";
    //reverse_link_list(head);
    //print_link_list(head);

    //cout << reverse(123) << endl;
    //cout << reverse(-123) << endl;
    //cout << reverse(120) << endl;
    //cout << reverse(INT_MIN) << endl;

    //auto f = [] (int a, int b) -> bool {
    //    return a < b;
    //};
    //cout << std::boolalpha << f(1, 2) << endl;

    //vector<vector<int>> richer = {{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    //vector<int> quiet = {3,2,5,4,6,1,7,0};
    //printContainer(loudAndRich(richer, quiet));

    //cout << superEggDrop(1, 2) << endl;
    //cout << superEggDrop(2, 6) << endl;
    //cout << superEggDrop(3, 14) << endl;

    //int a[10] = {0};
    //int a1[10] = {-1};
    //for (int i : a)
    //    cout << i << " ";
    //cout << "\n";
    //for (int i : a1)
    //    cout << i << " ";


    //char s[] = "Hello World!";
    //char *p = s;
    //printf("%p: %c\n", reinterpret_cast<void *>(p), *p);
    //printf("%p: %c\n", reinterpret_cast<void *>(++p), *p);


    //int cnt = 1024;
    //RandInt<int> randint(0, cnt);
    //vector<int> arr_origin;
    //arr_origin.reserve(cnt);
    //for (size_t i = 0; i < cnt; i++)
    //    arr_origin.push_back(randint());
    ////printContainer(arr);
    //RandReal<float> randreal(0, nextafter(cnt, std::numeric_limits<float>::max()));
    //vector<float> arr2_origin;
    //arr2_origin.reserve(cnt);
    //for (size_t i = 0; i < cnt; i++)
    //    arr2_origin.push_back(randreal());
    ////printContainer(arr2);

    ////cout << endl;
    //auto start_time = steady_clock::now(), stop_time = start_time;

    //vector<int> arr_sorted;
    //vector<float> arr2_sorted;
    //cout << "std::sort排序" << endl;
    //arr_sorted = arr_origin;
    //arr2_sorted = arr2_origin;
    //start_time = steady_clock::now();
    //std::sort(arr_sorted.begin(), arr_sorted.end());
    //stop_time = steady_clock::now();
    ////printContainer(arr_sorted);
    //printf("time spent(int): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //start_time = steady_clock::now();
    //std::sort(arr2_sorted.begin(), arr2_sorted.end());
    //stop_time = steady_clock::now();
    ////printContainer(arr2_sorted);
    //printf("time spent(real): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());

    //vector<int> arr;
    //vector<float> arr2;

    //cout << "堆排序" << endl;
    //arr = arr_origin;
    //arr2 = arr2_origin;
    //start_time = steady_clock::now();
    //heap_sort(arr);
    //stop_time = steady_clock::now();
    //if (arr == arr_sorted) {
    //    //printContainer(arr);
    //    printf("time spent(int): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}
    //start_time = steady_clock::now();
    //heap_sort(arr2);
    //stop_time = steady_clock::now();
    //if (arr2 == arr2_sorted) {
    //    //printContainer(arr2);
    //    printf("time spent(real): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}

    //cout << "快速排序" << endl;
    //arr = arr_origin;
    //arr2 = arr2_origin;
    //start_time = steady_clock::now();
    //quick_sort(arr);
    //stop_time = steady_clock::now();
    //if (arr == arr_sorted) {
    //    //printContainer(arr);
    //    printf("time spent(int): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}
    //start_time = steady_clock::now();
    //quick_sort(arr2);
    //stop_time = steady_clock::now();
    //if (arr2 == arr2_sorted) {
    //    //printContainer(arr2);
    //    printf("time spent(real): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}

    //cout << "归并排序" << endl;
    //arr = arr_origin;
    //arr2 = arr2_origin;
    //start_time = steady_clock::now();
    //merge_sort(arr);
    //stop_time = steady_clock::now();
    //if (arr == arr_sorted) {
    //    //printContainer(arr);
    //    printf("time spent(int): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}
    //start_time = steady_clock::now();
    //merge_sort(arr2);
    //stop_time = steady_clock::now();
    //if (arr2 == arr2_sorted) {
    //    //printContainer(arr2);
    //    printf("time spent(real): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}

    //cout << "shell排序" << endl;
    //arr = arr_origin;
    //arr2 = arr2_origin;
    //start_time = steady_clock::now();
    //shell_sort(arr);
    //stop_time = steady_clock::now();
    //if (arr == arr_sorted) {
    //    //printContainer(arr);
    //    printf("time spent(int): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}
    //start_time = steady_clock::now();
    //shell_sort(arr2);
    //stop_time = steady_clock::now();
    //if (arr2 == arr2_sorted) {
    //    //printContainer(arr2);
    //    printf("time spent(real): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}

    //cout << "插入排序" << endl;
    //arr = arr_origin;
    //arr2 = arr2_origin;
    //start_time = steady_clock::now();
    //insert_sort(arr);
    //stop_time = steady_clock::now();
    //if (arr == arr_sorted) {
    //    //printContainer(arr);
    //    printf("time spent(int): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}
    //start_time = steady_clock::now();
    //insert_sort(arr2);
    //stop_time = steady_clock::now();
    //if (arr2 == arr2_sorted) {
    //    //printContainer(arr2);
    //    printf("time spent(real): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}

    //cout << "选择排序" << endl;
    //arr = arr_origin;
    //arr2 = arr2_origin;
    //start_time = steady_clock::now();
    //select_sort(arr);
    //stop_time = steady_clock::now();
    //if (arr == arr_sorted) {
    //    //printContainer(arr);
    //    printf("time spent(int): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}
    //start_time = steady_clock::now();
    //select_sort(arr2);
    //stop_time = steady_clock::now();
    //if (arr2 == arr2_sorted) {
    //    //printContainer(arr2);
    //    printf("time spent(real): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}

    //cout << "冒泡排序" << endl;
    //arr = arr_origin;
    //arr2 = arr2_origin;
    //start_time = steady_clock::now();
    //bubble_sort(arr);
    //stop_time = steady_clock::now();
    //if (arr == arr_sorted) {
    //    //printContainer(arr);
    //    printf("time spent(int): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}
    //start_time = steady_clock::now();
    //bubble_sort(arr2);
    //stop_time = steady_clock::now();
    //if (arr2 == arr2_sorted) {
    //    //printContainer(arr2);
    //    printf("time spent(real): %ld us\n", duration_cast<microseconds>(stop_time - start_time).count());
    //}

    //printContainer(beautifulArray2(4));
    //printContainer(beautifulArray2(5));
    //printContainer(beautifulArray(4));
    //printContainer(beautifulArray(5));

    //LRU<int, int> lru(3);
    //vector<int> arr = {7,0,1,2,0,3,0,4};
    //for (int i : arr) {
    //    lru.put(i, i);
    //    lru.print();
    //}
    //lru.put(7, 1);
    //lru.print();
    //lru.put(0, 2);
    //lru.print();
    //lru.put(1, 3);
    //lru.print();
    //lru.put(2, 4);
    //lru.print();
    //cout << lru.get(0) << endl;
    //lru.print();
    //lru.put(3, 5);
    //lru.print();
    //cout << lru.get(0) << endl;
    //lru.print();
    //lru.put(4, 6);
    //lru.print();


    //list<int> l = {1,2,3,4,5};
    //list<int>::iterator it = l.begin();
    //++it;
    //cout << *it << endl;
    //l.insert(it, 100);
    //std::copy(l.begin(), l.end(), ostream_iterator<int>(std::cout, " "));
    //cout << endl;

    //string testcase = "*.**.\n*.***\n*.**.";
    //istringstream iss(testcase);
    //vector<vector<char>> pos;
    //string s;
    //while (getline(iss, s)) {
    //    pos.push_back(vector<char>(s.begin(), s.end()));
    //}
    //cout << GetMaxStaffs(pos) << endl;

    //cout << shortestSubarray({2, -1, 2}, 3) << endl;

    //cout << lengthOfLongestSubstring("abcabcbb") << endl;

    //string S = "abc";
    //vector<int> shifts = {3, 5, 9};
    //cout << shiftingLetters(S, shifts) << endl;

    //cout << std::boolalpha << isNStraightHand2({1,2,3,6,2,3,4,7,8}, 3) << endl;
    //cout << std::boolalpha << isNStraightHand2({1,2,3,4,5}, 4) << endl;

    //cout << longestMountain2({2,1,4,7,3,2,5}) << endl;
    //cout << longestMountain2({2,2,2}) << endl;

    //printContainer(splitIntoFibonacci("123456579"));
    //printContainer(splitIntoFibonacci("11235813"));
    //printContainer(splitIntoFibonacci("112358130"));
    //printContainer(splitIntoFibonacci("0123"));
    //printContainer(splitIntoFibonacci("1101111"));
    //printContainer(splitIntoFibonacci("214748364721474836422147483641"));

    //cout << pushDominoes(".L.R...LR..L..") << endl;
    //cout << pushDominoes("RR.L") << endl;

    //vector<int> difficulty = {2, 4, 6, 8, 10}, profit = {10, 20, 30, 40, 50}, worker = {4, 5, 6, 7};
    //cout << maxProfitAssignment2(difficulty, profit, worker) << endl;

    //cout << minimumLengthEncoding({"time", "me", "bell"}) << endl;

    //printContainer(ambiguousCoordinates("(123)"));
    //printContainer(ambiguousCoordinates("(00011)"));
    //printContainer(ambiguousCoordinates("(0123)"));
    //printContainer(ambiguousCoordinates("(100)"));
    //printContainer(ambiguousCoordinates("(00101)"));

    //string S = "heeellooo";
    //vector<string> words = {"hello", "hi", "helo"};
    //cout << expressiveWords(S, words) << endl;

    //vector<vector<int>> grid = {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    //cout << maxIncreaseKeepingSkyline(grid) << endl;

    //vector<int> A = {3,3,8,9,10}, B = {1,7,4,6,8};
    //cout << minSwap(A, B) << endl;

    //for (const auto &path : allPathsSourceTarget({{1, 2},{3}, {3}, {}}))
    //    printContainer(path);

    //string S = "abcde";
    //vector<string>  words = {"a", "bb", "acd", "ace"};
    //cout << numMatchingSubseq2(S, words) << endl;

    //string S = "cba", T = "abcd";
    //cout << customSortString(S, T) << endl;

    //cout << std::boolalpha << canTransform2("RXXLRXRXL", "XRLXXRRLX") << endl;
    //cout << std::boolalpha << canTransform2("XLXXXXXRXXRXLXXXXXXRXRXXXRXXXLXLLXXLXXXR",
    //                                        "LXRXRXXLXXRXXXRXXXRXLXXXLXXXXXXXXLXXLXRX") << endl;

    //vector<int> A{2,0,1};
    //cout << std::boolalpha << isIdealPermutation2(A) << endl;
    //A = {1,2,0};
    //cout << std::boolalpha << isIdealPermutation2(A) << endl;

    //cout << maxChunksToSorted2({4,3,2,1,0}) << endl;
    //cout << maxChunksToSorted2({1,0,2,3,4}) << endl;

    //cout << reorganizeString("aab") << endl;
    //cout << reorganizeString("aaab") << endl;

    //cout << orderOfLargestPlusSign2(5, {{4, 2}}) << endl;
    //cout << orderOfLargestPlusSign2(2, {}) << endl;
    //cout << orderOfLargestPlusSign2(1, {{0, 0}}) << endl;

    //printContainer(partitionLabels("ababcbacadefegdehijhklij"));

    //cout << std::boolalpha << pyramidTransition2("XYZ", {"XYD", "YZE", "DEA", "FFF"}) << endl;
    //cout << std::boolalpha << pyramidTransition2("XXYX", {"XXX", "XXY", "XYX", "XYY", "YXZ"}) << endl;

    //cout << networkDelayTime({{2, 1, 1},{2, 3, 1}, {3, 4, 1}}, 4, 2) << endl;

    //cout << deleteAndEarn({3, 4, 2}) << endl;
    //cout << deleteAndEarn({2, 2, 3, 3, 3, 4}) << endl;

    //printContainer(dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}));

    //cout << monotoneIncreasingDigits(10) << endl;
    //cout << monotoneIncreasingDigits(1234) << endl;
    //cout << monotoneIncreasingDigits(12332) << endl;
    //cout << monotoneIncreasingDigits(1247776456) << endl;

    //printContainer(asteroidCollision({5, 10, -5}));
    //printContainer(asteroidCollision({8, -8}));
    //printContainer(asteroidCollision({10, 2, -5}));
    //printContainer(asteroidCollision({-1, -2, 1, 2}));

    //MyCalendar cal;
    //cout << std::boolalpha << cal.book(10, 20) << endl; // returns true
    //cout << std::boolalpha << cal.book(15, 25) << endl; // returns false
    //cout << std::boolalpha << cal.book(20, 30) << endl; // returns true

    //vector<string> source{"/*Test program */", 
    //                      "int main()", 
    //                      "{ ", 
    //                      "  // variable declaration ", 
    //                      "int a, b, c;", 
    //                      "/* This is a test", 
    //                      "   multiline  ", 
    //                      "   comment for ", 
    //                      "   testing */", 
    //                      "a = b + c;", 
    //                      "}"};
    //printContainer(removeComments(source));
    //source = {"a/*comment", "line", "more_comment*/b"};
    //printContainer(removeComments(source));
    //vector<string> source = {"a/*/b//*c","blank","d/*/e*//f"};
    //printContainer(removeComments(source));


    //for (const auto &ac : accountsMerge({{"John", "johnsmith@mail.com", "john00@mail.com"},
    //                                    {"John", "johnnybravo@mail.com"},
    //                                    {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
    //                                    {"Mary", "mary@mail.com"}}))
    //    printContainer(ac);

    //cout << maxProfit({1, 3, 2, 8, 4, 9}, 2) << endl;

    //vector<int> nums{10,5,2,6};
    //cout << numSubarrayProductLessThanK(nums, 100) << endl;

    //cout << minimumDeleteSum("delete", "leet") << endl;

    //vector<int> nums = {4, 5, 3, 2, 5, 5, 5, 1, 5, 5, 5, 5, 3, 5, 5, 2};
    //cout << std::boolalpha << canPartitionKSubsets(nums, 13) << endl;

    //vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //    {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    //    {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
    //    {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
    //    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    //cout << maxAreaOfIsland(grid) << endl;

    //printContainer(topKFrequent({"i", "love", "leetcode", "i", "love", "coding"}, 2));
    //printContainer(topKFrequent({"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4));

    //printContainer(findRedundantConnection({{1,2}, {1,3}, {2,3}}));
    //printContainer(findRedundantConnection({{1,2}, {2,3}, {3,4}, {1,4}, {1,5}}));

    //cout << std::boolalpha << checkValidString("()") << endl;
    //cout << std::boolalpha << checkValidString("(*)") << endl;
    //cout << std::boolalpha << checkValidString("(*))") << endl;

    //cout << findNumberOfLIS2({1,3,5,4,7}) << endl;
    //cout << findNumberOfLIS2({5,5,5,5,5}) << endl;

    //cout << maximumSwap(2736) << endl;
    //cout << maximumSwap(9973) << endl;
    //cout << maximumSwap(1993) << endl;

    //printContainer(constructArray(10, 4));

    //vector<int> arr{1,2,3,4,5};
    //printContainer(findClosestElements(arr, 4, 3));
    //printContainer(findClosestElements(arr, 4, -1));

    //cout << minSteps(3) << endl;

    //vector<string> dict = {"cat", "bat", "rat"};
    //string res;
    //cout << (res = replaceWords(dict, "the cattle was rattled by the battery")) << endl;
    //assert(res == "the cat was rat by the bat");

    //cout << solveEquation("x+5-3+x=6+x-2") << endl;
    //cout << solveEquation("x=x") << endl;
    //cout << solveEquation("2x=x") << endl;
    //cout << solveEquation("2x+3x-6x=x+2") << endl;
    //cout << solveEquation("x=x+2") << endl;

    //printContainer(exclusiveTime(1,{"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"}));

    //vector<char> tasks{'A','A','A','B','B','B'};
    //cout << leastInterval(tasks, 2) << endl;

    //vector<int> vec{2,2,3,4};
    //cout << triangleNumber3(vec) << endl;

    //for (const auto &vec : findDuplicate({"root/a 1.txt(abcd) 2.txt(efgh)", 
    //                                     "root/c 3.txt(abcd)", 
    //                                     "root/c/d 4.txt(efgh)", 
    //                                     "root 4.txt(efgh)"}))
    //    printContainer(vec);

    //cout << std::boolalpha << validSquare({0,0}, {1,1}, {1,0}, {0,1}) << endl;

    //cout << fractionAddition("-1/2+1/2") << endl;
    //cout << fractionAddition("-1/2+1/2+1/3") << endl;
    //cout << fractionAddition("1/3-1/2") << endl;
    //cout << fractionAddition("5/3+1/3") << endl;

    //cout << minDistance3("dinitrophenylhydrazine",
    //                    "dimethylhydrazine") << endl;

    //cout << std::boolalpha << checkInclusion2("abc", "bbbca") << endl;
    //cout << std::boolalpha << checkInclusion2("ab", "eidbaooo") << endl;
    //cout << std::boolalpha << checkInclusion2("ab", "eidboaoo") << endl;

    //vector<int> vec = {5,4,0,3,1,6,2};
    //cout << arrayNesting2(vec) << endl;

    //cout << subarraySum2({-92, -63, 75, -86, -58, 22, 31, -16, -66, -67, 420},
    //                    100) << endl;
    //cout << subarraySum2({1, 1, 1}, 2) << endl;

    //cout << nextGreaterElement2(1256729) << endl;

    //cout << leastBricks({{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}}) << endl;

    //cout << optimalDivision({1000,100,10,2}) << endl;

    //for (const auto &row : updateMatrix3({{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}))
    //    printContainer(row);

    //cout << complexNumberMultiply("1+1i", "1+1i") << endl;
    //cout << complexNumberMultiply("1+-1i", "1+-1i") << endl;

    //string url = "https://leetcode-cn.com/problems/complex-number-multiplication/";
    //auto key = std::hash<string>{}(url);
    //ostringstream oss;
    //oss << std::hex << key;
    //cout << oss.str() << endl;

    //vector<vector<char>> b = {{'E', 'E', 'E', 'E', 'E'},
    //                          {'E', 'E', 'M', 'E', 'E'},
    //                          {'E', 'E', 'E', 'E', 'E'},
    //                          {'E', 'E', 'E', 'E', 'E'}};
    //b = updateBoard(b, {3, 0});
    //for (const auto &row : b)
    //    printContainer(row);
    //b = updateBoard(b, {1, 2});
    //for (const auto &row : b)
    //    printContainer(row);

    //for (int i = 1; i <= 15; i++)
    //{
    //    cout << countArrangement(i) << endl;
    //}

    //cout << findMaxLength2({1,0}) << endl;
    //cout << findMaxLength2({1,0,1}) << endl;
    //cout << findMaxLength2({1,0,1,0}) << endl; 
    //cout << findMaxLength2({1,0,1,1,0,0}) << endl;

    //vector<string> d{"ale","apple","monkey","plea"};
    //cout << findLongestWord2("abpcplea", d) << endl;
    //d = {"a", "b", "c"};
    //cout << findLongestWord2("abpcplea", d) << endl;

    //MatrixBitFlip mbf(2, 3);
    //for (int i = 0; i < 6; i++)
    //{
    //    printContainer(mbf.flip());
    //}

    //cout << change(5, {1, 2, 5}) << endl;
    //cout << change(3, {2}) << endl;
    //cout << change(10, {10}) << endl;

    //cout << longestPalindromeSubseq("abcabcabcabc") << endl;
    //cout << longestPalindromeSubseq("bbbab") << endl;
    //cout << longestPalindromeSubseq("cbbd") << endl;

    //TreeNode *root = new TreeNode(2);
    //root->left = new TreeNode(1);
    //root->right = new TreeNode(3);
    //cout << findBottomLeftValue(root);

    //printContainer(findFrequentTreeSum(root));

    //vector<int> vec{3, 2, 3, 5, 4, 2, 1, 2, 4, 3};
    //printContainer(nextGreater(vec));
    //printContainer(nextSmaller(vec));
    //printContainer(previousGreater(vec));
    //printContainer(previousSmaller(vec));

    //printContainer(nextGreaterElements({2, 1, 2, 4, 3}));

    //printContainer(findDiagonalOrder({{1,2,3},
    //                                 {4,5,6},
    //                                 {7,8,9}}));
    //printContainer(findDiagonalOrder({{2,5},
    //                                  {8,4},
    //                                  {0,-1}}));

    //vector<vector<int>> rects = {{1, 1, 5, 5}};
    //printContainer(PickPointInRectList(rects).pick());

    // cout << findPoisonedDuration2({1, 4}, 2) << endl;
    // cout << findPoisonedDuration2({1, 2}, 2) << endl;

    // cout << findTargetSumWays3({9, 28, 50, 9, 34, 48, 2, 50, 38, 10, 5, 16, 44, 5, 48, 21, 38, 17, 21, 49}, 20) << endl;

    // for (const auto &vec : findSubsequences({4, 6, 7, 7}))
    //     printContainer(vec);

    // cout << std::boolalpha << PredictTheWinner2({1, 5, 2}) << endl;
    // cout << std::boolalpha << PredictTheWinner2({1, 5, 233, 7}) << endl;

    // cout << magicalString(6) << endl;

    // cout << totalHammingDistance({4, 14, 2}) << endl;

    // vector<int> vec{1, 1, 2, 2, 2};
    // cout << std::boolalpha << makesquare2(vec) << endl;
    // vec = {3, 3, 3, 3, 4};
    // cout << std::boolalpha << makesquare2(vec) << endl;
    // vec = {5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3};
    // cout << std::boolalpha << makesquare2(vec) << endl;

    // int cnt[11]{0};
    // int total = 1000000;
    // for (int i = 0; i < total; i++)
    //     ++cnt[rand10()];
    // for (int i = 1; i <= 10; i++)
    //     cout << i << ": " << cnt[i] << endl;

    // cout << validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:") << endl;
    // cout << validIPAddress("172.16.254.1") << endl;
    // cout << validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;
    // cout << validIPAddress("256.256.256.256") << endl;

    // cout << findSubstringInWraproundString("a") << endl;
    // cout << findSubstringInWraproundString("cac") << endl;
    // cout << findSubstringInWraproundString("zab") << endl;

    // vector<int> nums{1, 2};
    // cout << minMoves2(nums) << endl;

    // cout << std::boolalpha << circularArrayLoop({1, 1, 2}) << endl;
    // cout << std::boolalpha << circularArrayLoop({-2, -3, -9}) << endl;

    // cout << std::boolalpha << find132pattern({1, 2, 3, 4}) << endl;
    // cout << std::boolalpha << find132pattern({3, 1, 4, 2}) << endl;
    // cout << std::boolalpha << find132pattern({-1, 3, 2, 0}) << endl;

    // vector<int> A{1, 2}, B{-2, -1}, C{-1, 2}, D{0, 2};
    // cout << fourSumCount2(A, B, C, D) << endl;

    // vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    // cout << findMinArrowShots(points) << endl;

    // cout << frequencySort("tree") << endl;

    // vector<int> vec{4, 3, 2, 7, 8, 2, 3, 1};
    // printContainer(findDuplicates2(vec));

    // auto root = construct({{1, 1, 1, 1, 0, 0, 0, 0},
    //                        {1, 1, 1, 1, 0, 0, 0, 0},
    //                        {1, 1, 1, 1, 1, 1, 1, 1},
    //                        {1, 1, 1, 1, 1, 1, 1, 1},
    //                        {1, 1, 1, 1, 0, 0, 0, 0},
    //                        {1, 1, 1, 1, 0, 0, 0, 0},
    //                        {1, 1, 1, 1, 0, 0, 0, 0},
    //                        {1, 1, 1, 1, 0, 0, 0, 0}});

    // cout << originalDigits2("owoztneoer") << endl;
    // cout << originalDigits2("fviefuro") << endl;

    // FindTwoNumsMaximumXORInArray solution;
    // cout << solution.findMaximumXOR2({3, 10, 5, 25, 2, 8}) << endl;

    // for (const auto &pair : pacificAtlantic({{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}}))
    //     printContainer(pair);

    // vector<int> v1{1, 1, 1, 1}, v2{1, 2, 3, 4, 5, 6, 7};
    // cout << std::boolalpha << canPartition3(v1) << endl;
    // cout << std::boolalpha << canPartition3(v2) << endl;

    // cout << numberOfArithmeticSlices2({1, 2, 3, 4}) << endl;

    // cout << removeKdigits("1432219", 3) << endl;
    // cout << removeKdigits("10200", 1) << endl;
    // cout << removeKdigits("10", 2) << endl;

    // printContainer(calcEquation2({{"a", "b"}, {"b", "c"}}, {2.0, 3.0}, {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}}));

    // cout << integerReplacement2(8) << endl;
    // cout << integerReplacement2(7) << endl;

    // vector<int> A{4, 3, 2, 6};
    // cout << maxRotateFunction2(A) << endl;

    // cout << decodeString("3[a]2[bc]") << endl;
    // cout << decodeString("3[a2[c]]") << endl;
    // cout << decodeString("2[abc]3[cd]ef") << endl;

    // cout << std::boolalpha << validUtf8({235, 140, 4}) << endl;

    // cout << lastRemaining(9) << endl;

    // printContainer(lexicalOrder2(13));

    // std::srand(std::time(nullptr));
    // cout << "build list" << endl;
    // ListNode *head = new ListNode(-1), *p = head;
    // constexpr int N = 10000;
    // constexpr int K = 100;
    // for (int i = 0; i < N; i++)
    // {
    //     ListNode *t = new ListNode(i);
    //     p->next = t;
    //     p = p->next;
    // }
    // p = head;
    // head = head->next;
    // delete p;
    // map<int, int> cnt;
    // cout << "start iteration" << endl;
    // // printContainer(reservoirSampling(head, K));
    // for (int i = 0; i < N; i++)
    // {
    //     for (int val : reservoirSampling(head, K))
    //         ++cnt[val];
    // }
    // for (const auto &item : cnt)
    // {
    //     cout << item.first << ": " << item.second * 1.0 / N << endl;
    // }
    // cout << "delete list" << endl;
    // ListNode *d = head;
    // while (head != nullptr)
    // {
    //     d = head;
    //     head = head->next;
    //     delete d;
    // }

    // // 初始化一个空的集合。
    // RandomizedSet randomSet;
    // // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    // randomSet.insert(1);
    // // 返回 false ，表示集合中不存在 2 。
    // randomSet.remove(2);
    // // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    // randomSet.insert(2);
    // // getRandom 应随机返回 1 或 2 。
    // randomSet.getRandom();
    // // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    // randomSet.remove(1);
    // // 2 已在集合中，所以返回 false 。
    // randomSet.insert(2);
    // // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
    // randomSet.getRandom();

    // vector<int> vec{1, 2, 3, 3, 3, 4, 5, 6};
    // cout << lower_bound(vec.begin(), vec.end(), 3) - vec.begin() << endl;
    // cout << upper_bound(vec.begin(), vec.end(), 3) - vec.begin() << endl;
    // auto iters = equal_range(vec.begin(), vec.end(), 3);
    // cout << iters.first - vec.begin() << endl;
    // cout << iters.second - vec.begin() << endl;

    // vector<vector<int>> m{{1, 5, 9},
    //                       {10, 11, 13},
    //                       {12, 13, 15}};
    // cout << kthSmallest(m, 8) << endl;

    // vector<int> nums{1, 2, 3};
    // cout << combinationSum4_2(nums, 4) << endl;

    // cout << wiggleMaxLength({0, 0}) << endl;

    // cout << getMoneyAmount(10) << endl;

    // vector<int> b{1, 2, 3};
    // cout << superPow(3, b) << endl;

    // vector<int> nums{1, 2, 4, 8};
    // printContainer(largestDivisibleSubset(nums));

    // cout << countNumbersWithUniqueDigits(2) << endl;
    // cout << countNumbersWithUniqueDigits(9) << endl;
    // cout << countNumbersWithUniqueDigits(10) << endl;
    // cout << countNumbersWithUniqueDigits(11) << endl;

    // printContainer(topKFrequent({1, 1, 1, 2, 2, 3}, 2));

    // cout << integerBreak(5) << endl;

    // printContainer(countBits(8));

    //printContainer(findItinerary({ {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"} }));

    //cout << knapsack({ 2,2,6,5,4 }, { 6,3,5,4,6 }, 10) << endl;

    //string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    //cout << isValidSerialization3(s) << endl;
    //cout << isValidSerialization("91,13,14,#,#,10") << endl;
    //cout << isValidSerialization("1,#") << endl;
    //cout << isValidSerialization("9,#,#,1") << endl;

    //vector<int> vec{ 1,2,5 };
    //cout << coinChange2(vec, 11) << endl;
    //vector<int> vec1{ 2 };
    //cout << coinChange2(vec1, 3) << endl;

    //vector<string> vec{ "abcw","baz","foo","bar","xtfn","abcdef" };
    //cout << maxProduct(vec) << endl;
    //vector<string> vec1{ "a","ab","abc","d","cd","bcd","abcd" };
    //cout << maxProduct(vec1) << endl;
    //vector<string> vec2{ "a","aa","aaa","aaaa" };
    //cout << maxProduct(vec2) << endl;

    //cout << nthSuperUglyNumber2(12, { 2,7,13,19 }) << endl;

    //cout << maxProfit({ 1,2,3,0,2 }) << endl;

    //cout << isAdditiveNumber("1203") << endl;
    //cout << isAdditiveNumber("112358") << endl;
    //cout << isAdditiveNumber("199100199") << endl;

    //cout << lengthOfLIS2({ 1,3,6,7,9,4,10,5,6 }) << endl;

    //cout << getHint("1807", "7810") << endl;
    //cout << getHint("1123", "0111") << endl;

    //cout << findDuplicate({ 1,3,4,2,2 }) << endl;

    //printContainer(productExceptSelf({ 1,2,3,4 }));

    //vector<TreeNode *> nodes(9, nullptr);
    //for (int i = 0; i < 9; i++)
    //{
    //    nodes[i] = new TreeNode(i);
    //}
    //nodes[3]->left = nodes[5];
    //nodes[3]->right = nodes[1];
    //nodes[5]->left = nodes[6];
    //nodes[5]->right = nodes[2];
    //nodes[2]->left = nodes[7];
    //nodes[2]->right = nodes[4];
    //nodes[1]->left = nodes[0];
    //nodes[1]->right = nodes[8];
    //TreeExample tree(nodes[3]);
    //cout << lowestCommonAncestor(tree.getTree(), nodes[5], nodes[1])->val << endl;
    //cout << lowestCommonAncestor(tree.getTree(), nodes[7], nodes[4])->val << endl;
    //cout << lowestCommonAncestor(tree.getTree(), nodes[5], nodes[4])->val << endl;

    //printContainer(summaryRanges({ 0,1,2,4,5,7 }));
    //printContainer(summaryRanges({ 0,2,3,4,6,8,9 }));

    //cout << calculate("3+2*2") << endl;
    //cout << calculate(" 3/2 ") << endl;
    //cout << calculate(" 3+5 / 2 ") << endl;
    //cout << calculate("42") << endl;

    //for (const auto &vec : combinationSum3(3, 9))
    //{
    //    printContainer(vec);
    //}

    //cout << rob({ 2,3,2 }) << endl;

    //WordDictionary wd;
    //wd.addWord("at");
    //wd.addWord("and");
    //wd.addWord("an");
    //wd.addWord("add");
    //cout << wd.search("a") << endl;
    //cout << wd.search(".at") << endl;
    //wd.addWord("bat");
    //cout << wd.search(".at") << endl;
    //cout << wd.search("an.") << endl;
    //cout << wd.search("a.d.") << endl;
    //cout << wd.search("b.") << endl;
    //cout << wd.search("a.d") << endl;
    //cout << wd.search(".") << endl;

    //cout << minSubArrayLen(7, { 2,3,1,2,4,3 }) << endl;

    //Trie trie;
    //trie.insert("apple");
    //cout << trie.search("apple") << endl;   // 返回 true
    //cout << trie.search("app") << endl;     // 返回 false
    //cout << trie.startsWith("app") << endl; // 返回 true
    //trie.insert("app");
    //cout << trie.search("app") << endl;     // 返回 true

    //printContainer(findRepeatedDnaSequences1("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));

    //cout << findPeakElement({ 0,1,3,3,3,2,0,0,0 }) << endl;

    //auto head = buildList({ 4,2,1,3 });
    //printList(sortList(head));

    //auto head = buildList({ 4,2,1,3 });
    //printList(insertionSortList(head));

    //string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    //vector<string> wordDict{ "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    //cout << wordBreak(s, wordDict) << endl;

    //vector<int> gas{ 1,2,3,4,5 }, cost{ 3,4,5,1,2 };
    //cout << canCompleteCircuit(gas, cost) << endl;

    //vector<int> vec{ -1,0,1,2 };
    //auto head = buildList(vec);
    //printList(head);
    //sortedListToBST(head);

    //vector<int> inorder{ 9,3,15,20,7 }, postorder{ 9,15,7,20,3 };
    //auto proot = buildTree(inorder, postorder);
    //middleOrder(proot);
    //cout << endl;
    //postOrder(proot);

    //cout << numTrees(3) << endl;

    //for (auto root : generateTrees(4))
    //{
    //    preOrder(root);
    //    cout << endl;
    //}

    //printContainer(restoreIpAddresses("25525511135"));
    //constexpr int N = 3;
    //for (auto i : grayCode(N))
    //{
    //    cout << bitset<N>(i) << endl;
    //}

    //vector<int> vec = { 1,2,3 };
    //for (const auto &v : subsets(vec))
    //    printContainer(v);

    //for (const auto &vec : combine(4, 2))
    //        printContainer(vec);

    //vector<int> colors = { 2,0,2,1,1,0 };
    //sortColors(colors);
    //printContainer(colors);

    //vector<vector<int> > m = { {1,1} };
    //cout << searchMatrix(m, 0) << endl;

    //cout << simplifyPath("/home/") << endl;
    //cout << simplifyPath("/../") << endl;
    //cout << simplifyPath("/home//foo/") << endl;
    //cout << simplifyPath("/a/./b/../../c/") << endl;
    //cout << simplifyPath("/a/../../b/../c//.//") << endl;
    //cout << simplifyPath("/a//b////c/d//././/..") << endl;

    //string s = "Hello World";
    //char * ps = const_cast<char *>(s.c_str());
    //cout << ++ps << endl;

    //TreeExample treeExample;
    ////preOrder(treeExample.getTree());
    //char *s = Serialize(treeExample.getTree());
    //cout << str_temp << endl;
    //TreeNode *pRoot = Deserialize(s);
    //preOrder(pRoot);

    //printContainer(multiply({ 1,2,3,4,5 }));

    //cout << sizeof(int) << " " << sizeof(long) << " " << sizeof(long long) << endl;

    //cout << Add(124, 345) << endl;

    //cout << LastRemaining_Solution(5, 3) << endl;

    //cout << ReverseSentence("I am a student.") << endl;

    //cout << GetNumberOfK({ 1,2,3,3,3,3,4,5 }, 3) << endl;

    //cout << InversePairs({ 1,2,3,4,5,6,7,0 }) << endl;

    //cout << PrintMinNumber({ 3,32,321 }) << endl;

    //cout << NumberOf1Between1AndN_Solution_2(21345) << endl;

    //vector<int> vec{ 4,5,1,6,2,7,3,8 };
    //printContainer(GetLeastNumbers_Solution_2(vec, 4));

    //string s = "abc";
    //printContainer(Permutation(s));

    //StackWithMin<int> st;
    //st.push(2);
    //st.push(1);
    //st.push(5);
    //cout << st.min() << " " << st.top() << endl;
    //st.pop();
    //cout << st.min() << " " << st.top() << endl;
    //st.pop();
    //cout << st.min() << " " << st.top() << endl;

    //vector<vector<int> > m{ {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
    //printContainer(printMatrix(m));

    //vector<int> vec{ 3,4,5,1,2 };
    //cout << minNumberInRotateArray(vec) << endl;
    //vec = { 1,0,1,1,1 };
    //cout << minNumberInRotateArray(vec) << endl;
    //vec = { 1,1,1,0,1 };
    //cout << minNumberInRotateArray(vec) << endl;

    //try
    //{
    //    StackBy2Queue<int> stack;
    //    stack.push(1);
    //    stack.push(2);
    //    stack.push(3);
    //    cout << stack.pop() << " ";
    //    cout << stack.pop() << " ";
    //    stack.push(4);
    //    stack.push(5);
    //    cout << stack.pop() << " ";
    //    cout << stack.pop() << " ";
    //    cout << stack.pop() << " ";
    //}
    //catch (const std::exception &e)
    //{
    //    cout << e.what() << endl;
    //}

    //TreeNode* root = reConstructBinaryTree({ 1,2,4,7,3,5,6,8 }, { 4,7,2,1,5,3,8,6 });
    //preOrder(root);
    //cout << endl;
    //MiddleOrder(root);
    //cout << endl;

    //char str[100] = "hello world hello c++ hello c.";
    //cout << str << endl;
    //replaceSpace(str, 100);
    //cout << str << endl;

    //vector<vector<int>> array{ {1,2,3,4}, {5,6,7,8},{9,10,11,12} };
    //cout << Find(0, array) << endl;

    //cout << uniquePaths(7, 3) << endl;

    //std::default_random_engine e;
    //std::uniform_int_distribution<int> uid(1, 10);
    //auto ge = [&](size_t size)
    //{
    //std::vector<int> vec;
    //for (size_t i = 0; i < size; i++)
    //{
    //vec.push_back(uid(e));
    //}
    //return vec;
    //};
    //auto pr = [](const std::vector<int> &vec)
    //{
    //for (const auto &item : vec)
    //std::cout << item << " ";
    //std::cout << endl;
    //};
    //std::vector<int> nums1 = ge(5), nums2 = ge(6);
    //pr(nums1);
    //pr(nums2);
    //std::sort(nums1.begin(), nums1.end());
    //std::sort(nums2.begin(), nums2.end());
    //std::vector<int> res;
    //std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(res));
    //pr(res);

    //string s("bdabcbabc");
    //cout << longestPalindrome(s) << endl;
    //cout << longestPalindromeDP(s) << endl;

    // cout << convert("ABCD", 2) << endl;

    //cout << my_atoi("-2147483648") << endl;
    //cout << my_atoi("-2147483649") << endl;
    //cout << my_atoi("-21474836471") << endl;
    //cout << my_atoi("-21474836481") << endl;
    //cout << my_atoi("-520") << endl;
    //cout << my_atoi("0") << endl;
    //cout << my_atoi("+0") << endl;
    //cout << my_atoi("-0") << endl;
    //cout << my_atoi("2147483647") << endl;
    //cout << my_atoi("2147483648") << endl;
    //cout << my_atoi("21474836461") << endl;
    //cout << my_atoi("21474836471") << endl;
    //cout << my_atoi("520") << endl;

    //cout << isMatchRE("aa", "a") << endl;
    //cout << isMatchRE("aa", "a*") << endl;
    //cout << isMatchRE("ab", ".*") << endl;
    //cout << isMatchRE("aab", "c*a*b") << endl;
    //cout << isMatchRE("aab", "c*a*b*") << endl;
    //cout << isMatchRE("mississippi", "mis*is*p*.") << endl;
    //cout << isMatchRE("mississippi", "mis*is*ip*.") << endl;
    //cout << isMatchRE("aaa", "aaaa") << endl;

    //cout << isMatchRecursive("aa", "a") << endl;
    //cout << isMatchRecursive("aa", "a*") << endl;
    //cout << isMatchRecursive("ab", ".*") << endl;
    //cout << isMatchRecursive("aab", "c*a*b") << endl;
    //cout << isMatchRecursive("aab", "c*a*b*") << endl;
    //cout << isMatchRecursive("mississippi", "mis*is*p*.") << endl;
    //cout << isMatchRecursive("mississippi", "mis*is*ip*.") << endl;
    //cout << isMatchRecursive("aaa", "aaaa") << endl;

    //cout << isMatchRecursiveConcise("aa", "a") << endl;
    //cout << isMatchRecursiveConcise("aa", "a*") << endl;
    //cout << isMatchRecursiveConcise("ab", ".*") << endl;
    //cout << isMatchRecursiveConcise("aab", "c*a*b") << endl;
    //cout << isMatchRecursiveConcise("aab", "c*a*b*") << endl;
    //cout << isMatchRecursiveConcise("mississippi", "mis*is*p*.") << endl;
    //cout << isMatchRecursiveConcise("mississippi", "mis*is*ip*.") << endl;
    //cout << isMatchRecursiveConcise("aaa", "aaaa") << endl;

    //cout << isMatchDP("aa", "a") << endl;
    //cout << isMatchDP("aa", "a*") << endl;
    //cout << isMatchDP("ab", ".*") << endl;
    //cout << isMatchDP("aab", "c*a*b") << endl;
    //cout << isMatchDP("aab", "c*a*b*") << endl;
    //cout << isMatchDP("mississippi", "mis*is*p*.") << endl;
    //cout << isMatchDP("mississippi", "mis*is*ip*.") << endl;
    //cout << isMatchDP("aaa", "aaaa") << endl;

    //cout << romanToInt("III") << endl;
    //cout << romanToInt("IV") << endl;
    //cout << romanToInt("IX") << endl;
    //cout << romanToInt("LVIII") << endl;
    //cout << romanToInt("MCMXCIV") << endl;

    //auto res = threeSumBetter({ -1,0,1,2,-1,-4 });
    //for (auto &item : res)
    //{
    //    for (auto &i : item)
    //        cout << i << " ";
    //    cout << endl;
    //}

    //cout << threeSumClosest({ -1, 2, 1, -4 }, 1) << endl;
    //cout << threeSumClosest({ -3,-2,-5,3,-4 }, -1) << endl;

    //cout << intToRoman(1) << endl;
    //cout << intToRoman(4) << endl;
    //cout << intToRoman(5) << endl;
    //cout << intToRoman(9) << endl;
    //cout << intToRoman(10) << endl;
    //cout << intToRoman(40) << endl;
    //cout << intToRoman(50) << endl;
    //cout << intToRoman(90) << endl;
    //cout << intToRoman(100) << endl;
    //cout << intToRoman(400) << endl;
    //cout << intToRoman(500) << endl;
    //cout << intToRoman(900) << endl;
    //cout << intToRoman(1000) << endl;
    //cout << intToRoman(58) << endl;
    //cout << intToRoman(1994) << endl;

    //string s = "abc";
    //sort(s.begin(), s.end());
    //do
    //{
    //    cout << s << endl;
    //} while (next_permutation(s.begin(), s.end()));

    //for (auto &s : letterCombinations("23"))
    //{
    //    cout << s << endl;
    //}

    //vector<int> nums = { 1, 0, -1, 0, -2, 2 };
    //vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    //auto res = fourSum(nums, -1);
    //for (auto &i : res)
    //{
    //    for (auto &item : i)
    //        cout << item << " ";
    //    cout << endl;
    //}

    //for (auto &s : generateParenthesis(3))
    //{
    //    cout << s << endl;
    //}

    //cout << divide(10, 3) << endl;
    //cout << divide(7, -3) << endl;

    //vector<string> res;
    //vector<string> words = { "foo", "bar" };
    //findSubstringDFS(words, "", res);
    //res = findSubstringDFS(words);
    //for (auto &s : res)
    //{
    //    cout << s << endl;
    //}
    //for (auto &i : findSubstring("barfoothefoobarman", words))
    //{
    //}
    //for (auto &i : findSubstring("foobarfoobar", words))
    //{
    //    cout << i << " ";
    //}
    //cout << endl;
    //vector<string> words = { "foo", "bar" };
    //printContainer(findSubstringBetter("barfoothefoobarman", words));
    //printContainer(findSubstringLinear("barfoothefoobarman", words));
    //words = { "word","student" };
    //printContainer(findSubstringBetter("wordgoodstudentgoodword", words));
    //printContainer(findSubstringLinear("wordgoodstudentgoodword", words));

    //string s = ")()())";
    //cout << longestValidParentheses(s) << endl;
    //cout << longestValidParenthesesDP(s) << endl;

    //vector<int> nums({ 1, 2, 3 });
    //printContainer(searchRange(nums, 1));

    //vector<int> c{ 8,6,4,12,5,7,3,11 };
    //for (const auto &i : combinationSum(c, 28))
    //{
    //    printContainer(i);
    //}

    //cout << multiply("999", "999") << endl;

    //cout << myPow(2.0, 8) << endl;
    //cout << myPowBitwise(2.0, 8) << endl;

    //vector<int> nums = { 3, 4, -1, 1 };
    //cout << firstMissingPositive(nums) << endl;
    //cout << firstMissingPositiveFaster(nums) << endl;

    //vector<int> in{ 0,1,0,2,1,0,1,3,2,1,2,1 };
    //cout << trap(in) << endl;

    //vector<int> in{ 2,3,1,1,4 };
    //cout << jump(in) << endl;
    //auto res = solveNQueens(6);
    //for (const auto &item : res)
    //{
    //    for (const auto &s : item)
    //        cout << s << endl;
    //    cout << endl << endl;
    //}

    //default_random_engine e(time(nullptr));
    //uniform_int_distribution<int> u(1,10);
    //vector<int> input;
    //size_t n = 30;
    //for (size_t i = 0; i < n; i++)
    //{
    //    input.push_back(u(e));
    //}
    //cout << "input: ";
    //printContainer(input);
    //pair<int, int> res = minmax(input, 0, input.size() - 1);
    //cout << "min: " << res.first << endl;
    //cout << "max: " << res.second << endl;

    //vector<int> seqs = { 1,2,3 };
    //vector<vector<int>> res = heapPermutation(seqs);
    //for (const auto &seq : res)
    //    printContainer(seq);
    //seqs = { 1,2,3,4 };
    //res = heapPermutation(seqs);
    //for (const auto &seq : res)
    //    printContainer(seq);

    //vector<int> a{ 2,4,7,9,1,2,4,5,9,7,3 };
    //printContainer(a);
    ////selectSort(a);
    ////mergesort(a, 0, a.size() - 1);
    //quicksort(a, 0, a.size() - 1);
    //printContainer(a);

    //system("pause");

    return 0;
}