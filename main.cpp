#include "conf.h"

int main (int argc, char* argv[]) {

    if (argc == 1) {

        printf ("Helo! This is a simple console-interface xor coder/decoder. For now it only supports super basic functions such as:\n"
                "Coding a string (-c <string>)\n"
                "Decoding a string (-d <coded string>)\n"
                "[Not implemented yet] Coding an entire file (-C <file name>)\n"
                "[Not implemented yet] Decoding an entire file (-D <file name>)\n"
                "Displaying this message again (-h)\n"
                "Leaving the program (-q)\n"
                "All output from -c, -d, -C and -D will be pasted to %s file for easier copy paste (created upon first input, erased when -q)\n"
                "[Not implemented yet] All functions except -q can be used as command line arguments for single use. Also some parameters could be changed via conf.h file (NOTE that setting size related variables to very high values can impact performance)\n", outFileName);

        char inputBuffer[inputBuffSize] = "";
        for (;;) {

            printf ("Please insert command:\n");

            scanf (" %s", inputBuffer); // reads command

            if (inputBuffer[0] != '-') { // checks for it being a command fr

                printf ("Unknown command, please type another one or -h for full command list.\n");
                continue;
            }

            int len = 0; // strlen var

            switch (inputBuffer[1]) {

                case 'c':

                    scanf (" %c", inputBuffer); // skips spaces and reads first char

                    if (fgets (inputBuffer + 1, inputBuffSize - 2, stdin) == NULL) { // reads input to buffer until \n, prints message if something failed

                        printf ("Error occured during string input. Try again, or change inputBuffSize to higher value in conf.h.\n");
                        continue;
                    }

                    len = strlen (inputBuffer) - 1; // saves strlen
                    inputBuffer[len] = '\0'; // sets \0
                    xorCipher (inputBuffer); // ciphers the thing

                    char2hexOutput (inputBuffer, len);  // outputs turning each char to %.02X

                break;

                case 'd':

                    scanf (" %c", inputBuffer); // skips spaces and reads first char

                    if (fgets (inputBuffer + 1, inputBuffSize - 2, stdin) == NULL) { // reads input to buffer until \n, prints message if something failed

                        printf ("Error occured during string input. Try again, or change inputBuffSize to higher value in conf.h.\n");
                        continue;
                    }

                    len = strlen (inputBuffer) - 1; // saves strlen
                    inputBuffer[len] = '\0'; // sets end of str

                    xorDeCipher (inputBuffer); // deciphers into string

                    charOutput (inputBuffer); // outputs string to file (simple as that)
                break;

                case 'q':

                    remove (outFileName);   // deletes output file
                return 0;

                case 'h':

                    printf ("Helo! This is a simple console-interface xor coder/decoder. For now it only supports super basic functions such as:\n"
                            "Coding a string (-c <string>)\n"
                            "Decoding a string (-d <coded string>)\n"
                            "[Not implemented yet] Coding an entire file (-C <file name>)\n"
                            "[Not implemented yet] Decoding an entire file (-D <file name>)\n"
                            "Displaying this message again (-h)\n"
                            "Leaving the program (-q)\n"
                            "All output from -c, -d, -C and -D will be pasted to %s file for easier copy paste (created upon first input, erased when -q)\n"
                            "[Not implemented yet] All functions except -q can be used as command line arguments for single use. Also some parameters could be changed via conf.h file (NOTE that setting size related variables to very high values can impact performance)\n", outFileName);

                break;

                default:

                    printf ("Unkown command. Type another one or -h for command list.\n"); // if an unknown command
                break;
            };
        }


    }
    else {


    }
}