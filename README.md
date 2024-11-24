The purpose of this program is to crack a set of passwords given by the user. The program achieves this by using two methods. The first method is a List sort algorithm. Which utalizes text files avaliable easily online containing real passwords that were leaked in data breaches. The list search algorithm involves the program reading the text file line by line and comparing each password in the file to the password input by the user. This is highly effective as passwords on the list are often commonly used weak passwords that many users use. If all passwords are guessed using the list search algorithm the program ends, but what happens when the user enters a password that is not on the leaked password list? Well whenever that instance happens the program will continue to run and start its second method to crack the password, a brute force machine. A BFM takes an input of the alphabet, numbers, and some special characters, then generates every single possible combination of them until it cracks the passwords that were unable to be cracked by the list seach alogirthm. This program tells the user how many seconds it took to crack all of the password and how many attempts in total, to show the user just how fast weak passwords can be cracked. 

    More specifics of program:

        Leaked password file used is called "rockyou.txt" avaliable at https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt 

        Program utalizes: arrays, file operations, functions, structures, loops, conditional statements, time operations, pointers, arrow opperators.

        Maximum length for passwords is 20 characters, and you can input up to 100 passwords

        If password takes less the 0.01 secnds to crack the program will display "instantly" for time

        Any password past 5 characters takes VERY long to crack so the longest avaliable password the BFC can calculate is 8 characters unless the list algoithm can crack the password

        At the end of the program the program will ask the user if it would like to run the program again

