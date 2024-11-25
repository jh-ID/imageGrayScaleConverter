#include <stdio.h>
#include <stdlib.h>
#include <time.h>

                                          /*rcx*/    /*rdx*/      /*r8*/ 
extern void imgCvtGrayDoubletoInt(int n, double* dValues, int* iValues);

/*
double measureExecutionTime(size_t width, size_t height, size_t iterations) {
    size_t i;
    size_t n = width * height; 
    double *dValues = (double *)malloc(n * sizeof(double));
    int *iValues = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) { 
        dValues[i] = ((double)rand() / RAND_MAX); // decimal value
    }

    clock_t start, end;
    double total_time = 0;

    for (i = 0; i < iterations; i++) { 
        start = clock();
        imgCvtGrayDoubletoInt(n, dValues, iValues);
        end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC * 1000; // Convert to milliseconds
    }

    free(dValues);
    free(iValues);

    return total_time / iterations;
}
 
int main() {
    srand(time(NULL)); // Seed the random number generator

    size_t test_sizes[] = {10, 100, 1000}; // Width/Height for 10x10, 100x100, 1000x1000
    size_t i; 
    size_t iterations = 30;

    for (i = 0; i < 3; i++) { 
        size_t size = test_sizes[i];
        double avg_time = measureExecutionTime(size, size, iterations);
        printf("Average execution time for %zux%zu: %.3f ms\n", size, size, avg_time);
    }

    return 0;
}
*/


int main() {
	
	int width, height, n;
    int i, k;
    
    
    //printf("Enter height: ");
    scanf("%d", &height);
    
    //printf("Enter width: ");
    scanf("%d", &width);

    n = width * height;

    // Allocate memory for dValues and iValues arrays
    double* dValues = (double*)malloc(n * sizeof(double));
    int* iValues = (int*)malloc(n * sizeof(int));
    
    if (dValues == NULL || iValues == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Input values into the dValues array
    //printf("\nInput values for the matrix:\n");
    for(i = 0; i < n; i++) { 
        //printf("Input value for dValues[%d]: ", i);
        scanf("%lf", &dValues[i]);
    }

    printf("\nInput:\n");
    for(i = 0; i < height; i++) {  
        for(k = 0; k < width; k++) { 
            printf("%.2f ", dValues[i * width + k]);  
        }
        printf("\n"); 
    }

    // Call the external function
    imgCvtGrayDoubletoInt(n, dValues, iValues);

    // Print the final output
    printf("\nOutput:\n");
    for(i = 0; i < height; i++) {  
        for(k = 0; k < width; k++) { 
            printf("%d ", iValues[i * width + k]);  
        }
        printf("\n"); 
    }

    // Free the allocated memory
    free(dValues);
    free(iValues);
   

    return 0;
}

