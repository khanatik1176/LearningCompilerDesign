#include <iostream>
#include <string.h>

using namespace std;

int main()
{
int syntax_array_rootv, starting_variable, top_rule, left_variable;
int input_tokenIndex, statement_index;
string input_token;
char statement_array[10];

char grammar [6][11] = {"A->BCDEDF.","B->i.","C->=.","D->i.","E->+.","F->;."};

char variableReplace_array[50];
char syntax_array[50];
int children_array[50];

cout<< "Please provide the input ";
getline (cin,input_token);

cout<< "The entered tokens are :"<<input_token<<endl;

 statement_index = 0;

for( int input_token_index = 0; input_token_index < input_token.length(); input_token_index++)
{

    if(input_token[input_token_index] == '<')

    {

    statement_array[statement_index] = input_token[input_token_index+1];
    statement_index ++;

    }

}
cout<<"The output is :"<<statement_array<<endl;



syntax_array_rootv = 0;
starting_variable = 0;
top_rule = 0;
left_variable = 0;

syntax_array[syntax_array_rootv] = grammar[top_rule][left_variable];
variableReplace_array[starting_variable]= grammar[top_rule][left_variable];

int variableReplace_array_currentIndex = 0;
int syntax_array_currentIndex = 1;
int statement_matchIndex = 0;


// loop until all the leaf nodes in the syntax tree are terminals

while(true)
{

 //find out the rule related to the variable in the variable variable_replacer

    int grammer_rule_no, rule_right_side_copy_index, copy_flag, parent;

    for(grammer_rule_no = 0; grammer_rule_no < 6; grammer_rule_no++){
        if(grammar[grammer_rule_no][left_variable] == variableReplace_array[variableReplace_array_currentIndex])
    {
        copy_flag = 0;
        parent = syntax_array_currentIndex - 1;

        for(rule_right_side_copy_index=0; grammar[grammer_rule_no][rule_right_side_copy_index] != '.'; rule_right_side_copy_index++)
        {
            if(grammar[grammer_rule_no][rule_right_side_copy_index] == '>')
            {
                copy_flag = 1;
                continue;
            }

            if(copy_flag == 1)
            {
                syntax_array[syntax_array_currentIndex] = grammar[grammer_rule_no][rule_right_side_copy_index];
                syntax_array_currentIndex++;
                variableReplace_array[variableReplace_array_currentIndex] = grammar[grammer_rule_no][rule_right_side_copy_index];
                variableReplace_array_currentIndex++;
                children_array[parent]++;
            }
        }
    }
}

variableReplace_array_currentIndex = 0;

if(variableReplace_array[variableReplace_array_currentIndex] == 'i' || variableReplace_array[variableReplace_array_currentIndex] == '=' || variableReplace_array[variableReplace_array_currentIndex] == '+' || variableReplace_array[variableReplace_array_currentIndex] == ';')
{
    if(variableReplace_array[variableReplace_array_currentIndex] == statement_array[statement_matchIndex])
    {
        variableReplace_array_currentIndex++;
    }

    else
    {
        cout<<"Syntax Error";
    }

    int i, break_flag = 1;

    for(i=0; i<50; i++)
    {
        if(variableReplace_array[i] != 'i' && variableReplace_array[i] != '=' && variableReplace_array[i] != '+' && variableReplace_array[i] != ';')
            break_flag = 0;
    }

    if(break_flag == 1)
    {
        break;
    }
}

}



//cout<<"The output is :"<<variableReplace_array<<endl;

//cout<<"The output is :"<<syntax_array<<endl;

//cout<<"The output is :"<<children_array<<endl;

return 0;


}
