#include<stdio.h>

#define SIZE 1000 // Define a constant SIZE with a value of 1000

int main()
{   
    int sum1=0, sum2=0; // Initialize sum1 and sum2 to 0
    int N; // Variable to store the number of elements
    int arr[SIZE]; // Declare an array of size SIZE

    scanf("%d", &N); // Read the value of N from the user

    // Read N elements into the array
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of elements at even indices
    for(int i=0; i<N; i+=2){
        sum1 = sum1 + arr[i];
    }   

    // Calculate the sum of elements at odd indices
    for(int i=1; i<N; i+=2){
        sum2 = sum2 + arr[i];
    } 

    // Check the conditions:
    // 1. Difference of sum2 and sum1 is divisible by 11
    // 2. Sum of sum1 and sum2 is divisible by 3
    // 3. The last two elements of the array are 0
    if((sum2 - sum1) % 11 == 0 && (sum1 + sum2) % 3 == 0 && arr[N-1] == 0 && arr[N-2] == 0){
        printf("YES"); // Print "YES" if all conditions are met
    } 
    else{
        printf("NO"); // Print "NO" otherwise
    }

    return 0; // Return 0 to indicate successful completion of the program
}
