 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Number 10

struct login_data{ 
  char id[20]; 
  char password[20]; 
};

void all_user(struct login_data * userlist[], int count); 
int load_list(struct login_data * userlist[]);

int main(void) {
  struct login_data * userlist[Number];// 10명의 로그인 데이터 보관용 포인터 배열
  for(int i=0;i<Number;i++)
    userlist[i]= (struct login_data *) malloc(sizeof(struct login_data));

  int user_count = 0;

  user_count = load_list(userlist);
  all_user(userlist,user_count);
  
  return 0;
}

void all_user(struct login_data * userlist[], int count){
  printf("\n");
  printf("등록된 사용자 목록\n");
  printf("No\t ID\t Password\n");
  for(int i=0;i<count;i++)
    printf("%d\t %s\t %s\n",i+1,userlist[i]->id,userlist[i]->password);
}

int load_list(struct login_data * userlist[]){
  FILE* fp = NULL;
  
  fp = fopen("user.txt","rt");
  
  int count = 0;
  while(!feof(fp)){
   fscanf(fp,"%s %s",userlist[count]->id,userlist[count]->password);
    count++;
  }
    
  printf("\n");
  printf("user.txt에서 %d명의 사용자 정보 읽어들였습니다.\n",count);
  
  fclose(fp);
  
  return count;
}