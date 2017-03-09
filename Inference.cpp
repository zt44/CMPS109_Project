#include "common_headers.h"
#include "Inference.h"


Inference::Inference()
{

}

Inference::Inference(string str, vector<string> p)
{
	assoc = str;
	param = p;
}

void Inference::setAssoc(string s)
{
	assoc = s;
}

void Inference::setParam(vector<string> p)
{
	param = p;
}

string Inference::getAssoc()
{
	return assoc;
}


