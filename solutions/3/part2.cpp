#include<iostream>
#include<string>
#include<regex>
#include<iterator>

int main(void){

	std::string memory = "";
	std::string x;
	while(std::getline(std::cin, x)){
		memory.append(x);
	}


	std::regex pattern("(mul\\([0-9]+,[0-9]+\\)|do\\(\\))|don't\\(\\)");
	std::regex num_pattern("[0-9]+");

	long sum = 0;
	bool is_enabled = true;

	std::sregex_iterator it(memory.begin(), memory.end(), pattern);
	std::sregex_iterator end;

	while (it != end) {
		std::smatch match = *it;
		if (match.str().find("do()") != std::string::npos) {
			is_enabled = true;
		} else if (match.str().find("don't()") != std::string::npos) {
			is_enabled = false;
		} else if (is_enabled) {
			std::string mulstr = match.str();
			std::sregex_iterator num_begin(mulstr.begin(), mulstr.end(), num_pattern);
			match = *num_begin;
			long n1 = std::stoi(match.str());
			match = *(++num_begin);
			long n2 = std::stoi(match.str());
			sum += n1*n2;
		}
		++it;
	}

	std::cout<<sum<<std::endl;
}

