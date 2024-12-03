#include<stdio.h>

void first_fit(int number_of_blocks, int number_of_files, int blocks[], int files[]);
void best_fit(int number_of_blocks, int number_of_files, int blocks[], int files[]);
void worst_fit(int number_of_blocks, int number_of_files, int blocks[], int files[]);

int main() {
    int blocks[20], files[20];
    int number_of_blocks, number_of_files, i;

    printf("Enter the number of blocks: ");
    scanf("%d", &number_of_blocks);

    printf("Enter the number of files: ");
    scanf("%d", &number_of_files);

    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < number_of_blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("\nEnter the size of the files:\n");
    for (i = 0; i < number_of_files; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &files[i]);
    }

    // First Fit Allocation
    printf("\nOUTPUT: \nFor First Fit:\n");
    first_fit(number_of_blocks, number_of_files, blocks, files);

    // Best Fit Allocation
    printf("\nBest Fit:\n");
    best_fit(number_of_blocks, number_of_files, blocks, files);

    // Worst Fit Allocation
    printf("\nWorst Fit:\n");
    worst_fit(number_of_blocks, number_of_files, blocks, files);

    return 0;
}

//First Fit Algorithm
void first_fit(int number_of_blocks, int number_of_files, int blocks[], int files[]) {
    int block_arr[10] = {0}; 
    int file_arr[10], fragments[10], temp, i, j;

    for (i = 0; i < number_of_files; i++) {
        for (j = 0; j < number_of_blocks; j++) {
            if (block_arr[j] != 1) { 
                temp = blocks[j] - files[i];
                if (temp >= 0) {
                    file_arr[i] = j; 
                    fragments[i] = temp;
                    block_arr[j] = 1; 
                    break;
                }
            }
        }
    }

    printf("File No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 0; i < number_of_files; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, 
               files[i], 
               file_arr[i] + 1, 
               blocks[file_arr[i]], 
               fragments[i]);
    }
}

//Best Fit Algorithm
void best_fit(int number_of_blocks, int number_of_files, int blocks[], int files[]) {
    int block_arr[10] = {0}; 
    int file_arr[10], fragments[10], temp, i, j, best_idx;

    for (i = 0; i < number_of_files; i++) {
        best_idx = -1; 
        for (j = 0; j < number_of_blocks; j++) {
            if (block_arr[j] != 1) { 
                temp = blocks[j] - files[i];
                if (temp >= 0) {
                    if (best_idx == -1 || temp < (blocks[best_idx] - files[i])) {
                        best_idx = j; 
                    }
                }
            }
        }
        if (best_idx != -1) {
            file_arr[i] = best_idx; 
            fragments[i] = blocks[best_idx] - files[i];
            block_arr[best_idx] = 1; 
        }
    }

    // Display the output
    printf("File No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 0; i < number_of_files; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, 
               files[i], 
               file_arr[i] + 1, 
               blocks[file_arr[i]], 
               fragments[i]);
    }
}

//Worst Fit Algorithm
void worst_fit(int number_of_blocks, int number_of_files, int blocks[], int files[]) {
    int block_arr[10] = {0}; 
    int file_arr[10], fragments[10], temp, i, j, top;

    for (i = 0; i < number_of_files; i++) {
        top = -1; 
        for (j = 0; j < number_of_blocks; j++) {
            if (block_arr[j] != 1) { 
                temp = blocks[j] - files[i];
                if (temp >= 0) {
                    if (top == -1 || temp > (blocks[top] - files[i])) {
                        top = j; 
                    }
                }
            }
        }
        if (top != -1) {
            file_arr[i] = top; 
            fragments[i] = blocks[top] - files[i];
            block_arr[top] = 1; 
        }
    }


    printf("File No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 0; i < number_of_files; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, 
               files[i], 
               file_arr[i] + 1, 
               blocks[file_arr[i]], 
               fragments[i]);
    }
}
