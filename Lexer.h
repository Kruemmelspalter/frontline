#pragma once
#include "Lexer_post.h"
#include "Lexer_pre.h"

class aLexer
{
private:
	Lexerpre lpre;
	PostLexer pl;
	const char *filename;
	Lexerpre::ccv last_ccv;
	PostLexer::lev last_lev;

public:
	aLexer(const char *filename)
	{
		this->filename = filename;
	}

	int run()
	{
		if (lpre.stup(filename) == true)
		{
			system("pause");
			return -1;
		}
		if (lpre.lex() == -1)
		{
			return -1;
		}

		pl.post_lex(lpre);

		last_ccv = pl.get_n_ccv();
		last_lev = pl.get_lev();

		return 0;
	}

	Lexerpre::ccv get_ccv()
	{
		return last_ccv;
	}

	PostLexer::lev get_lev()
	{
		return last_lev;
	}
};