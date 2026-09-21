// strings
 
#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv [])
{
	string s1 = "hello";
	string s2;
	
	s1 += "Hello";
	s2 = s1;
	
	cout << s1 << endl;
	cout << s1.length() << endl;
	
	return EXIT_SUCCESS;
}