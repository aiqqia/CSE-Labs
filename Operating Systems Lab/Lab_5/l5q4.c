#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fout;
	int num = 0;
	fout = fopen("my_binary_file.bin", "wb+");

	printf("Enter any 4 numbers: \n");
	for(int i=0;i<4;i++){
		scanf("%d", &num);
		fwrite(&num, sizeof(int), 1, fout);
	}

	printf("Writing complete!\n");
	fclose(fout);

	printf("Now, reading the binary file...\n");

	fout = fopen("my_binary_file.bin", "rb");

	for(int i=0;i<4;i++){
		fread(&num, sizeof(int), 1, fout);
		printf("%d\n", num);
	}
	fclose(fout);

	return 0;
}