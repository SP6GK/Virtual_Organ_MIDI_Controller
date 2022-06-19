/*===================|  tabs to midi value |==========================
 *
 *  This is a configuration file for combination pistons,
 * check the tabsToValues.h file for avaible names
 * then add desired names to pistons that you want to use
 *
 * You add desired ranks to combination by putting them into brackets {}
 * after name of division_number of button = { rank_16_acc, rank2_8_acc}
 *
 * Tip: you can use C  IDE or smart editor like Kate for
 * automatic suggestion of rank names when typing.
 *
 * Part of open source theatre organ project by SP6GK, 2022
 * ======================================================================
 */

#ifndef combinations_h
#define combinations_h

#include "tabsToValue.h"
 //Generals (if you want to chanhe all divisions with one button)
int general_1[] = {bourdon_16_acc, diapason_8_acc};
int general_2[] = {bourdon_16_acc, diapason_8_acc};
int general_3[] = {bourdon_16_acc, diapason_8_acc};
int general_4[] = {bourdon_16_acc, diapason_8_acc};
int general_5[] = {bourdon_16_acc, diapason_8_acc};

int general_6[] = {bourdon_16_acc, diapason_8_acc};
int general_7[] = {bourdon_16_acc, diapason_8_acc};
int general_8[] = {bourdon_16_acc, diapason_8_acc};
int general_9[] = {bourdon_16_acc, diapason_8_acc};
int general_10[] = {bourdon_16_acc, diapason_8_acc};

//Pedal
int ped_comb_1[] = {flute_8_ped, bourdon_16_ped};
int ped_comb_2[] = {diapason_8_ped, flute_8_ped, bourdon_16_ped, cello_8_ped};
int ped_comb_3[] = {flute_8_ped, tuba_8_ped, tuba_16_ped, bourdon_16_ped};

//Accompanient
int acc_comb_1[] = {flute_8_acc, flute_4_acc};
int acc_comb_2[] = {flute_8_acc, viol_8_acc, flute_4_acc};
int acc_comb_3[] = {flute_8_acc, viol_8_acc, vox_8_acc, flute_4_acc};
int acc_comb_4[] = {flute_8_acc, diapason_8_acc, flute_4_acc, tibia_2_acc };
int acc_comb_5[] = {tibia_8_acc, tuba_8_acc, diapason_8_acc, octave_4_acc, tibia_2_acc, viol_8_acc, vox_8_acc};

//Great
int grt_comb_1[] = {tibia_8_grt, tibia_4_grt, tibia_2_grt};
int grt_comb_3[] = {tibia_8_grt, cello_8_grt, vox_8_grt, viol_4_grt, cello_4_grt};
int grt_comb_2[] = {bourdon_16_grt, vox_16_grt, tibia_8_grt,vox_8_grt, diapason_8_grt, tuba_8_grt, tibia_4_grt, octave_4_grt, tibia_2_grt};
int grt_comb_4[] = {trumpet_8_grt, tibia_8_grt, diapason_8_grt,vox_8_grt, tuba_8_grt, clar_8_grt, sax_8_grt, tibia_4_grt};
int grt_comb_5[] = {tibia_16_grt, vox_16_grt, viol_8_grt, tibia_8_grt, clar_8_grt, diapason_8_grt, vox_8_grt, tibia_4_grt, octave_4_grt, glock_grt};


//Solo


#endif
