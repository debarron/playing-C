#include "RoboArm.h"

void RoboArm_moveAxis (int currentPosition, int finalPosition, char axis){
	while(currentPosition != finalPosition){
		if(currentPosition > finalPosition){
		       currentPosition = currentPosition - 1;
		}else{
	 		currentPosition = currentPosition + 1;
		}

		fprintf(stdout, ">> %c Axis, pos: %d\n", axis, currentPosition);		
	}
}

