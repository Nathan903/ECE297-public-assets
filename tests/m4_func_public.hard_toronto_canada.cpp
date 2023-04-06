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


SUITE(hard_toronto_canada_public) {
    TEST(hard_toronto_canada) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(186916, 64664), DeliveryInf(43668, 54633), DeliveryInf(31786, 77417), DeliveryInf(68505, 18512), DeliveryInf(95760, 1408), DeliveryInf(154103, 3051), DeliveryInf(175312, 131352), DeliveryInf(96709, 180142), DeliveryInf(145769, 6190), DeliveryInf(103850, 175353), DeliveryInf(9218, 100612), DeliveryInf(125187, 112737), DeliveryInf(155895, 106968), DeliveryInf(74082, 60242), DeliveryInf(160097, 1865), DeliveryInf(110933, 143419), DeliveryInf(136694, 13419), DeliveryInf(31643, 187229), DeliveryInf(192403, 182589), DeliveryInf(93241, 27641), DeliveryInf(21627, 59140), DeliveryInf(187015, 114155), DeliveryInf(172096, 35469), DeliveryInf(86643, 147992), DeliveryInf(105837, 178487), DeliveryInf(11648, 35008), DeliveryInf(182445, 115800), DeliveryInf(37754, 149311), DeliveryInf(193364, 187960), DeliveryInf(70616, 48081), DeliveryInf(25320, 111786), DeliveryInf(122674, 40194), DeliveryInf(193957, 166678), DeliveryInf(110381, 118004), DeliveryInf(160763, 45803), DeliveryInf(161942, 177462), DeliveryInf(186482, 168785), DeliveryInf(74486, 131300), DeliveryInf(14234, 159846), DeliveryInf(190865, 126336), DeliveryInf(16229, 147249), DeliveryInf(147033, 156771), DeliveryInf(7052, 13404), DeliveryInf(108581, 176697), DeliveryInf(69710, 148632), DeliveryInf(111673, 114341), DeliveryInf(89793, 24218), DeliveryInf(132425, 16080), DeliveryInf(9298, 21907), DeliveryInf(63661, 34221), DeliveryInf(31355, 167702), DeliveryInf(91391, 161198), DeliveryInf(51513, 115713), DeliveryInf(56362, 144912), DeliveryInf(22946, 42797), DeliveryInf(93943, 40441), DeliveryInf(186540, 172874), DeliveryInf(169633, 173762), DeliveryInf(121583, 6007), DeliveryInf(81614, 101765), DeliveryInf(54219, 167240), DeliveryInf(173999, 128836), DeliveryInf(189953, 11302), DeliveryInf(64833, 188933), DeliveryInf(36254, 178180), DeliveryInf(131303, 148161), DeliveryInf(157006, 49631), DeliveryInf(94381, 150225), DeliveryInf(87038, 9144), DeliveryInf(185514, 109377), DeliveryInf(177122, 101253), DeliveryInf(184464, 33245), DeliveryInf(105417, 104283), DeliveryInf(86361, 131019), DeliveryInf(90793, 92914), DeliveryInf(131069, 38687), DeliveryInf(159328, 155437), DeliveryInf(82175, 188056), DeliveryInf(13651, 95255), DeliveryInf(176261, 62872), DeliveryInf(69653, 35329), DeliveryInf(146674, 47202), DeliveryInf(98688, 178661), DeliveryInf(46735, 104270), DeliveryInf(168002, 165369), DeliveryInf(185457, 157477), DeliveryInf(140229, 38981), DeliveryInf(72035, 108320), DeliveryInf(144690, 29719), DeliveryInf(174121, 66706), DeliveryInf(53472, 174164), DeliveryInf(40606, 21590), DeliveryInf(68659, 106933), DeliveryInf(65525, 4441), DeliveryInf(91006, 113735), DeliveryInf(41410, 25101), DeliveryInf(135407, 148805), DeliveryInf(187635, 61856), DeliveryInf(184465, 90001), DeliveryInf(101244, 158898)};
        depots = {21, 82649, 1314, 89043, 163248, 184373, 111753, 192459, 61143, 139490};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR hard_toronto_canada: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR hard_toronto_canada: INVALID" << std::endl;
        }

    } //hard_toronto_canada

} //hard_toronto_canada_public

