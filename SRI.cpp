//
//  Inference.cpp
//  SRI
//
//  Created by Babbie Monahelis on 3/10/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#include "SRI.hpp"
#include "KnowledgeBase.hpp"
#include "RuleBase.hpp"
#include "Parser.hpp"

SRI::SRI()
{
    kb = new KnowledgeBase();
    rb = new RuleBase();
   
}

void SRI::inputLine(stringstream & inputStream)
{
    string action;
    string body;
    string rest;
    
    getline(inputStream, action, ' ');
    getline(inputStream, rest, '#');
    
    stringstream newStream(rest);
    getline(newStream, body);
    
}

void SRI::addFact(string factToAdd)
{
    vector<string> fact = parse->addFact(factToAdd);
    kb->addFact(fact);
}

void SRI::addRule(string ruleToAdd){
  
    map<string, vector<string>> rule = parse->addRule(ruleToAdd);
    rb->addRule(rule);
}

void SRI::load(string line)
{
    
    ifstream readFile(line);
    string fileLine;
    
    while(getline(readFile, fileLine))
    {
        stringstream stringsToLoad(fileLine);
        inputLine(stringsToLoad);
    }
}

void SRI::inference(string assoc)
{
    
    vector<string> statements = parse->inference(assoc);
    string relation = statements[0];
    statements.erase(statements.begin());
    
    string factToOut;
    
    stringstream associationStream(assoc);
    
    getline(associationStream,factToOut,')');
    getline(associationStream,factToOut, ' ');
    getline(associationStream,factToOut);
    
    if(kb->exists(relation))
    {
    vector<map<string,string>> member = inferenceFact(relation, statements);
        
        //print results of inference
        for(int i = 0; i < member.size(); i++)
        {
            for(int j = 0; j < statements.size(); j++)
            {
                string found = statements[j];
                cout<< found << ": " << member[i][found] << "\n";
            }
        }
    }
    
    if(rb->exists(relation))
    {
        vector<map<string,string>> members = inferenceRule(relation, statements);
        
        auto query = members[0];
        members.erase(members.begin());
        
        if(query["passedBack"] == "false")
        {
            cout << "No rule found with that relation. \n" << endl;
            return;
        }
        
        if(factToOut == "")
        {
            for(int i = 0; i < members.size(); i++)
            {
                for(int j = 0; j < statements.size(); j++)
                {
                    string found = statements[j];
                    cout << found << ": " << members[i][found] << "\n";
                }
                cout<<endl;
            }
        }
        else
        {
            vector<string> fact;
            for(int i = 0; i < members.size(); i++)
            {
                fact.push_back(factToOut);
                for(int j = 0; j < statements.size(); j++)
                {
                    string found = statements[j];
                    fact.push_back(members[i][found]);
                }
                
                kb->addFact(fact);
                fact.clear();
                
            }
        }
        
    }
}

vector<map<string,string>> SRI::inferenceFact(string assoc, vector<string> & mems)
{
    
    vector<vector<string>> members = kb->findFact(assoc);
    int totalMembers = mems.size();
    bool found = true;
    
    vector< map<string,string>> ourFacts;
    
        for(int i = 0; i < members.size(); i++){
        
        if(totalMembers != members[i].size()) continue;
        
        map<string,string> factMap;
        
        for(int j = 0; j < totalMembers; j++)
        {
            
            string curr = mems[j];
            string fact_item = members[i][j];
            
            if(factMap.find(curr) == factMap.end())
                factMap[curr] = fact_item;
            else
            {
                if(factMap[curr] != fact_item)
                {
                    found = false;
                    break;
                }
            }
        }
        
        if(found)
            ourFacts.push_back(factMap);
    }
    return ourFacts;
}

vector<map<string,string>> SRI::inferenceRule(string assoc, vector<string> & mems)
{
    vector<map<string, string>> x;
    
    return x;
}

/*
vector<map<string,string>> SRI::inferenceRule(string assoc, vector<string> & mems)
{
    
    vector<map<string,string>> result;
    int stringToPrint = mems.size();
    
    map<string, vector<string>> rule = findRule(assoc, stringToPrint);
    string found = rule["passedBack"][0];
    
    map<string,string> members;
    
    for(int i = 0; i < mems.size(); i++)
        members[mems[i]] = rule["vars"][i];
    
    if(found == "false")
    {
        map<string,string> fa;
        fa["passedBack"] = "false";
        result.push_back(fa);
        return result;
    }
    
    //build target vector
    vector<vector<string>> targets;
    for(int i=1; i<rule["ts"].size()+1; i++){
        string target = "target"+to_string(i);
        vector<string> t = rule[target];
        targets.push_back(t);
    }
    
    //process the rule targets
    vector<vector<map<string,string>>> target_returns;
    for(int i=0; i<targets.size(); i++){
        string name = targets[i][0];
        targets[i].erase(targets[i].begin());
        
        if(kb->exists(name)){
            vector<map<string,string>> t = inferenceFact(name, targets[i]);
            target_returns.push_back(t);
            
        }else if(rb->exists(name)){
            vector<map<string,string>> t = inferenceRule(name, targets[i]);
            t.erase(t.begin());
            target_returns.push_back(t);
        }
    }
    
    string op = rule["operand"][0];
    
    if(op == "AND"){
        result = andFunction(target_returns);
        
    }else if(op == "OR"){
        for(int i = 0; i<target_returns.size(); i++){
            for(int j = 0; j<target_returns[i].size(); j++){
                result.push_back(target_returns[i][j]);
            }
            
        }
        
    }
    
    map<string,string> fa;
    fa["passedBack"] = "true";
    result.insert(result.begin(), fa);
    return result;
}

map<string, vector<string>> SRI::findRule(string p_name, int p_size){
    vector<map<string, vector<string>>> rules = rb->findRule(p_name);
    map<string, vector<string>> rule;
    
    for(int i=0; i<rules.size(); i++){
        rule = rules[i];
        if(rule["vars"].size() == p_size){
            rule["passedBack"].push_back("true");
            return rule;
        }
    }
    
    rule["passedBack"].push_back("false");
    return rule;
}

vector<map<string,string>> SRI::andFunction(vector<vector<map<string,string>>> p_targets){
    vector<map<string,string>> result;
    vector<map<string,string>> first = p_targets[0];
    
    vector<int> pos(p_targets.size(), 0);
    bool ended = false;
    
    while(!ended){
        map<string,string> eval;
        bool isTrue;
        
        for(int i=0; i<p_targets.size(); i++){
            
            isTrue = true;
            vector<map<string,string>> myMaps = p_targets[i];
            int position = pos[i];
            
            for(auto const &x : myMaps[position]){
                
                if(eval.count(x.first) == 0){
                    eval[x.first] = x.second;
                }else{
                    if((eval[x.first]!=x.second)==1){
                        isTrue = false;
                    }
                }
            }
            
            if(i==p_targets.size()-1){
                int j=i;
                while(j>=-1){
                    
                    if(j == -1){
                        ended = true;
                        break;
                    }
                    
                    pos[j] += 1;
                    if(pos[j] == p_targets[j].size()){
                        pos[j] = 0;
                        j -= 1;
                    }else{
                        break;
                    }
                }
            }
        }
        if(isTrue == true){
            result.push_back(eval);
        }
    }
    
    return result;
}
*/

SRI::~SRI(){
    delete(kb);
    delete(rb);
    delete(parse);
}


