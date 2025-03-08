#ifndef C_RANDOM_H
#define C_RANDOM_H

/* INCLUDES */
#include <stdio.h>
#include <stdbool.h>

/* DEFINES */
#define LARGE_NUMBER_COUNT 57
#define MAX_LENGTH LARGE_NUMBER_COUNT * 3 

/* STATIC VARIABLES */
static const char onesAndTens[2][10][7] = {
	{"", "Bir", "Iki", "Uc", "Dort", "Bes", "Alti", "Yedi", "Sekiz", "Dokuz"},
	{"", "On", "Yirmi", "Otuz", "Kirk", "Elli", "Altmis", "Yetmis", "Seksen", "Doksan"}
};

static const char largeNumberNames[LARGE_NUMBER_COUNT][23] = {
	"", "Bin", "Milyon", "Milyar", 
	"Trilyon", "Katrilyon", "Kentilyon", "Seksilyon", 
	"Septilyon", "Oktilyon", "Nonilyon", "Desilyon", 
	"Undesilyon", "Dodesilyon", "Tredesilyon", "Kattuordesilyon", 
	"Kendesilyon", "Sexdesilyon", "Septendesilyon", "Oktodesilyon",
	"Novemdesilyon", "Vigintilyon", "Unvigintilyon", "Dovigintilyon", 
	"Trevigintilyon", "Kattuorvigintilyon", "Kenvigintilyon", "Sexvigintilyon", 
	"Septenvigintilyon", "Oktovigintilyon", "Novemvigintilyon", "Trigintilyon", 
	"Untrigintilyon", "Dotrigintilyon", "Tretrigintilyon", "Kattuortrigintilyon", 
	"Kentrigintilyon", "Sextrigintilyon", "Septentrigintilyon", "Oktotrigintilyon", 
	"Novemtrigintilyon", "Katragintilyon", "Unkatragintilyon", "Dokatragintilyon", 
	"Trekatragintilyon", "Kattuorkatragintilyon", "Kenkatragintilyon", "Sexkatragintilyon", 
	"Septenkatragintilyon", "Oktokatragintilyon", "Novemkatragintilyon", "Kenquagintilyon", 
	"Unkenquagintilyon", "Dokenquagintilyon", "Trekenquagintilyon", "Kattuorkenquagintilyon", 
	"Kenkenquagintilyon"
};

/* FUNCTIONS */
bool read_number(const char number[]);

#endif
