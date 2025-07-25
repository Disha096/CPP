#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int getCompChoice(){

	int choice = (rand () % 3) + 1;
	return choice;
}

int getUserChoice(){
	int choice;
	cout<<"\n Enter your choice : "<<endl;
	cout<<" 1. Rock"<<endl;
	cout<<" 2. Paper"<<endl;
	cout<<" 3. Scissors"<<endl;
	cout<<"\n Your choice : ";
	cin>>choice;
	
	while(choice<1 || choice>3){
		cout<<"\nInvalid Choice , Enter your choice(1,2,3) : ";
		cin>>choice;
	}
	
	return choice;

}

string charChoice(int choice){
	
	if(choice == 1){
		return "Rock";
	}
	else if(choice == 2){
		return "Paper";
	}
	else if(choice == 3){
		return "Scissors";
	}
	else{
		return "Invalid";
	}
}

int play(int user , int comp){
	cout<<"\nPlayer 1 (User''s) choice :"<<charChoice(user);
	cout<<"\nPlayer 1 (Computer's) choice : "<<charChoice(comp);
	
	if(user == comp){
		cout<<"\nResults : It's Draw"<<endl;
		return 0;
	}
	else if((user == 1 && comp == 3)||(user == 2 && comp == 1)||(user == 3 || comp == 2)){
		cout<<"\nResults : Player 1 (User) Wins!"<<endl;
		cout<<"Results : Player 2 (Computer) Lose!"<<endl;	
		return 1;
	}
	else{
		cout<<"\nResults : Player 2 (Computer) Wins!"<<endl;
		cout<<"Results : Player 1 (User) Lose!"<<endl;
		return 2;
	}
}

int main(){
	srand(time(0));
	
	char playagain;
	int win = 0 , lose = 0 , draw = 0;
	int userChoice = 0 , compChoice = 0 , result = 0;
	
	cout<<"Rock , Paper , Scissors game (Player v/s Computer)"<<endl;
	cout<<"Player 1 => You and Player 2 => Computer"<<endl;
	
	do{
		userChoice = getUserChoice();
		compChoice = getCompChoice();
		result = play(userChoice , compChoice);
		
		if(result == 0){
			draw++;
		}
		else if(result == 1){
			win++;
		}
		else{
			lose++;
		}
		
		cout<<"\nCurrent Score : ";
		cout<<"\nWins : "<<win;
		cout<<"\nLosses : "<<lose;
		cout<<"\nDraws : "<<draw;
		
	
			cout<<"\n\nDo you want to Play again?(Y or N)"<<endl;
			cin>>playagain;
			
			while(playagain != 'Y' && playagain != 'y' && playagain != 'N' && playagain != 'n'){
				cout<<"Invalid Input!please enter Y or N!!"<<endl;
				cout<<"Do you want to Play again?(Yes => y and No => n) : ";
				cin>>playagain;;
			}
		
	}while(playagain == 'Y'|| playagain == 'y');
	

	cout<<"\nFinal Score : ";
	cout<<"\nWins : "<<win;
	cout<<"\nLosses : "<<lose;
	cout<<"\nDraws : "<<draw;
	cout<<"\nThank you for playing!!"<<endl;
			
	return 0;
}