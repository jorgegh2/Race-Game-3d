#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Blue;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube cube1(info.cube1.x, info.cube1.y, info.cube1.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cube1.transform);

	Cube cube2(info.cube2.x, info.cube2.y, info.cube2.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cube2.transform);

	Cube cube3(info.cube3.x, info.cube3.y, info.cube3.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cube3.transform);

	Cube cube4(info.cube4.x, info.cube4.y, info.cube4.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cube4.transform);

	Cube cube5(info.cube5.x, info.cube5.y, info.cube5.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cube5.transform);

	Cube window(info.window.x, info.window.y, info.window.z);
	window.color = Cian;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&window.transform);

	Cylinder cylinder1(info.cilindre1.x, info.cilindre1.y);
	cylinder1.color = Cian;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cylinder1.transform);
	
	Cylinder cylindre2(info.cylindre2.x, info.cylindre2.y);
	cylindre2.color = White;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cylindre2.transform);

	Cylinder cylindre3(info.cylindre3.x, info.cylindre3.y);
	cylindre3.color = White;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cylindre3.transform);



	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();



	btVector3 cube1_offset(info.cube1_offset.x, info.cube1_offset.y, info.cube1_offset.z);
	cube1_offset = cube1_offset.rotate(q.getAxis(), q.getAngle());

	btVector3 cube2_offset(info.cube2_offset.x, info.cube2_offset.y, info.cube2_offset.z);
	cube2_offset = cube2_offset.rotate(q.getAxis(), q.getAngle());

	btVector3 cube3_offset(info.cube3_offset.x, info.cube3_offset.y, info.cube3_offset.z);
	cube3_offset = cube3_offset.rotate(q.getAxis(), q.getAngle());

	btVector3 cube4_offset(info.cube4_offset.x, info.cube4_offset.y, info.cube4_offset.z);
	cube4_offset = cube4_offset.rotate(q.getAxis(), q.getAngle());

	btVector3 cube5_offset(info.cube5_offset.x, info.cube5_offset.y, info.cube5_offset.z);
	cube5_offset = cube5_offset.rotate(q.getAxis(), q.getAngle());

	btVector3 window_offset(info.window_offset.x, info.window_offset.y, info.window_offset.z);
	window_offset = window_offset.rotate(q.getAxis(), q.getAngle());

	btVector3 cylinder1_offset(info.cilindre1_offset.x, info.cilindre1_offset.y, info.cilindre1_offset.z);
	cylinder1_offset = cylinder1_offset.rotate(q.getAxis(), q.getAngle());

	btVector3 cylindre2_offset(info.cylindre2_offset.x, info.cylindre2_offset.y, info.cylindre2_offset.z);
	cylindre2_offset = cylindre2_offset.rotate(q.getAxis(), q.getAngle());

	btVector3 cylindre3_offset(info.cylindre3_offset.x, info.cylindre3_offset.y, info.cylindre3_offset.z);
	cylindre3_offset = cylindre3_offset.rotate(q.getAxis(), q.getAngle());

	cube1.transform.M[12] += cube1_offset.getX();
	cube1.transform.M[13] += cube1_offset.getY();
	cube1.transform.M[14] += cube1_offset.getZ();

	cube2.transform.M[12] += cube2_offset.getX();
	cube2.transform.M[13] += cube2_offset.getY();
	cube2.transform.M[14] += cube2_offset.getZ();

	cube3.transform.M[12] += cube3_offset.getX();
	cube3.transform.M[13] += cube3_offset.getY();
	cube3.transform.M[14] += cube3_offset.getZ();

	cube4.transform.M[12] += cube4_offset.getX();
	cube4.transform.M[13] += cube4_offset.getY();
	cube4.transform.M[14] += cube4_offset.getZ();

	cube5.transform.M[12] += cube5_offset.getX();
	cube5.transform.M[13] += cube5_offset.getY();
	cube5.transform.M[14] += cube5_offset.getZ();

	window.transform.M[12] += window_offset.getX();
	window.transform.M[13] += window_offset.getY();
	window.transform.M[14] += window_offset.getZ();

	cylinder1.transform.M[12] += cylinder1_offset.getX();
	cylinder1.transform.M[13] += cylinder1_offset.getY();
	cylinder1.transform.M[14] += cylinder1_offset.getZ();

	cylindre2.transform.M[12] += cylindre2_offset.getX();
	cylindre2.transform.M[13] += cylindre2_offset.getY();
	cylindre2.transform.M[14] += cylindre2_offset.getZ();

	cylindre3.transform.M[12] += cylindre3_offset.getX();
	cylindre3.transform.M[13] += cylindre3_offset.getY();
	cylindre3.transform.M[14] += cylindre3_offset.getZ();

	cube1.Render();
	cube2.Render();
	cube3.Render();
	cube4.Render();
	cube5.Render();
	window.Render();
	cylindre2.Render();
	cylindre3.Render();
	cylinder1.Render();

}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}

vec3 PhysVehicle3D::GetBackDirection() const
{
	btVector3 ForwardVector = vehicle->getForwardVector();
	vec3 BackDirection = { -ForwardVector.getX(), -ForwardVector.getY(), -ForwardVector.getZ() };
	return BackDirection;
}

