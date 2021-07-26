//#include <iostream>
//#include<vector>
//
//using namespace std; 
//
//enum Direction {
//    up,
//    down
//};
//
//enum State {
//    moving,
//    idle,
//    stopped
//};
//
//class InternalReq {
//public:
//    int destFloor;
//};
//
//class ExternalReq {
//public:
//    int sourceFloor;
//    Direction dirn;
//};
//
//class Request {
//public:
//    InternalReq internalReq;
//    ExternalReq externalReq;
//};
//
//
//
//class Elevator {
//private:
//    int currFloor = 0;
//    State state = idle;
//    Direction currDirn;
//
//public:
//    Elevator() {}
//
//    void call(int floor) {
//        state = moving;
//        floor > currFloor ? currDirn = up : currDirn = down;
//            
//    }
//};
//
//class ElevatorSys {
//private:
//    vector<Elevator> _elevators;
//
//public:
//    ElevatorSys(vector<Elevator> elevators) {
//        _elevators = elevators;
//    }
//
//    void
//};
