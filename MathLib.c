#include <stdlib.h>
#include "ErrorLog.h"

unsigned char Math_Add(unsigned char param_1, unsigned char param_2)
{
	if ((param_1 + param_2) > 255)
	{
		ErrLog_Log();
		exit(0);
	}
	return param_1 + param_2;
}