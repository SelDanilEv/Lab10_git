#include "stdafx.h"
#include "Parm.h"
#include <iostream>
namespace Parm
{
	bool cheakIn(wchar_t arcg[], PARM* Input);//ѕроверка на наличие параметра -in и его заполнение
	bool cheakOut(wchar_t arcg[], PARM* Input);//ѕроверка на наличие параметра -out и его заполнение
	bool cheakLog(wchar_t arcg[], PARM* Input);//ѕроверка на наличие параметра -out и его заполнение
	
	PARM getparm(int argc, _TCHAR* argv[])
	{
		setlocale(LC_ALL, "");
		PARM Input = {}; //создание экземпл€ра структуры дл€ хранени€ информации
		if (argc > 1 && argc < 5) //если введен 1-3 параметра выполн€ем иначе ошибка
		{
			if (cheakIn((wchar_t*)argv[1], &Input)) //проверка на совпадение первого параметра с -in и его заполнение , иначе ошибка
			{
				std::wcout << "Input.in: " << Input.in << std::endl;
			}
			else
			{
				//ошибка: нет аргумента in
				std::cout << "ошибка нет аргумента in";
				throw "";
			}
			if ((argc > 2) && cheakOut((wchar_t*)argv[2], &Input)) //проверка на совпадение первого параметра с -in и его заполнение , иначе ошибка
			{
				std::wcout << "Input.out: " << Input.out << std::endl;
			}
			else
			{
				wcscpy_s(Input.out, Input.in);//копирование в строку Input.out строки Input.in
				wcsncat_s(Input.out, PARM_OUT_DEFAULT_EXT, wcslen(PARM_OUT_DEFAULT_EXT)); // добавление wcslen(PARM_OUT_DEFAULT_EXT) символов строки PARM_OUT_DEFAULT_EXT в Input.out
			}

			if ((argc > 3) && cheakLog((wchar_t*)argv[3], &Input)) //проверка на совпадение первого параметра с -in и его заполнение , иначе ошибка
			{
				std::wcout << "Input.log: " << Input.log << std::endl;
			}
			else
			{
				wcscpy_s(Input.log, Input.in);//копирование в строку Input.out строки Input.in
				wcsncat_s(Input.log, PARM_LOG_DEFAULT_EXT, wcslen(PARM_LOG_DEFAULT_EXT)); // добавление wcslen(PARM_OUT_DEFAULT_EXT) символов строки PARM_OUT_DEFAULT_EXT в Input.out
			}
		}
		else
		{
			std::cout << "ERROR";
			//ошибка
		}
		std::wcout <<Input.log << std::endl;
		return Input;
	}

	bool cheakIn(wchar_t arcg[], PARM* Input)
	{
		if (wcsstr(arcg, PARM_IN) != NULL)// wcsstr(arcg, PARM_IN) провер€ет на наличие строки  PARM_IN в строке arcg возвращает NULL если строку не находит
		{
			wcscpy_s(Input->in, &arcg[wcslen(PARM_IN)]); // опируем в Input.in , путь к нашему файлу (содержимое arcg , начина€ с wcslen(PARM_IN)( длины строки PARM_IN))
		}
		else
		{
			return false;
		}
		return true;
	}

	bool cheakOut(wchar_t arcg[], PARM* Input)
	{
		if (wcsstr(arcg, PARM_OUT) != NULL)// wcsstr(arcg, PARM_IN) провер€ет на наличие строки  PARM_OUT в строке arcg возвращает NULL если строку не находит
		{
			wcscpy_s(Input->out, &arcg[wcslen(PARM_OUT)]); // опируем в Input.in , путь к нашему файлу (содержимое arcg , начина€ с wcslen(PARM_OUT)( длины строки PARM_OUT))
		}
		else
		{
			return false;
		}
		return true;
	}

	bool cheakLog(wchar_t arcg[], PARM* Input)
	{
		if (wcsstr(arcg, PARM_LOG) != NULL)// wcsstr(arcg, PARM_LOG) провер€ет на наличие строки  PARM_IN в строке arcg возвращает NULL если строку не находит
		{
			wcscpy_s(Input->log, &arcg[wcslen(PARM_LOG)]); // опируем в Input.in , путь к нашему файлу (содержимое arcg , начина€ с wcslen(PARM_LOG)( длины строки PARM_LOG))
		}
		else
		{
			return false;
		}
		return true;
	}

}