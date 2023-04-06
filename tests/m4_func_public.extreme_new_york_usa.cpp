#include <random>
#include <iostream>
#include <UnitTest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"
#include "m4.h"

#include "unit_test_util.h"
#include "courier_verify.h"

using ece297test::relative_error;
using ece297test::courier_path_is_legal;


SUITE(extreme_new_york_usa_public) {
    TEST(extreme_new_york_usa) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(105744, 260369), DeliveryInf(25735, 274756), DeliveryInf(218331, 1367), DeliveryInf(126372, 44887), DeliveryInf(245068, 68890), DeliveryInf(302841, 105586), DeliveryInf(274262, 106750), DeliveryInf(183497, 266913), DeliveryInf(95795, 257098), DeliveryInf(45458, 270686), DeliveryInf(218825, 110853), DeliveryInf(291128, 86902), DeliveryInf(171951, 10135), DeliveryInf(172921, 84420), DeliveryInf(136651, 130132), DeliveryInf(120, 52442), DeliveryInf(191738, 254358), DeliveryInf(225270, 16782), DeliveryInf(249679, 210062), DeliveryInf(275408, 172843), DeliveryInf(269936, 130086), DeliveryInf(23308, 231576), DeliveryInf(22166, 226995), DeliveryInf(83822, 43142), DeliveryInf(143943, 272282), DeliveryInf(170696, 117179), DeliveryInf(288436, 243571), DeliveryInf(242326, 179042), DeliveryInf(54005, 273348), DeliveryInf(49077, 205633), DeliveryInf(201245, 246336), DeliveryInf(131911, 121295), DeliveryInf(16644, 21319), DeliveryInf(181198, 28137), DeliveryInf(83751, 46560), DeliveryInf(74381, 97102), DeliveryInf(163124, 48569), DeliveryInf(79684, 77644), DeliveryInf(197927, 247394), DeliveryInf(176025, 201036), DeliveryInf(58720, 175834), DeliveryInf(83051, 100345), DeliveryInf(91400, 78748), DeliveryInf(28498, 234550), DeliveryInf(165418, 205224), DeliveryInf(17936, 291593), DeliveryInf(162923, 64783), DeliveryInf(273140, 293156), DeliveryInf(64575, 136610), DeliveryInf(1822, 286659), DeliveryInf(278081, 95522), DeliveryInf(60683, 274779), DeliveryInf(297673, 190858), DeliveryInf(111666, 10437), DeliveryInf(137701, 171247), DeliveryInf(281920, 229230), DeliveryInf(261475, 260499), DeliveryInf(7958, 224384), DeliveryInf(101063, 164659), DeliveryInf(66454, 119525), DeliveryInf(29124, 108342), DeliveryInf(238738, 188924), DeliveryInf(142600, 102757), DeliveryInf(239130, 21711), DeliveryInf(259061, 148099), DeliveryInf(236762, 20303), DeliveryInf(205612, 202602), DeliveryInf(89239, 263365), DeliveryInf(278227, 116203), DeliveryInf(106029, 224210), DeliveryInf(236229, 225903), DeliveryInf(107254, 12989), DeliveryInf(179415, 260946), DeliveryInf(103595, 17580), DeliveryInf(193240, 149722), DeliveryInf(118889, 222300), DeliveryInf(218437, 198419), DeliveryInf(47164, 169060), DeliveryInf(15656, 250950), DeliveryInf(232337, 304904), DeliveryInf(44892, 23913), DeliveryInf(255539, 106709), DeliveryInf(164476, 101436), DeliveryInf(291676, 149651), DeliveryInf(61323, 24889), DeliveryInf(71935, 163144), DeliveryInf(91965, 223234), DeliveryInf(42060, 91416), DeliveryInf(174257, 91449), DeliveryInf(254020, 283443), DeliveryInf(24574, 87205), DeliveryInf(284459, 170894), DeliveryInf(242031, 61330), DeliveryInf(186278, 32390), DeliveryInf(80295, 295284), DeliveryInf(44217, 249729), DeliveryInf(154643, 77503), DeliveryInf(238787, 234905), DeliveryInf(277940, 200335), DeliveryInf(186457, 73533), DeliveryInf(207014, 38410), DeliveryInf(224575, 211298), DeliveryInf(109672, 110191), DeliveryInf(45271, 287150), DeliveryInf(182679, 91643), DeliveryInf(17363, 298255), DeliveryInf(46648, 189109), DeliveryInf(201578, 73810), DeliveryInf(71516, 30013), DeliveryInf(35125, 35783), DeliveryInf(91938, 71504), DeliveryInf(16373, 208187), DeliveryInf(97687, 68107), DeliveryInf(120788, 268987), DeliveryInf(202050, 92482), DeliveryInf(272486, 209206), DeliveryInf(248185, 45001), DeliveryInf(80491, 131302), DeliveryInf(261979, 116577), DeliveryInf(221588, 142692), DeliveryInf(12147, 137332), DeliveryInf(18160, 28163), DeliveryInf(48643, 220670), DeliveryInf(82123, 126986), DeliveryInf(68335, 226070), DeliveryInf(241831, 2394), DeliveryInf(63070, 115767), DeliveryInf(58869, 225937)};
        depots = {48};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR extreme_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR extreme_new_york_usa: INVALID" << std::endl;
        }

    } //extreme_new_york_usa

} //extreme_new_york_usa_public

