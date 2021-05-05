#ifndef CONCURRENTOBJECT_H
#define CONCURRENTOBJECT_H

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#include "RouteModel.h"
#include "RoutePlanner.h"

class ConcurrentObject {
  public:
    // constructor / destructor
    ConcurrentObject() {};
    ConcurrentObject(RouteModel *model, std::shared_ptr<RoutePlanner> route_planner) : model_(model), route_planner_(route_planner) {};
    ~ConcurrentObject();

    virtual void Simulate() {};

  protected:
    virtual void GenerateNew() {};
    int MAX_OBJECTS = 10; // TODO: Change or remove limit?
    RouteModel *model_;
    std::vector<std::thread> threads; // Holds all threads that have been launched within this object
    static std::mutex mtx_;           // Mutex shared by all concurrent objects for protecting cout
    int idCnt_ = 0; // Count object ids
    std::shared_ptr<RoutePlanner> route_planner_; // Route planner to use throughout the sim
};

#endif