//自己只会for循环嵌套，以下回溯法CSDN的

#include<string.h>
#include <iostream>
#include<vector>
using namespace std;

const string letterMap[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
vector<string>results ;
string s="";
int i = 0;

void backtracking(const string& digits, int index);
void main()
{

	backtracking("23", 0);
	for (int k = 0; k < results.size(); k++) {
		cout << results[k] << " ";
	}
	cout << endl;

}

void backtracking(const string& digits, int index)
{
	if (index ==digits.size()) {
		results.push_back(s);
		return;
	}
	int num = digits[index]-'0';
	string str = letterMap[num];
	for (int j = 0; j < str.length(); j++)
	{
		s+= str[j];
		backtracking(digits, index + 1);
		s.pop_back();
	}
}