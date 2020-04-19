#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "exp10to2.h"

int main(int argc, const char **argv)
{
    const char *numberStr = NULL;
	struct Number n;
	int error = 0;
    --argc; ++argv; // skip name of executable itself
    while (!error && argc)
    {
        if (strcmp(*argv,"-n") == 0)
        {
            --argc; ++argv;
            if (argc)
            {
                numberStr = *argv;
                --argc; ++argv;
            }
            else
            {
				fprintf(stderr,"-n should be followed by a number\n");
				error = 1;
            }
        }
    }
    if (!error && numberStr)
	{
		// no errors encountered
		parse(numberStr, &n);
		exp10ToExp2(&n);
	}
    return 0;
}
