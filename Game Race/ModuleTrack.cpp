#include "Globals.h"
#include "Application.h"
#include "PhysBody3D.h"
#include "Primitive.h"
#include "ModuleTrack.h"

ModuleTrack::ModuleTrack(Application* app, bool start_enable) : Module(app, start_enable) {

	wall_mass = 0.0f;
}

ModuleTrack::~ModuleTrack() {}

//Load assets

bool ModuleTrack::Start() {

	LOG("Loading track circuit");

	//Wall mass
	wall_mass = 30.0f;

	//Track walls
	wall.size.x = 10;
	wall.size.y = 10;
	wall.size.z = 10;

	wall.SetPos(50, 50, 0);
	App->physics->AddBody(wall, wall_mass);

	return true;
}

bool ModuleTrack::CleanUp() {

	LOG("Unloading track circuit");

	return true;
}


update_status ModuleTrack::Update(float dt) {

	wall.Render();

	return UPDATE_CONTINUE;
}