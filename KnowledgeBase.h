//  KnowledgeBase.h
//  SRI
//
//  Created by Babbie Monahelis on 2/25/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//
/*
#ifndef KnowledgeBase_h
#define KnowledgeBase_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include <map>
#include <algorithm>
#include "Component.h"
using namespace std;

class KnowledgeBase
{

public:

	map<string, vector<Fact*> > FactDictionary; //Map "dictionary" to hold the facts.

	KnowledgeBase(); //Constructor

	bool findFactAssociation(Fact * fact); //Find the association of a certain fact.
	void AddFact(Fact * fact); //Add a fact to the Knowledge Base FactDictionary
	Fact * drop(Fact * fact); //Drop fact from the FactDictuionary

	~KnowledgeBase(); //Deconstructor to delete the map

};



#endif /* KnowledgeBase_hpp */