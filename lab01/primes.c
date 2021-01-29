#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXVAL 10000 //Actually 1% of max value, to make percent messages easier.
//Returns 1 if the input is a prime number, and 0 otherwise.
int isPrime(int n)
{
    if (n == 2) {
        return 1;
    }
    if(n%2 == 0) {
        return 0;
    }
    for(int i = 3; i < n; i+=2)
    {
        if(n%i == 0) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    /*Allows for an optional command line input. This is only for autograder testing of your code; you should not use the command line input for this exercise.*/
    int onepercent = (argc == 2 ? atoi(argv[1]) : MAXVAL);
    /*You may assume that the above line is correct*/
    for(int i = 2;i<onepercent*100;i++) //So that percent messages are easier to set up.
    {
        int num_primes = 0;
        if(isPrime(i)) //Checks if a number is prime. As a reminder, 0 is false, and any nonzero value is true.
        {
            fprintf(stdout, "%d\n", i); //Prints the number i to standard output
            num_primes++;
        }
        if (i != 0 && i % onepercent == 0) {
            fprintf(stderr, "%d%% complete\n", (i / (onepercent * 100)));
        }
    }
    fprintf(stderr, "Total primes found: %d\n", num_primes);
}