#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int syntax_array_rootv, left_variable;
    int statement_matchIndex = 0;
    string input_token;
    char statement_array[10];

    char grammar[6][11] = {"A->BCDEDF.", "B->i.", "C->=.", "D->i.", "E->+.", "F->;."};

    char variableReplace_array[50];
    char syntax_array[50] = {};
    int children_array[50] = {};

    cout << "Please provide the input ";
    getline(cin, input_token);

    cout << "The entered tokens are: " << input_token << endl;

    int input_token_index = 0;
    while (input_token_index < input_token.length())
    {
        if (input_token[input_token_index] == '<')
        {
            statement_array[statement_matchIndex] = input_token[input_token_index + 1];
            statement_matchIndex++;
        }
        input_token_index++;
    }

    syntax_array_rootv = 0;
    left_variable = 0;

    syntax_array[syntax_array_rootv] = grammar[syntax_array_rootv][left_variable];
    variableReplace_array[0] = grammar[syntax_array_rootv][left_variable];

    int variableReplace_array_currentIndex = 0;
    int syntax_array_currentIndex = 1;

    while (true)
    {
        int grammar_rule_no, rule_right_side_copy_index, copy_flag, parent;

        for (grammar_rule_no = 0; grammar_rule_no < 6; grammar_rule_no++)
        {
            if (grammar[grammar_rule_no][left_variable] == variableReplace_array[variableReplace_array_currentIndex])
            {
                copy_flag = 0;
                parent = syntax_array_currentIndex - 1;

                for (rule_right_side_copy_index = 0; grammar[grammar_rule_no][rule_right_side_copy_index] != '.'; rule_right_side_copy_index++)
                {
                    if (grammar[grammar_rule_no][rule_right_side_copy_index] == '>')
                    {
                        copy_flag = 1;
                        continue;
                    }

                    if (copy_flag == 1)
                    {
                        syntax_array[syntax_array_currentIndex] = grammar[grammar_rule_no][rule_right_side_copy_index];
                        syntax_array_currentIndex++;
                        variableReplace_array[variableReplace_array_currentIndex] = grammar[grammar_rule_no][rule_right_side_copy_index];
                        variableReplace_array_currentIndex++;
                        children_array[parent]++;
                    }
                }
            }
        }

        if (variableReplace_array[variableReplace_array_currentIndex] == 'i' || variableReplace_array[variableReplace_array_currentIndex] == '=' || variableReplace_array[variableReplace_array_currentIndex] == '+' || variableReplace_array[variableReplace_array_currentIndex] == ';')
        {
            if (variableReplace_array[variableReplace_array_currentIndex] == statement_array[statement_matchIndex])
            {
                variableReplace_array_currentIndex++;
                statement_matchIndex++;
            }
            else
            {
                cout << "Syntax Error";
                break;
            }

            int i, break_flag = 1;

            for (i = 0; i < 50; i++)
            {
                if (variableReplace_array[i] != 'i' && variableReplace_array[i] != '=' && variableReplace_array[i] != '+' && variableReplace_array[i] != ';')
                {
                    break_flag = 0;
                    break;
                }
            }

            if (break_flag == 1)
            {
                break;
            }
        }
    }

    cout << "The output is: " << statement_array << endl;
    cout << "The output is: " << variableReplace_array << endl;
    cout << "The output is: ";
    for (int i = 0; i < 50; i++)
    {
        if (syntax_array[i] != '\0')
        {
            cout << syntax_array[i];
        }
    }
    cout << endl;
    cout << "The output is: ";
    for (int i = 0; i < 50; i++)
    {
        if (children_array[i] != 0)
        {
            cout << children_array[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
