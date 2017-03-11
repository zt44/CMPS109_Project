//
//  KnowledgeBase.cpp
//  SRI
//
//  Created by Babbie Monahelis on 3/9/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#include "KnowledgeBase.hpp"

KnowledgeBase::KnowledgeBase()
{
    
}

void KnowledgeBase::addFact(vector<string> mems)
{
    string assoc = mems.front(); //stored the association at the front of the vector.
    
    mems.erase(mems.begin()); //delete the association because we don't need it anymore
    
    vector< vector<string> > temp;
    temp.push_back(mems);
    
    auto add = FactDictionary.emplace(assoc, temp);
    
    if ( !add.second )
    {
        if ((find((*add.first).second.begin(), (*add.first).second.end(), mems) == (*add.first).second.end()))
            (*add.first).second.push_back(mems);
    }
    
}

vector< vector<string>> KnowledgeBase::findFact(string assoc)
{
    bool found;
    
    if (FactDictionary.count(assoc) == 0)
        found = false;
    else
        found = true;
    
    if (found == true)
        return FactDictionary[assoc];
    else
    {
        cout << "No facts of that association exists. \n";
        exit(0);
    }
    
}

bool KnowledgeBase::exists(string assoc)
{
    if (FactDictionary.count(assoc) == 0)
        return false;
    else
        return true; 
}








