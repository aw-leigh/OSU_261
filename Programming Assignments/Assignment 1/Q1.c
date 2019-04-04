/* CS261- Assignment 1 - Q.1*/
/* Name: Andrew Wilson
 * Date: 4/4/2019
 * Solution description: Implemented as per detailed instructions using the Fisher Yates shuffle
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     int numStudents = 10;
	struct student *students = malloc(numStudents * sizeof(struct student));

     /*Return the pointer*/
     return students;
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
     IDs being between 1 and 10, scores between 0 and 100*/

     int IDs[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     int j, temp;

     //Fisher Yates shuffle, modified from: https://qr.ae/TW19Cb

     //loop through the array backwards
     for(int i = 10 - 1; i >= 0; i--) 
     {
          //choose a j between 0 and i, 
          j = rand() % (i + 1); 
          //and swap the numbers at those indices
          temp = IDs[j];
          IDs[j] = IDs[i];
          IDs[i] = temp;
     }

     for(int i = 0; i < 10; i++)
     {
          (students + i)->id = IDs[i];
          (students + i)->score = (rand() % 101);
     }
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

     for(int i = 0; i < 10; i++)
     {
          printf("%d", (students + i)->id);
          printf(" %d\n", (students + i)->score);
     }

}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the 
ten students*/
     int min, max, avg;
     max = avg = 0;
     min = 100; //set min to a high score, as we looking for smaller values
     
     for(int i = 0; i < 10; i++)
     {
          avg += (students + i)->score; //sum up all scores

          if((students + i)->score > max)
          {
               max = (students + i)->score;
          }
          else if((students + i)->score < min)
          {
               min = (students + i)->score;
          }
     }

     avg /= 10; //divide by number of students

     printf("\nThe minimum score is %d\n", min);
     printf("The maximum score is %d\n", max);
     printf("The average score is %d\n", avg);
          
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
}

int main(){
    srand(time(0));
    struct student* stud = NULL;
    
    /*Call allocate*/
    stud = allocate(); //stud points to beginning of student memory chunk
    
    /*Call generate*/
    generate(stud);
    
    /*Call output*/
    output(stud);
    
    /*Call summary*/
    summary(stud);
    
    /*Call deallocate*/
    free(stud);

    return 0;
}

