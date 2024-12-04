#include<iostream>
#include<string>
#include<vector>

static std::vector<std::vector<char>> puzzle;

bool search(std::vector<int> pos, char c){
	int x = 0;
	int y = 0;
	switch(c){
		case 'h':
			x = 1;
			break;
		case 'H':
			x = -1;
			break;
		case 'v':
			y = 1;
			break;
		case 'V':
			y =-1;
			break;
		case 'd':
			x = 1;
			y = 1;
			break;
		case 'D':
			x = 1;
			y = -1;
			break;
		case 'c':
			x = -1;
			y = 1;
			break;
		case 'C':
			x = -1;
			y = -1;
			break;
	}
	std::vector<char> xmas = {'M', 'A', 'S'};
	for(int i = 1; i < 4; i ++){
		int new_x = pos[0] + (x*i);
		int new_y = pos[1] + (y*i);
		if(new_x < 0 || new_x >= puzzle.size() || new_y < 0 || new_y >= puzzle[pos[0]].size())
			return false;
		if(puzzle[new_x][new_y]!=xmas[i-1])
			return false;
	}
	return true;

}
int main(void){

	std::string x;
	while(std::getline(std::cin, x)){
		puzzle.push_back(std::vector<char>(x.begin(), x.end()));
	}

	std::vector<char> dirs = {'h', 'H', 'v', 'V', 'd', 'D', 'c', 'C'};
	long answer = 0;
	for(int i = 0; i < puzzle.size(); i ++){
		for(int j = 0; j < puzzle[i].size(); j++){
			if(puzzle[i][j] == 'X'){
				for(char d: dirs){
					std::vector<int> pos = {i, j};
					if(search(pos, d)){
						answer++;
					}
				}
			}
		}
	}
	std::cout<<answer<<std::endl;
}
