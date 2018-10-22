// Main program to run stack
#include <iostream>
using namespace std;
#include "StackUsingArray.cpp"
#include "StackUsingTemplate.cpp"
#include "StackUsingLL.cpp"

int main() {
	// Stack Using Linked List
	StackUsingLL<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	
	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.getSize() << endl;

	cout << s.isEmpty() << endl;
	
	/*StackUsingTemplate<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);

	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;*/

}

