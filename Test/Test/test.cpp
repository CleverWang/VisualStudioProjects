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

	// const��������
	// const double pi = 3.1415;
	/*cout << pi << endl; // pi�Ƕ����ڱ���ļ��еĳ���

	const double &PI = pi; // �Գ��������ã����԰󶨷ǳ������󣬵��ǳ�������ֻ���öԳ������������󶨣�
	cout << PI << endl;

	const double *ptr_pi = &pi; // ָ������ָ�루����ָ��ǳ������󣬵��ǳ�������ֻ����ָ������ָ��ָ��
	cout << *ptr_pi << endl;

	extern double sqrt_2; // �����ڱ���ļ��еı���
	cout << sqrt_2 << endl;

	const double *ptr_sqrt_2 = &sqrt_2;
	cout << *ptr_sqrt_2 << endl;

	double *const sqrt_2_ptr = &sqrt_2; // ����ָ��
	cout << *sqrt_2_ptr << endl;

	const double *const pi_ptr = &pi; // ָ�����ĳ���ָ��
	cout << *pi_ptr << endl;*/

	// auto and decltype
	/*auto var = 3.14; // �Զ��ƶ�����
	cout << var << endl;
	decltype(var) *ptr_var = &var; // decltype���������ڱ��ʽ������
	cout << *ptr_var << endl;
	decltype((var)) ref_var = var; // decltype((variable))��������Զ�����ã������ʼ��
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
	/*auto len = line.size(); // ��������Ϊstring::size_type���޷�����������
	cout << len << endl;*/
	// range for����Χfor�� in string
	//ͳ�Ʊ����Ÿ���
	/*string str = "hello world!!!";
	decltype(str.size()) punct_cnt = 0;
	for (auto c : str)
	{
		if (ispunct(c))
			punct_cnt++;
	}
	cout << punct_cnt << " punctuation characters in \"" << str << "\"" << endl;*/
	// ʹ�÷�Χfor����string
	/*for (auto &c : str)
	{
		c = toupper(c);
	}
	cout << str << endl;*/

	// vector
	// �б��ʼ���ͷ�Χfor
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

	// ָ�����飬ָ�������ָ�룬���������
	/*int nums[] = { 0,1,2,3,4,5,6,7,8,9 };
	constexpr size_t cnt = 10;
	int *num_ptrs[cnt]; // ָ������
	for (unsigned i = 0; i < cnt; ++i)
		num_ptrs[i] = &(nums[i]);
	for (auto i : num_ptrs)
		cout << *i << " ";
	cout << endl;
	int(*nums_ptr)[cnt] = &nums; // ָ�������ָ��
	for (unsigned i = 0; i < cnt; ++i)
		cout << (*nums_ptr)[i] << " ";
	cout << endl;
	int(&nums_ref)[cnt] = nums; // ���������
	for (auto i : nums_ref)
		cout << i << " ";
	cout << endl;
	int *(&num_ptrs_ref)[cnt] = num_ptrs; // ָ�����������
	for (auto i : num_ptrs_ref)
		cout << *i << " ";
	cout << endl;*/

	// �����begin��end
	/*int nums[] = { 0,1,2,3,4,5,6,7,8,9 };
	int *pbegin = begin(nums), *pend = end(nums);
	for (auto it = pbegin; it != pend; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;*/

	// ��Χfor�����ά����
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

	// ��ֵ->�������ݣ��ڴ��е�λ�ã�    ��ֵ->�����ֵ�����ݣ�
	/*int a = 123;
	int *ptr_a = &a;
	decltype(*ptr_a) b = a; // ��ָ��������ֵ��������Ϊint&
	cout << b << endl;
	decltype(&ptr_a) ptr_ptr_a = &ptr_a; // ȡ��ַ������ֵ��������Ϊint**
	cout << **ptr_ptr_a << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(ptr_a) << endl;
	cout << sizeof(ptr_ptr_a) << endl;*/

	// ��ʽ����ת����cast_name<type>(expr)    �ɰ汾��type(expr)��(type)expr
	// cast_name:static_cast, dynamic_cast, const_cast, reinterpret_cast
	// static_cast:��̬����ת�������ô���ײ�ָ��
	/*int a = 3, b = 2;
	double res = a / b;
	cout << res << endl;
	res = static_cast<double>(a) / b;
	cout << res << endl;
	void *ptr = &res;
	double *ptr_res = static_cast<double*>(ptr);
	cout << *ptr_res << endl;
	// const_cast:��������ת����ֻ����ײ�ָ�루��ָ������ָ��ת����ָ��ǳ�����ָ�룬��֮��Ȼ��
	const int cst = 123;
	const int *cptr_cst = &cst;
	cout << *cptr_cst << endl;
	int *ptr_cst = const_cast<int*>(cptr_cst); // ת��������޸���ָ��Ķ�����
	cout << *ptr_cst << endl;
	*ptr_cst = 1234;
	cout << *ptr_cst << endl;
	// reinterpret_cast:���½�������ת��
	int t = 65;
	int *ptr_t = &t;
	char *char_ptr_t = reinterpret_cast<char*>(ptr_t); // ���½��ͳ�ָ���ַ���ָ��
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

	// �ֲ���̬��������
	/*for (size_t i = 0; i < 10; ++i) {
		cout << "���ô�����" << func_call_times() << endl;
	}*/


	// initializer_list
	/*err_msg({ "func_x", "error", "bad!!!!" });
	err_msg({ "func_y","okay!!!!" });*/

	// ����ָ�������ָ��
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

	// const_cast���ں�������
	/*cout << shorter_string("hi", "hello") << endl;
	string s1 = "hi", s2 = "hello";
	string s = shorter_string(s1, s2);
	cout << s << endl;
	s[0] = 'H';
	cout << s << endl;*/

	// Ĭ�ϲ���
	/*print_info("Window");
	print_info("Window1",1000);
	print_info("Window2", 1000,2000);*/

	// constexpr����
	/*constexpr double result = x_pi_value(3, pi_value());
	cout << setprecision(10) << result << endl;*/

	// assert��NDEBUG
	/*cout << "hello world!" << endl;
	assert(1 + 1 == 3);
	#ifndef NDEBUG
		cout << __FILE__ << ": function " << __func__ << " error!" << endl;
		cout << "\tat line: " << __LINE__ << endl;
		cout << "\t\tcompiled on " << __DATE__ << " at " << __TIME__ << endl;
	#endif // !NDEBUG*/

	// ����ָ��
	/*const string& (*func_ptr)(const string &s1, const string &s2) = shorter_string;
	auto s = func_ptr("Hi", "Hello");
	cout << s << endl;*/

	// �������β�
	//cout << func_as_param("hi", "hello", shorter_string) << endl;

	// ���غ���ָ��
	/*cout << func_ptr_1()(-10) << endl;
	cout << func_ptr_2()(-10) << endl;
	cout << func_ptr_3()(-10) << endl;
	cout << func_ptr_4()(-10) << endl;*/

	// ����Sales_data_struct��
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

	// ����Sales_data��
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

	// ����ͨ�����캯����ʼֵ�б���г�ʼ��
	/*ConstRef cr(520);
	cr.print();*/

	// Screen�����
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

	// Window_mgr�����
	/*Window_mgr w;
	cout << "Added Screen at " << w.addScreen(s) << endl;
	cout << "Added Screen at " << w.addScreen(cs) << endl;
	w.display_screens(cout);
	w.clear(0);
	w.clear(1);
	w.clear(2);
	w.display_screens(cout);*/

	// IO����״̬
	/*auto status = cin.rdstate(); // ��ȡ����״̬��־
	cout << status << endl << endl;
	cout << cin.badbit << endl;
	cout << cin.bad() << endl;
	cout << cin.goodbit << endl;
	cout << cin.good() << endl;
	cout << cin.failbit << endl;
	cout << cin.fail() << endl;
	cout << cin.eofbit << endl;
	cout << cin.eof() << endl;
	cin.clear(); // �������λ������״̬��־
	cin.setstate(status); // ��������״̬��־*/

	// IO������
	/*cout << "Hello World!!!" << endl; // ���������ˢ�»�����
	cout << "Hello World!!!" << flush; // ����ˢ�»�����
	cout << "Hello World!!!" << ends; // ����ո���ˢ�»�����
	cout << unitbuf; // ���û�����Ϊ����ˢ��
	cout << "Hello World!!!";
	cout << nounitbuf; // �ָ������Ļ��巽ʽ*/

	// �����������Խ��������������������������������������������������������ǰһ����ˢ�¹�������
	/*cin.tie(&cout); // Ĭ��cin��cout�������˴�������ʾ��
	ostream *old_tie = cin.tie(nullptr); // ������й���
	cin.tie(&cerr); // ������cerr
	cin.tie(old_tie); // �ָ���ʼ����*/

	// �ļ�������
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

	// �ַ���������
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

	// ����������ڵ�������ָԪ��֮ǰ���в��룬����ָ�����ĵ�һ��Ԫ�صĵ�������
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
	// emplaceʹ�ù���������Ԫ�ؽ��в���
	sdq.emplace_front(3, 'o');
	sdq.emplace_back(4, 'u');
	sdq.emplace(sdq.end(), 5, 'i');
	for (const auto &item : sdq) {
		cout << item << endl;
	}*/

	// ����Ԫ��
	/*vector<int> ve = { 0,1,2,3,4 };
	cout << ve.front() << endl;
	cout << ve.back() << endl;
	cout << ve[1] << endl;
	cout << ve.at(1) << endl;*/

	// ɾ��Ԫ�أ�ɾ����������ָԪ�غ����Ԫ�أ�����ָ��ɾ��Ԫ�غ����Ԫ�صĵ�������
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

	// forword_list��������������������ԣ����в�������after��
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

	// string����
	/*string nums("0123456789"), name("hgs8g9hhh9ga53sdf0");
	string::size_type pos = 0;
	while ((pos = name.find_first_of(nums, pos)) != string::npos) {
		cout << "Found number " << name[pos] << " at " << pos << endl;
		++pos;
	}*/

	// ��ֵת��
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

	// ����������
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
		auto ret = wordcount.insert({ word,1 }); // ����һ��pair��<ָ�����Ԫ�صĵ�����,bool>
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
	if (wordcount.erase(removal_word)) { // ����ɾ����Ԫ�ظ���
		cout << "ok: \"" << removal_word << "\" removed!" << endl;
	}
	else {
		cout << "oops: \"" << removal_word << "\" not found!" << endl;
	}
	for (const auto &item : wordcount) {
		cout << "\"" << item.first << "\" occurs " << item.second << ((item.second > 1) ? " times" : " time") << endl;
	}*/

	// ���ҹؼ��ַ�Χ
	/*multimap<int, string> mset{ {0,"h"},{1,"e"},{2,"l"},{2,"l"},{3,"o"} };
	for (auto beg = mset.lower_bound(2), end = mset.upper_bound(2); beg != end; ++beg) {
		cout << beg->first << ": " << beg->second << endl;
	}
	for (auto range = mset.equal_range(2); range.first != range.second; ++range.first) {
		cout << range.first->first << ": " << range.first->second << endl;
	}*/

	/*ifstream map_file("E:\\test\\map_file.txt"), input("E:\\test\\transform_input.txt");
	word_transform(map_file, input);*/

	// ����StrBlob
	/*StrBlob b1;
	{
		StrBlob b2{ "I","love" };
		b1 = b2;
		b2.push_back("you");
		cout << "b2: " << b2.size() << endl;
	}
	cout << "b1: " << b1.size() << endl;*/

	// shared_ptr��new
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

	// ����StrBlobPtr
	/*StrBlob sb{ "I","love","you" };
	for (StrBlobPtr b = sb.begin(), e = sb.end(); !b.equal(e); b.incr()) {
		cout << b.deref() << " ";
	}
	cout << endl;*/

	// ��̬����������ָ��
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

	// ����TextQuery
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

	// ���Կ������캯��������һ�������ʼ����һ��ͬ���͵Ķ���ʱ�������ÿ������캯����
	/*Sales_data ad("1", 1, 1);
	Sales_data ad1 = ad;
	print(cout, ad1) << endl;*/

	// ���Կ�����ֵ�����������һ������ֵ��һ��ͬ���͵Ķ���ʱ�������ÿ�����ֵ�������
	/*Sales_data ad1("1", 1, 1), ad2("2", 2, 2);
	print(cout, ad1) << endl;
	ad1 = ad2;
	print(cout, ad1) << endl;*/

	// ����HasPtr
	/*HasPtr hp("test");
	hp.print_HasPtr(cout) << endl;
	auto p = [](HasPtr hp) {HasPtr ret = hp; return ret; }; // ���û�ж��忽�����캯����hp��ret��ִ��������spָ����ڴ汻�ͷ�����
	p(hp);
	HasPtr hp1 = hp; // ���û�ж��忽�����캯����hp1��hp��ָ����ɾ������Ч�ڴ�ռ�
	hp1.print_HasPtr(cout) << endl;*/

	// ����NoCopy
	/*NoCopy nc, nc1("test");
	// NoCopy nc2 = nc; �޷����п�����ʼ��������ֹ
	nc.print_NoCopy(cout) << endl;
	nc1.print_NoCopy(cout) << endl;
	// nc = nc1; �޷����и�ֵ����������ֹ*/

	// ������ָ���HasPtr
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

	// ����StrVec
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

	// ��������������汾Sales_data��
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

	// ��������������汾��StrBlobPtr
	/*StrBlob sb = { "I","love","you" };
	for (StrBlobPtr iter = sb.begin(); iter != sb.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;*/

	// ����PrintString
	/*PrintString ps;
	ps("hello");
	ps("world");
	cout << endl;
	vector<string> ve = { "I","love","you" };
	for_each(ve.begin(), ve.end(), PrintString(cout, '\n'));*/

	// function����
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

	// ����SmallInt��
	/*SmallInt si = 2; // ���ù��캯��SmallInt(int)
	cout << si + 4 << endl; // si��ʽ����ת����int(2)
	si = 0; // 0��ʽת����SmallInt��0����Ȼ����ø�ֵ���������
	cout << static_cast<bool>(si) << endl;
	if (!si) {
		cout << "Hello wordl!!!" << endl;
	}*/

	// ����Quote��
	/*vector<shared_ptr<Quote>> ve;
	ve.push_back(make_shared<Quote>("0", 50));
	ve.push_back(make_shared<Bulk_quote>("1", 50, 10, 0.25));
	for (const auto &ptr : ve) {
		cout << ptr->net_price(15) << endl;
	}*/

	/*cout << "compare 1 and 2: " << compare(1, 2) << endl;
	cout << "compare \"hi\" and \"hello\": " << compare("hi", "hello") << endl;*/

	// ����Blob��
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

	// ����ģ��������
	/*char s1[] = "hi", s2[] = "hello";
	const char *ps1 = "hi", *ps2 = "hello";
	cout << "char []: " << compare(s1, s2) << endl;
	cout << "char *: " << compare(ps1, ps2) << endl;*/

	// ����ת��
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

	// ������ʽ
	/*string p("[^c]ei");
	p = "[[:alpha:]]*" + p + "[[:alpha:]]*";
	regex r(p);
	smatch results;
	string test = "receipt freind theif receive";
	if (regex_search(test, results, r))
	{
		cout << results.str() << endl;
	}*/
	//regex re("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase); // ���Դ�Сд
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
	//	auto pos = it->prefix().length(); // prefix����ʾѰ����ƥ�䴮��ǰ����ַ�����ssub_match����
	//	pos = pos > 10 ? pos - 10 : 0;
	//	cout << it->prefix().str().substr(pos) << "\n\t>>>"
	//		<< it->str() << "<<<\n" << it->suffix().str().substr(0, 10) << endl; // suffix����ʾѰ����ƥ�䴮�ĺ�����ַ�����ssub_match����
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
	//string fmt = "$2.$5.$7"; // $n��ʾ��n���ӱ��ʽ
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

	// �����
	/*uniform_int_distribution<unsigned> u(1, 10); // ����unsigned�ֲ�
	default_random_engine e; // �����������
	cout << "min: " << e.min() << " max: " << e.max() << " max unsigned:" << (unsigned)(-1) << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << u(e) << " ";
	}
	cout << endl;*/
	// ���������������������static�Ļ���ÿ�ε���������ͬ���У������static���Ա���״̬
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
	//uniform_real_distribution<double> u(0, 1); // ����ʵ���ֲ�
	//default_random_engine e;
	//for (size_t i = 0; i < 10; i++)
	//{
	//	cout << u(e) << " ";
	//}
	//cout << endl;

	// �źŴ���
	//auto sighandler = [](int signum) // �źŴ�����
	//{
	//	cout << "Interrupt signal(" << signum << ") recieved!" << endl;
	//	exit(signum);
	//};
	//signal(SIGINT, sighandler); // �����źź��źŴ�����
	//int cnt = 0;
	//while (true)
	//{
	//	if (cnt == 3)
	//		raise(SIGINT);
	//	cout << "Sleeping..." << endl;
	//	Sleep(1000);
	//	++cnt;
	//}

	// ���߳�std::thread
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
	//thread t2(f1, n + 1); // ��ֵ
	//thread t3(f2, std::ref(n)); // ������
	//thread t4(std::move(t3)); // �ƶ���t3�����Ч��t4��������
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
	//// �ɱ�joinable��thread�����������������֮ǰ�����߳�join���߽�������Ϊdetached
	//t2.join();
	//t4.join();
	//cout << "Final value of n is " << n << endl;
	////t2.detach(); // �����̣߳����߳̽��������߳����û���������߳̽�����ִ��
	////t4.detach();
	////this_thread::sleep_for(chrono::seconds(10));

	// �������std::mutex
	//mutex m;
	//timed_mutex t_m;
	//auto f = [&m]()
	//{
	//	/* 
	//	ֻ�������õĻ������ϵ���lock()�������ȡ����������������
	//	�������ڶ���������
	//		std::defer_lock�ӻ���������ʼ�����������lock()������������Ҫ���ڵ���lock()��ȡ��
	//		std::try_to_lock��������������try_lock()�����������̣߳�Ȼ�����owns_lock()��operator==�ж��Ƿ�������
	//		std::adopt_lock���߳��Ѿ�������unique_lockֻ�ǻ�ȡ���Ĺ���Ȩ
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
	//	// �ȴ�ָ��ʱ���������������̴߳�������״̬�����ʱ������δ�õ���������false
	//	while (!lck.try_lock_for(std::chrono::milliseconds(200))) { 
	//		std::cout << "-";
	//	}
	//	// got a lock! - wait for 2s, then this thread prints "*"
	//	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	//	std::cout << "*\n";
	//	//t_m.unlock(); // �ǵ��ͷ���
	//};
	//std::thread threads[10];
	//// spawn 10 threads:
	//for (int i = 0; i < 10; ++i)
	//	//threads[i] = std::thread(f);
	//	threads[i] = std::thread(tf);
	//for (auto& th : threads)
	//	th.join();

	// ��ȡCPU������
	//cout << thread::hardware_concurrency() << endl;

	// promise��future
	//auto print_int = [](future<int>& fut) {
	//	int x = fut.get(); // ��ȡ����״̬��ֵ�����promise״̬����ready��������.
	//	cout << "value: " << x << '\n'; // ��ӡ value: 10.
	//};
	//promise<int> prom; // ����һ�� std::promise<int> ����.
	//future<int> fut = prom.get_future(); // �� future ����.
	//thread t(print_int, ref(fut)); // �� future ��������һ���߳�t.
	//this_thread::sleep_for(chrono::seconds(3));
	//prom.set_value(10); // ���ù���״̬��ֵ, promise״̬��Ϊready���˴����߳�t����ͬ��.
	//t.join();
	//auto get_int = [](std::promise<int>& prom) {
	//	int x;
	//	std::cout << "Please, enter an integer value: ";
	//	std::cin.exceptions(std::ios::failbit);   // throw on failbit
	//	try {
	//		std::cin >> x;                        
	//		prom.set_value(x); // ���ù���״ֵ̬
	//	}
	//	catch (std::exception&) { // sets failbit if input is not int
	//		prom.set_exception(std::current_exception()); // �����쳣
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

	// package_task��future
	//auto countdown = [](int from, int to) {
	//	for (int i = from; i != to; --i) {
	//		std::cout << i << '\n';
	//		std::this_thread::sleep_for(std::chrono::seconds(1));
	//	}
	//	std::cout << "Finished!\n";
	//	return from - to;
	//};
	//std::packaged_task<int(int, int)> task(countdown); // ���� packaged_task����װһ���ɵ��ö���
	//std::future<int> ret = task.get_future(); // ����� packaged_task ����״̬������� future ����.
	//std::thread th(std::move(task), 10, 0); // ����һ�����߳���ɼ�������.
	//th.detach();
	//int value = ret.get(); // �ȴ�������ɲ���ȡ���.����Ȼdetach�ˣ��������̱߳��������ȴ�future���ؽ����
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
	//std::mutex mtx; // ȫ�ֻ�����.
	//std::condition_variable cv; // ȫ����������.
	//bool ready = false; // ȫ�ֱ�־λ.
	//auto do_print_id = [&](int id)
	//{
	//	std::unique_lock<std::mutex> lck(mtx);
	//	while (!ready) // �����־λ��Ϊ true, ��ȴ�...
	//		cv.wait(lck); // ��ǰ�̱߳�����, ��ȫ�ֱ�־λ��Ϊ true ֮��,
	//	// �̱߳�����, ��������ִ�д�ӡ�̱߳��id.
	//	std::cout << "thread " << id << '\n';
	//};
	//auto go = [&]()
	//{
	//	std::unique_lock <std::mutex> lck(mtx);
	//	ready = true; // ����ȫ�ֱ�־λΪ true.
	//	cv.notify_all(); // ���������߳�.
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
	//auto shipment_available = [&]() // һԪν�ʣ��ж��Ƿ��������
	//{
	//	return cargo != 0;
	//};
	//// �������߳�.
	//auto consume = [&](int n)
	//{
	//	for (int i = 0; i < n; ++i) {
	//		std::unique_lock <std::mutex> lck(mtx);
	//		cv.wait(lck, shipment_available); // һԪν��Ϊfalse��wait
	//		std::cout << cargo << '\n';
	//		cargo = 0;
	//	}
	//};
	//std::thread consumer_thread(consume, 10); // �������߳�.
	//// ���߳�Ϊ�������߳�, ���� 10 ����Ʒ.
	//for (int i = 0; i < 10; ++i) {
	//	while (shipment_available()) // ����������ѣ�����ͣ�������̣߳��������߳�����
	//		std::this_thread::yield();
	//	std::unique_lock <std::mutex> lck(mtx);
	//	cargo = i + 1;
	//	cv.notify_one(); // ֪ͨ�������߳�����
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
	//	} // �ȴ����߳������� ready Ϊ true.

	//	for (int i = 0; i < 1000000; ++i) {
	//	} // ����.

	//	// ���ĳ���߳�����ִ��������ļ������̣�������Լ��� ID.
	//	// �˺������߳�ִ�� test_and_set �� if ����ж�Ϊ false��
	//	// ��˲���������� ID.
	//	if (!winner.test_and_set()) {
	//		std::cout << "thread #" << id << " won!\n";
	//	}
	//	/*
	//	test_and_set() ������� std::atomic_flag ��־��
	//	��� std::atomic_flag ֮ǰû�б����ù���
	//	������ std::atomic_flag �ı�־��
	//	��������ǰ�� std::atomic_flag �����Ƿ����ù���
	//	���֮ǰ std::atomic_flag �����ѱ����ã�
	//	�򷵻� true�����򷵻� false��
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
	//	// ʵ��������
	//	for (int cnt = 0; cnt < 10; ++cnt) {
	//		while (lock.test_and_set(std::memory_order_acquire))  // acquire lock
	//		{
	//		}; // spin��������
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