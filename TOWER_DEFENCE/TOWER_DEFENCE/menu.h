#pragma once

enum stan_gry_enum
{
	ekran_startrowy,
	gra,
	pauza
};

class menu
{
public:
	stan_gry_enum stan_gry;
	menu(void);
	~menu(void);
};

