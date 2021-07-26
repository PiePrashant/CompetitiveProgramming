#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include <string>
#include <string>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
#include<queue>
#include<stack>

using namespace std;



enum VehicleType {mini, sedan, suv, bus, truck};

class VehicleSlot {
public:
	int id;
	VehicleType vehicleSlotType;
	bool isOccupied = false;
	VehicleSlot(int id, VehicleType name) {
		this-> id = id;
		vehicleSlotType = name;
	}
};


class Exit {
public:
	string name;
	vector<VehicleType> supportedVehicle;
	unordered_map< VehicleType, priority_queue< pair<int, VehicleSlot*> > > distances;

	Exit(string name) {
		this -> name = name;
	}
	void addDist(VehicleSlot *vehicleSlot, int dist) {
		if (distances.find(vehicleSlot->vehicleSlotType) != distances.end())
			distances[vehicleSlot->vehicleSlotType].push({ -dist, vehicleSlot });
		else {
			distances[vehicleSlot->vehicleSlotType] = priority_queue < pair<int, VehicleSlot*>>{};
			distances[vehicleSlot->vehicleSlotType].push({ -dist, vehicleSlot });
		}
	}

	VehicleSlot* getSlot(VehicleType vehicleType) {
		while (!distances[vehicleType].empty()) {
			int dist = distances[vehicleType].top().first;
			VehicleSlot* ret = distances[vehicleType].top().second;
			distances[vehicleType].pop();
			if (ret->isOccupied == false) {
				ret->isOccupied = true;
				return ret;
			}
		}
		return nullptr;
	}

	void freeSlot(VehicleSlot *vehicleSlot,  int dist) {
		vehicleSlot->isOccupied = false;
		distances[vehicleSlot->vehicleSlotType].push({ -dist, vehicleSlot});
	}
};

class ParkingLot
{
private:
	unordered_map<string, Exit*> exits;
	unordered_map<int, VehicleSlot*> slots;

public:
	void addExit(string name) {
		exits[name] = new Exit(name);
	}
	void addVehcileSlot(int id, VehicleType vehicleSlotType) {
		slots[id] = new VehicleSlot(id, vehicleSlotType);
	}
	void addDist(string exitName, int slotId, int dist) {
		exits[exitName]->addDist(slots[slotId], dist);
	}
	int findSlot(string exitName, VehicleType vehicleType) {
		exits[exitName]->
	}
};







