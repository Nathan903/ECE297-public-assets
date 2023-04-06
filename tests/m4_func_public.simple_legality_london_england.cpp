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


SUITE(simple_legality_london_england_public) {
    TEST(simple_legality_london_england) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        std::vector<CourierSubPath> result_path;
        float turn_penalty;

        deliveries = {DeliveryInf(59900, 71396)};
        depots = {15};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(55661, 122651), DeliveryInf(65802, 46988), DeliveryInf(234368, 274578)};
        depots = {26275, 2932, 329265};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(59149, 127745), DeliveryInf(82205, 55750)};
        depots = {157518, 197501};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(133238, 31187)};
        depots = {278556, 204135};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(217289, 10491)};
        depots = {307307, 292091};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(280372, 185201)};
        depots = {10549};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(33862, 277324), DeliveryInf(286924, 159991), DeliveryInf(173046, 226487), DeliveryInf(226149, 102310), DeliveryInf(166361, 167080)};
        depots = {123805, 118553, 200193};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(57925, 218070), DeliveryInf(64751, 8250)};
        depots = {171539};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(77125, 304500)};
        depots = {65095, 65956};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(77875, 306143), DeliveryInf(224748, 306143), DeliveryInf(77875, 138425), DeliveryInf(224748, 99532), DeliveryInf(212623, 138425), DeliveryInf(224748, 236102), DeliveryInf(224748, 306143), DeliveryInf(212949, 138425), DeliveryInf(119292, 287772)};
        depots = {32714, 181392, 188884};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(93377, 88117), DeliveryInf(210584, 191410), DeliveryInf(67577, 104315), DeliveryInf(65544, 139444), DeliveryInf(65544, 190537), DeliveryInf(106562, 62590), DeliveryInf(65544, 279217), DeliveryInf(210584, 279417)};
        depots = {61783, 106302, 179642};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(108680, 165977), DeliveryInf(310094, 294650), DeliveryInf(67807, 296091), DeliveryInf(284493, 82034), DeliveryInf(233543, 252164)};
        depots = {112088, 170894, 285880};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(116011, 29131), DeliveryInf(139480, 171905), DeliveryInf(156765, 81016), DeliveryInf(156765, 119851), DeliveryInf(5110, 50356), DeliveryInf(156765, 73662), DeliveryInf(5110, 145242), DeliveryInf(122327, 257716)};
        depots = {165606, 341332, 327914};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(159080, 222986), DeliveryInf(83926, 42861), DeliveryInf(83860, 340468), DeliveryInf(48345, 339392), DeliveryInf(216467, 42861), DeliveryInf(337557, 42861), DeliveryInf(219523, 339392), DeliveryInf(286262, 254992)};
        depots = {34847, 267440, 51098};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(284341, 225272), DeliveryInf(165641, 123975), DeliveryInf(116454, 170971), DeliveryInf(284341, 123975), DeliveryInf(122866, 231184), DeliveryInf(284341, 123975), DeliveryInf(284341, 47044), DeliveryInf(165641, 170971), DeliveryInf(277950, 170971)};
        depots = {25706, 11986, 232870};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(346853, 192203), DeliveryInf(50481, 135153)};
        depots = {70126, 242980};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(116030, 252180), DeliveryInf(286597, 207123)};
        depots = {107778};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(175568, 97220), DeliveryInf(325022, 241976), DeliveryInf(139753, 311258), DeliveryInf(145718, 126119), DeliveryInf(128392, 322221)};
        depots = {11997, 95562, 211228};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(223756, 146014), DeliveryInf(316356, 36813), DeliveryInf(125934, 73754), DeliveryInf(336622, 143099), DeliveryInf(236133, 73754), DeliveryInf(24512, 36813), DeliveryInf(15079, 73754), DeliveryInf(232450, 310027)};
        depots = {35970, 240641, 168927};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(206737, 289837), DeliveryInf(213807, 294065), DeliveryInf(327180, 218387), DeliveryInf(44830, 218387), DeliveryInf(39595, 166260), DeliveryInf(315985, 80158), DeliveryInf(339947, 289837), DeliveryInf(156535, 218387)};
        depots = {42209, 244527, 2939};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(231364, 103942), DeliveryInf(207373, 50763), DeliveryInf(22930, 318711), DeliveryInf(6627, 107721), DeliveryInf(22930, 206138), DeliveryInf(290603, 199802), DeliveryInf(22930, 60114), DeliveryInf(231364, 197531)};
        depots = {178290, 135672, 224750};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(235880, 321071), DeliveryInf(53691, 90729), DeliveryInf(122941, 311205)};
        depots = {54282, 115473, 139846};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(345741, 79999), DeliveryInf(261092, 86118), DeliveryInf(121623, 80338)};
        depots = {134451, 116513, 323018};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(12819, 304528), DeliveryInf(24426, 203212), DeliveryInf(308666, 61772), DeliveryInf(266309, 59395), DeliveryInf(346802, 227185)};
        depots = {266208, 124007, 323704};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(90150, 316845), DeliveryInf(35329, 288138), DeliveryInf(282654, 83338), DeliveryInf(146616, 172239), DeliveryInf(16316, 33351)};
        depots = {214180, 334272, 123557};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(210462, 244687), DeliveryInf(210462, 289640), DeliveryInf(5738, 289640), DeliveryInf(140015, 244687), DeliveryInf(140015, 337269), DeliveryInf(140015, 48874), DeliveryInf(145503, 289640), DeliveryInf(73743, 135101), DeliveryInf(140015, 244687)};
        depots = {180145, 182155, 347977};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(210688, 151913), DeliveryInf(150640, 333284), DeliveryInf(320469, 254809), DeliveryInf(59212, 218), DeliveryInf(326899, 332571)};
        depots = {277825, 164273, 100356};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(309138, 290218), DeliveryInf(288037, 346799)};
        depots = {168580, 221286};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(328699, 209290), DeliveryInf(300127, 281421)};
        depots = {265315};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(329646, 133624)};
        depots = {275866};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

    } //simple_legality_london_england

} //simple_legality_london_england_public

