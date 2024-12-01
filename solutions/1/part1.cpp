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
	std::sort(a1.begin(), a1.end());
	std::sort(a2.begin(), a2.end());
	long diff = 0;
	for(int i=0; i<a1.size(); i++)
		diff+=abs(a1[i]-a2[i]);

	std::cout<<diff<<std::endl;
	return 0;

}
