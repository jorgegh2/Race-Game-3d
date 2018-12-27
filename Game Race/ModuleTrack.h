#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Primitive.h"

//EN START() CREATE BODY, HACER FUNCI�N PARA RECOPILAR TODAS LAS WALL

class ModuleTrack : public Module {
public:
	ModuleTrack(Application* app, bool start_enable = true);
	virtual ~ModuleTrack();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

public:
	Cube wall;
	float wall_mass;

};