// RandomGenerator.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme rada başlayıp biter.
//

#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
	const char l_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char s_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	const char symbol[] = "!@#$%&";
	const char number[] = "0123456789";
int numPos_decider();
int symbolPos_decider();
int letterPos2_decider();
int letterPos_decider();
void print_Username(std::string printUsername)
{
	std::cout << "Generated Username:  " << printUsername << "\n";
}
void print_Password(std::string printPassword)
{
	std::cout << "Generated Password: " << printPassword << "\n";
}
void add_Char(std::string password_Add)
{
	int smallPos, bigPos, symbPoss, numberPos;
	symbPoss = symbolPos_decider();
	bigPos = letterPos_decider();
	smallPos = letterPos2_decider();
	numberPos = numPos_decider();
	char choosePlace;
	char chooseFirstLetter;
	std::cout << "MENU ";
	std::cout << "Which char would you like to add? \n1-Symbol(s-S)\n2-UpperCase Letter(u-U)\n3-lowercase letter(l-L)\n4-Number(n-N) \n";
	std::cout << "Choose ";
	std::cin >> chooseFirstLetter;
	if (chooseFirstLetter == 's' || chooseFirstLetter == 'S' || chooseFirstLetter == '1')
	{
		password_Add += symbol[symbPoss];
		std::cout << "Added Random : " << password_Add << "\n";
	}
	if (chooseFirstLetter == 'u' || chooseFirstLetter == 'U' || chooseFirstLetter == '2')
	{
		password_Add += l_alphabet[bigPos];
		std::cout << "Added Random : " << password_Add << "\n";
	}
	if (chooseFirstLetter == 'l' || chooseFirstLetter == 'L' || chooseFirstLetter == '3')
	{
		password_Add += s_alphabet[smallPos];
		std::cout << "Added Random : " << password_Add << "\n";
	}
	if (chooseFirstLetter == 'n' || chooseFirstLetter == 'N' || chooseFirstLetter == '4')
	{
		password_Add += number[numberPos];
		std::cout << "Added Random : " << password_Add << "\n";
	}

}
void char_Remover(std::string randomTo_Edit)
{
	char addChar_Question{};
	char removeChar;
	char removeChar_Question{};
	std::cout << "Would you like to remove a symbol/letter/number? (y/n) : ";
	std::cin >> removeChar_Question;
	if (removeChar_Question == 'y')
	{
		std::cout << "Which one would you like to remove? : ";
		std::cin >> removeChar;
		randomTo_Edit.erase(remove(randomTo_Edit.begin(), randomTo_Edit.end(), removeChar), randomTo_Edit.end());
		std::cout << "Edited Generated Random : " << randomTo_Edit <<"\n";
		std::cout << "Would you like to add another symbol/letter/number to replace removed char? (y/n) : ";
		std::cin >> addChar_Question;
		if (addChar_Question == 'y')
		{
			add_Char(randomTo_Edit);
		}
		else
		{
			system("CLS");
			std::cout << "\n Generated Random : " << randomTo_Edit << "\n\n";
		}
	}
	else
	{
		system("cls");
		std::cout << "Generated Random : " << randomTo_Edit << "\n";
	}
}
int numPos_decider()
{
	int numPosition;
	numPosition = rand() % 10;

	return numPosition;

}
int symbolPos_decider()
{
	int symbolPosition;
	symbolPosition = rand() % 6;

	return symbolPosition;

}
int letterPos2_decider()
{
	int letterPosition;
	letterPosition = rand() % 26;

	return letterPosition;
}
int letterPos_decider()
{
	int position;
	position = rand() % 26;

		return position;
}
void create_Password(int lengthOfPass)
{
	int result;
	int letterPos,symbolPos,numberPos,letterPos2;
	std::string password = "";
	if (lengthOfPass % 4 != 0)
	{
		for (int i = 1; i <= (lengthOfPass/4)+1; ++i)
		{
			letterPos = letterPos_decider();
			letterPos2 = letterPos2_decider();
			symbolPos = symbolPos_decider();
			numberPos = numPos_decider();
			password = password + l_alphabet[letterPos];
			password = password + s_alphabet[letterPos2];
			password = password + symbol[symbolPos];
			password = password + number[numberPos];
		}
		if (password.size() != lengthOfPass)
		{
			result = password.size() - lengthOfPass;
			password.erase(password.size() - result);
			print_Password(password);
			char_Remover(password);
		}
		else
		{
			print_Password(password);
			char_Remover(password);
		}
	}
	else {
		for (int i = 1; i <= lengthOfPass / 4; ++i)
		{
			letterPos = letterPos_decider();
			letterPos2 = letterPos2_decider();
			symbolPos = symbolPos_decider();
			numberPos = numPos_decider();
			password = password + l_alphabet[letterPos];
			password = password + s_alphabet[letterPos2];
			password = password + symbol[symbolPos];
			password = password + number[numberPos];
		}
		print_Password(password);
		char_Remover(password);
	}


}
void create_Username(int lengthOfName)
{
	int result;
	int letterPos, symbolPos, numberPos, letterPos2;
	std::string username = "";
	if (lengthOfName % 3 != 0)
	{
		for (int i = 1; i <= (lengthOfName / 3) + 1; ++i)
		{
			letterPos = letterPos_decider();
			letterPos2 = letterPos2_decider();
			numberPos = numPos_decider();
			username = username + l_alphabet[letterPos];
			username = username + s_alphabet[letterPos2];
			username = username + number[numberPos];
		}
		if (username.size() != lengthOfName)
		{
			result = username.size() - lengthOfName;
			username.erase(username.size() - result);
			print_Username(username);
			char_Remover(username);
		}
		else
		{
			print_Username(username);
			char_Remover(username);
		}
	}
	else {
		for (int i = 1; i <= lengthOfName / 3; ++i)
		{
			letterPos = letterPos_decider();
			letterPos2 = letterPos2_decider();
			numberPos = numPos_decider();
			username = username + l_alphabet[letterPos];
			username = username + s_alphabet[letterPos2];
			username = username + number[numberPos];
		}
		print_Username(username);
		char_Remover(username);
	}


}



int main()
{
	srand(time(NULL));
	char switchChoice;
	int lengthOfRandom;
	std::cout << "					  /************************************/\n";
	std::cout << "					 / Random Password/Username Generator /\n";
	std::cout << "					/************************************/\n";
	


	while (true)
	{
		std::cout << "Length of the username/password : ";
		std::cin >> lengthOfRandom;
		std::cout << "Length : " << lengthOfRandom << "\n";
		// Sleep(1000);
		std::cout << "Key words for Random Password : 'p' / 'pass' / 'word' \n";
		std::cout << "Key words for Random Username : 'u' / 'user' / 'name' \n";
		std::cout << "Choice : ";
		std::cin >> switchChoice;
		system("cls");

		switch (switchChoice)
		{
		case 'pass': case 'p': case 'word':
			create_Password(lengthOfRandom);
			break;
		case 'user': case 'u': case 'name':
			create_Username(lengthOfRandom);
			break;
		}
	}
	system("pause");
}