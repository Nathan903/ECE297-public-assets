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


SUITE(easy_new_york_usa_public) {
    TEST(easy_new_york_usa) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(295640, 105154), DeliveryInf(152333, 227333), DeliveryInf(239150, 285273), DeliveryInf(55069, 75200), DeliveryInf(59814, 262066), DeliveryInf(176941, 66275), DeliveryInf(82817, 98199), DeliveryInf(277401, 167913), DeliveryInf(272704, 195085), DeliveryInf(194186, 271927), DeliveryInf(303734, 77656), DeliveryInf(164972, 249316), DeliveryInf(222126, 57429), DeliveryInf(215331, 91491), DeliveryInf(274772, 255396), DeliveryInf(132159, 20785), DeliveryInf(243146, 113864), DeliveryInf(209991, 239602), DeliveryInf(278644, 147094), DeliveryInf(175433, 164863), DeliveryInf(85749, 177439), DeliveryInf(71070, 246207), DeliveryInf(217215, 167713), DeliveryInf(167990, 206802), DeliveryInf(230189, 86592)};
        depots = {20, 78641, 247875, 208038};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR easy_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR easy_new_york_usa: INVALID" << std::endl;
        }

    } //easy_new_york_usa

} //easy_new_york_usa_public

