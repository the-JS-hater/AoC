#include<stdio.h>
#include<set>
#include<utility>
#include<string.h>
#include<vector>

int partOne(){
  std::set<std::vector<int>> visited;

  FILE *file_ptr;
  file_ptr = fopen("input.txt", "r");
  char file_line[4096];
  
  std::vector<int> current_location = {0, 0};
  visited.insert(current_location);

  while(fgets(file_line, 4096, file_ptr)){
    for (int i = 0; i < strlen(file_line); i++){
      switch (file_line[i]) {
        case '>':
          current_location[0]++;
          visited.insert(current_location);
          break;
        case '<':
          current_location[0]--;
          visited.insert(current_location);
          break;
        case 'v':
          current_location[1]--;
          visited.insert(current_location);
          break;
        case '^':
          current_location[1]++;
          visited.insert(current_location);
          break;
      }
    }
  }

  return visited.size(); 
}


int partTwo(){
  std::set<std::vector<int>> visited;

  FILE *file_ptr;
  file_ptr = fopen("input.txt", "r");
  char file_line[4096];
 
  bool santasTurn = true; //santa 0, robo_santa 1
  std::vector<int> santa_location = {0, 0};
  std::vector<int> robo_santa_location = {0, 0};
  visited.insert(santa_location);
  
  std::vector<std::vector<int>> santa_matrix = {santa_location, robo_santa_location}; //the santa matrix, lol
  while(fgets(file_line, 4096, file_ptr)){
    for (int i = 0; i < strlen(file_line); i++){
      int index = (int)santasTurn;
      switch (file_line[i]) {
        case '>':
          santa_matrix[santasTurn][0]++;
          visited.insert(santa_matrix[santasTurn]);
          break;
        case '<':
          santa_matrix[santasTurn][0]--;
          visited.insert(santa_matrix[santasTurn]);
          break;
        case 'v':
          santa_matrix[santasTurn][1]++;
          visited.insert(santa_matrix[santasTurn]);
          break;
        case '^':
          santa_matrix[santasTurn][1]--;
          visited.insert(santa_matrix[santasTurn]);
          break;
      }

      santasTurn = !santasTurn;
    }
  }

  return visited.size(); 
  
}


int main(){
  printf("Part one: %d \n", partOne()); 
  printf("Part two: %d \n", partTwo());
}
