#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>


int getmiddle(std::vector<std::vector<int>> &orders, int start, int end){
	std::vector<int> potential_matches = {};
	for(auto i: orders){
		if(i[0] == start)
			potential_matches.push_back(i[1]);
	}
	for(auto i: orders){
		if(i[1] == end && std::find(potential_matches.begin(), potential_matches.end(), i[0])!=potential_matches.end()){
			std::vector<int> t = {start, i[0]};
			orders.erase(std::remove(orders.begin(), orders.end(), t), orders.end());
			t = {i[0], end};
			orders.erase(std::remove(orders.begin(), orders.end(), t), orders.end());
			return i[0];
		}
	}
	return -1;
}
int main(void){
	std::vector<std::vector<int>> orders;
	std::string x;
	std::vector<int> t;
	while(std::getline(std::cin, x)){
		if(x == "")
			break;
		t.push_back(std::stoi(x.substr(0, 2)));
		t.push_back(std::stoi(x.substr(3, 2)));
		orders.push_back(t);
		t = {};
	}
	std::vector<std::vector<int>> updates;
	while(std::getline(std::cin, x)){
		for(int i = 0; i < x.length(); i+=3){
			t.push_back(std::stoi(x.substr(i, 2)));
		}
		updates.push_back(t);
		t = {};
	}

	long answer = 0;
	for(auto i: updates){
		bool correct = true;
		std::vector<int> fixupdate;
		int s;

		std::vector<int> done;
		for(s = 0; s < i.size()-1; s++){
			std::vector<int> required = {i[s], i[s+1]};
			if(std::find(orders.begin(), orders.end(), required) == orders.end()){
				correct = false;
				//fixupdate = std::vector<int>(i.begin() + s, i.end());
				//done = std::vector<int>(i.begin(), i.begin() + s);
				break;
			}

		}
		if(correct)
			continue;

		std::vector<int> startpages = {};
		std::vector<int> endpages = {};
		std::vector<std::vector<int>> relorders;
		for(auto j: orders){
			if(std::find(i.begin(), i.end(), j[0]) != i.end() && std::find(i.begin(), i.end(), j[1]) != i.end()){
				relorders.push_back(j);
				startpages.push_back(j[0]);
				endpages.push_back(j[1]);
			}
		}
		for(auto p: i){
			int s = std::count(startpages.begin(), startpages.end(), p);
			int e = std::count(endpages.begin(), endpages.end(), p);
			if(s==e && s == i.size()/2){
				answer += p;
				break;
			}
		}

		
	}
	std::cout<<answer<<std::endl;
}
