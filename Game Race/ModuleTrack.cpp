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

	//Wall Recta1 Izquierda 

	App->physics->CreateWall(10.0f, 1.5f, 2.5f);
	App->physics->CreateWall(10.0f, 1.5f, 7.5f);
	App->physics->CreateWall(10.0f, 1.5f, 12.5f);
	App->physics->CreateWall(10.0f, 1.5f, 17.5f);
	App->physics->CreateWall(10.0f, 1.5f, 22.5f);
	App->physics->CreateWall(10.0f, 1.5f, 27.5f);
	App->physics->CreateWall(10.0f, 1.5f, 32.5f);
	App->physics->CreateWall(10.0f, 1.5f, 37.5f);

	App->physics->CreateWall(10.0f, 1.5f, 42.5f);
	App->physics->CreateWall(10.0f, 1.5f, 47.5f);
	App->physics->CreateWall(10.0f, 1.5f, 52.5f);
	App->physics->CreateWall(10.0f, 1.5f, 57.5f);
	App->physics->CreateWall(10.0f, 1.5f, 62.5f);
	App->physics->CreateWall(10.0f, 1.5f, 67.5f);
	App->physics->CreateWall(10.0f, 1.5f, 72.5f);
	App->physics->CreateWall(10.0f, 1.5f, 77.5f);

	App->physics->CreateWall(10.0f, 1.5f, 82.5f);
	App->physics->CreateWall(10.0f, 1.5f, 87.5f);
	App->physics->CreateWall(10.0f, 1.5f, 92.5f);
	App->physics->CreateWall(10.0f, 1.5f, 97.5f);
	App->physics->CreateWall(10.0f, 1.5f, 102.5f);
	App->physics->CreateWall(10.0f, 1.5f, 107.5f);
	App->physics->CreateWall(10.0f, 1.5f, 112.5f);
	App->physics->CreateWall(10.0f, 1.5f, 117.5f);

	//Wall Recta1 Derecha

	App->physics->CreateWall(-10.0f, 1.5f, 2.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 7.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 12.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 17.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 22.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 27.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 32.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 37.5f);

	App->physics->CreateWall(-10.0f, 1.5f, 42.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 47.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 52.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 57.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 62.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 67.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 72.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 77.5f);

	App->physics->CreateWall(-10.0f, 1.5f, 82.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 87.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 92.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 97.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 102.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 107.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 112.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 117.5f);

	//First Curve Right

	App->physics->CreateWall(-7.5f, 1.5f, 122.5f);
	App->physics->CreateWall(-5.0f, 1.5f, 127.5f);
	App->physics->CreateWall(-2.5f, 1.5f, 132.5f);
	App->physics->CreateWall(-0.0f, 1.5f, 137.5f);
	App->physics->CreateWall(2.5f, 1.5f, 142.5f);
	App->physics->CreateWall(5.0f, 1.5f, 147.5f);

	App->physics->CreateWall(10.0f, 1.5f, 147.5f);
	App->physics->CreateWall(15.0f, 1.5f, 147.5f);
	App->physics->CreateWall(20.0f, 1.5f, 147.5f);

	//First Curve Left

	App->physics->CreateWall(12.5f, 1.5f, 122.5f);
	App->physics->CreateWall(15.0f, 1.5f, 127.5f);
	App->physics->CreateWall(20.0f, 1.5f, 127.5f);

	//Pequeña recta 2 Derecha
	App->physics->CreateWall(25.0f, 1.5f, 147.5f);
	App->physics->CreateWall(30.0f, 1.5f, 147.5f);
	App->physics->CreateWall(35.0f, 1.5f, 147.5f);

	//Pequeña recta 2 Izquierda
	App->physics->CreateWall(25.0f, 1.5f, 127.5f);
	App->physics->CreateWall(30.0f, 1.5f, 127.5f);
	App->physics->CreateWall(35.0f, 1.5f, 127.5f);
	App->physics->CreateWall(40.0f, 1.5f, 127.5f);

	//Curva 2 Izquierda
	App->physics->CreateWall(45.0f, 1.5f, 130.0f);
	App->physics->CreateWall(50.0f, 1.5f, 132.5f);
	App->physics->CreateWall(55.0f, 1.5f, 135.0f);
	App->physics->CreateWall(60.0f, 1.5f, 137.5f);
	App->physics->CreateWall(65.0f, 1.5f, 140.0f);
	App->physics->CreateWall(70.0f, 1.5f, 142.5f);

	App->physics->CreateWall(70.0f, 1.5f, 147.5f);
	App->physics->CreateWall(70.0f, 1.5f, 152.5f);
	App->physics->CreateWall(70.0f, 1.5f, 157.5f);

	//Curva 2 Derecha

	App->physics->CreateWall(40.0f, 1.5f, 150.0f);
	App->physics->CreateWall(45.0f, 1.5f, 152.5f);
	App->physics->CreateWall(45.0f, 1.5f, 157.5f);

	//Curva 3 Izquierda

	App->physics->CreateWall(70.0f, 1.5f, 162.5f);
	App->physics->CreateWall(70.0f, 1.5f, 167.5f);
	App->physics->CreateWall(67.5f, 1.5f, 172.5f);
	App->physics->CreateWall(62.5f, 1.5f, 175.0f);
	App->physics->CreateWall(57.5f, 1.5f, 177.5f);
	App->physics->CreateWall(52.5f, 1.5f, 180.0f);
	App->physics->CreateWall(47.5f, 1.5f, 182.5f);
	App->physics->CreateWall(42.5f, 1.5f, 185.0f);
	App->physics->CreateWall(37.5f, 1.5f, 185.0f);
	App->physics->CreateWall(32.5f, 1.5f, 185.0f);

	//Curva 3 Derecha

	App->physics->CreateWall(40.0f, 1.5f, 160.0f);
	App->physics->CreateWall(35.0f, 1.5f, 162.5f);
	App->physics->CreateWall(30.0f, 1.5f, 162.5f);

	//Recta 3 Antes de Rampa Izquierda

	App->physics->CreateWall(27.5f, 1.5f, 185.0f);
	App->physics->CreateWall(22.5f, 1.5f, 185.0f);
	App->physics->CreateWall(17.5f, 1.5f, 185.0f);
	App->physics->CreateWall(12.5f, 1.5f, 185.0f);

	App->physics->CreateWall(7.5f, 1.5f, 185.0f);
	App->physics->CreateWall(2.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-2.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-7.5f, 1.5f, 185.0f);

	App->physics->CreateWall(-12.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-17.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-22.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-27.5f, 1.5f, 185.0f);

	App->physics->CreateWall(-32.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-37.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-42.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-47.5f, 1.5f, 185.0f);

	//Recta 3 Antes de Rampa Derecha

	App->physics->CreateWall(25.0f, 1.5f, 162.5f);
	App->physics->CreateWall(20.0f, 1.5f, 162.5f);
	App->physics->CreateWall(15.0f, 1.5f, 162.5f);
	App->physics->CreateWall(10.0f, 1.5f, 162.5f);

	App->physics->CreateWall(5.0f, 1.5f, 162.5f);
	App->physics->CreateWall(0.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-5.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-10.0f, 1.5f, 162.5f);

	App->physics->CreateWall(-15.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-20.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-25.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-30.0f, 1.5f, 162.5f);

	App->physics->CreateWall(-35.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-40.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-45.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-50.0f, 1.5f, 162.5f);

	//RAMPA 1
	//85 to 62 = anchura rampa max -> 23, por lo tanto = 7.5 de ancho
	Cube ramp1;
	PhysBody3D* physRamp1 = nullptr;
	//{x, 4, x}
	ramp1.SetPos(-50, 1, 174);
	ramp1.size = { 0.1f, 8, 14 };
	physRamp1 = App->physics->AddBody(ramp1, WALL_MASS);

	ramp1.color = White;



	ramp1.SetRotation(85, { 0, 0, 1 });
	physRamp1->SetTransform(ramp1.transform.M);
	physRamp1->Setgravity0();
	App->track->wallList.add(ramp1);
	//cube.SetRotation(0, { 0,1,0 });
	//phys_cube->SetTransform(cube.transform.M);

	/*vec3 origin_ramp = physRamp1->GetPos();
	ramp1.SetPos(origin_ramp.x, origin_ramp.y, origin_ramp.z);*/

	//Recta 4 Despues de Rampa Derecha

	App->physics->CreateWall(-55.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-60.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-65.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-70.0f, 1.5f, 162.5f);

	App->physics->CreateWall(-75.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-80.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-85.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-90.0f, 1.5f, 162.5f);

	App->physics->CreateWall(-95.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-100.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-105.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-110.0f, 1.5f, 162.5f);

	App->physics->CreateWall(-115.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-120.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-125.0f, 1.5f, 162.5f);
	App->physics->CreateWall(-130.0f, 1.5f, 162.5f);

	//Recta 4 Despues de Rampa Izquierda

	App->physics->CreateWall(-52.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-57.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-62.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-67.5f, 1.5f, 185.0f);

	App->physics->CreateWall(-72.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-77.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-82.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-87.5f, 1.5f, 185.0f);

	App->physics->CreateWall(-92.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-97.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-102.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-107.5f, 1.5f, 185.0f);

	App->physics->CreateWall(-112.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-117.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-122.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-127.5f, 1.5f, 185.0f);

	//Curva 4 Derecha

	App->physics->CreateWall(-135.0f, 1.5f, 160.0f);
	App->physics->CreateWall(-140.0f, 1.5f, 157.5f);
	App->physics->CreateWall(-140.0f, 1.5f, 152.5f);
	App->physics->CreateWall(-135.0f, 1.5f, 150.0f);

	App->physics->CreateWall(-135.0f, 1.5f, 145.0f);
	App->physics->CreateWall(-130.0f, 1.5f, 140.0f);
	App->physics->CreateWall(-125.0f, 1.5f, 135.0f);

	//Curva 4 Izquierda

	App->physics->CreateWall(-132.5f, 1.5f, 185.0f);
	App->physics->CreateWall(-137.5f, 1.5f, 182.5f);
	App->physics->CreateWall(-142.5f, 1.5f, 180.0f);
	App->physics->CreateWall(-147.5f, 1.5f, 177.5f);

	App->physics->CreateWall(-152.5f, 1.5f, 175.0f);
	App->physics->CreateWall(-157.5f, 1.5f, 172.5f);
	App->physics->CreateWall(-162.5f, 1.5f, 170.0f);
	App->physics->CreateWall(-162.5f, 1.5f, 165.0f);

	App->physics->CreateWall(-162.5f, 1.5f, 160.0f);
	App->physics->CreateWall(-162.5f, 1.5f, 155.0f);
	App->physics->CreateWall(-162.5f, 1.5f, 150.0f);
	App->physics->CreateWall(-162.5f, 1.5f, 145.0f);

	App->physics->CreateWall(-157.5f, 1.5f, 140.0f);
	App->physics->CreateWall(-152.5f, 1.5f, 135.0f);
	App->physics->CreateWall(-147.5f, 1.5f, 130.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 125.0f);

	//Espacio Cuadrado Derecha

	App->physics->CreateWall(-120.0f, 1.5f, 135.0f);
	App->physics->CreateWall(-115.0f, 1.5f, 135.0f);
	App->physics->CreateWall(-110.0f, 1.5f, 135.0f);
	App->physics->CreateWall(-105.0f, 1.5f, 135.0f);
	App->physics->CreateWall(-100.0f, 1.5f, 135.0f);

	App->physics->CreateWall(-100.0f, 1.5f, 130.0f);
	App->physics->CreateWall(-100.0f, 1.5f, 125.0f);
	App->physics->CreateWall(-100.0f, 1.5f, 120.0f);
	App->physics->CreateWall(-100.0f, 1.5f, 115.0f);

	App->physics->CreateWall(-95.0f, 1.5f, 110.0f);
	App->physics->CreateWall(-90.0f, 1.5f, 105.0f);

	App->physics->CreateWall(-90.0f, 1.5f, 100.0f);
	App->physics->CreateWall(-90.0f, 1.5f, 95.0f);
	App->physics->CreateWall(-90.0f, 1.5f, 90.0f);
	App->physics->CreateWall(-90.0f, 1.5f, 85.0f);
	App->physics->CreateWall(-90.0f, 1.5f, 80.0f);
	App->physics->CreateWall(-90.0f, 1.5f, 75.0f);
	App->physics->CreateWall(-90.0f, 1.5f, 70.0f);
	App->physics->CreateWall(-90.0f, 1.5f, 65.0f);

	//Espacio Cuadrado Izquierda

	App->physics->CreateWall(-142.5f, 1.5f, 120.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 115.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 110.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 105.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 100.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 95.0f);

	App->physics->CreateWall(-137.5f, 1.5f, 95.0f);
	App->physics->CreateWall(-132.5f, 1.5f, 95.0f);
	App->physics->CreateWall(-127.5f, 1.5f, 95.0f);
	App->physics->CreateWall(-122.5f, 1.5f, 95.0f);

	App->physics->CreateWall(-117.5f, 1.5f, 90.0f);
	App->physics->CreateWall(-112.5f, 1.5f, 85.0f);

	App->physics->CreateWall(-112.5f, 1.5f, 80.0f);
	App->physics->CreateWall(-112.5f, 1.5f, 75.0f);


	//Curva 90 grados Derecha

	App->physics->CreateWall(-90.0f, 1.5f, 60.0f);
	App->physics->CreateWall(-90.0f, 1.5f, 55.0f);

	App->physics->CreateWall(-95.0f, 1.5f, 55.0f);
	App->physics->CreateWall(-100.0f, 1.5f, 55.0f);
	App->physics->CreateWall(-105.0f, 1.5f, 55.0f);
	App->physics->CreateWall(-110.0f, 1.5f, 55.0f);
	App->physics->CreateWall(-115.0f, 1.5f, 55.0f);
	App->physics->CreateWall(-120.0f, 1.5f, 55.0f);
	App->physics->CreateWall(-125.0f, 1.5f, 55.0f);

	App->physics->CreateWall(-125.0f, 1.5f, 50.0f);
	App->physics->CreateWall(-125.0f, 1.5f, 45.0f);
	App->physics->CreateWall(-125.0f, 1.5f, 40.0f);
	App->physics->CreateWall(-125.0f, 1.5f, 35.0f);



	//Curva 90 grados Izquierda

	App->physics->CreateWall(-117.5f, 1.5f, 75.0f);
	App->physics->CreateWall(-122.5f, 1.5f, 75.0f);
	App->physics->CreateWall(-127.5f, 1.5f, 75.0f);
	App->physics->CreateWall(-132.5f, 1.5f, 75.0f);
	App->physics->CreateWall(-137.5f, 1.5f, 75.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 75.0f);

	App->physics->CreateWall(-142.5f, 1.5f, 70.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 65.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 60.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 55.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 50.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 45.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 40.0f);
	App->physics->CreateWall(-142.5f, 1.5f, 35.0f);

	App->audio->PlayMusic("Music/LaCaravana.wav");

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