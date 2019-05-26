#include "stdafx.h"
#include "Parm.h"
#include <iostream>
namespace Parm
{
	bool cheakIn(wchar_t arcg[], PARM* Input);//�������� �� ������� ��������� -in � ��� ����������
	bool cheakOut(wchar_t arcg[], PARM* Input);//�������� �� ������� ��������� -out � ��� ����������
	bool cheakLog(wchar_t arcg[], PARM* Input);//�������� �� ������� ��������� -out � ��� ����������
	
	PARM getparm(int argc, _TCHAR* argv[])
	{
		setlocale(LC_ALL, "");
		PARM Input = {}; //�������� ���������� ��������� ��� �������� ����������
		if (argc > 1 && argc < 5) //���� ������ 1-3 ��������� ��������� ����� ������
		{
			if (cheakIn((wchar_t*)argv[1], &Input)) //�������� �� ���������� ������� ��������� � -in � ��� ���������� , ����� ������
			{
				std::wcout << "Input.in: " << Input.in << std::endl;
			}
			else
			{
				//������: ��� ��������� in
				std::cout << "������ ��� ��������� in";
				throw "";
			}
			if ((argc > 2) && cheakOut((wchar_t*)argv[2], &Input)) //�������� �� ���������� ������� ��������� � -in � ��� ���������� , ����� ������
			{
				std::wcout << "Input.out: " << Input.out << std::endl;
			}
			else
			{
				wcscpy_s(Input.out, Input.in);//����������� � ������ Input.out ������ Input.in
				wcsncat_s(Input.out, PARM_OUT_DEFAULT_EXT, wcslen(PARM_OUT_DEFAULT_EXT)); // ���������� wcslen(PARM_OUT_DEFAULT_EXT) �������� ������ PARM_OUT_DEFAULT_EXT � Input.out
			}

			if ((argc > 3) && cheakLog((wchar_t*)argv[3], &Input)) //�������� �� ���������� ������� ��������� � -in � ��� ���������� , ����� ������
			{
				std::wcout << "Input.log: " << Input.log << std::endl;
			}
			else
			{
				wcscpy_s(Input.log, Input.in);//����������� � ������ Input.out ������ Input.in
				wcsncat_s(Input.log, PARM_LOG_DEFAULT_EXT, wcslen(PARM_LOG_DEFAULT_EXT)); // ���������� wcslen(PARM_OUT_DEFAULT_EXT) �������� ������ PARM_OUT_DEFAULT_EXT � Input.out
			}
		}
		else
		{
			std::cout << "ERROR";
			//������
		}
		std::wcout <<Input.log << std::endl;
		return Input;
	}

	bool cheakIn(wchar_t arcg[], PARM* Input)
	{
		if (wcsstr(arcg, PARM_IN) != NULL)// wcsstr(arcg, PARM_IN) ��������� �� ������� ������  PARM_IN � ������ arcg ���������� NULL ���� ������ �� �������
		{
			wcscpy_s(Input->in, &arcg[wcslen(PARM_IN)]); //�������� � Input.in , ���� � ������ ����� (���������� arcg , ������� � wcslen(PARM_IN)( ����� ������ PARM_IN))
		}
		else
		{
			return false;
		}
		return true;
	}

	bool cheakOut(wchar_t arcg[], PARM* Input)
	{
		if (wcsstr(arcg, PARM_OUT) != NULL)// wcsstr(arcg, PARM_IN) ��������� �� ������� ������  PARM_OUT � ������ arcg ���������� NULL ���� ������ �� �������
		{
			wcscpy_s(Input->out, &arcg[wcslen(PARM_OUT)]); //�������� � Input.in , ���� � ������ ����� (���������� arcg , ������� � wcslen(PARM_OUT)( ����� ������ PARM_OUT))
		}
		else
		{
			return false;
		}
		return true;
	}

	bool cheakLog(wchar_t arcg[], PARM* Input)
	{
		if (wcsstr(arcg, PARM_LOG) != NULL)// wcsstr(arcg, PARM_LOG) ��������� �� ������� ������  PARM_IN � ������ arcg ���������� NULL ���� ������ �� �������
		{
			wcscpy_s(Input->log, &arcg[wcslen(PARM_LOG)]); //�������� � Input.in , ���� � ������ ����� (���������� arcg , ������� � wcslen(PARM_LOG)( ����� ������ PARM_LOG))
		}
		else
		{
			return false;
		}
		return true;
	}

}