#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	PhysVehicle3D* CreateCar();
	PhysVehicle3D* CreateVan();

public:
	PhysVehicle3D * car;
	PhysVehicle3D* van;
	PhysVehicle3D* vehicle;
	PhysVehicle3D* vehicle2;
	float turn;
	float acceleration;
	float brake;
	Cube c;
	PhysBody3D* pc;
};