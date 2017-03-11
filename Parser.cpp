//
//  Parser.cpp
//  SRI
//
//  Created by Babbie Monahelis on 3/10/17.
//  Copyright © 2017 Babbie Monahelis. All rights reserved.
//

#include "Parser.hpp"

Parser::Parser(){
}

Parser::~Parser(){
}

/*void Parser::addLine(stringstream & p_ss)
{
    string line = "";
    getline(p_ss,line,'#');
    lines.push_back(line);
}*/

bool Parser::getType(string s)
{
    string str = s.substr(0,4);
    
    if (str == "FACT")
        return true;
    else if (str == "RULE")
        return false;
    else
        return false;
}

bool Parser::getGate(string s)
{
    int str = s.find(" AND ");
    if (str > 999999)
        return false;
    else
        return true;
}

string Parser::getFactAssoc(string s)
{
    int spaceIndex = s.find(" ");
    int paranIndex = s.find("(");
    
    string strtemp = s.substr(spaceIndex, paranIndex);
    return strtemp;
}

string Parser::getRuleAssoc(string s)
{
    int spaceIndex = s.find(" ");
    int paranIndex = s.find("(");
    
    string strtemp = s.substr(spaceIndex, paranIndex - spaceIndex);
    return strtemp;
}

string Parser::getInferAssoc(string s)
{
    int spaceIndex = s.find(" ");
    int paranIndex = s.find("(");
    
    string strtemp = s.substr(spaceIndex+1, (paranIndex -spaceIndex)-1);
    
    return strtemp;
}


vector<string> Parser::addFact(string assoc)
{
    
    stringstream newStream(assoc);
    vector<string> params;
    
    string relationship = "";
    string rest = "";
    
    getline(newStream, relationship,'(');
    getline(newStream, rest, ')');
    stringstream newerStream(rest);
    
    params.push_back(relationship);
    
    while(getline(newerStream, rest, ','))
        params.push_back(rest);
    
    return params;
}

map<string, vector<string>> Parser::addRule(string assoc)
{
    stringstream newStream(assoc);
    map<string, vector<string>> rule;
    string first, operand, vars, rest, param;
    int i = 1;

    
    getline(newStream, first, ':');
    vector<string> base = parseRule(first);
    rule["name"].push_back(base[0]);
    
    for(int i = 1; i < base.size(); i++)
        rule["vars"].push_back(base[i]);
    
    getline(newStream, rest, ' ');
    getline(newStream, operand, ' ');
    rule["operand"].push_back(operand);
    
    while(getline(newStream, param, ' '))
    {
        string target = "target";
        target += to_string(i);
        rule[target] = parseRule(param);
        rule["ts"].push_back("");
        i++;
    }
    
    return rule;
}

vector<string> Parser::parseRule(string assoc)
{
    vector<string> ret;
    string name, params, var;
    
    stringstream newStream(assoc);
    
    getline(newStream, name, '(');
    ret.push_back(name);
    
    getline(newStream, params, ')');
    stringstream iss(params);
    
    while(getline(iss, var, ','))
        ret.push_back(var);
    return ret;
}

vector<string> Parser::inference(string p_string)
{
    vector<string> ret = parseRule(p_string);
    return ret;
}
