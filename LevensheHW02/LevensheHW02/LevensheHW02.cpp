// LevensheHW02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LevensheHW02.h"
#include "TRADE_DATE.h"
#include <algorithm>
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			/*
			vector < TRADE_DATE> TDArray;
			for (int i = 0; i < 100000; i++)
			{
				TRADE_DATE td;
				TDArray.push_back(td);
			}
			*/
#define ArraySize 10

			std::array<TRADE_DATE, ArraySize>TDArray;
			struct {
				bool operator()(TRADE_DATE a, TRADE_DATE b)
				{
					if (std::get<0>(a.begin_date) != std::get<0>(b.begin_date)) return std::get<0>(a.begin_date) <  std::get<0>(b.begin_date);
					if (std::get<1>(a.begin_date) != std::get<1>(b.begin_date)) return std::get<1>(a.begin_date) <  std::get<1>(b.begin_date);
					if (std::get<2>(a.begin_date) != std::get<2>(b.begin_date)) return std::get<2>(a.begin_date) <  std::get<2>(b.begin_date);
					
				}
			} customLess;

			std::sort(TDArray.begin(), TDArray.end(), customLess);

			for (auto a : TDArray) {
				std::cout << "\n " << a.duration << ", " << std::get<0>(a.begin_date) << ", " << std::get<1>(a.begin_date) << ", " << std::get<2>(a.begin_date);
			}
			std::cout << '\n';
			TRADE_DATE aaa, bbb;
			auto lower = std::lower_bound(TDArray.begin(), TDArray.end(), aaa, customLess);
			auto upper = std::upper_bound(TDArray.begin(), TDArray.end(), bbb, customLess);

			std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));


			



		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}
	::getchar();
	return nRetCode;
}
