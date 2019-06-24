/*
* 
*listdiazj1: my main class.
*
*@author: Jason Diaz
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listdiazj1.h"
#define MAXWORD 50

struct tnode {
	char *first; //pointer to the first name
	char *last;	//pointer to the last name
	struct tnode *left; //left child
	struct tnode *right; //right child
	};
	
/* addtree: add a node with f and l, below p */
struct tnode *addtree(struct tnode *p, char *f, char *l) {
		int cond;
		if(p == NULL) {
			p = talloc();
			p->first = strdup(f);
			p->last = strdup(l);
			p->left = p->right = NULL;
		}
		else if((cond = strcmp(l,p->last)) == 0) { //same last name
				if((cond = strcmp(f,p->first)) < 0) { //check first name
					p->left = addtree(p->left, f, l);
					return p;
				}
				else {
				p->right = addtree(p->right, f, l);
				return p;
				}
		}
		else if(cond < 0) { //last name is smaller
			p->left = addtree(p->left, f, l);
			return p;
		}
		else { //the last name is bigger
			p->right = addtree(p->right, f, l);
			return p;
		}
	}
	
/* kgetline: read a line, store the first name in f, store the last name in l.
 * if there is a ',' a 1 is returned if it is the end of file a -1 is returned.
 * if not a 2 is returned or a -2 for the same purpose.
 */
int kgetline(char f[], char l[]) {
	char c;
	int s,i, j, bool, swap;
	bool=swap=0; //false
	while(s<25) {
	f[s] = 0;
	l[s] = 0;
	s++;
	}
	for (j=i=0;(c=getchar()) !=EOF && c!='\n';i++) {
	
	if(c==' ') {
			bool = 1;
		}
		else if(c==',') {
			swap = 1;
		} 
		else if(bool == 0) {
			f[i] = c;
		}
		else {
			l[j] = c;
			j++;
		}
	}
	
	if(c == EOF && swap == 1) {
		return -1;
	}
	else if(c == EOF && swap == 0) {
		
		return -2;
	}
	else {
		return swap;
	}
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
	
	if (p != NULL) {
		treeprint(p->left);
		printf("%s %s\n", p->first, p->last);
		treeprint(p->right);
	}
}

/* talloc: make a node */
struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
	}