#include<iostream>
using namespace std;

//global variables
char board [3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row ;
int column;
char x_or_o = 'x';
bool tie = false;
void game_board()
{
    //Structure of game board

    cout<<"    |    |    \n";
    cout<<" "<<board[0][0]<<"  | "<<board[0][1]<<"  | "<<board[0][2]<<"\n";
    cout<<"____|____|____ \n";
    cout<<"    |    |    \n";
    cout<<" "<<board[1][0]<<"  | "<<board[1][1]<<"  | "<<board[1][2]<<"\n";
    cout<<"____|____|____\n";
    cout<<"    |    |    \n";
    cout<<" "<<board[2][0]<<"  | "<<board[2][1]<<"  | "<<board[2][2]<<"\n";
    cout<<"    |    |    \n";

}

void fun_to_enter(string player_01,string player_02)
{
    int digit;

    if(x_or_o == 'x')
    {
        cout<<player_01<<" please enter :";
        cin>>digit;
    }
    else //(x_or_o == 'o')
    {
        cout<<player_02<<" please enter :";
        cin>>digit;
    }

    //check that the digit enter is invalid or not
    if(digit == 1)
    {
        row = 0;
        column =0;
    }
    if(digit == 2)
    {
        row = 0;
        column =1;
    }

    if(digit == 3)
    {
        row = 0;
        column =2;
    }

    if(digit == 4)
    {
        row = 1;
        column =0;
    }
    if(digit == 5)
    {
        row = 1;
        column =1;
    }
    if(digit ==6)
    {
        row = 1;
        column =2;
    }
    if(digit ==7)
    {
        row = 2;
        column =0;
    }
    if(digit ==8)
    {
        row = 2;
        column =1;
    }
    if(digit ==9)
    {
        row = 2;
        column =2;
    }
    else if(digit<1 || digit>9)
    {
        cout<<" Invalid Entry "<<endl;

    }

    //check if box is empty or not
    if(x_or_o == 'x' && board[row][column]!='x' && board[row][column]!='o' )
    {
        board[row][column]='x';
        x_or_o = 'o';
    }
    else if(x_or_o == 'o' && board[row][column]!='x' && board[row][column]!='o' )
    {
        board[row][column]='o';
        x_or_o = 'x';
    }
    else{
        cout<<"There is no empty space"<<endl;
        fun_to_enter(player_01,player_02);
    }
    game_board();
    cout<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    return;
}

//fun to check player won / lost / game is going on

bool fun_win_lost()
{
    for(int i=0 ; i<3 ;i++)
    {
        if(((board[i][0]==board[i][1]) && ( board[i][1]==board[i][2]) )|| ((board[0][i]==board[1][i]) &&(board[1][i]==board[2][i]))){
            return true;
        }
      
    }
        /*diagonal '\'                                 */
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            return true;
        }
        //cross diagonal '/'
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            return true;
        }


    /*If any space is not filled or empty, 
    it will return false because it means the game is still going on.
    If the condition is not satisfied, 
    that means there is no space left and 
    the game is also not won by anyone then 
    it means it’s a tie so that the control will go outside the loops.*/

    // check for tie
   
    bool isTie = true;
    for(int i=0 ; i<3 ;i++){
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='x' && board[i][j]!='o')
            {
                isTie = false;
                break;
            }
        }
        if(!isTie) break;
    }
    if(isTie) {
        tie = true;
        return true;
    }

    
    return false;
    
}







int main()
{   cout<<endl<<endl;
    cout<<"                 Welcome to Tic-Tac-Toe !!!                  "<<endl;
    cout<<endl<<endl;
    cout<<"Enter the names of players : "<<endl<<endl;
    string player_01,player_02;
    cout<<"Enter the name of player 1 : ";
    getline(cin,player_01);
    cout<<"Enter the name of player 2 : ";
    getline(cin,player_02);
    cout<<endl;
    cout<<player_01<<"  will play the game first : x \n";
    cout<<player_02<<"  will play the game second: o \n";
    cout<<endl<<endl;

    //jab tak fun_win_lost true nahi hota tab tak game chalni chahiye hence the while loop will be :
     while( ! fun_win_lost())
    {
        game_board();
        fun_to_enter(player_01,player_02);
        fun_win_lost();
    }

    cout<<endl<<endl;
    /* if the x_or_o's (token) value is x and tie is false, 
    then n2 or player2 will be the winner. 
    It means the last turn was played by player2; 
    that is why now the value of turn is x, and 
    it is also not a tie as the value of tie is false. 
    So it means player2 wins the game.*/

    if(tie == false && x_or_o == 'x')
    {
        cout<<player_02<<" WIN WIN WIN !!!!!!!!"<<endl;
    }
    if(tie == false && x_or_o == 'o')
    {
        cout<<player_01<<" WIN WIN WIN !!!!!!!!"<<endl;
    }
    if(tie== true ){
        cout<<" OOPS !! "<<" It's draw the match !"<<endl;
    }
}