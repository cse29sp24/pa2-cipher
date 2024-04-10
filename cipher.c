/**
 * CSE 29 Programming Assignment: Affine Cipher
 *
 * See https://en.wikipedia.org/wiki/Affine_cipher
 *
 * All input is converted to lower case before encryption/decryption.
 * Only characters in the English alphabet are encrypted. Punctuation
 * and whitespaces are left untouched.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include <assert.h>

#define VOCAB_SIZE 26 /* size of the english alphabet */
#define MAX_INPUT_SIZE 1000
#define ENCRYPT_MODE 0
#define DECRYPT_MODE 1

/**
 * Find the modulo multiplicative inverse of key1.
 * a a_inv = 1 (under mod m)
 *
 * a = number for which we want to find the Multiplicative Inverse
 * a_inv = Multiplicative Inverse of a. a_inv belongs to (0, m)
 *
 * Note that this range (0, m) is exclusive of both 0 and m. 
 * This is because the LHS would be 0 in both these cases.
 *
 * The Multiplicative Inverse only exists if gcd(a, m) == 1
 */
int mmi(int key1)
{
    for (int a_inv = 1; a_inv < VOCAB_SIZE; a_inv++) {
        if ((key1 * a_inv) % VOCAB_SIZE == 1) {
            return a_inv;
        }
    }
    return -1;
}

/**
 * Check if key1 is valid (coprime with 26).
 * Returns 1 if the key is valid, 0 if not.
 */
int valid_key1(int key1)
{
    static const int possible_values_a[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    for (int i = 0; i < sizeof(possible_values_a) / sizeof(possible_values_a[0]); i++){
        if (key1 == possible_values_a[i]){
            return 1;
        }
    }
    return 0;
}

/**
 * encrypts a character using the affine cipher
 * (only encrypts lower case letters, other characters are skipped)
 * 
 * parameters:
 *  char c      the character to encrypt
 *  int key1    the first key (non-negative, coprime with 26)
 *  int key2    the second key (non-negative)
 * returns
 *  the encrypted char (or original character if not lower case letter)
 */
char affine_encrypt(char c, int key1, int key2)
{
    /* TODO: implement this function. */
    return c;
}

/**
 * decrypts a character using the affine cipher
 * (only decrypts lower case letters, other characters are skipped)
 * 
 * parameters:
 *  char c      the character to decrypt
 *  int key1    the first key (non-negative, coprime with 26)
 *  int key2    the second key (non-negative)
 * returns
 *  the decrypted char (or original character if not lower case letter)
 */ 
char affine_decrypt(char c, int key1, int key2)
{
    /* TODO: implement this function. */
    return c;
}

void print_usage()
{
    fprintf(stderr, "Usage: cipher [-e|-d] key1 key2\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int opt;
    char buf[MAX_INPUT_SIZE];
    int key1, key2;
    int mode = ENCRYPT_MODE;
    char *endptr;

    /* Handle command line arguments. */
    if (argc < 3) {
        print_usage();
    }

    while ((opt = getopt(argc, argv, "ed")) != -1) {
        switch (opt) {
        case 'e':
            // if -e flag is present, set to ENCRYPT mode
            mode = ENCRYPT_MODE;
            break;
        case 'd':
            // if -d flag is present, set to DECRYPT mode
            mode = DECRYPT_MODE;
            break;
        default:
            print_usage();
        }
    }

    /* Parse remaining arguments as key1 and key2 */
    key1 = strtol(argv[optind++], &endptr, 10);
    key2 = strtol(argv[optind++], &endptr, 10);

    /* TODO: Check key1 is valid using the valid_key1() function. */

    /* Read input on a loop until EOF */
    int len;
    while (fgets(buf, sizeof(buf), stdin)) {
        len = strlen(buf);

        // Double check length does not exceed buffer size.
        // This is done for security reasons.
        assert(len <= MAX_INPUT_SIZE);

        // strip the trailing newline character if present.
        if (buf[len - 1] == '\n') {
            buf[--len] = 0;
        }

        /* TODO: Encrypt/decrypt the text in buffer in-place. */
    }
    
    return EXIT_SUCCESS;    
}
