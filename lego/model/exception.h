#pragma once

#include "../exception.h"

class LoaderError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Can not load model!";
	}
};

class CompositeAddNULLError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Attempting to add NULL item into composite!";
	}
};

class TransparencyValueError : public BaseException
{
public:
	virtual const char* what() const
	{
		return "Transparency value must be in 0..100 interval!";
	}
};
