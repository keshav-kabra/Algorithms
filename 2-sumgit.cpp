#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SLOT 524287

typedef struct hash_table_chain{
    __int64 value;
    struct hash_table_chain *next;
}chain_t, *chain_p;

typedef struct hash_table_head{
    int number;
    chain_p head;
}head_t, *head_p;

int hashFunction(__int64 key);
void chaining(__int64 value, head_p hashTableSlot);

 main(){
    clock_t begin = clock();
    FILE *inFile = fopen("prob-2sum.txt", "r");
    head_p pHashTable, nHashTable;
    chain_p nodePtr;
    __int64 value, tempValue, matchValue;
    int index, maxIndex = MAX_SLOT, nMaxChainingNumber = 0, pMaxChainingNumber = 0;
    int i, counter = 0, checkArray[20001] = {0}, checkArrayIndex;
    
    if(!inFile)
    	printf("Fail to open file\n");
    else
    	printf("Open file successfully!\n");
    /* Initialize hash table */
    pHashTable = (head_p)malloc(maxIndex * sizeof(head_t));
    if(!pHashTable){
        printf("Malloc hashTable failed.\n");
        exit(1);
    }
    nHashTable = (head_p)malloc(maxIndex * sizeof(head_t));
    if(!nHashTable){
        printf("Malloc hashTable failed.\n");
        exit(1);
    }
    for(i = 0; i < maxIndex; i++){
        pHashTable[i].number = nHashTable[i].number = 0;
        pHashTable[i].head = NULL;
        nHashTable[i].head = NULL;
    }
    /* insert keys to hash table */
    while(fscanf(inFile, "%lld", &value) != EOF){
        index = hashFunction(value);
        /* chaining */
        if(value > 0){
            chaining(value, &pHashTable[index]);
            if(pHashTable[index].number > pMaxChainingNumber)
                pMaxChainingNumber = pHashTable[index].number;
        }
        else{
            chaining(value, &nHashTable[index]);
            if(nHashTable[index].number > nMaxChainingNumber)
                nMaxChainingNumber = nHashTable[index].number;
        }
        
    }
    printf("nMaxChainingNumber = %d, pMaxChainingNumber = %d\n", nMaxChainingNumber, pMaxChainingNumber);
    fseek(inFile, 0, SEEK_SET);
    /* find the temp value to the key */
    while(fscanf(inFile, "%lld", &value) != EOF){
        /* looking for -value +- 10000 */
        /* i.e. value = 68037543430 
        we will looking for tempValue = -68037530000, -68037540000, -68037550000 */
        tempValue = (value - (value % 10000)) * (-1);
        /* so only iterate 3 times */
        for(i = -10000; i <= 10000; i += 10000){
            index = hashFunction(tempValue + i);
            if(tempValue > 0){
                if(!pHashTable[index].number)
                    break;
                nodePtr = pHashTable[index].head;
            }
            else{
                if(!nHashTable[index].number)
                    break;
                nodePtr = nHashTable[index].head;
            }
            while(nodePtr){
                matchValue = nodePtr->value + value;
                if(-10000 <= matchValue && matchValue <= 10000){
                    checkArrayIndex = (int)(matchValue + 10000);
                    if(!checkArray[checkArrayIndex]){
                        checkArray[checkArrayIndex]++;
                        printf("value of t is %d", matchValue);
                        counter++;
                    }
                }
                nodePtr = nodePtr->next;
            }
        }
    }
    printf("Counter = %d\n", counter);

    fclose(inFile);
    clock_t end = clock();
    printf("Running time = %.3f (sec)\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

int hashFunction(__int64 key){
    /* Multiplication method */
//    int m = (int) pow(2, POWER), index;
//    double A = 0.618, keyMultiA, fraction;
//    
//    key = key / 10000;
//    if(key < 0)
//        key *= (-1);
//    keyMultiA = (double) key * A;
//    fraction = keyMultiA - (__int64) keyMultiA;
//    index = (int)((double) m * fraction);
    /* Division method */
    int index;
    key = key / 10000;
    if(key < 0)
        key *= (-1);
    index = key % MAX_SLOT;
    return index;
}

void chaining(__int64 value, head_p hashTableSlot){
    hash_table_chain* newNode = (hash_table_chain*)malloc(sizeof(chain_t));
    newNode->value = value;
    /* insert node */
    newNode->next = hashTableSlot->head;
    hashTableSlot->head = newNode; 
    hashTableSlot->number++;
    return;
}