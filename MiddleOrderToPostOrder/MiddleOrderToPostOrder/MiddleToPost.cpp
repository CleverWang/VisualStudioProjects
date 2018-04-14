#include<iostream>	
#include<string>
#include<stack>
using namespace std;

bool isOP(char c) {
	if (c == '+' || c == '*' || c == '-' || c == '/')
		return true;
	else
		return false;
}

string middletopost(string s) {
	stack<int> st;
	char nowchar;
	string output;
	for (int i = 0, length = s.length(); i < length; i++)
	{
		nowchar = s[i];
		if (nowchar <= '9'&&nowchar >= '0') // 数字直接输出
			output += nowchar;
		else if (st.empty() && isOP(nowchar)) // 栈为空，操作符直接进栈
			st.push(nowchar);
		else if (nowchar == '(' || nowchar == '*' || nowchar == '/') // （，*，/优先级最高，直接进栈
			st.push(nowchar);
		else if (nowchar == ')') { // 遇到）将（）中的全部输出
			char temp = st.top();
			while (temp != '(') {
				st.pop();
				output += temp;
				temp = st.top();
			}
			st.pop();
		}
		else if (nowchar == '+' || nowchar == '-') { // 遇到+、-，优先级最低，连续输出高优先级的，除了（外，再将+、-入栈
			if (st.top() != '(') {
				while (!st.empty() && st.top() != '(') {
					output += st.top();
					st.pop();
				}
				st.push(nowchar);
			}
			else
				st.push(nowchar);
		}
	}
	//cout << output << " " << st.size() << endl;
	for (int i = 0, size = st.size();i < size;i++) { // 输出栈中剩余元素
		output += st.top();
		st.pop();
	}
	return output;
}

int main() {
	string input;
	cin >> input;
	cout << middletopost(input);
}