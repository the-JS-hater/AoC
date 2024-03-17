#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void part_one(){
  FILE *file_ptr;
  file_ptr = fopen("input.txt", "r");
  char file_line[4096];
  
  int answer = 0;

  while(fgets(file_line, 4096, file_ptr)){
    int l, w, h;
    sscanf(file_line, "%dx%dx%d", &l, &w, &h);

    int lw, lh, wh;
    lw = l * w;
    lh = l * h;
    wh = w * h;

    int area = 2 * lw + 2 * lh + 2 * wh;  
    
    int min_val;
    if(lw < lh) min_val = lw; else min_val = lh;
    if(wh < min_val) min_val = wh;
     
    answer += area + min_val;
  }

  printf("%d\n", answer);
  fclose(file_ptr);
}


int min(int a, int b){
  int min = (a < b) ? a : b;
  return min;
}

int max(int a, int b){
  int max = (a < b) ? b : a;
  return max;
}

void part_two(){
  FILE *file_ptr;
  file_ptr = fopen("input.txt", "r");
  char file_line[4096];
  
  int answer = 0;

  while(fgets(file_line, 4096, file_ptr)){
    int l, w, h;
    sscanf(file_line, "%dx%dx%d", &l, &w, &h);
    
    int bow = l * w * h;

    int smallest = min(l, min(w, h));
    int largest = max(l, max(w, h));
    int middle = l + w + h - smallest - largest;
    
    int wrapper = 2 * smallest + 2 * middle; 

    answer += wrapper + bow; 
  }

  printf("%d\n", answer);
  fclose(file_ptr);
}


int main(){
  part_one();
  part_two();
}
