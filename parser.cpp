#include "Parser.h"
#include "common_headers.h"

bool Parser::getType(string s)
{
	string str = s.substr(0,4);
	if (str == "FACT")
		return true;
	else if(str == "RULE")
	    return false;
}

bool Parser::getGate(string s)
{
	int str = s.find(" AND ");
	if (str > 999999)
		return false;
	else
	    return true;
}

string Parser::getFactAssoc(string s)
{
	int spaceIndex = s.find(" ");
	int paranIndex = s.find("(");

	string strtemp = s.substr(spaceIndex, paranIndex);
	return strtemp;
}

string Parser::getRuleAssoc(string s)
{
	int spaceIndex = s.find(" ");
	int paranIndex = s.find("(");

	string strtemp = s.substr(spaceIndex, paranIndex - spaceIndex);
	return strtemp; 
}

string Parser::getInferAssoc(string s)
{
	int spaceIndex = s.find(" ");
	int paranIndex = s.find("(");

	string strtemp = s.substr(spaceIndex+1, (paranIndex -spaceIndex)-1);

	return strtemp;
}

vector<string> Parser::getFactParam(string str) 
{
	vector<int> indices;

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

		param.push_back(str.substr(x + 1, (y - x) - 1));   //push the rest of the paramters to the vector param
	}

	return param;
}

vector<string> Parser::getRuleFacts(string str)
{
    
    stringstream stream(str);
    string assoc;
    string param;
    string member;
    vector<string> temp;
    
    getline(stream, assoc, '(');
    temp.push_back(assoc); //adding rule assoc to vector
    
    getline(stream, param, ')');
    stringstream mems(param); //finding the members of the rule
    
    while( getline(mems, member, ',') )
        temp.push_back(member); //adding the member of the rule to the vector
    
    return temp;
}










