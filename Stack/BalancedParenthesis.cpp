#include <bits/stdc++.h>
using namespace std;
bool matching(char a, char b)
{
	return ((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'));
}
bool CheckBalanced(string str)
{
	stack<char> s;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
		{
			s.push(str[i]);
		}
		else
		{
			if(s.empty())
			{
				return false;
			}
			else if (matching(s.top(),str[i])==false) //Last in First out
			{
				return false;
			}
			else
			{
				s.pop();
			}
		}
	}
	return (s.empty()); //For Extra Brackets
}
int main()
{
	string str;
	cin>>str;
	if(CheckBalanced(str))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";	
	}
	return 0;
}