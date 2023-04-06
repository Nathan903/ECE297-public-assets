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


SUITE(medium_toronto_canada_public) {
    TEST(medium_toronto_canada) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(154553, 167686), DeliveryInf(1203, 130848), DeliveryInf(112414, 183210), DeliveryInf(192876, 86871), DeliveryInf(121221, 149181), DeliveryInf(39442, 181329), DeliveryInf(188078, 190122), DeliveryInf(109866, 18010), DeliveryInf(152797, 110775), DeliveryInf(191184, 99453), DeliveryInf(142505, 132439), DeliveryInf(81400, 38997), DeliveryInf(160611, 123660), DeliveryInf(128545, 42023), DeliveryInf(40304, 119636), DeliveryInf(182839, 155348), DeliveryInf(131678, 72705), DeliveryInf(123256, 121167), DeliveryInf(6672, 112277), DeliveryInf(13243, 188638), DeliveryInf(143534, 139213), DeliveryInf(54267, 90552), DeliveryInf(37918, 117607), DeliveryInf(75698, 99510), DeliveryInf(38765, 161282), DeliveryInf(135624, 166446), DeliveryInf(147470, 241), DeliveryInf(5831, 159348), DeliveryInf(172178, 173493), DeliveryInf(188723, 161839), DeliveryInf(149129, 141723), DeliveryInf(36111, 164374), DeliveryInf(189712, 119964), DeliveryInf(125318, 166281), DeliveryInf(53689, 107315), DeliveryInf(60792, 147896), DeliveryInf(40664, 193797), DeliveryInf(166831, 36814), DeliveryInf(177892, 83951), DeliveryInf(85960, 160847), DeliveryInf(119469, 91991), DeliveryInf(4454, 174584), DeliveryInf(53949, 172707), DeliveryInf(108208, 136385), DeliveryInf(108560, 74847), DeliveryInf(66221, 65360), DeliveryInf(105484, 123726), DeliveryInf(14100, 63397), DeliveryInf(136848, 154263), DeliveryInf(51929, 38168)};
        depots = {129069, 129489, 28375, 13230, 62654};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR medium_toronto_canada: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR medium_toronto_canada: INVALID" << std::endl;
        }

    } //medium_toronto_canada

} //medium_toronto_canada_public

