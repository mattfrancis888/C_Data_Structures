#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expeval.h"

int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}

int type(char c) {
  if (c >= '0' &&  c <= '9' )
     return 0;
  else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
    return 1;
  else if (c == '(')
    return 2;
  else if ( c == ')')
    return 3;  
  else 
    return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
// your implementation
	QUEUE postfix = {0};
	STACK stack = {0};
	int num, sign = 1;
	while(*infixstr) {
		switch(type(*infixstr)) {
		case 0: // if an integer
			num = *infixstr-'0';
			infixstr++;
			while(type(*(infixstr)) == 0) { // horners algorithm. loops till character is not an integer
				num = num*10 + *(infixstr)-'0';
				infixstr++;
			}
			enqueue(&postfix, new_node(sign*num, 0)); sign = 1; num = 0; goto a; // reset sign and num. goto a to skip going to next char again
		case 2: push(&stack, new_node(*infixstr, 2)); break; // if a left bracket
		case 3: // if a right bracket
			while(stack.top->type != 2) enqueue(&postfix, (pop(&stack)));
			if(stack.top->type == 2) pop(&stack); break;
		case 1: // if an operator
			if(*infixstr == '-' && (*(infixstr-1) == '(' || !(*(infixstr-1)))) {sign = -1; break;} // checks for negative number
			if(!(stack.top)) push(&stack, new_node(*infixstr, 1)); // if stack is empty
			else if(get_priority(*infixstr) > get_priority(stack.top->data)) push(&stack, new_node(*infixstr, 1)); // push to stack
			else if (get_priority(*infixstr) == get_priority(stack.top->data)) {enqueue(&postfix, (pop(&stack))); push(&stack, new_node(*infixstr, 1));} 
			else {
				while(stack.top || get_priority(*infixstr) < get_priority(stack.top->data)) enqueue(&postfix, (pop(&stack))); // loop till priority of char is greater than top of stack or stack is empty
				push(&stack, new_node(*infixstr, 1));
			}
			break;
		default: break; // for characters that are spaces or arent of use in calculation
		}
			infixstr++;
			a:;
		}
	while(stack.top) enqueue(&postfix, (pop(&stack)));
	return postfix;
}

int evaluate_postfix(QUEUE queue) {
// your implementation
	STACK stack = {0};
	NODE *a, *b;
	while(queue.front) {
		if(queue.front->type == 0) push(&stack, dequeue(&queue));
		else if(queue.front->type == 1) {
			a = pop(&stack); b = pop(&stack);
			switch(queue.front->data) {
				case '/': push(&stack, new_node(b->data / a->data, 0)); break;
				case '*': push(&stack, new_node(b->data * a->data, 0)); break;
				case '%': push(&stack, new_node(b->data % a->data, 0)); break;
				case '+': push(&stack, new_node(b->data + a->data, 0)); break;
				case '-': push(&stack, new_node(b->data - a->data, 0)); break;
			}
			dequeue(&queue);
		}
	}
	return stack.top->data;
}