#include "common_headers.h"
#include "Inference.h"
#include "Parser.h"

int main()
{
	string str = "INFERENCE Father(Roger,John)";
	Inference command;
	Parser parse;

	string temp = parse.getInferAssoc(str);
	command.setAssoc(temp);

	cout << command.getAssoc() << endl;


	/*
	bool exit = false;
	int i = 0;
	while (exit == false)
	{
		string input;

		//string str = "INFERENCE Father(Roger,John)";
		cout << "Enter inference command: " << endl;
		cin >> input;

		string a = parse.getInferAssoc(input);
		commands[i].setAssoc(a);
		i++;

	}
	*/
	return 0;
}
