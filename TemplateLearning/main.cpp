#include <bits/stdc++.h>

using namespace std;

// template <typename T, int N, template <typename U, typename Allocator = allocator<U>> class Container = vector>
// class MyArray {
// public:
//     int size() const { return N; }

// private:
//     Container<T> data_[N];
// };

// void my_print() {}

// template <typename T, typename... Types> void my_print(const T &val, const Types &...args) {
//     cout << val << "\n";
//     my_print(args...);
// }

// template <typename T, typename U> class IsConvertible {
// private:
//     using TrueType = char;
//     using FalseType = struct { char unused_field[2]; };

//     static T get_T();
//     static TrueType test(U);
//     static FalseType test(...);

// public:
//     static constexpr bool value = sizeof(test(get_T())) == sizeof(TrueType);
// };
// template <typename T> class IsClass {
// private:
//     using TrueType = char;
//     using FalseType = struct { char unused_field[2]; };

//     template <typename U> static TrueType test(int U::*);

//     template <typename U> static FalseType test(...);

// public:
//     static constexpr bool value = sizeof(test<T>(nullptr)) == sizeof(TrueType);
// };

// template <typename T, typename U> class StrongerType {
// private:
//     static T get_T();
//     static U get_U();

// public:
//     using type = decltype(true ? get_T() : get_U());
// };

// template <typename T, typename U> typename StrongerType<T, U>::type my_add(T t, U u) { return t + u; }

// template <typename T, typename... Ts> void func(const T &val, const Ts &...vals) {
//     // cout << sizeof...(Ts) << endl;
//     array<T, sizeof...(Ts) + 1> arr = {val, vals...};
//     // cout << arr.size() << endl;
//     for (int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// // int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// // int lcm(int a, int b) { return a * b / gcd(a, b); }

// template <int A, int B> struct MyGCD { static constexpr int value = MyGCD<B, A % B>::value; };
// template <int A> struct MyGCD<A, 0> { static constexpr int value = A; };
// template <int A, int B> struct MyLCM { static constexpr int value = A * B / MyGCD<A, B>::value; };

// // decltype(auto) f(auto a) { return a; }
// // void f(auto &a) { a += 1; }
// // void f(auto &&a) { a += 1; }
// template <typename T> T get_type();
// template <typename T> decltype(auto) f(T &&a) {
//     get_type<decltype(a)>();
//     return a;
// }

// class MyClass {
// private:
//     unordered_map<int, string> map_;

// public:
//     MyClass() {
//         // cout << "MyClass()\n";
//     }
//     MyClass(initializer_list<typename decltype(map_)::value_type> init) : map_(init) {}
//     ~MyClass() {
//         // cout << "~MyClass()\n";
//     }

//     MyClass(const MyClass &) = default;
//     // { cout << "MyClass(const MyClass &)\n"; }
//     MyClass &operator=(const MyClass &) = default;
//     // { cout << "MyClass &operator=(const MyClass &)\n"; }

//     MyClass(MyClass &&) = default;
//     // { cout << "MyClass(MyClass &&)\n"; }
//     MyClass &operator=(MyClass &&) = default;
//     // { cout << "MyClass &operator=(MyClass &&)\n"; }

//     void print() const {
//         for (const auto &[key, value] : map_) {
//             printf("{%d: %s} ", key, value.c_str());
//         }
//         cout << endl;
//     }
// };

// template <typename T>
// void Combination(const vector<T> &in, int idx, int m, vector<T> &result, vector<vector<T>> &results) {
//     if (m == 0) {
//         results.push_back(result);
//         return;
//     }

//     for (int i = idx; i < in.size(); i++) {
//         result.push_back(in[i]);
//         Combination(in, i + 1, m - 1, result, results);
//         result.pop_back();
//     }
// }

int main(int argc, char *argv[]) {

    // vector<int> a = {1, 2, 3, 4, 5};
    // vector<int> b;
    // b.reserve(2);
    // vector<vector<int>> results;
    // Combination(a, 0, 2, b, results);
    // for (auto &&result : results) {
    //     for (int i : result) {
    //         cout << i << " ";
    //     }
    //     cout << "\n";
    // }

    // unordered_map<int, string> m = {{1, "one"}};
    // for (const auto &kv : m) {
    //     printf("{%d: %s} ", kv.first, kv.second.c_str());
    // }
    // cout << endl;

    // auto it = m.begin();
    // it->second = "two";
    // for (const auto &kv : m) {
    //     printf("{%d: %s} ", kv.first, kv.second.c_str());
    // }
    // cout << endl;

    // for (auto &&kv : m) {
    //     string temp;
    //     transform(kv.second.begin(), kv.second.end(), back_inserter(temp), [](char c) { return toupper(c); });
    //     kv.second = temp;
    //     printf("{%d: %s} ", kv.first, kv.second.c_str());
    // }

    // MyClass my_class = {{1, "one"}}, my_class_temp = {{1, "one"}, {2, "two"}};
    // my_class.print();
    // my_class_temp.print();
    // cout << endl;

    // MyClass my_class_copy(my_class_temp);
    // my_class_copy.print();
    // my_class_copy = my_class;
    // my_class_copy.print();
    // my_class.print();
    // my_class_temp.print();
    // cout << endl;

    // MyClass my_class_copy1(std::move(my_class_temp));
    // my_class_copy1.print();
    // my_class_copy1 = std::move(my_class);
    // my_class_copy1.print();
    // my_class.print();
    // my_class_temp.print();
    // cout << endl;

    // cout << f(1) << endl;
    // double d = 0;
    // f(d);
    // cout << d << endl;

    // int a = 0;
    // f(a) = 1;
    // cout << a << endl;
    // int a = 0;
    // f(a);
    // get_type<decltype(f(a))>();

    // auto f = [](auto a, auto b) { return a + b; };
    // auto r = f(1, 2);
    // cout << r << endl;
    // auto r1 = f(string("Hello "), string("World!"));
    // cout << r1 << endl;

    // auto f1 = [](auto &a) -> decltype(auto) { return a; };
    // int a = 0;
    // f1(a) = 1;
    // cout << a << endl;

    // auto f2 = [](auto arr) -> decltype(auto) { return arr[0]; };
    // int arr[] = {0};
    // f2(arr) = 1;
    // cout << arr[0] << endl;

    // tuple<int, string, double> student(0, "Cong", 100.0);
    // printf("id: %d, name: %s, score: %f\n\n", get<0>(student), get<1>(student).c_str(), get<2>(student));

    // int id = 1;
    // string name = "Qi";
    // double score = 100;
    // tuple<int &, string &, double &> student1(id, name, score);
    // printf("id: %d, name: %s, score: %f\n", get<0>(student1), get<1>(student1).c_str(), get<2>(student1));
    // id = 2;
    // name = "Xiao";
    // score = 99;
    // printf("id: %d, name: %s, score: %f\n", get<0>(student1), get<1>(student1).c_str(), get<2>(student1));
    // tie(id, name, score) = student;
    // printf("id: %d, name: %s, score: %f\n\n", id, name.c_str(), score);

    // // auto [ID, NAME, SCORE] = student;
    // auto &[ID, NAME, SCORE] = student;
    // printf("id: %d, name: %s, score: %f\n", ID, NAME.c_str(), SCORE);
    // ID = 3;
    // NAME = "Ying";
    // SCORE = 98;
    // printf("id: %d, name: %s, score: %f\n\n", get<0>(student), get<1>(student).c_str(), get<2>(student));

    // int a[2] = {1, 2};
    // auto [a1, a2] = a;
    // printf("a1: %d, a2: %d\n", a1, a2);
    // a1 = 3;
    // a2 = 4;
    // printf("a1: %d, a2: %d\n", a[0], a[1]);
    // auto &[a1_ref, a2_ref] = a;
    // printf("a1: %d, a2: %d\n", a1_ref, a2_ref);
    // a1_ref = 3;
    // a2_ref = 4;
    // printf("a1: %d, a2: %d\n", a[0], a[1]);

    // cout << MyGCD<2, 10>::value << endl;
    // cout << MyGCD<10, 2>::value << endl;
    // cout << MyLCM<2, 10>::value << endl;
    // cout << MyLCM<14, 10>::value << endl;

    // cout << gcd(2, 10) << endl;
    // cout << gcd(10, 2) << endl;
    // cout << lcm(10, 2) << endl;
    // cout << gcd(5, 10) << endl;
    // cout << gcd(10, 5) << endl;
    // cout << lcm(10, 5) << endl;
    // cout << gcd(100, 35) << endl;
    // cout << lcm(100, 35) << endl;

    // func(1, 2, 3, 4);
    // func(true, false, true);
    // func(string("Hello"), string("World"), string("!"));
    // func("Hello World", 1, 2, 3);
    // func(true, 1, 1.0, "Hello World!");

    // cout << my_add(1, 1.1) << "\n";

    // cout << typeid(StrongerType<char, int>::type).name() << "\n";
    // cout << typeid(StrongerType<int, char>::type).name() << "\n";
    // cout << typeid(StrongerType<int, double>::type).name() << "\n";

    // cout << boolalpha;
    // cout << IsClass<int>::value << "\n";
    // cout << IsClass<string>::value << "\n";
    // cout << is_class<int>::value << "\n";
    // cout << is_class<string>::value << "\n";

    // cout << IsConvertible<int, double>::value << "\n";
    // cout << IsConvertible<double, int>::value << "\n";
    // cout << IsConvertible<int, string>::value << "\n";
    // cout << is_convertible<int, double>::value << "\n";
    // cout << is_convertible<double, int>::value << "\n";
    // cout << is_convertible<int, string>::value << "\n";

    // my_print(true, 'a', 100, 3.14, "Hello World!");

    // MyArray<int, 3> arr;
    // cout << arr.size() << "\n";

    return 0;
}
