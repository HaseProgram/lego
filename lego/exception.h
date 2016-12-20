#pragma once
#include <exception>

class BaseException : public std::exception
{
public:
	virtual const char* what() const = 0;
};

class AllocationMemoryError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can't allocate memory!";
	}
};

class ModelChoosingError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Choose model to add from top select field!";
	}
};

class BrickChoosingError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Choose brick to modifiate from bottom select field!";
	}
};

class AddBrickCollisionError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can't add brick on this coordinates:\n another brick blocks place!";
	}
};

class LoaderOpenFileError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not open file! Please check if file exists!";
	}
};

class LoaderBadFile : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Wrong file structure!";
	}
};