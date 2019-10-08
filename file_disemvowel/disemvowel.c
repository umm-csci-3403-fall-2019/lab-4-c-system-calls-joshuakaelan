#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
     const char* all_vowels = "aeiouAEIOU";
     bool vowel_status = false;
     for(int j=0; all_vowels[j] != '\0';j++){
	     if(all_vowels[j] == c){
		    vowel_status = true;
		    break;
	     }
     }
     return vowel_status;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
     int j =0;
     for(int i=0; i<num_chars; i++){
	     if(!is_vowel(in_buf[i])){
		    out_buf[j] = in_buf[i];
		    j++; 
	     }
     }
     return num_chars - j; 
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
     char* buffer[BUF_SIZE];
     FILE* input;
     input = fopen("inputFile", "r");
     int i = 0;
     while(!feof(input)){
            
            fread(buffer, sizeof(buffer), 1, input);
	    i++;

     }
     fclose(input);
     char* endbuffer[BUF_SIZE];
     copy_non_vowels(i,buffer,endbuffer);
     fwrite(endbuffer, sizeof(endbuffer), 1, outputFile); 
        
}

int main(int argc, char *argv[]) {
    // You should set these to `stdin` and `stdout` by default
    // and then set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile;
    FILE *outputFile;
    
    inputFile = stdin;
    outputFile = stdout;
    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);

    return 0;
}
