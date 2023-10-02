#include<iostream>

using namespace std;

int main()
{
    char statement [50];

    int inputer;
    int ic = 0;
    cin.getline(statement,50);

    for(inputer=0; inputer<49; inputer++)
    {

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



        else if(statement[inputer]== '+' || statement[inputer]== '-' || statement[inputer]=='='|| statement[inputer]=='*'|| statement[inputer]=='/'|| statement[inputer]== '%')
        {

            cout<<"<"<<statement[inputer]<<">";
            //cout<<"<id,"<<ic++<<">";


        }

        else
        {
            if(isdigit(statement[inputer]))
            {
                if(!isdigit(statement[inputer+1]))
                {


                cout<<"<"<<statement[inputer-1]<<statement[inputer]<<">";
                }
            }


            if(statement[inputer] == ';')
            {
                cout<<"<"<<statement[inputer]<<">";
                break;
            }


        }





}
    return 0;

}
