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


SUITE(hard_new_york_usa_public) {
    TEST(hard_new_york_usa) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(252670, 14502), DeliveryInf(214735, 99706), DeliveryInf(118123, 7043), DeliveryInf(248987, 298227), DeliveryInf(129427, 50182), DeliveryInf(292388, 262250), DeliveryInf(292534, 9527), DeliveryInf(301236, 264326), DeliveryInf(50407, 160571), DeliveryInf(25736, 254946), DeliveryInf(64395, 11183), DeliveryInf(57494, 289330), DeliveryInf(307586, 100957), DeliveryInf(280889, 108883), DeliveryInf(198528, 244383), DeliveryInf(138029, 283054), DeliveryInf(103913, 296917), DeliveryInf(194543, 233514), DeliveryInf(144321, 285678), DeliveryInf(294197, 306645), DeliveryInf(153366, 72636), DeliveryInf(210006, 63742), DeliveryInf(89381, 38406), DeliveryInf(110459, 111986), DeliveryInf(247225, 229457), DeliveryInf(222382, 173455), DeliveryInf(295732, 231168), DeliveryInf(114237, 67870), DeliveryInf(18473, 299619), DeliveryInf(172194, 34297), DeliveryInf(175922, 110549), DeliveryInf(59873, 255635), DeliveryInf(85983, 147348), DeliveryInf(164690, 227440), DeliveryInf(22573, 169635), DeliveryInf(256815, 183503), DeliveryInf(177096, 235982), DeliveryInf(266426, 108639), DeliveryInf(137402, 169579), DeliveryInf(142397, 233172), DeliveryInf(207855, 298075), DeliveryInf(156505, 142728), DeliveryInf(253889, 136955), DeliveryInf(69251, 151060), DeliveryInf(14619, 130317), DeliveryInf(272917, 43834), DeliveryInf(167175, 192812), DeliveryInf(36389, 232602), DeliveryInf(221210, 65670), DeliveryInf(269011, 2233), DeliveryInf(117483, 34742), DeliveryInf(296577, 305121), DeliveryInf(279523, 84799), DeliveryInf(151861, 175048), DeliveryInf(49724, 246499), DeliveryInf(96963, 204314), DeliveryInf(275935, 234961), DeliveryInf(81692, 297560), DeliveryInf(167842, 21649), DeliveryInf(40154, 148979), DeliveryInf(258887, 171780), DeliveryInf(144932, 216776), DeliveryInf(102816, 302682), DeliveryInf(296420, 251988), DeliveryInf(276129, 278083), DeliveryInf(177224, 235708), DeliveryInf(14746, 267668), DeliveryInf(292531, 281427), DeliveryInf(149673, 74115), DeliveryInf(295824, 265217), DeliveryInf(305210, 208226), DeliveryInf(143984, 248615), DeliveryInf(278017, 147867), DeliveryInf(300704, 294106), DeliveryInf(160557, 177275)};
        depots = {34, 131069, 2084, 141209};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR hard_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR hard_new_york_usa: INVALID" << std::endl;
        }

    } //hard_new_york_usa

} //hard_new_york_usa_public

