/*
* 
*project2diazj1: my main class.
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
	
main() {

	char firstName[MAXWORD];
	char lastName[MAXWORD];
	char empty[MAXWORD];
	int bool = kgetline(firstName, lastName);
	struct tnode *root;
	root = talloc();
	
	//setting up the root
	if(bool == 0) { 
	root->first = strdup(firstName);
	root->last = strdup(lastName);	
	}
	else {
	root->first = strdup(lastName);
	root->last = strdup(firstName);
	}
	
	while(bool != -1 && bool != -2) { //the negatives are for the last nodes

		bool = kgetline(firstName, lastName);
		
		if((bool == 0) || (bool == -2)) {
			root = addtree(root, firstName, lastName);
		}
		else {
			root = addtree(root, lastName, firstName);
		}
	}

	treeprint(root);

} 