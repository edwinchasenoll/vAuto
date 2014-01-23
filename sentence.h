/***************************************************
This header file defines the class sentence. It's functionality
consist of getting and setting sent(a string sentence) and
abbr(the abbrevation of sent) and the performing that abbreviation.
Criteria is defined in main.cpp

Author: Chase Noll
Date: 1/23/2014
Purpose: vAuto pre-interview assignment
****************************************************/
#ifndef SENTENCE_H
#define SENTENCE_H

#include<string>

using namespace std;

class sentence
{
private:
	string sent;
	string abbr;

public:
	sentence();
	sentence(string);
	void setSent(string);
	string getSent();
	void setAbbr(string);
	string getAbbr();
	void abbreviate();
};

//Set string values to nothing really
sentence::sentence()
{
		sent = "";
		abbr = "";
}

//Initiallize sent with a user value
sentence::sentence(string text)
{
		sent = text;
		abbr = "";
}

void sentence::setSent(string text)
{
	sent = text;
}

string sentence::getSent()
{
	return sent;
}

void sentence::setAbbr(string text)
{
	abbr = text;
}

string sentence::getAbbr()
{
	return abbr;
}

//abbreviate sent using criteria in main.cpp
//I first thought separate the words and abbreviat them but then decided if I could abbreviate with one iteration through the string that would
//be faster
void sentence::abbreviate()
{
	string abbreviation = "";
	
	//Store word length per criteria num character in middel to be displayed. Display wordLen - 2 (minus first and last)
	int wordLen = 0;

	//Store first character of word '!' start of new word
	char first = '!';
	//Store last character of word '!' start of new word
	char last = '!';

	//Buffer for convertring wordLen to alpha (itoa)
	char buff[100];

	//Transverse each character of sentence
	for(unsigned int i = 0; i < sent.length(); i++)
	{
		//If character is alpha
		if(isalpha(sent.at(i)))
		{
			//If starting new word
			if (first == '!')
			{
				//Set first and last character
				first = sent.at(i);
				last = sent.at(i);
			}
			else //This is not new word only update last character
				last = sent.at(i);
			
			//Increment word length
			wordLen++;

			//If the user sentence ends here append the current word abbreviation
			if (i == sent.length() - 1)
			{
				//Append first character of word to abbreviation
				abbreviation.push_back(first);

				//If word length is > 1 it has a last character append it to abbreviation
				if (wordLen > 1)
				{
					//If chracters exist between first and last append wordLen to abbreviation before last character
					if (wordLen > 2)
					{
						//Convert wordLen to alpha
						_itoa_s(wordLen - 2, buff, 10);
						abbreviation.append(buff);
					}
					abbreviation.push_back(last);
				}
				//Reset initial values
				first = '!';
				last = '!';
				wordLen = 0;
			}
		}
		else//Character is not alpha
		{
			//If non alpha found while processing word append word abbreviation
			if (wordLen > 0)
				abbreviation.push_back(first);
			
			//If word length is > 1 it has a last character append it to abbreviation
			if (wordLen > 1)
			{
				//If chracters exist between first and last append wordLen to abbreviation before last character
				if (wordLen > 2)
				{
					//Convert wordLen to alpha
					_itoa_s(wordLen - 2, buff, 10);
					abbreviation.append(buff);
				}
				abbreviation.push_back(last);
			}

			//Append non alpha character always
			abbreviation.push_back(sent.at(i));

			//Reset initial values
			first = '!';
			last = '!';
			wordLen = 0;
		}
	}

	//Set abbr to fromed abbreviation
	setAbbr(abbreviation);
}

#endif