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

	App->physics->CreateWall(10.0f, 1.5f, 2.5f);
	App->physics->CreateWall(10.0f, 1.5f, 7.5f);
	App->physics->CreateWall(10.0f, 1.5f, 12.5f);
	App->physics->CreateWall(10.0f, 1.5f, 17.5f);
	App->physics->CreateWall(10.0f, 1.5f, 22.5f);
	App->physics->CreateWall(10.0f, 1.5f, 27.5f);
	App->physics->CreateWall(10.0f, 1.5f, 32.5f);
	App->physics->CreateWall(10.0f, 1.5f, 37.5f);	

	return true;
}

bool ModuleTrack::CleanUp() {

	LOG("Unloading track circuit");

	wallList.clear();
	
	//All bodies are deleted in module physics 
	return true;
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