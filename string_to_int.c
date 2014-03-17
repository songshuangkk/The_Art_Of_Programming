#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Str_To_Int (char *str)
{
	int num = 1;
	int sum = 0;
	int i;
	int len = strlen(str);

	while(*str)
	{
		for(i=1; i<len-1; i *= 10)
		{
			num = num*i;
		}
		len--;
		sum = sum + (*str - '0')*num;
		num = 1;
		str++;
	}
	return sum;
}

int
main(int argc, const char *argv[])
{
	char str[20] = {};
	
	fgets(str, 20, stdin);
	
	printf("Str_to_Int: %d\n", Str_To_Int(str));
	return 0;
}
