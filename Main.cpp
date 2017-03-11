#include "common_headers.h"
#include "SRI.cpp"
#include "KnowledgeBase.h"
#include "RuleBase.h"

void menu()
{
    SRI *sriobj;
    KnowledgeBase *kb = new KnowledgeBase();
    RuleBase *rb = new RuleBase();

    string command, command1, command2; //command
    string input;
    ofstream fout;
    bool exit = false;

    while(!exit){
    cout<<"(i)FACT"<<endl;
    cout<<"(ii)RULE"<<endl;
    cout<<"(iii)LOAD"<<endl;
    cout<<"(iv)DUMP"<<endl;
    cout<<"(v)DROP"<<endl;
    cout<<"(vi)INFERENCE"<<endl;
    cout<<"(vii)QUIT"<<endl;
    cout<<"-------------"<<endl;
	cout<<"Enter your command: "<<endl;
	getline(cin, input);
	stringstream str(input);
	getline(str, command, ' ');//catch the first command entered
	getline(str, command1);
	command2 = input;

	if(command2 == "i"){
		cout<<"Fact entered: "<<command1<<endl; //pring the fact entered on console
		sriobj->addFact(command1);

    }
	else if(command2 == "ii"){
            cout<<"Rule entered: "<<command1<<endl;
            sriobj->addRule(command1);

        }

	else if(command2 == "iii"){
            cout<<"LOADING"<<endl;
            sriobj->load(command1);
    }
    else if(command2 == "iv"){
            sriobj->dump(kb, rb);
            cout<<"DUMPING KB AND RB"<<endl;
    }

    else if(command2 == "v"){
            cout<<"DROPPING"<<endl;
            sriobj->drop(command1, kb, rb);

    }
    else if(command2 == "vi"){
        cout<<"Issuing a query"<<endl;
        sriobj->inference(command1);
    }
    else if(command == "vii"){
        cout<<"CIAO BAMBINO"<<endl;
        break;
    }

      }
}
int main(){
	menu();
}
