#include<iostream>
#include<vector>
#include<string>
#include<sstream>

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
		bool inc;
		int diff = 0;
		for(int j = 1; j < reports[i].size(); j++){
			diff = reports[i][j] - reports[i][j-1];
			if(j==1){
				inc = diff>0?1:0;
			}
			if(diff == 0 || abs(diff) > 3 || (inc != diff>0)) break;
			if (j==reports[i].size()-1) safes++;
		}
	}
	std::cout<<safes<<std::endl;
}
