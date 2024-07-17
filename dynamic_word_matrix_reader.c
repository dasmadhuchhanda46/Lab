#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>  

int main()
{ 
    int columns, rows;
    
    // Prompt the user to enter the number of rows and columns
    printf("Enter the value of column:");
    scanf("%d %d", &rows, &columns);
    
    char ***lines;
    
    // Allocate memory for 'rows' number of char** (each row is an array of strings)
    lines = (char ***)malloc(rows * sizeof(char **));
    
    // Allocate memory for each row
    for(int i = 0; i < rows; i++){
        lines[i] = (char**)malloc(columns * sizeof(char*));
        // Allocate memory for each string in the row
        for(int j = 0; j < columns; j++){
            lines[i][j] = (char*)calloc(16, sizeof(char));
        }
    }
    
    // Allocate memory to store the number of words in each row
    int *nwords = (int*)malloc(rows * sizeof(int));
    
    char c;
    int column;
    
    // Read input for each row
    for(int row = 0; row < rows; row++){
        c = getchar(); // Read a character from stdin
        column = 0; // Initialize column index to 0
        
        // Read characters until a newline is encountered
        while('\n' != c){
            if(EOF == c){
                break; // Break if End-Of-File is reached
            }
            if(isspace(c)){
                // If the character is a whitespace, read a word into lines[row][column]
                scanf("%s", lines[row][column]);
                column++;
            }
            else{
                // If the character is not a whitespace, put it back into the input buffer
                ungetc(c, stdin);
                // Read a word into lines[row][column]
                scanf("%s", lines[row][column]);
                column++;
            }
            c = getchar(); // Read the next character
        }
        nwords[row] = column; // Store the number of words read in this row
    }
    
    // Print the words in the 2D array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < nwords[i]; j++){
            printf("%s ", lines[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            free(lines[i][j]);
        }
        free(lines[i]);
    }
    free(lines);
    free(nwords);

    return 0;
}
