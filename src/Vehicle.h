#ifndef VEHICLE_H
#define VEHICLE_H

#include <memory>
#include <vector>

#include "Coordinate.h"
#include "MapObject.h"
#include "Passenger.h"
#include "RouteModel.h"

namespace rideshare {

enum VehicleState {
    no_passenger_requested,
    no_passenger_queued,
    passenger_queued,
    waiting,
    driving_passenger,
};

class Vehicle: public MapObject {
  public:
    // Constructor / Destructor

    // Getters / Setters
    int Shape() { return shape_; }
    int State() { return state_; }
    int PathIndex() { return path_index_; }
    std::shared_ptr<Passenger> GetPassenger() { return passenger_; }
    void SetState(VehicleState state) { state_ = state; }
    void SetPassenger(std::shared_ptr<Passenger> passenger);
    void SetPosition(const Coordinate &position); // Override base class
    void SetDestination(const Coordinate &destination); // Override base class

    // Other functionality
    void DropOffPassenger();
    void IncrementPathIndex() { ++path_index_; }

  private:
    void ResetPathAndIndex();

    std::shared_ptr<Passenger> passenger_;
    int shape_ = DrawMarker::square;
    int state_ = VehicleState::no_passenger_requested;
    int path_index_ = 0;
};

}  // namespace rideshare

#endif
