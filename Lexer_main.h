#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <string>

class Lexer
{
private:
	char spe[10] = { ')','(',',',' ','.','[',']','{','}',';' };

	bool is_spec(char what) {

		for (int i = 0; i < sizeof(spe); ++i)
		{
			if (what == spe[i])
			{
				return true;
			}
		}
		return false;
	}

	int get_file_length(const char* file_name) {
		std::fstream temp;

		temp.open(file_name);
		temp.seekg(0, temp.end);
		int length = temp.tellg();
		temp.seekg(0, temp.beg);

		temp.close();
		return length;
	}

	enum lexer_em {
		UNKNOWN,
		OPERATOR,	// "+,-,/,*,<,>,=,.,~,?,..."
		Ctypes,		// "(,),[,..."
		SYM,		// ";"
		KEYWORD,	// int,class,namespace,...
	};

	std::vector<const char*> vec_conchar;	//tokens				"vector_const-chars"
	std::vector<lexer_em> vec_em;			//token in enum-form	"vector_enum"

	std::fstream file;
	std::string raw_code = "";
	char* buffer;
	const char* filename = "";
public:
	typedef std::vector<const char*> ccv;	// "const char vector"
	typedef std::vector<lexer_em> lev;		// "lever enum vector"

	Lexer(const char* file_name) {
		filename = file_name;
		file.open(file_name);
	}

	~Lexer() {
		file.close();
	}

	ccv get_ccv() {
		return vec_conchar;
	}

	lev get_lev() {
		return vec_em;
	}

	void lex() {
		std::string temp;
		file.read(buffer, get_file_length(filename));
		raw_code = buffer;

		for (int i = 0; i < raw_code.length(); ++i)		//fill vec_conchar with chars
		{
			if (is_spec(raw_code[i]))
			{
				vec_conchar.push_back(temp.c_str());
				vec_conchar.push_back((const char*)raw_code[i]);

				temp.clear();
			}
			else
			{
				temp += raw_code[i];
			}
		}
	}
};