/* 

   assignment1Implementation.cpp - implementation file for a program named example
   ============================================================================

   This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - assignment1Application.cpp - for details of the functionality of this program

   
   Author
   ------

   Gaston Karamba, Carnegie Mellon University Africa
   03/02/2020


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  Gaston Karamba, 03/02/2020.
   - Added print_message_to_file() to allow users to write message to the file. First, it takes two arguments as explained below:
	             + pointer to the file
				 + array of character to be writen to the specified file.
   
   - Added store_location() that takes 4 parameters such as array of structure, time as float, x coordinate as integer
     and y coordinate as integer respectively. Then Search for the location i.e. x coordinate and y coordinate in the data structure comparing them with
	 new  x coordinate and y coordinate passed as parameter in the function. Then, if location is found return the unique identification number,
	 otherwise it add that new location to the data structure and assign a unique identification number which is also returned after.
	 
*/

 
 
#include "assignment1Interface.h"
/* This function allows users to read the message on the terminal before it is closed*/
void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}
/* This function allows users to write the message to the file specified*/
void print_message_to_file(FILE *fp, char message[]) {
   fprintf(fp,"The message is: %s\n", message);
}
/*This function  search for location passed as parameter in the array of structure, then if found it return the unique identification,
   but it is not found, it adds that new location to the array of structure as well as assigning unique identification number*/
int store_location(struct location_type location[],float t, int x, int y){
	/* variable count that tracks new identification number*/
	static int count = 0;
	/* variable j that tracks current index of added location to the aray of structure */
	static int j = 0;
	/* variable that shows where to start when comparing current location and passed location as parameter */
	static int start_index = 0;
	int i = start_index;
	/* variable that change when location is found */
	bool is_available = false;

	if(t < 0){/* variable that change when location is found */
		count = 0;
		start_index = j;
		//return -1;
	}
	else{
		while(i < j){ 
			if(location[i].x == x && location[i].y == y){ /* check x and y coordinate*/
				is_available = true;
				return location[i].id_number;
			}
			i++;
		}
		if(is_available == false){
			count++;
			location[j].t = t;
			location[j].x = x;
			location[j].y = y;
			location[j].id_number = count;
			j = j + 1;
			return count; // eventually, return a unique location id. number
		}

	}
}