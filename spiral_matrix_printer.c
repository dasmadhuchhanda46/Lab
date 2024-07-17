#include<stdio.h>
#include<math.h>

#define SIZE 100 // Define a constant SIZE with a value of 100

// Function to create the required matrix from the input array
void create_matrix(char matrix[][SIZE], int m, int n, char array[], int k){
    int p = 0; // Index for the input array
    for(int i = 0; i < m; i++){ // Loop through rows
        for(int j = 0; j < n; j++){ // Loop through columns
            matrix[i][j] = array[p]; // Assign each element from the array to the matrix
            p++;
        }
    }
}

// Function to print the matrix in a spiral order
void spiral_matrix(char matrix[][SIZE], int m, int n, int k){
    int row_start = 0; // Starting index for rows
    int row_end = m - 1; // Ending index for rows
    int col_start = 0; // Starting index for columns
    int col_end = n - 1; // Ending index for columns
    char final[SIZE]; // Array to store the spiral order
    int s = 0; // Index for the final array
    int i;

    // Loop to traverse the matrix in spiral order
    while(row_start <= row_end && col_start <= col_end){
        // Traverse right across the top row
        for(i = col_start; i <= col_end; i++){
            final[s] = matrix[row_start][i];
            s++;
        }
        row_start++;

        // Traverse down the rightmost column
        for(i = row_start; i <= row_end; i++){
            final[s] = matrix[i][col_end];
            s++;
        }
        col_end--;

        // Traverse left across the bottom row, if rows remain
        if(row_start <= row_end){
            for(i = col_end; i >= col_start; i--){
                final[s] = matrix[row_end][i];
                s++;
            }
            row_end--;
        }

        // Traverse up the leftmost column, if columns remain
        if(col_start <= col_end){
            for(i = row_end; i >= row_start; i--){
                final[s] = matrix[i][col_start];
                s++;
            }
            col_start++;
        }
    }

    // Print the elements in the final spiral order array
    for(int i = 0; i < k; i++){
        printf("%c ", final[i]);
    }
}

int main(){
    int m, n;
    
    // Read the dimensions of the matrix
    scanf("%d %d", &m, &n);
    int k = m * n; // Calculate the total number of elements

    char array[SIZE]; // Array to store the input characters
    // Read the input characters into the array
    for(int i = 0; i < k; i++){
        scanf(" %c", &array[i]);
    }

    char matrix[SIZE][SIZE]; // Declare the matrix

    // Create the matrix from the input array
    create_matrix(matrix, m, n, array, k);
    // Print the matrix in spiral order
    spiral_matrix(matrix, m, n, k);

    return 0; // Return 0 to indicate successful completion of the program
}
