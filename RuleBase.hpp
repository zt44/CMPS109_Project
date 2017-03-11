//
//  RuleBase.hpp
//  SRI
//
//  Created by Babbie Monahelis on 3/9/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#ifndef RuleBase_hpp
#define RuleBase_hpp

#include <stdio.h>
#include "common.h"

class RuleBase
{
    
private:
    map<string, vector<map <string, vector<string>>>> RuleDictionary;
    
public:
    
    RuleBase();
    
    void addRule(map<string, vector<string>> mems);
    void removeRule(map<string, vector<string>> mems);
    void removeAllRulesWithKey(string key); //removes all rules with the key
    int totalRules();
    bool exists(string);
    vector<map <string, vector<string>>> findRule(string);
    
    
    
    ~RuleBase(); 
};

#endif /* RuleBase_hpp */
