#include<iostream>
#include<string>
#include<vector>

static std::vector<std::vector<char>> puzzle;

bool search(std::vector<int> pos){
	std::vector<std::vector<int>> delta = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
	int new_x, new_y;
	std::string xmas = "";
	for(int i = 0; i < delta.size(); i ++){
		new_x = pos[0] + delta[i][0];
		new_y = pos[1] + delta[i][1];
		if(new_x < 0 || new_x >= puzzle.size() || new_y < 0 || new_y >= puzzle[pos[0]].size())
			return false;
		xmas += puzzle[new_x][new_y];
	}
	if(xmas == "MMSS" || xmas == "SSMM" || xmas == "MSMS" || xmas == "SMSM")
		return true;
	return false;

}
int main(void){

	std::string x;
	while(std::getline(std::cin, x)){
		puzzle.push_back(std::vector<char>(x.begin(), x.end()));
	}

	long answer = 0;
	for(int i = 0; i < puzzle.size(); i ++){
		for(int j = 0; j < puzzle[i].size(); j++){
			if(puzzle[i][j] == 'A'){
				std::vector<int> pos = {i, j};
				if(search(pos)){
					answer++;
				}
			}
		}
	}
	std::cout<<answer<<std::endl;
}
