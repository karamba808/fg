/* 

   exampleApplication.cpp - application file for a program named example
   =====================================================================

   This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers. 

   The functionality of the program is defined as follows.
   
   Read data fom an input file called "input.txt" then store it to the pointer to the file called "fp_in", write it to the terminal, 
   and also write a version of it to an output file.

   The message to be written to file should be prepended with the following text:

   Input
   -----
   While reading data from input file, the first line is the integer that shows the number of test cases that are going to be processed which relay in range
   from 1 to 10 inclusively. This test case is also known as ant paths that are in the input file. Each path  has a number of locations that have been made by the ant
   as well as the corresponsing time. The negative time shows the end of each test case or ant path which means time must be positive in each test case. Therefore,
   the range that x coordinate and y coordinate relay between -450 and 450.

   Output
   ------
   The output file content  begins with the display of student Andrew Id(gkaramba).
   For Each test case in output file, is composed of 4 different field such as unique id number, time, x coordinate and y coordinate.
   For Each loation, there have been truncation that remove every number after the dot i.e. if x coordinate is 10.999, it will be truncated to 10.

   As there are some duplication of location on some teast cases in input file, output file's test case is composed of distinct location for every test case. However,
   each test is treated separately that is to say certain location can be present in different test cases.

   For every test case, unique identifications start from 1. In addition, a line composed of dash (-) shows the end of each test case in output file.

 

   Sample Input
   ------------
   2
0.000 0.000 0.000
0.100 0.050 0.000
0.200 0.100 0.000
0.300 0.190 0.000
1.300 0.000 1.020
1.400 0.000 2.000
1.500 0.000 2.000
1.600 0.000 4.000
1.700 0.000 4.090
1.800 0.000 5.000
1.900 0.000 4.000
2.000 0.000 2.000
-1.00 0.000 0.000
60.063	-28.247 20.743
60.165	-28.292 20.564
60.267	-28.430 20.522
60.370	-28.442 20.456
62.223	-30.683 18.633
64.456	-29.283 17.090
64.559	-29.019 17.464
64.667	-28.514 18.610
-1.00   0.000   0.000


   Sample Output
   -------------

   gkaramba
  1	 0.000    0     0 
  2	 1.300    0     1 
  3	 1.400    0     2 
  4	 1.600    0     4 
  5	 1.800    0     5 
-------------
  1	60.063  -28    20 
  2	62.223  -30    18 
  3	64.456  -29    17 
  4	64.667  -28    18 
-------------

   Solution Strategy
   -----------------

   The program begins by reading the test case value from the input file and store it to a variable. Without exceeding the test case value, the program loops in 
	the input file reading all sets of locations and prints them on both the terminal and the output file.

	While reading, the program checks whether the value of t is greater or equal to zero(0). if the condition is true, it then calls the store_location() function 
	to check if the values of x and y coordinates exist in the array of structure location[] of location_type as type. 

	The returned unique id number is then used in writing to the output file, then the program  prints the id number, time(t),x and y location coordinates 
	values to the terminal as well as to the the ouput file. 

	I the time t is negative, it prints dashes to both the terminal and the output file. 
	After going through all the test cases, the program will then close both the input and output files


	Summary (pseudo-code)
	`````````````````````
	Read number_of_test_cases from the input file(fp_in)

	Print Andrew Id to both the terminal and output file

	Loop through the input file(fp_in) for n times (where n is number_of_test_cases provided from input file)
	
	Read from the input file time (t), x and y coordinates

	If the value of t>=0, call the store_location() function that returns the unique id number

	Use that id when writing to the output file

	After going through all test cases, close both the input file and the output files.

	Lastly, call the prompt_and_exit() function 

   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

    - Data set with duplicates locations (x and y coordinates)
   - Data set with many values
   - Data set that has several instances of the same location
   - Data set with negative location values


   File organization
   -----------------

   example.h                  interface file:      
                              contains the declarations required to use the functions that implement the solution to this problem
                              typically, these will include the definitions of the abstract data types used in the implementation

   exampleImplementation.cpp  implementation file: 
                              contains the definitions of the functions that implement the algorithms used in the implementation
 
   exampleApplication.cpp     application file:    
                              contains the code that instantiates the abstract data types and calls the associated functions
                              in order to effect the required functionality for this application


   Author
   ------

   Gaston Karamba, Carnegie Mellon University Africa
   03/02/2020


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/
 
#include "assignment1Interface.h"
 
int main() {

   int number_of_test_cases;
   float t, x, y;
   struct location_type location[MAX_NUMBER_OF_POINTS];
   int k,id;
   int index = 0;


   FILE *fp_in, *fp_out;

   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
     prompt_and_exit(1);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
     prompt_and_exit(1);
   }
  
 /* read the number of test cases from a file */
fscanf(fp_in, "%d", &number_of_test_cases); //note the &

/* write andrew id to file */
fprintf(fp_out,"gkaramba\n"); // print test case number
 /* read the location data from a file */


printf("gkaramba\n");
for(k = 0; k < number_of_test_cases;k++){
	fscanf(fp_in, "%f %f %f", &t, &x, &y);
	while(t >= 0){
		id = store_location(location,t,(int)x,(int)y);
			if(location[index].id_number != NULL ){
				/* write data to file */
				fprintf(fp_out,"  %d\t%6.3f %4d  %4d \n",id,location[index].t,location[index].x,location[index].y);
				/* write data to terminal*/
				printf("  %d\t%6.3f %4d  %4d \n",id,location[index].t,location[index].x,location[index].y);
				index++;
			}
		fscanf(fp_in, "%f %f %f", &t, &x, &y);
	}
	id = store_location(location,t,(int)x,(int)y);
	fprintf(fp_out,"-------------\n");
	printf("-------------\n");
}


   fclose(fp_in);
   fclose(fp_out);

   prompt_and_exit(0);
}
