#include "headers.h"

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
//     res.push_back(new TreeNode(1)); // 初始只有一棵树，并且只有一个节点1

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
//     a.中间集合较小，接下来是中间集合到结束结合的转换
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

int main(int argc, char **argv)
{
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

    system("pause");

    return 0;
}