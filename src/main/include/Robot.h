// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc/Servo.h>
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc/GenericHID.h>
#include <frc/AnalogPotentiometer.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  frc::Servo callasServo { 1 };
  ctre::phoenix::motorcontrol::can::TalonSRX callasTalon { 5 };
  frc::DigitalInput callasDIO { 5 };
  frc::GenericHID gameController { 0 };
  frc::AnalogPotentiometer pot { 0 };
};
