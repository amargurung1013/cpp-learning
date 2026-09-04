#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main() {
    int motorRPM {200};
    int batteryVoltage {2000};
    int sensorDistance {100};
    int* motorPtr {&motorRPM};
    int* batteryPtr {&batteryVoltage};
    int* sensorDistPtr {&sensorDistance};
    LOG(motorRPM);
    LOG(batteryVoltage);
    LOG(sensorDistance);
    *motorPtr = 300;
    *batteryPtr = 1800;
    *sensorDistPtr = 50;
    LOG(motorRPM);
    LOG(batteryVoltage);
    LOG(sensorDistance);

    int* control;

    control = &motorRPM;
    *control = 300;
    control = &sensorDistance;
    *control = 200;
    LOG(motorRPM);
    LOG(sensorDistance);


}