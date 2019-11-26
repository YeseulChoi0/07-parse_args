#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "header.h"

int main(){
  char * line = strdup("ls -a -l");
  //printf("THIS IS WOKRING\n");
  char ** arguments = parse_args(line);
  //printf("PLEASE WORK\n");
  printf("%s\n", arguments[0]);
  execvp(arguments[0], arguments);
}

char ** parse_args( char * line ){
  char ** arguments = calloc(sizeof(char*), 6);
  //printf("this is working?\n");
  char * s1 = line;
  char * token;

  int i;
  int si;
  for (i = 0; i < 6; i++){
    //printf("is this working?\n");
    arguments[i] = calloc(100, 1);
    token = strsep(&s1, " ");
    //printf("testing0\n");
    arguments[i] = token;
    if (token == '\0'){
      break;
    }
    //printf("%token: s\n", token);
    //printf("THIS IS THE PROBLEM\n");
  }
  return arguments;

}
