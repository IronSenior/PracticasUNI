//guess.cc
//A program that generate a random number which you have to guess
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[])
{
	//It will change the random seed
	srand(time(NULL)); //time(NULL) returns "UNIX Epoch"
	//It will generate a random number between 0 and 10
	int random_number = rand() % 11;

	//Loop for the user to guess the number
	int user_number = -1;

	while(user_number != random_number){
		std:: cout << "Adivina el numero entre 0 y 10\n";
		std:: cin >> user_number;

		//It will determine if the number is bigger or smaller than the random_number
		if (user_number > random_number){
			std:: cout << "Te has pasado\n";
		}
r
		if (user_number < random_number){
			std:: cout << "Te has quedado corto\n";
		}
	}

	//When the loop end the program know that the user has guessed the number
	std:: cout << "Correcto!!! \n";
	
	return 0;
}

