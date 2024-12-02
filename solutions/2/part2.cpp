#include<iostream>
#include<vector>
#include<string>
#include<sstream>

bool check_row(std::vector<int> row){
	bool inc;
	int diff;
	for(int i = 0; i < row.size()-1; i++){
		diff = row[i+1] - row[i];
		if(i == 0) inc = (diff > 0);
		if(abs(diff) < 1 || abs(diff) > 3 || inc != (diff > 0)){
			return false;
		}
	}
	return true;
}
std::vector<int> remove_index(std::vector<int> row, int index){
	row.erase(row.begin() + index);
	return row;
}

int main(void){
	std::vector<std::vector<int>> reports;

	std::string s;
	std::vector<int> report;
	while(std::getline(std::cin, s)){
		std::istringstream i(s);
		std::string x;
		while(std::getline(i, x, ' ')){
			report.push_back(std::stoi(x));
		}
		reports.push_back(report);
		report = {};
	}
	int safes = 0;
	for(int i = 0; i < reports.size(); i++){
		if(check_row(reports[i])) safes++;
		else{
			for(int j = 0; j < reports[i].size(); j++){
				std::vector<int> row(reports[i]);
				row.erase(row.begin() + j);
				if(check_row(row)){
					safes++;
					break;
				}
			}
		}
	}
	std::cout<<safes<<std::endl;
}
