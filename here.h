#include <string>
#include <any>
#include <typeinfo>

template <typename T>
std::string process_arg (T& arg) {
	
	std::string vartype;						//variable type as a string
	std::string valuestr;						//variable value, cast to string
	const std::type_info& type = typeid(arg);	//type id for testing
	
	/*
	 in a past version i simply checked the data type using one if statement with is_arithmetic. the reason i decided to check for each type individually is because i wanted
	 to add support for std::any. is_arithmetic requires the type to be known at compilation, but std::any is not known until runtime. so, because i cant use is_arithmetic,
	 i had to do it the hard way
	 */
	if (type == typeid (int)) {
		vartype = "int";
		valuestr = std::to_string (std::any_cast<int> (arg));
	}
	else if (type == typeid (float)) {
		vartype = "float";
		valuestr = std::to_string (std::any_cast<float> (arg));
	}
	else if (type == typeid (double)) {
		vartype = "double";
		valuestr = std::to_string (std::any_cast<double> (arg));
	}
	else if (type == typeid (long)) {
		vartype = "long";
		valuestr = std::to_string (std::any_cast<long> (arg));
	}
	else if (type == typeid (long long)) {
		vartype = "long long";
		valuestr = std::to_string (std::any_cast<long long> (arg));
	}
	else if (type == typeid (unsigned int)) {
		vartype = "unsigned int";
		valuestr = std::to_string (std::any_cast<unsigned int> (arg));
	}
	else if (type == typeid (unsigned long)) {
		vartype = "unsigned long";
		valuestr = std::to_string (std::any_cast<unsigned long> (arg));
	}
	else if (type == typeid (unsigned long long)) {
		vartype = "unsigned long long";
		valuestr = std::to_string (std::any_cast<unsigned long long> (arg));
	}
	else if (type == typeid (short)) {
		vartype = "short";
		valuestr = std::to_string (std::any_cast<short> (arg));
	}
	else if (type == typeid (unsigned short)) {
		vartype = "unsigned short";
		valuestr = std::to_string (std::any_cast<unsigned short> (arg));
	}
	else if (type == typeid (char)) {
		vartype = "char";
		valuestr = std::string (1, std::any_cast<char> (arg));
	}
	else if (type == typeid (unsigned char)) {
		vartype = "unsigned char";
		valuestr = std::to_string (std::any_cast<unsigned char> (arg));
	}
	else if (type == typeid (bool)) {
		vartype = "bool";
		valuestr = std::any_cast<bool> (arg) ? "1 true" : "0 false";
	}
	else if (type == typeid (const char*)) {
		vartype = "const char*";
		valuestr = std::string (std::any_cast<const char*> (arg));
	}
	else if (type == typeid (std::string)) {
		vartype = "string";
		valuestr = std::any_cast<std::string> (arg);
	}
	else {
		vartype = "";	//if variable type doesnt match anything
		try {valuestr = arg;}	//if type is unknown, may fail to make string
		catch (...) {valuestr = "invalid";}
	}
	/*
	 in the below return function, explanation of ternary condition:
	 if string vartype is empty ("") then it reached the last else statement in the type checking,
	 which means the data type of the variable is not recognized, in which case change the output format
	 if vartype is valid, then output format is like: "int = 12"
	 else if vartype == "" (empty string, meaning invalid type) then output format is just valuestr, like: "string"
	 */
	return (vartype != "") ? (vartype + " = " + valuestr) : valuestr;
	
}

template <typename... T>
std::string here (T&&... args) {	//sends parameters to process_args
	
	std::string print = "\nhere\n\n";
	((print += process_arg (args) + "\n"), ...);	//fold expression to send each arg one at a time to process_arg, append the return value to string print
	return print;	//return complete output to be printed
}
