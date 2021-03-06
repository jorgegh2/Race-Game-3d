#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"
#include "ModulePhysics3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), car(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	car = CreateCar();
	van1 = CreateVan();
	van2 = CreateVan();
	van3 = CreateVan();

	van2->SetPos(0.0f, 0.0f, -18.0f);
	van3->SetPos(0.0f, 0.0f, -30.0f);
	App->physics->AddConstraintP2P(*car, *van1, vec3{ 0,0.25f,-5 }, vec3{ 0,-0.25f,5 });
	App->physics->AddConstraintP2P(*van1, *van2, vec3{ 0,0.25f,-5 }, vec3{ 0,-0.25f,5 });
	App->physics->AddConstraintP2P(*van2, *van3, vec3{ 0,0.25f,-5 }, vec3{ 0,-0.25f,5 });

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}

	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		if (car->GetKmh() <= 0)
		{
			acceleration = -MAX_ACCELERATION;
		}
		else
		{
			brake = BRAKE_POWER;
		}
	}

	car->ApplyEngineForce(acceleration);
	car->Turn(turn);
	car->Brake(brake);

	if (App->input->GetKey(SDL_SCANCODE_F10) == KEY_DOWN)
	{
		cameraActive = !cameraActive;
	}

	if (cameraActive)
	{
		App->camera->CameraFollowVehicle(DISTANCE_CAMERA);
	}
	

	car->Render();
	van1->Render();
	van2->Render();
	van3->Render();
	
	//App->physics->AddConstraintP2P(*vehicle, *pc, vec3{ -3,1,0 }, vec3{ 3,-1,0 });

//	App->physics->AddConstraintHinge(*vehicle, *pc, vec3{ -3,1,0 }, vec3{ 3,-1,0 }, vec3{0,0,1}, vec3{ 0,0,1 });
	/*vec3 origin_phys_pc = pc->GetPos();
	c.SetPos(origin_phys_pc.x, origin_phys_pc.y, origin_phys_pc.z);
	c.Render();*/

	char title[TITLE_LENGTH];
	sprintf_s(title, "La Caravana");
	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}

PhysVehicle3D* ModulePlayer::CreateCar()
{
	VehicleInfo car;

	// Car properties ----------------------------------------
	car.cube1.Set(2.5f, 1.5f, 6.0f);
	car.cube1_offset.Set(0, 1.5, 0);
	car.cube2.Set(2.5f, 1.5f, 4.0f);
	car.cube2_offset.Set(0, 3, -1.0f);
	car.cube3.Set(2.5f, 1.0f, 2.0f);
	car.cube3_offset.Set(0, 1.25f, -2.75f);
	car.cilindre1.Set(1.5, 2.4, 0);
	car.cilindre1_offset.Set(0, 2.25f, 1.0f);
	car.window.Set(2.0f, 1.25f, 1.0f);
	car.window_offset.Set(0.0f, 3.0f, -2.6f);
	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.5f;
	float wheel_radius = 0.80f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.cube1.x*0.5f;
	float half_length = car.cube1.z*0.5f;

	vec3 direction(0, -1, 0);
	vec3 axis(-1, 0, 0);

	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	PhysVehicle3D* vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 1, 0);

	return vehicle;
}

PhysVehicle3D* ModulePlayer::CreateVan()
{
	VehicleInfo car;

	// Car properties ----------------------------------------
	car.cube1.Set(3.0f, 1.5f, 7);//3, 3, 4
	car.cube1_offset.Set(0.0f, 0.75f, 0.0f);//0, 1.5, 0
	car.cube2.Set(1, 0.5f, 4);
	car.cube2_offset.Set(0.0f, 0.5f, 5.0f);
	car.cube3.Set(1.5f, 0.75f, 1);
	car.cube3_offset.Set(0.0f, 0.5f, 3.5f);
	car.cube4.Set(3, 3, 5);
	car.cube4_offset.Set(0, 1.5, -0.5f);
	//car.cube5.Set(4.0f, 1.5f, -2.0f);
	//car.cube5_offset.Set(0.0f, 2.0f, -2.0f);
	car.cylindre2.Set(1.25f, 2.99f, 0.0f);
	car.cylindre2_offset.Set(0.0f, 1.75f, 2.25f);
	car.cylindre3.Set(1.0f, 2.99f, 0.0f);
	car.cylindre3_offset.Set(0.0f, 2.0f, -2.75f);
	car.window.Set(3.1f, 1.25f, 3.5f);
	car.window_offset.Set(0.0f, 2.0f, -0.5f);
	car.mass = 125.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.cube1.x*0.5f;
	float half_length = car.cube1.z*0.5f;

	vec3 direction(0, -1, 0);
	vec3 axis(-1, 0, 0);

	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	PhysVehicle3D* vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 1, -8);

	return vehicle;
}



