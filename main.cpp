//main.cpp
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	uint32_t n = 0;
	uint64_t sum = 0;
	long fSize = 0;
       	uint32_t fStrlen = 0;	
	
	for(int i = 1; i < argc; i++){
		FILE* f = fopen(argv[i], "rb");
		if(!f) continue;

		fseek(f, 0, SEEK_END);
		fSize = ftell(f);
		rewind(f);
		if (fSize != 4) continue;

		fStrlen = strlen(argv[i]);
		if (fStrlen < 3) continue;
		if (strcmp("bin", argv[i] + fStrlen - 3)) continue;
	

		fread(&n, 4, 1, f);
		sum += ntohl(n);
		fclose(f);
	}
	printf("sum : %d", sum);
	return sum;
}
