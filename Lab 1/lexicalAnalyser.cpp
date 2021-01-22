#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
using namespace std;

string arr[] = { "void", "using", "namespace", "int", "include", "iostream", "std", "main",
"cin", "cout", "return", "float", "double", "string" };

bool
isKeyword (string a)
{
  for (int i = 0; i < 14; i++)
    {
      if (arr[i] == a)
	{
	  return true;
	}
    }
  return false;
}

int main() 
{ 

	fstream file; 
	string s, filename; 

	filename = "./add.c"; 

	file.open(filename.c_str()); 

	while (file >> s) 
	{
        if (s == "+" || s == "-" || s == "" || s == "/" || s == "^" || s == "&&" || s == "||" || s == "=" || s == "==" || s == "&" || s == "|" || s == "%" || s == "++" || s == "--" || s == "+=" || s == "-=" || s == "/=" || s == "=" || s == "%=")
	    {
	      cout << s << " is an operator\n";
	      s = "";
	    }
	  else if (isKeyword (s))
	    {
	      cout << s << " is a keyword\n";
	      s = "";
	    }
	  else if (s == "(" || s == "{" || s == "[" || s == ")" || s == "}" || s == "]" || s == "<" || s == ">" || s == "()" || s == ";" || s == "<<" || s == ">>" || s == "," || s == "#")
	    {
	      cout << s << " is a symbol\n";
	      s = "";

	    }
	  else if (s == "\n" || s == " " || s == "")
	    {
	      s = "";

	    }
	  else if (isdigit (s[0]))
	    {
	      int x = 0;
	      if (!isdigit (s[x++]))
		{
		  continue;
		}
	      else
		{
		  cout << s << " is a constant\n";
		  s = "";
		}
	    }
	  else
	    {
	      cout << s << " is an identifier\n";
	      s = "";
	    } 
	} 

	return 0; 
} 
