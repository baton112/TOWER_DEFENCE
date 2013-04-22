#pragma once
#include "pozycja.h"
class potworek : public pozycja
{
public:
	int zycie;
	int damage;
	int predkosc;
	int zasieg;
	void virtual przesun();
	void virtual atakuj();
	potworek(void);
	~potworek(void);
};

