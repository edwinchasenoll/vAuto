/******************************************************************************************************
PP 1.1: Spend up to 1 hour in the programming language of your choice and write a program 
that takes an arbitrary sentence and abbreviates it by replacing each word with the first 
letter of the word and the last letter of the word and a number representing the number of 
characters between the first and last letter.  For example, Ford would become F2d.  Words 
are separated by spaces or any other non-alphabetic characters.  The program should maintain 
all non-alphabetic characters in their original form.

Author: Chase Noll
Date: 1/23/2014
Purpose: vAuto Pre-interview assignment
*******************************************************************************************************/
#include <iostream>
#include <string>
#include "sentence.h"

string prompt();

using namespace std;

int main()
{
	//Stores user entered sentence
	string userSent;
	//Create sentence object
	sentence *line = new sentence();

	//Prompt for sentence
	userSent = prompt();

	//Loop as long as a user doesn't enter 'q' for quit
	while (userSent != "q")
	{
		//Set sent and abbreviate
		line->setSent(userSent);
		line->abbreviate();

		//Display original sentence and abbreviation
		cout << "Sentence: " << line->getSent() << endl << "Abbreviation: " << line->getAbbr() << endl << endl;

		//Prompt for sentence
		userSent = prompt();
	}
}

//Function that prompts and gets user sentence
string prompt()
{
	string sent;
	cout << "Enter a sentence or 'q' to quit: ";
	getline(cin, sent);
	return sent;
}