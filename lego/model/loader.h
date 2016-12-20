/*!
\file loader.h "model/loader.h"
\brief  Load model from file
\author Dmitry Zaitsev
\copyright � BMSTU All rights violated.
\version 1.0
\date 16 October 2016

Load model from file into Brick object
*/

#pragma once

#include "composite.h"
#include "exception.h"

/*!
\class Loader loader.h "model/loader.h"
\brief  Load model from file

Load model from file into Brick object
*/
class Loader
{
public:
	/*!
	Empty constructor. No action.
	*/
	Loader();

	/*!
	Constructor. Set name of file to read.
	\param[in] filename Name of file to read
	*/
	Loader(char* filename);

	/*!
	Destructor. No action.
	*/
	~Loader();

	/*!
	Main function. Loading from file into Brick object.
	\param[in] obj Composite array 
	\return Pointer to loaded Brick object
	*/
	Brick* load(Composite* obj);

private:
	/*!
	Opens file to read.
	*/
	void openFile();

	/*!
	Closes file after reading.
	*/
	void closeFile();

	/*!
	Reads line contins vertex coordinates.
	\return Vertex object contains coordinates from file
	*/
	Vertex readVertex();

	/*!
	Reads line contins face parameters.
	\return Three ID of vertex
	*/
	Face readFace();

	/*!
	Reads line contins normal coordinates
	\return Geometric vector contains normal to face
	*/
	GVector readNormal();

	char* filename;		/*!< Name of file to read */
	FILE* file;			/*!< File to read */

	double maxX, minX;	/*!< Min and max X coordinate of brick */
	double maxY, minY;	/*!< Min and max Y coordinate of brick */
	double maxZ, minZ;	/*!< Min and max Z coordinate of brick */
};
