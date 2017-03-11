//
//  KnowledgeBase.hpp
//  SRI
//
//  Created by Babbie Monahelis on 3/9/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#ifndef KnowledgeBase_hpp
#define KnowledgeBase_hpp

#include <stdio.h>
#include "common.h"

class KnowledgeBase
{
private:
    map<string, vector<vector<string>>> FactDictionary;
    
public:
    
    KnowledgeBase();

    void addFact(vector<string> mems);
    void removeFact(vector<string> mems);
    void removeAllFactsWithKey(string key);
    int totalFacts();
    vector<vector<string>> findFact(string assoc);
    bool exists(string);
    
};

#endif /* KnowledgeBase_hpp */
