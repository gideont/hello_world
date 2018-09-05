/***********************************************
*      Copyright (C) Gideon Tsang, 2018        *
*                                              *
* This is a C++11 example.                     *
***********************************************/

#include <iostream>
#include <vector>

using namespace std;

bool accept()
{
	cout << "Do you want to proceed (y or n)?\n";
	char answer = 0;
	cin >> answer;

	switch (answer)
	{
		case 'y':
			return true;
		case 'n':
			exit(EXIT_FAILURE);;
		default:
			cout << "Sorry I don't understand.  I'll assume the answer is 'yes'.\n";
			return true;
	}
	exit(EXIT_FAILURE);;
}
 
int main(int argc, char *argv[])
{
    std::cout << "Hello world!\n";

	// vector of int type
	vector<int> v {1,2,3,4,5,6};

	accept();  // continue?

	// for each i in v
	for(auto i : v)
	{
		cout << i << endl;
	}

    return 0;
}
