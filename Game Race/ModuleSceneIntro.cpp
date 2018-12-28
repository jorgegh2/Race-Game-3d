#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(0.0f, 15.0f, -30.0f));
	App->camera->LookAt(vec3(0.0f, 0.0f, 1.0f));

	hola.SetPos(5, 5, 5);
	hola.size = { 5,5,5 };
	physHola = App->physics->AddBody(hola, 100000);
	hola.SetRotation(45, { 0,1,0 });
	physHola->SetTransform(hola.transform.M);

	Cube c = { 10,10,10 };
	c.SetPos(0, 5, 50);
	Sensor = App->physics->AddBody(c, 0);
	Sensor->collision_listeners.add(this);
	Sensor->SetAsSensor(true);


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	vec3 origin = physHola->GetPos();

	
	hola.SetPos(origin.x, origin.y, origin.z);
	
	hola.Render();


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Yeeeeyy!")
}

