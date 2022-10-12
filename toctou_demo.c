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

    // Note that initally there is no file in the system called "users.txt"
    if (access(userFile, F_OK) == 0) 
    {
        // This occurs only if the attacker creates the file before the program does
        // From this point the attacker has full control of the file.
        printf("File found. Writing %s to file.\n", userId);
        writeToFile(userFile, userId);
    }
    else 
    {   
        // Tf the file is not found in a normal secnaerio it creates the file and appends the user id
        printf("File not found, created new file...\n");
        writeToFile(userFile, userId);
    }

}