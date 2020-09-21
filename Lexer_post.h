#pragma once

#include "Lexer_main.h"
#include <string>

class PostLexer 
{
private:
	const char* multi_op[15] = {"::","->","|>","|<","&&","||","\"\"","\'\'","##","!=","==","?=","//","/*","*/"}; //operrators with more than one char

	bool in_moa(std::string to_) {
		

		for (int i = 0; i < sizeof(multi_op); ++i)
		{
			if (to_ == multi_op[i])
			{
				return true;
			}
		}
		return false;
	}

public:
	void post_lex(Lexer lexer) {
		std::string temp = "";
		Lexer::ccv ccv = lexer.get_ccv();
		Lexer::lev lev = lexer.get_lev();
		
		for (int i = 0; i < ccv.size(); ++i)
		{
			if (i == 0)
			{
				temp = ccv[i];
			}
			else
			{
				if (in_moa(temp + ccv[i]))
				{

				}
			}
		}
	}
};