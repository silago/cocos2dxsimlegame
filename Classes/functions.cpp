#include "functions.h"

char inttostr(int i)
{
	 char str[2];	
	 str[0] = i + '0';
     str[1] = 0; //
     return *str;
}
