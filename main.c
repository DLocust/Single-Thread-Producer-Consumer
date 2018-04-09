#ifdef WIN32
	char full_direct[100] = "C:\\temp\\coursein\\p1-in.txt";
	char full_direct2[100] = "C:\\temp\\courseout\\p1-out.txt";
#else
	char full_direct[100] = "./text.txt";
	char full_direct2[100] = "./textout.txt";
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time_functions.h"
#pragma warning(disable : 4996)
int main(){
	int mode;
	int c;
	FILE *file;
	FILE *filedest;
	file = fopen(full_direct, "r");
		if(file == NULL){
				printf("Error Retrieving File \n");
				printf("Could not retrieve file from the following directory: %s \n", full_direct);
				exit(1);
				}
	filedest = fopen(full_direct2, "w+"); 

	printf("Select mode 0 or 1: ");//This will create the newly written file in the mandatory folder
	scanf("%d",&mode);
	printf("The mode you selected was: %d \n", mode);
	char line [80];
	if (mode == 0){
		if (file){
			start_timing();
				while ((c = getc(file)) != EOF){
					fputc(c, filedest);
				}
				fclose(file);
				fclose(filedest);
			stop_timing();
			get_wall_clock_diff();
			get_CPU_time_diff();
			printf("The Wall Time was %lf seconds.\n", get_wall_clock_diff());
			printf("The CPU time was %lf seconds.\n", get_CPU_time_diff());
		}
	}
	else if (mode == 1){
		if (file){
			start_timing();
				
				while (fgets(line, sizeof line, file) != NULL) {
					fputs(line, filedest);
				}
				fclose(file);
				fclose(filedest);
			stop_timing();
			get_wall_clock_diff();
			get_CPU_time_diff();
			printf("The Wall Time was %lf seconds.\n", get_wall_clock_diff());
			printf("The CPU time was %lf seconds.\n", get_CPU_time_diff());
		}
	}
	else {
		printf("That's not a correct mode, try again \n");
	}
return 0;
}
