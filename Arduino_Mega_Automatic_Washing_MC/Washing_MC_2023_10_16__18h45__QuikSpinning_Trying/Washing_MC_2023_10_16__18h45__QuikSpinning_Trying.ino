#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x25, 16, 2);
//LiquidCrystal_I2C lcd1(0x23, 20, 4);

//***********************************************
//***********************************************
//            SERIAL PRINT TIMER

unsigned long SerialPrintTime = 50;
unsigned long SerialPrintStartTime;
unsigned long SerialPrintProgress;
unsigned long SerialPrintResetTime = 1000;

int SerialPrintState;
//***********************************************

//***********************************************
//            LCD PRINT TIMER

unsigned long LCDPrintTime = 50;
unsigned long LCDPrintStartTime;
unsigned long LCDPrintProgress;
unsigned long LCDPrintResetTime = 1000;

int LCDPrintState;
//***********************************************
//***********************************************
//***********************************************
//            STOP TIMER

unsigned long StopTime = 100;
unsigned long StopStartTime;
unsigned long StopProgress;
unsigned long StopResetTime = 1000;

int StopState;
//***********************************************
//***********************************************
//            SUBTRACT TIMER

unsigned long SubtractTime = 5;
unsigned long SubtractStartTime;
unsigned long SubtractProgress;
unsigned long SubtractResetTime = 1000;

int SubtractState;
//***********************************************
//***********************************************
//           QUIK SUBTRACT TIMER

unsigned long QuikSubtractTime = 5;
unsigned long QuikSubtractStartTime;
unsigned long QuikSubtractProgress;
unsigned long QuikSubtractResetTime = 1000;

int QuikSubtractState;
//***********************************************
//***********************************************
//            FULL CYCLE TIMER 1


int RunningCycleTime;
int RunningCycleTimeSeconds;
int RunningCycleTimeMinutes;
int millisec;
int tseconds;
int tminutes;
int seconds;
String DisplayTime;
int times;

int PrevCycleSeconds; //  = 60;
int PostCycleSeconds; //  = PrevCycleSeconds + 60;

int PrevCycleMinutes; //  = 60;
int PostCycleMinutes; // = PrevCycleMinutes + 60;

//*********************************************************

int UltraLow;   //  = 15;= Total = 15, Wash = 5, Rinse = 8, Spin = 2;    *****!!!! ALL TIMES IN MINUTES
int UltraLowCycle;   //  = 15;= Total = 15, Wash = 5, Rinse = 8, Spin = 2;    *****!!!! ALL TIMES IN MINUTES
int UltraLowCycleTimeMinutes;    //      = 15;
int UltraLowCycleTimeSeconds;
int UltraLowCycleTimeMilliSeconds;
int UltraLowCycleTime;     //      = 15;
float UltraLowWashCycleTime;     //      = 5;
float UltraLowWashCycleTimeSeconds;     //      = 5;
float UltraLowWashCycleTimeMillis;     //      = 5;
float UltraLowRinseCycleTime;     //      = 8;
float UltraLowRinseCycleTimeSeconds;     //      = 8;
float UltraLowRinseCycleTimeMillis;     //      = 8;
float UltraLowSpinCycleTime;     //      = 2;
float UltraLowSpinCycleTimeSeconds;     //      = 2;
float UltraLowSpinCycleTimeMillis;     //      = 2;

int QuikUltraLowWashCycleTimeMinutes;    //      = 15;
int QuikUltraLowWashCycleTimeSeconds;

int QuikUltraLowRinseCycleTimeMinutes;    //      = 15;
int QuikUltraLowRinseCycleTimeSeconds;

int QuikUltraLowSpinCycleTimeMinutes;    //      = 15;
int QuikUltraLowSpinCycleTimeSeconds;

//*********************************************************

int ExtraLow;   //  = 21;= Total = 21, Wash = 5, Rinse = 10, Spin = 6;    *****!!!! ALL TIMES IN MINUTES
int ExtraLowCycle;   //  = 21;= Total = 21, Wash = 5, Rinse = 10, Spin = 6;    *****!!!! ALL TIMES IN MINUTES
int ExtraLowCycleTimeMinutes;    //      = 59;
int ExtraLowCycleTimeSeconds;
int ExtraLowCycleTimeMilliSeconds;    //      = 59;
int ExtraLowCycleTime;     //      = 21;
float ExtraLowWashCycleTime;     //      = 5;
float ExtraLowWashCycleTimeSeconds;     //      = 5;
float ExtraLowWashCycleTimeMillis;     //      = 5;
float ExtraLowRinseCycleTime;     //      = 10;
float ExtraLowRinseCycleTimeSeconds;     //      = 10;
float ExtraLowRinseCycleTimeMillis;     //      = 10;
float ExtraLowSpinCycleTime;     //      = 6;
float ExtraLowSpinCycleTimeSeconds;     //      = 6;
float ExtraLowSpinCycleTimeMillis;     //      = 6;

int QuikExtraLowWashCycleTimeMinutes;    //      = 15;
int QuikExtraLowWashCycleTimeSeconds;

int QuikExtraLowRinseCycleTimeMinutes;    //      = 15;
int QuikExtraLowRinseCycleTimeSeconds;

int QuikExtraLowSpinCycleTimeMinutes;    //      = 15;
int QuikExtraLowSpinCycleTimeSeconds;

//*********************************************************

int VeryLow;   //  = 25;= Total = 25, Wash = 7, Rinse = 12, Spin = 6;    *****!!!! ALL TIMES IN MINUTES
int VeryLowCycle;   //  = 25;= Total = 25, Wash = 7, Rinse = 12, Spin = 6;    *****!!!! ALL TIMES IN MINUTES
int VeryLowCycleTimeMinutes;    //      = 25;
int VeryLowCycleTimeSeconds;
int VeryLowCycleTimeMilliSeconds;
int VeryLowCycleTime;     //      = 25;
float VeryLowWashCycleTime;     //      = 7;
float VeryLowWashCycleTimeSeconds;     //      = 7;
float VeryLowWashCycleTimeMillis;     //      = 7;
float VeryLowRinseCycleTime;     //      = 12;
float VeryLowRinseCycleTimeSeconds;
float VeryLowRinseCycleTimeMillis;
float VeryLowSpinCycleTime;     //      = 6;
float VeryLowSpinCycleTimeSeconds;
float VeryLowSpinCycleTimeMillis;

int QuikVeryLowWashCycleTimeMinutes;    //      = 15;
int QuikVeryLowWashCycleTimeSeconds;

int QuikVeryLowRinseCycleTimeMinutes;    //      = 15;
int QuikVeryLowRinseCycleTimeSeconds;

int QuikVeryLowSpinCycleTimeMinutes;    //      = 15;
int QuikVeryLowSpinCycleTimeSeconds;

//*********************************************************

int Low;        //  = 28;= Total = 28, Wash = 8, Rinse = 12, Spin = 8;    *****!!!! ALL TIMES IN MINUTES
int LowCycle;        //  = 28;= Total = 28, Wash = 8, Rinse = 12, Spin = 8;    *****!!!! ALL TIMES IN MINUTES
int LowCycleTimeMinutes;    //      = 59;
int LowCycleTimeSeconds;
int LowCycleTimeMilliSeconds;    //      = 59;
int LowCycleTime;     //      = 28;
float LowWashCycleTime;     //      = 8;
float LowWashCycleTimeSeconds;
float LowWashCycleTimeMillis;
float LowRinseCycleTime;     //      = 12;
float LowRinseCycleTimeSeconds;
float LowRinseCycleTimeMillis;
float LowSpinCycleTime;     //      = 8;
float LowSpinCycleTimeSeconds;
float LowSpinCycleTimeMillis;

int QuikLowWashCycleTimeMinutes;    //      = 15;
int QuikLowWashCycleTimeSeconds;

int QuikLowRinseCycleTimeMinutes;    //      = 15;
int QuikLowRinseCycleTimeSeconds;

int QuikLowSpinCycleTimeMinutes;    //      = 15;
int QuikLowSpinCycleTimeSeconds;

//*********************************************************

int MedLow;     //  = 34;= Total = 34, Wash = 12, Rinse = 15, Spin = 7;   *****!!!! ALL TIMES IN MINUTES
int MedLowCycle;     //  = 34;= Total = 34, Wash = 12, Rinse = 15, Spin = 7;   *****!!!! ALL TIMES IN MINUTES
int MedLowCycleTimeMinutes;    //      = 59;
int MedLowCycleTimeSeconds;
int MedLowCycleTimeMilliSeconds;    //      = 59;
int MedLowCycleTime;     //      = 34;
float MedLowWashCycleTime;     //      = 12;
float MedLowWashCycleTimeSeconds;
float MedLowWashCycleTimeMillis;
float MedLowRinseCycleTime;     //      = 15;
float MedLowRinseCycleTimeSeconds;
float MedLowRinseCycleTimeMillis;
float MedLowSpinCycleTime;     //      = 7;
float MedLowSpinCycleTimeSeconds;
float MedLowSpinCycleTimeMillis;

int QuikMedLowWashCycleTimeMinutes;    //      = 15;
int QuikMedLowWashCycleTimeSeconds;

int QuikMedLowRinseCycleTimeMinutes;    //      = 15;
int QuikMedLowRinseCycleTimeSeconds;

int QuikMedLowSpinCycleTimeMinutes;    //      = 15;
int QuikMedLowSpinCycleTimeSeconds;

//*********************************************************

int MedMed;     //  = 38;= Total = 38, Wash = 14, Rinse = 17, Spin = 7;   *****!!!! ALL TIMES IN MINUTES
int MedMedCycle;     //  = 38;= Total = 38, Wash = 14, Rinse = 17, Spin = 7;   *****!!!! ALL TIMES IN MINUTES
int MedMedCycleTimeMinutes;    //      = 38;
int MedMedCycleTimeSeconds;
int MedMedCycleTimeMilliSeconds;
int MedMedCycleTime;     //      = 38;
float MedMedWashCycleTime;     //      = 14;
float MedMedWashCycleTimeSeconds;
float MedMedWashCycleTimeMillis;
float MedMedRinseCycleTime;     //      = 17;
float MedMedRinseCycleTimeSeconds;
float MedMedRinseCycleTimeMillis;
float MedMedSpinCycleTime;     //      = 7;
float MedMedSpinCycleTimeSeconds;
float MedMedSpinCycleTimeMillis;

int QuikMedMedWashCycleTimeMinutes;    //      = 15;
int QuikMedMedWashCycleTimeSeconds;

int QuikMedMedRinseCycleTimeMinutes;    //      = 15;
int QuikMedMedRinseCycleTimeSeconds;

int QuikMedMedSpinCycleTimeMinutes;    //      = 15;
int QuikMedMedSpinCycleTimeSeconds;

//*********************************************************

int Medium;     //  = 41;= Total = 41, Wash = 15, Rinse = 16, Spin = 10;  *****!!!! ALL TIMES IN MINUTES
int MediumCycle;     //  = 41;= Total = 41, Wash = 15, Rinse = 16, Spin = 10;  *****!!!! ALL TIMES IN MINUTES
int MediumCycleTimeMinutes;    //      = 59;
int MediumCycleTimeSeconds;
int MediumCycleTimeMilliSeconds;    //      = 59;
int MediumCycleTime;     //      = 41;
float MediumWashCycleTime;     //      = 15;
float MediumWashCycleTimeSeconds;
float MediumWashCycleTimeMillis;
float MediumRinseCycleTime;     //      = 16;
float MediumRinseCycleTimeSeconds;
float MediumRinseCycleTimeMillis;
float MediumSpinCycleTime;     //      = 10;
float MediumSpinCycleTimeSeconds;
float MediumSpinCycleTimeMillis;

int QuikMediumWashCycleTimeMinutes;    //      = 15;
int QuikMediumWashCycleTimeSeconds;

int QuikMediumRinseCycleTimeMinutes;    //      = 15;
int QuikMediumRinseCycleTimeSeconds;

int QuikMediumSpinCycleTimeMinutes;    //      = 15;
int QuikMediumSpinCycleTimeSeconds;

//*********************************************************

int MedHigh;     //  = 45;= Total = 45, Wash = 17, Rinse = 18, Spin = 10;  *****!!!! ALL TIMES IN MINUTES
int MedHighCycle;     //  = 45;= Total = 45, Wash = 17, Rinse = 18, Spin = 10;  *****!!!! ALL TIMES IN MINUTES
int MedHighCycleTimeMinutes;    //      = 45;
int MedHighCycleTimeSeconds;
int MedHighCycleTimeMilliSeconds;
int MedHighCycleTime;     //      = 45;
float MedHighWashCycleTime;     //      = 17;
float MedHighWashCycleTimeSeconds;
float MedHighWashCycleTimeMillis;
float MedHighRinseCycleTime;     //      = 18;
float MedHighRinseCycleTimeSeconds;
float MedHighRinseCycleTimeMillis;
float MedHighSpinCycleTime;     //      = 10;
float MedHighSpinCycleTimeSeconds;
float MedHighSpinCycleTimeMillis;

int QuikMedHighWashCycleTimeMinutes;    //      = 15;
int QuikMedHighWashCycleTimeSeconds;

int QuikMedHighRinseCycleTimeMinutes;    //      = 15;
int QuikMedHighRinseCycleTimeSeconds;

int QuikMedHighSpinCycleTimeMinutes;    //      = 15;
int QuikMedHighSpinCycleTimeSeconds;

//*********************************************************

int High;       //  = 52;= Total = 52, Wash = 17, Rinse = 20, Spin = 15;  *****!!!! ALL TIMES IN MINUTES
int HighCycle;       //  = 52;= Total = 52, Wash = 17, Rinse = 20, Spin = 15;  *****!!!! ALL TIMES IN MINUTES
int HighCycleTimeMinutes;    //      = 59;
int HighCycleTimeSeconds;
int HighCycleTimeMilliSeconds;    //      = 59;
int HighCycleTime;     //      = 52;
float HighWashCycleTime;     //      = 17;
float HighWashCycleTimeSeconds;
float HighWashCycleTimeMillis;
float HighRinseCycleTime;     //      = 20;
float HighRinseCycleTimeSeconds;
float HighRinseCycleTimeMillis;
float HighSpinCycleTime;     //      = 15;
float HighSpinCycleTimeSeconds;
float HighSpinCycleTimeMillis;

int QuikHighWashCycleTimeMinutes;    //      = 15;
int QuikHighWashCycleTimeSeconds;

int QuikHighRinseCycleTimeMinutes;    //      = 15;
int QuikHighRinseCycleTimeSeconds;

int QuikHighSpinCycleTimeMinutes;    //      = 15;
int QuikHighSpinCycleTimeSeconds;

//*********************************************************

int Maximum;    //  = 59;= Total = 59, Wash = 19, Rinse = 24, Spin = 16;  *****!!!! ALL TIMES IN MINUTES
int MaximumCycle;    //  = 59;= Total = 59, Wash = 19, Rinse = 24, Spin = 16;  *****!!!! ALL TIMES IN MINUTES
int MaximumCycleTimeMinutes;    //      = 59;
int MaximumCycleTimeSeconds;    //      = 59;
int MaximumCycleTimeMilliSeconds;    //      = 59;
float MaximumWashCycleTime;    //      = 19;
float MaximumWashCycleTimeSeconds;
float MaximumWashCycleTimeMillis;
float MaximumRinseCycleTime;     //     = 24;
float MaximumRinseCycleTimeSeconds;
float MaximumRinseCycleTimeMillis;
float MaximumSpinCycleTime;     //     = 16;
float MaximumSpinCycleTimeSeconds;
float MaximumSpinCycleTimeMillis;

int QuikMaximumWashCycleTimeMinutes;    //      = 15;
int QuikMaximumWashCycleTimeSeconds;

int QuikMaximumRinseCycleTimeMinutes;    //      = 15;
int QuikMaximumRinseCycleTimeSeconds;

int QuikMaximumSpinCycleTimeMinutes;    //      = 15;
int QuikMaximumSpinCycleTimeSeconds;


//*********************************************************

int HotCycle;
int ColdCycle;
int DelayCycle;

int HotColdCNT = 0;
int CycleVolumeCNT = 0;

//int CourseCNT = 0;

unsigned long CycleSetTime;     /// = 3240;   //Cycle Time To Run In Seconds.
unsigned long CycleProgressSetTime = CycleSetTime * 1000;

int NumberOfCycles;
//int EachCycleTime;   // = CycleProgressSetTime / NumberOfCycles;

float EachCycleTime;   // = CycleProgressSetTime / NumberOfCycles;

unsigned long CycleSeconds;
unsigned long CycleMinutes;
unsigned long CycleHours;

unsigned long CycleProgressSeconds;
unsigned long CycleProgressMinutes;
unsigned long CycleProgressHours;

unsigned long CycleTime = 0;
unsigned long CycleStartTime;
unsigned long CycleProgress;

unsigned long WashCycleProgress;
unsigned long WashCycleTime = 500;
unsigned long WashCycleStartTime;
unsigned long WashCycleStopTime;    // = EachCycleTime;

unsigned long RinseCycleProgress;
unsigned long RinseCycleTime = 0;
unsigned long RinseCycleStartTime;
unsigned long RinseCycleStopTime;    // = EachCycleTime;

unsigned long SpinCycleProgress;
unsigned long SpinCycleTime = 0;
unsigned long SpinCycleStartTime;
unsigned long SpinCycleStopTime;    // = EachCycleTime;
unsigned long SpinCycleBuzzerStopTime;    // = EachCycleTime;




unsigned long CycleResetTime1;    // = EachCycleTime;
unsigned long CycleResetTime2;     // = EachCycleTime + EachCycleTime;
unsigned long CycleResetTime3;    //// = EachCycleTime + EachCycleTime + EachCycleTime;
unsigned long CycleResetTime4;    //// = EachCycleTime + EachCycleTime + EachCycleTime;

//unsigned long FillWashCycle;
//unsigned long StopFillCycle;
//unsigned long WashRunCycle;
//unsigned long StopWashCycle;
//unsigned long WashDrainCycle;
//unsigned long SmallWashSpinCycle;
//unsigned long StopSmallSpin;
//unsigned long StopDrainCycle;
//unsigned long FillRinseCycle;
//unsigned long StopFillRinseCycle;
//unsigned long RinseRunCycle;
//unsigned long StopRinseCycle;
//unsigned long SpinDrain;
//unsigned long SmallRinseSpinCycle;
//unsigned long BigSpinCycle;
//unsigned long StopBigSpinCycle;
//unsigned long StopSpinDrainCycle;
//unsigned long StopBuzzerCycle;

//unsigned long CycleResetTime2;     // = EachCycleTime + EachCycleTime;
//unsigned long CycleResetTime3;    //// = EachCycleTime + EachCycleTime + EachCycleTime;
//unsigned long CycleResetTime4;    //// = EachCycleTime + EachCycleTime + EachCycleTime;


//CycleResetTime1 = EachCycleTime;
//CycleResetTime2 = EachCycleTime * 2;
//CycleResetTime3 = EachCycleTime * 3;

int CycleState;
int CycleTimerRunning;

int CycleStage1;
int CycleStage2;
int CycleStage3;
int CycleStage4;

int CycleTimeStage1;
int CycleTimeStage2;
int CycleTimeStage3;
int CycleTimeStage4;

int FillingWashCycle;
int StopFillingCycle;
int WashRunCycle;
int StopWashCycle;
int WashDrainCycle;
int SmallWashSpinCycle;
int StopSmallSpin;
int StopDrainCycle;
int FillRinseCycle;
int StopFillRinseCycle;
int RinseRunCycle;
int StopRinseCycle;
int SpinDrain;
int SmallRinseSpinCycle;
int BigSpinCycle;
int StopBigSpinCycle;
int StopSpinDrainCycle;

int WashFillRunning;
int RinseFillRunning;
int WashDrainRunning;
int RinseDrainRunning;
int WashingRunning;
int RinsingRunning;
int SpinningRunning;
int BigSpinRunning;

int TotalCycleTime = 180000;


//CycleResetTime1 = 60000;
//CycleResetTime2 = 120000;
//CycleResetTime3 = 180000;

//CycleResetTime1 = EachCycleTime;
//CycleResetTime2 = EachCycleTime * 2;
//CycleResetTime3 = EachCycleTime * 3;
//
//
//EachCycleTime = TotalCycleTime / NumberOfCycles;


//***********************************************
//***********************************************
//            FULL QUIK CYCLE TIMER 1


unsigned long PreviousQuikCycleSetTime;     // = 160;
unsigned long QuikCycleSetTime;     // = 160;
unsigned long QuikCycleProgressSetTime = QuikCycleSetTime * 1000;

int NumberOfQuikCycles = 3;

float EachQuikCycleTime;   // = QuikCycleProgressSetTime;  // = TotalQuikCycleTime / NumberOfQuikCycles;

unsigned long QuikCycleSeconds;
unsigned long QuikCycleMinutes;
unsigned long QuikCycleHours;

unsigned long QuikCycleProgressSeconds;
unsigned long QuikCycleProgressMinutes;
unsigned long QuikCycleProgressHours;

unsigned long QuikWashCycleTime = QuikCycleProgressSetTime;
unsigned long QuikRinseResetTime = QuikCycleProgressSetTime;
unsigned long QuikSpinResetTime = QuikCycleProgressSetTime;

unsigned long QuikCycleTime = 0;
unsigned long QuikCycleStartTime;
unsigned long QuikCycleProgress;
unsigned long  QuikCycleResetTime1;    // = QuikCycleProgressSetTime;
unsigned long  QuikCycleResetTime2;    // = QuikCycleProgressSetTime + QuikCycleProgressSetTime;
unsigned long  QuikCycleResetTime3;    // = QuikCycleProgressSetTime + QuikCycleProgressSetTime + QuikCycleProgressSetTime;
unsigned long  QuikCycleResetTime4;    // = QuikCycleProgressSetTime + QuikCycleProgressSetTime + QuikCycleProgressSetTime;

//QuikCycleResetTime1 = 60000;
//QuikCycleResetTime2 = 120000;
//QuikCycleResetTime3 = 180000;
//QuikTotalCycleTime = QuikTotalCycleTime / NumberOfQuikCycles;

//QuikCycleResetTime1 = EachQuikCycleTime;
//QuikCycleResetTime2 = EachQuikCycleTime * 2;
//QuikCycleResetTime3 = EachQuikCycleTime * 3;
//QuikTotalCycleTime = QuikTotalCycleTime / NumberOfQuikCycles;

int QuikCycleState;
int QuikCycleTimerRunning;

int QuikCycleStage1;
int QuikCycleStage2;
int QuikCycleStage3;
int QuikCycleStage4;

int QuikCycleTimeStage1;
int QuikCycleTimeStage2;
int QuikCycleTimeStage3;
int QuikCycleTimeStage4;

int QuikTotalCycleTime = QuikCycleResetTime3;

int QuikMathTotal;

int QuikTimer; //= QuikCycleProgress;

//***********************************************

//***********************************************
//           BRAKE RELEASE TIMER

unsigned long BrakeReleaseTime = 5000;
unsigned long BrakeReleaseStartTime;
unsigned long BrakeReleaseProgress;
unsigned long BrakeReleaseResetTime = 6000;

int BrakeReleaseState;
int BrakeReleaseTimerRunning;

//***********************************************

//***********************************************
//            WASH / RINSE PULSE TIMER

unsigned long WashPulseTime = 5000;   //5000  // 10000
unsigned long WashPulseStartTime;
unsigned long WashPulseProgress;
unsigned long WashPulseResetTime1 = 8000;    //8000    //15000
unsigned long WashPulseResetTime2 = 13000;   //13000    //25000
unsigned long WashPulseResetTime3 = 20000;   //20000    //31000
//unsigned long WashPulseResetTime4 = 35000;   //20000

int WashPulseState;
int WashPulseForState;
int WashPulseRevState;
int WashPulseStopState1;
int WashPulseStopState2;
int WashPulseTimerRunning;

//***********************************************

//***********************************************
//            SPIN PULSE TIMER

unsigned long SpinPulseTime = 4000;
unsigned long SpinPulseStartTime;
unsigned long SpinPulseProgress;
unsigned long SpinPulseResetTime = 5000;
unsigned long SpinPulseResetTime2 = 5500;

int SpinPulseState;
int SpinPulseResetTime3;
int SpinPulseTimerRunning;



//***********************************************
//***********************************************
//            SMALL SPIN TIMER

unsigned long SmallSpinStartingTime = 0;
unsigned long SmallSpinStartTime;
unsigned long SmallSpinProgress;
unsigned long SmallSpinResetTime = 59000;   //4000;  // 5 MINUTES = 300000
unsigned long SmallSpinResetTime1 = 60000;

int SmallSpinState;
int SmallSpinDrainState;
int SmallSpinResetTime3;
int SmallSpinTimerRunning;



//***********************************************
//***********************************************
//            BIG SPIN TIMER

unsigned long BigSpinStartingTime = 0;
unsigned long BigSpinStartTime;
unsigned long BigSpinProgress;
unsigned long BigSpinResetTime = CycleResetTime3;   //4000;
unsigned long BigSpinResetTime1 = BigSpinResetTime + 120000;

int BigSpinState;
int BigSpinDrainState;
int BigSpinResetTime3;
int BigSpinTimerRunning;



//***********************************************
//***********************************************
//            QUIK WASH / RINSE PULSE TIMER

unsigned long QuikWashPulseTime = 5000;
unsigned long QuikWashPulseStartTime;
unsigned long QuikWashPulseProgress;
unsigned long QuikWashPulseResetTime1 = 8000;
unsigned long QuikWashPulseResetTime2 = 13000;
unsigned long QuikWashPulseResetTime3 = 16000;

int QuikWashPulseState;
int QuikWashPulseForState;
int QuikWashPulseRevState;
int QuikWashPulseStopState;
int QuikWashPulseTimerRunning;

volatile bool QuikWashingOn = false;
volatile bool QuikWashingFilling = false;
volatile bool QuikWashingLevelOk = false;
volatile bool QuikWashingLevelNotOk = false;
volatile bool QuikWashingDraining = false;

volatile bool QuikRinsingOn = false;
volatile bool QuikRinsingFilling = false;
volatile bool QuikRinsingLevelOk = false;
volatile bool QuikRinsingLevelNotOk = false;
volatile bool QuikRinsingDraining = false;

//***********************************************
//***********************************************
//           QUIK SPIN PULSE TIMER

unsigned long QuikSpinPulseTime = 2000;
unsigned long QuikSpinPulseStartTime;
unsigned long QuikSpinPulseProgress;
unsigned long QuikSpinPulseResetTime = 4000;
unsigned long QuikSpinPulseResetTime2 = 6000;

int QuikSpinPulseState;
int QuikSpinPulseResetTime3;
int QuikSpinPulseTimerRunning;

//***********************************************
//***********************************************
//            DELAY TIMER

float DelaySetTime;  // = 20000;
//unsigned long DelaySetTime;  // = 20000;
unsigned long DelayTime;  // = 20000;
unsigned long DelayStartTime;
unsigned long DelayProgress;
unsigned long DelayResetTime = 21000;

int DelayState;
int DelayTimerRunning;
int DelayDispTimeSeconds;
int DelayDispTimeMinutes;
int DelayDispTimeHours;

String DisplayDelayTime;
int DelayTimeSeconds;
int DelayTimeMinutes;
int DelayTimeHours;

int DelaySetTimeSeconds;
int DelaySetTimeMinutes;
int DelaySetTimeHours;

//***********************************************
//***********************************************
//           DRAIN PUMP TIMER

unsigned long DrainPumpTime = 20000;
unsigned long DrainPumpStartTime;
unsigned long DrainPumpProgress;
unsigned long DrainPumpResetTime = 21000;

int DrainPumpState;
int DrainPumpTimerRunning;

//***********************************************
//***********************************************
//            BUZZER PULSE TIMER

unsigned long BuzzerPulseTime = 1000;
unsigned long BuzzerPulseStartingTime = 0;
unsigned long BuzzerPulseStartTime;
unsigned long BuzzerPulseProgress;
unsigned long BuzzerPulseResetTime = 500;
unsigned long BuzzerPulseResetTime1 = 2000;

int BuzzerPulseState;
int BuzzerPulseResetTime3;
int BuzzerPulseTimerRunning;



//***********************************************
//***********************************************
//            BUZZER TIMER

unsigned long BuzzerTime = 10000;
unsigned long BuzzerStartTime;
unsigned long BuzzerProgress;
unsigned long BuzzerResetTime = 10500;
unsigned long BuzzerResetTime2 = 11000;

int BuzzerState;
int BuzzerResetTime3;
int BuzzerTimerRunning;



//***********************************************
//***********************************************
//           QUIK BUZZER PULSE TIMER

//unsigned long QuikBuzzerPulseTime = 100;
unsigned long QuikBuzzerPulseStartingTime = 0;
unsigned long QuikBuzzerPulseStartTime;
unsigned long QuikBuzzerPulseProgress;
unsigned long QuikBuzzerPulseResetTime = 500;
unsigned long QuikBuzzerPulseResetTime1 = 2000;

int QuikBuzzerPulseState;
int QuikBuzzerPulseResetTime3;
int QuikBuzzerPulseTimerRunning;



//***********************************************
//***********************************************
//            QUIK BUZZER TIMER

unsigned long QuikBuzzerTime = 10000;
unsigned long QuikBuzzerStartTime;
unsigned long QuikBuzzerProgress;
unsigned long QuikBuzzerResetTime = 10500;
unsigned long QuikBuzzerResetTime2 = 11000;

int QuikBuzzerState;
int QuikBuzzerResetTime3;
int QuikBuzzerTimerRunning;



//***********************************************
//***********************************************
//        PIN LOCATION AND FUNCTIONS

#define PowerOnPin A0

#define StartPausePin A1
int StartPauseCNT;

#define StopPin A2

//#define DirForPin A3   // For Testing
//#define DirRevPin A4   // For Testing

#define DoorSwPin A15
//#define VolumeHighPin A4
//#define VolumeMedPin A5

#define MainMotorOnOff A3
int MainMotorOnOffState = LOW;

int Volume;

//
#define MotorTempPin A5
int MotorTemp;
float Voltage;
float Temperature;

#define WaterVolumePin A4   //Sensor Value Pin

int SelectedWaterLevel;
int WaterLevel;
int WaterLevelOK;
int WaterLevelNotOK;
int WaterLevelProblem;
int WaterLevelActual;
int WaterLevelActual2;
int WaterLevelPrevious;
volatile bool WaterLevelGood = false;


#define WaterSupplyPin A6   //Push Button Select Pin
int WaterSupplyState;

#define WaterLevelPin A7
int WaterLevelState;

#define QuikWashPin A8
#define QuikRinsePin A9
#define QuikSpinPin A10

#define SoakPin A11

#define SuperWashPin A12

#define CoursePin A13

#define DelayPin A14

#define ForRevDRVRelayPin 12

#define DriveSpeedPin 2

#define ForRelayPin 3
#define RevRelayPin 4

#define SP1RelayPin 5
#define SP2RelayPin 6

#define HotSolRelayPin 7

#define ColdSolRelayPin 8
#define DetergentSolRelayPin 9

#define BrakeRelayPin 10
volatile bool BrakingOn;

#define DrainPumpRelayPin 11

#define StopRedLedPin 22
#define RunGrnLedPin 23
#define PowerBluLedPin 24

#define HotRedLedPin 25
#define ColdBluLedPin 26

#define MaximumLedPin 27
#define HighLedPin 28
#define MedHighLedPin 29
#define MediumLedPin 30
#define  MedMedLedPin 31
#define MedLowLedPin 32
#define LowLedPin 33
#define VeryLowLedPin 34
#define  ExtraLowLedPin 35
#define UltraLowLedPin 36

#define QuikWashLedPin 38
#define QuikRinseLedPin 39
#define QuikSpinLedPin 40

#define DigitalLedPin 41
#define SoakLedPin 42
#define SpeedyLedPin 43
#define WoolLedPin 44
#define ECOLedPin 45
#define HeavyBlanketLedPin 46

#define buzzerPin 13
#define TonebuzzerPin 16

int DriveSpeedNormal = 255;
int DriveSpeedSpinning = 255;

int PowerOnPinState;
int StartPausePinState;
int StopPinState;

int DirForPinState;   // For Testing
int DirRevPinState;   // For Testing

int DoorSwPinState;
int VolumeHighPinState;
int VolumeMedPinState;

int WaterSupplyPinState;
int WaterSupplylastButtonState;
int WaterSupplybuttonPushCounter = 0;

int WaterLevelPinState;
int WaterLevellastButtonState;
int WaterLevelbuttonPushCounter;

int WashPinState;
int WashRunning;

int RinsePinState;
int RinseRunning;

int SpinPinState;
int SpinRunning;

int SoakPinState;
int SoakRunning;

int SuperWashPinState;
int SuperWashRunning;

int CoursePinState;
int CoursePinRunning;
int CourselastButtonState;
int CoursebuttonPushCounter = 0;
int CourseCNT;

int DelayPinState;
int DelayActive;
int DelayPinRunning;
int DelaylastButtonState;
int DelaybuttonPushCounter;
int DelayCNT;
int DelayStage1;
int DelayStage2;
int DelayStage3;
int DelayStage4;
int DelayStage5;
int DelayStage6;
int DelayStage7;
int DelayStage8;
int DelayStage9;
int DelayStage10;
int DelayStage11;
int DelayStage12;


int DrainPumpRunning;
int EmptyDrum;
int StartState;
int StoppingState;

int QuikStartState;
int QuikStoppingState;

int WaterSuppySelect;
int WaterLevelSelect;
int QuikCycleSelectWash;
int QuikCycleSelectRinse;
int QuikCycleSelectSpin;
int SuperCleanSelect;
int CourseSelect;
int DelaySelect;

int SpinningOn;
int BigSpinningOn;
int AllCyclesRun;

int WashFillOn;
int RinseOn;
int RinseFillOn;
int RinseDrainOn;

int QuikWashBuzzerPinState;
int QuikWashPinState;
int QuikWashRunning;

int QuikRinseBuzzerPinState;
int QuikRinsePinState;
int QuikRinseRunning;

int QuikSpinBuzzerPinState;
int QuikSpinPinState;
int QuikSpinRunning;

int QuikSelectRunningState;
int NormalSelectRunningState;


//***********************************************
//          CYCLE TIMER EQUATIONS

void MathCycleTimes() {



  //CycleResetTime1 = EachCycleTime;
  //CycleResetTime2 = EachCycleTime * 2;
  //CycleResetTime3 = EachCycleTime * 3;
  //QuikCycleResetTime1 = EachQuikCycleTime;
  //QuikCycleResetTime2 = EachQuikCycleTime * 2;
  //QuikCycleResetTime3 = EachQuikCycleTime * 3;
  //
  //QuikTotalCycleTime = QuikTotalCycleTime / NumberOfQuikCycles;
  //EachCycleTime = TotalCycleTime / NumberOfCycles;

}



////***********************************************
////           CYCLE TIMER
//
//
void CycleTimer() {
  //  MathCycleTimes();
  //  CycleTimerRunning = HIGH;
  //
  //  CycleProgress = millis() - CycleStartTime;     // Servo Head Progress
  //
  ////  if (CycleProgress >= CycleTime) {
  ////    CycleState = HIGH;
  ////    CycleStage1 = HIGH;
  ////    CycleStage2 = LOW;
  ////
  ////  }
  ////
  ////  if (CycleProgress >= CycleResetTime1) {
  ////    CycleStage1 = LOW;
  ////    CycleStage2 = HIGH;
  ////
  ////  }
  ////
  ////  if (CycleProgress >= CycleResetTime2) {
  ////    CycleStage2 = LOW;
  ////    CycleStage3 = HIGH;
  ////
  ////  }
  ////
  ////  if (CycleProgress <= CycleResetTime3) {
  ////
  ////    BuzzerPulseStartTime = millis();
  ////    BuzzerStartTime = millis();
  ////  }
  ////
  ////  if (CycleProgress >= CycleResetTime3) {
  ////    CycleStage3 = LOW;
  ////    CycleStage4 = HIGH;
  ////    //    CycleState = LOW;
  ////    BuzzerTimer();
  ////    Buzzer();
  ////  }
  ////
  ////  if (CycleProgress >= CycleResetTime4) {
  ////    CycleStage4 = LOW;
  ////    //    CycleState = LOW;
  ////    //    BuzzerTimer();
  ////    //    Buzzer();
  ////  }
  //
  //
  //  if (CycleProgress >= CycleTime) {       // 0
  //    CycleState = HIGH;
  //    CycleStage1 = HIGH;
  //    CycleStage2 = LOW;
  //
  //  }
  //
  //  if (CycleProgress >= CycleResetTime1) {   // Stop Wash, Begin Rinse
  //    CycleStage1 = LOW;
  //    CycleStage2 = HIGH;
  //
  //  }
  //
  //  if (CycleProgress >= CycleResetTime2) {   // Stop Rinse, Begin Spin
  //    CycleStage2 = LOW;
  //    CycleStage3 = HIGH;
  //
  //  }
  //
  //  if (CycleProgress <= CycleResetTime3) {   // Stop Spin
  //
  //    BuzzerPulseStartTime = millis();
  //    BuzzerStartTime = millis();
  //  }
  //
  //  if (CycleProgress >= CycleResetTime3) {   // Begin Buzzer
  //    CycleStage3 = LOW;
  //    CycleStage4 = HIGH;
  //    //    CycleState = LOW;
  //    BuzzerTimer();
  //    Buzzer();
  //  }
  //
  //  if (CycleProgress >= CycleResetTime4) {  // Stop Buzzer
  //    CycleStage4 = LOW;
  //    //    CycleState = LOW;
  //    //    BuzzerTimer();
  //    //    Buzzer();
  //  }
  //
  ////      CycleStartTime = millis();
  //
}

//**********************************************************************************
//                      NEW CYCLES

//*************************************************

void BrakeReleaseTimer() {

  CheckInputStates();

  BrakeReleaseProgress = millis() - BrakeReleaseStartTime;     // Servo Head Progress

  if (BrakeReleaseProgress >= BrakeReleaseTime) {       // 0

    BrakeReleaseState = LOW;
//    digitalWrite(BrakeRelayPin, HIGH);
//BrakingOn = false;
//BrakeOff();
  }

  if (BrakeReleaseProgress >= BrakeReleaseResetTime) {   // Stop Wash, Begin Rinse

    BrakeReleaseState = HIGH;
    
//    digitalWrite(BrakeRelayPin, HIGH);
//BrakingOn = false;
//BrakeOff();

  }

}

//*************************************************

//*************************************************

void WashCycleTimer() {
  //  CheckInputStates();

  CheckInputStates();
  WashCycleStopTime = CycleResetTime1;
  RunningCycleTime =  WashCycleProgress;
  CycleProgress = WashCycleProgress;

  WashCycleProgress = millis() - WashCycleStartTime;     // Servo Head Progress

  if (WashCycleProgress >= WashCycleTime) {       // 0
    FillingWashCycle = LOW;
    CycleState = HIGH;   //???
    WashRunCycle = HIGH;
    WashFillOn = LOW;
    WashingRunning = HIGH;

  }

  if (WashCycleProgress >= WashCycleStopTime) {   // Stop Wash, Begin Rinse
    WashDrainCycle = HIGH;
    WashDrain();
    WashRunCycle = LOW;
  }

}

//*************************************************

void RinseCycleTimer() {
  //  CheckInputStates();
  //FillRinseCycle = LOW;


  CheckInputStates();
  RinseCycleStopTime = CycleResetTime2;
  RunningCycleTime =  RinseCycleProgress;
  CycleProgress = WashCycleStopTime + RinseCycleProgress;

  RinseCycleProgress = millis() - RinseCycleStartTime;     // Servo Head Progress

  if (RinseCycleProgress >= RinseCycleTime) {   // Stop Wash, Begin Rinse
    RinseRunCycle = HIGH;
    RinsingRunning = HIGH;
  }

  if (RinseCycleProgress >= RinseCycleStopTime) {   // Stop Rinse, Begin Spin
    RinseRunCycle = LOW;
    SpinDrain = HIGH;
    BigSpinDrainState = HIGH;
  CycleProgress = WashCycleStopTime + RinseCycleStopTime + SpinCycleTime;
  RinseDrain();
    RinseDrainWatch();
  }

}

//*************************************************

void SpinCycleTimer() {
  CheckInputStates();
  SpinCycleStopTime = CycleResetTime3;
  RunningCycleTime =  SpinCycleProgress;
  CycleProgress = WashCycleStopTime + RinseCycleStopTime + SpinCycleProgress;
  //  CycleProgress = RinseCycleStopTime + SpinCycleProgress;
  RinsingRunning = LOW;
    
    SmallSpinTimer();

    
  SpinCycleProgress = millis() - SpinCycleStartTime;     // Servo Head Progress

  if (SpinCycleProgress >= SpinCycleTime) {   // Stop Rinse, Begin Spin
SmallSpinProgress = 0;    
    SmallSpinTimer();
    BigSpinDrainState = HIGH;
    CycleStage2 = LOW;
    BigSpinCycle = HIGH;
  }

  if (SpinCycleProgress <= SpinCycleStopTime) {   // Stop Spin

    //    BuzzerPulseStartTime = millis();
    //    BuzzerStartTime = millis();
  }

  SpinCycleBuzzerStopTime = SpinCycleStopTime + 10000;

  if (SpinCycleProgress >= SpinCycleBuzzerStopTime) {   // Begin Buzzer
//    RinseDrainRunning = LOW;
    BigSpinCycle = LOW;
    BigSpinDrainState = LOW;
    //    BuzzerTimer();
    //    Buzzer();
    CycleState = LOW;
  }
}



//***********************************************
//           SMALL SPIN TIMER

void SmallSpinTimer() {
 SpinPulseTimer();
  
  CheckInputStates();
  SpinCycleStopTime = CycleResetTime3;
  RunningCycleTime =  SmallSpinProgress;
  SmallSpinTimerRunning = HIGH;

  CycleProgress = WashCycleStopTime + RinseCycleStopTime + SmallSpinProgress;

  SmallSpinProgress = millis() - SmallSpinStartTime;     // Servo Head Progress

  if (SmallSpinProgress >= SmallSpinStartingTime) {
    SmallSpinState = HIGH;
    //    BigSpinStartTime = millis();
    digitalWrite(DrainPumpRelayPin, HIGH);
  }

  if (SmallSpinProgress >= SmallSpinResetTime) {
    //    BigSpinStartTime = millis();
    SmallSpinState = LOW;
    digitalWrite(DrainPumpRelayPin, HIGH);

  }

  if (SmallSpinProgress >= SmallSpinResetTime1) {
    //    SmallSpinStartTime = millis();
    //    FillingSoftner();
    BigSpinCycle = HIGH;
    BigSpinning();
    BigSpinTimer();
  }
}

//***********************************************
//***********************************************
//           BIG SPIN TIMER

void BigSpinTimer() {

  CheckInputStates();
  SpinCycleStopTime = CycleResetTime3;
  RunningCycleTime =  BigSpinProgress;

  BigSpinning();

  //  SmallSpinResetTime1 = SpinCycleStopTime + 120000;

  BigSpinTimerRunning = HIGH;
  //  CycleProgress = WashCycleStopTime + RinseCycleStopTime + SmallSpinResetTime + BigSpinProgress;
  CycleProgress = WashCycleStopTime + RinseCycleStopTime + BigSpinProgress;


  BigSpinProgress = millis() - BigSpinStartTime;     // Servo Head Progress

  if (BigSpinProgress >= BigSpinStartingTime) {
    BigSpinState = HIGH;
    BigSpinningOn = HIGH;
//    BuzzerPulseStartTime = millis();
//    BuzzerStartTime = millis();
    digitalWrite(DrainPumpRelayPin, HIGH);
  }

  if ((BigSpinProgress >= BigSpinStartingTime) &&  (BigSpinProgress <= SpinCycleStopTime)){
    BuzzerPulseStartTime = millis();
    BuzzerStartTime = millis();
    
  }


  if (BigSpinProgress >= SpinCycleStopTime) {
    BigSpinState = LOW;
    BigSpinningOn = LOW;
    BuzzerPulseTimer();
    BuzzerTimer();
    Buzzer();
    digitalWrite(DrainPumpRelayPin, HIGH);
//    digitalWrite(BrakeRelayPin, HIGH);
   //    CycleState = LOW;

  }

  BigSpinResetTime1 = SpinCycleStopTime + 10000;

  if (BigSpinProgress >= BigSpinResetTime1) {
    //    BigSpinStartTime = millis();
//    digitalWrite(DrainPumpRelayPin, HIGH);
//    digitalWrite(BrakeRelayPin, HIGH);
    BigSpinningOn = LOW;
    AllCyclesRun = LOW;
  }
}


//***********************************************

//***********************************************
//           BUZZER PULSE TIMER

void BuzzerPulseTimer() {

  BuzzerPulseTimerRunning = HIGH;

  BuzzerPulseProgress = millis() - BuzzerPulseStartTime;     // Servo Head Progress

//  if ((BuzzerPulseProgress >= BuzzerPulseStartingTime) && (BuzzerPulseProgress <= BuzzerPulseTime)) {
  if (BuzzerPulseProgress >= 0){
    BuzzerPulseState = HIGH;
  }

//  if ((BuzzerPulseProgress >= BuzzerPulseResetTime) && (BuzzerPulseProgress <= BuzzerPulseResetTime1)) {
  if (BuzzerPulseProgress >= BuzzerPulseResetTime){
    BuzzerPulseState = LOW;
  }

  if (BuzzerPulseProgress >= BuzzerPulseResetTime1) {
    BuzzerPulseStartTime = millis();
  }
}

//***********************************************
//***********************************************
//           BUZZER TIMER

void BuzzerTimer() {

  BuzzerTimerRunning = HIGH;

  BuzzerProgress = millis() - BuzzerStartTime;     // Servo Head Progress

  if (BuzzerProgress <= BuzzerTime) {
    BuzzerState = HIGH;
  }

  if (BuzzerProgress >= BuzzerTime) {
    BuzzerState = LOW;
  }

  if (BuzzerProgress >= BuzzerResetTime) {
    //    BuzzerStartTime = millis();
    CycleState = LOW;
  }
}


//***********************************************
//***********************************************

void Buzzer() {
//BigSpinTimer();
  if (BuzzerState == HIGH) {
    BuzzerPulse();
  }
  else if (BuzzerState == LOW) {
    digitalWrite(TonebuzzerPin, LOW);
  }

}

//***********************************************
void BuzzerPulse() {
  BuzzerPulseTimer();

  if (BuzzerPulseState == HIGH) {
    digitalWrite(TonebuzzerPin, HIGH);
  }
  else if (BuzzerPulseState == LOW) {
    digitalWrite(TonebuzzerPin, LOW);
  }

}


//***********************************************

void QuikBuzzerPulse() {
  QuikBuzzerPulseTimer();

  if (QuikBuzzerPulseState == HIGH) {
    digitalWrite(TonebuzzerPin, HIGH);
  }
  else if (QuikBuzzerPulseState == LOW) {
    digitalWrite(TonebuzzerPin, LOW);
  }

}

//***********************************************

void QuikBuzzer() {
  QuikBuzzerTimer();

  if (QuikBuzzerState == HIGH) {
    QuikBuzzerPulse();
  }
  else if (QuikBuzzerState == LOW) {
    digitalWrite(TonebuzzerPin, LOW);
  }
  
QuikWashingOn = false;
QuikRinsingOn = false;

}

//***********************************************
//***********************************************
//          QUIK BUZZER PULSE TIMER

void QuikBuzzerPulseTimer() {

  QuikBuzzerPulseTimerRunning = HIGH;

  QuikBuzzerPulseProgress = millis() - QuikBuzzerPulseStartTime;     // Servo Head Progress

  if ((QuikBuzzerPulseProgress >= QuikBuzzerPulseStartingTime) && (QuikBuzzerPulseProgress <= QuikBuzzerPulseResetTime)) {
    QuikBuzzerPulseState = HIGH;
  }

  if ((QuikBuzzerPulseProgress >= QuikBuzzerPulseResetTime) && (QuikBuzzerPulseProgress <= QuikBuzzerPulseResetTime1)) {
    QuikBuzzerPulseState = LOW;
  }

  if (QuikBuzzerPulseProgress >= QuikBuzzerPulseResetTime1) {
    QuikBuzzerPulseStartTime = millis();
  }

}

//***********************************************
//***********************************************
//          QUIK BUZZER TIMER

void QuikBuzzerTimer() {

  QuikBuzzerTimerRunning = HIGH;

  QuikBuzzerProgress = millis() - QuikBuzzerStartTime;     // Servo Head Progress

  if (QuikBuzzerProgress <= QuikBuzzerTime) {
    QuikBuzzerState = HIGH;
  }

  if (QuikBuzzerProgress >= QuikBuzzerTime) {
    QuikBuzzerState = LOW;
    QuikCycleState = LOW;
  }

  if (QuikBuzzerProgress >= QuikBuzzerResetTime) {
    //    QuikBuzzerStartTime = millis();
    //    QuikCycleState = LOW;
  }
}

//***********************************************
//***********************************************
//           SPIN PULSE TIMER

void SpinPulseTimer() {

  SpinPulseTimerRunning = HIGH;

  SpinPulseProgress = millis() - SpinPulseStartTime;     // Servo Head Progress

  if (SpinPulseProgress <= SpinPulseTime) {
    SpinPulseState = HIGH;
  }

  if (SpinPulseProgress >= SpinPulseTime) {
    SpinPulseState = LOW;
  }

  if (SpinPulseProgress >= SpinPulseResetTime) {
    SpinPulseStartTime = millis();
  }
}

//***********************************************
//***********************************************
void Washing() {
  CheckInputStates();
//WaterLevel = WaterLevel - 20;
  WashPulseTimer();

  if (QuikSelectRunningState == LOW) {

    if (WashPulseForState == HIGH) {

      MotorForDir();

    }

    if (WashPulseStopState1 == HIGH) {

      MotorStop1();

    }

    if (WashPulseRevState == HIGH) {

      MotorRevDir();

    }

    if (WashPulseStopState2 == HIGH) {

      MotorStop2();

    }
    
    //            RinseStartTime = millis();
    //            RinsePulseStartTime = millis();
    lcd.setCursor(0, 0);
    lcd.print("    WASHING     ");

  }

}

//***********************************************

void Rinsing() {
  CheckInputStates();

  WashPulseTimer();

  //Washing();
  if (QuikSelectRunningState == LOW) {

    if (WashPulseForState == HIGH) {

      MotorForDir();

    }

    if (WashPulseStopState1 == HIGH) {

      MotorStop1();

    }

    if (WashPulseRevState == HIGH) {

      MotorRevDir();

    }

    if (WashPulseStopState2 == HIGH) {

      MotorStop2();

    }
        
    //      SpinStartTime = millis();
    //      SpinPulseStartTime = millis();
    lcd.setCursor(0, 0);
    lcd.print("    RINSING     ");
  }

  SpinPulseStartTime = millis();
}

//***********************************************
void Spinning() {
  CheckInputStates();
  SmallSpinTimer();
  SpinPulseTimer();
  SpinningRunning = HIGH;


  if (QuikSelectRunningState == LOW) {

    if (SmallSpinState == HIGH) {
      if (SpinPulseState == HIGH) {

        MotorSpinPulseForDir();

//          MotorSpinForDir();
      }
//else{
    if (SpinPulseState == LOW) {
analogWrite(DriveSpeedPin ,0);

//        MotorStop();
        MainMotorOff();
      }

      lcd.setCursor(0, 0);
      lcd.print("    SPINNING     ");

    }
 
  }
}

//***********************************************
void BigSpinning() {
  CheckInputStates();
  BigSpinRunning = HIGH;
  //  SpinCycleTimer();
  //  BigSpinTimer();

  //    BigSpinTimer();
  //    BigSpinStartTime = millis();
  //     BigSpinState = HIGH
  if (QuikSelectRunningState == LOW) {

    if (BigSpinState == HIGH) {

          MotorSpinForDir();

    }

    if (BigSpinState == LOW) {

analogWrite(DriveSpeedPin ,0);
      MotorStop();
        MainMotorOff();

    }

    lcd.setCursor(0, 0);
    lcd.print("  BIG SPINNING   ");

  }

  //      Serial.println("");
  //      Serial.print("SpinProgress :");
  //      Serial.print(SpinProgress);
  //      Serial.println("");
  //
  //          Serial.println("");
  //          Serial.print("SpinPulseProgress :");
  //          Serial.print(SpinPulseProgress);
  //          Serial.println("");

}


//***********************************************

//***********************************************
//***********************************************
//           QUIK CYCLE TIMER


void QuikCycleTimer() {
  MathCycleTimes();
  QuikCycleTimerRunning = HIGH;

  QuikCycleProgress = millis() - QuikCycleStartTime;     // Servo Head Progress

  if (QuikCycleProgress >= QuikCycleTime) {
    QuikCycleState = HIGH;
    QuikCycleStage1 = HIGH;
    //StopPinState = LOW;
    StopStartTime = millis();

  }

  if (QuikCycleProgress <= QuikCycleResetTime1) {
    QuikBuzzerPulseStartTime = millis();
    QuikBuzzerStartTime = millis();
  }


  
  if (QuikCycleProgress >= QuikCycleResetTime1) {
    QuikCycleStage1 = LOW;
    QuikCycleStage2 = HIGH;

if (QuikWashingOn == true){

WashDrain();

  }

if (QuikRinsingOn == true){

RinseDrain();

}

// QuikRinsing(); 

    //    QuikCycleState = LOW;

//    QuikBuzzerPulseTimer();
//    QuikBuzzerTimer();
//    QuikBuzzer();

  }

  if (QuikCycleProgress >= QuikCycleResetTime2) {
    //    QuikCycleStage1 = LOW;
    QuikCycleStage2 = LOW;
    QuikCycleStage3 = HIGH;
    //    QuikBuzzerPulseTimer();
    //    QuikBuzzerTimer();
    //    QuikBuzzer();
  }

  if (QuikCycleProgress >= QuikCycleResetTime3) {
    ////    QuikCycleProgress = 0;
    //     QuikCycleState = LOW;
    QuikCycleStage3 = LOW;
    //        QuikCycleStartTime = millis();

  }
  //      QuikCycleStartTime = millis();
}


//***********************************************
//***********************************************
//           WASH PULSE TIMER

void WashPulseTimer() {

  WashPulseTimerRunning = HIGH;

  WashPulseProgress = millis() - WashPulseStartTime;     // Servo Head Progress
BrakeOff();


  if (WashPulseProgress <= WashPulseTime) {
    WashPulseForState = HIGH;
    WashPulseStopState2 = LOW;
  }

  if (WashPulseProgress >= WashPulseTime) {
    WashPulseStopState1 = HIGH;
    WashPulseRevState = LOW;
    WashPulseForState = LOW;
  }

  if (WashPulseProgress >= WashPulseTime) {
//BrakeOn();
BrakingOn = true;
  }

  if (WashPulseProgress >= WashPulseTime + 1000) {

//BrakeOff();
BrakingOn = false;

  }

  if (WashPulseProgress >= WashPulseResetTime1) {
    WashPulseRevState = HIGH;
    WashPulseStopState1 = LOW;
  }

  if (WashPulseProgress >= WashPulseResetTime2) {
    WashPulseStopState2 = HIGH;
    WashPulseRevState = LOW;
    WashPulseForState = LOW;

  }
  
  if (WashPulseProgress >= WashPulseResetTime2) {
    
//BrakeOn();
BrakingOn = true;

  }  

  if (WashPulseProgress >= WashPulseResetTime2 + 1000) {
//BrakeOff();
BrakingOn = false;

  }
  
  if (WashPulseProgress >= WashPulseResetTime3) {
    WashPulseStartTime = millis();
  }
}

//***********************************************

//***********************************************
//           QUIK WASH PULSE TIMER

void QuikWashPulseTimer() {

  QuikWashPulseTimerRunning = HIGH;

  QuikWashPulseProgress = millis() - QuikWashPulseStartTime;     // Servo Head Progress

  if (QuikWashPulseProgress <= QuikWashPulseTime) {
    QuikWashPulseForState = HIGH;
    QuikWashPulseStopState = LOW;
  }

  if (QuikWashPulseProgress >= QuikWashPulseTime) {
    QuikWashPulseStopState = HIGH;
    QuikWashPulseRevState = LOW;
    QuikWashPulseForState = LOW;
  }

  if (QuikWashPulseProgress >= QuikWashPulseTime) {
//BrakeOn();
BrakingOn = true;
  }

  if (QuikWashPulseProgress >= QuikWashPulseTime + 1000) {

//BrakeOff();
BrakingOn = false;

  }

  if (QuikWashPulseProgress >= QuikWashPulseResetTime1) {
    QuikWashPulseRevState = HIGH;
    QuikWashPulseStopState = LOW;
  }

  if (QuikWashPulseProgress >= QuikWashPulseResetTime2) {
    QuikWashPulseStopState = HIGH;
    QuikWashPulseRevState = LOW;
    QuikWashPulseForState = LOW;
  }
  
  if (QuikWashPulseProgress >= QuikWashPulseResetTime2) {
    
//BrakeOn();
BrakingOn = true;

  }  

  if (QuikWashPulseProgress >= QuikWashPulseResetTime2 + 1000) {
//BrakeOff();
BrakingOn = false;

  }
  
  if (QuikWashPulseProgress >= QuikWashPulseResetTime3) {
    QuikWashPulseStartTime = millis();
  }
}

//***********************************************
//***********************************************
//           QUIK SPIN PULSE TIMER

void QuikSpinPulseTimer() {

  QuikSpinPulseTimerRunning = HIGH;

  QuikSpinPulseProgress = millis() - QuikSpinPulseStartTime;     // Servo Head Progress

  if (QuikSpinPulseProgress <= QuikSpinPulseTime) {
    QuikSpinPulseState = HIGH;
  }

  if (QuikSpinPulseProgress >= QuikSpinPulseTime) {
    QuikSpinPulseState = LOW;
  }

  if (QuikSpinPulseProgress >= QuikSpinPulseResetTime) {
    QuikSpinPulseStartTime = millis();
  }
}

//***********************************************
//***********************************************
//           SOAK TIMER


//void SoakTimer() {
//
//SoakTimerRunning = HIGH;
//
//  SoakProgress = millis() - SoakStartTime;     // Servo Head Progress
//
//  if (SoakProgress <= SoakTime) {
//    SoakState = HIGH;
//  }
//
//  if (SoakProgress >= SoakTime) {
//    SoakState = LOW;
//  }
//
////  if (SoakProgress >= SoakResetTime) {
////    SoakStartTime = millis();
////  }
//}
//
////***********************************************

////***********************************************
////           DELAYD START TIMER


void DelayStartTimer() {

  DelayTimerRunning = HIGH;

  DelayProgress = millis() - DelayStartTime;     // Servo Head Progress

  if (DelayProgress <= DelayTime) {
    DelayState = HIGH;
    CycleStartTime = millis();

  }

  if (DelayProgress >= DelayTime) {
    DelayState = LOW;
    DelayActive = LOW;
  }

  //  if (DelayProgress >= DelayResetTime) {
  //    DelayStartTime = millis();
  //  }
}

//***********************************************
////***********************************************
////           PUMP TIMER
//
//
//void DrainPumpTimer() {
//
//DrainPumpTimerRunning = HIGH;
//
//  DrainPumpProgress = millis() - DrainPumpStartTime;     // Servo Head Progress
//
//  if (DrainPumpProgress <= DrainPumpTime) {
//   DrainPumpState = HIGH;
//  }
//
//  if (DrainPumpProgress >= DrainPumpTime) {
//    DrainPumpState = LOW;
//  }
//
////  if (PumpProgress >= PumpResetTime) {
////    PumpStartTime = millis();
////  }
//}

//***********************************************
//***********************************************
//           SERIAL PRINT DELAY TIMER

void serialprintTimer() {

  SerialPrintProgress = millis() - SerialPrintStartTime;     // Servo Head Progress

  if (SerialPrintProgress <= SerialPrintTime) {
    SerialPrintState = HIGH;
  }

  if (SerialPrintProgress >= SerialPrintTime) {
    SerialPrintState = LOW;
  }

  if (SerialPrintProgress >= SerialPrintResetTime) {
    SerialPrintStartTime = millis();
  }
}

//***********************************************
//***********************************************
//           LCD PRINT DELAY TIMER

void LCDprintTimer() {

  LCDPrintProgress = millis() - LCDPrintStartTime;     // Servo Head Progress

  if (LCDPrintProgress <= LCDPrintTime) {
    LCDPrintState = HIGH;
  }

  if (LCDPrintProgress >= LCDPrintTime) {
    LCDPrintState = LOW;
  }

  if (LCDPrintProgress >= LCDPrintResetTime) {
    LCDPrintStartTime = millis();
  }
}

//***********************************************
//***********************************************
//           SUBTRACT TIMER

void SubtractTimer() {

  SubtractProgress = millis() - SubtractStartTime;     // Servo Head Progress

  if (SubtractProgress <= SubtractTime) {
    SubtractState = HIGH;
  }

  if (SubtractProgress >= SubtractTime) {
    SubtractState = LOW;
  }

  if (SubtractProgress >= SubtractResetTime) {
    SubtractStartTime = millis();
  }
}


//***********************************************
//***********************************************
//           STOP TIMER

void StopTimer() {

  StopProgress = millis() - StopStartTime;     // Servo Head Progress

  if (StopProgress <= StopTime) {
    StopState = HIGH;
  }

  if (StopProgress >= StopTime) {
    StopState = LOW;
  }

  if (StopProgress >= StopResetTime) {
    StopStartTime = millis();
  }
}


//***********************************************
//***********************************************
//          QUIK SUBTRACT TIMER

void QuikSubtractTimer() {

  QuikSubtractProgress = millis() - QuikSubtractStartTime;     // Servo Head Progress

  if (QuikSubtractProgress <= QuikSubtractTime) {
    QuikSubtractState = HIGH;
  }

  if (QuikSubtractProgress >= QuikSubtractTime) {
    QuikSubtractState = LOW;
  }

  if (QuikSubtractProgress >= QuikSubtractResetTime) {
    QuikSubtractStartTime = millis();
  }
}


//***********************************************

void SubtractCycleTimer() {


  if (QuikSelectRunningState == LOW) {

    if (SubtractState == HIGH) {
      TotalCycleTime = TotalCycleTime--;
    }
    LCDprintTimer();

    if (LCDPrintState == HIGH) {
      //      lcd.setCursor(3, 1);
      //      lcd.print(TotalCycleTime);


    }

  }

  ////QuikTotalCycleTime
  //QuikMathTotal = QuikCycleProgress;

  if (QuikSelectRunningState == HIGH) {

    //    if (QuikSubtractState == HIGH) {
    //      EachQuikCycleTime = EachQuikCycleTime--;
    //    }
    LCDprintTimer();

  }
}

//***********************************************

//***********************************************

void LCDprint() {

  LCDprintTimer();
  CheckInputStates();
  CycleTimer();



}
//***********************************************
//***********************************************
//              CHECK ALL INPUT PINS

void CheckInputStates() {

  PowerOnPinState = digitalRead(PowerOnPin);
  StartPausePinState = digitalRead(StartPausePin);
  StopPinState = digitalRead(StopPin);

  DoorSwPinState = digitalRead(DoorSwPin);
  //  VolumeHighPinState = digitalRead(VolumeHighPin);
  //  VolumeMedPinState = digitalRead(VolumeMedPin);

  WaterSupplyPinState = digitalRead(WaterSupplyPin);
  WaterLevelPinState = digitalRead(WaterLevelPin);
  QuikWashPinState = digitalRead(QuikWashPin);
  QuikRinsePinState = digitalRead(QuikRinsePin);
  QuikSpinPinState = digitalRead(QuikSpinPin);
  SoakPinState = digitalRead(SoakPin);
  SuperWashPinState = digitalRead(SuperWashPin);
  CoursePinState = digitalRead(CoursePin);
  DelayPinState = !digitalRead(DelayPin);
  QuikWashBuzzerPinState = digitalRead(QuikWashPin);
  QuikRinseBuzzerPinState = digitalRead(QuikRinsePin);
  QuikSpinBuzzerPinState = digitalRead(QuikSpinPin);
}

//***********************************************
//***********************************************

void PowerState() {

  CheckInputStates();

  if (PowerOnPinState == LOW) {
    digitalWrite(PowerBluLedPin, HIGH);
  }
  else if (PowerOnPinState == HIGH) {
    digitalWrite(PowerBluLedPin, LOW);
  }

}

//***********************************************
//***********************************************

void StartCycle() {
  CheckInputStates();
  

  // if (QuikSelectRunningState == LOW){
  //  CycleTimer();
  //Filling();
      WashFillOn = HIGH;
  CheckInputStates();
  //  LCDprint();
  SubtractTimer();
  SubtractCycleTimer();
  StartState = HIGH;
  AllCyclesRun = HIGH;
  FillingWashCycle = HIGH;
  StoppingState = LOW;
  digitalWrite(RunGrnLedPin, HIGH);
  digitalWrite(StopRedLedPin, LOW);
  QuikCycleStartTime = millis();
  //    QuikBuzzerPulseStartTime = millis();
  //    QuikBuzzerStartTime = millis();
  // }



}

//***********************************************

void StopCycle() {
  CheckInputStates();

//
BrakeReleaseState = LOW;
BrakeReleaseStartTime = millis();
//

  DelayStartTime = millis();
  DelayProgress = 0;

  //  if (StopState == HIGH) {

  if (QuikSelectRunningState == LOW) {
    //    WaterLevelbuttonPushCounter = 1;
    WashCycleStartTime = millis();
    //  RinseCycleStartTime = millis();
    //  SpinCycleStartTime = millis();

    CycleStartTime = millis();
    DelayStartTime = millis();
    DelayProgress = 0;
    //***
    digitalWrite(DetergentSolRelayPin, LOW);
    digitalWrite(ColdSolRelayPin, LOW);
    digitalWrite(HotSolRelayPin, LOW);
    digitalWrite(DrainPumpRelayPin, LOW);
    digitalWrite(BrakeRelayPin, LOW);

    WashCycleStartTime = millis();
    //    RinseCycleStartTime = millis();
    //    SpinCycleStartTime = millis();


    CycleProgress = 0;
    WashCycleProgress = 0;
    RinseCycleProgress = 0;
    SpinCycleProgress = 0;
    SmallSpinProgress = 0;
    BigSpinProgress = 0;


    WashDrainCycle = LOW;
    FillRinseCycle = LOW;
    SpinDrain = LOW;
    RinseFillOn = LOW;
    RinseDrainRunning = LOW;
    BigSpinDrainState = LOW;
    BigSpinCycle = LOW;

WashFillOn = LOW;
RinseFillOn = LOW;
    //***
    CheckInputStates();
    CycleState = LOW;

    StartState = LOW;
    StoppingState = HIGH;

    QuikBuzzerPulseTimer();
    QuikBuzzerTimer();
    QuikBuzzer();

    //  QuikMillisReset();

    QuikCycleStartTime = millis();

    //      CycleStartTime = millis();
    WashPulseStartTime = millis();
    SpinPulseStartTime = millis();

    digitalWrite(SP1RelayPin, LOW);
    digitalWrite(SP2RelayPin, LOW);
    digitalWrite(RevRelayPin, LOW);
    digitalWrite(ForRelayPin, LOW);

    digitalWrite(RunGrnLedPin, LOW);
    digitalWrite(StopRedLedPin, HIGH);

    if (DelayActive == LOW) {

      lcd.setCursor(0, 0);
      lcd.print("    STOPPED     ");
      //  lcd.setCursor(0, 1);
      //  lcd.print("Sel Cycle, Start");
    }
    if (QuikSelectRunningState == HIGH) {

      QuikCycleStartTime = millis();

      //    QuikBuzzerPulseTimer();
      //    QuikBuzzerTimer();
      //    QuikBuzzer();

    }
  }
  //  }
}

//***********************************************
//***********************************************

void QuikStartCycle() {


  // if (QuikSelectRunningState == HIGH){
  //  CycleTimer();
  QuikCycleSetTime = PreviousQuikCycleSetTime;



  //    QuikBuzzerPulseTimer();
  //    QuikBuzzerTimer();
  //    QuikBuzzer();

  //
  CheckInputStates();
  //  LCDprint();
  QuikSubtractTimer();
  SubtractCycleTimer();
  QuikStartState = HIGH;
  QuikStoppingState = LOW;
  digitalWrite(RunGrnLedPin, HIGH);
  digitalWrite(StopRedLedPin, LOW);
  QuikCycleStartTime = millis();
  // }
}

//***********************************************

void QuikStopCycle() {

  CheckInputStates();
  QuikCycleStartTime = millis();
  QuikCycleSetTime = PreviousQuikCycleSetTime;

  if (QuikSelectRunningState == HIGH) {

    QuikBuzzerPulseTimer();
    QuikBuzzerTimer();
    QuikBuzzer();

    QuikStartState = LOW;
    QuikStoppingState = HIGH;
    digitalWrite(RunGrnLedPin, LOW);
    digitalWrite(StopRedLedPin, HIGH);

    //  QuikMillisReset();

    //  QuikCycleStartTime = millis();

    digitalWrite(SP1RelayPin, LOW);
    digitalWrite(SP2RelayPin, LOW);
    digitalWrite(RevRelayPin, LOW);
    digitalWrite(ForRelayPin, LOW);

    lcd.setCursor(0, 0);
    lcd.print("    STOPPED     ");
    //  lcd.setCursor(0, 1);
    //  lcd.print("Sel Cycle, Start");

    //    digitalWrite(QuikWashLedPin, LOW);
    //    digitalWrite(QuikRinseLedPin, LOW);
    //    digitalWrite(QuikSpinLedPin, LOW);

    if (QuikSelectRunningState == HIGH) {

      QuikCycleStartTime = millis();
    }
  }
}
//***********************************************
//***********************************************

void QuikMillisReset() {

  QuikWashPulseStartTime = millis();
  QuikSpinPulseStartTime = millis();


}

//***********************************************
//***********************************************
void ForDrvDir() {

  CheckInputStates();

  digitalWrite(ForRevDRVRelayPin, HIGH);

}

//***********************************************
//***********************************************

void RevDrvDir() {

  CheckInputStates();

  digitalWrite(ForRevDRVRelayPin, LOW);

}

//***********************************************
//***********************************************

void MotorSpinPulseForDir() {

  WashRunning = HIGH;
  CheckInputStates();
  
if (SmallSpinState == HIGH){
    if ((SpinPulseState == HIGH) && (BigSpinState == LOW)) {

analogWrite(DriveSpeedPin ,DriveSpeedSpinning);
  digitalWrite(RevRelayPin, LOW);
  digitalWrite(ForRelayPin, HIGH);
//    digitalWrite(BrakeRelayPin, HIGH);
    }
    
 if ((SpinPulseState == LOW) && (BigSpinState == LOW)){
  
analogWrite(DriveSpeedPin ,0);
  digitalWrite(ForRelayPin, LOW);

 }
}
}

//***********************************************
void MotorStop() {
  CheckInputStates();

  WashRunning = LOW;
  
analogWrite(DriveSpeedPin ,0);
  digitalWrite(RevRelayPin, LOW);
  digitalWrite(ForRelayPin, LOW);
//    digitalWrite(BrakeRelayPin, LOW);
}
//***********************************************

void MotorSpinForDir() {

  WashRunning = HIGH;
  CheckInputStates();

    if ((BigSpinState == HIGH) && (SmallSpinState == LOW)) {

analogWrite(DriveSpeedPin ,DriveSpeedSpinning);
  digitalWrite(RevRelayPin, LOW);
  digitalWrite(ForRelayPin, HIGH);
//    digitalWrite(BrakeRelayPin, HIGH);
    }
    
}

//***********************************************

void MotorForDir() {

  WashRunning = HIGH;
  CheckInputStates();

    if ((BigSpinState == LOW) && (SmallSpinState == LOW)) {

analogWrite(DriveSpeedPin ,DriveSpeedNormal);
  digitalWrite(RevRelayPin, LOW);
  digitalWrite(ForRelayPin, HIGH);
//    digitalWrite(BrakeRelayPin, HIGH);
    }
}

//***********************************************

void MotorStop1() {
  CheckInputStates();

  WashRunning = LOW;
  
analogWrite(DriveSpeedPin ,0);
  digitalWrite(RevRelayPin, LOW);
  digitalWrite(ForRelayPin, LOW);
//    digitalWrite(BrakeRelayPin, HIGH);
}

//***********************************************

void MotorRevDir() {

  WashRunning = HIGH;
  CheckInputStates();

    if ((BigSpinState == LOW) && (SmallSpinState == LOW)) {

analogWrite(DriveSpeedPin ,DriveSpeedNormal);
 digitalWrite(ForRelayPin, LOW);
  digitalWrite(RevRelayPin, HIGH);
//    digitalWrite(BrakeRelayPin, HIGH);
}
}

//***********************************************

void MotorStop2() {
  CheckInputStates();

  WashRunning = LOW;
WaterLevel = SelectedWaterLevel;  
analogWrite(DriveSpeedPin ,0);
  digitalWrite(RevRelayPin, LOW);
  digitalWrite(ForRelayPin, LOW);
//    digitalWrite(BrakeRelayPin, HIGH);
}

//***********************************************
//***********************************************

void SP1On() {

  digitalWrite(SP1RelayPin, LOW);

}

//***********************************************

void SP1Off() {

  digitalWrite(SP1RelayPin, HIGH);

}

//***********************************************
//***********************************************

void SP2On() {


  digitalWrite(SP2RelayPin, LOW);

}

//***********************************************

void SP2Off() {


  digitalWrite(SP2RelayPin, HIGH);

}

//***********************************************
//***********************************************

void MainMotorOn() {
  
  MainMotorOnOffState = HIGH;

  digitalWrite(MainMotorOnOff, HIGH);

}


//***********************************************

void MainMotorOff() {
  
  MainMotorOnOffState = LOW;

  digitalWrite(MainMotorOnOff, LOW);

}


//***********************************************
//***********************************************

void BrakeOn() {

//WashPulseTimer();

if (BrakingOn == true){
  digitalWrite(BrakeRelayPin, LOW);
}
}


//***********************************************

void BrakeOff() {
//
//WashPulseTimer();

if (BrakingOn == false){

  digitalWrite(BrakeRelayPin, HIGH);
}
}


//***********************************************
//***********************************************

void DrainPumpOn() {
  WashDrain();
  DrainPumpRunning = HIGH;

  digitalWrite(DrainPumpRelayPin, HIGH);

}


//***********************************************

void DrainPumpOff() {
  WashDrain();
  DrainPumpRunning = LOW;

  digitalWrite(DrainPumpRelayPin, LOW);

}


//***********************************************
//***********************************************

void ColdSolOn() {


  digitalWrite(ColdSolRelayPin, HIGH);

}


//***********************************************

void ColdSolOff() {


  digitalWrite(ColdSolRelayPin, LOW);

}


//***********************************************
//***********************************************

void DetergentSolOn() {


  digitalWrite(DetergentSolRelayPin, HIGH);

}


//***********************************************

void DetergentSolOff() {


  digitalWrite(DetergentSolRelayPin, LOW);

}


//***********************************************
//***********************************************

void HotSolOn() {


  digitalWrite(HotSolRelayPin, HIGH);

}


//***********************************************

void HotSolOff() {


  digitalWrite(HotSolRelayPin, LOW);

}


////***********************************************
//              WATER SUPPLY (HOT / COLD) SELECT

void HotColdSelect() {

  WashLoadSelect();
  //  LCDprint();
  MathCycleTimes();
  CheckInputStates();

  // compare the buttonState to its previous state
  if (WaterSupplyPinState != WaterSupplylastButtonState) {
    // if the state has changed, increment the counter
    if (WaterSupplyPinState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      WaterSupplybuttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(WaterSupplybuttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(10);
  }
  // save the current state as the last state, for next time through the loop
  WaterSupplylastButtonState = WaterSupplyPinState;

  if (WaterSupplybuttonPushCounter == 0) {
    digitalWrite(ColdBluLedPin, HIGH);
  } else {
    digitalWrite(ColdBluLedPin, LOW);
  }

  if (WaterSupplybuttonPushCounter == 1) {
    digitalWrite(HotRedLedPin, HIGH);
  } else {
    digitalWrite(HotRedLedPin, LOW);
  }

  if (WaterSupplybuttonPushCounter == 2) {
    WaterSupplybuttonPushCounter = 0;
  }

}

//*************************************************
//        WATER LEVEL CONTROL

void WaterLevelControl() {
  CheckInputStates();

//  WaterLevelActual = analogRead(WaterVolumePin);
//  WaterLevelActual = map(WaterLevelActual, 0, 61, 0, 100);
//  
//  WaterLevelActual2 = analogRead(WaterVolumePin);
//  WaterLevelActual2 = map(WaterLevelActual2, 0, 61, 0, 100);

  WaterLevel = analogRead(WaterVolumePin);
//  WaterLevel = map(WaterLevel, 0, 61, 0, 100);

if (WaterLevel <= 0){

  WaterLevel = 0;
}

  if (WaterLevel >= SelectedWaterLevel + 5) {
    
WaterLevelGood = true;
    
//    WaterLevelPrevious = WaterLevel;
    
//    WaterLevelPrevious = WaterLevel;
    WaterLevelNotOK = LOW;
    WaterLevelOK = HIGH;
    
    QuikWashingLevelNotOk = false;
    QuikRinsingLevelNotOk = false;    
    QuikWashingLevelOk = true;
    QuikRinsingLevelOk = true;
    
    digitalWrite(DetergentSolRelayPin, LOW);
    digitalWrite(ColdSolRelayPin, LOW);
    digitalWrite(HotSolRelayPin, LOW);
    //
    //      digitalWrite(SP1RelayPin, LOW);
    //      digitalWrite(SP2RelayPin, LOW);
    //      digitalWrite(RevRelayPin, HIGH);
    //      digitalWrite(ForRelayPin, HIGH);

  }
  
  if (WaterLevel >= SelectedWaterLevel - 5) {
    
WaterLevelGood = false;

    WaterLevelOK = LOW;
    WaterLevelNotOK = HIGH;
    
    QuikWashingLevelOk = false;
    QuikRinsingLevelOk = false;
    QuikWashingLevelNotOk = true;
    QuikRinsingLevelNotOk = true;
        
//  WaterLevelActual = analogRead(WaterVolumePin);
//  WaterLevelActual = map(WaterLevelActual, 0, 61, 0, 100);
//  
//WaterLevelActual2 = analogRead(WaterVolumePin);
//  WaterLevelActual2 = map(WaterLevelActual2, 0, 61, 0, 100);
//
//WaterLevel = ((WaterLevelActual + WaterLevelActual2) / 2);
//
//  WaterLevel = analogRead(WaterVolumePin);
//
//  WaterLevel = map(WaterLevel, 0, 61, 0, 100);
  
  }


if (WaterLevelGood == true){
    
    digitalWrite(DetergentSolRelayPin, LOW);
    digitalWrite(ColdSolRelayPin, LOW);
    digitalWrite(HotSolRelayPin, LOW);  
}




  if (WaterLevel <= 5) {
    EmptyDrum = HIGH;
    DrainPumpRunning = LOW;
//    digitalWrite(DrainPumpRelayPin, LOW);

  }

  if (WaterLevel >= 10) {
    EmptyDrum = LOW;
  }

  if (WaterLevel <= SelectedWaterLevel) {
//    WaterLevelPrevious = WaterLevel;
  }

}

//***************************************************

void Filling() {



  
  CheckInputStates();
  
  WaterLevelControl();

  
    RinseFillOn = LOW;
WashFillOn = HIGH;

//        digitalWrite(SP1RelayPin, LOW);
//        digitalWrite(SP2RelayPin, LOW);
//        digitalWrite(RevRelayPin, HIGH);
//        digitalWrite(ForRelayPin, HIGH);

  if (RinseFillOn == LOW){
  if (StartState == HIGH) {

    if (BigSpinningOn == LOW) {

      if ((WashDrainCycle == LOW) && (FillRinseCycle == LOW)) {
        FillingWashCycle = HIGH;
        WashFillRunning = HIGH;
      }

      if ((RinseFillRunning == LOW) && (WashDrainRunning == LOW)) {

        //**************************************************
        //                COLD SELECT CYCLE

        if  ((WaterLevelNotOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 0) && (FillingWashCycle == HIGH) && (WashDrainCycle == LOW) && (FillRinseCycle == LOW) && (RinseFillOn == LOW)) {

          digitalWrite(HotSolRelayPin, LOW);
          digitalWrite(ColdSolRelayPin, HIGH);

          //ColdSolOn();
          lcd.setCursor(0, 0);
          lcd.print(" Fill COLD Water ");
          WashWaterReady();
          WashCycleStartTime = millis();
        }

        else if ((WaterLevelOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 0) && (FillingWashCycle == HIGH))
        {

//    WaterLevelPrevious = WaterLevel;
          
          //  digitalWrite(ColdSolRelayPin, LOW);
          ////ColdSolOff();
          //WashCycleTimer();
          WashWaterReady();
        }

        //**************************************************
        //                HOT SELECT CYCLE

        if  ((WaterLevelNotOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 1) && (FillingWashCycle == HIGH) && (WashDrainCycle == LOW) && (FillRinseCycle == LOW) && (RinseFillOn == LOW)) {

          //HotSolOn();

          digitalWrite(ColdSolRelayPin, HIGH);
          digitalWrite(HotSolRelayPin, HIGH);

          lcd.setCursor(0, 0);
          lcd.print(" Fill HOT Water ");
          WashWaterReady();
          WashCycleStartTime = millis();

        }

        else if ((WaterLevelOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 1) && (FillingWashCycle == HIGH))
        {

//    WaterLevelPrevious = WaterLevel;
          
          ////  digitalWrite(ColdSolRelayPin, LOW);
          //  digitalWrite(HotSolRelayPin, LOW);
          //  WashCycleTimer();
          //  WashFillRunning = LOW;
          ////HotSolOff();
          WashWaterReady();
        }
      }
    }
  }
//  else if (StopState == HIGH) {
//    StopCycle();
//  }
}

//************************************************************
//                QUIK WASH FILLING
//
//volatile bool QuikWashingFilling = false;
//QuikWashingLevelNotOk
//QuikWashingOn = true;
//    QuikWashingLevelOk = true;
//    
//    QuikRinsingLevelOk = true;
//QuikRinsingLevelNotOk
//QuikRinsingOn = true;
//volatile bool QuikRinsingFilling = false;

if (QuikWashingOn == true){

//**************************************************
//                COLD SELECT CYCLE

        if  ((QuikWashingLevelNotOk == true) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 0) && (QuikWashingFilling == true)) {

          digitalWrite(HotSolRelayPin, LOW);
          digitalWrite(ColdSolRelayPin, HIGH);

          //ColdSolOn();
          lcd.setCursor(0, 0);
          lcd.print(" Fill COLD Water ");
          WashWaterReady();
//          WashCycleStartTime = millis();
        }

        else if ((QuikWashingLevelOk == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 0) && (QuikWashingFilling == true))
        {

//    WaterLevelPrevious = WaterLevel;
          
          //  digitalWrite(ColdSolRelayPin, LOW);
          ////ColdSolOff();
          //WashCycleTimer();
          WashWaterReady();
        }

        //**************************************************
        //                HOT SELECT CYCLE

        if  ((QuikWashingLevelNotOk == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 1) && (QuikWashingFilling == true)) {

          //HotSolOn();

          digitalWrite(ColdSolRelayPin, HIGH);
          digitalWrite(HotSolRelayPin, HIGH);

          lcd.setCursor(0, 0);
          lcd.print(" Fill HOT Water ");
          WashWaterReady();
//          WashCycleStartTime = millis();

        }

        else if ((QuikWashingLevelOk == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 1) && (QuikWashingFilling == true))
        {

//    WaterLevelPrevious = WaterLevel;
          
          ////  digitalWrite(ColdSolRelayPin, LOW);
          //  digitalWrite(HotSolRelayPin, LOW);
          //  WashCycleTimer();
          //  WashFillRunning = LOW;
          ////HotSolOff();
          WashWaterReady();
        }


}

//***********************************************************

}

//**********************************************************
void WashWaterReady() {
  CheckInputStates();
WashFillOn = LOW;

  if  ((WaterLevelOK == HIGH) && (StartState == HIGH) && (FillingWashCycle == HIGH)) {
    
//WaterLevel = WaterLevel - 20;

    digitalWrite(ColdSolRelayPin, LOW);
    digitalWrite(HotSolRelayPin, LOW);

//    WaterLevelPrevious = WaterLevel;
    
    WashCycleTimer();
    WashFillRunning = LOW;

  }
  if  ((WaterLevelOK == LOW) && (StartState == HIGH) && (FillingWashCycle == HIGH)) {
    //  WashCycleStartTime = millis();
    //  CycleStartTime = millis();
    //WashDrainCycle = LOW;
  }


//******************************************************************
//            QUIK WASHING WATER LEVEL READY


//
//QuikWashingFilling
//QuikWashingLevelNotOk
//QuikWashingOn
//QuikWashingLevelOk
//    
//QuikRinsingLevelOk
//QuikRinsingLevelNotOk
//QuikRinsingOn
//QuikRinsingFilling


if (QuikWashingOn == true){


QuikWashingFilling = true;

  if  ((QuikWashingLevelOk == true) && (StartState == HIGH) && (QuikWashingOn == true) && (QuikWashingFilling == true)) {
    
    digitalWrite(ColdSolRelayPin, LOW);
    digitalWrite(HotSolRelayPin, LOW);
    
//    WashCycleTimer();

    QuikWashing();

  }
  
//  if  ((WaterLevelOK == LOW) && (StartState == HIGH) && (FillingWashCycle == HIGH)) {
//    //  WashCycleStartTime = millis();
//    //  CycleStartTime = millis();
//    //WashDrainCycle = LOW;
//  }

}

//******************************************************************

}

//**********************************************************************************
//               DRAINING CYCLE

void WashDrain() {
//WashFillOn = LOW;



//        digitalWrite(SP1RelayPin, LOW);
//        digitalWrite(SP2RelayPin, LOW);
//        digitalWrite(RevRelayPin, HIGH);
//        digitalWrite(ForRelayPin, HIGH);

  //WashDrainWatch();
  CheckInputStates();
  if (StartState == HIGH) {
    FillingWashCycle = LOW;
    if (RinsingRunning == LOW) {

      if (RinseDrainRunning == LOW) {

        if ((EmptyDrum == LOW) && (StartState == HIGH) && (WashDrainCycle == HIGH)) {
//  WaterLevel = WaterLevelPrevious;
  lcd.setCursor(0, 0);
          lcd.print("Drain Wash Water ");
      WashFillOn = LOW;
          WashDrainRunning = HIGH;
          digitalWrite(DrainPumpRelayPin, HIGH);
          //DrainPumpOn();
          //      CycleStartTime = millis();

        }

        if ((EmptyDrum == HIGH) && (StartState == HIGH) && (WashDrainRunning == HIGH)) {
          //DrainPumpOff();
          //WashDrainRunning = LOW;
          //WashRunCycle = LOW;
          digitalWrite(DrainPumpRelayPin, LOW);
          WashFillOn = LOW;
          WashRunCycle = LOW;
          FillingSoftner();
          WashDrainCycle = LOW;

        }
      }
    }
  }
  else if (StopState == HIGH) {
    StopCycle();
  }

//**************************************************
//          QUIK WASH DRAINING

 if (QuikWashingOn == true){

        if ((EmptyDrum == LOW) && (StartState == HIGH) && (QuikWashingDraining == true)) {
//  WaterLevel = WaterLevelPrevious;
  lcd.setCursor(0, 0);
          lcd.print("Drain Wash Water ");

          digitalWrite(DrainPumpRelayPin, HIGH);
          //DrainPumpOn();
          //      CycleStartTime = millis();

        }
    
        if ((EmptyDrum == HIGH) && (StartState == HIGH) && (QuikWashingDraining == true)) {
    
    QuikBuzzerPulseTimer();
    QuikBuzzerTimer();
    QuikBuzzer();
    
  lcd.setCursor(0, 0);
          lcd.print("Done Quik Wash");          
        }

        
  
 }




//**************************************************

}
//***************************************************

//**********************************

void WashDrainWatch() {
      RinseFillOn = HIGH;

  WaterLevelControl();
  if (StartState == HIGH) {
    RinseFillOn = HIGH;
    CheckInputStates();
    FillingWashCycle = LOW;
    if ((WashingRunning == HIGH) && (WashDrainRunning == HIGH) && (WaterLevelNotOK == HIGH)) {
      WashDrainRunning = LOW;
      WashingRunning = LOW;
//      Spinning();
    }
  }
  else if (StopState == HIGH) {
    StopCycle();
  }

//************************************************************************

if ((QuikWashingOn == true) && (WashDrainRunning == HIGH) && (EmptyDrum== HIGH)) {


    QuikBuzzerPulseTimer();
    QuikBuzzerTimer();
    QuikBuzzer();

}
}


//**********************************
void FillingSoftner() {

  WaterLevelControl();
  
  CheckInputStates();
      RinseFillOn = HIGH;
if (WashFillOn == LOW){
  
//        digitalWrite(SP1RelayPin, LOW);
//        digitalWrite(SP2RelayPin, LOW);
//        digitalWrite(RevRelayPin, HIGH);
//        digitalWrite(ForRelayPin, HIGH);

  //  if (StartState == HIGH) {
  if (BigSpinningOn == LOW) {
    if (BigSpinCycle == LOW) {
      RinseFillOn = HIGH;
      WashDrainRunning = LOW;
      WashDrainCycle = LOW;
      WashDrainRunning = LOW;
      //RinseWaterReady();
      WashDrainCycle = LOW;
      RinseFillRunning = HIGH;
      FillingWashCycle = LOW;
      FillRinseCycle = HIGH;
      WaterLevelControl();
      RinseWaterReady();

      //**************************************************
      //                COLD RINSE SELECT CYCLE

      if  ((WaterLevelNotOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 0) && (FillRinseCycle == HIGH) && (RinseFillOn == HIGH) && (WashFillOn == LOW)) {
        lcd.setCursor(0, 0);
        lcd.print(" Fill Det. Water ");

        digitalWrite(HotSolRelayPin, LOW);
        digitalWrite(ColdSolRelayPin, HIGH);
        digitalWrite(DetergentSolRelayPin, HIGH);

        //DetergentSolOn();
        //ColdSolOn();
        //      CycleStartTime = millis();
        //RinseCycleStartTime = millis();
      }

      else if ((WaterLevelOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 0) && (FillRinseCycle == HIGH) && (RinseFillOn == HIGH) && (WashFillOn == LOW)) {

//    WaterLevelPrevious = WaterLevel;

        //  digitalWrite(ColdSolRelayPin, LOW);
        //  digitalWrite(DetergentSolRelayPin, LOW);

        RinseWaterReady();
      }

      //**************************************************
      //                HOT RINSE SELECT CYCLE


      if  ((WaterLevelNotOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 1) && (FillRinseCycle == HIGH) && (RinseFillOn == HIGH) && (WashFillOn == LOW)) {
        lcd.setCursor(0, 0);
        lcd.print(" Fill Det. Water ");

        digitalWrite(ColdSolRelayPin, HIGH);
        digitalWrite(DetergentSolRelayPin, HIGH);
        digitalWrite(HotSolRelayPin, HIGH);

        //DetergentSolOn();
        //HotSolOn();
        //      CycleStartTime = millis();
        //RinseCycleStartTime = millis();
      }

      else if ((WaterLevelOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 1) && (FillRinseCycle == HIGH) && (RinseFillOn == HIGH) && (WashFillOn == LOW)) {
        //
        //  digitalWrite(ColdSolRelayPin, LOW);
        //  digitalWrite(DetergentSolRelayPin, LOW);
        //  digitalWrite(HotSolRelayPin, LOW);

//    WaterLevelPrevious = WaterLevel;

        RinseWaterReady();
      }

      //}
    }
  }
  else if (StopState == HIGH) {
    StopCycle();
  }
  //  }
}

//***********************************************************
//            QUIK RINSING FILLING

if (QuikRinsingOn == true){

      //**************************************************
      //                COLD RINSE SELECT CYCLE

      if  ((WaterLevelNotOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 0) && (FillRinseCycle == HIGH) && (RinseFillOn == HIGH) && (WashFillOn == LOW)) {
        lcd.setCursor(0, 0);
        lcd.print(" Fill Det. Water ");

        digitalWrite(HotSolRelayPin, LOW);
        digitalWrite(ColdSolRelayPin, HIGH);
        digitalWrite(DetergentSolRelayPin, HIGH);

        //DetergentSolOn();
        //ColdSolOn();
        //      CycleStartTime = millis();
        //RinseCycleStartTime = millis();
      }

      else if ((WaterLevelOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 0) && (FillRinseCycle == HIGH) && (RinseFillOn == HIGH) && (WashFillOn == LOW)) {

//    WaterLevelPrevious = WaterLevel;

        //  digitalWrite(ColdSolRelayPin, LOW);
        //  digitalWrite(DetergentSolRelayPin, LOW);

        RinseWaterReady();
      }

      //**************************************************
      //                HOT RINSE SELECT CYCLE


      if  ((WaterLevelNotOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 1) && (FillRinseCycle == HIGH) && (RinseFillOn == HIGH) && (WashFillOn == LOW)) {
        lcd.setCursor(0, 0);
        lcd.print(" Fill Det. Water ");

        digitalWrite(ColdSolRelayPin, HIGH);
        digitalWrite(DetergentSolRelayPin, HIGH);
        digitalWrite(HotSolRelayPin, HIGH);

        //DetergentSolOn();
        //HotSolOn();
        //      CycleStartTime = millis();
        //RinseCycleStartTime = millis();
      }

      else if ((WaterLevelOK == HIGH) && (StartState == HIGH) && (WaterSupplybuttonPushCounter == 1) && (FillRinseCycle == HIGH) && (RinseFillOn == HIGH) && (WashFillOn == LOW)) {
        //
        //  digitalWrite(ColdSolRelayPin, LOW);
        //  digitalWrite(DetergentSolRelayPin, LOW);
        //  digitalWrite(HotSolRelayPin, LOW);

//    WaterLevelPrevious = WaterLevel;

        RinseWaterReady();
      }
  
}




//************************************************************

}

//**********************************************************
void RinseWaterReady() {
  CheckInputStates();
  FillingWashCycle = LOW;
  //FillingSoftner();
  WaterLevelControl();

  if  ((WaterLevelOK == LOW) && (StartState == HIGH) && (FillRinseCycle == HIGH)){
//       && (RinseFillOn == HIGH)) {
    //FillRinseCycle = HIGH;
    RinseCycleStartTime = millis();

    //  CycleStartTime = millis();
  }

  else

    if  ((WaterLevelOK == HIGH) && (StartState == HIGH) && (FillRinseCycle == HIGH)){
//         && (RinseFillOn == HIGH)) {
      if (FillingWashCycle == LOW) {
    
//WaterLevel = WaterLevel - 20;

        digitalWrite(DetergentSolRelayPin, LOW);
        digitalWrite(ColdSolRelayPin, LOW);
        digitalWrite(HotSolRelayPin, LOW);
        //FillRinseCycle = LOW;
        RinseFillRunning = LOW;
        RinseCycleTimer();
      }

    }


//*************************************************************************************
//                QUIK RINSING WATER READY

if (QuikRinsingOn == true){

  if  ((WaterLevelOK == LOW) && (StartState == HIGH) && (QuikRinsingFilling == true)){

  }

  else

    if  ((WaterLevelOK == HIGH) && (StartState == HIGH) && (QuikRinsingFilling == true)){
    

        digitalWrite(DetergentSolRelayPin, LOW);
        digitalWrite(ColdSolRelayPin, LOW);
        digitalWrite(HotSolRelayPin, LOW);

        QuikRinsing();


    }  
}

//****************************************************
    
}

//**********************************************************************************
//*****************************

void RinseDrain() {

  CycleProgress = WashCycleStopTime + RinseCycleStopTime + SpinCycleTime;

//        digitalWrite(SP1RelayPin, LOW);
//        digitalWrite(SP2RelayPin, LOW);
//        digitalWrite(RevRelayPin, HIGH);
//        digitalWrite(ForRelayPin, HIGH);

  RinseFillOn = LOW;
  FillingWashCycle = LOW;
  FillRinseCycle = LOW;

  WaterLevelControl();
  CheckInputStates();
  RinseDrainWatch();

  if (StartState == HIGH) {

    //  if ((EmptyDrum == LOW) && (StartState == HIGH) && (SpinDrain == HIGH) && (BigSpinDrainState == HIGH)) {
    if ((EmptyDrum == LOW) && (RinseDrainRunning == HIGH)) {
      //    lcd.setCursor(0, 0);
      //    lcd.print("Drain Det. Water ");
      RinseDrainWatch();
    }

    //  if ((EmptyDrum == HIGH) && (StartState == HIGH) && (SpinDrain == HIGH) && (BigSpinDrainState == HIGH)) {
    if ((EmptyDrum == HIGH) && (RinseDrainRunning == HIGH)) {
      //    lcd.setCursor(0, 0);
      //    lcd.print("    DRUM EMPTY   ");
      RinsDrainEmpty();
      RinseDrainWatch();
    }

  }
  else if (StopState == HIGH) {
    StopCycle();
  }

//***********************************************************************************
//              QUIK RINSE DRAINING

if (QuikRinsingOn == true){
  
  if (StartState == HIGH) {

    //  if ((EmptyDrum == LOW) && (StartState == HIGH) && (SpinDrain == HIGH) && (BigSpinDrainState == HIGH)) {
    if ((EmptyDrum == LOW) && (QuikRinsingOn == true)) {
          lcd.setCursor(0, 0);
          lcd.print("Drain Det. Water ");
      RinseDrainWatch();
    }

    //  if ((EmptyDrum == HIGH) && (StartState == HIGH) && (SpinDrain == HIGH) && (BigSpinDrainState == HIGH)) {
    if ((EmptyDrum == HIGH) && (QuikRinsingOn == true)) {
          lcd.setCursor(0, 0);
          lcd.print("    DRUM EMPTY   ");

    QuikBuzzerPulseTimer();
    QuikBuzzerTimer();
    QuikBuzzer();
    
    }

  }
  else if (StopState == HIGH) {
    StopCycle();
  }
  
}





}

//**********************************************************

void RinseDrainWatch() {
  WaterLevelControl();
  CheckInputStates();
  FillingWashCycle = LOW;
  RinseDrainRunning = HIGH;

  //  if ((RinsingRunning == HIGH) && (RinseDrainRunning == HIGH) && (EmptyDrum == LOW)) {
  if ((EmptyDrum == LOW) && (RinseDrainRunning == HIGH)) {
  CycleProgress = WashCycleStopTime + RinseCycleStopTime + SpinCycleTime;
//  WaterLevel = WaterLevelPrevious;
  lcd.setCursor(0, 0);
    lcd.print("Drain Det. Water ");
    digitalWrite(DrainPumpRelayPin, HIGH);
    //DrainPumpOn();
    SpinCycleStartTime = millis();
    SmallSpinStartTime = millis();
  }



  //    if ((RinsingRunning == HIGH) && (RinseDrainRunning == HIGH) && (EmptyDrum == HIGH)) {
  if ((EmptyDrum == HIGH)  && (RinseDrainRunning == HIGH)) {
    RinsDrainEmpty();
    //DrainPumpOff();

  }



//***********************************************************************************
//              QUIK RINSE DRAINING

if (QuikRinsingOn == true){


  if ((EmptyDrum == LOW) && (QuikRinsingOn == true)) {
  CycleProgress = WashCycleStopTime + RinseCycleStopTime + SpinCycleTime;
//  WaterLevel = WaterLevelPrevious;
  lcd.setCursor(0, 0);
    lcd.print("Drain Det. Water ");
    digitalWrite(DrainPumpRelayPin, HIGH);
    //DrainPumpOn();
    SpinCycleStartTime = millis();
    SmallSpinStartTime = millis();
  }



  //    if ((RinsingRunning == HIGH) && (RinseDrainRunning == HIGH) && (EmptyDrum == HIGH)) {
  if ((EmptyDrum == HIGH)  && (QuikRinsingOn == true)) {

QuikRinsing();

  }
}
  
}

//******************************************************************************

void RinsDrainEmpty() {

  if ((RinsingRunning == HIGH) && (RinseDrainRunning == HIGH) && (EmptyDrum == LOW)) {
  CycleProgress = WashCycleStopTime + RinseCycleStopTime + SpinCycleTime;
    FillRinseCycle = LOW;
    lcd.setCursor(0, 0);
    lcd.print("Drain Det. Water ");
        digitalWrite(DrainPumpRelayPin, HIGH);
    //DrainPumpOn();
    SpinCycleStartTime = millis();
    SmallSpinStartTime = millis();
    BigSpinStartTime = millis();

  }

  if ((RinsingRunning == HIGH) && (RinseDrainRunning == HIGH) && (EmptyDrum == HIGH)) {
    FillRinseCycle = LOW;
    lcd.setCursor(0, 0);
    lcd.print("    DRUM EMPTY   ");
//    RinseDrainRunning = LOW;
//    RinsingRunning = LOW;
    digitalWrite(DrainPumpRelayPin, HIGH);
//RinseDrainRunning = LOW;
    SpinCycleTimer();
    //      SmallSpinTimer();
    //      BigSpinning();
  }
}

//*****************************************************************************************

void MotorRunningCheck(){

if ((BigSpinState == LOW) && (SmallSpinState == LOW)) {
if ((RinseDrainRunning == HIGH) || (WashDrainCycle == HIGH)){
        
        digitalWrite(SP1RelayPin, LOW);
        digitalWrite(SP2RelayPin, LOW);
        digitalWrite(RevRelayPin, LOW);
        digitalWrite(ForRelayPin, LOW);  

}
}
}

//******************************************************************************************

//RinseRunning = HIGH;
//    BigSpinTimer();
//    BigSpinStartTime = millis();
//     BigSpinState = HIGH

//int FillingWashCycle;
//int StopFillingCycle;
//int WashRunCycle;
//int StopWashCycle;
//int WashDrainCycle;
//int SmallWashSpinCycle;
//int StopSmallSpin;
//int StopDrainCycle;
//int FillRinseCycle;
//int StopFillRinseCycle;
//int RinseRunCycle;
//int StopRinseCycle;
//int SpinDrain
//int SmallRinseSpinCycle;
//int BigSpinCycle
//int StopBigSpinCycle
//int StopSpinDrainCycle;
////***********************************************


////***********************************************

//            WASHLOADSELECT

////***********************************************
//            WASHLOADSELECT

void WashLoadSelect() {

  CheckInputStates();

  if (WaterLevelPinState != WaterLevellastButtonState) {
    // if the state has changed, increment the counter
    if (WaterLevelPinState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      WaterLevelbuttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(WaterLevelbuttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(10);
  }
  // save the current state as the last state, for next time through the loop
  WaterLevellastButtonState = WaterLevelPinState;


  if (WaterLevelbuttonPushCounter == 1) {
    digitalWrite(UltraLowLedPin, HIGH);
    SelectedWaterLevel = 30;  //20;
    UltraLowSelCycle();
    UltraLow = HIGH;
  } else {
    digitalWrite(UltraLowLedPin, LOW);
    UltraLow = LOW;

  }

  if (WaterLevelbuttonPushCounter == 2) {
    digitalWrite( ExtraLowLedPin, HIGH);
    SelectedWaterLevel = 30;
    ExtraLowSelCycle();
    ExtraLow = HIGH;
  } else {
    digitalWrite( ExtraLowLedPin, LOW);
    ExtraLow = LOW;

  }

  if (WaterLevelbuttonPushCounter == 3) {
    digitalWrite(VeryLowLedPin, HIGH);
    SelectedWaterLevel = 40;
    VeryLowSelCycle();
    VeryLow = HIGH;
  } else {
    digitalWrite(VeryLowLedPin, LOW);
    VeryLow = LOW;

  }

  if (WaterLevelbuttonPushCounter == 4) {
    digitalWrite(LowLedPin, HIGH);
    SelectedWaterLevel = 50;
    LowSelCycle();
    Low = HIGH;
  } else {
    digitalWrite(LowLedPin, LOW);
    Low = LOW;

  }

  if (WaterLevelbuttonPushCounter == 5) {
    digitalWrite(MedLowLedPin, HIGH);
    SelectedWaterLevel = 60;
    MedLowSelCycle();
    MedLow = HIGH;
  } else {
    digitalWrite(MedLowLedPin, LOW);
    MedLow = LOW;

  }

  if (WaterLevelbuttonPushCounter == 6) {
    digitalWrite( MedMedLedPin, HIGH);
    SelectedWaterLevel = 70;
    MedMedSelCycle();
    MedMed = HIGH;
  } else {
    digitalWrite( MedMedLedPin, LOW);
    MedMed = LOW;

  }

  if (WaterLevelbuttonPushCounter == 7) {
    digitalWrite(MediumLedPin, HIGH);
    SelectedWaterLevel = 80;
    MediumSelCycle();
    Medium = HIGH;
  } else {
    digitalWrite(MediumLedPin, LOW);
    Medium = LOW;

  }

  if (WaterLevelbuttonPushCounter == 8) {
    digitalWrite(MedHighLedPin, HIGH);
    SelectedWaterLevel = 90;
    MedHighSelCycle();
    MedHigh = HIGH;
  } else {
    digitalWrite(MedHighLedPin, LOW);
    MedHigh = LOW;

  }

  if (WaterLevelbuttonPushCounter == 9) {
    digitalWrite(HighLedPin, HIGH);
    SelectedWaterLevel = 95;
    HighSelCycle();
    High = HIGH;
  } else {
    digitalWrite(HighLedPin, LOW);
    High = LOW;

  }

  if (WaterLevelbuttonPushCounter == 10) {
    digitalWrite(MaximumLedPin, HIGH);
    SelectedWaterLevel = 100;
    MaxSelCycle();
    Maximum = HIGH;
  } else {
    digitalWrite(MaximumLedPin, LOW);
    Maximum = LOW;

  }

  if ((WaterLevelbuttonPushCounter >= 11)) {   // || (StoppingState == HIGH)){
    WaterLevelbuttonPushCounter = 1;
  }


}


//***********************************************

////***********************************************
////          MAXIMUM CYCLE
//
void MaxSelCycle() {

  if (Maximum == HIGH) {



    MaximumCycle;    //  = 59;= Total = 59, Wash = 19, Rinse = 24, Spin = 16;  *****!!!! ALL TIMES IN MINUTES
    MaximumCycleTimeMinutes = 59;    //      = 59;
    MaximumCycleTimeSeconds;
    MaximumCycleTimeMilliSeconds;
    MaximumWashCycleTime = 20;    //      = 19;
    MaximumWashCycleTimeSeconds = (MaximumWashCycleTime * 60);    //      = 19;
    MaximumWashCycleTimeMillis = (MaximumWashCycleTime * 60) * 1000;    //      = 19;
    MaximumRinseCycleTime = 24;     //     = 24;
    MaximumRinseCycleTimeSeconds = (MaximumRinseCycleTime * 60);     //     = 24;
    MaximumRinseCycleTimeMillis = (MaximumWashCycleTime * 60) * 1000;     //     = 24;
    MaximumSpinCycleTime = 16;     //     = 16;
    MaximumSpinCycleTimeSeconds = (MaximumSpinCycleTime * 60);     //     = 16;
    MaximumSpinCycleTimeMillis = (MaximumWashCycleTime * 60) * 1000;     //     = 16;

    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      MaximumCycleTimeMinutes = 59;
      MaximumCycleTimeSeconds = MaximumCycleTimeMinutes * 60;
      //MaximumCycleTimeMilliSeconds = MaximumCycleTimeSeconds * 1000;

      CycleSetTime = MaximumCycleTimeSeconds;

      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;
      //
      //      CycleResetTime1 = MaximumWashCycleTimeMillis;
      //      CycleResetTime2 = MaximumWashCycleTimeMillis + MaximumRinseCycleTimeMillis;
      //      CycleResetTime3 = MaximumWashCycleTimeMillis + MaximumRinseCycleTimeMillis + MaximumSpinCycleTimeMillis;

      CycleResetTime1 = MaximumWashCycleTimeMillis;
      CycleResetTime2 = MaximumRinseCycleTimeMillis;
      CycleResetTime3 = MaximumSpinCycleTimeMillis;

      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (MaximumCycleTimeMinutes >= 1) {

        if (MaximumCycleTimeSeconds >= 59) {   // || (MaximumCycleTimeSeconds >= 60)){

          MaximumCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }

      MaximumCycleTimeSeconds = MaximumCycleTimeSeconds - CycleSeconds;
      MaximumCycleTimeMinutes = MaximumCycleTimeMinutes - CycleMinutes;

    }

    if (QuikSelectRunningState == LOW) {

      if (MaximumCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(MaximumCycleTimeMinutes, DEC) + ":" + String(MaximumCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }
      if (MaximumCycleTimeSeconds <= 9) {
        DisplayTime = "Time Left: " + String(MaximumCycleTimeMinutes, DEC) + ":0" + String(MaximumCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }


      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);
    }

    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = MaximumWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;

        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMaximumWashCycleTimeSeconds = MaximumWashCycleTimeMillis / 1000;
        QuikMaximumWashCycleTimeMinutes = QuikMaximumWashCycleTimeSeconds / 60;

        if (QuikMaximumWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MaximumCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMaximumWashCycleTimeMinutes = MaximumWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMaximumWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMaximumWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {
        QuikRinsing();
        QuikCycleSetTime = MaximumRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMaximumRinseCycleTimeSeconds = MaximumRinseCycleTimeMillis / 1000;
        QuikMaximumRinseCycleTimeMinutes = QuikMaximumRinseCycleTimeSeconds / 60;

        if (QuikMaximumRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MaximumCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMaximumRinseCycleTimeMinutes = MaximumRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMaximumRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMaximumRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = MaximumSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikMaximumSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikMaximumSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MaximumCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMaximumSpinCycleTimeMinutes = MaximumRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMaximumSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikMaximumSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }

  }
}

//***********************************************
//***********************************************
//          HIGH CYCLE

void HighSelCycle() {

  if (High == HIGH) {



    HighCycle;       //  = 52;= Total = 52, Wash = 17, Rinse = 20, Spin = 15;  *****!!!! ALL TIMES IN MINUTES
    HighCycleTimeMinutes = 51;
    HighCycleTimeSeconds;
    HighCycleTimeMilliSeconds;
    HighWashCycleTime = 17;
    HighWashCycleTimeSeconds = HighWashCycleTime * 60;
    HighWashCycleTimeMillis = HighWashCycleTime * 60 * 1000;
    HighRinseCycleTime = 20;
    HighRinseCycleTimeSeconds = HighRinseCycleTime * 60;
    HighRinseCycleTimeMillis = HighRinseCycleTime * 60 * 1000;
    HighSpinCycleTime = 15;
    HighSpinCycleTimeSeconds = HighSpinCycleTime * 60;
    HighSpinCycleTimeMillis = HighSpinCycleTime * 60 * 1000;


    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      HighCycleTimeMinutes = 51;
      HighCycleTimeSeconds = HighCycleTimeMinutes * 60;
      //HighCycleTimeMilliSeconds = HighCycleTimeSeconds * 1000;

      CycleSetTime = HighCycleTimeSeconds;

      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;
      //
      //      CycleResetTime1 = HighWashCycleTimeMillis;
      //      CycleResetTime2 = HighWashCycleTimeMillis + HighRinseCycleTimeMillis;
      //      CycleResetTime3 = HighWashCycleTimeMillis + HighRinseCycleTimeMillis + HighSpinCycleTimeMillis;


      CycleResetTime1 = HighWashCycleTimeMillis;
      CycleResetTime2 = HighRinseCycleTimeMillis;
      CycleResetTime3 = HighSpinCycleTimeMillis;

      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (HighCycleTimeMinutes >= 1) {

        if (HighCycleTimeSeconds >= 59) {   // || (HighCycleTimeSeconds >= 60)){

          HighCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }

      HighCycleTimeSeconds = HighCycleTimeSeconds - CycleSeconds;
      HighCycleTimeMinutes = HighCycleTimeMinutes - CycleMinutes;

    }

    if (QuikSelectRunningState == LOW) {


      if (HighCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(HighCycleTimeMinutes, DEC) + ":" + String(HighCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }
      if (HighCycleTimeSeconds <= 9) {
        DisplayTime = "Time Left: " + String(HighCycleTimeMinutes, DEC) + ":0" + String(HighCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }


      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);
    }

    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = HighWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikHighWashCycleTimeSeconds = HighWashCycleTimeMillis / 1000;
        QuikHighWashCycleTimeMinutes = QuikHighWashCycleTimeSeconds / 60;

        if (QuikHighWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (HighCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikHighWashCycleTimeMinutes = HighWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikHighWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikHighWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {
        QuikRinsing();
        QuikCycleSetTime = HighRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikHighRinseCycleTimeSeconds = HighRinseCycleTimeMillis / 1000;
        QuikHighRinseCycleTimeMinutes = QuikHighRinseCycleTimeSeconds / 60;

        if (QuikHighRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (HighCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikHighRinseCycleTimeMinutes = HighRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikHighRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikHighRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = HighSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikHighSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikHighSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (HighCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikHighSpinCycleTimeMinutes = QuikHighSpinCycleTimeMinutes - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikHighSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikHighSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }

  }
}
////***********************************************
////***********************************************
////          MEDIUM HIGH CYCLE
//
void MedHighSelCycle() {
  //
  ////LCDprint();
  //  CheckInputStates();
  //CycleTimer();
  //WashLoadSelect();

  if (MedHigh == HIGH) {


    MedHighCycle;     //  = 45;= Total = 45, Wash = 17, Rinse = 18, Spin = 10;  *****!!!! ALL TIMES IN MINUTES
    MedHighCycleTimeMinutes;    //      = 45;
    MedHighCycleTimeSeconds;
    MedHighCycleTimeMilliSeconds;
    MedHighCycleTime = 44;
    MedHighWashCycleTime = 17;
    MedHighWashCycleTimeSeconds = MedHighWashCycleTime * 60;
    MedHighWashCycleTimeMillis = MedHighWashCycleTime * 60 * 1000;
    MedHighRinseCycleTime = 18;
    MedHighRinseCycleTimeSeconds = MedHighRinseCycleTime * 60;
    MedHighRinseCycleTimeMillis = MedHighRinseCycleTime * 60 * 1000;
    MedHighSpinCycleTime = 10;
    MedHighSpinCycleTimeSeconds = MedHighSpinCycleTime * 60;
    MedHighSpinCycleTimeMillis = MedHighSpinCycleTime * 60 * 1000;


    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      MedHighCycleTimeMinutes = 44;
      MedHighCycleTimeSeconds = MedHighCycleTimeMinutes * 60;
      //HighCycleTimeMilliSeconds = HighCycleTimeSeconds * 1000;

      CycleSetTime = MedHighCycleTimeSeconds;

      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;
      //
      //      CycleResetTime1 = MedHighWashCycleTimeMillis;
      //      CycleResetTime2 = MedHighWashCycleTimeMillis + MedHighRinseCycleTimeMillis;
      //      CycleResetTime3 = MedHighWashCycleTimeMillis + MedHighRinseCycleTimeMillis + MedHighSpinCycleTimeMillis;

      CycleResetTime1 = MedHighWashCycleTimeMillis;
      CycleResetTime2 = MedHighRinseCycleTimeMillis;
      CycleResetTime3 = MedHighSpinCycleTimeMillis;

      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (MedHighCycleTimeMinutes >= 1) {

        if (MedHighCycleTimeSeconds >= 59) {   // || (MedHighCycleTimeSeconds >= 60)){

          MedHighCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }

      MedHighCycleTimeSeconds = MedHighCycleTimeSeconds - CycleSeconds;
      MedHighCycleTimeMinutes = MedHighCycleTimeMinutes - CycleMinutes;

    }

    if (QuikSelectRunningState == LOW) {

      if (MedHighCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(MedHighCycleTimeMinutes, DEC) + ":" + String(MedHighCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }
      if (MedHighCycleTimeSeconds <= 9) {
        DisplayTime = "Time Left: " + String(MedHighCycleTimeMinutes, DEC) + ":0" + String(MedHighCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }


      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);
    }

    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = MedHighWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMedHighWashCycleTimeSeconds = MedHighWashCycleTimeMillis / 1000;
        QuikMedHighWashCycleTimeMinutes = QuikMedHighWashCycleTimeSeconds / 60;

        if (QuikMedHighWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MedHighCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMedHighWashCycleTimeMinutes = MedHighWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMedHighWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMedHighWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {
        QuikRinsing();
        QuikCycleSetTime = MedHighRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMedHighRinseCycleTimeSeconds = MedHighRinseCycleTimeMillis / 1000;
        QuikMedHighRinseCycleTimeMinutes = QuikMedHighRinseCycleTimeSeconds / 60;

        if (QuikMedHighRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MedHighCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMedHighRinseCycleTimeMinutes = MedHighRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMedHighRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMedHighRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = MedHighSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikMedHighSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikMedHighSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MedHighCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMedHighSpinCycleTimeMinutes = QuikMedHighSpinCycleTimeMinutes - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMedHighSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikMedHighSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }

  }
}
////***********************************************
////***********************************************
////          MEDIUM CYCLE
//
void MediumSelCycle() {

  //LCDprint();
  //  CheckInputStates();
  //CycleTimer();
  //WashLoadSelect();

  if (Medium == HIGH) {


    MediumCycle;     //  = 41;= Total = 41, Wash = 15, Rinse = 16, Spin = 10;  *****!!!! ALL TIMES IN MINUTES
    MediumCycleTimeMinutes = 40;
    MediumCycleTimeSeconds;
    MediumCycleTimeMilliSeconds;
    MediumWashCycleTime = 15;
    MediumWashCycleTimeSeconds = MediumWashCycleTime * 60;
    MediumWashCycleTimeMillis = MediumWashCycleTime * 60 * 1000;
    MediumRinseCycleTime = 16;
    MediumRinseCycleTimeSeconds = MediumRinseCycleTime * 60;
    MediumRinseCycleTimeMillis = MediumRinseCycleTime * 60 * 1000;
    MediumSpinCycleTime = 10;
    MediumSpinCycleTimeSeconds = MediumSpinCycleTime * 60;
    MediumSpinCycleTimeMillis = MediumSpinCycleTime * 60 * 1000;

    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      MediumCycleTimeMinutes = 40;
      MediumCycleTimeSeconds = MediumCycleTimeMinutes * 60;
      //MediumCycleTimeMilliSeconds = MediumCycleTimeSeconds * 1000;

      CycleSetTime = MediumCycleTimeSeconds;

      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;
      //
      //      CycleResetTime1 = MediumWashCycleTimeMillis;
      //      CycleResetTime2 = MediumWashCycleTimeMillis + MediumRinseCycleTimeMillis;
      //      CycleResetTime3 = MediumWashCycleTimeMillis + MediumRinseCycleTimeMillis + MediumSpinCycleTimeMillis;

      CycleResetTime1 = MediumWashCycleTimeMillis;
      CycleResetTime2 = MediumRinseCycleTimeMillis;
      CycleResetTime3 = MediumSpinCycleTimeMillis;

      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (MediumCycleTimeMinutes >= 1) {

        if (MediumCycleTimeSeconds >= 59) {   // || (MediumCycleTimeSeconds >= 60)){

          MediumCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }
      MediumCycleTimeSeconds = MediumCycleTimeSeconds - CycleSeconds;
      MediumCycleTimeMinutes = MediumCycleTimeMinutes - CycleMinutes;

    }

    if (QuikSelectRunningState == LOW) {

      if (MediumCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(MediumCycleTimeMinutes, DEC) + ":" + String(MediumCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }
      if (MediumCycleTimeSeconds <= 9) {
        DisplayTime = "Time Left: " + String(MediumCycleTimeMinutes, DEC) + ":0" + String(MediumCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }


      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);
    }

    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = MediumWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMediumWashCycleTimeSeconds = MediumWashCycleTimeMillis / 1000;
        QuikMediumWashCycleTimeMinutes = QuikMediumWashCycleTimeSeconds / 60;

        if (QuikMediumWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MediumCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMediumWashCycleTimeMinutes = MediumWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMediumWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMediumWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {
        QuikRinsing();
        QuikCycleSetTime = MediumRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMediumRinseCycleTimeSeconds = MediumRinseCycleTimeMillis / 1000;
        QuikMediumRinseCycleTimeMinutes = QuikMediumRinseCycleTimeSeconds / 60;

        if (QuikMediumRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MediumCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMediumRinseCycleTimeMinutes = MediumRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMediumRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMediumRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = MediumSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikMediumSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikMediumSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MediumCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMediumSpinCycleTimeMinutes = QuikMediumSpinCycleTimeMinutes - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMediumSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikMediumSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }

  }
}
////***********************************************
////***********************************************
////          MEDIUM MEDIUM CYCLE
//
void MedMedSelCycle() {
  //
  ////LCDprint();
  //  CheckInputStates();
  //CycleTimer();
  //WashLoadSelect();

  if (MedMed == HIGH) {


    MedMedCycle;     //  = 38;= Total = 38, Wash = 14, Rinse = 17, Spin = 7;   *****!!!! ALL TIMES IN MINUTES
    MedMedCycleTimeMinutes;    //      = 38;
    MedMedCycleTimeSeconds;
    MedMedCycleTimeMilliSeconds;
    MedMedCycleTime = 37;
    MedMedWashCycleTime = 14;
    MedMedWashCycleTimeSeconds = MedMedWashCycleTime * 60;
    MedMedWashCycleTimeMillis = MedMedWashCycleTime * 60 * 1000;
    MedMedRinseCycleTime = 17;
    MedMedRinseCycleTimeSeconds = MedMedRinseCycleTime * 60;
    MedMedRinseCycleTimeMillis = MedMedRinseCycleTime * 60 * 1000;
    MedMedSpinCycleTime = 7;
    MedMedSpinCycleTimeSeconds = MedMedSpinCycleTime * 60;
    MedMedSpinCycleTimeMillis = MedMedSpinCycleTime * 60 * 1000;

    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      MedMedCycleTimeMinutes = 37;
      MedMedCycleTimeSeconds = MedMedCycleTimeMinutes * 60;
      //HighCycleTimeMilliSeconds = HighCycleTimeSeconds * 1000;

      CycleSetTime = MedMedCycleTimeSeconds;

      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;
      //
      //      CycleResetTime1 = MedMedWashCycleTimeMillis;
      //      CycleResetTime2 = MedMedWashCycleTimeMillis + MedMedRinseCycleTimeMillis;
      //      CycleResetTime3 = MedMedWashCycleTimeMillis + MedMedRinseCycleTimeMillis + MedMedSpinCycleTimeMillis;

      CycleResetTime1 = MedMedWashCycleTimeMillis;
      CycleResetTime2 = MedMedRinseCycleTimeMillis;
      CycleResetTime3 = MedMedSpinCycleTimeMillis;

      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (MedMedCycleTimeMinutes >= 1) {

        if (MedMedCycleTimeSeconds >= 59) {   // || (MedMedCycleTimeSeconds >= 60)){

          MedMedCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }

      MedMedCycleTimeSeconds = MedMedCycleTimeSeconds - CycleSeconds;
      MedMedCycleTimeMinutes = MedMedCycleTimeMinutes - CycleMinutes;

    }


    if (QuikSelectRunningState == LOW) {

      if (MedMedCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(MedMedCycleTimeMinutes, DEC) + ":" + String(MedMedCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }
      if (MedMedCycleTimeSeconds <= 9) {
        DisplayTime = "Time Left: " + String(MedMedCycleTimeMinutes, DEC) + ":0" + String(MedMedCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }


      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);
    }

    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = MedMedWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMedMedWashCycleTimeSeconds = MedMedWashCycleTimeMillis / 1000;
        QuikMedMedWashCycleTimeMinutes = QuikMedMedWashCycleTimeSeconds / 60;

        if (QuikMedMedWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MedMedCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMedMedWashCycleTimeMinutes = MedMedWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMedMedWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMedMedWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {
        QuikRinsing();
        QuikCycleSetTime = MedMedRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMedMedRinseCycleTimeSeconds = MedMedRinseCycleTimeMillis / 1000;
        QuikMedMedRinseCycleTimeMinutes = QuikMedMedRinseCycleTimeSeconds / 60;

        if (QuikMedMedRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MedMedCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMedMedRinseCycleTimeMinutes = MedMedRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMedMedRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMedMedRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = MedMedSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikMedMedSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikMedMedSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MedMedCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMedMedSpinCycleTimeMinutes = QuikMedMedSpinCycleTimeMinutes - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMedMedSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikMedMedSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }

  }
}
////***********************************************
////***********************************************
////          MEDIUM LOW CYCLE
//
void MedLowSelCycle() {
  //
  ////LCDprint();
  //  CheckInputStates();
  //CycleTimer();
  //WashLoadSelect();

  if (MedLow == HIGH) {

    MedLowCycle;     //  = 34;= Total = 34, Wash = 12, Rinse = 15, Spin = 7;   *****!!!! ALL TIMES IN MINUTES
    MedLowCycleTimeMinutes = 33;
    MedLowCycleTimeSeconds;
    MedLowCycleTimeMilliSeconds;
    MedLowWashCycleTime = 12;
    MedLowWashCycleTimeSeconds = MedLowWashCycleTime * 60;
    MedLowWashCycleTimeMillis = MedLowWashCycleTime * 60 * 1000;
    MedLowRinseCycleTime = 15;
    MedLowRinseCycleTimeSeconds = MedLowRinseCycleTime * 60;
    MedLowRinseCycleTimeMillis = MedLowRinseCycleTime * 60 * 1000;
    MedLowSpinCycleTime = 7;
    MedLowSpinCycleTimeSeconds = MedLowSpinCycleTime * 60;
    MedLowSpinCycleTimeMillis = MedLowSpinCycleTime * 60 * 1000;

    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      MedLowCycleTimeMinutes = 33;
      MedLowCycleTimeSeconds = MedLowCycleTimeMinutes * 60;
      //MedLowCycleTimeMilliSeconds = MedLowCycleTimeSeconds * 1000;

      CycleSetTime = MedLowCycleTimeSeconds;


      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;

      CycleResetTime1 = MedLowWashCycleTimeMillis;
      CycleResetTime2 = MedLowWashCycleTimeMillis + MedLowRinseCycleTimeMillis;
      CycleResetTime3 = MedLowWashCycleTimeMillis + MedLowRinseCycleTimeMillis + MedLowSpinCycleTimeMillis;

      CycleResetTime1 = MedLowWashCycleTimeMillis;
      CycleResetTime2 = MedLowRinseCycleTimeMillis;
      CycleResetTime3 = MedLowSpinCycleTimeMillis;

      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (MedLowCycleTimeMinutes >= 1) {

        if (MedLowCycleTimeSeconds >= 59) {   // || (MedLowCycleTimeSeconds >= 60)){

          MedLowCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }

      MedLowCycleTimeSeconds = MedLowCycleTimeSeconds - CycleSeconds;
      MedLowCycleTimeMinutes = MedLowCycleTimeMinutes - CycleMinutes;

    }

    if (QuikSelectRunningState == LOW) {

      if (MedLowCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(MedLowCycleTimeMinutes, DEC) + ":" + String(MedLowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }
      if (MedLowCycleTimeSeconds <= 9) {
        DisplayTime = "Time Left: " + String(MedLowCycleTimeMinutes, DEC) + ":0" + String(MedLowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }


      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);
    }

    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = MedLowWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMedLowWashCycleTimeSeconds = MedLowWashCycleTimeMillis / 1000;
        QuikMedLowWashCycleTimeMinutes = QuikMedLowWashCycleTimeSeconds / 60;

        if (QuikMedLowWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MedLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMedLowWashCycleTimeMinutes = MedLowWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMedLowWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMedLowWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {
        QuikRinsing();
        QuikCycleSetTime = MedLowRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikMedLowRinseCycleTimeSeconds = MedLowRinseCycleTimeMillis / 1000;
        QuikMedLowRinseCycleTimeMinutes = QuikMedLowRinseCycleTimeSeconds / 60;

        if (QuikMedLowRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MedLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMedLowRinseCycleTimeMinutes = MedLowRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMedLowRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikMedLowRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = MedLowSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikMedLowSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikMedLowSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (MedLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikMedLowSpinCycleTimeMinutes = QuikMedLowSpinCycleTimeMinutes - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikMedLowSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikMedLowSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }

  }
}
////***********************************************
////***********************************************
////          LOW CYCLE
//
void LowSelCycle() {
  //
  ////LCDprint();
  //  CheckInputStates();
  //CycleTimer();
  //WashLoadSelect();

  if (Low == HIGH) {


    LowCycle;        //  = 28;= Total = 28, Wash = 8, Rinse = 12, Spin = 8;    *****!!!! ALL TIMES IN MINUTES
    LowCycleTimeMinutes = 27;
    LowCycleTimeSeconds;
    LowCycleTimeMilliSeconds;
    LowWashCycleTime = 8;
    LowWashCycleTimeSeconds = LowWashCycleTime * 60;
    LowWashCycleTimeMillis = LowWashCycleTime * 60 * 1000;
    LowRinseCycleTime = 12;
    LowRinseCycleTimeSeconds = LowRinseCycleTime * 60;
    LowRinseCycleTimeMillis = LowRinseCycleTime * 60 * 1000;
    LowSpinCycleTime = 8;
    LowSpinCycleTimeSeconds = LowSpinCycleTime * 60;
    LowSpinCycleTimeMillis = LowSpinCycleTime * 60 * 1000;

    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      LowCycleTimeMinutes = 27;
      LowCycleTimeSeconds = LowCycleTimeMinutes * 60;
      //HighCycleTimeMilliSeconds = HighCycleTimeSeconds * 1000;

      CycleSetTime = LowCycleTimeSeconds;

      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;
      //
      //      CycleResetTime1 = LowWashCycleTimeMillis;
      //      CycleResetTime2 = LowWashCycleTimeMillis + LowRinseCycleTimeMillis;
      //      CycleResetTime3 = LowWashCycleTimeMillis + LowRinseCycleTimeMillis + LowSpinCycleTimeMillis;

      CycleResetTime1 = LowWashCycleTimeMillis;
      CycleResetTime2 = LowRinseCycleTimeMillis;
      CycleResetTime3 = LowSpinCycleTimeMillis;

      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (LowCycleTimeMinutes >= 1) {

        if (LowCycleTimeSeconds >= 59) {   // || (LowCycleTimeSeconds >= 60)){

          LowCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }

      LowCycleTimeSeconds = LowCycleTimeSeconds - CycleSeconds;
      LowCycleTimeMinutes = LowCycleTimeMinutes - CycleMinutes;

    }

    if (QuikSelectRunningState == LOW) {

      if (LowCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(LowCycleTimeMinutes, DEC) + ":" + String(LowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }
      if (LowCycleTimeSeconds <= 9) {
        DisplayTime = "Time Left: " + String(LowCycleTimeMinutes, DEC) + ":0" + String(LowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }


      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);
    }

    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = LowWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikLowWashCycleTimeSeconds = LowWashCycleTimeMillis / 1000;
        QuikLowWashCycleTimeMinutes = QuikLowWashCycleTimeSeconds / 60;

        if (QuikLowWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (LowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikLowWashCycleTimeMinutes = LowWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikLowWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikLowWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {
        QuikRinsing();
        QuikCycleSetTime = LowRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikLowRinseCycleTimeSeconds = LowRinseCycleTimeMillis / 1000;
        QuikLowRinseCycleTimeMinutes = QuikLowRinseCycleTimeSeconds / 60;

        if (QuikLowRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (LowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikLowRinseCycleTimeMinutes = LowRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikLowRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikLowRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = LowSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikLowSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikLowSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (LowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikLowSpinCycleTimeMinutes = QuikLowSpinCycleTimeMinutes - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikLowSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikLowSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }

  }
}
////***********************************************
////***********************************************
////          VERY LOW CYCLE
//
void VeryLowSelCycle() {
  //
  ////LCDprint();
  //  CheckInputStates();
  //CycleTimer();
  //WashLoadSelect();

  if (VeryLow == HIGH) {


    VeryLowCycle;   //  = 25;= Total = 25, Wash = 7, Rinse = 12, Spin = 6;    *****!!!! ALL TIMES IN MINUTES
    VeryLowCycleTimeMinutes = 24;
    VeryLowCycleTimeSeconds;
    VeryLowCycleTimeMilliSeconds;
    VeryLowCycleTime = 25;
    VeryLowWashCycleTime = 7;
    VeryLowWashCycleTimeSeconds = VeryLowWashCycleTime * 60;
    VeryLowWashCycleTimeMillis = VeryLowWashCycleTime * 60 * 1000;
    VeryLowRinseCycleTime = 12;
    VeryLowRinseCycleTimeSeconds = VeryLowRinseCycleTime * 60;
    VeryLowRinseCycleTimeMillis = VeryLowRinseCycleTime * 60 * 1000;
    VeryLowSpinCycleTime = 6;
    VeryLowSpinCycleTimeSeconds = VeryLowSpinCycleTime * 60;
    VeryLowSpinCycleTimeMillis = VeryLowSpinCycleTime * 60 * 1000;


    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      VeryLowCycleTimeMinutes = 24;
      VeryLowCycleTimeSeconds = VeryLowCycleTimeMinutes * 60;
      //HighCycleTimeMilliSeconds = HighCycleTimeSeconds * 1000;

      CycleSetTime = VeryLowCycleTimeSeconds;

      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;
      //
      //      CycleResetTime1 = VeryLowWashCycleTimeMillis;
      //      CycleResetTime2 = VeryLowWashCycleTimeMillis + VeryLowRinseCycleTimeMillis;
      //      CycleResetTime3 = VeryLowWashCycleTimeMillis + VeryLowRinseCycleTimeMillis + VeryLowSpinCycleTimeMillis;

      CycleResetTime1 = VeryLowWashCycleTimeMillis;
      CycleResetTime2 = VeryLowRinseCycleTimeMillis;
      CycleResetTime3 = VeryLowSpinCycleTimeMillis;

      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (VeryLowCycleTimeMinutes >= 1) {

        if (VeryLowCycleTimeSeconds >= 59) {   // || (VeryLowCycleTimeSeconds >= 60)){

          VeryLowCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }

      VeryLowCycleTimeSeconds = VeryLowCycleTimeSeconds - CycleSeconds;
      VeryLowCycleTimeMinutes = VeryLowCycleTimeMinutes - CycleMinutes;

    }

    if (QuikSelectRunningState == LOW) {

      if (VeryLowCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(VeryLowCycleTimeMinutes, DEC) + ":" + String(VeryLowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }
      if (VeryLowCycleTimeSeconds <= 9) {
        DisplayTime = "Time Left: " + String(VeryLowCycleTimeMinutes, DEC) + ":0" + String(VeryLowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }

      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);
    }

    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = VeryLowWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikVeryLowWashCycleTimeSeconds = VeryLowWashCycleTimeMillis / 1000;
        QuikVeryLowWashCycleTimeMinutes = QuikVeryLowWashCycleTimeSeconds / 60;

        if (QuikVeryLowWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (VeryLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikVeryLowWashCycleTimeMinutes = VeryLowWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikVeryLowWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikVeryLowWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {
        QuikRinsing();
        QuikCycleSetTime = VeryLowRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikVeryLowRinseCycleTimeSeconds = VeryLowRinseCycleTimeMillis / 1000;
        QuikVeryLowRinseCycleTimeMinutes = QuikVeryLowRinseCycleTimeSeconds / 60;

        if (QuikVeryLowRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (VeryLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikVeryLowRinseCycleTimeMinutes = VeryLowRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikVeryLowRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikVeryLowRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = VeryLowSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikVeryLowSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikVeryLowSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (VeryLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikVeryLowSpinCycleTimeMinutes = QuikVeryLowSpinCycleTimeMinutes - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikVeryLowSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikVeryLowSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }

  }
}
////***********************************************
//
////***********************************************
////          EXTRA LOW CYCLE
//
void ExtraLowSelCycle() {
  //
  ////LCDprint();
  //  CheckInputStates();
  //CycleTimer();
  //WashLoadSelect();

  if (ExtraLow == HIGH) {



    ExtraLowCycle;   //  = 21;= Total = 21, Wash = 5, Rinse = 10, Spin = 6;    *****!!!! ALL TIMES IN MINUTES
    ExtraLowCycleTimeMinutes = 20;
    ExtraLowCycleTimeSeconds;
    ExtraLowCycleTimeMilliSeconds;
    ExtraLowWashCycleTime = 5;
    ExtraLowWashCycleTimeSeconds = (ExtraLowWashCycleTime * 60);
    ExtraLowWashCycleTimeMillis = (ExtraLowWashCycleTime * 60) * 1000;
    ExtraLowRinseCycleTime = 10;
    ExtraLowRinseCycleTimeSeconds = (ExtraLowRinseCycleTime * 60);
    ExtraLowRinseCycleTimeMillis = (ExtraLowRinseCycleTime * 60) * 1000;
    ExtraLowSpinCycleTime = 6;
    ExtraLowSpinCycleTimeSeconds = (ExtraLowSpinCycleTime * 60);
    ExtraLowSpinCycleTimeMillis = (ExtraLowSpinCycleTime * 60) * 1000;

    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      ExtraLowCycleTimeMinutes = 20;
      ExtraLowCycleTimeSeconds = ExtraLowCycleTimeMinutes * 60;
      //ExtraLowCycleTimeMilliSeconds = ExtraLowCycleTimeSeconds * 1000;

      CycleSetTime = ExtraLowCycleTimeSeconds;

      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;
      //
      //      CycleResetTime1 = ExtraLowWashCycleTimeMillis;
      //      CycleResetTime2 = ExtraLowWashCycleTimeMillis + ExtraLowRinseCycleTimeMillis;
      //      CycleResetTime3 = ExtraLowWashCycleTimeMillis + ExtraLowRinseCycleTimeMillis + ExtraLowSpinCycleTimeMillis;

      CycleResetTime1 = ExtraLowWashCycleTimeMillis;
      CycleResetTime2 = ExtraLowRinseCycleTimeMillis;
      CycleResetTime3 = ExtraLowSpinCycleTimeMillis;

      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (ExtraLowCycleTimeMinutes >= 1) {

        if (ExtraLowCycleTimeSeconds >= 59) {   // || (ExtraLowCycleTimeSeconds >= 60)){

          ExtraLowCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }

      ExtraLowCycleTimeSeconds = ExtraLowCycleTimeSeconds - CycleSeconds;
      ExtraLowCycleTimeMinutes = ExtraLowCycleTimeMinutes - CycleMinutes;

    }

    if (QuikSelectRunningState == LOW) {


      if (ExtraLowCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(ExtraLowCycleTimeMinutes, DEC) + ":" + String(ExtraLowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }

      if (ExtraLowCycleTimeSeconds <= 9) {
        DisplayTime = "Time Left: " + String(ExtraLowCycleTimeMinutes, DEC) + ":0" + String(ExtraLowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }

      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);
    }

    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = ExtraLowWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikExtraLowWashCycleTimeSeconds = ExtraLowWashCycleTimeMillis / 1000;
        QuikExtraLowWashCycleTimeMinutes = QuikExtraLowWashCycleTimeSeconds / 60;

        if (QuikExtraLowWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (ExtraLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikExtraLowWashCycleTimeMinutes = ExtraLowWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikExtraLowWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikExtraLowWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {
        QuikRinsing();
        QuikCycleSetTime = ExtraLowRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikExtraLowRinseCycleTimeSeconds = ExtraLowRinseCycleTimeMillis / 1000;
        QuikExtraLowRinseCycleTimeMinutes = QuikExtraLowRinseCycleTimeSeconds / 60;

        if (QuikExtraLowRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (ExtraLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikExtraLowRinseCycleTimeMinutes = ExtraLowRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikExtraLowRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikExtraLowRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = ExtraLowSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikExtraLowSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikExtraLowSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (ExtraLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikExtraLowSpinCycleTimeMinutes = QuikExtraLowSpinCycleTimeMinutes - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikExtraLowSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikExtraLowSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }



  }
}
////***********************************************
//***********************************************
//          ULTRA LOW CYCLE

void UltraLowSelCycle() {
  //
  ////LCDprint();
  //  CheckInputStates();
  //CycleTimer();
  //WashLoadSelect();

  if (UltraLow == HIGH) {

    UltraLowCycle;   //  = 15;= Total = 15, Wash = 5, Rinse = 8, Spin = 2;    *****!!!! ALL TIMES IN MINUTES
    UltraLowCycleTimeMinutes = 5; //14;
    UltraLowCycleTimeSeconds;
    UltraLowCycleTimeMilliSeconds;
    UltraLowCycleTime = 6;  //15;

    UltraLowWashCycleTime = 2;  //5;
    UltraLowWashCycleTimeSeconds = (UltraLowWashCycleTime * 60);
    UltraLowWashCycleTimeMillis = (UltraLowWashCycleTime * 60) * 1000;

    UltraLowRinseCycleTime = 2; //8;
    UltraLowRinseCycleTimeSeconds = (UltraLowRinseCycleTime * 60);
    UltraLowRinseCycleTimeMillis = (UltraLowRinseCycleTime * 60) * 1000;

    UltraLowSpinCycleTime = 2;  //2;
    UltraLowSpinCycleTimeSeconds = (UltraLowSpinCycleTime * 60);
    UltraLowSpinCycleTimeMillis = (UltraLowSpinCycleTime * 60) * 1000;


    RunningCycleTime = times - millis();

    if (QuikSelectRunningState == LOW) {

      RunningCycleTimeSeconds = RunningCycleTime / 1000;
      RunningCycleTimeMinutes = RunningCycleTimeSeconds / 60;
      seconds = RunningCycleTimeSeconds; //% 60;

      //int RunningCycleTimeSeconds;
      //int RunningCycleTimeMinutes;


      UltraLowCycleTimeMinutes = 5; //14;
      UltraLowCycleTimeSeconds = UltraLowCycleTimeMinutes * 60;
      //UltraLowCycleTimeMilliSeconds = UltraLowCycleTimeSeconds * 1000;

      CycleSetTime = UltraLowCycleTimeSeconds;

      //times = millis();
      //millisec = times % 100;
      tseconds = times / 1000;
      tminutes = tseconds / 60;
      //seconds = tseconds % 60;
      //seconds = tseconds;  // % 60;

      CycleProgressSetTime = CycleSetTime * 1000;

      NumberOfCycles = 3;

      EachCycleTime = CycleProgressSetTime / NumberOfCycles;
      //
      //      CycleResetTime1 = UltraLowWashCycleTimeMillis;
      //      CycleResetTime2 = UltraLowWashCycleTimeMillis + UltraLowRinseCycleTimeMillis;
      //      CycleResetTime3 = UltraLowWashCycleTimeMillis + UltraLowRinseCycleTimeMillis + UltraLowSpinCycleTimeMillis;

      CycleResetTime1 = UltraLowWashCycleTimeMillis;
      CycleResetTime2 = UltraLowRinseCycleTimeMillis;
      CycleResetTime3 = UltraLowSpinCycleTimeMillis;

      //      CycleResetTime1 = UltraLowWashCycleTimeSeconds;
      //      CycleResetTime2 = UltraLowWashCycleTimeSeconds + UltraLowRinseCycleTimeSeconds;
      //      CycleResetTime3 = UltraLowWashCycleTimeSeconds + UltraLowRinseCycleTimeSeconds + UltraLowSpinCycleTimeSeconds;


      CycleProgressSeconds = CycleProgress / 1000;
      CycleMinutes = CycleProgressSeconds / 60;
      CycleSeconds = CycleProgress / 1000;
      CycleSeconds = CycleSeconds % 60;


      if (UltraLowCycleTimeMinutes >= 1) {

        if (UltraLowCycleTimeSeconds >= 59) {   // || (UltraLowCycleTimeSeconds >= 60)){

          UltraLowCycleTimeSeconds = 59;

        }
      }

      if (CycleSeconds >= 60) {

        CycleSeconds = 1;
      }

      UltraLowCycleTimeSeconds = UltraLowCycleTimeSeconds - CycleSeconds;
      UltraLowCycleTimeMinutes = UltraLowCycleTimeMinutes - CycleMinutes;


      //    if (QuikSelectRunningState == HIGH) {

      if (UltraLowCycleTimeSeconds >= 10) {
        DisplayTime = "Time Left: " + String(UltraLowCycleTimeMinutes, DEC) + ":" + String(UltraLowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }

      if (UltraLowCycleTimeSeconds <= 9) {

        DisplayTime = "Time Left: " + String(UltraLowCycleTimeMinutes, DEC) + ":0" + String(UltraLowCycleTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
      }

      lcd.setCursor(0, 1);
      lcd.print(DisplayTime);

      //    }
    }
    //*****************************************************************
    //              QUIK CYCLE

    if (QuikSelectRunningState == HIGH) {

      QuikCycleProgressSeconds = QuikCycleProgress / 1000;

      QuikCycleSeconds = QuikCycleProgress / 1000;

      QuikCycleMinutes = QuikCycleProgressSeconds / 60;
      QuikCycleHours = QuikCycleMinutes / 60;

      //**********************************************************

      if (QuikWashRunning == HIGH) {
        QuikWashing();
        QuikCycleSetTime = UltraLowWashCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikUltraLowWashCycleTimeSeconds = UltraLowWashCycleTimeMillis / 1000;
        QuikUltraLowWashCycleTimeMinutes = QuikUltraLowWashCycleTimeSeconds / 60;

        if (QuikUltraLowWashCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (UltraLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikUltraLowWashCycleTimeMinutes = UltraLowWashCycleTime - QuikCycleMinutes - 1;


        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikUltraLowWashCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikUltraLowWashCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }

      //**********************************************************

      if (QuikRinseRunning == HIGH) {

        //        SelectedWaterLevel = 10;

        QuikRinsing();
        QuikCycleSetTime = UltraLowRinseCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;

        QuikUltraLowRinseCycleTimeSeconds = UltraLowRinseCycleTimeMillis / 1000;
        QuikUltraLowRinseCycleTimeMinutes = QuikUltraLowRinseCycleTimeSeconds / 60;

        if (QuikUltraLowRinseCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (UltraLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikUltraLowRinseCycleTimeMinutes = UltraLowRinseCycleTime - QuikCycleMinutes - 1;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikUltraLowRinseCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {

          DisplayTime = "Time Left: " + String(QuikUltraLowRinseCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);
      }

      //**********************************************************

      if (QuikSpinRunning == HIGH) {
        QuikSpinning();
        QuikCycleSetTime = UltraLowSpinCycleTimeMillis;

        PreviousQuikCycleSetTime = UltraLowSpinCycleTimeMillis;

        //        QuikCycleResetTime1 = QuikCycleSetTime;
        //        QuikCycleResetTime2 = QuikCycleSetTime + QuikCycleSetTime;
        //        QuikCycleResetTime3 = QuikCycleSetTime + QuikCycleSetTime + QuikCycleSetTime;

        QuikCycleResetTime1 = QuikCycleSetTime;
        QuikCycleResetTime2 = QuikCycleSetTime + 10000;
        QuikCycleResetTime3 = QuikCycleResetTime2 + 1000;


        QuikCycleProgressSeconds = QuikCycleProgress / 1000;
        QuikCycleMinutes = QuikCycleProgressSeconds / 60;
        QuikCycleSeconds = QuikCycleProgress / 1000;
        QuikCycleSeconds = QuikCycleSeconds % 60;
        //      QuikCycleMinutes = QuikCycleSeconds / 60;

        QuikUltraLowSpinCycleTimeMinutes = QuikCycleSetTime / 60000;    //      = 15;

        if (QuikUltraLowSpinCycleTimeMinutes >= 1) {
          if (QuikCycleSetTime >= 59) {   // || (UltraLowCycleTimeSeconds >= 60)){
            QuikCycleSetTime = 59;
          }
        }

        if (QuikCycleSetTime >= 60) {
          QuikCycleSetTime = 1;
        }

        QuikCycleSetTime = QuikCycleSetTime - QuikCycleSeconds;
        QuikUltraLowSpinCycleTimeMinutes = 1 - QuikCycleMinutes;

        if (QuikCycleSetTime >= 10) {
          DisplayTime = "Time Left: " + String(QuikUltraLowSpinCycleTimeMinutes, DEC) + ":" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        if (QuikCycleSetTime <= 9) {
          DisplayTime = "Time Left: " + String(QuikUltraLowSpinCycleTimeMinutes, DEC) + ":0" + String(QuikCycleSetTime, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
        }

        lcd.setCursor(0, 1);
        lcd.print(DisplayTime);

      }
    }
  }
}

//***********************************************
//***********************************************
//           QUIK CYCLEs

void QuikWashSelect() {


  if ((QuikWashPinState == LOW)) { // && (QuikRinseRunning == HIGH) && (QuikSpinRunning == HIGH)){

    PreviousQuikCycleSetTime = QuikCycleSetTime;
    QuikWashRunning = HIGH;
    QuikRinseRunning = LOW;
    QuikSpinRunning = LOW;
    QuikCycleStartTime = millis();
    //    digitalWrite(TonebuzzerPin, HIGH);

    digitalWrite(QuikWashLedPin, HIGH);
    digitalWrite(QuikRinseLedPin, LOW);
    digitalWrite(QuikSpinLedPin, LOW);

    QuikSelectRunningState = HIGH;
    lcd.setCursor(0, 0);
    lcd.print("   QUIK WASH    ");
  }
}

//*********************************
void QuikRinseSelect() {


  if ((QuikRinsePinState == LOW)) { // && (QuikWashRunning == HIGH) && (QuikSpinRunning == HIGH)){

    PreviousQuikCycleSetTime = QuikCycleSetTime;
    QuikRinseRunning = HIGH;
    QuikWashRunning = LOW;
    QuikSpinRunning = LOW;
    QuikCycleStartTime = millis();
    //    digitalWrite(TonebuzzerPin, HIGH);

    digitalWrite(QuikRinseLedPin, HIGH);
    digitalWrite(QuikWashLedPin, LOW);
    digitalWrite(QuikSpinLedPin, LOW);

    QuikSelectRunningState = HIGH;
    QuikSelectRunningState = HIGH;
    lcd.setCursor(0, 0);
    lcd.print("   QUIK RINSE    ");
  }
}

//*********************************
void QuikSpinSelect() {


  if ((QuikSpinPinState == LOW)) { // && (QuikWashRunning == HIGH) && (QuikRinseRunning == HIGH)){

    PreviousQuikCycleSetTime = QuikCycleSetTime;
    QuikSpinRunning = HIGH;
    QuikWashRunning = LOW;
    QuikRinseRunning = LOW;
    QuikCycleStartTime = millis();
    //    digitalWrite(TonebuzzerPin, HIGH);

    //QuikCycleSetTime = QuikCycleSetTime;
    digitalWrite(QuikSpinLedPin, HIGH);
    digitalWrite(QuikRinseLedPin, LOW);
    digitalWrite(QuikWashLedPin, LOW);

    QuikSelectRunningState = HIGH;
    lcd.setCursor(0, 0);
    lcd.print("   QUIK SPIN    ");
  }
}

//***********************************************

void QuikWashing() {
  CheckInputStates();

    QuikWashingFilling = false;

  QuikSpinPulseStartTime = millis();
  //    QuikBuzzerPulseStartTime = millis();
  //    QuikBuzzerStartTime = millis();
  QuikWashPulseTimer();

  if (QuikCycleStage1 == HIGH) {

    if ((QuikSpinRunning == LOW)) {

      if (QuikSelectRunningState == HIGH) {


        if (QuikWashPulseForState == HIGH) {

          MotorForDir();

        }

        if (QuikWashPulseStopState == HIGH) {

          MotorStop();

        }

        if (QuikWashPulseRevState == HIGH) {

          MotorRevDir();

        }

        lcd.setCursor(2, 0);
        lcd.print("QUIKWASHING");

      }
    }
  }
}

//***********************************************

void QuikRinsing() {
  CheckInputStates();

  QuikWashPulseTimer();

QuikRinsingFilling = false;
  
  //    QuikBuzzerPulseStartTime = millis();
  //    QuikBuzzerStartTime = millis();
  if (QuikCycleStage1 == HIGH) {
    if ((QuikSpinRunning == LOW)) {
      if (QuikSelectRunningState == HIGH) {

        if (QuikWashPulseForState == HIGH) {

          MotorForDir();

        }

        if (QuikWashPulseState == LOW) {

          MotorStop();

        }

        if (QuikWashPulseRevState == HIGH) {

          MotorRevDir();

        }

        lcd.setCursor(2, 0);
        lcd.print("QUIKRINSING");



        //      Serial.println("");
        //      Serial.print("QuikRinseProgress :");
        //      Serial.print(QuikRinseProgress);
        //      Serial.println("");
        //
        //          Serial.println("");
        //          Serial.print("QuikRinsePulseProgress :");
        //          Serial.print(QuikRinsePulseProgress);
        //          Serial.println("");
      }
    }
  }

  
}


//***********************************************

void QuikSpinning() {
  CheckInputStates();

  QuikSpinPulseTimer();
  //    QuikBuzzerPulseStartTime = millis();
  //    QuikBuzzerStartTime = millis();
  if (QuikCycleStage1 == HIGH) {

    if ((QuikWashRunning == LOW)) {

      if (QuikSelectRunningState == HIGH) {

        if (QuikSpinPulseState == HIGH) {

          MotorSpinForDir();

        }
        //else

        if (QuikSpinPulseState == LOW) {

          MotorStop();

        }

        lcd.setCursor(2, 0);
        lcd.print("QUIKSPINNING");



        //      Serial.println("");
        //      Serial.print("QuikSpinProgress :");
        //      Serial.print(QuikSpinProgress);
        //      Serial.println("");
        //
        //          Serial.println("");
        //          Serial.print("QuikSpinPulseProgress :");
        //          Serial.print(QuikSpinPulseProgress);
        //          Serial.println("");
      }
    }
  }
}

//***********************************************



////***********************************************
//              COURSE SELECT

void CourseSelection() {

  WashLoadSelect();
  //  LCDprint();
  MathCycleTimes();
  CheckInputStates();

  // compare the buttonState to its previous state
  if (CoursePinState != CourselastButtonState) {
    // if the state has changed, increment the counter
    if (CoursePinState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      CoursebuttonPushCounter++;
      //      Serial.println("on");
      //      Serial.print("number of button pushes: ");
      //      Serial.println(CoursebuttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      //      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(5);
  }
  // save the current state as the last state, for next time through the loop
  CourselastButtonState = CoursePinState;


  if (CoursebuttonPushCounter == 1) {
    digitalWrite(DigitalLedPin, HIGH);
  } else {
    digitalWrite(DigitalLedPin, LOW);
  }

  if (CoursebuttonPushCounter == 2) {
    digitalWrite(SoakLedPin, HIGH);
  } else {
    digitalWrite(SoakLedPin, LOW);
  }

  if (CoursebuttonPushCounter == 3) {
    digitalWrite(SpeedyLedPin, HIGH);
  } else {
    digitalWrite(SpeedyLedPin, LOW);
  }

  if (CoursebuttonPushCounter == 4) {
    digitalWrite(WoolLedPin, HIGH);
  } else {
    digitalWrite(WoolLedPin, LOW);
  }

  if (CoursebuttonPushCounter == 5) {
    digitalWrite(ECOLedPin, HIGH);
  } else {
    digitalWrite(ECOLedPin, LOW);
  }

  if (CoursebuttonPushCounter == 6) {
    digitalWrite(HeavyBlanketLedPin, HIGH);
  } else {
    digitalWrite(HeavyBlanketLedPin, LOW);
  }

  if (CoursebuttonPushCounter == 7) {
    CoursebuttonPushCounter = 1;
  }

}

////***********************************************

//***********************************************

void Rinseing() {


}
//***********************************************

void SpeedWashing() {


}
//***********************************************

void EcoWashing() {


}
//***********************************************
void DelayActiveState() {

  //DelaySelection();
  //  CheckInputStates();
  //
  //if (DelayPinState == LOW){
  //DelayActive = HIGH;
  //}

}

////***********************************************
//              DELAY SELECT

void DelaySelection() {

  if (DelayActive == HIGH) {

    WashLoadSelect();
    //  LCDprint();
    MathCycleTimes();
    CheckInputStates();


    // compare the buttonState to its previous state
    if (DelayPinState != DelaylastButtonState) {
      // if the state has changed, increment the counter
      if (DelayPinState == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        DelaybuttonPushCounter++;
        //      Serial.println("on");
        //      Serial.print("number of button pushes: ");
        //      Serial.println(DelaybuttonPushCounter);
      } else {
        // if the current state is LOW then the button went from on to off:
        //      Serial.println("off");
      }
      // Delay a little bit to avoid bouncing
      delay(5);
    }
    // save the current state as the last state, for next time through the loop
    DelaylastButtonState = DelayPinState;

    if (DelaybuttonPushCounter == 1) {

      DelayStage8 = LOW;
      DelayStage1 = HIGH;
      //  } else {
      //DelayStage1 = LOW;
    }

    if (DelaybuttonPushCounter == 2) {

      DelayStage1 = LOW;
      DelayStage2 = HIGH;
      //  } else {
      //DelayStage2 = LOW;
    }

    if (DelaybuttonPushCounter == 3) {

      DelayStage2 = LOW;
      DelayStage3 = HIGH;
      //  } else {
      //DelayStage3 = LOW;
    }

    if (DelaybuttonPushCounter == 4) {

      DelayStage3 = LOW;
      DelayStage4 = HIGH;
      //  } else {
      //DelayStage4 = LOW;
    }

    if (DelaybuttonPushCounter == 5) {

      DelayStage4 = LOW;
      DelayStage5 = HIGH;
      //  } else {
      //DelayStage5 = LOW;
    }

    if (DelaybuttonPushCounter == 6) {

      DelayStage5 = LOW;
      DelayStage6 = HIGH;
      //  } else {
      //DelayStage6 = LOW;
    }

    if (DelaybuttonPushCounter == 7) {

      DelayStage6 = LOW;
      DelayStage7 = HIGH;
      //  } else {
      //DelayStage7 = LOW;
    }

    if (DelaybuttonPushCounter == 8) {

      DelayStage7 = LOW;
      DelayStage8 = HIGH;
      //  } else {
      //DelayStage8 = LOW;
    }

    //    if (DelaybuttonPushCounter == 9) {
    //
    //      DelayStage8 = LOW;
    //      DelayStage9 = HIGH;
    //      //  } else {
    //      //DelayStage9 = LOW;
    //    }
    //
    //    if (DelaybuttonPushCounter == 10) {
    //
    //      DelayStage9 = LOW;
    //      DelayStage10 = HIGH;
    //      //  } else {
    //      //DelayStage10 = LOW;
    //    }
    //
    //    if (DelaybuttonPushCounter == 11) {
    //
    //      DelayStage10 = LOW;
    //      DelayStage11 = HIGH;
    //      //  } else {
    //      //DelayStage11 = LOW;
    //    }
    //
    //    if (DelaybuttonPushCounter == 12) {
    //
    //      DelayStage11 = LOW;
    //      DelayStage12 = HIGH;
    //      //  } else {
    //      //DelayStage12 = LOW;
    //    }

    if (DelaybuttonPushCounter == 9) {
      DelayStage8 = LOW;
      DelaybuttonPushCounter = 1;
    }

    //************************************************************************
    //int DelayDispTimeSeconds;
    //int DelayDispTimeMinutes;
    //int DelayDispTimeHours;
    //DelayTime



    if (DelayStage1 == HIGH) {

      DelaySetTime = 3599000;  // 3600;  //3600000;
    }

    if (DelayStage2 == HIGH) {

      DelaySetTime =  7199000;

    }

    if (DelayStage3 == HIGH) {

      DelaySetTime =  10799900;

    }

    if (DelayStage4 == HIGH) {

      DelaySetTime =  14399000;

    }

    if (DelayStage5 == HIGH) {

      DelaySetTime =  17999000;

    }

    if (DelayStage6 == HIGH) {

      DelaySetTime =  21599000;

    }

    if (DelayStage7 == HIGH) {

      DelaySetTime =  25199000;

    }

    if (DelayStage8 == HIGH) {

      DelaySetTime =  28799000;

    }

    //    if (DelayStage9 == HIGH) {
    //
    //      DelaySetTime =  32399000;
    //
    //    }
    //
    //    if (DelayStage10 == HIGH) {
    //
    //      DelaySetTime =  35999000;
    //
    //    }
    //
    //    if (DelayStage11 == HIGH) {
    //
    //      DelaySetTime =  39599000;
    //
    //    }
    //
    //    if (DelayStage12 == HIGH) {
    //
    //      DelaySetTime =  43199000;
    //
    //    }

    DelayTime = DelaySetTime;

    DelaySetTimeSeconds = DelaySetTime / 1000;
    DelaySetTimeMinutes = DelaySetTimeSeconds / 60;
    DelaySetTimeHours = DelaySetTimeMinutes / 60;
    DelaySetTimeSeconds = DelaySetTimeSeconds % 60;
    DelaySetTimeMinutes = DelaySetTimeMinutes % 60;

    DelayTimeSeconds = DelayProgress / 1000;
    DelayTimeMinutes = DelayTimeSeconds / 60 ;
    DelayTimeHours = DelayTimeMinutes / 60;
    DelayTimeSeconds = DelayTimeSeconds % 60;
    DelayTimeMinutes = DelayTimeMinutes % 60 ;

    if (DelayTimeSeconds >= 60) {

      DelayTimeSeconds = 0;
    }

    if (DelayTimeMinutes >= 60) {

      DelayTimeSeconds = 0;
    }


    DelayDispTimeSeconds = DelaySetTime / 1000;
    DelayDispTimeMinutes = DelayDispTimeSeconds / 60;
    DelayDispTimeHours = DelayDispTimeMinutes / 60;
    DelayDispTimeSeconds = DelayDispTimeSeconds % 60;
    DelayDispTimeMinutes = DelayDispTimeMinutes % 60;

    if (DelayDispTimeHours >= 1) {
      if (DelayDispTimeMinutes >= 60) {
        DelayDispTimeMinutes = 59;
      }

      DelayDispTimeMinutes = DelaySetTimeMinutes - DelayTimeMinutes;

    }

    if (DelayDispTimeMinutes >= 60) {
      DelayDispTimeMinutes = 59;
    }

    DelayDispTimeMinutes = DelaySetTimeMinutes - DelayTimeMinutes;

    if (DelayDispTimeMinutes >= 1) {
      if (DelayDispTimeSeconds >= 60) {
        DelayDispTimeSeconds = 59;
      }

      if (DelayDispTimeSeconds <= -1) {
        DelayDispTimeSeconds = 59;
      }

      DelayDispTimeSeconds = DelaySetTimeSeconds - DelayTimeSeconds;

    }

    if (DelayDispTimeSeconds <= -1) {
      DelayDispTimeSeconds = 59;
    }

    DelayDispTimeSeconds = DelaySetTimeSeconds - DelayTimeSeconds;

    if (DelayDispTimeSeconds >= 10) {
      DisplayDelayTime = "Delay:  " + String(DelayDispTimeHours, DEC) + ":"  + String(DelayDispTimeMinutes, DEC) + ":" + String(DelayDispTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
    }

    if (DelayDispTimeSeconds <= 9) {
      DisplayDelayTime = "Delay:  " + String(DelayDispTimeHours, DEC) + ":" + String(DelayDispTimeMinutes, DEC) + ":0" + String(DelayDispTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
    }

    if ((DelayDispTimeMinutes >= 10) && (DelayDispTimeSeconds <= 9)) {
      DisplayDelayTime = "Delay:  " + String(DelayDispTimeHours, DEC) + ":"  + String(DelayDispTimeMinutes, DEC) + ":0" + String(DelayDispTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
    }

    if ((DelayDispTimeMinutes <= 9) && (DelayDispTimeSeconds >= 10)) {
      DisplayDelayTime = "Delay:  " + String(DelayDispTimeHours, DEC) + ":0"  + String(DelayDispTimeMinutes, DEC) + ":" + String(DelayDispTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
    }

    if ((DelayDispTimeSeconds <= 9) && (DelayDispTimeMinutes <= 9)) {
      DisplayDelayTime = "Delay:  " + String(DelayDispTimeHours, DEC) + ":0" + String(DelayDispTimeMinutes, DEC) + ":0" + String(DelayDispTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
    }

    //        if (DelayDispTimeHours >= 10) {
    //          DisplayDelayTime = "Delay: 0" + String(DelayDispTimeHours, DEC) + ":"  + String(DelayDispTimeMinutes, DEC) + ":" + String(DelayDispTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
    //        }
    //
    //        if (DelayDispTimeHours <= 9) {
    //          DisplayDelayTime = "Delay: 0" + String(DelayDispTimeHours, DEC) + ":"  + String(DelayDispTimeMinutes, DEC) + ":" + String(DelayDispTimeSeconds, DEC) + "  ";   // + ":" + String(millisec,DEC) + "  ";
    //        }

    lcd.setCursor(0, 0);
    lcd.print(DisplayDelayTime);

  }
}

////***********************************************

void setup() {
  // put your setup code here, to run once:

  lcd.init();
  lcd.backlight();

  Serial.begin(115200);

  //************************************************************

  pinMode (PowerOnPin, INPUT_PULLUP);
  pinMode (StartPausePin, INPUT);
  pinMode (StopPin, INPUT);

  //  pinMode (DirForPin, INPUT_PULLUP);   // For Testing
  //  pinMode (DirRevPin, INPUT_PULLUP);   // For Testing

  pinMode (DoorSwPin, INPUT_PULLUP);
  //  pinMode (VolumeMedPin, INPUT_PULLUP);
  //  pinMode (VolumeHighPin, INPUT_PULLUP);

  pinMode (WaterSupplyPin, INPUT_PULLUP);
  pinMode (WaterLevelPin, INPUT_PULLUP);
  pinMode (QuikWashPin, INPUT_PULLUP);
  pinMode (QuikRinsePin, INPUT_PULLUP);
  pinMode (QuikSpinPin, INPUT_PULLUP);
  pinMode (SoakPin, INPUT_PULLUP);
  pinMode (SuperWashPin, INPUT_PULLUP);
  pinMode (CoursePin, INPUT_PULLUP);
  pinMode (DelayPin, INPUT_PULLUP);

  pinMode (buzzerPin, OUTPUT);
  pinMode (TonebuzzerPin, OUTPUT);

  pinMode (ForRevDRVRelayPin, OUTPUT);      // LEFT MOTOR

  pinMode (ForRelayPin, OUTPUT);      // LEFT MOTOR
  pinMode (RevRelayPin, OUTPUT);      // RIGHT MOTOR
  pinMode (SP1RelayPin, OUTPUT);      // RIGHT MOTOR
  pinMode (SP2RelayPin, OUTPUT);      // RIGHT MOTOR

  pinMode (MainMotorOnOff, OUTPUT);      // RIGHT MOTOR
  

  pinMode (HotSolRelayPin, OUTPUT);
  pinMode (ColdSolRelayPin, OUTPUT);
  pinMode (DetergentSolRelayPin, OUTPUT);

  pinMode (BrakeRelayPin, OUTPUT);
  pinMode (DrainPumpRelayPin, OUTPUT);

  pinMode (StopRedLedPin, OUTPUT);
  pinMode (RunGrnLedPin, OUTPUT);
  pinMode (PowerBluLedPin, OUTPUT);

  pinMode (MaximumLedPin, OUTPUT);
  pinMode (HighLedPin, OUTPUT);
  pinMode (MedHighLedPin, OUTPUT);
  pinMode (MediumLedPin, OUTPUT);
  pinMode ( MedMedLedPin, OUTPUT);
  pinMode (MedLowLedPin, OUTPUT);
  pinMode (LowLedPin, OUTPUT);
  pinMode (VeryLowLedPin, OUTPUT);
  pinMode ( ExtraLowLedPin, OUTPUT);
  pinMode (UltraLowLedPin, OUTPUT);

  pinMode (ColdBluLedPin, OUTPUT);
  pinMode (HotRedLedPin, OUTPUT);


  pinMode (DigitalLedPin, OUTPUT);
  pinMode (SoakLedPin, OUTPUT);
  pinMode (SpeedyLedPin, OUTPUT);
  pinMode (WoolLedPin, OUTPUT);
  pinMode (ECOLedPin, OUTPUT);
  pinMode (HeavyBlanketLedPin, OUTPUT);

  digitalWrite(SP1RelayPin, HIGH);
  digitalWrite(SP2RelayPin, HIGH);
  digitalWrite(RevRelayPin, LOW);
  digitalWrite(ForRelayPin, LOW);
  digitalWrite(ForRevDRVRelayPin, LOW);

  digitalWrite(MainMotorOnOff, HIGH);

  SerialPrintStartTime = millis();
  LCDPrintStartTime = millis();

  //  CycleStartTime = millis();
  //  WashStartTime = millis();
  //  WashPulseStartTime = millis();
  //  SpinStartTime = millis();
  //  SpinPulseStartTime = millis();

  //  QuikCycleStartTime = millis();
  //  QuikWashStartTime = millis();
  //  QuikWashPulseStartTime = millis();
  //  QuikRinseStartTime = millis();
  //  QuikRinsePulseStartTime = millis();
  //  QuikSpinStartTime = millis();
  //  QuikSpinPulseStartTime = millis();

  //  SoakStartTime = millis();
  //  RinseStartTime = millis();

  //  DelayStartTime = millis();
  //  DrainPumpStartTime = millis();

  StopStartTime = millis();

  //StopCycle();

  WaterSupplybuttonPushCounter = 1;
  CoursebuttonPushCounter = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hallo, Celinda");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("Initializing.");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Initializing..");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Initializing....");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("     Done !!!   ");
    digitalWrite(TonebuzzerPin, HIGH);
  delay(2000);
    digitalWrite(TonebuzzerPin, LOW);
}

//***********************************************************************************************


void loop() {
  // put your main code here, to run repeatedly:

//    if ((SpinPulseState == HIGH) && (BigSpinState == LOW)) {
//
//analogWrite(DriveSpeedPin ,DriveSpeedSpinning);
//  digitalWrite(RevRelayPin, LOW);
//  digitalWrite(ForRelayPin, HIGH);
////    digitalWrite(BrakeRelayPin, HIGH);
//    }
//    
// if ((SpinPulseState == LOW) && (BigSpinState == LOW)){
//  
//analogWrite(DriveSpeedPin ,0);
//  digitalWrite(ForRelayPin, LOW);
//
//
//}
MotorSpinPulseForDir();


//WaterLevel = map(cap1.Measure(), 0, 100, 0, 100);

//WaterLevel = WaterLevel * 5;


//
//MotorTemp = analogRead(MotorTempPin);
//
//MotorTemp = MotorTemp * 0.5;

//Voltage = MotorTemp * (5000 / 1024.0);
//Temperature = (Voltage - 500);


  CycleResetTime4 = CycleResetTime3 + 1000;
  QuikCycleResetTime2 = QuikCycleResetTime1 + 1000;

  //  if (QuikCycleProgress <= QuikCycleResetTime1) {
  //    QuikBuzzerPulseStartTime = millis();
  //    QuikBuzzerStartTime = millis();
  //  }

 MotorRunningCheck();  
  RinsDrainEmpty();
  RinseWaterReady();
  WashDrain();
  WaterLevelControl();
  
  StopTimer();
  HotColdSelect();
  WashLoadSelect();

  
//  WaterLevelControl();

  
  //  LCDprint();
  
  MathCycleTimes();
  CheckInputStates();
  PowerState();
  //StartCycle();
  //StopCycle();
  //ForRevDrvDir();
  //ForDir();
  //ZeroSelect();
  //RevDir();
  serialprintTimer();
  serialprint();
  LCDprintTimer();
  //  LCDprint();

  //CycleTimer();
  //WashPulseTimer();
  //SpinPulseTimer();
  //SoakTimer();
  //DelayTimer();
  //DrainPumpPulseTimer();
  QuikWashSelect();
  QuikRinseSelect();
  QuikSpinSelect();

  CourseSelection();
  DelaySelection();
  //DelayActiveState();


  //    SubtractStartTime = millis();

  //CycleTimer();

  //*************************************************************************

  QuikTimer = QuikCycleProgress;

  if (DelayPinState == LOW) {
    DelayActive = HIGH;
  }
  if (StopPinState == HIGH) {
    DelayActive = LOW;
  }

  if ((DelayActive == HIGH) && (PowerOnPinState == LOW) && (StartState == HIGH) && (QuikSelectRunningState == LOW)) {
    DelayStartTimer();
    DelayActiveState();
  }

  if ((DelayActive == HIGH) && (StartState == LOW)) {
    CycleStartTime = millis();
    WashCycleStartTime = millis();
    DelayProgress = 0;
  }

  //************************************************************************
  //***********************************************
  //           POWER ON AND CYCLE START

    if (PowerOnPinState == LOW) {


  if (StartPausePinState == HIGH) {  // && (PowerOnPinState == LOW)){
    StartCycle();
    //      Filling();

  }

  //    else

  //  if ((StopPinState == HIGH)){  // || (CycleState == LOW)){ // && (QuikSelectRunningState == LOW)) {  // || (PowerOnPinState == HIGH)){
  if ((StopPinState == HIGH) || (AllCyclesRun == LOW)) { // && (QuikSelectRunningState == LOW)) {  // || (PowerOnPinState == HIGH)){
    //    QuikBuzzerPulseTimer();
    //    QuikBuzzerTimer();
    //    QuikBuzzer();

    StopCycle();
    //DelayActive = LOW;

  }


    }

  //************************************************************************
  ///***********************************************
  //            START NORMAL SELECTED CYCLE

  //  if (QuikSelectRunningState == HIGH) {

  if ((PowerOnPinState == LOW) && (StartState == HIGH) && (QuikSelectRunningState == LOW) && (DelayState == LOW)
      && (StopState == LOW)) {

    //DelayStartTimer();
    //DelaySelection();
    //DelayActiveState();


    if ((DelayState == LOW) && (DelayActive == LOW)) {
      //FillingWashCycle = HIGH;
      Filling();
      //      WashCycleTimer();
      //      CycleTimer();
      SubtractTimer();
      //times = millis();

      if ((WashRunCycle == HIGH) && (WaterLevelOK == HIGH)) {
       
//    digitalWrite(BrakeRelayPin, HIGH);
//delay(5000);     
   
if (BrakeReleaseState == HIGH){
        
        Washing();
      }
    }
    
      if ((RinseRunCycle == HIGH) && (WaterLevelOK == HIGH))  {
        Rinsing();
      }

      if ((BigSpinCycle == HIGH) && (WaterLevelNotOK == HIGH))  {
        Spinning();
        //        BigSpinning();
      }

if (BrakeReleaseState == LOW){
BrakeReleaseTimer();
    }

if ((BrakingOn == true) && (BrakeReleaseState == HIGH)){  
BrakeOn();        
}


if ((BrakingOn == false) && (BrakeReleaseState == HIGH)){
BrakeOff();        
}


if ((BrakingOn == false)  && (BrakeReleaseState == LOW)){

BrakeOff();        
}     

 
      //******

      //      if (CycleStage1 == HIGH) {
      //        Washing();
      //      }
      //
      //      if (CycleStage2 == HIGH) {
      //        Rinsing();
      //      }
      //
      //      if (CycleStage3 == HIGH) {
      //        Spinning();
      //      }
      //    BuzzerPulseStartTime = millis();
      //    BuzzerStartTime = millis();

    }
  }
  else

    if (QuikSelectRunningState == LOW) {

      if ((PowerOnPinState == HIGH) || (StoppingState == HIGH) || (CycleState == LOW) || (QuikStoppingState == HIGH)
          || (QuikCycleStage3 == HIGH) || (QuikStoppingState == HIGH) || (QuikSelectRunningState == LOW)
          || (StopState == HIGH)) {

        //          WaterLevelbuttonPushCounter = 1;
        ////    QuikBuzzerPulseTimer();
        //    QuikBuzzerTimer();
        //    QuikBuzzer();
        SubtractStartTime = millis();
        times = millis();

        //        QuikCycleStartTime = millis();
        //        CycleStartTime = millis();
        DelayStartTime = millis();

        CycleStage1 = LOW;
        CycleStage2 = LOW;
        CycleStage3 = LOW;

        //      QuikCycleStage1 = LOW;
        //      QuikCycleStage2 = LOW;
        //      QuikCycleStage3 = LOW;

        StopCycle();

      }
    }
  //  }

  ////************************************************************************
  ////                        START QUIK SELECTED CYCLE

  if ((QuikSelectRunningState == HIGH)) {
    if ((PowerOnPinState == LOW) && (QuikWashRunning == HIGH) && (StartState == HIGH) && (QuikWashingLevelOk == true)) {

if (BrakeReleaseState == LOW){
BrakeReleaseTimer();
    }

if ((BrakingOn == true) && (BrakeReleaseState == HIGH)){  
BrakeOn();        
}


if ((BrakingOn == false) && (BrakeReleaseState == HIGH)){
BrakeOff();        
}


if ((BrakingOn == false)  && (BrakeReleaseState == LOW)){

BrakeOff();        
}   
      
      HotColdSelect();
      WashLoadSelect();
      QuikCycleTimer();
      QuikSubtractTimer();

QuikWashingOn = true;
QuikWashingFilling = true;

//      Filling();

if ((QuikWashingLevelOk == true) && (QuikWashingLevelNotOk == false)){ 

     QuikWashing();
      
      //          StopCycle();
      //    QuikBuzzerPulseStartTime = millis();
      //    QuikBuzzerStartTime = millis();
    }
    
    }
    
if (QuikWashingLevelNotOk == true)
    {
    
            Filling();
    }
    
    if ((PowerOnPinState == LOW) && (QuikRinseRunning == HIGH) && (StartState == HIGH) && (QuikWashingLevelOk == true)) {

if (BrakeReleaseState == LOW){
BrakeReleaseTimer();
    }

if ((BrakingOn == true) && (BrakeReleaseState == HIGH)){  
BrakeOn();        
}


if ((BrakingOn == false) && (BrakeReleaseState == HIGH)){
BrakeOff();        
}


if ((BrakingOn == false)  && (BrakeReleaseState == LOW)){

BrakeOff();        
}   
      
      HotColdSelect();
      WashLoadSelect();
      QuikCycleTimer();
      QuikSubtractTimer();
      
QuikRinsingOn = true;
QuikRinsingFilling = true;
     
//FillingSoftner();
      
      if (QuikRinsingLevelOk == true){
        
      QuikRinsing();
      
      //          StopCycle();

      //    QuikBuzzerPulseStartTime = millis();
      //    QuikBuzzerStartTime = millis();
    }
      }
      
if (QuikRinsingLevelNotOk == true)
    {
       FillingSoftner();
    }
      
    if ((PowerOnPinState == LOW) && (QuikSpinRunning == HIGH) && (StartState == HIGH) && (EmptyDrum == HIGH)) {

if (BrakeReleaseState == LOW){
BrakeReleaseTimer();
    }

if ((BrakingOn == true) && (BrakeReleaseState == HIGH)){  
BrakeOn();        
}


if ((BrakingOn == false) && (BrakeReleaseState == HIGH)){
BrakeOff();        
}


if ((BrakingOn == false)  && (BrakeReleaseState == LOW)){

BrakeOff();        
}   
      
      HotColdSelect();
      WashLoadSelect();
      QuikCycleTimer();
      QuikSubtractTimer();

 if (EmptyDrum == HIGH){
 QuikSpinning();
 }

// if (EmptyDrum == LOW){
// RinseDrain();
// }
      //          StopCycle();

      //    QuikBuzzerPulseStartTime = millis();
      //    QuikBuzzerStartTime = millis();
    }
    
 if (EmptyDrum == LOW){
 RinseDrain();
 }
    //  else

    if ((QuikSelectRunningState == HIGH)) {
      if ((PowerOnPinState == HIGH) || (QuikStoppingState == HIGH) || (QuikCycleStage3 == HIGH)
          || (StopPinState == HIGH)) {   // || (StopState == HIGH)) {

        //    QuikBuzzerPulseTimer();
        //    QuikBuzzerTimer();
        //    QuikBuzzer();

        QuikCycleStartTime = millis();
        QuikCycleSetTime = PreviousQuikCycleSetTime;

        digitalWrite(QuikWashLedPin, LOW);
        digitalWrite(QuikRinseLedPin, LOW);
        digitalWrite(QuikSpinLedPin, LOW);

        QuikCycleStage1 = LOW;
        QuikCycleStage2 = LOW;
        QuikCycleStage3 = LOW;

        QuikSelectRunningState = LOW;

        QuikWashRunning = LOW;
        QuikRinseRunning = LOW;
        QuikSpinRunning = LOW;

        //      QuikMillisReset();
        QuikSubtractStartTime = millis();
        QuikStopCycle();
        StopCycle();
        //      StopTimer();
      }
    }
    if ((StopPinState == HIGH)) {
      WaterLevelbuttonPushCounter = 1;
      WaterSupplybuttonPushCounter = 0;
      QuikCycleStartTime = millis();
      QuikCycleSetTime = PreviousQuikCycleSetTime;
      //DelayActive = LOW;
      //    BuzzerPulseStartTime = millis();
      //    BuzzerStartTime = millis();
      //    QuikBuzzerPulseStartTime = millis();
      //    QuikBuzzerStartTime = millis();
    }

    if (StopState == HIGH) {
      StopPinState = HIGH;

    }
    if (StopState == LOW) {
      StopPinState = LOW;
    }


  }

  // if (QuikStartState == HIGH){
  //    QuikBuzzerPulseStartTime = millis();
  //    QuikBuzzerStartTime = millis();
  //
  //  }

  //************************************************************************

  //  if ((StartPausePinState == HIGH) || (StopPinState == HIGH)
  //       || (WaterSupplyPinState == LOW) || (WaterLevelPinState == LOW)
  //       || (QuikWashBuzzerPinState == LOW) || (QuikRinseBuzzerPinState == LOW) || (QuikSpinBuzzerPinState == LOW)
  //       ){
  //
  //  digitalWrite(TonebuzzerPin, HIGH);
  //
  //
  //}else
  //
  //  if ((StartPausePinState == LOW) || (StopPinState == LOW)
  //       || (WaterSupplyPinState == HIGH) || (WaterLevelPinState == HIGH)
  //       || (QuikWashBuzzerPinState == HIGH) || (QuikRinseBuzzerPinState == HIGH) || (QuikSpinBuzzerPinState == HIGH)){
  //
  //  digitalWrite(TonebuzzerPin, LOW);
  //
  //
  //}

}
//  QuikWashBuzzerPinState = digitalRead(QuikWashPin);
//  QuikRinseBuzzerPinState = digitalRead(QuikRinsePin);
//  QuikSpinBuzzerPinState = digitalRead(QuikSpinPin);

//***********************************************
void serialprint() {

  serialprintTimer();

  //          Serial.println("");
  //          Serial.print("StopProgress :");
  //          Serial.print(StopProgress);
  //          Serial.println("");
  //    //
  //          Serial.println("");
  //          Serial.print("StopPinState :");
  //          Serial.print(StopPinState);
  //          Serial.println("");
  //
  //          Serial.println("");
  //          Serial.print("StopState :");
  //          Serial.print(StopState);
  //          Serial.println("");

  //  Serial.println("");
  //  Serial.print("WaterLevel :");
  //  Serial.print(WaterLevel);
  //  Serial.println("");
  //
  //              Serial.println("");
  //              Serial.print("CycleProgress :");
  //              Serial.print(CycleProgress);

  //              Serial.println("");
  //              Serial.print("QuikCycleProgress :");
  //              Serial.print(QuikCycleProgress);
  //
  //  Serial.println("");
  //  Serial.print("BuzzerPulseProgress :");
  //  Serial.print(BuzzerPulseProgress);
  //
  //  Serial.println("");
  //  Serial.print("BuzzerProgress :");
  //  Serial.print(BuzzerProgress);
  //
  //  Serial.println("");
  //  Serial.print("QuikBuzzerPulseProgress :");
  //  Serial.print(QuikBuzzerPulseProgress);
  //
  //  Serial.println("");
  //  Serial.print("QuikBuzzerProgress :");
  //  Serial.print(QuikBuzzerProgress);


  if (SerialPrintState == HIGH) {

    if (QuikSelectRunningState == LOW) {

//      Serial.println("");
//      Serial.print("PowerOnPinState :");
//      Serial.print(PowerOnPinState);
//
//      Serial.println("");
//      Serial.print("StartPausePinState :");
//      Serial.print(StartPausePinState);
//
//      Serial.println("");
//      Serial.print("StartState :");
//      Serial.print(StartState);
//
//      Serial.println("");
//      Serial.print("StopPinState :");
//      Serial.print(StopPinState);
//
//      Serial.println("");
//      Serial.print("StoppingState :");
//      Serial.print(StoppingState);

      //**
//
//      Serial.println("");
//      Serial.print("cap1.Measure() :");
//      Serial.print(cap1.Measure());
      
      Serial.println("");
      Serial.print("SelectedWaterLevel :");
      Serial.print(SelectedWaterLevel);

      Serial.println("");
      Serial.print("WaterLevel :");
      Serial.print(WaterLevel);
      
      Serial.println("");
      Serial.print("WaterLevelPrevious :");
      Serial.print(WaterLevelPrevious);
//      
//      Serial.println("");
//      Serial.print("WaterVolumePin :");
//      Serial.print(WaterVolumePin);
//      
      Serial.println("");
      Serial.print("WaterLevelActual :");
      Serial.print(WaterLevelActual);
      
      Serial.println("");
      Serial.print("WaterLevelActual2 :");
      Serial.print(WaterLevelActual2);

      Serial.println("");
      Serial.print("WaterLevelOK :");
      Serial.print(WaterLevelOK);

      Serial.println("");
      Serial.print("WaterLevelNotOK :");
      Serial.print(WaterLevelNotOK);

      //      Serial.println("");
      //      Serial.print("WaterLevelProblem :");
      //      Serial.print(WaterLevelProblem);

      //**
      //      Serial.print("CoursePinState :");
      //      Serial.print(CoursePinState);
      //      Serial.println("");
      //
      //      Serial.print("CoursebuttonPushCounter :");
      //      Serial.print(CoursebuttonPushCounter);
      //      Serial.println("");
      //
      ////**
      //
      //      Serial.print("DelaybuttonPushCounter :");
      //      Serial.print(DelaybuttonPushCounter);
      //      Serial.println("");
      //
      //      Serial.print("DelayPinState :");
      //      Serial.print(DelayPinState);
      //      Serial.println("");
      //
      //      Serial.print("DelaySetTime :");
      //      Serial.print(DelaySetTime);
      //      Serial.println("");
      //
      //      Serial.print("DelayTime :");
      //      Serial.print(DelayTime);
      //      Serial.println("");
      //
      //      Serial.print("DelayProgress :");
      //      Serial.print(DelayProgress);
      //      Serial.println("");
      //
      //      Serial.print("DelayState :");
      //      Serial.print(DelayState);
      //      Serial.println("");
      //
      //      Serial.print("DelayActive :");
      //      Serial.print(DelayActive);
      //      Serial.println("");
      //
      //      Serial.print("DelayDispTimeSeconds :");
      //      Serial.print(DelayDispTimeSeconds);
      //      Serial.println("");
      //
      //      Serial.print("DelayDispTimeMinutes :");
      //      Serial.print(DelayDispTimeMinutes);
      //      Serial.println("");
      //
      //      Serial.print("DelayDispTimeHours :");
      //      Serial.print(DelayDispTimeHours);
      //      Serial.println("");
      //
      //      Serial.print("DelayTimeSeconds :");
      //      Serial.print(DelayTimeSeconds);
      //      Serial.println("");
      //
      //      Serial.print("DelayTimeMinutes :");
      //      Serial.print(DelayTimeMinutes);
      //      Serial.println("");
      //
      //      Serial.print("DelaySetTimeHours :");
      //      Serial.print(DelaySetTimeHours);
      //      Serial.println("");
      //
      //      Serial.print("DelaySetTimeSeconds :");
      //      Serial.print(DelaySetTimeSeconds);
      //      Serial.println("");
      //
      //      Serial.print("DelaySetTimeMinutes :");
      //      Serial.print(DelaySetTimeMinutes);
      //      Serial.println("");
      //
      //      Serial.print("DelaySetTimeHours :");
      //      Serial.print(DelaySetTimeHours);
      //      Serial.println("");
      //
      ////**

      //          Serial.println("");
      //          Serial.print("DirForPinState :");
      //          Serial.print(DirForPinState);
      //          Serial.println("");
      //
      //      Serial.println("");
      //      Serial.print("DirRevPinState :");
      //      Serial.print(DirRevPinState);
      //      Serial.println("");

      //    Serial.println("");
      //    Serial.print("CycleState :");
      //    Serial.print(CycleState);
      //    Serial.println("");

          Serial.println("");
          Serial.print("BrakeReleaseState :");
          Serial.print(BrakeReleaseState);

          Serial.println("");
          Serial.print("BrakingOn :");
          Serial.print(BrakingOn);      
      
          Serial.println("");
          Serial.print("WashPulseProgress :");
          Serial.print(WashPulseProgress);
          Serial.println("");

//      
          Serial.println("");
          Serial.print("SpinPulseProgress :");
          Serial.print(SpinPulseProgress);

          Serial.println("");
          Serial.print("SpinPulseState :");
          Serial.print(SpinPulseState);

          Serial.println("");
          Serial.print("SmallSpinState :");
          Serial.print(SmallSpinState);
      
      Serial.println("");
      Serial.print("BigSpinState :");
      Serial.print(BigSpinState);
                      
//
          Serial.println("");
      //    Serial.print("CycleStage1 :");
      //    Serial.print(CycleStage1);
      //    Serial.println("");
      //
      //    Serial.println("");
      //    Serial.print("CycleStage2 :");
      //    Serial.print(CycleStage2);
      //    Serial.println("");
      //
      //    Serial.println("");
      //    Serial.print("CycleStage3 :");
      //    Serial.print(CycleStage3);
      //    Serial.println("");

      //    Serial.println("");
      //    Serial.print("CycleSeconds :");
      //    Serial.print(CycleSeconds);
      //
      //    Serial.println("");
      //    Serial.print("CycleMinutes :");
      //    Serial.print(CycleMinutes);
      //
      //    Serial.println("");
      //    Serial.print("CycleHours :");
      //    Serial.print(CycleHours);
      //
      //    Serial.println("");
      //    Serial.print("PrevCycleSeconds :");
      //    Serial.print(PrevCycleSeconds);
      //
      //    Serial.println("");
      //    Serial.print("PostCycleSeconds :");
      //    Serial.print(PostCycleSeconds);
      //
      //    Serial.println("");
      //    Serial.print("RunningCycleTimeSeconds :");
      //    Serial.print(RunningCycleTimeSeconds);
      //
      //    Serial.println("");
      //    Serial.print("RunningCycleTimeMinutes :");
      //    Serial.print(RunningCycleTimeMinutes);
      //
      //    Serial.println("");
      //    Serial.print("MaximumCycleTimeMinutes :");
      //    Serial.print(MaximumCycleTimeMinutes);
      //
      //    Serial.println("");
      //    Serial.print("MaximumCycleTimeSeconds :");
      //    Serial.print(MaximumCycleTimeSeconds);
      //
      //    Serial.println("");
      //    Serial.print("MaximumCycleTimeMilliSeconds :");
      //    Serial.print(MaximumCycleTimeMilliSeconds);

      //**
//
//      Serial.println("");
//      Serial.print("BrakeReleaseProgress :");
//      Serial.print(BrakeReleaseProgress);
//
//      Serial.println("");
//      Serial.print("MotorTemp :");
//      Serial.print(MotorTemp);
//
//
//      Serial.println("");
//      Serial.print("Temperature :");
//      Serial.print(Temperature);

      Serial.println("");
      Serial.print("DisplayTime :");
      Serial.print(DisplayTime);
//
//      Serial.println("");
//      Serial.print("CycleProgress :");
//      Serial.print(CycleProgress);
//
//      Serial.println("");
//      Serial.print("CycleState :");
//      Serial.print(CycleState);
//
//      Serial.println("");
//      Serial.print("WashCycleProgress :");
//      Serial.print(WashCycleProgress);
//
//      Serial.println("");
//      Serial.print("RinseCycleProgress :");
//      Serial.print(RinseCycleProgress);
//
      Serial.println("");
      Serial.print("SpinCycleProgress :");
      Serial.print(SpinCycleProgress);

      Serial.println("");
      Serial.print("SmallSpinProgress :");
      Serial.print(SmallSpinProgress);

      Serial.println("");
      Serial.print("BigSpinProgress :");
      Serial.print(BigSpinProgress);
//
//      Serial.println("");
//      Serial.print("BuzzerPulseProgress :");
//      Serial.print(BuzzerPulseProgress);
//
//      Serial.println("");
//      Serial.print("BuzzerProgress :");
//      Serial.print(BuzzerProgress);
//
//      Serial.println("");
//      Serial.print("WashFillOn :");
//      Serial.print(WashFillOn);
//
//      Serial.println("");
//      Serial.print("FillingWashCycle :");
//      Serial.print(FillingWashCycle);
//      
//      Serial.println("");
//      Serial.print("WashRunCycle :");
//      Serial.print(WashRunCycle);
//
//      Serial.println("");
//      Serial.print("WashDrainCycle :");
//      Serial.print(WashDrainCycle);
//
//      Serial.println("");
//      Serial.print("WashDrainRunning :");
//      Serial.print(WashDrainRunning);
//      
//      Serial.println("");
//      Serial.print("EmptyDrum :");
//      Serial.print(EmptyDrum);
//
//      Serial.println("");
//      Serial.print("RinseFillOn :");
//      Serial.print(RinseFillOn);
//
//
//      Serial.println("");
//      Serial.print("FillRinseCycle :");
//      Serial.print(FillRinseCycle);
//
//      Serial.println("");
//      Serial.print("RinseFillOn :");
//      Serial.print(RinseFillOn);
//      
//      Serial.println("");
//      Serial.print("RinseRunCycle :");
//      Serial.print(RinseRunCycle);
//
//      Serial.println("");
//      Serial.print("SpinDrain :");
//      Serial.print(SpinDrain);
//
//      Serial.println("");
//      Serial.print("RinseDrainRunning :");
//      Serial.print(RinseDrainRunning);
//
//      Serial.println("");
//      Serial.print("BigSpinDrainState :");
//      Serial.print(BigSpinDrainState);
//
//
//      Serial.println("");
//      Serial.print("RinsingRunning :");
//      Serial.print(RinsingRunning);
//
//
//
//      //          Serial.println("");
//      //          Serial.print("RinsingRunning :");
//      //          Serial.print(RinsingRunning);

      Serial.println("");
      Serial.print("BigSpinCycle :");
      Serial.print(BigSpinCycle);
//
//      Serial.println("");
//      Serial.print("CycleSetTime :");
//      Serial.print(CycleSetTime);
//
//      Serial.println("");
//      Serial.print("CycleSeconds :");
//      Serial.print(CycleSeconds);
//
//      Serial.println("");
//      Serial.print("CycleMinutes :");
//      Serial.print(CycleMinutes);
////
////      Serial.println("");
////      Serial.print("EachCycleTime :");
////      Serial.print(EachCycleTime);
////
////      Serial.println("");
////      Serial.print("CycleResetTime1 :");
////      Serial.print(CycleResetTime1);
////
////      Serial.println("");
////      Serial.print("CycleResetTime2 :");
////      Serial.print(CycleResetTime2);
////
////      Serial.println("");
////      Serial.print("CycleResetTime3 :");
////      Serial.print(CycleResetTime3);
////
////
//

      //    }
      //
      //    if (QuikSelectRunningState == HIGH) {
      //
      //
      //    Serial.println("");
      //    Serial.print("QuikCycleSetTime :");
      //    Serial.print(QuikCycleSetTime);
      //
      //        Serial.println("");
      //        Serial.print("QuikCycleProgress :");
      //        Serial.print(QuikCycleProgress);
      //
      //        Serial.println("");
      //        Serial.print("QuikCycleSeconds :");
      //        Serial.print(QuikCycleSeconds);
      //
      //        Serial.println("");
      //        Serial.print("QuikCycleMinutes :");
      //        Serial.print(QuikCycleMinutes);
      //
      //        Serial.println("");
      //        Serial.print("UltraLowSpinCycleTimeSeconds :");
      //        Serial.print(UltraLowSpinCycleTimeSeconds);
      //
      //        Serial.println("");
      //        Serial.print("UltraLowSpinCycleTimeMinutes :");
      //        Serial.print(UltraLowSpinCycleTime);
      //
      //
      //
      //
      //        Serial.println("");
      //        Serial.print("QuikCycleResetTime1 :");
      //        Serial.print(QuikCycleResetTime1);
      //
      //        Serial.println("");
      //        Serial.print("QuikCycleResetTime2 :");
      //        Serial.print(QuikCycleResetTime2);
      //
      //
      //        Serial.println("");
      //        Serial.print("QuikCycleResetTime3 :");
      //        Serial.print(QuikCycleResetTime3);
      //        Serial.println("");
//
//      Serial.println("");
//      Serial.print("QuikSelectRunningState :");
//      Serial.print(QuikSelectRunningState);
      //    //
      //    //    Serial.println("");
      //    //    Serial.print("QuikWashPulseProgress :");
      //    //    Serial.print(QuikWashPulseProgress);
      //    //
      //    //    Serial.println("");
      //    //    Serial.print("QuikSpinPulseProgress :");
      //    //    Serial.print(QuikSpinPulseProgress);
      //
      //        Serial.println("");
      //        Serial.print("QuikUltraLowWashCycleTimeSeconds :");
      //        Serial.print(QuikUltraLowWashCycleTimeSeconds);
      //
      //            Serial.println("");
      //        Serial.print("QuikUltraLowWashCycleTimeMinutes :");
      //        Serial.print(QuikUltraLowWashCycleTimeMinutes);
      //
      //        Serial.println("");
      //        Serial.print("QuikUltraLowRinseCycleTimeSeconds :");
      //        Serial.print(QuikUltraLowRinseCycleTimeSeconds);
      //
      //        Serial.println("");
      //        Serial.print("QuikUltraLowRinseCycleTimeMinutes :");
      //        Serial.print(QuikUltraLowRinseCycleTimeMinutes);
      //
      //        Serial.println("");
      //        Serial.print("QuikUltraLowSpinCycleTimeSeconds :");
      //        Serial.print(QuikUltraLowSpinCycleTimeSeconds);
      //
      //        Serial.println("");
      //        Serial.print("QuikUltraLowSpinCycleTimeMinutes :");
      //        Serial.print(QuikUltraLowSpinCycleTimeMinutes);

      //**


      //            Serial.println("");
      //        Serial.print("LCDPrintProgress :");
      //        Serial.print(LCDPrintProgress);
      //
      //        Serial.println("");
      //        Serial.print("SubtractProgress :");
      //        Serial.print(QuikSubtractProgress);
      //
      //                Serial.println("");
      //        Serial.print("QuikSubtractState :");
      //        Serial.print(QuikSubtractState);
      //
      //                Serial.println("");
      //        Serial.print("QuikTimer :");
      //        Serial.print(QuikTimer);

      //                Serial.println("");
      //        Serial.print("QuikCycleProgress :");
      //        Serial.print(QuikCycleProgress);
      //
      //                Serial.println("");
      //        Serial.print("EachQuikCycleTime :");
      //        Serial.print(EachQuikCycleTime);

      //        Serial.println("");
      //        Serial.print("QuikCycleResetTime1 :");
      //        Serial.print(QuikCycleResetTime1);
      //
      //        Serial.println("");
      //        Serial.print("QuikCycleResetTime2 :");
      //        Serial.print(QuikCycleResetTime2);
      //
      //        Serial.println("");
      //        Serial.print("QuikCycleResetTime3 :");
      //        Serial.print(QuikCycleResetTime3);





      
      Serial.println("");
      Serial.print("EmptyDrum :");
      Serial.print(EmptyDrum);

      
              Serial.println("");
              Serial.print("QuikWashingLevelOk :");
              Serial.print(QuikWashingLevelOk);  
              
              Serial.println("");
              Serial.print("QuikWashingLevelNotOk :");
              Serial.print(QuikWashingLevelNotOk);

              Serial.println("");
              Serial.print("QuikWashingFilling :");
              Serial.print(QuikWashingFilling);
                    
              Serial.println("");
              Serial.print("QuikWashingOn :");
              Serial.print(QuikWashingOn);



              Serial.println("");
              Serial.print("QuikRinsingLevelOk :");
              Serial.print(QuikRinsingLevelOk);

              Serial.println("");
              Serial.print("QuikRinsingLevelNotOk :");
              Serial.print(QuikRinsingLevelNotOk);
      
              Serial.println("");
              Serial.print("QuikRinsingFilling :");
              Serial.print(QuikRinsingFilling);
                    
              Serial.println("");
              Serial.print("QuikRinsingOn :");
              Serial.print(QuikRinsingOn);



    }
  }
}
//***********************************************
