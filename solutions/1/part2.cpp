#include<iostream>
#include<vector>
#include<algorithm>

int main(void){
	std::vector<int> a1 {};
	std::vector<int> a2 {};
	int x;
	while(std::cin>>x){
		a1.push_back(x);
		std::cin>>x;
		a2.push_back(x);
	}
	long simscore = 0;
	for(int i=0; i<a1.size(); i++)
		simscore+=a1[i]*(std::count(a2.begin(), a2.end(), a1[i]));

	std::cout<<simscore<<std::endl;
	return 0;

}
