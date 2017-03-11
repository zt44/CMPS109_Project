//
//  RuleBase.cpp
//  SRI
//
//  Created by Babbie Monahelis on 3/9/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#include "RuleBase.hpp"

RuleBase::RuleBase()
{
    
}

void RuleBase::addRule(map<string, vector<string>> mems)
{
    string assoc = mems["association"][0];
    
    if (RuleDictionary.count(assoc) == 0)
        RuleDictionary[assoc].push_back(mems);
    else
    {
        for(vector<map<string, vector<string>>>::iterator it = RuleDictionary.at(assoc).begin(); it != RuleDictionary.at(assoc).end(); it++)
        {
            if(equal((*it).begin(), (*it).end(), mems.begin()))
                RuleDictionary[assoc].push_back(mems);
        }
    }
    
}

void RuleBase::removeRule(map<string, vector<string>> mems)
{
    vector<string> tempRuleMems = mems.at("association");
    string head = tempRuleMems[0];
    
    auto it = find(RuleDictionary.at(head).begin(), RuleDictionary.at(head).end(), mems);
    
    if (it != RuleDictionary.at(head).end())
        RuleDictionary.at(head).erase(it);
    
}

vector<map <string, vector<string>>> RuleBase::findRule(string assoc)
{
    if (RuleDictionary.find(assoc) == RuleDictionary.end())
    {
        cout << "No rule exists with that association.\n";
    }
    return RuleDictionary[assoc];
}

bool RuleBase::exists(string assoc)
{
    if (RuleDictionary.find(assoc) == RuleDictionary.end())
        return false;
    else
        return true;
}

int RuleBase::totalRules()
{
    return RuleDictionary.size();

}

RuleBase::~RuleBase()
{
    
}

