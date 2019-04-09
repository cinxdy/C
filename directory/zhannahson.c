#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct menu{
	int no;
	char name[20];
	char madein[20];
	int price;
};

void save_menu(struct menu *list[]){
	FILE *p = fopen("menu.txt","wt");
	int i=0;
	while(i!=SIZE){
		list[i]=(struct menu*)malloc(sizeof(struct menu));
		printf("%d번째 메뉴의 번호,메뉴명, 원산지, 가격을 입력하시오.\n",i+1);
		scanf("%d %s %s %d",&list[i]->no, list[i]->name, list[i]->madein, &list[i]->price);
		fprintf(p,"%d %s %s %d\n",list[i]->no, list[i]->name, list[i]->madein, list[i]->price);
		i++;
	}
	fclose(p);
}

int main(void) {
	int i=0;
	struct menu *mymenu[5];
	save_menu(mymenu);
	FILE *fp = fopen("menu.txt","rt");
	printf("메뉴번호\t 메뉴이름\t 원산지\t 1인분가격\n");
	for(i = 0; i<SIZE ;i++){
		mymenu[i]=(struct menu*)malloc(sizeof(struct menu));
		fscanf(fp, "%d\t %s\t %s\t %d\n", &mymenu[i]->no, mymenu[i]->name, mymenu[i]->madein, &mymenu[i]->price);

		printf("%d\t %s\t %s\t %d\n",mymenu[i]->no, mymenu[i]->name, mymenu[i]->madein, mymenu[i]->price);
	}
	fclose(fp);
  	return 0;
}


