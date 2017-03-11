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

void SRI::dumpRF(ostream &os, KnowledgeBase *kb, RuleBase *brules)
{   cout<<"DUMP"<<endl;
    cout<<"dumping into dump.sri"<<endl;
    for(auto iteratorx = kb->FactDictionary.begin(); iteratorx != kb->FactDictionary.end(); iteratorx++)
    {
        os<<iteratorx->second<<endl;
    }

    for(auto iteratorx = brules->rules.begin(); iteratorx != brules->rules.end(); iteratorx++)
    {
        os<<iteratorx->second<<endl;
    }
}

void SRI::dump(KnowledgeBase *kb, RuleBase *rb)
{
    ofstream out;
    //open file
    out.open("dump.sri");
    dumpRF(out, kb, rb);

}

void SRI::drop(string param, KnowledgeBase *kb, RuleBase *rb)
{
    kb->dropFact(param, kb);
    rb->dropRule(param, rb);

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

SRI::~SRI(){
    delete(kb);
    delete(rb);
    delete(parse);
}


