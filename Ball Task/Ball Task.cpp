//============================================================================
// Name        : Ball.cpp
// Author      : Me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

struct Points {
	int x, y;
};
//for storing the x0 and y0

std::vector<int> ReadContentsOfFile(const std::string &);
void WriteToFile(std::vector<Points> &, std::ofstream &);
void Calculations(std::vector<int> &);

int main() {

	//opening the file
	std::string fileName = "BallTaskInput[1994].txt";
	std::vector<int> data(ReadContentsOfFile(fileName));

	//checking to see if the contents of the vector are correct
	/*for(std::vector<int>::iterator it = data.begin(); it != data.end(); it++){
	 std::cout << *it << std::endl;
	 }*/

	Calculations(data);

	return 0;
}

//function to read the input file and then return a populated vector with its contents
std::vector<int> ReadContentsOfFile(const std::string &fileName) {
	std::string file;
	std::ifstream fileContents;
	fileContents.open(fileName);
	if (!fileContents.is_open()) {
		std::cout << "File cannot be opened." << std::endl;
	}

	std::vector<int> vec;
	std::string line;
	while (getline(fileContents, line, ',')) {
		int value;
		std::stringstream lineStream(line);
		while (lineStream >> value) {
			vec.push_back(value);
		}

	}

	return vec;
}

//Calculations' function, using the Independence of Perpendicular Components of Motion
void Calculations(std::vector<int> &data) {
	//initializing the data according to the input file
	int xmax = data[0];
	int ymax = data[1];
	std::cout << "xmax: " << xmax << "  " << "ymax: " << ymax << std::endl
			<< std::endl;
	int xmin = 0;
	int ymin = 0;
	int x0 = data[2];
	int y0 = data[3];
	std::cout << "x0: " << x0 << "  " << "y0: " << y0 << std::endl << std::endl;
	int x1 = data[4];
	int y1 = data[5];
	std::cout << "x1: " << x1 << "  " << "y1: " << y1 << std::endl << std::endl;
	int vx = data[4]; // x component of the ball's velocity
	int vy = data[5]; // y component of the ball's velocity

	//time initialization

	int time_initial = 0; //time at the beginning of each step
	int time_final = 0; //time passed after one step
	int delta_t = 0; // delta_t = |time_final - time_initial|

	//for the calculation of the vector of the speed
	double sin_theta;
	double cos_theta;
	double hypotenuse;

	Points coordinate; //creating an object for storing the x0 and y0
	std::vector<Points> coordinates;	//creating a vector to store the (x0,y0)
	std::ofstream outFile;

	//calculation of the x and y according to the file data
	for (unsigned int i = 6; i < data.size(); i++) { // unsigned int because eclipse is giving me a warning
		time_final = data[i];
		delta_t = abs(time_final - time_initial);
		time_initial = time_final;

		//calculating each motion of the ball separately (x-axis, y-axis)
		//and correcting the trajectory if the ball hits a wall or a corner
		for (int i = 1; i <= delta_t; i++) {
			for (int step = 1; step <= vy; step++) {
				hypotenuse = sqrt(pow(x1, 2) + pow(y1, 2));
				sin_theta = x1 / hypotenuse;
				cos_theta = y1 / hypotenuse;

				if (sin_theta > 0 && cos_theta > 0) {

					y0++;
					if (y0 == ymax || y0 == ymin) {
						y1 = -y1;
					}

				} else if (sin_theta > 0 && cos_theta < 0) {

					y0--;
					if (y0 == ymax || y0 == ymin) {
						y1 = -y1;
					}

				} else if (sin_theta < 0 && cos_theta > 0) {

					y0++;
					if (y0 == ymax || y0 == ymin) {
						y1 = -y1;
					}
				} else if (sin_theta < 0 && cos_theta < 0) {

					y0--;
					if (y0 == ymax || y0 == ymin) {
						y1 = -y1;
					}

				}

			}

			for (int step = 1; step <= abs(vx); step++) {

				hypotenuse = sqrt(pow(x1, 2) + pow(y1, 2));
				sin_theta = x1 / hypotenuse;
				cos_theta = y1 / hypotenuse;

				if (sin_theta > 0 && cos_theta > 0) {

					x0++;
					if (x0 == xmax || x0 == xmin) {
						x1 = -x1;
					}

				} else if (sin_theta > 0 && cos_theta < 0) {

					x0++;
					if (x0 == xmax || x0 == xmin) {
						x1 = -x1;
					}

				} else if (sin_theta < 0 && cos_theta > 0) {

					x0--;
					if (x0 == xmax || x0 == xmin) {
						x1 = -x1;
					}
				} else if (sin_theta < 0 && cos_theta < 0) {

					x0--;
					if (x0 == xmax || x0 == xmin) {
						x1 = -x1;
					}

				}

			}

		}

		coordinate.x = x0;  //setting the x parameter equal to x0
		coordinate.y = y0;	//setting the y parameter equal to y0
		coordinates.push_back(coordinate);
		WriteToFile(coordinates, outFile);
		std::cout << "x0: " << x0 << "   " << "y0: " << y0 << std::endl;

	}

}

//function which writes the (x0,y0) after the calculations' loop
void WriteToFile(std::vector<Points> &vecp, std::ofstream &outFile) {

	std::string outPutFile = "CurrentOutput.txt";
	outFile.open(outPutFile);
	if (outFile.is_open()) {
		for (std::vector<Points>::iterator it = vecp.begin(); it != vecp.end();
				++it) {
			outFile << it->x << "," << it->y << std::endl;
		}
	} else {
		std::cout << "Cannot open file" << std::endl;
	}

}
