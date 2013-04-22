#pragma once
#include "pozycja.h"
class wierza : public pozycja
{
public:
	int angle; 
	int zasieg;
	int damage;
	wierza(void);
	~wierza(void);
};

