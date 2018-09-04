#include "global.h"
//#include "node.h"
//#include "Sales_data_struct.h"
//#include "Sales_data.h"
//#include "construct_paras_must_init.h"
//#include "Screen.h"
//#include "Window_mgr.h"
//#include "StrBlob.h"
//#include "TextQuery.h"
//#include "HasPtr.h"
//#include "NoCopy.h"
//#include "StrVec.h"
//#include "CallableClass.h"
//#include "conversion_operator.h"
//#include "Quote.h"
//#include "template_functions.h"
//#include "Blob.h"

//int my_special_add(int a, int b) { return a + b; }

int main(int argc, char *argv[])
{
	// reference
	/*string str = "Hello world!";
	string str1 = "Hello c++!";
	string &str_ref = str;
	cout << str << endl;
	cout << str_ref << endl << endl;
	str_ref[0] = 'h';
	cout << str << endl;
	cout << str_ref << endl << endl;
	str_ref = str1;
	cout << str1 << endl;
	cout << str_ref << endl;*/

	// pointer
	/*int year = 2017;
	int *pt_year = &year;
	cout << year << endl;
	cout << pt_year << endl;
	cout << *pt_year << endl;
	pt_year = nullptr;
	cout << pt_year << endl;
	pt_year = 0;
	cout << pt_year << endl;
	pt_year = NULL;
	cout << pt_year << endl;
	int *&year_ptr = pt_year;
	cout << *year_ptr << endl;
	*year_ptr = 2018;
	cout << *year_ptr << endl;*/

	// const（常量）
	// const double pi = 3.1415;
	/*cout << pi << endl; // pi是定义在别的文件中的常量

	const double &PI = pi; // 对常量的引用（可以绑定非常量对象，但是常量对象只能用对常量的引用来绑定）
	cout << PI << endl;

	const double *ptr_pi = &pi; // 指向常量的指针（可以指向非常量对象，但是常量对象只能用指向常量的指针指向）
	cout << *ptr_pi << endl;

	extern double sqrt_2; // 定义在别的文件中的变量
	cout << sqrt_2 << endl;

	const double *ptr_sqrt_2 = &sqrt_2;
	cout << *ptr_sqrt_2 << endl;

	double *const sqrt_2_ptr = &sqrt_2; // 常量指针
	cout << *sqrt_2_ptr << endl;

	const double *const pi_ptr = &pi; // 指向常量的常量指针
	cout << *pi_ptr << endl;*/

	// auto and decltype
	/*auto var = 3.14; // 自动推断类型
	cout << var << endl;
	decltype(var) *ptr_var = &var; // decltype返回括号内表达式的类型
	cout << *ptr_var << endl;
	decltype((var)) ref_var = var; // decltype((variable))的类型永远是引用，必须初始化
	cout << ref_var << endl;*/

	// in-class initializer
	/*node n;
	cout << n.value << endl;
	cout << n.next << endl;*/

	// string
	// getline
	/*string line;
	while (getline(cin, line))
	{
		if (!line.empty())
			cout << line << endl;
	}*/
	// string::size_type
	/*auto len = line.size(); // 返回类型为string::size_type（无符号整型数）
	cout << len << endl;*/
	// range for（范围for） in string
	//统计标点符号个数
	/*string str = "hello world!!!";
	decltype(str.size()) punct_cnt = 0;
	for (auto c : str)
	{
		if (ispunct(c))
			punct_cnt++;
	}
	cout << punct_cnt << " punctuation characters in \"" << str << "\"" << endl;*/
	// 使用范围for更改string
	/*for (auto &c : str)
	{
		c = toupper(c);
	}
	cout << str << endl;*/

	// vector
	// 列表初始化和范围for
	/*vector<int> ve{ 1,2,3,4,5,6,7,8,9 };
	for (auto &i : ve)
	{
		i *= i;
	}
	for (auto i : ve)
	{
		cout << i << " ";
	}
	cout << endl;*/
	//iterator and const_interator
	/*vector<int> ve{ 1,2,3,4,5,6,7,8,9 };
	const vector<int> ve1{ 1,2,3,4,5,6,7,8,9 };
	vector<int>::iterator it;
	vector<int>::const_iterator it1;
	for (it = ve.begin(); it != ve.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (auto iter = ve.begin(); iter != ve.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	for (it1 = ve1.begin(); it1 != ve1.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	for (auto iter1 = ve.cbegin(); iter1 != ve.cend(); ++iter1)
	{
		cout << *iter1 << " ";
	}
	cout << endl;*/

	// 指针数组，指向数组的指针，数组的引用
	/*int nums[] = { 0,1,2,3,4,5,6,7,8,9 };
	constexpr size_t cnt = 10;
	int *num_ptrs[cnt]; // 指针数组
	for (unsigned i = 0; i < cnt; ++i)
		num_ptrs[i] = &(nums[i]);
	for (auto i : num_ptrs)
		cout << *i << " ";
	cout << endl;
	int(*nums_ptr)[cnt] = &nums; // 指向数组的指针
	for (unsigned i = 0; i < cnt; ++i)
		cout << (*nums_ptr)[i] << " ";
	cout << endl;
	int(&nums_ref)[cnt] = nums; // 数组的引用
	for (auto i : nums_ref)
		cout << i << " ";
	cout << endl;
	int *(&num_ptrs_ref)[cnt] = num_ptrs; // 指针数组的引用
	for (auto i : num_ptrs_ref)
		cout << *i << " ";
	cout << endl;*/

	// 数组的begin和end
	/*int nums[] = { 0,1,2,3,4,5,6,7,8,9 };
	int *pbegin = begin(nums), *pend = end(nums);
	for (auto it = pbegin; it != pend; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;*/

	// 范围for处理多维数组
	/*constexpr size_t row = 3, col = 3;
	int nums[row][col];
	int cnt = 0;
	for (auto &row : nums)
		for (auto &col : row)
		{
			col = cnt++;
		}
	for (const auto &row : nums) {
		for (auto col : row)
			cout << col << " ";
		cout << endl;
	}*/

	// 左值->对象的身份（内存中的位置）    右值->对象的值（内容）
	/*int a = 123;
	int *ptr_a = &a;
	decltype(*ptr_a) b = a; // 解指针生成左值，则类型为int&
	cout << b << endl;
	decltype(&ptr_a) ptr_ptr_a = &ptr_a; // 取地址生成右值，则类型为int**
	cout << **ptr_ptr_a << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(ptr_a) << endl;
	cout << sizeof(ptr_ptr_a) << endl;*/

	// 显式类型转换：cast_name<type>(expr)    旧版本：type(expr)或(type)expr
	// cast_name:static_cast, dynamic_cast, const_cast, reinterpret_cast
	// static_cast:静态类型转换，不得处理底层指针
	/*int a = 3, b = 2;
	double res = a / b;
	cout << res << endl;
	res = static_cast<double>(a) / b;
	cout << res << endl;
	void *ptr = &res;
	double *ptr_res = static_cast<double*>(ptr);
	cout << *ptr_res << endl;
	// const_cast:常量类型转换，只处理底层指针（将指向常量的指针转换成指向非常量的指针，反之亦然）
	const int cst = 123;
	const int *cptr_cst = &cst;
	cout << *cptr_cst << endl;
	int *ptr_cst = const_cast<int*>(cptr_cst); // 转换后可以修改其指向的对象了
	cout << *ptr_cst << endl;
	*ptr_cst = 1234;
	cout << *ptr_cst << endl;
	// reinterpret_cast:重新解释类型转换
	int t = 65;
	int *ptr_t = &t;
	char *char_ptr_t = reinterpret_cast<char*>(ptr_t); // 重新解释成指向字符的指针
	cout << *char_ptr_t << endl;*/

	// try-catch
	/*try
	{
		int a = 1, b = 0;
		if (b == 0)
			throw runtime_error("divided by zero!!!");
		cout << (a / b) << endl;
	}
	catch (runtime_error err) {
		cout << err.what() << endl;
	}*/

	// 局部静态变量测试
	/*for (size_t i = 0; i < 10; ++i) {
		cout << "调用次数：" << func_call_times() << endl;
	}*/


	// initializer_list
	/*err_msg({ "func_x", "error", "bad!!!!" });
	err_msg({ "func_y","okay!!!!" });*/

	// 返回指向数组的指针
	/*int(*arr_ptr)[5] = odd_eve_1(1);
	for (auto &i : *arr_ptr)
		cout << i << " ";
	cout << endl;
	arr_ptr = odd_even_2(2);
	for (auto &i : *arr_ptr)
		cout << i << " ";
	cout << endl;
	arr_ptr = odd_even_3(3);
	for (auto &i : *arr_ptr)
		cout << i << " ";
	cout << endl;*/

	// const_cast用于函数重载
	/*cout << shorter_string("hi", "hello") << endl;
	string s1 = "hi", s2 = "hello";
	string s = shorter_string(s1, s2);
	cout << s << endl;
	s[0] = 'H';
	cout << s << endl;*/

	// 默认参数
	/*print_info("Window");
	print_info("Window1",1000);
	print_info("Window2", 1000,2000);*/

	// constexpr函数
	/*constexpr double result = x_pi_value(3, pi_value());
	cout << setprecision(10) << result << endl;*/

	// assert和NDEBUG
	/*cout << "hello world!" << endl;
	assert(1 + 1 == 3);
	#ifndef NDEBUG
		cout << __FILE__ << ": function " << __func__ << " error!" << endl;
		cout << "\tat line: " << __LINE__ << endl;
		cout << "\t\tcompiled on " << __DATE__ << " at " << __TIME__ << endl;
	#endif // !NDEBUG*/

	// 函数指针
	/*const string& (*func_ptr)(const string &s1, const string &s2) = shorter_string;
	auto s = func_ptr("Hi", "Hello");
	cout << s << endl;*/

	// 函数做形参
	//cout << func_as_param("hi", "hello", shorter_string) << endl;

	// 返回函数指针
	/*cout << func_ptr_1()(-10) << endl;
	cout << func_ptr_2()(-10) << endl;
	cout << func_ptr_3()(-10) << endl;
	cout << func_ptr_4()(-10) << endl;*/

	// 测试Sales_data_struct类
	/*Sales_data_struct total;
	if (read(cin, total))
	{
		Sales_data_struct trans;
		while (read(cin, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}*/

	// 测试Sales_data类
	/*Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}*/

	// 必须通过构造函数初始值列表进行初始化
	/*ConstRef cr(520);
	cr.print();*/

	// Screen类测试
	/*Screen s(2, 3, '*');
	const Screen cs(2, 3, '#');
	s.mutable_test();
	cs.mutable_test();
	s.display(cout);
	cs.display(cout);
	s.move(0, 2).set('$').display(cout);
	cs.display(cout);
	s.mutable_test();
	cs.mutable_test();*/

	// Window_mgr类测试
	/*Window_mgr w;
	cout << "Added Screen at " << w.addScreen(s) << endl;
	cout << "Added Screen at " << w.addScreen(cs) << endl;
	w.display_screens(cout);
	w.clear(0);
	w.clear(1);
	w.clear(2);
	w.display_screens(cout);*/

	// IO条件状态
	/*auto status = cin.rdstate(); // 获取流的状态标志
	cout << status << endl << endl;
	cout << cin.badbit << endl;
	cout << cin.bad() << endl;
	cout << cin.goodbit << endl;
	cout << cin.good() << endl;
	cout << cin.failbit << endl;
	cout << cin.fail() << endl;
	cout << cin.eofbit << endl;
	cout << cin.eof() << endl;
	cin.clear(); // 清除（复位）流的状态标志
	cin.setstate(status); // 设置流的状态标志*/

	// IO缓冲区
	/*cout << "Hello World!!!" << endl; // 输出换行再刷新缓冲区
	cout << "Hello World!!!" << flush; // 立即刷新缓冲区
	cout << "Hello World!!!" << ends; // 输出空格再刷新缓冲区
	cout << unitbuf; // 设置缓冲区为立即刷新
	cout << "Hello World!!!";
	cout << nounitbuf; // 恢复正常的缓冲方式*/

	// 流关联（可以将输入流关联到输出流或输出流关联到输出流，这样当被关联流操作前一定会刷新关联流）
	/*cin.tie(&cout); // 默认cin与cout关联（此处用于演示）
	ostream *old_tie = cin.tie(nullptr); // 解除所有关联
	cin.tie(&cerr); // 关联到cerr
	cin.tie(old_tie); // 恢复初始关联*/

	// 文件流操作
	/*ifstream input;
	input.open("E:\\test\\in.txt");
	if (input) {
		string s;
		while (input >> s)
			cout << s << endl;
	}
	input.close();
	ofstream output;
	output.open("E:\\test\\out.txt");
	string s = "Hello world!!!";
	output << s << endl;
	output.close();
	output.open("E:\\test\\out.txt", ofstream::app);
	output << s << endl;
	output.close();*/

	// 字符串流操作
	/*string s = "wang 123 456 789";
	istringstream iss(s);
	string name;
	iss >> name;
	string word;
	vector<string> nums;
	while (iss >> word)
		nums.push_back(word);
	ostringstream oss;
	oss << name << ": ";
	for (const auto &item : nums) {
		oss << item << " ";
	}
	cout << oss.str() << endl;*/

	// array
	/*array<int, 10> rnd;
	for (const auto &item : rnd){
		cout << item << endl;
	}
	for (auto it = rnd.begin(); it != rnd.end(); ++it){
		*it = rand();
	}
	for (const auto &item : rnd){
		cout << item << endl;
	}*/

	// assign
	/*list<const char*> oldstring{ "hello","world","!" };
	vector<string> newstring;
	newstring.assign(oldstring.cbegin(), oldstring.cend());
	for (const auto &item : newstring){
		cout << item << endl;
	}
	newstring.assign(5, "hi");
	for (const auto &item : newstring){
		cout << item << endl;
	}*/

	// swap
	/*vector<int> ve1{ 1,2,3 };
	vector<int> ve2{ 4,5,6 };
	swap(ve1, ve2);
	for (const auto &item : ve1){
		cout << item << endl;
	}
	cout << endl;
	for (const auto &item : ve2){
		cout << item << endl;
	}*/

	// max_size()
	/*vector<int> ve;
	cout << ve.max_size() << endl;*/

	// 插入操作（在迭代器所指元素之前进行插入，返回指向插入的第一个元素的迭代器）
	/*deque<int> dq{ 1,2,3 };
	dq.push_back(4);
	dq.push_front(0);
	for (const auto &item : dq) {
		cout << item << endl;
	}
	auto it = dq.end();
	list<int> li{ 5,6,7,8,9 };
	// dq.insert(it, { 5,6,7,8,9 });
	dq.insert(it, li.begin(), li.end());
	for (const auto &item : dq) {
		cout << item << endl;
	}
	deque<string> sdq;
	// emplace使用构造器构造元素进行插入
	sdq.emplace_front(3, 'o');
	sdq.emplace_back(4, 'u');
	sdq.emplace(sdq.end(), 5, 'i');
	for (const auto &item : sdq) {
		cout << item << endl;
	}*/

	// 访问元素
	/*vector<int> ve = { 0,1,2,3,4 };
	cout << ve.front() << endl;
	cout << ve.back() << endl;
	cout << ve[1] << endl;
	cout << ve.at(1) << endl;*/

	// 删除元素（删除迭代器所指元素后面的元素，返回指向删除元素后面的元素的迭代器）
	/*list<int> li = { 0,1,2,3,4 };
	li.pop_back();
	li.pop_front();
	for (const auto &item : li) {
		cout << item << endl;
	}
	auto it = li.begin();
	li.erase(it);
	cout << endl;
	for (const auto &item : li) {
		cout << item << endl;
	}
	it = li.end();
	li.erase(--it);
	cout << endl;
	for (const auto &item : li) {
		cout << item << endl;
	}
	li.erase(li.begin(), li.end());
	for (const auto &item : li) {
		cout << item << endl;
	}
	// li.clear();*/

	// forword_list特殊操作（由于其特殊性，所有操作都是after）
	/*forward_list<int> fli{ 0,1,2,3,4,5,6,7,8,9 };
	auto pre = fli.before_begin();
	auto curr = fli.begin();
	while (curr != fli.end()) {
		if (*curr % 2) {
			curr = fli.erase_after(pre);
		}
		else {
			pre = curr;
			++curr;
		}
	}
	for (const auto &item : fli) {
		cout << item << endl;
	}*/

	// resize
	/*deque<int> dq(10, 1);
	dq.resize(5);
	for (const auto &item : dq) {
		cout << item << endl;
	}
	dq.resize(10, 2);
	for (const auto &item : dq) {
		cout << item << endl;
	}*/

	// string搜索
	/*string nums("0123456789"), name("hgs8g9hhh9ga53sdf0");
	string::size_type pos = 0;
	while ((pos = name.find_first_of(nums, pos)) != string::npos) {
		cout << "Found number " << name[pos] << " at " << pos << endl;
		++pos;
	}*/

	// 数值转换
	/*string spi = to_string(pi);
	cout << spi << endl;
	string sn = "12345";
	string sd = "1234.567";
	cout << stoi(sn) << endl;
	cout << stol(sn) << endl;
	cout << stoul(sn) << endl;
	cout << stoll(sn) << endl;
	cout << stoull(sn) << endl;
	cout << stof(sd) << endl;
	cout << stod(sd) << endl;
	cout << stold(sd) << endl;*/

	// 容器适配器
	/*stack<int> st;
	for (int i = 0; i < 10; ++i) {
		st.push(i);
	}
	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	queue<int> qu;
	for (int i = 0; i < 10; i++)
	{
		qu.push(i);
	}
	while (!qu.empty()) {
		cout << qu.front() << endl;
		qu.pop();
	}*/

	// sort unique stable_sort
	/*string s = "the quick red fox jumps over the slow red turtle";
	vector<string> words;
	istringstream iss(s);
	string word;
	while (iss >> word)
	{
		words.push_back(word);
	}
	elimDups(words);
	// stable_sort(words.begin(), words.end(), isShorter);
	// lambda
	stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size(); });
	cout << "After stable sorting: " << endl;
	for (const auto &item : words) {
		cout << item << " ";
	}
	cout << endl;*/

	// lambda,for_each
	/*string s = "the quick red fox jumps over the slow red turtle";
	vector<string> words;
	istringstream iss(s);
	string word;
	while (iss >> word)
	{
		words.push_back(word);
	}
	biggies_lambda(words, 4);
	cout << endl;
	biggies_bind(words, 4);*/

	// inserter
	/*list<int> lst = { 1,2,3,4,5,6,7,8,9 };
	list<int> lst1, lst2, lst3;
	copy(lst.begin(), lst.end(), back_inserter(lst1));
	copy(lst.begin(), lst.end(), front_inserter(lst2));
	copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));
	for (const int &val : lst1) {
		cout << val << " ";
	}
	cout << endl;
	for (const int &val : lst2) {
		cout << val << " ";
	}
	cout << endl;
	for (const int &val : lst3) {
		cout << val << " ";
	}
	cout << endl;*/

	// wordcount
	/*string s = "the quick red fox jumps over the slow red turtle";
	map<string, size_t> wordcount;
	istringstream iss(s);
	string word;
	while (iss >> word)
	{
		// ++wordcount[word];
		auto ret = wordcount.insert({ word,1 }); // 返回一个pair，<指向插入元素的迭代器,bool>
		if (!ret.second) {
			++ret.first->second;
		}
	}
	auto iter = wordcount.cbegin();
	while (iter != wordcount.cend()) {
		cout << "\"" << iter->first << "\" occurs " << iter->second << ((iter->second > 1) ? " times" : " time") << endl;
		++iter;
	}
	cout << endl;
	string removal_word = "the";
	if (wordcount.erase(removal_word)) { // 返回删除的元素个数
		cout << "ok: \"" << removal_word << "\" removed!" << endl;
	}
	else {
		cout << "oops: \"" << removal_word << "\" not found!" << endl;
	}
	for (const auto &item : wordcount) {
		cout << "\"" << item.first << "\" occurs " << item.second << ((item.second > 1) ? " times" : " time") << endl;
	}*/

	// 查找关键字范围
	/*multimap<int, string> mset{ {0,"h"},{1,"e"},{2,"l"},{2,"l"},{3,"o"} };
	for (auto beg = mset.lower_bound(2), end = mset.upper_bound(2); beg != end; ++beg) {
		cout << beg->first << ": " << beg->second << endl;
	}
	for (auto range = mset.equal_range(2); range.first != range.second; ++range.first) {
		cout << range.first->first << ": " << range.first->second << endl;
	}*/

	/*ifstream map_file("E:\\test\\map_file.txt"), input("E:\\test\\transform_input.txt");
	word_transform(map_file, input);*/

	// 测试StrBlob
	/*StrBlob b1;
	{
		StrBlob b2{ "I","love" };
		b1 = b2;
		b2.push_back("you");
		cout << "b2: " << b2.size() << endl;
	}
	cout << "b1: " << b1.size() << endl;*/

	// shared_ptr与new
	/*shared_ptr<int> sp(new int(520));
	cout << *sp << endl;
	*sp = 1314;
	cout << *sp << endl;
	auto sp1 = sp;
	if (!sp.unique()) {
		sp.reset(new int(520));
	}
	cout << *sp << endl;
	cout << *sp1 << endl;*/

	// 测试StrBlobPtr
	/*StrBlob sb{ "I","love","you" };
	for (StrBlobPtr b = sb.begin(), e = sb.end(); !b.equal(e); b.incr()) {
		cout << b.deref() << " ";
	}
	cout << endl;*/

	// 动态数组与智能指针
	/*int *ia = new int[10];
	for (size_t i = 0; i < 10; i++)
	{
		ia[i] = i;
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << ia[i] << " ";
	}
	cout << endl;
	delete[] ia;
	unique_ptr<int[]> up(new int[10]);
	for (size_t i = 0; i < 10; i++)
	{
		up[i] = i;
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << up[i] << " ";
	}
	up.release();*/

	// allocator
	/*vector<int> ve{ 0,1,2,3,4,5,6,7,8,9 };
	allocator<int> alloc;
	auto p = alloc.allocate(ve.size() * 2);
	auto q = uninitialized_copy(ve.begin(), ve.end(), p);
	uninitialized_fill_n(q, ve.size(), 10);
	for (auto e = p + ve.size() * 2; p != e; ++e) {
		cout << *p << " ";
	}
	cout << endl;*/

	// 测试TextQuery
	/*ifstream infile("E:\\test\\TextQuery_test.txt");
	TextQuery tq(infile);
	while (true) {
		cout << "Enter word to look for or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") {
			break;
		}
		print(cout, tq.query(s)) << endl;
	}*/

	// 测试拷贝构造函数（当用一个对象初始化另一个同类型的对象时，将调用拷贝构造函数）
	/*Sales_data ad("1", 1, 1);
	Sales_data ad1 = ad;
	print(cout, ad1) << endl;*/

	// 测试拷贝赋值运算符（当用一个对象赋值另一个同类型的对象时，将调用拷贝赋值运算符）
	/*Sales_data ad1("1", 1, 1), ad2("2", 2, 2);
	print(cout, ad1) << endl;
	ad1 = ad2;
	print(cout, ad1) << endl;*/

	// 测试HasPtr
	/*HasPtr hp("test");
	hp.print_HasPtr(cout) << endl;
	auto p = [](HasPtr hp) {HasPtr ret = hp; return ret; }; // 如果没有定义拷贝构造函数，hp和ret会执行析构，sp指向的内存被释放两次
	p(hp);
	HasPtr hp1 = hp; // 如果没有定义拷贝构造函数，hp1和hp都指向已删除的无效内存空间
	hp1.print_HasPtr(cout) << endl;*/

	// 测试NoCopy
	/*NoCopy nc, nc1("test");
	// NoCopy nc2 = nc; 无法进行拷贝初始化，被阻止
	nc.print_NoCopy(cout) << endl;
	nc1.print_NoCopy(cout) << endl;
	// nc = nc1; 无法进行赋值拷贝，被阻止*/

	// 测试类指针的HasPtr
	/*HasPtr hp1("HasPtr1");
	hp1.print_HasPtr(cout) << endl << endl;
	HasPtr hp2 = hp1;
	hp1.print_HasPtr(cout) << endl;
	hp2.print_HasPtr(cout) << endl << endl;
	hp1 = hp2;
	hp1.print_HasPtr(cout) << endl;
	hp2.print_HasPtr(cout) << endl << endl;
	HasPtr hp3("HasPtr3");
	hp1 = hp3;
	hp1.print_HasPtr(cout) << endl;
	hp2.print_HasPtr(cout) << endl;
	hp3.print_HasPtr(cout) << endl << endl;*/

	// 测试StrVec
	/*StrVec sv;
	sv.push_back("hello");
	sv.push_back("world");
	for (auto iter = sv.begin(); iter != sv.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	cout << sv.size() << " " << sv.capacity() << endl;
	StrVec sv1 = sv;
	for (auto iter = sv1.begin(); iter != sv1.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	cout << sv1.size() << " " << sv1.capacity() << endl;
	sv1.push_back("!");
	for (auto iter = sv1.begin(); iter != sv1.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	cout << sv1.size() << " " << sv1.capacity() << endl;
	sv1 = sv;
	for (auto iter = sv1.begin(); iter != sv1.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	cout << sv1.size() << " " << sv1.capacity() << endl;*/

	// 测试重载运算符版本Sales_data类
	/*Sales_data total;
	if (cin >> total)
	{
		Sales_data trans;
		while (cin >> total)
		{
			if (total.isbn() == trans.isbn())
				total += trans;
			else
			{
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}*/

	// 测试重载运算符版本的StrBlobPtr
	/*StrBlob sb = { "I","love","you" };
	for (StrBlobPtr iter = sb.begin(); iter != sb.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;*/

	// 测试PrintString
	/*PrintString ps;
	ps("hello");
	ps("world");
	cout << endl;
	vector<string> ve = { "I","love","you" };
	for_each(ve.begin(), ve.end(), PrintString(cout, '\n'));*/

	// function类型
	/*auto mod = [](int a, int b) {return a % b; };
	map < string, function<int(int, int)>> binops = {
		{"+",my_special_add },
		{"-",std::minus<int>()},
		{"*",[](int a,int b) {return a * b; }},
		{"/",divide()},
		{"%",mod}
	};
	cout << binops["+"](10, 5) << endl;
	cout << binops["-"](10, 5) << endl;
	cout << binops["*"](10, 5) << endl;
	cout << binops["/"](10, 5) << endl;
	cout << binops["%"](10, 5) << endl;*/

	// 测试SmallInt类
	/*SmallInt si = 2; // 调用构造函数SmallInt(int)
	cout << si + 4 << endl; // si隐式类型转换成int(2)
	si = 0; // 0隐式转换成SmallInt（0），然后调用赋值拷贝运算符
	cout << static_cast<bool>(si) << endl;
	if (!si) {
		cout << "Hello wordl!!!" << endl;
	}*/

	// 测试Quote类
	/*vector<shared_ptr<Quote>> ve;
	ve.push_back(make_shared<Quote>("0", 50));
	ve.push_back(make_shared<Bulk_quote>("1", 50, 10, 0.25));
	for (const auto &ptr : ve) {
		cout << ptr->net_price(15) << endl;
	}*/

	/*cout << "compare 1 and 2: " << compare(1, 2) << endl;
	cout << "compare \"hi\" and \"hello\": " << compare("hi", "hello") << endl;*/

	// 测试Blob类
	/*Blob<int> b = { 0,1,2,3,4 };
	for (size_t i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
		b[i] = b[i] * b[i];
	}
	cout << endl;
	for (size_t i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	b.push_back(25);
	cout << "front: " << b.front() << " back: " << b.back() << endl;
	b.pop_back();
	for (size_t i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	const Blob<int> cb = { 0,1,2,3,4 };
	const int &v1 = cb.front(), &v2 = cb.back(), &v3 = cb[1];
	cout << "cb[0]: " << v1 << " cb[4]: " << v2 << " cb[1]: " << v3 << endl;*/

	/*cout << compare(1, 2) << endl;
	cout << compare(1, 1) << endl;
	cout << compare(2, 1) << endl;
	Sales_data s1("1", 1, 1), s2("2", 2, 2);
	auto isbn_compare = [](const Sales_data &sd1, const Sales_data &sd2)->int {return sd1.isbn().compare(sd2.isbn()); };
	cout << compare(s1, s2, isbn_compare) << endl;*/

	/*long a = 100;
	int b = 20;
	cout << sum<long long>(a, b) << endl;
	cout << sum<long long, int, int>(a, b) << endl;*/

	/*int a = 0;
	double b = 2;
	string c = "3";
	long d = 4;
	print(cout, a, b, c, d) << endl;*/

	// 函数模板特例化
	/*char s1[] = "hi", s2[] = "hello";
	const char *ps1 = "hi", *ps2 = "hello";
	cout << "char []: " << compare(s1, s2) << endl;
	cout << "char *: " << compare(ps1, ps2) << endl;*/

	// 类型转发
	/*auto f = [](int &&i, int &j) {cout << i << " " << ++j << endl; };
	int v = 1;
	flip(f, v, 1);*/

	/*cout << sizeof(bool) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(long double) << endl;*/

	// 正则表达式
	/*string p("[^c]ei");
	p = "[[:alpha:]]*" + p + "[[:alpha:]]*";
	regex r(p);
	smatch results;
	string test = "receipt freind theif receive";
	if (regex_search(test, results, r))
	{
		cout << results.str() << endl;
	}*/
	//regex re("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase); // 忽略大小写
	//smatch res;
	//string filename("hello.cpp");
	//if (regex_search(filename, res, re))
	//{
	//	cout << res.str() << endl;
	//}
	//string p("[^c]ei");
	//p = "[[:alpha:]]*" + p + "[[:alpha:]]*";
	//regex r(p);
	//string test = "receipt freind theif receive";
	//for (sregex_iterator it(test.begin(), test.end(), r), it_end; it != it_end; ++it)
	//{
	//	auto pos = it->prefix().length(); // prefix，表示寻到的匹配串的前面的字符串，ssub_match对象
	//	pos = pos > 10 ? pos - 10 : 0;
	//	cout << it->prefix().str().substr(pos) << "\n\t>>>"
	//		<< it->str() << "<<<\n" << it->suffix().str().substr(0, 10) << endl; // suffix，表示寻到的匹配串的后面的字符串，ssub_match对象
	//}
	/*auto valid = [](const smatch &m)->bool
	{
		if (m[1].matched)
		{
			return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
		}
		else
		{
			return !m[3].matched && m[4].str() == m[6].str();
		}
	};*/
	//string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	//string fmt = "$2.$5.$7"; // $n表示第n个子表达式
	//regex re(phone);
	//string test = "000 1234567, (000) 1234567, 000-1234567, 000 123 4567, 000-123-4567";
	//for (sregex_iterator it(test.begin(), test.end(), re), it_end; it != it_end; ++it)
	//{
	//	if (valid(*it))
	//	{
	//		cout << "valid: " << it->str() << "\tformatted: " << (*it).format(fmt) << endl;
	//		// cout << "valid: " << it->str() << "\tformatted: " << regex_replace(it->str(), re, fmt) << endl;
	//	}
	//	else
	//	{
	//		cout << "invalid: " << it->str() << endl;
	//	}
	//}

	// 随机数
	/*uniform_int_distribution<unsigned> u(1, 10); // 均匀unsigned分布
	default_random_engine e; // 随机数生成器
	cout << "min: " << e.min() << " max: " << e.max() << " max unsigned:" << (unsigned)(-1) << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << u(e) << " ";
	}
	cout << endl;*/
	// 随机数生成器如果不定义成static的话，每次调用生成相同序列，定义成static可以保持状态
	//auto p = []()
	//{
	//	vector<unsigned> ve;
	//	/*uniform_int_distribution<unsigned> u(1, 10);
	//	default_random_engine e;*/
	//	static uniform_int_distribution<unsigned> u(1, 10);
	//	static default_random_engine e;
	//	for (size_t i = 0; i < 10; i++)
	//	{
	//		ve.push_back(u(e));
	//	}
	//	return ve;
	//};
	//vector<unsigned> ve1 = p(), ve2 = p();
	//for (size_t i = 0, sz = ve1.size(); i < sz; i++)
	//{
	//	cout << ve1[i] << " ";
	//}
	//cout << endl;
	//for (size_t i = 0, sz = ve2.size(); i < sz; i++)
	//{
	//	cout << ve2[i] << " ";
	//}
	//cout << endl;
	//uniform_real_distribution<double> u(0, 1); // 均匀实数分布
	//default_random_engine e;
	//for (size_t i = 0; i < 10; i++)
	//{
	//	cout << u(e) << " ";
	//}
	//cout << endl;

	// 信号处理
	//auto sighandler = [](int signum) // 信号处理函数
	//{
	//	cout << "Interrupt signal(" << signum << ") recieved!" << endl;
	//	exit(signum);
	//};
	//signal(SIGINT, sighandler); // 关联信号和信号处理函数
	//int cnt = 0;
	//while (true)
	//{
	//	if (cnt == 3)
	//		raise(SIGINT);
	//	cout << "Sleeping..." << endl;
	//	Sleep(1000);
	//	++cnt;
	//}

	// 多线程std::thread
	//auto f1 = [](int n)
	//{
	//	for (int i = 0; i < 5; ++i)
	//	{
	//		cout << "Thread " << n << " executing... ID: " << this_thread::get_id() << endl;
	//		this_thread::sleep_for(chrono::seconds(1));
	//	}
	//};
	//auto f2 = [](int& n)
	//{
	//	for (int i = 0; i < 5; ++i) {
	//		cout << "Thread 2 executing... ID: " << this_thread::get_id() << endl;
	//		++n;
	//		this_thread::sleep_for(chrono::seconds(1));
	//	}
	//};
	//int n = 0;
	//thread t1;
	//thread t2(f1, n + 1); // 传值
	//thread t3(f2, std::ref(n)); // 传引用
	//thread t4(std::move(t3)); // 移动后t3变成无效，t4继续运行
	////if (t1.joinable())
	////	cout << "t1 is joinable" << endl;
	////else
	////	cout << "t1 is not joinable" << endl;
	////if (t2.joinable())
	////	cout << "t2 is joinable" << endl;
	////else
	////	cout << "t2 is not joinable" << endl;
	////if (t3.joinable())
	////	cout << "t3 is joinable" << endl;
	////else
	////	cout << "t3 is not joinable" << endl;
	////if (t4.joinable())
	////	cout << "t4 is joinable" << endl;
	////else
	////	cout << "t4 is not joinable" << endl;
	//std::swap(t2, t4);
	//// 可被joinable的thread对象必须在他们销毁之前被主线程join或者将其设置为detached
	//t2.join();
	//t4.join();
	//cout << "Final value of n is " << n << endl;
	////t2.detach(); // 分离线程，主线程结束后子线程如果没结束，子线程将继续执行
	////t4.detach();
	////this_thread::sleep_for(chrono::seconds(10));

	// 互斥对象std::mutex
	//mutex m;
	//timed_mutex t_m;
	//auto f = [&m]()
	//{
	//	/* 
	//	只传入引用的话，马上调用lock()，如果获取不到锁，则阻塞；
	//	如果传入第二个参数：
	//		std::defer_lock延缓上锁，初始化并不会调用lock()，不阻塞，需要后期调用lock()获取锁
	//		std::try_to_lock尝试上锁（调用try_lock()，不会阻塞线程，然后调用owns_lock()或operator==判断是否获得锁）
	//		std::adopt_lock本线程已经上锁，unique_lock只是获取锁的管理权
	//	*/
	//	unique_lock<mutex> lck(m, defer_lock); 
	//	while (!lck.try_lock())
	//		cout << "-";
	//	this_thread::sleep_for(chrono::milliseconds(1));
	//	cout << "*" << endl;
	//	//m.unlock();
	//};
	//auto tf = [&t_m]()
	//{
	//	unique_lock<timed_mutex> lck(t_m, defer_lock);
	//	// waiting to get a lock: each thread prints "-" every 200ms:
	//	// 等待指定时间间隔，在这个间隔线程处于阻塞状态，如果时间间隔后未得到锁，返回false
	//	while (!lck.try_lock_for(std::chrono::milliseconds(200))) { 
	//		std::cout << "-";
	//	}
	//	// got a lock! - wait for 2s, then this thread prints "*"
	//	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	//	std::cout << "*\n";
	//	//t_m.unlock(); // 记得释放锁
	//};
	//std::thread threads[10];
	//// spawn 10 threads:
	//for (int i = 0; i < 10; ++i)
	//	//threads[i] = std::thread(f);
	//	threads[i] = std::thread(tf);
	//for (auto& th : threads)
	//	th.join();

	// 获取CPU核心数
	//cout << thread::hardware_concurrency() << endl;

	// promise和future
	//auto print_int = [](future<int>& fut) {
	//	int x = fut.get(); // 获取共享状态的值，如果promise状态不是ready，则阻塞.
	//	cout << "value: " << x << '\n'; // 打印 value: 10.
	//};
	//promise<int> prom; // 生成一个 std::promise<int> 对象.
	//future<int> fut = prom.get_future(); // 和 future 关联.
	//thread t(print_int, ref(fut)); // 将 future 交给另外一个线程t.
	//this_thread::sleep_for(chrono::seconds(3));
	//prom.set_value(10); // 设置共享状态的值, promise状态成为ready，此处和线程t保持同步.
	//t.join();
	//auto get_int = [](std::promise<int>& prom) {
	//	int x;
	//	std::cout << "Please, enter an integer value: ";
	//	std::cin.exceptions(std::ios::failbit);   // throw on failbit
	//	try {
	//		std::cin >> x;                        
	//		prom.set_value(x); // 设置共享状态值
	//	}
	//	catch (std::exception&) { // sets failbit if input is not int
	//		prom.set_exception(std::current_exception()); // 设置异常
	//	}
	//};
	//auto print_int = [](std::future<int>& fut) {
	//	try {
	//		int x = fut.get();
	//		std::cout << "value: " << x << '\n';
	//	}
	//	catch (std::exception& e) {
	//		std::cout << "[exception caught: " << e.what() << "]\n";
	//	}
	//};
	//std::promise<int> prom;
	//std::future<int> fut = prom.get_future();
	//std::thread th1(get_int, std::ref(prom));
	//std::thread th2(print_int, std::ref(fut));
	//th1.join();
	//th2.join();

	// package_task和future
	//auto countdown = [](int from, int to) {
	//	for (int i = from; i != to; --i) {
	//		std::cout << i << '\n';
	//		std::this_thread::sleep_for(std::chrono::seconds(1));
	//	}
	//	std::cout << "Finished!\n";
	//	return from - to;
	//};
	//std::packaged_task<int(int, int)> task(countdown); // 设置 packaged_task（封装一个可调用对象）
	//std::future<int> ret = task.get_future(); // 获得与 packaged_task 共享状态相关联的 future 对象.
	//std::thread th(std::move(task), 10, 0); // 创建一个新线程完成计数任务.
	//th.detach();
	//int value = ret.get(); // 等待任务完成并获取结果.（虽然detach了，但是主线程被阻塞，等待future返回结果）
	//std::cout << "The countdown lasted for " << value << " seconds.\n";
	//th.join();

	// async
	//auto is_prime = [](int x)
	//{
	//	for (int i = 2; i < x; ++i)
	//		if (x % i == 0)
	//			return false;
	//	return true;
	//};
	//// call function asynchronously:
	//std::future <bool> fut = std::async(is_prime, 444444443);
	//// do something while waiting for function to set future:
	//std::cout << "checking, please wait";
	//std::chrono::milliseconds span(100);
	//while (fut.wait_for(span) == std::future_status::timeout)
	//	std::cout << '.';
	//bool x = fut.get();         // retrieve return value
	//std::cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";

	// condition_variable
	//std::mutex mtx; // 全局互斥锁.
	//std::condition_variable cv; // 全局条件变量.
	//bool ready = false; // 全局标志位.
	//auto do_print_id = [&](int id)
	//{
	//	std::unique_lock<std::mutex> lck(mtx);
	//	while (!ready) // 如果标志位不为 true, 则等待...
	//		cv.wait(lck); // 当前线程被阻塞, 当全局标志位变为 true 之后,
	//	// 线程被唤醒, 继续往下执行打印线程编号id.
	//	std::cout << "thread " << id << '\n';
	//};
	//auto go = [&]()
	//{
	//	std::unique_lock <std::mutex> lck(mtx);
	//	ready = true; // 设置全局标志位为 true.
	//	cv.notify_all(); // 唤醒所有线程.
	//};
	//std::thread threads[10];
	//// spawn 10 threads:
	//for (int i = 0; i < 10; ++i)
	//	threads[i] = std::thread(do_print_id, i);
	//std::cout << "10 threads ready to race...\n";
	//go(); // go!
	//for (auto & th : threads)
	//	th.join();
	//std::mutex mtx;
	//std::condition_variable cv;
	//int cargo = 0;
	//auto shipment_available = [&]() // 一元谓词，判断是否可以消费
	//{
	//	return cargo != 0;
	//};
	//// 消费者线程.
	//auto consume = [&](int n)
	//{
	//	for (int i = 0; i < n; ++i) {
	//		std::unique_lock <std::mutex> lck(mtx);
	//		cv.wait(lck, shipment_available); // 一元谓词为false才wait
	//		std::cout << cargo << '\n';
	//		cargo = 0;
	//	}
	//};
	//std::thread consumer_thread(consume, 10); // 消费者线程.
	//// 主线程为生产者线程, 生产 10 个物品.
	//for (int i = 0; i < 10; ++i) {
	//	while (shipment_available()) // 有羊可以消费，则暂停生产者线程，消费者线程消费
	//		std::this_thread::yield();
	//	std::unique_lock <std::mutex> lck(mtx);
	//	cargo = i + 1;
	//	cv.notify_one(); // 通知消费者线程消费
	//}
	//consumer_thread.join();
	/*std::condition_variable cv;
	int value;
	std::cout << "Please, enter an integer (I'll be printing dots): \n";
	std::thread th([&]() {
		std::cin >> value;
		cv.notify_one();
	});
	std::mutex mtx;
	std::unique_lock<std::mutex> lck(mtx);
	while (cv.wait_for(lck, std::chrono::seconds(1)) == std::cv_status::timeout) {
		std::cout << '.';
		std::cout.flush();
	}
	std::cout << "You entered: " << value << '\n';
	th.join();*/

	// atomic_flag
	//std::atomic<bool> ready(false);    // can be checked without being set
	//std::atomic_flag winner = ATOMIC_FLAG_INIT;    // always set when checked
	//auto count1m = [&](int id)
	//{
	//	while (!ready) {
	//		std::this_thread::yield();
	//	} // 等待主线程中设置 ready 为 true.

	//	for (int i = 0; i < 1000000; ++i) {
	//	} // 计数.

	//	// 如果某个线程率先执行完上面的计数过程，则输出自己的 ID.
	//	// 此后其他线程执行 test_and_set 是 if 语句判断为 false，
	//	// 因此不会输出自身 ID.
	//	if (!winner.test_and_set()) {
	//		std::cout << "thread #" << id << " won!\n";
	//	}
	//	/*
	//	test_and_set() 函数检查 std::atomic_flag 标志，
	//	如果 std::atomic_flag 之前没有被设置过，
	//	则设置 std::atomic_flag 的标志，
	//	并返回先前该 std::atomic_flag 对象是否被设置过，
	//	如果之前 std::atomic_flag 对象已被设置，
	//	则返回 true，否则返回 false。
	//	*/
	//};
	//std::vector<std::thread> threads;
	//std::cout << "spawning 10 threads that count to 1 million...\n";
	//for (int i = 1; i <= 10; ++i)
	//	threads.push_back(std::thread(count1m, i));
	//ready = true;
	//for (auto & th : threads)
	//	th.join();
	//std::atomic_flag lock = ATOMIC_FLAG_INIT;
	//auto f = [&](int n)
	//{
	//	// 实现自旋锁
	//	for (int cnt = 0; cnt < 10; ++cnt) {
	//		while (lock.test_and_set(std::memory_order_acquire))  // acquire lock
	//		{
	//		}; // spin（自旋）
	//		std::cout << "Output from thread " << n << '\n';
	//		lock.clear(std::memory_order_release);               // release lock
	//	}
	//};
	//std::vector<std::thread> v;
	//for (int n = 0; n < 10; ++n) {
	//	v.emplace_back(f, n);
	//}
	//for (auto& t : v) {
	//	t.join();
	//}


	return 0;
}