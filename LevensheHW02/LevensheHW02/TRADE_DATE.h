#pragma once
#include <tuple>
#include <random>
#include <vector>
using namespace std;

class TRADE_DATE
{
public:
	TRADE_DATE();
	~TRADE_DATE();
	int ID;
	tuple<int, int, int>begin_date;
	tuple<int, int, int>end_date;
	int duration;
	void Generator()
	{
		std::random_device rd;
		std::uniform_int_distribution<int> dist(1, 10);
		duration=dist(rd); 
		std::uniform_int_distribution<int> year(1900, 2000);
		std::uniform_int_distribution<int> month(1, 12);
		std::uniform_int_distribution<int> day(1, 30);
		begin_date = make_tuple(year(rd), month(rd), day(rd));
		end_date = make_tuple(year(rd), month(rd), day(rd));

	}

};

