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


SUITE(medium_new_york_usa_public) {
    TEST(medium_new_york_usa) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(122756, 108152), DeliveryInf(302219, 236485), DeliveryInf(199746, 289222), DeliveryInf(49059, 203956), DeliveryInf(188666, 97436), DeliveryInf(143901, 26783), DeliveryInf(74468, 50109), DeliveryInf(135008, 114736), DeliveryInf(195929, 296941), DeliveryInf(37445, 118293), DeliveryInf(97591, 289893), DeliveryInf(203111, 140038), DeliveryInf(275736, 186082), DeliveryInf(117057, 235357), DeliveryInf(223618, 180839), DeliveryInf(233234, 182605), DeliveryInf(232867, 82253), DeliveryInf(95021, 115187), DeliveryInf(133161, 109564), DeliveryInf(14443, 101982), DeliveryInf(115457, 52536), DeliveryInf(267108, 60348), DeliveryInf(260846, 61622), DeliveryInf(184349, 215209), DeliveryInf(110423, 257163), DeliveryInf(79081, 244097), DeliveryInf(295100, 172369), DeliveryInf(224748, 150750), DeliveryInf(156155, 140632), DeliveryInf(186860, 158822), DeliveryInf(58082, 214702), DeliveryInf(73453, 268099), DeliveryInf(179332, 265734), DeliveryInf(54593, 163458), DeliveryInf(28172, 245221), DeliveryInf(18364, 244801), DeliveryInf(72084, 186537), DeliveryInf(113949, 202136), DeliveryInf(203027, 253755), DeliveryInf(113347, 6183), DeliveryInf(217092, 8946), DeliveryInf(229661, 154249), DeliveryInf(103541, 148762), DeliveryInf(88367, 104628), DeliveryInf(298886, 180490), DeliveryInf(193408, 5133), DeliveryInf(101399, 93986), DeliveryInf(54289, 45995), DeliveryInf(236585, 25255), DeliveryInf(278946, 212901)};
        depots = {27, 104855, 124980, 174624, 268766, 233910, 18467, 182512, 15914, 300280};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR medium_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR medium_new_york_usa: INVALID" << std::endl;
        }

    } //medium_new_york_usa

} //medium_new_york_usa_public

