#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

bool judge_Palindromic_strings(string s);

int main()
{	
	string s;
	getline(cin,s);
	bool state= judge_Palindromic_strings(s);
	if (state == true) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}		
	return 0;
}

//字符串预处理
size_t preprocessing(string& s)
{
	int i = 0;
	size_t len = s.length();
	while (i < len)
	{
		if ((s[i] >= 'A' && s[i] <= 'Z')) {
			s[i] += 32;
			i++;
		}
		else if ((s[i] >= '0' && s[i] <= '9')|| (s[i] >= 'a' && s[i] <= 'z')) {
			i++;
		}
		else {
			s.erase(i, 1);
			len--;
		}
	}
	return len;
}

//判断是否为回文串
bool judge_Palindromic_strings(string s)
{
	size_t len= preprocessing(s);
	for (int i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - i - 1]) {
			return false;
		}
	}
	return true;
}