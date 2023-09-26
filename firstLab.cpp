#include<iostream>

using namespace std;

int main()
{
    char statement [12];

    int inputer;
    int ic =1;
    cin.getline(statement,12);

    for(inputer=0; inputer<11; inputer++)
    {



        if(isalpha(statement[inputer]))
        {
         cout<<"<id"<<ic++<<">";


        }


        else
        {
            if(statement[inputer]== '+' || statement[inputer]== '-' || statement[inputer]=='='|| statement[inputer]=='*'|| statement[inputer]=='/'|| statement[inputer]== '%'|| statement[inputer]== ';'|| isdigit(statement[inputer]))

            {
                cout<<"<"<<statement[inputer]<<">";

             if (statement[inputer] == ';')
            {
                break;
            }

            }

        }


    }
    return 0;

}
