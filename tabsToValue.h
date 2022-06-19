/*===================|  tabs to midi value |==========================
 *
 *  This is a configuration file for combination pistons,
 * press down (or pull out) stop, note value from midi monitor
 * change corresponding value (for given stop and division) in this file
 * You can add your own ranks/ effects in any place of this file
 *
 * Part of open source theatre organ project by SP6GK, 2022
 * ======================================================================
 */


 #ifndef tabsToValue_h
 #define tabsToValue_h

//Pedal
const int tuba_16_ped     = 119;
const int diapason_16_ped = 106;
const int tibia_16_ped    = 122;
const int salic_16_ped    = 108;
const int bourdon_16_ped  = 107;
const int horn_8_ped      = 104;
const int tuba_8_ped      = 103;
const int diapason_8_ped  = 102;
const int tibia_8_ped     = 101;
const int clar_8_ped      = 99;
const int salic_8_ped     = 121;
const int cello_8_ped     = 121;
const int flute_8_ped     = 117;
const int piano_16_ped    = 120;

//Accomp
const int viol_16_acc    = 1;
const int bourdon_16_acc = 2;
const int tuba_8_acc     = 3;
const int diapason_8_acc = 4;
const int tibia_8_acc    = 5;
const int clar_8_acc     = 6;
const int viol_8_acc     = 7;
const int cello_8_acc    = 8;
const int flute_8_acc    = 9;
const int vox_8_acc      = 10;
const int octave_4_acc   = 11;
const int tibia_4_acc    = 12;
const int viol_4_acc     = 13;
const int cello_4_acc    = 14;
const int flute_4_acc    = 15;
const int tibia_2_acc    = 16;

const int harp_acc  = 17;
const int crys_acc  = 18;
const int snare_acc = 19;
const int cast_acc  = 20;
const int tom_acc   = 21;
const int block_acc = 22;


//Great
const int tuba_16_grt    = 82;
const int tibia_16_grt   = 81;
const int clar_16_grt    = 80;
const int sal_16_grt     = 79;
const int bourdon_16_grt = 78;
const int vox_16_grt     = 77;
const int horn_8_grt     = 76;
const int trumpet_8_grt  = 75;
const int tuba_8_grt     = 94;
const int diapason_8_grt = 97;
const int tibia_8_grt    = 93;
const int clar_8_grt     = 96;
const int kinura_8_grt   = 95;
const int oboe_8_grt     = 98;
const int sax_8_grt      = 92;
const int sal_8_grt      = 91;
const int viol_8_grt     = 88;
const int cello_8_grt    = 86;
const int flute_8_grt    = 89;
const int vox_8_grt      = 90;
const int octave_4_grt   = 84;
const int tibia_4_grt    = 83;
const int viol_4_grt     = 82;
const int cello_4_grt    = 87;
const int tibia_2_grt    = 67;
const int tierce_113_grt = 68;
const int fife_1_grt     = 74;

const int harp_grt    = 65;
const int marimba_grt = 66;
const int chimes_grt  = 60;
const int xylo_grt    = 59;
const int glock_grt   = 58;
const int bells_grt   = 63;
const int piano_8_grt = 18;

//Solo
const int tuba_16_sol     = 48;
const int diapason_16_sol = 50;
const int tibia_16_sol    = 47;
const int clar_16_sol     = 49;
const int horn_8_sol      = 46;
const int trumpet_8_sol   = 28;
const int tuba_8_sol      = 26;
const int diapason_8_sol  = 32;
const int tibia_8_sol     = 31;
const int clar_8_sol      = 29;
const int kinura_8_sol    = 30;
const int oboe_8_sol      = 27;
const int sali_8_sol      = 39;
const int vox_8_sol       = 37;
const int oct_4_sol       = 40;
const int tibia_4_sol     = 41;
const int tibia_2_sol     = 35;

const int chimes_sol     = 34;
const int xylo_sol       = 33;
const int glock_sol      = 38;

//Tremulants
const int main_tr = 17;
const int solo_tr = 14;
const int vox_tr  = 12;
const int tub_dia_tr = 15;
const int tibia_tr   = 10;

//Couplers
const int sub  = 19;
const int off  = 22;
const int oct  = 21;
const int solo = 25;

//2T Pedal (percusion)
const int bass_drum = 8;
const int kett_drum = 7;
const int crsh_cymb = 6;
const int cymbal    = 5;

//2T Accomp

//2T Solo

//Others

//group stops in arrays, used for pulling in the whole divisions
const int pedal_stops[]  = {tuba_16_ped, diapason_16_ped, tibia_16_ped, salic_16_ped, bourdon_16_ped, horn_8_ped, tuba_8_ped, diapason_8_ped, tibia_8_ped, clar_8_ped, salic_8_ped, cello_8_ped, flute_8_ped, piano_16_ped};
const int accomp_stops[] = {viol_16_acc, bourdon_16_acc, tuba_8_acc, diapason_8_acc, tibia_8_acc, clar_8_acc, viol_8_acc, cello_8_acc, flute_8_acc, vox_8_acc, octave_4_acc, tibia_4_acc, viol_4_acc, cello_4_acc, flute_4_acc, tibia_2_acc, harp_acc, crys_acc, snare_acc, cast_acc, tom_acc, block_acc};
const int great_stops[]  = {tuba_16_grt, tibia_16_grt, clar_16_grt, sal_16_grt, bourdon_16_grt, vox_16_grt, horn_8_grt, trumpet_8_grt, tuba_8_grt, diapason_8_grt, tibia_8_grt, clar_8_grt, kinura_8_grt, oboe_8_grt, sax_8_grt, sal_8_grt, viol_8_grt, cello_8_grt, flute_8_grt, vox_8_grt, octave_4_grt, tibia_4_grt, viol_4_grt, cello_4_grt, tibia_2_grt, tierce_113_grt, fife_1_grt, harp_grt, marimba_grt, chimes_grt, xylo_grt, glock_grt, bells_grt, piano_8_grt};
const int solo_stops[]   = {tuba_16_sol, diapason_16_sol, tibia_16_sol, clar_16_sol, horn_8_sol, trumpet_8_sol, tuba_8_sol, diapason_8_sol, tibia_8_sol, clar_8_sol, kinura_8_sol, oboe_8_sol, sali_8_sol, vox_8_sol, oct_4_sol, tibia_4_sol, tibia_2_sol, chimes_sol, xylo_sol, glock_sol};


 #endif
