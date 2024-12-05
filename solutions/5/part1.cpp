#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


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

	//for(auto i: orders){
	//	for(auto j: i)
	//		std::cout<<j<<" ";
	//	std::cout<<std::endl;
	//}

	//for(auto i: updates){
	//	for(auto j: i)
	//		std::cout<<j<<" ";
	//	std::cout<<std::endl;
	//}

	long answer = 0;
	for(auto i: updates){
		bool correct = true;
		for(int j = 0; j < i.size()-1; j++){
			std::vector<int> required = {i[j], i[j+1]};
			if(std::find(orders.begin(), orders.end(), required) == orders.end()){
				correct = false;
				break;
			}
		}
		if(correct)
			answer += i[i.size()/2];
	}
	std::cout<<answer<<std::endl;
}
