/* -----------------------------------------------
Submitted By: Salvatore DeLuca
Homework Number: Honors
Credit to:
        <Salvatore DeLuca>
Submitted On: 11/22/2024
By submitting this program with my name,
I affirm that the creation and modification
of this program is primarily my own work.
------------------------------------------------ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct PasswordInfo { //Define structure 'PasswordInfo'
char pass[20]; //Set the maximum length of passwords to be 20 charcaters long
char guess[20];
long long attempts;
double timeTaken;
int cracked;
};

double calculateTime(time_t start, time_t end, double* totalTime){ //Function to calculate the time that has passed for each password 
    double temp = ((double) (end - start)) / CLOCKS_PER_SEC; //Calculate time in seconds
    *totalTime += temp;
    return temp;
}

void generatePasswords(char* alphabet, int alphabetsize, struct PasswordInfo* password, int index, int length){ //Function to generate the passwords using a recursive loop
    if (index == length){
        password->guess[length] = '\0'; //Terminate the string

        password->attempts++; //Increase attempts after each loop

        //If guess and password are same marked a scracked
        if (strcmp(password->guess, password->pass) == 0){
            password->cracked = 1;
        }
        return; //End function
    }

    for (int i = 0; i < alphabetsize; i++){
        password->guess[index] = alphabet[i];

        generatePasswords(alphabet, alphabetsize, password, index + 1, length); //Start recursive loop
    
        if (password->cracked){
            return; //End function if password is cracked
        }
    }
}

void listAlgorithm(struct PasswordInfo* password, int* crackedCounter, int size, int* listAttempts, time_t end, time_t start, FILE* file, double* totalTime){ //Function to search through a file of given passwords for matches and display useful information to the user
    char filePassword[20];

    while (fgets(filePassword, sizeof(filePassword), file)){

    filePassword[strcspn(filePassword, "\n")] = '\0'; //Get rid of the newline character

    (*listAttempts)++; //Tracks Number of passwords searched through

    for (int i = 0; i < size; i++){
        password[i].attempts++; //Count total attempts of each password

        if (strcmp(filePassword, password[i].pass) == 0){
            end = clock(); //Set 'end' to the current program time

            (*crackedCounter)++; //Increase variable to tell how many passwords have been cracked

            password[i].cracked = 1; //Flag to determine if a password was cracked or not

            password[i].timeTaken = calculateTime(start, end, totalTime); //Calculate seconds took to complete program

            //Display to user the password cracked and how long it took to compute
            printf("\nYour Password '%s' was cracked ", password[i].pass);
            if (password[i].timeTaken < 0.01){
                printf("instantly!");
            }
            else{
                printf("in %.2lf seconds", password[i].timeTaken);
            }

            //Display to the user the total number of passwords check for each password
            printf("\nThe total number of passwords checked was %lld\n", password[i].attempts);

            goto end; //Having a break instread will cause the program to reenter the loop and display times for every single password containing your password Ex: 'A' returns about 20 passwords
            }
        }
    }
    end:
        return;
} 

void bruteForce(struct PasswordInfo* password, int size, char* alphabet, int alphabetsize, time_t end, time_t start, double* totalTime){ //Function to access the Brute force machine and display results

    for (int i = 0; i < size; i++){
        if (!password[i].cracked){
            for (int length = 1; length <= 8; length++){ //Set max length for brute force program to check for to 8 to make it reasonable
                generatePasswords(alphabet, alphabetsize, &password[i], 0, length); //Start brute force machine

                if (password[i].cracked){

                    //Calculate time and total passwords
                    end = clock();
                    password[i].timeTaken = calculateTime(start, end, totalTime);

                    //Display results from BFM
                    if (password[i].timeTaken < 0.01){
                        printf("\n\nYour Password '%s' was cracked instantly", password[i].guess);
                    }
                    else{
                        printf("\n\nYour Password '%s' was cracked in %.2lf seconds", password[i].guess, password[i].timeTaken);
                    }
                    printf("\nIt took the brute force machine %lld attempts to crack %s\n", password[i].attempts, password[i].guess);
                    break;
                }
            }
        }
    }
}

int main(void){

    int rerun = 0; //Define rerun so loop can operate
    
    while (rerun <= 1){ //While loop to keep program operating until user ends it
    
        //Define/Initialize variables used
        char alphabet[] = 
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$*_";
<<<<<<< HEAD
        int alphabetsize = sizeof(alphabet) - 1, listAttempts = 0, size = 0, cracked = 0, uncracked = 0, bfContinue = 0, crackedCounter = 0, toolong = 0, validPassword = 0;
=======
        int alphabetsize = sizeof(alphabet) - 1, listAttempts = 0, size = 0, cracked = 0, uncracked = 0, bfContinue = 0, crackedCounter = 0, toolong = 0;
>>>>>>> e1106516e98a4593d833a20ca7ac1d695b3c864e
        double timeTaken, totalTime = 0;
        long long passwordCapture = 0, preBrute = 0, postBrute = 0;
        time_t start, end;

<<<<<<< HEAD
=======
        struct PasswordInfo password[size]; //Call structure 'PasswordInfo' to main function and create subset 'password'

>>>>>>> e1106516e98a4593d833a20ca7ac1d695b3c864e
        //Ask user for how many passwords the system will crack
        printf("\nEnter how many passwords you would like to crack: ");
        scanf("%d", &size);

<<<<<<< HEAD
        struct PasswordInfo password[size]; //Call structure 'PasswordInfo' to main function and create subset 'password'

=======
>>>>>>> e1106516e98a4593d833a20ca7ac1d695b3c864e
        //Validate data entry and ensure the user cannot enter string values
        while(size <= 0 || size > 100){
            while(getchar() != '\n');
            printf("\nPlease enter a size between 1 and 100: ");
            scanf("%d", &size);
        }

        //Ask user for passwords and initialize structure data for the structure array
<<<<<<< HEAD


        for (int i = 0; i < size; i++){
             validPassword = 0; //Reset password validation flag

            while (!validPassword){
                //Ask for passwords and initialize some data used for passwords
                printf("\nEnter password %d to crack: ", i + 1);
                scanf("%s", password[i].pass);
                password[i].attempts = 0;
                password[i].timeTaken = 0;
                password[i].cracked = 0;

                validPassword = 1;

                //Validate the password
                for (int j = 0; password[i].pass[j] != '\0'; j++){
                    if (!strchr(alphabet, password[i].pass[j])){
                        validPassword = 0;
                        printf("\nA character you entered is not allowed, please re-enter your password\n");
                        break;
                    }
                }
            }
        }
        
=======
        for (int i = 0; i < size; i++){
            printf("\nEnter password %d to crack: ", i + 1);
            scanf("%s", password[i].pass);
            password[i].attempts = 0;
            password[i].timeTaken = 0;
            password[i].cracked = 0;
            //If a character is entered not in the BFM directory and the listalgorithm cannot crack it ask user to re-input password
            if (strpbrk(password[i].pass, alphabet) != NULL){
                printf("\nA character you entered is not allowed, please re-enter your password: ");
                scanf("%s", password[i].pass);
            }
        }
>>>>>>> e1106516e98a4593d833a20ca7ac1d695b3c864e

        //CREATE THE LIST SEARCHED ALGORITHM
        FILE* file; //Set pointer to file

        //Open file for reading, display error message if file fails to open
        file = fopen("Common_Password_List.txt", "r");
        if (file == NULL){
            perror("\nThere was an error opening the file, please try again");
            return 1;
        }

        start = clock(); //Set 'start' to the current program time

        listAlgorithm(password, &crackedCounter, size, &listAttempts, end, start, file, &totalTime); //Call list algorithm function

        fclose(file); //Closes file

        //Display passwords that were unable to be cracked using List Algorithm or inform the user if all passwords were cracked with listAlgorithm
        for (int i = 0; i < size; i++){
            if (password[i].cracked != 1){

                printf("\n%s was unable to be cracked!", password[i].pass);

                for (int j = 0; j < (sizeof(alphabet) - 1); j++){
<<<<<<< HEAD
                    if (strlen(password[i].pass) > 8){ 
                        printf("\nSorry your password is too long for the brute force machine it would take a VERY long time to crack\n");
                        toolong = 1; //Flag to tell the program the password is too long
                        break;
                    }
                }
                if (!toolong){
                    bfContinue = 1; //Assign flag to uncracked passwords
                }
=======
                    if (password[i].pass[9] == '\0' || password[i].pass[9] == alphabet[j]){ //If the 9th position is NULL or any possible character end exit both loops
                        printf("\nSorry your password is too long for the brute force machine it would take a VERY long time to crack\n");
                        toolong = 1; //Flag to tell the program the password is too long
                        goto end; //Skip 'bfContinue' flag if it is bigger then 8 characters
                    }
                }

                bfContinue = 1; //Assign flag to uncracked passwords

                end:
                    if (toolong){
                        continue; //Skip password if it is too long
                    }
>>>>>>> e1106516e98a4593d833a20ca7ac1d695b3c864e
            }

            //Display if all passwords have been cracked
            if (crackedCounter == size){
                printf("\nAll the passwords were cracked, thank you for using the program!");
            }
        }
        //BRUTE FORCE MACHINE ALGORITHM
        //For passwords that were uncracked start the brue force process
        if (bfContinue == 1){
            printf("\nList Search Algorithm Failed... Entering Brute Force... This may take a while");

            start = clock(); //Reassign the starting clock value to compute time taken for BFM passwords

            bruteForce(password, size, alphabet, alphabetsize, end, start, &totalTime); //Call bruteForce function

        }
        //Print total time to the user if they enetered multiple passwords
        if (size > 1){
            printf("\nThe total time it took to operate the program was ");
            if (totalTime < 0.01){
                printf("only an instant!\n");
            }
            else{
            printf("%.2lf", totalTime);
            }
        }
        //Ask user to exit the program
        printf("\nWould you like to run the program again?\nYes 1):\nNo 2):\n");
        scanf("%d", &rerun);
    }
    return 0;
}
