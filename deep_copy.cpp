
/*
6] Amazon interview question:

deepcopy contents of list a to list b:

struct Node {
	char *data;
	int dataLen;
	struct Node *next;
};


a = {"abcd": 4}, {"efghij": 6], {"klmno": 5}

b = {"lmnop": 5}, {"qrs": 3}, {"tuvwxyz": 8}

after deepcopy b = {"abcde": 5}, {fgh": 3}, {"ijklmno": 7}
int deepCopy(struct Node *a, struct Node*b)
{
	// copy all data from a to a vector<string>
	// Then write it to be based on b->dataLen
	
	
}
*/

#include <iostream>
#include <string.h>

using namespace std;

struct Node {
	char *data;
	int dataLen;
	struct Node *next;
};


struct Node *create(char *data, int length) {
    //struct Node *node = (struct Node *) malloc(sizeof (struct Node));
    struct Node *node = new Node();
    //node->data = (char *) malloc(sizeof(length));
    node->data = (char *)new char[length];
    memcpy(node->data, data, length);
    node->next = NULL;
    node->dataLen = length;
    return node;
}

// copy a to b;
struct Node * deepCopy1(struct Node *a, struct Node *b) {
    string temp;

    struct Node *aNode = a;
    while (aNode != NULL) {
        if (aNode->dataLen > 0) {
            temp += aNode->data;
        }
        aNode = aNode->next;
    }
    char *writer = b->data;
    struct Node *bNode = b;
    const char *reader = temp.c_str();

    while (bNode != NULL) {
        memcpy(b->data, reader, b->dataLen);
        bNode = bNode->next;
    }
    return b;
}

/*
 * deep copy using pointers
 * find min_bytes_to_write with a and b
 * use reader and writer pointers to a and b
 * copy data from reader to writer 
 * if a has written min_bytes_to_write
 *     goto a->next node
 * if b has written min_bytes_to_write
 *     goto b->next node
 */

struct Node * deepCopy(struct Node *a, struct Node *b) {

    struct Node *aNode = a;
    struct Node *bNode = b;
    char *writer = bNode->data;
    const char *reader = aNode->data;
    int a_min_bytes_to_read = aNode->dataLen;
    int b_min_bytes_to_write = bNode->dataLen;
    int min_bytes_to_write = 0;

    cout << "hi1" << endl;
    while (aNode != NULL) {
        int min_bytes_to_write = min(a_min_bytes_to_read, b_min_bytes_to_write);
        memcpy(writer, reader, min_bytes_to_write);
        reader += min_bytes_to_write;
        writer += min_bytes_to_write;
        a_min_bytes_to_read -= min_bytes_to_write;
        b_min_bytes_to_write -= min_bytes_to_write;

    cout << "hi2" << endl;
        if (a_min_bytes_to_read == 0) {
            aNode = aNode->next;
            reader = aNode->data;
            a_min_bytes_to_read = aNode->dataLen;
        }
        if (b_min_bytes_to_write == 0) {
            bNode = bNode->next;
            writer = bNode->data;
            b_min_bytes_to_write = bNode->dataLen;
        }
    }
    return b;
}


int main() {

    struct Node *a, *b;
    a = create("abcd", 4);
    a->next = create("efgh", 4);
    a->next->next = create("ijklm", 5);

    b = create("abc", 3);
    b->next = create("def", 3);
    b->next->next = create("ghijklm", 7);

    struct Node *b1 = deepCopy(a, b);

    // print b1
    while (b1 != NULL) {
        cout << b1->data << " " << endl;
        b1 = b1->next;
    }
    cout << endl;
    return 0;

}