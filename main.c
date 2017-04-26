#include <stdio.h.>
#include <string.h.>

#define MEMORY_FOR_RATE 50
#define FILE_NAME "d:\\rate.bin"

struct Rate
{
	float BynToUsd;
	float UsdToByn;
	float BynToEuro;
	float EuroToByn;
};

void writeFile(float* buff, struct Rate* rate)
{
	FILE* file = fopen(FILE_NAME, "rb");
	/*scanf("%f", rate->BynToUsd);
	printf("BYN - USD = %.2f");*/
	if (file == NULL)
	{
		file = fopen(FILE_NAME, "wb");
		fwrite(buff, 1, sizeof(buff), file);
		fclose(file);
		return 0;
	}
	fread(buff, 1, sizeof(buff), file);
	printf("%s\n", buff);
}

int main()
{
	char buff[] = {"ALLO"};
	struct Rate* rate = malloc(sizeof(struct Rate));
	writeFile(buff, rate);
}
