#include<bits/stdc++.h>
using namespace std;
//create a betting game of finding the ace
struct Player
{
    int Choice ; string Name;
};
class Single_Player
{
    private:
    int Player_Choice , Bet ;
    int Random_value()
    {
        //compute a random variable between 1 and 3
        srand(time(0)); 
        int value = rand() ;
        // cout<<"\nrandom generated value is "<<value;
        value = (value%3 )+ 1; 
        cout<<"\nposition of ACE card is  "<<value;
        return value;
    }
    public :
    int Money , id;
    string Name; 
    Single_Player()
    {
        //initail money for a player
        Money = 100;
    }
    
    int Play(int PlayerMoney)
    {
        
        //here player will play the game
        if(PlayerMoney <= 0) 
        {
            cout<<"SORRY YOU ARE OUT OF MONEY......!!!";
            return 0;
        }
        //enter the bet
        cout<<"\nenter the amount to bet";
        while(true)
        {
            cin>>Bet;
            if(Bet <= PlayerMoney && Bet > 0) break;
            else cout<<"\nplease choose money less than "<<PlayerMoney<<" and greater than 0 ";
        }
        cout<<"\nchoose a position of ace card  from top (1 , 2, or 3)";
        while(true)
        {
            cin>>Player_Choice;
            if(Player_Choice == 1|| Player_Choice == 2|| Player_Choice == 3) break;
            else cout<<"please enter a valid choice ";
        }
        cout<< "\nWAIT SHUFFLING CARDS........";

        int Computer_Value = Random_value();
        if(Computer_Value == Player_Choice)
        {
            cout<<"\nCONGRAGULATIONS......YOU CHOOSE RIGHT ";
            PlayerMoney = Bet * 3;
            return PlayerMoney;
        }
        else
        {
            cout<<"\nOPP's WRONG GUESS........";
            PlayerMoney = PlayerMoney-Bet;
            return PlayerMoney;
            
        }
        


    }

};
class MultiPlayer
{
    private:
    string Name ; int Choice , TotalPlayers;  
    MultiPlayer()
    {
       TotalPlayers =0;
        
    }
    public:
    int play() 
    {
        //crete an array of players wiht their name and comman bet amount and choices
        cout<<"eneter the number of players who will play";
        cin>>TotalPlayers;
        for(int i=1;i<=TotalPlayers;i++) 
        {
            
        }
        //pass the array to the play function 
        //player function then return who is winner and total winning

    }


};

int main()
{
    //create a new player
    // Player player;
    // player.Name = "keshav";
    // int UpdatedMoney = player.Play(player.Money);
    // cout<<"\nyour updated balance"<<UpdatedMoney; 
    
    //build driver menu 
    int Game_Choice, Player_Choice;
    Single_Player player;
    MultiPlayer multiplayer;
    cout<<"******WELCOME TO BETTING WORLD********";
    cout<<"\nenter your choice \n1.play Game\n2 Exit";
    cin>>Game_Choice;
    switch(Game_Choice)
    {
        case  1: 
        while(Player_Choice!=3)
        {
            cout<<"\nenter the choice \n1single player\n2.multiplayer\n3.exit";
            cin>>Player_Choice;
            switch(Player_Choice)
            {
                case 1 : //play with single player
                player.Money = player.Play(player.Money);
                cout<<"your final amount is "<<player.Money; 
                case 2 :
                {
                    multiplayer.play();
                    
                    
                }
    
            
            }
        }
        break; 
        case 2: 
        default : 
        cout<<"\nPlease select a valid option";
         //do nothing
    }
    cout<<"\n THANK YOU FOR PLAYING ....!!!!";
    return 0;
}