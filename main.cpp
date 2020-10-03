#include "Lexer.h"
#include <iostream>

int main()
{
	aLexer lexer("test.txt");
	lexer.run();
	Lexerpre::ccv to_print = lexer.get_ccv();

	for (int i = 0; i < to_print.size(); ++i)
	{
		std::cout << "token num" << i << ": " << to_print[i] << "\n";
	}
}