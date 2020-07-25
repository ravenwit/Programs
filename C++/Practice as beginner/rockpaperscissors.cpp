#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

std::string tools[]={"ROCK","PAPER","SCISSORS","ROPE"};
bool isTryAgain=true;
std::string userName;
std::string c="Computer";
std::string userTool;
std::string computerTool;
std::string clearString="\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n ";
void PrintResult(std::string Contents)
{
    cout << "\n \t" << Contents << "\n \n \n \n \n \n \n \n " <<endl;
}
void GetUserName()
{
    PrintResult("What is your name?");
    cin >> userName ;
}
bool CheckToolValidity(std::string tool)
{
    if(tool==tools[0] || tool==tools[1] || tool==tools[2] || tool==tools[3]){return true;}
    return false;
}
void GetUserTool()
{
    bool isCorrect=false;
    while(!isCorrect){
    cout << "\n \n Which tool do you want to choose? " << tools[0] << ", " << tools[1] << ", " << tools[2] << " or " << tools[3] << endl;
    cin >> userTool;
    transform(userTool.begin(),userTool.end(),userTool.begin(),::toupper);
    if(CheckToolValidity(userTool)){isCorrect=true;}else{
            cout << "\n \n Sorry! There is no such tool as " << userTool << "\n Please try again" << endl;
            isCorrect=false;}
}
}
void GenerateComputerTool()
{
    srand(time(NULL));
    int randomInteger=rand() % 10 +1;
    if(randomInteger <=3){
        computerTool=tools[0];
    }
    else if(randomInteger <=5 ){
        computerTool=tools[1];
    }
     else if(randomInteger <=8 ){
        computerTool=tools[2];
    }else{computerTool=tools[3];}
}
void ShowTools()
{
    cout << "Computer : " << computerTool << endl;
    cout << userName << ": " << userTool << endl;
}
void Result(std::string tool1, std::string tool2)
{
        bool isWin=true;
        std::string winner = "Computer";
        std::string winningTool=tools[0];

        if(tool1==tools[0] && tool2==tools[1] || tool1==tools[1] && tool2==tools[0]){
           winningTool = tools[1];
        }
         else if(tool1==tools[0] && tool2==tools[2] || tool1==tools[2] && tool2==tools[0]){
           winningTool = tools[0];
        }
         else if(tool1==tools[0] && tool2==tools[3] || tool1==tools[3] && tool2==tools[0]){
           winningTool = tools[3];
        }
         else if(tool1==tools[1] && tool2==tools[2] || tool1==tools[2] && tool2==tools[1]){
           winningTool = tools[2];
        }
         else if(tool1==tools[1] && tool2==tools[3] || tool1==tools[3] && tool2==tools[1]){
           winningTool = tools[1];
        }
         else if(tool1==tools[2] && tool2==tools[3] || tool1==tools[3] && tool2==tools[2]){
           winningTool = tools[2];
        }else{isWin=false;}
        if(tool1==winningTool){winner=userName;}
        if(isWin){
            PrintResult(winner + " wins with " + winningTool + "! ");
        }else{
            PrintResult("The result is a tie.");
        }
}
char getAnswer(char inputChar)
{
    char outputChar;
    char ans;
    if(inputChar=='Y' || inputChar=='y')
    {
        outputChar='y';
    }else if(inputChar=='n' || inputChar=='N')
    {
        outputChar='n';
    }else{
        cout << "\n ______________________________________________________________________________ \n \t \t Wrong Answer! \n \t \t Yes(y) or No(n), (y/n): ";
        cin >> ans;
        getAnswer(ans);
    }
    return outputChar;
}
int main()
{
    char ans;
    GetUserName();
    while(isTryAgain){
            cout << clearString << endl;
        GenerateComputerTool();
        GetUserTool();
        ShowTools();
        Result(userTool,computerTool);
        cout << " \n \n ___________________________________________________________________ \n \n \t \t Do you want to try again? (y/n): ";
        cin >> ans;
        cout << "\n \n ____________________________________________________________________ " << endl;
           if(getAnswer(ans)=='y'){isTryAgain=true;}else if(getAnswer(ans)=='n'){isTryAgain=false;}
    }

return 0;
}
