#include "stdafx.h"
#include "../stdafx.h"
#include "vertex.h"

Vertex::Vertex()
{
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
}

Vertex::Vertex(double X, double Y, double Z)
{
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}

Vertex::Vertex(const Vertex& other)
{
	this->X = other.getX();
	this->Y = other.getY();
	this->Z = other.getZ();
}

Vertex::Vertex(Vertex&& other)
{
	this->X = other.getX();
	this->Y = other.getY();
	this->Z = other.getZ();
}

Vertex::~Vertex()
{
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
}

void Vertex::setX(double X)
{
	this->X = X;
}

void Vertex::setY(double Y)
{
	this->Y = Y;
}

void Vertex::setZ(double Z)
{
	this->Z = Z;
}

double Vertex::getX()
{
	return this->X;
}

double Vertex::getX() const
{
	return this->X;
}

double Vertex::getY()
{
	return this->Y;
}

double Vertex::getY() const
{
	return this->Y;
}

double Vertex::getZ()
{
	return this->Z;
}

double Vertex::getZ() const
{
	return this->Z;
}

void Vertex::modificate()
{
	//todo
}