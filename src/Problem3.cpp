/*
Given a Tree which consists of operands and operators ,Solve the Tree and return the result
The tree will have special nodes of type enode which will have 3 fields
data => String of 5 chars .which can be either a operator or operand 
If its a operator its values will be one of the 3 following strings "+" , "-" , "*".
If its a operand its values will be any number from -9999 to 99999 in its respective string format;
Left and Right pointers will point to either NULL or another enode
Only the leaf nodes will have operand values .

Example 1:
    +
   / \
  4   5 
The Result expression is : 4+5 ,Ans is 9

Example 2:
        *
       / \
      -   5
     / \
    7   2

The Result expression is : (7-2) * 5  ,Ans is 25

Example 3:
       +
     /   \
    *     -  
   / \   / \
  7   2  4  *
           / \
          2   1
  
The Result expression is : (7*2) + (4-(2*1)) =>14+2 =>16 ,Ans is 16 

Constraints : 
Total number of enodes will be <=20 for 50% of Test cases
Data value will only have "0"<=data<="99999" values for 50% of cases .
Data value for operators will have sign as first character and \0 as next character .

Input :
Root node of a Tree of type enode
Output :
Return Final answer or -1 for Null inputs

Note :
->Dont Create an Extra Array/String ,or else your solution would receive 20%-40% Cut in the Marks you got .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

//data can be accessed using root->data;
struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

/*
Helper Functions are optional to write
*/
//Helper Functions Start
int isOperator(char *data){
	int index = 0;
	if (*data == '+' || *data == '*')
		return 1;
	else if (*data == '-')
	{
		while (data[index] != '\0')
		{
			index++;
		}
		if (index == 1)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int isOperand(char *data){
	return 1;
}
int getOperand(char *data){
	//converts data string to an integer "123" => 123
	int num = 0, index = 0;
	if (data[0] == '-')
	{
		index++;
	}
	int i = index;
		for (index = i;data[index] != '\0'; index++)
		num = (num * 10) + (data[index] - '0');
	return num;
}
//Helper Functions end
int inorder(struct enode*root)
{
	int val1, val2, lt, rt, res;
	if (root != NULL)
	{
		lt = inorder(root->left);
		rt = inorder(root->right);
		val1 = isOperator(root->data);
		if (val1 == 1)
		{
			if (root->data[0] == '+')
			{
				res = lt + rt;
			}
			else
				if (root->data[0] == '-')
				{
					res = lt - rt;
				}
				else
					if (root->data[0] == '*')
					{
						res = lt*rt;
					}
			return res;

		}
		if (val1 != 1)
			val2 = isOperand(root->data);
		if (val2 == 1)
			res = getOperand(root->data);
		return lt + rt + res;
	}
	return 0;
}
int solve_tree(struct enode *root){
	if (root==NULL)
		return -1;
	return inorder(root);

}
