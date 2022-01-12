// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"

double leftleadmotorID = 3, rightleadmotorID = 1, leftfollowmotorID = 4 , rightfollowermotorID = 2;
 rev::CANSparkMax m_leftfront{leftleadmotorID, rev::CANSparkMax::MotorType::kBrushless};
 rev::CANSparkMax m_leftback{leftfollowmotorID, rev::CANSparkMax::MotorType::kBrushless};
 rev::CANSparkMax m_rightfront{rightleadmotorID, rev::CANSparkMax::MotorType::kBrushless};
 rev::CANSparkMax m_rightback{rightfollowermotorID, rev::CANSparkMax::MotorType::kBrushless};


void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  m_leftback.Follow(m_leftfront);
  m_rightback.Follow(m_rightfront);
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif