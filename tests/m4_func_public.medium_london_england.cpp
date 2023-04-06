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


SUITE(medium_london_england_public) {
    TEST(medium_london_england) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(152141, 56051), DeliveryInf(213493, 131913), DeliveryInf(62027, 266477), DeliveryInf(262394, 341486), DeliveryInf(220974, 32187), DeliveryInf(231964, 62375), DeliveryInf(20982, 204892), DeliveryInf(210624, 270306), DeliveryInf(298024, 100962), DeliveryInf(66361, 130190), DeliveryInf(248034, 256781), DeliveryInf(232060, 154250), DeliveryInf(82358, 140252), DeliveryInf(215556, 133741)};
        depots = {31, 119800, 142793, 199513, 307073, 267249, 21099, 208525, 18183, 343079, 126161, 85082, 115851, 83922, 129502, 16501, 178411, 345294, 318704, 305179};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR medium_london_england: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR medium_london_england: INVALID" << std::endl;
        }

    } //medium_london_england

} //medium_london_england_public

