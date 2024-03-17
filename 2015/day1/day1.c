#include <stdio.h>
#include <string.h>


void part_one(){
  FILE *file_ptr;
  file_ptr = fopen("input.txt", "r");
  char file_content[4096];
  
  int floor = 0;  

  while(fgets(file_content, 4096, file_ptr)){
    for(int i = 0; i < strlen(file_content); i++){
      if(file_content[i] == '(') floor++;
      if(file_content[i] == ')') floor--;
    }
  }

  printf("%d\n", floor);
  fclose(file_ptr);
}


void part_two(){
  FILE *file_ptr;
  file_ptr = fopen("input.txt", "r");
  char file_content[4096];
  
  int floor = 0;  
  int pos = 0;

  while(fgets(file_content, 4096, file_ptr)){
    for(int i = 0; i < strlen(file_content); i++){
      if (floor < 0) goto end; else pos++;
      if(file_content[i] == '(') floor++;
      if(file_content[i] == ')') floor--;
    }
  }
  
  end:
  printf("%d\n", pos);
  fclose(file_ptr);
}

int main() {
  part_one();
  part_two();
}
