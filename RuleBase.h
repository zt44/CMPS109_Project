//
//  RuleBase.hpp
//  SRI
//
//  Created by Babbie Monahelis on 2/28/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//
/*
#ifndef RuleBase_h
#define RuleBase_h

#include <stdio.h>
#include "Component.h"
using namespace std;

class RuleBase
{

private:

	vector<Rule*> rules;

public:

	RuleBase(); //default constructor
	~RuleBase(); //Destructor

	void AddRule(Rule * rule);
	void DropRule(Rule * rule);

};



#endif /* RuleBase_hpp */