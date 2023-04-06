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


SUITE(extreme_multi_london_england_public) {
    TEST(extreme_multi_london_england) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        float turn_penalty;
        std::vector<CourierSubPath> result_path;
        bool is_legal;

        deliveries = {DeliveryInf(33003, 94772), DeliveryInf(46806, 125055), DeliveryInf(258138, 225362), DeliveryInf(267482, 111824), DeliveryInf(280505, 111824), DeliveryInf(64375, 151517), DeliveryInf(139546, 294651), DeliveryInf(78893, 57710), DeliveryInf(167844, 208768), DeliveryInf(113833, 74030), DeliveryInf(167844, 111824), DeliveryInf(167844, 51789), DeliveryInf(134273, 211097), DeliveryInf(187953, 306607), DeliveryInf(170164, 312820), DeliveryInf(41653, 252063), DeliveryInf(64832, 168837), DeliveryInf(124055, 294651), DeliveryInf(112103, 173654), DeliveryInf(33003, 220177), DeliveryInf(10699, 128471), DeliveryInf(258138, 31816), DeliveryInf(338369, 270308), DeliveryInf(233036, 294651), DeliveryInf(182280, 137090), DeliveryInf(46806, 254998), DeliveryInf(223001, 310204), DeliveryInf(182280, 323488), DeliveryInf(111708, 221019), DeliveryInf(41964, 179321), DeliveryInf(322102, 270308), DeliveryInf(344473, 295017), DeliveryInf(161343, 293572), DeliveryInf(85566, 61201), DeliveryInf(182280, 78666), DeliveryInf(132722, 120048), DeliveryInf(170164, 205701), DeliveryInf(182280, 158381), DeliveryInf(33003, 161431), DeliveryInf(46806, 178871), DeliveryInf(179895, 139389), DeliveryInf(222647, 57710), DeliveryInf(164716, 26510), DeliveryInf(182280, 205701), DeliveryInf(33003, 143881), DeliveryInf(167844, 258127), DeliveryInf(328823, 171447), DeliveryInf(326308, 335706), DeliveryInf(170164, 4211), DeliveryInf(72989, 218188), DeliveryInf(11731, 111824), DeliveryInf(33003, 120115), DeliveryInf(158761, 98049), DeliveryInf(239081, 169111), DeliveryInf(167844, 120048), DeliveryInf(319997, 4211), DeliveryInf(260402, 208126), DeliveryInf(170164, 231837), DeliveryInf(201925, 21291), DeliveryInf(263826, 74030), DeliveryInf(69028, 201425), DeliveryInf(170164, 13101), DeliveryInf(260381, 315638), DeliveryInf(258138, 201425), DeliveryInf(46806, 193381), DeliveryInf(172569, 300912), DeliveryInf(338369, 315531), DeliveryInf(214764, 201425), DeliveryInf(143848, 254998), DeliveryInf(243829, 240095), DeliveryInf(33003, 85686), DeliveryInf(182280, 122510), DeliveryInf(180706, 254998), DeliveryInf(124750, 190587), DeliveryInf(89730, 11757), DeliveryInf(262179, 208126), DeliveryInf(111901, 4211), DeliveryInf(185587, 310204), DeliveryInf(104213, 254998), DeliveryInf(33003, 320679), DeliveryInf(188392, 96377), DeliveryInf(74767, 208126), DeliveryInf(109673, 111824), DeliveryInf(95491, 172865), DeliveryInf(180734, 240458), DeliveryInf(46806, 310204), DeliveryInf(247133, 120048), DeliveryInf(167844, 28326), DeliveryInf(263210, 201425), DeliveryInf(188162, 190470), DeliveryInf(207165, 137090), DeliveryInf(258138, 4211), DeliveryInf(46806, 205701), DeliveryInf(64832, 320635), DeliveryInf(14129, 273670), DeliveryInf(61009, 303131), DeliveryInf(182280, 187505), DeliveryInf(236599, 274842), DeliveryInf(227625, 105753), DeliveryInf(321352, 274842), DeliveryInf(330538, 285859), DeliveryInf(217130, 208126), DeliveryInf(182280, 91721), DeliveryInf(138387, 284101), DeliveryInf(46806, 289830), DeliveryInf(258138, 294651), DeliveryInf(258138, 150789), DeliveryInf(57566, 57710), DeliveryInf(46806, 60319), DeliveryInf(170164, 21291), DeliveryInf(105102, 57710), DeliveryInf(258138, 4211), DeliveryInf(239600, 183450), DeliveryInf(304282, 146295), DeliveryInf(33003, 147253), DeliveryInf(235413, 8723), DeliveryInf(46806, 294651), DeliveryInf(277853, 102690), DeliveryInf(258138, 207284), DeliveryInf(167844, 310197), DeliveryInf(339931, 221522), DeliveryInf(308501, 273922), DeliveryInf(170164, 254998), DeliveryInf(170164, 137090), DeliveryInf(333939, 88391), DeliveryInf(333939, 194564), DeliveryInf(258138, 119603), DeliveryInf(137898, 203053), DeliveryInf(64832, 204394), DeliveryInf(330754, 63552)};
        depots = {63};
        turn_penalty = 30.000000000;
        {
        	ECE297_TIME_CONSTRAINT(50000);
        	
        	result_path = travelingCourier(deliveries, depots, turn_penalty);
        }

        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);

        if(is_legal) {
        	double path_cost = ece297test::compute_courier_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR extreme_multi_london_england: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR extreme_multi_london_england: INVALID" << std::endl;
        }

    } //extreme_multi_london_england

} //extreme_multi_london_england_public

