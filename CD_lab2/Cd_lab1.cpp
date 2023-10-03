#include<iostream>

using namespace std;

int main()
{
    char statement [50];

    int inputer;
    int ic = 0;
    cout<<"Welcome to the Lexical Analyzer"<<endl;
    cout<<"---------------------------"<<endl;
    //Taking Inputs as character
    cout<<"Please Provide the inputs for Lexical Analysis"<<endl;
    cin.getline(statement,50);

    for(inputer=0; inputer<49; inputer++)
    {
        //checking if it is alphabet or not and if it alphabet then creating token
        if(isalpha(statement[inputer]))
        {
            if(isalpha(statement[inputer+1]))
                {

                }
            else
                {
                cout<<"<id,"<<ic++<<">";
                }

        }


        //checking operators and based on the operator creating tokens fpr the operator
        else if(statement[inputer]== '+' || statement[inputer]== '-' || statement[inputer]=='='|| statement[inputer]=='*'|| statement[inputer]=='/'|| statement[inputer]== '%')
        {

            cout<<"<"<<statement[inputer]<<">";


        }

        else
        {   //checking if there is any digit available in the array and based on that creating token
            if(isdigit(statement[inputer]))
            {
                if(!isdigit(statement[inputer+1]))
                {


                cout<<"<"<<statement[inputer-1]<<statement[inputer]<<">";
                }
            }

            //checking if the last character of the array is ;
            if(statement[inputer] == ';')
            {
                cout<<"<"<<statement[inputer]<<">";
                break;
            }


        }





}
    return 0;

}
