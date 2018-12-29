#include "Globals.h"
#include "Application.h"
#include "PhysBody3D.h"
#include "Primitive.h"
#include "ModuleTrack.h"

ModuleTrack::ModuleTrack(Application* app, bool start_enable) : Module(app, start_enable) {

}

ModuleTrack::~ModuleTrack() {}

//Load assets

bool ModuleTrack::Start() {

	LOG("Loading track circuit");

	//Wall Derecha Recta1 

	CreateCube(wall_1right, physWall_1right, 10.0f, 0.0f, 50.0f);

	/*wall_1right.SetPos(10, 0, 50);
	wall_1right.size = { 5,3,100 };
	physWall_1right = App->physics->AddBody(wall_1right, WALL_MASS);
	wall_1right.SetRotation(0, { 0,1,0 });
	physWall_1right->SetTransform(wall_1right.transform.M);*/

	//Wall Izquierda Recta1 
	wall_1left.SetPos(-10, 0, 50);
	wall_1left.size = { 5,3,100};
	physWall_1left = App->physics->AddBody(wall_1left, WALL_MASS);
	wall_1left.SetRotation(0, { 0,1,0 });
	physWall_1left->SetTransform(wall_1left.transform.M);
	

	return true;
}

bool ModuleTrack::CleanUp() {

	LOG("Unloading track circuit");

	return true;
}

void ModuleTrack::CreateCube(Cube& cube, PhysBody3D* phys_cube, float position_x, float position_y, float position_z) {

	//Addbody y PhysBody añadir
	cube.SetPos(position_x, position_y, position_z);
	cube.size = { 5,3,100 };
	phys_cube = App->physics->AddBody(cube, WALL_MASS);
	//cube.SetRotation(0, { 0,1,0 });
	//phys_cube->SetTransform(cube.transform.M);
	
}


update_status ModuleTrack::Update(float dt) {

	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	vec3 origin_wall_1right = physWall_1right->GetPos();
	wall_1right.SetPos(origin_wall_1right.x, origin_wall_1right.y, origin_wall_1right.z);
	wall_1right.Render();

	vec3 origin_wall_1left = physWall_1left->GetPos();
	wall_1left.SetPos(origin_wall_1left.x, origin_wall_1left.y, origin_wall_1left.z);
	wall_1left.Render();

	return UPDATE_CONTINUE;
}