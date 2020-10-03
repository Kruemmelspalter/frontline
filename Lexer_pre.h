#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <string>

class Lexerpre
{
private:
	char spe[10] = {')', '(', ',', ' ', '.', '[', ']', '{', '}', ';'};

	bool is_spec(char what)
	{

		for (int i = 0; i < sizeof(spe); ++i)
		{
			if (what == spe[i])
			{
				return true;
			}
		}
		return false;
	}

	int get_file_length(const char *file_name)
	{
		std::fstream temp;

		temp.open(file_name);
		temp.seekg(0, temp.end);
		int length = temp.tellg();
		temp.seekg(0, temp.beg);

		temp.close();
		return length;
	}

	std::vector<const char *> vec_conchar; //tokens				"vector_const-chars"

	std::fstream file;
	std::string raw_code = "";
	char *buffer;
	const char *filename = "";
	bool faild = false;

public:
	typedef std::vector<const char *> ccv; // "const char vector"

	Lexerpre(std::string file_name)
	{
		filename = file_name.c_str();
		file.open(file_name);
		if (!file.is_open())
		{
			perror("Error by reading file...");
			faild = true;
		}
	}

	Lexerpre()
	{
	}

	~Lexerpre()
	{
		file.close();
	}

	bool stup(const char *filename)
	{
		this->filename = filename;
		file.open(this->filename);
		if (!file.is_open())
		{
			perror("Error by stup()...");
			faild = true;
			return true;
		}
	}

	ccv get_ccv()
	{
		return vec_conchar;
	}

	int lex()
	{
		std::string temp = "";
		file.read(buffer, get_file_length(filename));
		if (buffer == nullptr)
		{
			perror("Error by lex()... ");
			system("pause");
			return -1;
		}
		else
		{
			raw_code = (std::string)buffer;
		}
		for (int i = 0; i < raw_code.length(); ++i) //fill vec_conchar with chars
		{
			if (is_spec(raw_code[i]))
			{
				if (temp != "")
				{
					vec_conchar.push_back(temp.c_str());
				}
				vec_conchar.push_back((const char *)raw_code[i]);

				temp.clear();
			}
			else
			{
				temp += raw_code[i];
			}
		}
		return 0;
	}
};