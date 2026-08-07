#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char exp[100];
int pos = 0;

typedef struct Node {
    char op;
    int value;
    struct Node *left, *right;
} Node;

Node* numberNode(int value) {
    Node *n = malloc(sizeof(Node));
    n->op = '\0';
    n->value = value;
    n->left = n->right = NULL;
    return n;
}

Node* operatorNode(char op, Node *left, Node *right) {
    Node *n = malloc(sizeof(Node));
    n->op = op;
    n->left = left;
    n->right = right;
    return n;
}

Node* expression();

Node* factor() {
    while (exp[pos] == ' ')
        pos++;

    if (exp[pos] == '(') {
        pos++;
        Node *n = expression();
        pos++;
        return n;
    }

    int num = 0;

    while (isdigit(exp[pos])) {
        num = num * 10 + (exp[pos] - '0');
        pos++;
    }

    return numberNode(num);
}

Node* term() {
    Node *left = factor();

    while (exp[pos] == '*' || exp[pos] == '/') {
        char op = exp[pos++];
        Node *right = factor();
        left = operatorNode(op, left, right);
    }

    return left;
}

Node* expression() {
    Node *left = term();

    while (exp[pos] == '+' || exp[pos] == '-') {
        char op = exp[pos++];
        Node *right = term();
        left = operatorNode(op, left, right);
    }

    return left;
}

/* SDD synthesized attribute evaluation */
int evaluate(Node *root) {
    if (root->op == '\0')
        return root->value;

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    switch (root->op) {
        case '+':
            return left + right;

        case '-':
            return left - right;

        case '*':
            return left * right;

        case '/':
            if (right == 0) {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            return left / right;
    }

    return 0;
}

/* Display syntax tree */
void preorder(Node *root) {
    if (root == NULL)
        return;

    if (root->op == '\0')
        printf("%d ", root->value);
    else
        printf("%c ", root->op);

    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node *root;
    int result;

    printf("Enter arithmetic expression: ");
    fgets(exp, sizeof(exp), stdin);

    root = expression();

    printf("\nSyntax Tree (Preorder): ");
    preorder(root);

    result = evaluate(root);

    printf("\nFinal Computed Value = %d\n", result);

    return 0;
}
