#pragma once
class Dice
{
private:
	int number;
	int sides;
	int values[12]{};
	int total = 0;
	int advantage;
	int crit = 0;
	int fumble = 0;
public:
	Dice();
	Dice(int num, int d, int advan);

	int getNumber();

	int getTotal();

	int getCrit();

	int getFumble();

	~Dice();
};

