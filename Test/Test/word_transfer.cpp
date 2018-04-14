#include "global.h"

map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 0) {
			trans_map[key] = value.substr(1);
		}
		else {
			throw runtime_error("No rules for " + key);
		}
	}
	return trans_map;
}

const string &transform(const string &s, const map<string, string> &m) {
	auto map_it = m.find(s);
	if (map_it != m.end()) {
		return map_it->second;
	}
	else {
		return s;
	}
}

void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);
	string line;
	while (getline(input, line)) {
		istringstream iss(line);
		bool first_word = true;
		string word;
		while (iss >> word) {
			if (first_word) {
				first_word = false;
			}
			else {
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}