#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <malloc.h>


#define ALLOC(typ,no) ((typ *) allocation(sizeof(typ)*(no)))
typedef enum { FALSE,TRUE} bool;
typedef enum {INTEGER ,FLOAT ,PROGNAME ,ERROR} Type;


//list of symbols
typedef struct{
  int intNum;
  float floatNum;
  Type type;	
} number;
#include "lps_tab.h"
typedef struct node {
	char id[20];
	number num;
	struct node* next;
}node ;

typedef struct{
    node* head;
}List;

List s_list;
/**********************************/

/**********************************/
typedef struct undefined{
    char id[20];
    struct undefined* next; 
}undefined;

//list of the undefined id`s
typedef struct{
    undefined* head;
}udefined_list;

udefined_list u_list;
/**********************************/

extern int yyparse();
extern FILE *yyin, *yyout;
const char * src;




int sleTypeCheck(const char* str){
    return !strcmp(str,"sle")||!strcmp(str,"SLE");
}

void* allocation(unsigned int size){
    void* alloc = malloc(size);
	if (!alloc) {
		fprintf(stderr, "allocation faild");
		exit(1);
	}
	return alloc;
}

//search the symbol in the list
node* searchSymbol(const char* id){
    node* temp = s_list.head;
	while (temp)
	{
		if(!strcmp(id,temp->id)){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

//insert the symbol to the list
void insertSymbol(const char* id, number insert_num){
    node* temp = searchSymbol(id);

    if(temp != NULL){ //if the symbol allready in the list then return.
        if(temp->num.type == INTEGER){
            temp->num.intNum = insert_num.intNum;
        }
        if(temp->num.type == FLOAT){
            temp->num.floatNum = insert_num.floatNum;
        }
        return;
    }
    node* new_node = ALLOC(node,1);
    strcpy(new_node->id, id);
    new_node->num.type = insert_num.type;
    new_node->next = s_list.head;
	s_list.head = new_node;
}


//insert symbol to the undefined list
void insertUndefinedSymbol(const char* id){
    undefined* temp = ALLOC(undefined, 1);
	strcpy(temp->id, id);
	temp->next = u_list.head;
	u_list.head = temp;
}


//search the symbol in the undefined list
int searchInUndefined(const char* id){
    undefined* temp = u_list.head;

    while(temp){
        if(!strcmp(id, temp->id)){
			return 1;
		}
		temp = temp->next;
    }
    insertUndefinedSymbol(id);
    return 0;
}

//insert the assign operator to the list
void insertAssignOp(const char* id, number insert_num){
    node* temp = searchSymbol(id);
	if(!temp){
		searchInUndefined(id);
		return;
	}

	if(temp->num.type == FLOAT){
    
    	temp->num.floatNum = insert_num.type==FLOAT? insert_num.floatNum:(float)insert_num.intNum;
    }
  	if(temp->num.type == INTEGER){
   	temp->num.intNum = insert_num.type==FLOAT? (int)insert_num.floatNum:insert_num.intNum;
	}
  return;
}

//print the value of symbol with value of number
void printNumber(number print_num){
    switch(print_num.type){
    	case INTEGER:
    	printf("%d",print_num.intNum);
    	return;
		case FLOAT:
		printf("%f",print_num.floatNum);
		return;
		case ERROR:
		return;
  }
}


//get the number value of symbol
number getSymbolValue(const char* id){
    node* temp = searchSymbol(id);
	if(!temp){
		searchInUndefined(id);
		number failed;
		failed.type = ERROR;
		return failed;
	}
	return temp->num;
}


//return the result of boolean expration
int booleanExpration(number left_num, char sign, number right_num){
    double left;
    double right;

    if(left_num.type == INTEGER){
        left = left_num.intNum;
    }
    else{
        left = left_num.floatNum;
    }

    if(right_num.type == INTEGER){
        right = right_num.intNum;
    }
    else{
        right = right_num.floatNum;
    }

  switch( sign ){
    case '<':
    	return left < right? TRUE:FALSE;
    case '>':
    	return left > right? TRUE:FALSE;
    case '!':
    	return left != right? TRUE:FALSE;
    case '=':
    	return left == right? TRUE:FALSE;
    case '&':
    	return left && right? TRUE:FALSE;
    case '~':
    	return left || right? TRUE:FALSE;
  }
}


//make the add operation expration
number addOperator(number left_num, char sign, number right_num){
    double left;
  	double right;
    number result;
    double temp_val;

    if(left_num.type == INTEGER){
        left = left_num.intNum;
    }
    else{
        left = left_num.floatNum;
    }

    if(right_num.type == INTEGER){
        right = right_num.intNum;
    }
    else{
        right = right_num.floatNum;
    }

	right = (sign == '-') ? -right:right;
	temp_val  = left + right;


	if(left_num.type == INTEGER && right_num.type == INTEGER){
		result.type == INTEGER;
		result.intNum = (int)temp_val;
	}else{
		result.type == FLOAT;
		result.floatNum = temp_val;
	}
	return result;
}

//make the mult operation expration
number mulOperator(number left_num, char sign, number right_num){
	double left;
  	double right;
	number result;

    if(left_num.type == INTEGER){
        left = left_num.intNum;
    }
    else{
        left = left_num.floatNum;
    }

    if(right_num.type == INTEGER){
        right = right_num.intNum;
    }
    else{
        right = right_num.floatNum;
    }

	if(left_num.type == INTEGER && right_num.type == INTEGER){
		result.type == INTEGER;
	}

	switch (sign){
		case '*':
            if(result.type == INTEGER){
                result.intNum = (int)(left * right);
            }
            else{
                result.floatNum = left * right;
            }
			break;
		case '/':
			if(right == 0){
				fprintf(stderr, "cant divide by zero!\n");
				break;
			}
            if(result.type == INTEGER){
                result.intNum = (int)(left / right);
            }
            else{
                result.floatNum = left / right;
            }
			break;
		case '%':
			if(result.type == FLOAT){
				fprintf(stderr, "MOD operator can only work on INTEGER numbers\n");
				break;
			}else{
				result.intNum = (int)left % (int)right;
				break;
			}
	}
	return result;
}





int main(int argc, char** argv){
    src = strchr(argv[1],'.')+1;

    if(argc < 2){
        fprintf(stderr, "arguments not valid");
    }

    if(!sleTypeCheck(src)){
		fprintf(stderr,"The file type needs to be .sle!\n");
		exit(1);
	}

    if((yyin = fopen(argv[1],"r")) == NULL){
		fprintf(stderr,"Error openning file!");
		exit(1);
	}

    if(yyparse()){
		fprintf(stdout,"parse was not successful\n");
	}else{
		fprintf(stdout,"parse was successful\n");
	}



    fclose(yyin);
    return 0;
}