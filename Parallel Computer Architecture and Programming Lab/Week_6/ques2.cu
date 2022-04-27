#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>

// Write a program in CUDA to read a sentence with equal length words. Count the number of times a given word is repeated in this sentence.  (Use Atomic function).  
// Sample string:  Pcap EEFM  exam Pcap test Pcap 
// Word: Pcap    Given word repeated 3 times 

__global__
void FindOccurrencesKernel(char *sentence, char *word, int *count, int length){
    int idx = threadIdx.x;
    int sum = 0;
    for (int i = 0; i < length; i++){
        if (word[i] == sentence[idx * length + i]){
            sum++;
        }
    }
    if (sum == length)
        atomicAdd(count, 1);
}
void FindOccurrences(char **sentence, char *word, int *count, int length, int n){
    char *d_sentence, *d_word;
    int *d_count;
    char s[n * length];
    int k = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < length; j++){
            s[k++] = sentence[i][j];
        }
    }
    cudaMalloc((void **)&d_sentence, sizeof(char) * length * n);
    cudaMalloc((void **)&d_word, sizeof(char) * length);
    cudaMalloc((void **)&d_count, sizeof(int));
    cudaMemcpy(d_sentence, s, sizeof(char) * length * n, cudaMemcpyHostToDevice);
    cudaMemcpy(d_word, word, sizeof(char) * length, cudaMemcpyHostToDevice);
    FindOccurrencesKernel<<<1, n>>>(d_sentence, d_word, d_count, length);
    cudaMemcpy(count, d_count, sizeof(int), cudaMemcpyDeviceToHost);
}
int main(){
    printf("Enter the number of words in the sentence : ");
    int n;
    scanf("%d", &n);
    char **sentence = (char **)calloc(n, sizeof(char *));
    printf("Enter the equal word length : ");
    int length;
    scanf("%d", &length);
    printf("Enter the sentence : ");
    for (int i = 0; i < n; i++)
    {
        sentence[i] = (char *)calloc(length, sizeof(char));
        scanf(" %s", sentence[i]);
    }
    int count = 0;
    printf("Enter the word to be searched for : ");
    char *word = (char *)calloc(length, sizeof(char));
    scanf(" %s", word);
    FindOccurrences(sentence, word, &count, length, n);
    printf("The number of occurrences are : %d\n", count);
    return 0;
}