## Time of Check Time of Use Demo Program

Step 1 - Compile the program

`gcc toctou_demo.c -o toctou_demo`

`gcc toctou_demo_patch.c -o toctou_demo_patch`

Step 2 - Run

`./toctou_demo`

`./toctou_demo`

- Pass in a string of size 20 or less when the program asks for input.
- When the program displays `Processing...` create a file called `users.txt` in your current working directory to see the exploit in action [10 second window to create the file].
- After the program completes it execution check the `users.txt` file. It will contain the id of the user.
- Note that you are the owner of this file therefore it can be used for any malicious activity.
- Now delete the `users.txt` file and run the program again.
- The program itself will create the file and put in the user id in it. Note that in a real scenerio you
will not be the owner of that file. Therefore you will not be able to view or update its content.
