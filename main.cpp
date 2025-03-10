//main.cpp
#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	uint32_t n = 0;
	int sum = 0;

	// 1. file == NULL
	// 2. 4byte check
	// 3. not number
	// 4. not duplication
	for(int i = 1; i < argc; i++){
		FILE* f = fopen(argv[i], "rb");
		fread(&n, 4, 1, f);
		sum += ntohl(n);
		fclose(f);
	}
	printf("sum : %d", sum);
	return sum;
}
