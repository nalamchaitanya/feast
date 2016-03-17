#ifndef HELPER_H
#define HELPER_H

// All Helper function headers here.

#define NO_OF_ROUNDS 6
#define KEY_SIZE     24
#define INPUT_SIZE   32

char **keys_arr;
int **sbox_arr;
int *expansion_arr;
int *diffusion_arr;

void fileread();              //to read all the requires csv files
void generatekeys();          //generates the round keys
void function(char *input,char *output,int round_no); 
                        //the 'f' part where compression and expansion occurs
void xor(char *arr1,char *arr2,char *output,int size);
                        //output is the xor of 2 arrays arr1,arr2 of given size
void fiestel(char *input);
						//complete fiestel block which takes input and encrypts

#endif
