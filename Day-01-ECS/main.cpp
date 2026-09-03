#include <iostream>
#include <print>
#include <string>

class VehicleSystem {
public:
    VehicleSystem() = default;
    VehicleSystem(std::string systemName, std::string systemId, std::string systemStatus)
        : mSystemName{systemName}, mSystemId(systemId), mSystemStatus(systemStatus) {
        std::print("\nVehicle system constructor");
    }

    virtual void PrintStatus() {
        std::print("\nSystem Name: {}\nSystem Id: {}\nSystem Status: {}\n", mSystemName, mSystemId, mSystemStatus);
    }

protected:
    std::string mSystemName;
    std::string mSystemId;
    std::string mSystemStatus;
};

class EngineSystem: public VehicleSystem {
public:
    EngineSystem(std::string systemName, std::string systemId, std::string systemStatus, int rpmValue, float coolantTemp)
        : VehicleSystem(systemName, systemId, systemStatus), mRPM{rpmValue}, mCoolantTemperature(coolantTemp) {
        std::print("\nEngineSystem Constructor");
    }

    void ChangeStatus(int newValue){
        if (newValue < 0) {
            return;
        }
        else {
            mSystemStatus = "WARNING";
            mRPM = newValue;
            mCoolantTemperature = 105.0f;
            std::print("\nEngine status updated.");
        }
    }

    virtual void PrintStatus() override {
        VehicleSystem::PrintStatus();
        std::print("RPM: {}\nCoolant Temperature: {}\n", mRPM, mCoolantTemperature);
    }
protected:
    int mRPM;
    float mCoolantTemperature;
};

class BrakeSystem: public VehicleSystem {
public:
    BrakeSystem(std::string systemName, std::string systemId, std::string systemStatus, int breakValue, std::string activeState)
        : VehicleSystem(systemName, systemId, systemStatus), mBrakePressure{breakValue}, mABSActiveState{activeState} {
        std::print("\nBreakSystem Constructor");

    }

    void updateStatus(int newValue) {
        mSystemStatus = "WARNING";
        mBrakePressure = 58;
        std::print("\nBrake status updated!");
    }

    virtual void PrintStatus() override {
        VehicleSystem::PrintStatus();
        std::print("BrakePressure: {}\nABS active state: {}\n", mBrakePressure, mABSActiveState);
    }
protected:
    int mBrakePressure;
    std::string mABSActiveState;
};


class CameraSystem: public VehicleSystem {
public:
    CameraSystem(std::string systemName, std::string systemId, std::string systemStatus, std::string resolutionValue, int objectDetected)
        : VehicleSystem(systemName, systemId, systemStatus), mResolution{resolutionValue}, mDetectedObjects{objectDetected} {
        std::print("\nCameraSystem Constructor");

    }

    virtual void PrintStatus() override {
        VehicleSystem::PrintStatus();
        std::print("Resolution: {}\nDetected Objects: {}\n", mResolution, mDetectedObjects);
    }
protected:
    std::string mResolution;
    int mDetectedObjects;
};

int main() {
    EngineSystem engine{"Engine Control Unit", "ENG-01", "OK", 2100, 89.0f};
    BrakeSystem brakes{"Brake Control Unit", "BRK-01", "OK", 42, "Active"};
    CameraSystem camera{"Front Camera", "CAM-01",
        "OK", "1920X1080", 5};

    std::print("\n=== System Information ===\n\n=== INITIAL STATUS ===\n");
    engine.PrintStatus();
    brakes.PrintStatus();
    camera.PrintStatus();
    engine.ChangeStatus(6000);
    engine.PrintStatus();
}