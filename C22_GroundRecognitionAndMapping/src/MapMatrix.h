/*
 * MapMatrix.h
 *
 *  Created on: Dec 26, 2012
 *      Author: root
 */

#ifndef MAPMATRIX_H_
#define MAPMATRIX_H_
#include "pclPlane.h"
#include "MPlane.h"
#include "MapSquare.h"
#include "math.h"
#include <pcl/ModelCoefficients.h>
#include <pcl/point_types.h>
const int SIZEOFMAP = 12;	//The map matrix is defined as a square of SIZEOFMAP*SIZEOFMAP meters
const double SIZEOFSQUARE = 0.25;	//Size of each square is defined by SIZEOFSQUARE*SIZEOFSQUARE in meters
const int BEHIND = 2;		//Number of meters behind robot in map matrix
const int NUMOFSQUARES = 48;	//in one row or column- calculated as length of mapped area (in meters) * 4 (because we have 0.25cm squares)

class MapMatrix {
public:
	std::vector<std::vector<MapSquare*>*>* data;
	MapMatrix();
	virtual ~MapMatrix();
	void clearMatrix();
	void printMatrix();
	void computeMMatrix(std::vector<pclPlane*>* mapPlanes,pcl::PointCloud<pcl::PointXYZ>::Ptr map_cloud);
private:
	double calcSlopeZ(float a,float b,float c);
	bool inMatrixRange(pcl::PointXYZ p);
};

#endif /* MAPMATRIX_H_ */