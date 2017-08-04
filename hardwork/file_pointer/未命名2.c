#include<stdio.h>

int main() {
	int a;
	char str[20];
	double b;
	
	FILE * p;
	if((p = fopen("001.txt","w")) == NULL) {
		printf("ERROR");
	}
	else {
		printf("ENTER\n");
		printf("? ");
		scanf("%d%s%lf",&a,str,&b);
		while(!feof(stdin)) {
			fprintf(p,"%d%s%.2f",a,str,b);
			printf("? ");
			scanf("%d%s%lf",&a,str,&b);
		}
	fclose(p);
	}
	
	return 0;
} 
