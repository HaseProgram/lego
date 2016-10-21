/*!
\file brick.h "model/brick.h"
\brief  Model basement
\author Dmitry Zaitsev
\copyright � BMSTU All rights violated.
\version 1.0
\date 16 October 2016

Contains model archetecture
*/

#pragma once
using namespace std;

#include "vertex.h"
#include "face.h"

/*!
\class Brick brick.h "model/brick.h"
\brief  Brick archetecture

Provide interface brick values
*/
class Brick : public BaseObject
{
public:
	/*!
	Emty constructor. No action.
	*/
	Brick();

	/*!
	Constructor. Copies incoming model.
	\param[in] brick Source model to copy.
	*/
	Brick(const Brick& brick);

	/*!
	Constructor. Transfer incoming model.
	\param[in] brick Source model to transfer.
	*/
	Brick::Brick(Brick&& brick);

	/*!
	Destructor. Clears vertex and faces array.
	*/
	~Brick();

	/*!
	Copies incoming model.
	\param[in] brick Source model to copy.
	\return Link to this object.
	*/
	Brick& operator=(const Brick& brick);

	/*!
	Adds vertex in model.
	\param[in] v Vertex to add in array.
	*/
	void addVertex(Vertex v);

	/*!
	Adds face in model.
	\param[in] face Vector of 3 links
	*/
	void addFace(Face);

	/*!
	Provides access to vertex array
	\return Vertex array
	*/
	vector<Vertex> getVertex() const;

	/*!
	Provides access to faces array
	\return Faces array
	*/
	vector<Face> getFaces() const;

	/*!
	Amount of vertex in model
	\return Amount of items
	*/
	int vertexCount();

	/*!
	Amount of faces in model
	\return Amount of items
	*/
	int facesCount();

	/*!
	Modificate coordinates (rotate/zoom etc)
	\todo param[in] modification
	*/
	virtual void modificate() override;

	/*!
	Get uniqui ID of brick
	\return ID of brick
	*/
	virtual int getID() override;

	/*!
	Set uniqui ID of brick
	\param[in] ID of brick
	*/
	void setID(int ID);

private:
	int ID;
	vector<Vertex> vertex;		/*!< Vertex array */
	vector<Face> faces;			/*!< Faces array */
};