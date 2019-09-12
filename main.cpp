#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <vector>

using namespace std;

struct token_record {
	string lexem, type;
	int first_appearance_line;
	token_record(string lexem, string type, int first_appearance) : lexem(lexem), type(type), first_appearance_line(first_appearance) {}
};

struct token {
	string name;
	token_record* link;
	string lexem; // only if link == nullptr
	token(string name, token_record* link = nullptr, string lexem = "") : name(name), link(link), lexem(lexem) {}
};

//vector<record> Result;
unordered_map<string, token_record*> Mp;
set<string> Delimiters = { "(*", "*)", "(.", ".)", "//", "{", "}", "[", "]", ".", ",", "..", "...", ";", ":"};


// OPERATORS


token parsenext(string::iterator &it, string::iterator end_of_str, int line_number) {
	while (isblank(*it))
		it++;

	string lexem;
	
	if (isalpha(*it)) { // identifier or keyword

		while (it != end_of_str && (isalpha(*it) || isdigit(*it))) {
			lexem.push_back(*it);
			it++;
		}

		if (Mp.count(lexem) == 0) // not existing identifier
			Mp[lexem] = new token_record(lexem, "identifier", line_number);

		if (Mp[lexem]->type == "keyword") 
			return token(lexem, Mp[lexem]); // keyword
		else
			return token("identifier", Mp[lexem]); // identifier

	}
	else if (*it == '\'') { // literal
		
		it++;
		while (it != end_of_str && *it != '\'') {
			lexem.push_back(*it);
			it++;
		}
		if (it != end_of_str && *it == '\'') it++;

		return token("literal", nullptr, lexem);
	}
	else if (isdigit(*it)) { // number

		while (it != end_of_str && (isdigit(*it) || *it == '.')) {
			lexem.push_back(*it);
			it++;
		}

		return token("number", nullptr, lexem);
	}
	else if (Delimiters.count(string(1, *it))) { // delimiters
		lexem = string(1, *it);
		it++;
		return token("delimiter", nullptr, lexem);
	}
	else { // undefined
		while (it != end_of_str && !isblank(*it)) {
			lexem.push_back(*it);
			it++;
		}

		return token("undefined", nullptr, lexem);
	}
}


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	vector<string> Keywords = { "downto", "do", "const", "absolute", "in", "destructor", "var", "begin", "array", "div", "asm", "constructor", "interface", "else", "end", "repeat", "file", "function", "implementation", "inherited", "packed", "inline", "operator", "label", "nil", "object", "of", "procedure", "program", "record", "uses", "reintroduce", "self", "string", "then", "to", "type", "unit" };
	vector<string> Operators = { "/", "xor", "goto", "and", "until", ":=", "+", "set", "mod", ">", "*", "=", "while", "-", "shl", "case", "for", "if", "not", ")", "shr", "or", "with", "<", "(", ":", "^", "@", "$", "#", "&", "%", "<<", ">>", "**", "<>", "+=", "-=", "*=", "/=", ">=", "><", "<=" };

	for (auto elem : Delimiters) Mp[elem] = new token_record(elem, "delimiter", -1);
	for (auto elem : Keywords) Mp[elem] = new token_record(elem, "keyword", -1);
	for (auto elem : Operators) Mp[elem] = new token_record(elem, "operator", -1);

	string source_code;

	int line_number = 1;
	while (getline(cin, source_code)) {
		auto temp = source_code.begin();

		while (temp != source_code.end()) {
			auto res = parsenext(temp, source_code.end(), line_number);
			if (res.link != nullptr)
				cout << "<" << res.link->type << " " << res.name << " \"" << res.link->lexem << "\"> ";
			else
				cout << "<" << res.name << " \"" << res.lexem << "\"> ";
		}

		cout << "\n";
		line_number++;
	}


	return 0;
}