#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct token {
	string type, lexem;
	token(string type, string lexem) : type(type), lexem(lexem) {}
};

vector<token> Result;
unordered_map<string, string> Mp = { {"Absolute", "keyword"}, {"array", "keyword"}, {"asm", "keyword"}, {"begin", "keyword"}, {"const", "keyword"}, {"constructor", "keyword"}, {"destructor", "keyword"}, {"div", "keyword"}, {"do", "keyword"}, {"downto", "keyword"}, {"else", "keyword"}, {"end", "keyword"}, {"file", "keyword"}, {"function", "keyword"}, {"implementation", "keyword"}, {"in", "keyword"}, {"inherited", "keyword"}, {"inline", "keyword"}, {"interface", "keyword"}, {"label", "keyword"}, {"nil", "keyword"}, {"object", "keyword"}, {"of", "keyword"}, {"operator", "keyword"}, {"packed", "keyword"}, {"procedure", "keyword"}, {"program", "keyword"}, {"record", "keyword"}, {"reintroduce", "keyword"}, {"repeat", "keyword"}, {"self", "keyword"}, {"string", "keyword"}, {"then", "keyword"}, {"to", "keyword"}, {"type", "keyword"}, {"unit", "keyword"}, {"uses", "keyword"}, {"var", "keyword"}, {"and", "operator"}, {"case", "operator"}, {"for", "operator"}, {"goto", "operator"}, {"if", "operator"}, {"mod", "operator"}, {"not", "operator"}, {"or", "operator"}, {"set", "operator"}, {"shl", "operator"}, {"shr", "operator"}, {"until", "operator"}, {"while", "operator"}, {"with", "operator"}, {"xor", "operator"}, {"+", "operator"}, {"-", "operator"}, {"*", "operator"}, {"/", "operator"}, {"=", "operator"}, {"<", "operator"}, {">", "operator"}, {"(", "operator"}, {")", "operator"}, {":", "operator"}, {"^", "operator"}, {"@", "operator"}, {"$", "operator"}, {"#", "operator"}, {"&", "operator"}, {"%", "operator"}, {"<<", "operator"}, {">>", "operator"}, {"**", "operator"}, {"<>", "operator"}, {"><", "operator "}, {"<=", "operator "}, {">=", "operator "}, {":=", "operator"}, {"+=", "operator"}, {"-=", "operator"}, {"*=", "operator"}, {"/=", "operator"}, {"(*", "delimiter"}, {"*)", "delimiter"}, {"(.", "delimiter"}, {".)", "delimiter"}, {"//", "delimiter"}, {"{", "delimiter"}, {"}", "delimiter"}, {"[", "delimiter"}, {"]", "delimiter"}, {".", "delimiter"}, {",", "delimiter"} };
string source_code; // remove it from here

bool letter(char a) {
	return 'a' <= a && a <= 'z' || 'A' <= a && a <= 'Z';
}

bool digit(char a) {
	return '0' <= a && a <= '9';
}

bool space(char a) {
	return a == ' ' || a == '\n' || a == '\t'; // Add some white spaces
}

token parsenext(string::iterator &it) {
	while (space(*it))
		it++;

	string current;
	while (it != source_code.end() && (letter(*it) || digit(*it))) {
		current.push_back(*it);
		it++;
	}

	if (current.size() == 0) {
		while (it != source_code.end() && !letter(*it) && !digit(*it) && !space(*it))
			current.push_back(*it), it++;
	}

	if (Mp.count(current))
		return token(Mp[current], current);
	else
		return token("?", current);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (getline(cin, source_code)) {
		auto temp = source_code.begin();

		while (temp != source_code.end()) {
			auto res = parsenext(temp);
			cout << "<" << res.type << ", " << res.lexem << "> ";
		}
		cout << "\n";
	}


	return 0;
}