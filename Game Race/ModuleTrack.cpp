#include "Globals.h"
#include "Application.h"
#include "PhysBody3D.h"
#include "Primitive.h"
#include "ModuleTrack.h"

ModuleTrack::ModuleTrack(Application* app, bool start_enable) : Module(app, start_enable) 
{

}

ModuleTrack::~ModuleTrack() {}

//Load assets

bool ModuleTrack::Start() {

	LOG("Loading track circuit");

	//Wall Derecha Recta1 

	CreateWall(10.0f, 1.5f, 50.0f);

	/*wall_1right.SetPos(10, 0, 50);
	wall_1right.size = { 5,3,100 };
	physWall_1right = App->physics->AddBody(wall_1right, WALL_MASS);
	wall_1right.SetRotation(0, { 0,1,0 });
	physWall_1right->SetTransform(wall_1right.transform.M);*/

	//Wall Izquierda Recta1 

	CreateWall(-10.0f, 1.5f, 50.0f);

	/*wall_1left.SetPos(-10, 0, 50);
	wall_1left.size = { 5,3,100};
	physWall_1left = App->physics->AddBody(wall_1left, WALL_MASS);
	wall_1left.SetRotation(0, { 0,1,0 });
	physWall_1left->SetTransform(wall_1left.transform.M);*/
	

	return true;
}

bool ModuleTrack::CleanUp() {

	LOG("Unloading track circuit");

	wallList.clear();
	
	//All bodies are deleted in module physics 
	physWallList.clear();
	return true;
}

void ModuleTrack::CreateWall(float position_x, float position_y, float position_z) {

	//Addbody y PhysBody añadir
	Cube wall;
	PhysBody3D* physWall = nullptr;
	wall.SetPos(position_x, position_y, position_z);
	wall.size = { 5,3,100 };
	physWall = App->physics->AddBody(wall, WALL_MASS);

	
	uint colorCount = wallList.count() % 2;
	switch (colorCount)
	{
	case 0:
		wall.color = Red;
		break;
	case 1:
		wall.color = Green;
		break;
	case 2:
		wall.color = Blue;
		break;
	}

	wallList.add(wall);
	physWallList.add(physWall);

	//cube.SetRotation(0, { 0,1,0 });
	//phys_cube->SetTransform(cube.transform.M);
	
}


update_status ModuleTrack::Update(float dt) {

	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	DrawWalls();

	//vec3 origin_wall_1right = physWall_1right->GetPos();
	//wall_1right.SetPos(origin_wall_1right.x, origin_wall_1right.y, origin_wall_1right.z);
	//wall_1right.Render();

	//vec3 origin_wall_1left = physWall_1left->GetPos();
	//wall_1left.SetPos(origin_wall_1left.x, origin_wall_1left.y, origin_wall_1left.z);
	//wall_1left.Render();

	return UPDATE_CONTINUE;
}

void ModuleTrack::DrawWalls() const
{
	p2List_item<Cube>* item = nullptr;

	for (item = wallList.getFirst(); item; item = item->next)
	{
		item->data.Render();
	}
}