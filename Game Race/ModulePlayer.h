#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1500.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f
#define DISTANCE_CAMERA 40
#define TITLE_LENGTH 80

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
	PhysVehicle3D* van1;
	PhysVehicle3D* van2;
	PhysVehicle3D* van3;
	
	float turn;
	float acceleration;
	float brake;
	
	bool cameraActive = true;
};