/*
#include"common_headers.h"

size_t betterFind(const string& haystack, size_t pos, const string& needle, size_t n)
{
	size_t found = haystack.find(needle, pos);
	if (0 == n || string::npos == found) 
		return found;
	return betterFind(haystack, found + 1, needle, n - 1);
}

int main()
{
	string str = "GrandFather($X,$Y):- AND Parent($X,$Y)Father($Y,$X)";
	//string str = "FACT Father(waseem,is,a,baby)";
	vector<int> indices;
	
	int i = 0;
	while (betterFind(str, 0, "$", i)<999999) {

		size_t paramCount = betterFind(str, 2, "$", i);
		indices.push_back(paramCount);
		cout << indices[i] << endl;
		i++;
	}



	return 0;
}
*/