#include<stdio.h>
#include<set>
#include<utility>
#include<string.h>

void part_one(){
  std::set<std::pair<int, int>> visited;

  FILE *file_ptr;
  file_ptr = fopen("input.txt", "r");
  char file_line[4096];
  
  int x = 0; 
  int y = 0;

  while(fgets(file_line, 4096, file_ptr)){
      for (int i = 0; i < strlen(file_line); i++){
         switch (file_line[i]) {
             case 
         }
      }
  }
}


int main(){
    
}
