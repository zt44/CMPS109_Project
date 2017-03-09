//
//  KnowledgeBase.cpp
//  SRI
//
//  Created by Babbie Monahelis on 2/25/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//
/*
#include "KnowledgeBase.h"
#include "Inference.h"

KnowledgeBase::KnowledgeBase()
{
	map<string, vector<Fact *>> FactDictionary = *new map<string, vector<Fact *> >();
}

bool KnowledgeBase::findFactAssociation(Fact * fact)
{
	if (FactDictionary.find(fact->association) == FactDictionary.end())
		return false;

	return true;
}

void KnowledgeBase::AddFact(Fact * fact)
{
	bool found = findFactAssociation(fact);

	if (found == false)
	{
		vector<Fact *> tempVector;
		tempVector.push_back(fact);
		FactDictionary[fact->association] = tempVector;
	}
	else
	{
		for (Fact * f : FactDictionary[fact->association])
		{
			if (f->members == fact->members)
				cout << "This fact is already in our knowledge base.\n";
		}

		FactDictionary[fact->association].push_back(fact);

	}

}

KnowledgeBase::~KnowledgeBase()
{
	FactDictionary.clear();
}
*/