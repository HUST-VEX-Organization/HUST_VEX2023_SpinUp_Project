using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Left_Give;
extern motor Right_Give;
extern controller Controller1;
extern motor Get_Plate;
extern motor Motor8;
extern motor MOVE1;
extern motor MOVE2;
extern motor MOVE3_FO;
extern motor MOVE4;
extern smartdrive Drivetrain;
extern motor BeginFire;
extern motor Air;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );