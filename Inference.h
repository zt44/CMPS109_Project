//  Component.h
//  SRI
//
//  Created by Babbie Monahelis on 2/28/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//  (word is Tarik also helped out a little bit)
//
#ifndef Inference_h
#define Inference_h

#include <stdio.h>
#include <cstdarg>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

class Inference 
{

private:
	string assoc;     //the association of the inference-line
	vector<string> param;     //vector containing the parameters of the inference-line

public:
	Inference();
	Inference(string, vector<string>);
	void setAssoc(string);
	void setParam(vector<string>);
	string getAssoc();

};

class Fact 
{

public:
	Fact(string assoc, vector<string> members); //Main constructor for a Fact.
	Fact(const Fact & f); //Copy constructor.
	Fact(Fact && f); //Move constructor.

private:
	string assoc; //The association of the fact i.e Father, Mother, etc...
	vector<string> param; //The members of the fact i.e John, Paul, Jones, etc...
};


class Rule
{
public:
	Rule();
	Rule(const Rule & r); //copy constructor
	Rule(Rule && r); //Move constructor

private:
	string assoc;
	vector<Fact> facts;     //all the facts on the right side of the rule statement 
};

#endif /* Component_h */