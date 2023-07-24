#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 256
struct MinHeapNode
{
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};
struct MinHeap
{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};
struct MinHeapNode *createNode(char data, unsigned frequency)
{
    struct MinHeapNode *node = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}
struct MinHeap *createMinHeap(unsigned capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;
    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}
struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}
void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
int isLeaf(struct MinHeapNode *root)
{
    return !(root->left) && !(root->right);
}
struct MinHeap *createAndBuildMinHeap(char data[], unsigned frequency[], int size)
{
    struct MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(data[i], frequency[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}
struct MinHeapNode *buildHuffmanTree(char data[], unsigned frequency[], int size)
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap *minHeap = createAndBuildMinHeap(data, frequency, size);
    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to perform Huffman coding
void HuffmanCodes(char data[], unsigned frequency[], int size)
{
    struct MinHeapNode *root = buildHuffmanTree(data, frequency, size);

    int arr[MAX_CHAR], top = 0;

    printCodes(root, arr, top);
}

int main()
{
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    unsigned frequency[MAX_CHAR] = {0};
    for (int i = 0; sentence[i] != '\0'; ++i)
        frequency[(int)sentence[i]]++;

    int size = 0;
    for (int i = 0; i < MAX_CHAR; ++i)
    {
        if (frequency[i] > 0)
            size++;
    }
    char data[size];
    unsigned freq[size];
    int index = 0;
    for (int i = 0; i < MAX_CHAR; ++i)
    {
        if (frequency[i] > 0)
        {
            data[index] = (char)i;
            freq[index] = frequency[i];
            index++;
        }
    }
    HuffmanCodes(data, freq, size);
    return 0;
}