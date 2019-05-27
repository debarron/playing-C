#include "RoboArm.h"

#define COLS 3

int** getSequenceData(FILE *theFile, int *rows){
	int i;
	int **values;

	fscanf(theFile, "%d", rows);
	values = (int **) malloc(sizeof(int *) * *rows);

	for(i = 0; i < *rows; i++){
		values[i] = (int *) malloc(sizeof(int) * COLS);
		
		fscanf(theFile, "%d,%d,%d\n", 
			&values[i][0], 
			&values[i][1], 
			&values[i][2]
		);
	}

	return values;
}


int main(int argc, char **argv){
	FILE *sequenceFile;
	int **sequenceData;
	int rows, i;
	char *filePath;

	int *currentPos;
	filePath = argv[1];

	//Init the File
	sequenceFile = fopen(filePath, "r");
	if(sequenceFile == NULL){
		fprintf(stdout, "Error with the file %s\n", filePath);
		exit(1);
	}

	//Get the Data
	sequenceData = getSequenceData(sequenceFile, &rows);
	fclose(sequenceFile);

	//Print the steps
	currentPos = sequenceData[0];
	fprintf(stdout, ">> Initial coordinate: %d %d %d\n", 
		sequenceData[0][0], 
		sequenceData[0][1], 
		sequenceData[0][2]
	);

	for(i = 1; i < rows; i++){
		fprintf(stderr, ">>>> Expected Position: %d %d %d\n", 
			sequenceData[i][0], 
			sequenceData[i][1], 
			sequenceData[i][2]
		);

		RoboArm_moveAxis(currentPos[0], sequenceData[i][0], 'X');
		RoboArm_moveAxis(currentPos[1], sequenceData[i][1], 'Y');
		RoboArm_moveAxis(currentPos[2], sequenceData[i][2], 'Z');

		currentPos = sequenceData[i];
	}

	fprintf(stdout, ">>>> End of the Program\n");
	fprintf(stdout, ">>>> Final position: %d %d %d\n", 
			currentPos[0], 
			currentPos[1], 
			currentPos[2]
		);

	return 0;
}