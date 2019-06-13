/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tarea2.c
 * Author: sebam
 *
 * Created on August 9, 2018, 5:45 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define PATH "unsorted.csv"
#define destinationPATH "sorted.csv"
#define size 50
void sort_array(int array[]);
void write_sorted_array_file(int array[]);

void read_file(){

    // open the file for reading
    FILE *file = fopen(PATH, "r");
    int lineArray[size];
    int i = 0;
    if(NULL == file)
    {
        printf("Cannot open file: %s\n");
       
    }
    size_t buffer_size = 20;
    char *buffer = malloc(buffer_size * sizeof(char));

    while(-1 != getline(&buffer, &buffer_size, file))
    {
        lineArray[i] = atoi(buffer);
        i++;
    }
    fflush(stdout);

    // make sure we close the file and clean up the buffer when we're
    // finished
    fclose(file);
    free(buffer);
    sort_array(lineArray);
}

void sort_array(int array[]){
    int j,i,temp,position;
     for ( i = 0 ; i < size-1 ; i++ )
   {
      position = i; 
      for ( j = i + 1 ; j < size ; j++ )
      {
         if ( array[position] > array[j] )
            position = j;
      }
      if ( position != i )
      {
         temp = array[i];
         array[i] = array[position];
         array[position] = temp;
      }
   }
    write_sorted_array_file(array);
}



void write_sorted_array_file(int array[]){
    FILE *f = fopen(destinationPATH, "wb");
    int i;
    for(i = 0; i < size ; i++){
    fprintf(f, "%d\n", array[i]);
    }
    fclose(f);
}

void print_array(int array[]){
    int i;
    for(i = 0; i < size; i++){
        printf("\n%d",array[i]);
        
    }
}


int main(int argc, char** argv) {
    read_file();
    return (EXIT_SUCCESS);
}
