#include"common_headers.h"
#include"Parser.h"
/*
size_t betterFind(const string& haystack, size_t pos, const string& needle, size_t n)
{
	size_t found = haystack.find(needle, pos);
	if (0 == n || string::npos == found) 
		return found;
	return betterFind(haystack, found + 1, needle, n - 1);
}

int main()
{
	string str = "RULE Father($X,$Y):- AND Parent($X,$Y)Mother($X,$Y)";
	Parser parse;

	vector<string> commandParams = parse.getRuleFacts(str);

	for (int i = 0; i < commandParams.size(); i++)
	{
		cout << commandParams[i] << endl;
	}
	
	vector<int> indices;
	string str = "FACT Father(roger,john,nick)";
	int i = 0;
	while (betterFind(str, 0, ",", i)<999999) {

		size_t paramCount = betterFind(str, 2, ",", i);
		indices.push_back(paramCount);
		i++;
	}

	vector<string> param;
	param.push_back(str.substr(str.find('(') + 1, (str.find(',') - str.find('(') - 1)));   //param[0] = first parameter

	for (int j = 0; j < indices.size() - 1; j++) 
	{
		int x = indices[j];
		int y = indices[j + 1];

		param.push_back(str.substr(x + 1, (y - x) - 1));   //push the rest of the paramters (except for last parameter)
	}

	int before = str.rfind(",");
	int after = str.rfind(")");
	param.push_back(str.substr(before+1, (after - before)-1));   //push the last parameter
	
	
	for (int k = 0; k < param.size(); k++)
	{
		cout << param[k] << endl;
	}
	

	return 0;
}
*/