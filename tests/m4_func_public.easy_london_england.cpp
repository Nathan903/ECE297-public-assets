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


SUITE(easy_london_england_public) {
    TEST(easy_london_england) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(237689, 81199), DeliveryInf(283205, 94621), DeliveryInf(200437, 273236), DeliveryInf(89850, 239921), DeliveryInf(318359, 277802), DeliveryInf(191934, 150996), DeliveryInf(68339, 262998)};
        depots = {23};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR easy_london_england: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR easy_london_england: INVALID" << std::endl;
        }

    } //easy_london_england

} //easy_london_england_public

