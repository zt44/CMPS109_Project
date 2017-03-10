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

	string strtemp = s.substr(spaceIndex+1, (paranIndex - spaceIndex)-1);    //cuts the string and stores resulting substring 
	                                                                         //in strtemp

	return strtemp; 
}

string Parser::getInferAssoc(string s)
{
	int spaceIndex = s.find(" ");
	int paranIndex = s.find("(");

	string strtemp = s.substr(spaceIndex+1, (paranIndex -spaceIndex)-1);    //cuts the string and stores resulting substring 
	                                                                        //in strtemp

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

		param.push_back(str.substr(x + 1, (y - x) - 1));   //push the rest of the paramters (except for last parameter)
	}

	int start = str.rfind(",");    //starts looking from the back of string
	int end = str.rfind(")");
	param.push_back(str.substr(start + 1, (end - start) - 1));   //push the last parameter

	return param;
}

vector<string> Parser::getInferParam(string str)
{
	vector<int> indices;    //will hold indices of commas

	int i = 0;
	while (betterFind(str, 0, ",", i)<999999) {

		size_t paramCount = betterFind(str, 2, ",", i);
		indices.push_back(paramCount);
		i++;
	}

	vector<string> param;    //will hold the actual parameters

	param.push_back(str.substr(str.find('(') + 1, (str.find(',') - str.find('(') - 1)));   //param[0] = first parameter

	for (int j = 0; j < indices.size() - 1; j++)
	{
		int x = indices[j];
		int y = indices[j + 1];

		param.push_back(str.substr(x + 1, (y - x) - 1));   //push the rest of the paramters (except for last parameter)
	}

	int start = str.rfind(",");
	int end = str.rfind(")");
	param.push_back(str.substr(start + 1, (end - start) - 1));   //push the last parameter

	return param;
}

vector<string> Parser::getRuleFacts(string str)
{
	vector<int> indices;    //will hold the indices of the spaces in a string
	int i = 0;
	while (betterFind(str, 0, " ", i)<999999) {

		size_t paramCount = betterFind(str, 2, " ", i);
		indices.push_back(paramCount);
		i++;
	}
	int start1 = indices[0];
	int end1 = str.find(":-");

	vector<string> facts;    //will hold the actual facts
	facts.push_back(str.substr(start1 + 1, (end1 - start1) - 1));    //push first fact
	indices.erase(indices.begin());    //delete first element
	indices.erase(indices.begin());     //delete second element



	for (int j = 0; j < indices.size() - 1; j++)
	{
		int x = indices[j];
		int y = indices[j + 1];

		facts.push_back(str.substr(x + 1, (y - x) - 1));   //push all parameters except the first and last
	}

	int start2 = str.rfind(" ");
	int end2 = str.rfind(")");
	facts.push_back(str.substr(start2 + 1, (end2 - start2)));   //push the last parameter

	return facts;
}








