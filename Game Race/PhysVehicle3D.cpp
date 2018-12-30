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

	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();

	btVector3 cube1_offset(info.cube1_offset.x, info.cube1_offset.y, info.cube1_offset.z);
	cube1_offset = cube1_offset.rotate(q.getAxis(), q.getAngle());

	btVector3 cube2_offset(info.cube2_offset.x, info.cube2_offset.y, info.cube2_offset.z);
	cube2_offset = cube2_offset.rotate(q.getAxis(), q.getAngle());

	cube1.transform.M[12] += cube1_offset.getX();
	cube1.transform.M[13] += cube1_offset.getY();
	cube1.transform.M[14] += cube1_offset.getZ();

	cube2.transform.M[12] += cube2_offset.getX();
	cube2.transform.M[13] += cube2_offset.getY();
	cube2.transform.M[14] += cube2_offset.getZ();

	cube1.Render();
	cube2.Render();

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