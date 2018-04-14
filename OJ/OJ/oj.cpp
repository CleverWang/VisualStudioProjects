//#include<iostream>
//using namespace std;
//
//int main() {
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int n;
//	long long a, b;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a >> b;
//		cout << "Case " << i + 1 << ":" << endl;
//		cout << a << " + " << b << " = " << a + b << endl << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<stdio.h>
//int main()//最大字段和，输出和以及起始位置
//{
//	int i, ca = 1, t, s, e, n, x, now, before, max;
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d", &n);
//		for (i = 1;i <= n;i++)
//		{
//			scanf("%d", &now);
//			if (i == 1)//初始化 
//			{
//				max = before = now;//max保留之前算出来的最大和，before存储目前在读入数据前保留的和，now保留读入数据  
//				x = s = e = 1;//x用来暂时存储before保留的和的起始位置，当before>max时将赋在s位置，s，e保留最大和的start和end位置 
//			}
//			else {
//				if (now > now + before)//如果之前存储的和加上现在的数据比现在的数据小，就把存储的和换成现在的数据，反之就说明数据在递增，可以直接加上 
//				{
//					before = now;
//					x = i;//预存的位置要重置 
//				}
//				else before += now;
//			}
//			if (before > max)//跟之前算出来的最大和进行比较，如果大于，位置和数据就要重置 
//				max = before, s = x, e = i;
//		}
//		printf("Case %d:\n%d %d %d\n", ca++, max, s, e);
//		if (t)
//			printf("\n");
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	while (n != 0) {
//		string t;
//		map<string, int> color;
//		map<string, int>::iterator it;
//		for (int i = 0;i < n;i++) {
//			cin >> t;
//			it = color.find(t);
//			if (it == color.end())
//				color[t] = 1;
//			else
//				color[t] = color[t] + 1;
//		}
//		int max = 0;
//		string max_s;
//		for (it = color.begin();it != color.end();++it) {
//			if (it->second > max) {
//				max = it->second;
//				max_s = it->first;
//			}
//		}
//		cout << max_s << endl;
//		cin >> n;
//	}
//	return 0;
//}

//#include <stdio.h>
//int s[100];
//int main()
//{
//	int a, b, n, i;
//	while (scanf("%d%d%d", &a, &b, &n), a || b || n)
//	{
//		int i;
//		s[1] = s[2] = 1;
//		for (i = 3; i < 100;i++)
//		{
//			s[i] = (a*s[i - 1] + b*s[i - 2]) % 7;
//			if (s[i] == 1 && s[i - 1] == 1)
//				break;
//		}
//		n = n % (i - 2);
//		if (n == 0)
//			printf("%d\n", s[i - 2]);
//		else
//			printf("%d\n", s[n]);
//	}
//	return 0;
//}

//#include<iostream>  
//#include<iomanip>  
//using namespace std;
//
////const double w_h=1.0/120,w_m=1./10,w_s=6.0;  //角速度  
//const double hm = 11.0 / 120, hs = 719.0 / 120, sm = 59.0 / 10;    //相对角速度  
//const double T_hm = 43200.0 / 11, T_hs = 43200.0 / 719, T_sm = 3600.0 / 59;   //相对周期  
//
//inline double min(double a, double b, double c)
//{
//	double temp = (a > b) ? b : a;
//
//	return (c > temp) ? temp : c;
//}
//
//inline double max(double a, double b, double c)
//{
//	double temp = (a > b) ? a : b;
//
//	return (c > temp) ? c : temp;
//}
//
//int main()
//{
//	double degree;
//	double x[3], y[3];
//	double m[3], n[3];
//	double end, begin, sum;
//
//	while (cin >> degree, degree != -1)
//	{
//		x[0] = degree / hm;
//		x[1] = degree / hs;
//		x[2] = degree / sm;
//
//		y[0] = (360 - degree) / hm;
//		y[1] = (360 - degree) / hs;
//		y[2] = (360 - degree) / sm;
//
//		sum = 0.0;
//		for (m[0] = x[0], n[0] = y[0];n[0] <= 43200.000001;m[0] += T_hm, n[0] += T_hm)
//		{
//			for (m[1] = x[1], n[1] = y[1];n[1] <= 43200.000001;m[1] += T_hs, n[1] += T_hs)
//			{
//				if (n[0] < m[1])
//					break;
//				if (m[0] > n[1])
//					continue;
//
//				for (m[2] = x[2], n[2] = y[2];n[2] <= 43200.000001;m[2] += T_sm, n[2] += T_sm)
//				{
//					if (n[0] < m[2] || n[1] < m[2])
//						break;
//					if (m[0] > n[2] || m[1] > n[2])
//						continue;
//
//					begin = max(m[0], m[1], m[2]);
//					end = min(n[0], n[1], n[2]);
//
//					if (end > begin)
//						sum += end - begin;
//				}
//			}
//		}
//
//		cout << setiosflags(ios::fixed) << setprecision(3) << sum*100.0 / 43200 << endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//struct point {
//	double x;
//	double y;
//};
//point a[100001];
//
//int main()
//{
//	int n;
//	while (cin >> n, n) {
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i].x >> a[i].y;
//		}
//		double result = DBL_MAX;
//		double temp = 0;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = i + 1; j < n; j++)
//			{
//				temp = sqrt((a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y));
//				if (temp < result)
//					result = temp;
//			}
//		}
//		cout << setiosflags(ios::fixed) << setprecision(2) << (result / 2) << endl;
//	}
//}

//#include<iostream>	
//#include<stdio.h>
//using namespace std;
//
//int main()
//{
//	cout << "n e\n- -----------\n";
//	double result = 0, jiecheng = 1;
//	for (int i = 0; i < 10; i++)
//	{
//		if (i == 0)
//			jiecheng = 1;
//		else
//			jiecheng *= i;
//		result += (1 / jiecheng);
//		cout << i << " ";
//		if (i < 3)
//			cout << result << endl;
//		else
//			printf("%.9f\n", result);
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//	string s = "";
//	while (cin >> s) {
//		int input = 0;
//		if (s == "0")
//			break;
//		else
//			for (int i = 0, length = s.length(); i < length; i++) {
//				input += (s[i] - '0');
//			}
//		int t, sum;
//		while (1) {
//			t = input / 10;
//			sum = input % 10;
//			while (t != 0) {
//				sum += t % 10;
//				t = t / 10;
//			}
//			if (sum > 9)
//				input = sum;
//			else
//				break;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//int main() {
//	char a[] = "12345";
//	int i;
//	sscanf(a, "%d", &i);
//	//printf("%d\n",i);
//	cout << i << endl;
//	char b[] = "123.45";
//	double f;
//	sscanf(b, "%lf", &f);
//	cout << f << endl;
//	char c[100], d[100];
//	sprintf(c, "%d", i);
//	sprintf(d, "%lf", f);
//	cout << c << endl << d << endl;
//
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
////#include<stdio.h>
//using namespace std;
//
//int prims[15] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
//int n;
//
//bool isprim(int a, int b) {
//	int sum = a + b;
//	int i;
//	for (i = 0; i < 15; i++)
//	{
//		if (sum == prims[i])
//			return true;
//	}
//	return false;
//}
//
//void swap(int &a, int &b) {
//	int temp=a;
//	a = b;
//	b = temp;
//}
//
//void permutation(int a[],int k, int m) {
//	if (k == m) {
//		int i;
//		for (i = 0; i < n; i++)
//		{
//			if (isprim(a[i], a[(i + 1) % n]))
//				continue;
//			else
//				break;
//		}
//		if (i == n) {
//			for (int i = 0; i < n - 1; i++)
//			{
//				cout << a[i] << " ";
//			}
//			cout << a[n - 1] << endl;
//		}
//		return;
//	}
//	for (int i = k; i <= m; i++)
//	{
//		swap(a[k], a[i]);
//		permutation(a, k + 1, m);
//		swap(a[k], a[i]);
//	}
//}
//
//int main() {
//	int a[20];
//	int count = 1;
//	while (cin>>n) {
//		cout << "Case " << count << ":\n";
//		count++;
//		for (int i = 0; i < n; i++)
//		{
//			a[i] = i + 1;
//		}
//		permutation(a, 1, n-1);
//		/*do {
//			int i;
//			for (i = 0; i < n; i++)
//			{
//				if (isprim(a[i], a[(i + 1)%n]))
//					continue;
//				else
//					break;
//			}
//			if (i == n) {
//				for (int i = 0; i < n-1; i++)
//				{
//					cout << a[i] << " ";
//				}
//				cout << a[n - 1] << endl;
//			}
//		} while (next_permutation(a+1, a + n ));*/
//		cout << endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void swap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void permutation(int *a, int n, int start, int end) {
//	if (start == end) {
//		for (int i = 0; i < n; i++)
//		{
//			cout << a[i] << " ";
//		}
//		cout << endl;
//		return;
//	}
//	for (int i = start; i <= end; i++)
//	{
//		swap(a[start], a[i]);
//		permutation(a, n, start + 1, end);
//		swap(a[start], a[i]);
//	}
//}
//
//int main() {
//	int a[] = { 1,2,3,4,5 };
//	permutation(a, 5, 1, 3);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int prime[40] = { 0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0 }, n;//素数打表，因为n最大是20，所以只要打到40
//int visited[21], a[21];
//void dfs(int num)//深搜
//{
//	int i;
//	if (num == n&&prime[a[num - 1] + a[0]])  //满足条件了，就输出来
//	{
//		for (i = 0;i < num - 1;i++)
//			printf("%d ", a[i]);
//		printf("%d\n", a[num - 1]);
//	}
//	else
//	{
//		for (i = 2;i <= n;i++)
//		{
//			if (visited[i] == 0)//是否用过了
//			{
//				if (prime[i + a[num - 1]]) //是否和相邻的加起来是素数
//				{
//					visited[i] = -1;//标记了
//					a[num++] = i;//放进数组
//					dfs(num); //递归调用
//					visited[i] = 0; //退去标记
//					num--;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	int num = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		num++;
//		printf("Case %d:\n", num);
//		memset(visited, 0, sizeof(visited));
//		a[0] = 1;
//		dfs(1);
//		printf("\n");
//	}
//	return 0;
//}

//#include<iostream>
//#include<stack>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//bool isOk(int n, int  out[15], int  in[15])
//{
//	stack<int> st;
//	int index_in = 0, index_out = 0;
//	for (;index_out < n;index_out++) {
//		int now = out[index_out];
//		if (!st.empty()) {
//			if (now == st.top()) {
//				st.pop();
//			}
//			else {
//				for (;index_in < n;index_in++) {
//					if (in[index_in] == now) {
//						st.push(now);
//						index_in++;
//						break;
//					}
//					else {
//						st.push(in[index_in]);
//					}
//				}
//				if (now == st.top()) {
//					st.pop();
//				}
//				else {
//					return false;
//					break;
//				}
//			}
//		}
//		else {
//			for (;index_in < n;index_in++) {
//				if (in[index_in] == now) {
//					st.push(now);
//					index_in++;
//					break;
//				}
//				else {
//					st.push(in[index_in]);
//				}
//			}
//			if (now == st.top()) {
//				st.pop();
//			}
//			else {
//				return false;
//				break;
//			}
//		}
//	}
//	if (st.empty()) {
//		return true;
//	}
//}
//
//int main() {
//	int n;
//	int in[105], out[105];
//	while (cin >> n) {
//		long long count = 0;
//		for (int i = 0; i < n; i++)
//		{
//			in[i] = out[i] = i;
//		}
//		do {
//			if (isOk(n, out, in))
//				count++;
//		} while (next_permutation(out, out + n));
//		cout << count << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<map>
//using namespace std;
//
//int main() {
//	int n, t, times;
//	while (cin >> n) {
//		times = (n + 1) / 2;
//		map<int, int> m;
//		map<int, int>::iterator it;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> t;
//			it = m.find(t);
//			if (it == m.end()) {
//				m[t] = 1;
//			}
//			else {
//				m[t] += 1;
//				/*if (m[t] >= times) {
//					cout << t << endl;
//					break;
//				}*/
//			}
//		}
//
//		for (it = m.begin();it != m.end();it++) {
//			if (it->second >= times) {
//				cout << it->first << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//struct node {
//	int index;
//	double rate;
//};
//
//bool comp(node a, node b) {
//	return a.rate > b.rate;
//}
//
//int main() {
//	int n, m, k;
//	while (cin>>n>>m>>k)
//	{
//		node *a = new node[m];
//		
//		for (int i = 0; i < m; i++)
//		{
//			node temp;
//			temp.index = i + 1;
//			cin >> temp.rate;
//			a[i] = temp;
//		}
//		double t;
//		for (int i = 0; i < n-1; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				cin >> t;
//				a[j].rate += t;
//			}
//		}
//		sort(a, a + m, comp);
//		int *idx = new int[k];
//		for (int i = 0; i < k; i++)
//		{
//			idx[i] = a[i].index;
//		}
//		sort(idx, idx + k);
//		for (int i = k - 1;i > 0;i--) {
//			cout << idx[i] << " ";
//		}
//		cout << idx[0] << endl;
//		delete[] a;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int len_of_n(int n) {
//	int len = 1;
//	while (true) {
//		if (n == 1)
//			return len;
//		if (n % 2 != 0)
//			n = 3 * n + 1;
//		else
//			n = n / 2;
//		len++;
//	}
//}
//
//int main() {
//	/*cout << len_of_n(22);*/
//	int i, j;
//	while (cin >> i >> j) {
//		cout << i << " " << j << " ";
//		if (i > j) {
//			int temp = i;
//			i = j;
//			j = temp;
//		}
//		int max = 0;
//		for (int k = i; k <= j; k++)
//		{
//			int temp = len_of_n(k);
//			max = ((temp > max) ? temp : max);
//		}
//		cout << max << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main() {
//	char input[205];
//	while (cin >> input) {
//		cout << "300 420 moveto\n310 420 lineto" << endl;
//		int x = 310, y = 420;
//		char dir = 'r';
//		for (int i = 0,length=strlen(input); i < length; i++)
//		{
//			if (dir == 'r') {
//				if (input[i] == 'A') {
//					y -= 10;
//					dir = 'd';
//				}
//				else {
//					y += 10;
//					dir = 'u';
//				}
//			}
//			else if(dir == 'u') {
//				if (input[i] == 'A') {
//					x += 10;
//					dir = 'r';
//				}
//				else {
//					x -= 10;
//					dir = 'l';
//				}
//			}
//			else if (dir == 'd') {
//				if (input[i] == 'A') {
//					x -= 10;
//					dir = 'l';
//				}
//				else {
//					x += 10;
//					dir = 'r';
//				}
//			}
//			else if (dir == 'l') {
//				if (input[i] == 'A') {
//					y += 10;
//					dir = 'u';
//				}
//				else {
//					y -= 10;
//					dir = 'd';
//				}
//			}
//			cout << x << " " << y << " lineto\n";
//		}
//		cout << "stroke\nshowpage\n";
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main() {
//	int n;
//	while (cin >> n,n) {
//		int *a = new int[n];
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		int *b = new int[n];
//		int count = 0;
//		bool conti = true;
//		int temp;
//		while (conti) {
//			count++;
//			bool tempbool = true;
//			int i;
//			for (i = 0; i < n; i++)
//			{
//				temp = (a[i] + a[(i - 1 + n) % n]) / 2;
//				b[(i - 1 + n) % n] = ((temp % 2 == 0) ? temp : (temp + 1));
//				if (i >= 1) {
//					if (tempbool)
//						if (b[i - 1] != b[(i - 2 + n) % n])
//							tempbool = false;
//				}
//			}
//			if (tempbool)
//				if (b[i - 1] != b[i - 2])
//					tempbool = false;
//			/*for (i = 0; i < n; i++)
//			{
//				if (b[i] != b[(i + 1) % n]) {
//					tempbool = false;
//					break;
//				}
//			}*/
//			if (tempbool)
//				conti = false;
//			else {
//				int *t = a;
//				a = b;
//				b = t;
//			}
//		}
//		cout << count << " " << b[0] << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct onepoint
//{
//	int x, y;
//};
//char m[15][15];
//bool flags[15][15];
//
//int main() {
//	int row, col, start;
//	while (cin >> row >> col&& (row || col))
//	{
//		cin >> start;
//		for (int i = 0; i < 15; i++)
//		{
//			for (int j = 0; j < 15; j++)
//			{
//				flags[i][j] = false;
//			}
//		}
//		vector<onepoint> ve;
//		for (int i = 0; i < row; i++)
//		{
//			cin >> m[i];
//		}
//
//		int x = 0, y = start - 1;
//		onepoint t;
//		t.x = x;t.y = y;
//		ve.push_back(t);
//		flags[x][y] = true;
//		bool isOk = false;
//		int loop_x, loop_y;
//		while (true)
//		{
//			if (m[x][y] == 'N') {
//				x -= 1;
//			}
//			else if (m[x][y] == 'S') {
//				x += 1;
//			}
//			else if (m[x][y] == 'E') {
//				y += 1;
//			}
//			else if (m[x][y] == 'W') {
//				y -= 1;
//			}
//			if (x<0 || x>row - 1 || y<0 || y>col - 1) {
//				isOk = true;
//				break;
//			}
//			else if (flags[x][y] == true) {
//				loop_x = x;loop_y = y;
//				break;
//			}
//			else {
//				onepoint t;
//				t.x = x;t.y = y;
//				ve.push_back(t);
//				flags[x][y] = true;
//			}
//		}
//		if (isOk) {
//			cout << ve.size() << " step(s) to exit\n";
//		}
//		else {
//			int before = 0, s = ve.size();
//			for (int i = 0; i < s; i++)
//			{
//				if (ve[i].x == loop_x&&ve[i].y == loop_y) {
//					break;
//				}
//				else
//					before++;
//			}
//			cout << before << " step(s) before a loop of " << (s - before) << " step(s)\n";
//		}
//	}
//	return 0;
//}

//#include<iostream>
//#include<stdio.h>
//#include<string>
//using namespace std;
//
//char vos[] = { 'a', 'e', 'i', 'o',  'u' };
//
//bool is_vowels(char c) {
//	for (int i = 0; i < 5; i++)
//	{
//		if (c == vos[i])
//			return true;
//	}
//	return false;
//}
//
//int main() {
//	char s[25];
//	while (cin >> s, strcmp(s, "end")) {
//		int length = strlen(s);
//		if (length == 1) {
//			if (is_vowels(s[0]))
//				printf("<%s> is acceptable.\n", s);
//			else
//				printf("<%s> is not acceptable.\n", s);
//		}
//		else if (length == 2) {
//			if (s[0] == s[1]) {
//				if (s[0] == 'e' || s[0] == 'o')
//					printf("<%s> is acceptable.\n", s);
//				else
//					printf("<%s> is not acceptable.\n", s);
//			}
//			else if (is_vowels(s[0]) == false && is_vowels(s[1]) == false)
//				printf("<%s> is not acceptable.\n", s);
//			else
//				printf("<%s> is acceptable.\n", s);
//		}
//		else {
//			bool c1 = false, c2 = false, c3 = false;
//			for (int i = 0; i < length; i++)
//			{
//				if (is_vowels(s[i])) {
//					c1 = true;
//					break;
//				}
//			}
//			if (c1 == false) {
//				printf("<%s> is not acceptable.\n", s);
//				continue;
//			}
//			char bb = s[0], b = s[1];
//			bool t1, t2, t3;
//			for (int i = 2; i < length; i++)
//			{
//				t1 = is_vowels(bb);
//				t2 = is_vowels(b);
//				t3 = is_vowels(s[i]);
//				if (t1&&t2&&t3 || (t1 == false && t2 == false && t3 == false)) {
//					c2 = true;
//					break;
//				}
//				bb = b;
//				b = s[i];
//			}
//			if (c2) {
//				printf("<%s> is not acceptable.\n", s);
//				continue;
//			}
//			char before = s[0];
//			for (int i = 1; i < length; i++)
//			{
//				if (before == s[i] && before != 'e'&&before != 'o') {
//					c3 = true;
//					break;
//				}
//				before = s[i];
//			}
//			if (c3) {
//				printf("<%s> is not acceptable.\n", s);
//				continue;
//			}
//			printf("<%s> is acceptable.\n", s);
//		}
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int n, bestn;
//char map[10][10];
//
//
//int canput(int row, int col)
//{
//	int i;
//	for (i = row - 1;i >= 0;i--)
//	{
//		if (map[i][col] == 'X')
//		{
//			break;
//		}
//		if (map[i][col] == 'o')
//		{
//			return 0;
//		}
//	}
//	for (i = col - 1;i >= 0;i--)
//	{
//		if (map[row][i] == 'X')
//		{
//			break;
//		}
//		if (map[row][i] == 'o')
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//void backtrack(int k, int current)
//{
//	int x, y;
//	if (k >= n*n)
//	{
//		if (current > bestn)
//		{
//			bestn = current;
//		}
//		return;
//	}
//	else
//	{
//		x = k / n;
//		y = k%n;
//		if (map[x][y] == '.'&&canput(x, y))
//		{
//			map[x][y] = 'o';
//			backtrack(k + 1, current + 1);
//			map[x][y] = '.';
//		}
//		backtrack(k + 1, current);
//	}
//}
//
//int main() {
//	while (cin >> n, n)
//	{
//		bestn = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> map[i];
//		}
//		backtrack(0, 0);
//		cout << bestn << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
//using namespace std;
//
//int main() {
//	char input[205];
//	while (gets_s(input)) {
//		if (strcmp(input,"START")==0 || strcmp(input, "END") == 0)
//			continue;
//		else if (strcmp(input, "ENDOFINPUT") == 0)
//			break;
//		else {
//			for (int i = 0, length = strlen(input); i < length; i++)
//			{
//				if (input[i] >= 'A'&&input[i] <= 'Z')
//					input[i] = (int(input[i] - 'A') - 5 + 26) % 26 + 'A';
//			}
//			cout << input << endl;
//		}
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main() {
//	int n, u, d;
//	while (cin >> n >> u >> d, n, u, d) {
//		int height = 0, time = 0;
//		while (true) {
//			height += u;
//			time++;
//			if (height >= n) {
//				break;
//			}
//			time++;
//			height -= d;
//		}
//		cout << time << endl;
//	}
//	return 0;
//}

//#include <iostream>  
//using namespace std;
//char map[9][9];        //地图最多不超过7行7列,又从(1,1)计算,所以开辟9,9  
//int n, m, t, di, dj;       //给定的三个量,以及终点位置  
//bool escape;           //标识逃生成功  
//int dir[4][2] = { { 0,-1 },{ 0,1 },{ 1,0 },{ -1,0 } };  //分别表示左、右、下、上四个方向  
//void DFS(int si, int sj, int cnt)
//{
//	int i, temp;
//	if (si > n || sj > m || si <= 0 || sj <= 0)   //越出边界便不搜索  
//		return;
//	if (si == di && sj == dj && cnt == t)
//	{
//		escape = 1;                   //时间正好的时候才能逃生  
//		return;
//	}
//	temp = abs(t - cnt) - (abs(di - si) + abs(dj - sj));     //计算当前到终点的最短路与还需要的时间差,若小于0则路径剪枝  
//	if (temp < 0 || temp & 1)           //temp如果是奇数的话也要剪枝  
//		return;
//	for (i = 0;i < 4;i++)
//	{
//		if (map[si + dir[i][0]][sj + dir[i][1]] != 'X')
//		{
//			map[si + dir[i][0]][sj + dir[i][1]] = 'X';  //把当前点刷为X  
//			DFS(si + dir[i][0], sj + dir[i][1], cnt + 1); //搜索该点              
//			if (escape)
//				return;
//			map[si + dir[i][0]][sj + dir[i][1]] = '.';  //如果搜索不到退出来了,则重新把该点刷为'.'  
//		}
//	}
//	return;
//}
//int main()
//{
//	int i, j, si, sj, wall;
//	while (cin >> n >> m >> t)
//	{
//		if (n == 0 && m == 0 && t == 0)
//		{
//			break;
//		}
//		wall = 0;
//		for (i = 1;i <= n;i++)
//		{
//			for (j = 1;j <= m;j++)
//			{
//				cin >> map[i][j];
//				if (map[i][j] == 'S')
//				{
//					si = i, sj = j;
//				}
//				else if (map[i][j] == 'D')
//				{
//					di = i, dj = j;
//				}
//				else if (map[i][j] == 'X')
//				{
//					wall++;
//				}
//			}
//		}
//		if (n*m - wall <= t)      //路径剪枝,当走完不含墙的迷宫都还不到T时间将不能逃生  
//		{
//			cout << "NO" << endl;
//			continue;
//		}
//		escape = 0;
//		map[si][sj] = 'X';      //记得刷为'X'  
//		DFS(si, sj, 0);
//		if (escape)
//		{
//			cout << "YES" << endl;
//		}
//		else
//		{
//			cout << "NO" << endl;
//		}
//	}
//	return 0;
//}
//
//#include <iostream>  
//#include <vector>  
//using namespace std;
//const int SIZE = 105;
//
//int roomNumber, trooperNumber;
//int cost[SIZE], brain[SIZE];
//int dp[SIZE][SIZE];   /*dp[u][p]表示用 P 个士兵占领以 u 为根节点的子树所能获得的概率最大值*/
//vector<int> adj[SIZE];   /*图*/
//
//void dfsPulsDp(int p, int pre)
//{
//	for (int i = cost[p]; i <= trooperNumber; ++i)   /*初始化,首先将dp[p][i]里面填充进brain[p],后面可以更新dp[p][i]的值*/
//		dp[p][i] = brain[p]; /*也就是说当我们有cost[p]名队员以至于更多时,我们最少可以获得brain[p]个大脑*/
//	int num = adj[p].size();   /*num指p节点含有的支路数*/
//	for (int i = 0; i < num; ++i)  /*一条支路一条支路遍历,也就是所谓的dfs*/
//	{
//		int v = adj[p][i];
//		if (v == pre) continue;  /*避免死循环,节点如果是根部,就继续*/
//		dfsPulsDp(v, p);   /*递归解决问题,先将子节点的所能得到的最大值计算出来*/
//
//		for (int j = trooperNumber; j >= cost[p]; --j)  /*当队员人数一定时*/
//			for (int k = 1; k <= j - cost[p]; ++k)     /*由于p节点一定要通过,所以一定要花费cost[p]*/
//				if (dp[p][j] < dp[p][j - k] + dp[v][k])
//				{/*v节点就两种状态,要么选择，要么不选择,选择的话dp[p][j] = dp[p][j - k] + dp[v][k],不选择的话就不变*/
//					dp[p][j] = dp[p][j - k] + dp[v][k];
//				}
//	}
//}
//
//int main()
//{
//	while ((cin >> roomNumber >> trooperNumber) && (roomNumber != -1) && (trooperNumber != -1))
//	{
//		int bug, bi1, bi2;
//		int i;
//		for (i = 0; i < roomNumber; i++)
//		{
//			cin >> bug >> brain[i];
//			cost[i] = (bug + 19) / 20;
//		}
//		for (i = 0; i < roomNumber; i++)
//			adj[i].clear();
//
//		for (i = 0; i < roomNumber - 1; i++)
//		{
//			cin >> bi1 >> bi2;
//			adj[bi1 - 1].push_back(bi2 - 1);
//			adj[bi2 - 1].push_back(bi1 - 1);
//		}
//
//		if (trooperNumber == 0)
//		{
//			cout << '0' << endl;
//			continue;
//		}
//
//		memset(dp, 0, sizeof(dp));
//		dfsPulsDp(0, -1);
//		cout << dp[0][trooperNumber] << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//struct node
//{
//	int l, w;
//};
//node sti[5005];
//bool flags[5005];
//
//bool cmp(node a, node b)
//{
//	if (a.l != b.l)
//		return a.l > b.l;
//	else
//		return a.w > b.w;
//}
//
//int main() {
//	int n, m;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> m;
//		for (int j = 0; j < m; j++)
//		{
//			cin >> sti[j].l >> sti[j].w;
//			flags[j] = 0;
//		}
//		sort(sti, sti + m, cmp);
//		int times = 0;
//		for (int j = 0; j < m; j++)
//		{
//			if (flags[j])
//				continue;
//			int min = sti[j].w;
//			for (int k = j + 1; k < m; k++)
//			{
//				if (min >= sti[k].w && !flags[k])
//				{
//					min = sti[k].w;
//					flags[k] = 1;
//				}
//			}
//			times++;
//		}
//		cout << times << endl;
//	}
//	return 0;
//}