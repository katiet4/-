#include <iostream>
using namespace std;


class Map
{
public:
	void draw(){
		cout<<"\n---------------\n";
		cout<<"1-9 is coords\nO or X is chars\n\n";
		int charCurrent = 0;
		for (int i = 0; i < 3; i++)
		{
			cout<<"|";
			for (int j = 0; j < 3; j++)
			{
				cout<<chars[ i*3+j ]<<"|";
			}
			cout<<"\n";
		}



	}
	int set_chars(int coord, char ch){

		if(coord >= 9 || coord < 0){

			cout<<"Error: Out of range\n";
			return 1;

		}

		else if(chars[coord] == 'X' || chars[coord] == 'O'){

			cout<<"Error: Place isn't empty\n";
			return 2;

		}

		this->chars[coord] = ch;

		// checking somebody won
		for (int i = 0; i < 3; i++)
		{
			int wonLeftToRight = 0;
			int wonUpToDown = 0;
			int wonDiagonal = 0;
			for (int j = 0; j < 3; j++)
			{
				int threadLeftToRight = i*3+j;
				int threadUpToDown = i+j*3;
				int threadDiagonal;
				if(this->chars[threadLeftToRight] == ch){
					wonLeftToRight++;
				}
				if(this->chars[threadUpToDown] == ch){
					wonUpToDown++;
				}
				if(i<2){
					if(i == 0){
						threadDiagonal = j*3+j;
					}
					else if(i == 1){
						threadDiagonal = j*2+2;
					}

					if(this->chars[threadDiagonal] == ch){
						wonDiagonal++;
					}
					
				}
			}

			if(wonLeftToRight == 3){
				return 200;
			}
			else if(wonUpToDown == 3){
				return 200;
			}
			else if(wonDiagonal == 3){
				return 200;
			}

		}



		return 0;
	}

// Инкапсуляция
private:
char chars[9]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};

};



class Player
{
public:
	virtual void put(int coord, Map map){}
	
};

// Наследование
class X:Player
{
public:
	int put(int coord, Map *map){
		return map->set_chars(coord-1, 'X');
	}
};

// Наследование
class O:Player{
public:
	int put(int coord, Map *map){
		return map->set_chars(coord-1, 'O');
	}

};



int main(){
	while (true)
	{
		Map *map = new Map();
		system("cls");
		map->draw();

		X *x = new X(); 
		O *o = new O(); 

		int whoMove = 1; // 1 - X; 0 - O.
		for (int i = 0; i < 9; i++)
		{
			int coord, response;
			cout<<"Input coord:";
			cin >> coord;
			cout<<"\n";

			if (whoMove)
			{	
				// Полиморфизм
				response = x->put(coord, map);
				whoMove = 0;
			}
			else{
				// Полиморфизм
				response = o->put(coord, map);
				whoMove = 1;
			}

			//if something went wrong or somebody won
			if(response){
				i--;
				// Somebody won
				if(response == 200){
					whoMove = !whoMove;
					char winner = whoMove ? 'X' : 'O';
					system("cls");
					map->draw();
					cout<<winner<<" won\n";
					break;
				}
			}
			if(i==8){
				system("cls");
				map->draw();
				cout<<"Nobody won\n";
				break;
			}
			system("cls");
			map->draw();
		}

		int next;
		cout<<"Do you wont play again?(0 - Yes; >0 - No)\n: ";
		cin >> next;
		if(next){
			break;
		}


	}
	

	return 0;
}				