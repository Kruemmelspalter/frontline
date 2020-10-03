#pragma once

#include "Lexer_pre.h"
#include <string>

class PostLexer
{
private:
	const char *multi_op[17] = {"::", "->", "|>", "<|", "&&", "||", "\"\"", "\'\'", "##", "!=", "==", "?=", "//", "/*", "*/", "<<", ">>"}; //operrators with more than one char

	bool in_moa(std::string to_)
	{ // "in multi-operator-array"

		for (int i = 0; i < sizeof(multi_op); ++i)
		{
			if (to_ == multi_op[i])
			{
				return true;
			}
		}
		return false;
	}

	enum lexeme_em
	{
		UNKNOWN,
		OPERATOR, // "+,-,/,*,<,>,=,.,~,?,..."
		Ctypes,	  // "(,),[,..."
		SYM,	  // ";"
		KEYWORD,  // int,class,namespace,...
	};
	std::vector<lexeme_em> vec_em; //token in enum-form	"vector_enum"

	typedef Lexerpre::ccv ccv;
	Lexerpre::ccv preccv;
	Lexerpre::ccv new_ccv;

public:
	typedef std::vector<lexeme_em> lev;
	lev get_lev()
	{
		return vec_em;
	}

	Lexerpre::ccv get_n_ccv()
	{
		return new_ccv;
	}

	void post_lex(Lexerpre &lexer)
	{
		std::string temp = "";
		preccv = lexer.get_ccv();

		for (int i = 0; i < preccv.size(); ++i)
		{
			temp = preccv[i] + (std::string)preccv[i + 1];

			if (in_moa(temp))
			{
				preccv.push_back(temp.c_str());
				temp.clear();
				i += 1;
			}
			else
			{
				temp.clear();
				new_ccv.push_back(preccv[i]);
			}
		}
	}
};