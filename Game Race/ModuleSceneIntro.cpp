#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"

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

	Cube cSensor = { 20,5,2 };
	cSensor.SetPos(-135, 5, 5);
	Sensor = App->physics->AddBody(cSensor, 0);
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

	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
	{
		App->player->car->SetPos(0.0f, 0.0f, 1.0f);
		App->player->van1->SetPos(0.0f, 0.0f, -8.0f);
		App->player->van2->SetPos(0.0f, 0.0f, -18.0f);
		App->player->van3->SetPos(0.0f, 0.0f, -30.0f);
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	App->player->cameraActive = false;
}

