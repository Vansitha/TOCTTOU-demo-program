/*
 * FILE: toctou_demo.c 
 * AUTHOR: Vansitha Induja Ratnayake
 * UNIT: Cyber Crime and Security Enhanced Programming ISEC3004
 * PURPOSE: Demo program for Time of Check Time of Use
 * REFERENCE: None
 * COMMENTS: None
 * REQUIRES: Linux OS 
 * LAST MOD: 12/10/22
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void writeToFile(char *filename, char *userIdStr) {

    // no error handling done for the purpose of the demo.
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%s", userIdStr);
    fclose(fp);
}

int main() 
{
    printf("## Time of check Time of Use Demo ##\n\n");
    char userId[20]; // stores user id string
    char userFile[12] = "users.txt"; // file which stores all user ids

    // reads in a user id
    printf("Enter your ID: ");
    fgets(userId, sizeof(userId), stdin);
    
    /* Does some additional processing using the user id. 
       This is mimicked using the sleep function
       Meanwhile this processing occurs the attacker has time to 
       create the users.txt file if it does not exist 
    */
    printf("Processing...\n");
    sleep(10); // set to 10 seconds for demo purpose only. Usally a very small window.

    /* The writeToFile function will create the user file if it does not exist but if it already does
    exists it will just append the value to that file. Therefore intially when the file is not available
    and the attacker creates the file called "users.txt" all the data will be written to it which they
    have access to */
    printf("Writing id to file.\n");
    writeToFile(userFile, userId);

}