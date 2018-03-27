#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "crc32.h"

int main( int argc, char *argv[] )
{
	if (argc <=1){
		printf( "Usage: crc32 string\n" );
		return -1;
	}
	//int argv1l=strlen(argv[1]);
	uint32_t crc = crc32(argv[1],strlen(argv[1]));
	//crc32(argv[1],strlen(argv[1]));
	printf("%u\n", crc);
	printf("0x%x\n", crc);
	return 0;
}
