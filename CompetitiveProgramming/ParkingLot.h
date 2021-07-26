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
	unordered_map< VehicleType, priority_queue< pair<int, VehicleSlot*> > > pqMap;
	unordered_map<VehicleSlot*, int> distances;
	Exit(string name) {
		this -> name = name;
	}
	void addDist(VehicleSlot *vehicleSlot, int dist) {
		if (pqMap.find(vehicleSlot->vehicleSlotType) != pqMap.end())
			pqMap[vehicleSlot->vehicleSlotType].push({ -dist, vehicleSlot });
		else {
			pqMap[vehicleSlot->vehicleSlotType] = priority_queue < pair<int, VehicleSlot*>>{};
			pqMap[vehicleSlot->vehicleSlotType].push({ -dist, vehicleSlot });
		}
		distances[vehicleSlot] = dist;
	}

	VehicleSlot* getSlot(VehicleType vehicleType) {
		while (!pqMap[vehicleType].empty()) {
			int dist = pqMap[vehicleType].top().first;
			VehicleSlot* ret = pqMap[vehicleType].top().second;
			pqMap[vehicleType].pop();
			if (ret->isOccupied == false) {
				ret->isOccupied = true;
				return ret;
			}
		}
		return nullptr;
	}

	void freeSlot(VehicleSlot *vehicleSlot) {
		vehicleSlot->isOccupied = false;
		int dist = distances[vehicleSlot];
		pqMap[vehicleSlot->vehicleSlotType].push({ -dist, vehicleSlot});
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
	int bookSlot(string exitName, VehicleType vehicleType) {
		exits[exitName]->getSlot(vehicleType);
	}
	int releaseSlot(int slotId) {
		VehicleSlot* slot = slots[slotId];
		for (auto el : exits) {
			Exit* exit = el.second;
			string exitName = el.first;
			exit->freeSlot(slot);
		}
	}
};







