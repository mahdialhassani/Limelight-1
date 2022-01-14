#include <Robot.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"


double leftleadmotorID = 3, rightleadmotorID = 1, leftfollowmotorID = 4 , rightfollowermotorID = 2;
  rev::CANSparkMax m_leftfront{leftleadmotorID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_leftback{leftfollowmotorID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightfront{rightleadmotorID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightback{rightfollowermotorID, rev::CANSparkMax::MotorType::kBrushless};

  std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
  double tx = table->GetNumber("tx",0.0);                   //Get horizontal off set from target
  double ty = table->GetNumber("ty",0.0);                   //Get vertical offset from target
  double ta = table->GetNumber("ta",0.0);                   //Get area of target on screen
  double ts = table->GetNumber("ts",0.0);                   //Get skew of target
  double tv = table->GetNumber("tv", 0.0);

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  m_leftback.Follow(m_leftfront);
  m_rightback.Follow(m_rightfront);
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  while (true){
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    double tx = table->GetNumber("tx",0.0);  
    float Kp = -0.1;

    float heading_error = tx;
    float steering_adjust = Kp * tx;

    m_leftfront += steering_adjust;
    m_rightfront -= steering_adjust;
  }
  /*
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  // fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
  */
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
