#include<iostream>

using namespace std;

int main()
{
    char statement [50];

    int inputer;
    int ic =1;
    cin.getline(statement,50);

    for(inputer=0; inputer<49; inputer++)
    {



        if(statement[inputer]== '='|| statement[inputer+1] == !isdigit(statement[inputer]))
        {
         cout<<"<id,"<<ic++<<">";


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

        }

        if(statement[inputer]== '+' || statement[inputer]== '-' || statement[inputer]=='='|| statement[inputer]=='*'|| statement[inputer]=='/'|| statement[inputer]== '%')
        {

            cout<<"<"<<statement[inputer]<<">";
            cout<<"<id,"<<ic++<<">";


        }

        else
        {
            if(statement[inputer]== '+' || statement[inputer]== '-' || statement[inputer]=='='|| statement[inputer]=='*'|| statement[inputer]=='/'|| statement[inputer]== '%'|| statement[inputer]== ';')

            {
                cout<<"<"<<statement[inputer]<<">";



            }


            if(statement[inputer] == ';')
            {
                break;
            }


        }


    }
    return 0;

}
