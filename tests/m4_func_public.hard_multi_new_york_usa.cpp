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


SUITE(hard_multi_new_york_usa_public) {
    TEST(hard_multi_new_york_usa) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(14533, 75163), DeliveryInf(246522, 210058), DeliveryInf(27146, 226125), DeliveryInf(294048, 146490), DeliveryInf(139754, 216352), DeliveryInf(142140, 60138), DeliveryInf(272763, 231604), DeliveryInf(142532, 111066), DeliveryInf(210309, 117118), DeliveryInf(173185, 245187), DeliveryInf(227729, 117418), DeliveryInf(195160, 231604), DeliveryInf(294189, 11072), DeliveryInf(114858, 210058), DeliveryInf(190351, 212730), DeliveryInf(172781, 194315), DeliveryInf(7700, 57865), DeliveryInf(152098, 172104), DeliveryInf(111702, 163415), DeliveryInf(110139, 210948), DeliveryInf(146386, 210058), DeliveryInf(135972, 210388), DeliveryInf(170924, 292712), DeliveryInf(21664, 159866), DeliveryInf(170020, 76490), DeliveryInf(264319, 232988), DeliveryInf(303204, 18594), DeliveryInf(184134, 299225), DeliveryInf(104413, 210058), DeliveryInf(111702, 92433), DeliveryInf(307114, 282850), DeliveryInf(215852, 279123), DeliveryInf(262266, 116594), DeliveryInf(241264, 175025), DeliveryInf(202512, 244461), DeliveryInf(119628, 47961), DeliveryInf(134370, 6419), DeliveryInf(196399, 238474), DeliveryInf(80092, 244662), DeliveryInf(248008, 177440), DeliveryInf(182982, 210058), DeliveryInf(238234, 220297), DeliveryInf(111702, 213692), DeliveryInf(142140, 103347), DeliveryInf(299188, 279806), DeliveryInf(81890, 143101), DeliveryInf(46597, 57960), DeliveryInf(140979, 44756), DeliveryInf(132551, 231604), DeliveryInf(13772, 132223), DeliveryInf(105323, 12921), DeliveryInf(235574, 187649), DeliveryInf(68993, 13420), DeliveryInf(142140, 231604), DeliveryInf(155312, 304616), DeliveryInf(123379, 69003), DeliveryInf(27547, 272928), DeliveryInf(142140, 279693), DeliveryInf(45602, 231374), DeliveryInf(200587, 73089), DeliveryInf(146154, 157846), DeliveryInf(21445, 133292), DeliveryInf(126150, 193420), DeliveryInf(2801, 126559), DeliveryInf(58921, 78804), DeliveryInf(111702, 236231), DeliveryInf(122383, 231604), DeliveryInf(304666, 60209), DeliveryInf(41571, 273907), DeliveryInf(226492, 17402), DeliveryInf(282999, 164347), DeliveryInf(145480, 281859), DeliveryInf(237129, 162228), DeliveryInf(150400, 192024), DeliveryInf(171498, 156904)};
        depots = {41, 157283, 187470, 107795, 249008, 42585, 27700};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR hard_multi_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR hard_multi_new_york_usa: INVALID" << std::endl;
        }

    } //hard_multi_new_york_usa

} //hard_multi_new_york_usa_public

