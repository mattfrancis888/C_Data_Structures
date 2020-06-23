#include "bigint.h"

BIGINT bigint(char *p) {
  BIGINT bn = {0};
  if (p == NULL) 
    return bn;
  else if (!(*p >= '0' && *p <= '9')) {// not begin with digits 
    return bn;
  }
  else if (*p == '0' && *(p+1) == '\0') {// just "0"
    insert_end(&bn.start, &bn.end, new_node(*p));
    return bn;
  }  
  else { 
    while (*p) {
      if (*p >= '0' && *p <= '9' ){
        insert_end(&bn.start, &bn.end, new_node(*p));
      } else {
        clean_bigint(&bn);   
        break;
      }
      p++;
    }
    return bn;
  }
}

void display_bigint(BIGINT bignumber) {

	NODE *ptr = bignumber.start;

	while (ptr) {
		printf("%c", ptr->data);
		ptr = ptr->next;
	}

}

void clean_bigint(BIGINT *bignumberp) {
  clean(&bignumberp->start, &bignumberp->end);
}

BIGINT add(BIGINT op1, BIGINT op2) {

	BIGINT sum = bigint(NULL);
	
	NODE *p1 = op1.end;
	NODE *p2 = op2.end;

	int carry = 0, a, b, s;

	while (p1 || p2) { // addition algorithm
		a = 0; 
		b = 0;
		
		if (p1) {
			a = p1->data - '0'; //convert to char
			p1 = p1->prev;
		}
		if (p2) {
			b = p2->data - '0'; 
			p2 = p2->prev;
		}

		s = a + b + carry;
		if (10 <= s) {
			insert_start(&sum.start, &sum.end, new_node(s-10+'0')); //convert to int
			carry = 1;
		}
		else {
			insert_start(&sum.start, &sum.end, new_node(s+'0'));
			carry = 0;
		}
    	s = 0;
	}
	if (carry == 1)  insert_start(&sum.start, &sum.end, new_node('1')); //  insert 1 at start of  the doubly linked list
	return sum;

}

BIGINT Fibonacci(int n) {

	if (n <= 2) {
		return bigint("1");
	} else {
		BIGINT temp = bigint(NULL);  
		BIGINT f1 = bigint("1");
		BIGINT f2 = bigint("1");
		int i;		
		for (i = 3; i <= n; i++) {

			temp = f2;
			f2 = add(f1, f2);
			f1 = temp;

        }
		return f2;
	}
}
