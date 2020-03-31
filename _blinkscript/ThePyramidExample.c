//CS50 IDE: https://sandbox.cs50.io/3cfffd71-8415-4196-8337-21f6fc25051d

#include <stdio.h>
#include <cs50.h>

int perLine(int r, int n, int d){
	// same as python's string repeating function

	//r: cur row number
	//n: number of blocks
	//d: direction
	if (d==-1){
		for (int i=1; i<=n; i++){
			if(i<=(n-r)){
			  printf(" ");
			}else{
			  printf("#");
		  	}
		}
	}else if(d==1){
		for (int i=1; i<=n; i++){
		  	if(i<=r){
				printf("#");
		  	}else{
				printf(" ");
		  	}
		}
	}else{
		return 0;
	}
		return 0;
	}

int main(){
	int blocks;

	do{
		blocks = get_int("Height: ");
	}while(blocks<0);

	for (int r=1; r<=blocks; r++){
		perLine(r, blocks,-1);
		printf("  ");
		perLine(r, blocks,1);
		printf("\n");
	}
}

//return
/*
	   #  #
	  ##  ##
	 ###  ###
	####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
*/
