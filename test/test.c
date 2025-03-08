#include <stdio.h>

#include "../src/number_reader.h"

int main(int argc, const char** argv)
{
	int i;
	// Argument Error
	if (argc < 2)
	{
		printf("Hatali arguman!\n");
		return 0;
	}
	// Read Numbers
	for (i = 1; i < argc; i++)
	{
		printf("%s: ", argv[i]);
		read_number(argv[i]);
		printf("\n");
	}
	return (0);
}
