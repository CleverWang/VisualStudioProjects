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
		if (nowchar <= '9'&&nowchar >= '0') // ����ֱ�����
			output += nowchar;
		else if (st.empty() && isOP(nowchar)) // ջΪ�գ�������ֱ�ӽ�ջ
			st.push(nowchar);
		else if (nowchar == '(' || nowchar == '*' || nowchar == '/') // ����*��/���ȼ���ߣ�ֱ�ӽ�ջ
			st.push(nowchar);
		else if (nowchar == ')') { // �������������е�ȫ�����
			char temp = st.top();
			while (temp != '(') {
				st.pop();
				output += temp;
				temp = st.top();
			}
			st.pop();
		}
		else if (nowchar == '+' || nowchar == '-') { // ����+��-�����ȼ���ͣ�������������ȼ��ģ����ˣ��⣬�ٽ�+��-��ջ
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
	for (int i = 0, size = st.size();i < size;i++) { // ���ջ��ʣ��Ԫ��
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