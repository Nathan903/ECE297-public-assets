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


SUITE(simple_legality_new_york_usa_public) {
    TEST(simple_legality_new_york_usa) {
        std::vector<DeliveryInf> deliveries;
        std::vector<IntersectionIdx> depots;
        std::vector<CourierSubPath> result_path;
        float turn_penalty;

        deliveries = {DeliveryInf(52427, 62490)};
        depots = {13};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(48718, 107351), DeliveryInf(57593, 41126), DeliveryInf(205131, 240324)};
        depots = {22997, 2566, 288189};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(51770, 111809), DeliveryInf(71950, 48795)};
        depots = {137868, 172863};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(116617, 27296)};
        depots = {243806, 178669};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(190182, 9182)};
        depots = {268970, 255653};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(245396, 162097)};
        depots = {9233};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(29638, 242728), DeliveryInf(251131, 140032), DeliveryInf(151458, 198233), DeliveryInf(197937, 89547), DeliveryInf(145607, 146237)};
        depots = {108361, 103764, 175219};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(50699, 190866), DeliveryInf(56673, 7221)};
        depots = {150140};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(67504, 266514)};
        depots = {56974, 57728};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(68160, 267952), DeliveryInf(196711, 267952), DeliveryInf(68160, 121156), DeliveryInf(196711, 87115), DeliveryInf(186098, 121156), DeliveryInf(196711, 206648), DeliveryInf(196711, 267952), DeliveryInf(186384, 121156), DeliveryInf(104411, 251873)};
        depots = {28633, 158764, 165321};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(81729, 77124), DeliveryInf(184314, 167532), DeliveryInf(59146, 91302), DeliveryInf(57368, 122048), DeliveryInf(57368, 166768), DeliveryInf(93268, 54782), DeliveryInf(57368, 244385), DeliveryInf(184314, 244560)};
        depots = {54076, 93041, 157232};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(95122, 145272), DeliveryInf(271410, 257892), DeliveryInf(59348, 259154), DeliveryInf(249003, 71800), DeliveryInf(204409, 220707)};
        depots = {98105, 149576, 250217};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(101538, 25496), DeliveryInf(122080, 150460), DeliveryInf(137209, 70910), DeliveryInf(137209, 104900), DeliveryInf(4473, 44074), DeliveryInf(137209, 64473), DeliveryInf(4473, 127123), DeliveryInf(107067, 225566)};
        depots = {144946, 298751, 287007};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(139235, 195168), DeliveryInf(73456, 37514), DeliveryInf(73399, 297995), DeliveryInf(42314, 297054), DeliveryInf(189463, 37514), DeliveryInf(295447, 37514), DeliveryInf(192138, 297054), DeliveryInf(250551, 223182)};
        depots = {30500, 234077, 44724};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(248870, 197169), DeliveryInf(144977, 108510), DeliveryInf(101926, 149643), DeliveryInf(248870, 108510), DeliveryInf(107539, 202344), DeliveryInf(248870, 108510), DeliveryInf(248870, 41175), DeliveryInf(144977, 149643), DeliveryInf(243276, 149643)};
        depots = {22499, 10490, 203820};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(303583, 168226), DeliveryInf(44183, 118292)};
        depots = {61378, 212668};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(101555, 220721), DeliveryInf(250844, 181285)};
        depots = {94333};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(153666, 85092), DeliveryInf(284476, 211790), DeliveryInf(122319, 272429), DeliveryInf(127539, 110385), DeliveryInf(112375, 282024)};
        depots = {10501, 83640, 184878};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(195843, 127799), DeliveryInf(276891, 32221), DeliveryInf(110224, 64553), DeliveryInf(294629, 125247), DeliveryInf(206676, 64553), DeliveryInf(21454, 32221), DeliveryInf(13198, 64553), DeliveryInf(203452, 271351)};
        depots = {31483, 210622, 147853};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(180947, 253680), DeliveryInf(187134, 257381), DeliveryInf(286365, 191144), DeliveryInf(39237, 191144), DeliveryInf(34655, 145519), DeliveryInf(276567, 70159), DeliveryInf(297539, 253680), DeliveryInf(137008, 191144)};
        depots = {36943, 214023, 2572};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(202502, 90976), DeliveryInf(181504, 44430), DeliveryInf(20069, 278953), DeliveryInf(5800, 94283), DeliveryInf(20069, 180423), DeliveryInf(254350, 174877), DeliveryInf(20069, 52615), DeliveryInf(202502, 172889)};
        depots = {156049, 118747, 196713};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(206454, 281017), DeliveryInf(46993, 79411), DeliveryInf(107604, 272382)};
        depots = {47510, 101068, 122400};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(302611, 70019), DeliveryInf(228521, 75375), DeliveryInf(106450, 70316)};
        depots = {117678, 101978, 282722};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(11220, 266539), DeliveryInf(21379, 177862), DeliveryInf(270161, 54066), DeliveryInf(233087, 51985), DeliveryInf(303539, 198844)};
        depots = {232999, 108537, 283322};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(78904, 277319), DeliveryInf(30922, 252193), DeliveryInf(247393, 72942), DeliveryInf(128326, 150752), DeliveryInf(14280, 29190)};
        depots = {187461, 292572, 108143};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(184207, 214163), DeliveryInf(184207, 253508), DeliveryInf(5022, 253508), DeliveryInf(122548, 214163), DeliveryInf(122548, 295195), DeliveryInf(122548, 42777), DeliveryInf(127352, 253508), DeliveryInf(64543, 118247), DeliveryInf(122548, 214163)};
        depots = {157672, 159431, 304567};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(184405, 132962), DeliveryInf(131848, 291707), DeliveryInf(280491, 223022), DeliveryInf(51826, 191), DeliveryInf(286119, 291084)};
        depots = {243167, 143780, 87836};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(270573, 254013), DeliveryInf(252105, 303536)};
        depots = {147550, 193681};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(287694, 183181), DeliveryInf(262686, 246314)};
        depots = {232217};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

        deliveries = {DeliveryInf(288523, 116955)};
        depots = {241452};
        turn_penalty = 30.000000000;
        result_path = travelingCourier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));

    } //simple_legality_new_york_usa

} //simple_legality_new_york_usa_public

