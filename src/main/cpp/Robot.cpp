// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

#include <iostream>

void Robot::RobotInit() {
  std::cout << "Hi, Calla\n";
}

void Robot::RobotPeriodic() { }

void Robot::AutonomousInit() {
  //callasServo.Set(0.0);
  //callasTalon.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.1);
}

void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {
  std::cout << "Hi, Ishan\n";
  //callasServo.Set(1.0);
  //callasTalon.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.1);
}

void Robot::TeleopPeriodic() {
  double joystick = gameController.GetRawAxis(0);

  if (joystick > 0.5) {
    callasServo.Set(1.0);
  }
  else if (joystick < -0.5) {
    callasServo.Set(0.0);
  }
  else {
    callasServo.Set(0.5);
  }

  double dpad = gameController.GetPOV();

  if (dpad == 90) {
    callasTalon.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.1);
  }
  else if (dpad == 270) {
    callasTalon.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.1);
  }
  else {
    callasTalon.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
  }

  double potPosition = pot.Get();
  std::cout << potPosition << "\n";
}

void Robot::DisabledInit() {
  callasServo.Set(0.5);
  callasTalon.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
}

void Robot::DisabledPeriodic() {
}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
