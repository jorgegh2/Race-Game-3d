#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Primitive.h"

//EN START() CREATE BODY, HACER FUNCIÓN PARA RECOPILAR TODAS LAS WALL

#define WALL_MASS 100000

class ModuleTrack : public Module {
public:
	ModuleTrack(Application* app, bool start_enable = true);
	virtual ~ModuleTrack();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void CreateCube(Cube&, PhysBody3D*, float, float, float);

public:
	Cube wall_1right;
	PhysBody3D* physWall_1right = nullptr;

	Cube wall_1left;
	PhysBody3D* physWall_1left = nullptr;

};