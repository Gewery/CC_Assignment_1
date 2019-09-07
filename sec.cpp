//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <map>
//#include <unordered_map>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//
//	string st;
//	cin >> st;
//	while (st.size() != 0) {
//
//		st.pop_back();
//		
//		if (st[0] == '“')
//			st = st.substr(1, st.size() - 2);
//
//		cout << "{\"" << st << "\", ";
//		
//		cin >> st;
//
//		cout << "\"" << st << "\"}, ";
//
//		cin >> st;
//	}
//
//	return 0;
//}