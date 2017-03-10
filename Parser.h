#pragma once
#include "common_headers.h"

class Parser {
public:
	bool getType(string);     //determine whether a given line is a fact, rule, or inference 
	                          //returns 'true' for fact and 'false' for rule
	bool getGate(string);     //returns the type of gate used in any given rule 
	                            //returns 'true' for AND and 'false' for OR
	string getFactAssoc(string);   //returns association type of a fact line
	string getRuleAssoc(string);     //returns left-most association type of a rule line
	string getInferAssoc(string);     //returns the association of an inference command statement 
	
	vector<string> getFactParam(string);     //returns a vector of the parameters in any given fact line
	vector<string> getInferParam(string);     //returns a vector of the parameters in any given fact line

	vector<string> getRuleFacts(string);     //returns a vector of 
	
	size_t betterFind(const string& haystack, size_t pos, const string& needle, size_t n)    //find the nth instance of a keyword in a string
	{
		size_t found = haystack.find(needle, pos);
		if (0 == n || string::npos == found)
			return found;
		return betterFind(haystack, found + 1, needle, n - 1);
	}
private:

	
};

