#include <iostream>
using namespace std;

// Node for Generalized Linked List
struct GLLNode {
    int flag; 
    char data; 
    GLLNode* next;
    GLLNode* down; 
};

// Function to create a data node
GLLNode* createDataNode(char value) {
    GLLNode* newNode = new GLLNode;
    newNode->flag = 0;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->down = nullptr;
    return newNode;
}

// Function to create a sublist node
GLLNode* createSublistNode(GLLNode* sublist) {
    GLLNode* newNode = new GLLNode;
    newNode->flag = 1;
    newNode->data = '\0'; 
    newNode->next = nullptr;
    newNode->down = sublist; 
    return newNode;
}

// Recursive function to display the GLL
void display(GLLNode* head) {
    cout << "{ ";
    while (head != nullptr) {
        if (head->flag == 0) {
            cout << head->data; 
        } else {
            display(head->down); 
        }
        head = head->next;
        if (head != nullptr) cout << ", ";
    }
    cout << " }";
}

int main() {
    // Example: S = { p, q, { r, s }, t }
    
    // Create inner set {r, s}
    GLLNode* r = createDataNode('r');
    GLLNode* s = createDataNode('s');
    r->next = s;
    
    GLLNode* innerSet = createSublistNode(r);
    
    // Create main set {p, q, {r, s}, t}
    GLLNode* p = createDataNode('p');
    GLLNode* q = createDataNode('q');
    GLLNode* t = createDataNode('t');
    
    p->next = q;
    q->next = innerSet;
    innerSet->next = t;

    cout << "Generalized Linked List Representation:\n";
    display(p);
    cout << endl;

    return 0;
}


/*
1. We create a GLLNode structure with flag, data, next, and down pointers.

2. flag = 0 means the node stores a single data element, flag = 1 means it stores a sublist.

3. We create data nodes using createDataNode() and sublist nodes using createSublistNode().

4. Each node’s next pointer links to the next element at the same level, down pointer links to a nested set.

5. To display the set, we use a recursive display() function.

6. In display(), if flag = 0 we print the data, if flag = 1 we recursively display the sublist.

7. We use braces { } to show set notation for each level of nesting.

8. Commas are printed between elements while traversing the list.
*/

