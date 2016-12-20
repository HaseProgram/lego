#pragma once
#include "model\loader.h"
#include "model\modification\rotation.h"
#include "model\modification\movement.h"

#define COLLISION_EPS 0.5

class Action
{
public:
	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) = 0;
};

class ActionLoadbrick : public Action
{
public:
	ActionLoadbrick(char* filename)
	{
		this->filename = filename;
	}

	~ActionLoadbrick()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		Loader brick(this->filename);
		brick.load(loadedBricks);
	}

private:
	char* filename;
};

class ActionAddbrick : public Action
{
public:
	ActionAddbrick(int X, int Y, int Z, COLORREF color, float trancparency)
	{
		this->X = X;
		this->Y = Y;
		this->Z = Z;
		this->color = color;
		this->trancparency = trancparency;
	}

	~ActionAddbrick()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		Brick brick = *(loadedBricks->objects[ID]);
		if (!scene->AddBrick(brick, ID, this->X, this->Y, this->Z, this->color, this->trancparency))
		{
			throw AddBrickCollisionError();
		}
	}

private:
	int X, Y, Z;
	COLORREF color;
	float trancparency;
};

class ActionDeletebrick : public Action
{
public:
	ActionDeletebrick(int delID)
	{
		this->delID = delID;
	}

	~ActionDeletebrick()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		scene->bricks->remove(this->delID);
	}

private:
	int delID;
};

class ActionDraw : public Action
{
public:
	ActionDraw()
	{
	}

	~ActionDraw()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		scene->DrawScene(ID);
	}
};

class ActionBrickRotateX : public Action
{
public:
	ActionBrickRotateX(double angle)
	{
		this->angle = angle;
	}

	~ActionBrickRotateX()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		RotationX* modification = new RotationX(this->angle);
		BaseObject* brick = scene->bricks;
		if (ID >= 0)
		{
			Composite* bricks = (Composite*)brick;
			brick = bricks->get(ID);
		}
		brick->modificate(modification);
		if (!scene->checkCollision(ID))
		{
			brick->applyModification();
			brick->angleX += this->angle;
		}
		else
		{
			this->angle /= 2;
			bool collision = false;
			while (abs(this->angle) > COLLISION_EPS)
			{
				Rotation* closer = new RotationX(this->angle);
				brick->modificate(closer);
				collision = (scene->checkCollision(ID) == 1);
				if (collision)
				{
					this->angle /= 2;
				}
				else
				{
					brick->applyModification();
					brick->angleX += this->angle;
				}
			}
		}
	}

private:
	double angle;
};

class ActionBrickRotateY : public Action
{
public:
	ActionBrickRotateY(double angle)
	{
		this->angle = angle;
	}

	~ActionBrickRotateY()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		RotationY* modification = new RotationY(this->angle);
		BaseObject* brick = scene->bricks;
		if (ID >= 0)
		{
			Composite* bricks = (Composite*)brick;
			brick = bricks->get(ID);
		}
		brick->modificate(modification);
		if (!scene->checkCollision(ID))
		{
			brick->applyModification();
			brick->angleY += this->angle;
		}
		else
		{
			this->angle /= 2;
			bool collision = false;
			while (abs(this->angle) > COLLISION_EPS)
			{
				Rotation* closer = new RotationY(this->angle);
				brick->modificate(closer);
				collision = (scene->checkCollision(ID) == 1);
				if (collision)
				{
					this->angle /= 2;
				}
				else
				{
					brick->applyModification();
					brick->angleY += this->angle;
				}
			}
		}
	}

private:
	double angle;
};

class ActionBrickRotateZ : public Action
{
public:
	ActionBrickRotateZ(double angle)
	{
		this->angle = angle;
	}

	~ActionBrickRotateZ()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		RotationZ* modification = new RotationZ(this->angle);
		BaseObject* brick = scene->bricks;
		if (ID >= 0)
		{
			Composite* bricks = (Composite*)brick;
			brick = bricks->get(ID);
		}
		brick->modificate(modification);
		if (!scene->checkCollision(ID))
		{
			brick->applyModification();
			brick->angleZ += this->angle;
		}
		else
		{
			this->angle /= 2;
			bool collision = false;
			while (abs(this->angle) > COLLISION_EPS)
			{
				Rotation* closer = new RotationZ(this->angle);
				brick->modificate(closer);
				collision = (scene->checkCollision(ID) == 1);
				if (collision)
				{
					this->angle /= 2;
				}
				else
				{
					brick->applyModification();
					brick->angleZ += this->angle;
				}
			}
		}
	}

private:
	double angle;
};

class ActionBrickMoveX : public Action
{
public:
	ActionBrickMoveX(double shift)
	{
		this->shift = shift;
	}

	~ActionBrickMoveX()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		MovementX* modification = new MovementX(this->shift);
		BaseObject* brick = scene->bricks;
		if (ID >= 0)
		{
			Composite* bricks = (Composite*)brick;
			brick = bricks->get(ID);
		}
		brick->modificate(modification);
		if (!scene->checkCollision(ID))
		{
			brick->applyModification();
		}
		else
		{
			this->shift /= 2;
			bool collision = false;
			while (abs(this->shift) > COLLISION_EPS)
			{
				Movement* closer = new MovementX(this->shift);
				brick->modificate(closer);
				collision = (scene->checkCollision(ID) == 1);
				if (collision)
				{
					this->shift /= 2;
				}
				else
				{
					brick->applyModification();
				}
			}
		}
	}

private:
	double shift;
};

class ActionBrickMoveY : public Action
{
public:
	ActionBrickMoveY(double shift)
	{
		this->shift = shift;
	}

	~ActionBrickMoveY()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		MovementY* modification = new MovementY(this->shift);
		BaseObject* brick = scene->bricks;
		if (ID >= 0)
		{
			Composite* bricks = (Composite*)brick;
			brick = bricks->get(ID);
		}
		brick->modificate(modification);
		if (!scene->checkCollision(ID))
		{
			brick->applyModification();
		}
		else
		{
			this->shift /= 2;
			bool collision = false;
			while (abs(this->shift) > COLLISION_EPS)
			{
				Movement* closer = new MovementY(this->shift);
				brick->modificate(closer);
				collision = (scene->checkCollision(ID) == 1);
				if (collision)
				{
					this->shift /= 2;
				}
				else
				{
					brick->applyModification();
				}
			}
		}
	}

private:
	double shift;
};

class ActionBrickMoveZ : public Action
{
public:
	ActionBrickMoveZ(double shift)
	{
		this->shift = shift;
	}

	~ActionBrickMoveZ()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		MovementZ* modification = new MovementZ(this->shift);
		BaseObject* brick = scene->bricks;
		if (ID >= 0)
		{
			Composite* bricks = (Composite*)brick;
			brick = bricks->get(ID);
		}
		brick->modificate(modification);
		Brick* currentBrick = (Brick*)brick;
		if (!scene->checkCollision(ID))
		{
			brick->applyModification();
		}
		else
		{
			this->shift /= 2;
			bool collision = false;
			while (abs(this->shift) > COLLISION_EPS)
			{
				Movement* closer = new MovementZ(this->shift);
				brick->modificate(closer);
				collision = (scene->checkCollision(ID) == 1);
				if (collision)
				{
					this->shift /= 2;
				}
				else
				{
					brick->applyModification();
				}
			}
		}
	}

private:
	double shift;
};

class ActionCameraRotationHorizontal : public Action
{
public:
	ActionCameraRotationHorizontal(double angle)
	{
		this->angle = angle;
	}

	~ActionCameraRotationHorizontal()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		scene->cam->rotateHorizontalSphere(this->angle);
	}

private:
	double angle;
};

class ActionCameraRotationVerticalZ : public Action
{
public:
	ActionCameraRotationVerticalZ(double angle)
	{
		this->angle = angle;
	}

	~ActionCameraRotationVerticalZ()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		scene->cam->rotateVerticalSphereZ(this->angle);
	}

private:
	double angle;
};

class ActionCameraRotationVerticalX : public Action
{
public:
	ActionCameraRotationVerticalX(double angle)
	{
		this->angle = angle;
	}

	~ActionCameraRotationVerticalX()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		scene->cam->rotateVerticalSphereX(this->angle);
	}

private:
	double angle;
};

// It's better to make new class but I have no time to make it look nice

class ActionLoadScene : public Action
{
public:
	ActionLoadScene(char* filename)
	{
		this->filename = filename;
		this->count = 0;
	}

	~ActionLoadScene()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		if ((this->file = fopen(this->filename, "r")) == NULL)
		{
			throw LoaderOpenFileError();
		}
		FILE* f = this->file;

		scene->bricks->clear();

		int bid;
		double t, x, y, z, rx, ry, rz;
		int rr, gg, bb;

		while (!feof(f))
		{
			if (fscanf_s(this->file, "%d/%lf/%d/%d/%d/%lf/%lf/%lf/%lf/%lf/%lf\n", &bid, &t, &rr, &gg, &bb, &x, &y, &z, &rx, &ry, &rz) != 11)
			{
				throw LoaderBadFile();
			}

			Brick brick = *(loadedBricks->objects[bid]);
			COLORREF c = RGB(rr, gg, bb);
			if (!scene->AddBrick(brick, bid, x, y, z, c, t))
			{
				throw AddBrickCollisionError();
			}

			
			BaseObject* scbrick = scene->bricks;
			Composite* bricks = (Composite*)scbrick;
			scbrick = bricks->get(bricks->ID);

			RotationX* arx = new RotationX(rx);
			scbrick->modificate(arx);
			scbrick->applyModification();

			RotationY* ary = new RotationY(ry);
			scbrick->modificate(ary);
			scbrick->applyModification();

			RotationZ* arz = new RotationZ(rz);
			scbrick->modificate(arz);
			scbrick->applyModification();

			count++;
		}

		fclose(this->file);
	}

	int count;

private:
	char* filename;
	FILE* file;
};

class ActionSaveScene : public Action
{
public:
	ActionSaveScene(char* filename)
	{
		this->filename = filename;
	}

	~ActionSaveScene()
	{
	}

	virtual void Execute(Scene* scene, Composite* loadedBricks, int ID) override
	{
		if ((this->file = fopen(this->filename, "w")) == NULL)
		{
			throw LoaderOpenFileError();
		}
		FILE* f = this->file;

		int bid;
		double t, x, y, z, rx, ry, rz;
		int rr, gg, bb;

		for (int i = 0; i <= scene->bricks->ID; i++)
		{
			Brick* tmp = scene->bricks->get(i);
			fprintf_s(this->file, "%d/%lf/%d/%d/%d/%lf/%lf/%lf/%lf/%lf/%lf\n",
				tmp->type,tmp->transparency, GetRValue(tmp->color), GetGValue(tmp->color), GetBValue(tmp->color), 
				tmp->center.X, tmp->center.Y, tmp->center.Z, tmp->angleX, tmp->angleY, tmp->angleZ);
		}

		fclose(this->file);
	}

private:
	char* filename;
	FILE* file;
};
