#include "stdafx.h"
#include "In.h"
#include "Error.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

In::IN getin(wchar_t infile[])
{
	ifstream fin(infile);					// открыли файл для чтения
	if (!fin.is_open())						// если файл не открыт
		ERROR_THROW (110)					// ?????как выбросить 110 ошибку??
	else
	{
		In::IN tmp;							//создаём временные переменные
		tmp.lines = 0;
		tmp.size = 0;
		tmp.ignor = 0;
		for (int i = 0; i < 256; i++)
		{
			/*IN_CODE_TABLE[i];
			tmp.code[i] = 
			Как-то нужно заполнить массив code из таблицы, думаю для этого нужен enum, но не понимаю почему у него нет имени
			*/
		}
		string tmp_str;
		while (!fin.eof())
		{
			if (getline(fin, tmp_str))
				tmp.lines++;
			tmp.size += tmp_str.length();
			for (int i = 0; i < tmp_str.length(); i++)
			{
				tmp_str[i];
			}
		}
		fin.close();
	}
}
