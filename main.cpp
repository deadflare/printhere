#include <iostream>
#include <string>
#include <vector>
#include "here.h"

// example code for here() function

int main() {
	int i = 12;
	float n = 3.14;
	const char* c = "f";
	bool x = true;
	std::vector<std::string> vec = {"one", "two"};
	std::cout << here (i, "pi:", n, c, "bool x:", x, vec[0], vec[1]);
}
