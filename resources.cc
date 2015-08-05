// Copyright 2013 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// Resources definitions.
//
// Automatically generated with:
// make resources


#include "resources.h"

namespace batumi {

static const char str_dummy[] = "dummy";


const char* string_table[] = {
  str_dummy,
};



const uint16_t* lookup_table_table[] = {
};

const uint32_t lut_increments[] = {
  4286473, 4317534, 4348821, 4380334,
  4412076, 4444048, 4476251, 4508688,
  4541360, 4574268, 4607415, 4640803,
  4674432, 4708305, 4742423, 4776788,
  4811403, 4846268, 4881387, 4916759,
  4952388, 4988275, 5024422, 5060831,
  5097504, 5134443, 5171649, 5209125,
  5246872, 5284893, 5323190, 5361764,
  5400617, 5439752, 5479171, 5518876,
  5558868, 5599149, 5639723, 5680591,
  5721755, 5763217, 5804980, 5847045,
  5889415, 5932092, 5975079, 6018376,
  6061988, 6105916, 6150162, 6194728,
  6239618, 6284833, 6330375, 6376248,
  6422453, 6468992, 6515869, 6563086,
  6610645, 6658548, 6706799, 6755399,
  6804352, 6853659, 6903323, 6953348,
  7003734, 7054486, 7105606, 7157096,
  7208960, 7261199, 7313816, 7366815,
  7420198, 7473968, 7528127, 7582679,
  7637627, 7692972, 7748718, 7804869,
  7861426, 7918393, 7975773, 8033569,
  8091784, 8150420, 8209481, 8268971,
  8328891, 8389245, 8450037, 8511270,
  8572946,
};
const uint32_t lut_lfo_increments[] = {
  2621439, 2633255, 2645124, 2657047,
  2669023, 2681053, 2693138, 2705277,
  2717471, 2729719, 2742023, 2754382,
  2766797, 2779268, 2791795, 2804379,
  2817019, 2829717, 2842471, 2855283,
  2868153, 2881081, 2894067, 2907112,
  2920215, 2933378, 2946599, 2959881,
  2973222, 2986623, 3000085, 3013608,
  3027191, 3040836, 3054542, 3068310,
  3082140, 3096032, 3109987, 3124005,
  3138086, 3152231, 3166439, 3180711,
  3195048, 3209449, 3223915, 3238447,
  3253043, 3267706, 3282435, 3297230,
  3312092, 3327021, 3342017, 3357080,
  3372212, 3387412, 3402680, 3418017,
  3433423, 3448899, 3464445, 3480060,
  3495746, 3511503, 3527330, 3543229,
  3559200, 3575242, 3591357, 3607545,
  3623805, 3640139, 3656547, 3673028,
  3689584, 3706214, 3722919, 3739700,
  3756556, 3773488, 3790497, 3807582,
  3824744, 3841983, 3859301, 3876696,
  3894170, 3911722, 3929354, 3947065,
  3964856, 3982727, 4000678, 4018711,
  4036824, 4055020, 4073297, 4091657,
  4110100, 4128626, 4147235, 4165928,
  4184705, 4203567, 4222514, 4241547,
  4260665, 4279869, 4299160, 4318538,
  4338003, 4357556, 4377197, 4396927,
  4416745, 4436653, 4456651, 4476739,
  4496917, 4517186, 4537547, 4557999,
  4578544, 4599181, 4619911, 4640735,
  4661652, 4682664, 4703771, 4724972,
  4746269, 4767662, 4789152, 4810739,
  4832422, 4854204, 4876083, 4898062,
  4920139, 4942316, 4964593, 4986970,
  5009448, 5032027, 5054709, 5077492,
  5100378, 5123367, 5146460, 5169657,
  5192959, 5216365, 5239877, 5263495,
  5287220, 5311051, 5334990, 5359037,
  5383192, 5407456, 5431830, 5456313,
  5480906, 5505611, 5530427, 5555354,
  5580394, 5605547, 5630813, 5656194,
  5681688, 5707297, 5733022, 5758863,
  5784820, 5810895, 5837087, 5863396,
  5889825, 5916373, 5943040, 5969827,
  5996735, 6023765, 6050916, 6078190,
  6105586, 6133107, 6160751, 6188519,
  6216413, 6244433, 6272579, 6300852,
  6329252, 6357780, 6386437, 6415223,
  6444139, 6473185, 6502362, 6531670,
  6561111, 6590684, 6620391, 6650232,
  6680207, 6710317, 6740562, 6770945,
  6801464, 6832120, 6862915, 6893849,
  6924922, 6956135, 6987489, 7018984,
  7050621, 7082401, 7114324, 7146391,
  7178602, 7210959, 7243461, 7276110,
  7308906, 7341850, 7374943, 7408184,
  7441576, 7475117, 7508810, 7542655,
  7576653, 7610804, 7645108, 7679568,
  7714182, 7748953, 7783880, 7818965,
  7854208, 7889610, 7925171, 7960893,
  7996775, 8032820, 8069027, 8105397,
  8141931, 8178629, 8215493, 8252524,
  8289721, 8327085, 8364619, 8402321,
  8440193, 8478236, 8516451, 8554838,
  8593397, 8632131, 8671039, 8710123,
  8749382, 8788819, 8828433, 8868226,
  8908199, 8948351, 8988685, 9029200,
  9069898, 9110779, 9151845, 9193096,
  9234532, 9276156, 9317967, 9359966,
  9402155, 9444534, 9487104, 9529866,
  9572820, 9615968, 9659311, 9702849,
  9746583, 9790515, 9834644, 9878972,
  9923501, 9968229, 10013160, 10058293,
  10103629, 10149170, 10194916, 10240868,
  10287028, 10333395, 10379971, 10426758,
  10473755, 10520964, 10568386, 10616021,
  10663871, 10711937, 10760220, 10808720,
  10857439, 10906378, 10955537, 11004917,
  11054520, 11104347, 11154398, 11204675,
  11255179, 11305910, 11356870, 11408060,
  11459480, 11511132, 11563017, 11615135,
  11667489, 11720079, 11772905, 11825970,
  11879274, 11932818, 11986604, 12040632,
  12094903, 12149420, 12204181, 12259190,
  12314447, 12369952, 12425708, 12481716,
  12537975, 12594488, 12651256, 12708280,
  12765561, 12823100, 12880898, 12938957,
  12997278, 13055861, 13114709, 13173822,
  13233201, 13292848, 13352763, 13412949,
  13473406, 13534136, 13595139, 13656417,
  13717972, 13779804, 13841914, 13904305,
  13966977, 14029931, 14093169, 14156692,
  14220501, 14284598, 14348984, 14413660,
  14478628, 14543888, 14609443, 14675293,
  14741440, 14807885, 14874630, 14941675,
  15009022, 15076674, 15144630, 15212892,
  15281462, 15350341, 15419531, 15489032,
  15558847, 15628976, 15699422, 15770185,
  15841267, 15912669, 15984393, 16056441,
  16128813, 16201512, 16274538, 16347893,
  16421579, 16495597, 16569949, 16644635,
  16719659, 16795020, 16870722, 16946764,
  17023149, 17099879, 17176954, 17254377,
  17332149, 17410271, 17488746, 17567574,
  17646757, 17726298, 17806196, 17886455,
  17967076, 18048060, 18129410, 18211125,
  18293210, 18375664, 18458490, 18541689,
  18625263, 18709214, 18793543, 18878252,
  18963343, 19048818, 19134678, 19220925,
  19307561, 19394587, 19482005, 19569818,
  19658026, 19746632, 19835637, 19925044,
  20014853, 20105068, 20195688, 20286718,
  20378157, 20470009, 20562275, 20654957,
  20748056, 20841575, 20935516, 21029880,
  21124669, 21219886, 21315531, 21411608,
  21508118, 21605063, 21702445, 21800266,
  21898527, 21997232, 22096382, 22195978,
  22296023, 22396520, 22497469, 22598873,
  22700735, 22803055, 22905837, 23009082,
  23112792, 23216970, 23321617, 23426736,
  23532329, 23638398, 23744945, 23851972,
  23959481, 24067475, 24175956, 24284926,
  24394387, 24504342, 24614792, 24725739,
  24837187, 24949138, 25061592, 25174554,
  25288025, 25402007, 25516504, 25631516,
  25747046, 25863098, 25979672, 26096772,
  26214400, 26332557, 26451248, 26570473,
  26690236, 26810539, 26931383, 27052773,
  27174710, 27297196, 27420234, 27543827,
  27667978, 27792687, 27917959, 28043795,
  28170199, 28297172, 28424718, 28552839,
  28681537, 28810815, 28940676, 29071122,
  29202156, 29333781, 29465999, 29598813,
  29732225, 29866239, 30000857, 30136082,
  30271916, 30408363, 30545424, 30683104,
  30821404, 30960327, 31099877, 31240055,
  31380865, 31522310, 31664393, 31807116,
  31950482, 32094495, 32239156, 32384470,
  32530438, 32677065, 32824352, 32972304,
  33120922, 33270210, 33420171, 33570808,
  33722124, 33874121, 34026804, 34180176,
  34334238, 34488995, 34644450, 34800605,
  34957464, 35115030, 35273306, 35432296,
  35592002, 35752428, 35913577, 36075453,
  36238058, 36401396, 36565471, 36730284,
  36895841, 37062144, 37229197, 37397002,
  37565564, 37734886, 37904971, 38075822,
  38247444, 38419839, 38593011, 38766964,
  38941701, 39117225, 39293541, 39470651,
  39648560, 39827270, 40006786, 40187111,
  40368249, 40550204, 40732978, 40916577,
  41101003, 41286260, 41472352, 41659283,
  41847057, 42035677, 42225147, 42415471,
  42606653, 42798696, 42991606, 43185385,
  43380037, 43575567, 43771977, 43969274,
  44167459, 44366538, 44566514, 44767392,
  44969175, 45171867, 45375473, 45579997,
  45785443, 45991814, 46199116, 46407352,
  46616527, 46826645, 47037710, 47249726,
  47462698, 47676629, 47891525, 48107390,
  48324227, 48542042, 48760839, 48980622,
  49201395, 49423164, 49645932, 49869704,
  50094485, 50320279, 50547091, 50774925,
  51003786, 51233679, 51464608, 51696578,
  51929593, 52163658, 52398779, 52634959,
  52872204, 53110519, 53349907, 53590375,
  53831926, 54074566, 54318300, 54563132,
  54809068, 55056113, 55304270, 55553547,
  55803947, 56055476, 56308138, 56561940,
  56816885, 57072979, 57330228, 57588636,
  57848209, 58108952, 58370870, 58633969,
  58898254, 59163730, 59430402, 59698277,
  59967358, 60237653, 60509166, 60781903,
  61055869, 61331070, 61607512, 61885199,
  62164138, 62444335, 62725794, 63008522,
  63292525, 63577807, 63864375, 64152235,
  64441393, 64731854, 65023624, 65316709,
  65611115, 65906848, 66203914, 66502320,
  66802070, 67103171, 67405629, 67709451,
  68014642, 68321209, 68629158, 68938494,
  69249225, 69561357, 69874895, 70189847,
  70506218, 70824015, 71143245, 71463913,
  71786027, 72109593, 72434617, 72761106,
  73089067, 73418506, 73749430, 74081846,
  74415760, 74751179, 75088109, 75426559,
  75766534, 76108041, 76451088, 76795681,
  77141827, 77489533, 77838807, 78189655,
  78542084, 78896102, 79251715, 79608931,
  79967758, 80328202, 80690270, 81053971,
  81419310, 81786297, 82154937, 82525240,
  82897211, 83270859, 83646191, 84023215,
  84401938, 84782368, 85164513, 85548381,
  85933979, 86321314, 86710396, 87101231,
  87493828, 87888195, 88284339, 88682269,
  89081992, 89483517, 89886852, 90292004,
  90698983, 91107797, 91518453, 91930960,
  92345326, 92761560, 93179670, 93599665,
  94021553, 94445342, 94871042, 95298660,
  95728206, 96159688, 96593115, 97028495,
  97465838, 97905152, 98346446, 98789729,
  99235010, 99682299, 100131603, 100582933,
  101036297, 101491704, 101949164, 102408686,
  102870280, 103333953, 103799717, 104267580,
  104737552, 105209643, 105683861, 106160216,
  106638719, 107119379, 107602205, 108087207,
  108574395, 109063780, 109555370, 110049176,
  110545208, 111043475, 111543989, 112046758,
  112551794, 113059105, 113568704, 114080600,
  114594802, 115111323, 115630172, 116151359,
  116674895, 117200792, 117729058, 118259706,
  118792746, 119328188, 119866043, 120406323,
  120949038, 121494200, 122041818, 122591905,
  123144472, 123699529, 124257088, 124817160,
  125379756, 125944888, 126512568, 127082806,
  127655614, 128231005, 128808989, 129389578,
  129972784, 130558618, 131147094, 131738221,
  132332013, 132928482, 133527639, 134129497,
  134734067, 135341363, 135951396, 136564178,
  137179723, 137798042, 138419148, 139043053,
  139669771, 140299313, 140931693, 141566924,
  142205018, 142845987, 143489846, 144136607,
  144786284, 145438888, 146094434, 146752935,
  147414404, 148078854, 148746300, 149416753,
  150090229, 150766740, 151446301, 152128925,
  152814625, 153503416, 154195312, 154890327,
  155588474, 156289768, 156994223, 157701853,
  158412672, 159126696, 159843938, 160564413,
  161288135, 162015120, 162745381, 163478933,
  164215793, 164955973, 165699490, 166446358,
  167196592, 167950208, 168707221, 169467646,
  170231498, 170998793, 171769547, 172543775,
  173321493, 174102716, 174887460, 175675742,
  176467576, 177262980, 178061969, 178864559,
  179670767, 180480608, 181294100, 182111259,
  182932100, 183756642, 184584900, 185416891,
  186252633, 187092141, 187935434, 188782527,
  189633439, 190488186, 191346786, 192209255,
  193075612, 193945874, 194820059, 195698184,
  196580267, 197466326, 198356379, 199250443,
  200148537, 201050680, 201956888, 202867182,
  203781578, 204700096, 205622754, 206549570,
  207480564, 208415755, 209355161, 210298801,
  211246694, 212198860, 213155317, 214116086,
  215081185, 216050634, 217024453, 218002662,
  218985279, 219972325, 220963821, 221959785,
  222960239, 223965202, 224974695, 225988738,
  227007351, 228030556, 229058373, 230090822,
  231127925, 232169703, 233216177, 234267367,
  235323295, 236383983, 237449452, 238519723,
  239594818, 240674759, 241759568, 242849266,
  243943877, 245043421, 246147920, 247257399,
  248371878, 249491380, 250615929, 251745546,
  252880255, 254020079, 255165040, 256315161,
  257470467, 258630980, 259796724, 260967723,
  262144000,
};


const uint32_t* lookup_table_32_table[] = {
  lut_increments,
  lut_lfo_increments,
};

const int16_t wav_sine[] = {
       0,    201,    402,    603,
     804,   1005,   1206,   1406,
    1607,   1808,   2009,   2209,
    2410,   2610,   2811,   3011,
    3211,   3411,   3611,   3811,
    4011,   4210,   4409,   4608,
    4807,   5006,   5205,   5403,
    5601,   5799,   5997,   6195,
    6392,   6589,   6786,   6982,
    7179,   7375,   7571,   7766,
    7961,   8156,   8351,   8545,
    8739,   8932,   9126,   9319,
    9511,   9703,   9895,  10087,
   10278,  10469,  10659,  10849,
   11038,  11227,  11416,  11604,
   11792,  11980,  12166,  12353,
   12539,  12724,  12909,  13094,
   13278,  13462,  13645,  13827,
   14009,  14191,  14372,  14552,
   14732,  14911,  15090,  15268,
   15446,  15623,  15799,  15975,
   16150,  16325,  16499,  16672,
   16845,  17017,  17189,  17360,
   17530,  17699,  17868,  18036,
   18204,  18371,  18537,  18702,
   18867,  19031,  19194,  19357,
   19519,  19680,  19840,  20000,
   20159,  20317,  20474,  20631,
   20787,  20942,  21096,  21249,
   21402,  21554,  21705,  21855,
   22004,  22153,  22301,  22448,
   22594,  22739,  22883,  23027,
   23169,  23311,  23452,  23592,
   23731,  23869,  24006,  24143,
   24278,  24413,  24546,  24679,
   24811,  24942,  25072,  25201,
   25329,  25456,  25582,  25707,
   25831,  25954,  26077,  26198,
   26318,  26437,  26556,  26673,
   26789,  26905,  27019,  27132,
   27244,  27355,  27466,  27575,
   27683,  27790,  27896,  28001,
   28105,  28208,  28309,  28410,
   28510,  28608,  28706,  28802,
   28897,  28992,  29085,  29177,
   29268,  29358,  29446,  29534,
   29621,  29706,  29790,  29873,
   29955,  30036,  30116,  30195,
   30272,  30349,  30424,  30498,
   30571,  30643,  30713,  30783,
   30851,  30918,  30984,  31049,
   31113,  31175,  31236,  31297,
   31356,  31413,  31470,  31525,
   31580,  31633,  31684,  31735,
   31785,  31833,  31880,  31926,
   31970,  32014,  32056,  32097,
   32137,  32176,  32213,  32249,
   32284,  32318,  32350,  32382,
   32412,  32441,  32468,  32495,
   32520,  32544,  32567,  32588,
   32609,  32628,  32646,  32662,
   32678,  32692,  32705,  32717,
   32727,  32736,  32744,  32751,
   32757,  32761,  32764,  32766,
   32767,  32766,  32764,  32761,
   32757,  32751,  32744,  32736,
   32727,  32717,  32705,  32692,
   32678,  32662,  32646,  32628,
   32609,  32588,  32567,  32544,
   32520,  32495,  32468,  32441,
   32412,  32382,  32350,  32318,
   32284,  32249,  32213,  32176,
   32137,  32097,  32056,  32014,
   31970,  31926,  31880,  31833,
   31785,  31735,  31684,  31633,
   31580,  31525,  31470,  31413,
   31356,  31297,  31236,  31175,
   31113,  31049,  30984,  30918,
   30851,  30783,  30713,  30643,
   30571,  30498,  30424,  30349,
   30272,  30195,  30116,  30036,
   29955,  29873,  29790,  29706,
   29621,  29534,  29446,  29358,
   29268,  29177,  29085,  28992,
   28897,  28802,  28706,  28608,
   28510,  28410,  28309,  28208,
   28105,  28001,  27896,  27790,
   27683,  27575,  27466,  27355,
   27244,  27132,  27019,  26905,
   26789,  26673,  26556,  26437,
   26318,  26198,  26077,  25954,
   25831,  25707,  25582,  25456,
   25329,  25201,  25072,  24942,
   24811,  24679,  24546,  24413,
   24278,  24143,  24006,  23869,
   23731,  23592,  23452,  23311,
   23169,  23027,  22883,  22739,
   22594,  22448,  22301,  22153,
   22004,  21855,  21705,  21554,
   21402,  21249,  21096,  20942,
   20787,  20631,  20474,  20317,
   20159,  20000,  19840,  19680,
   19519,  19357,  19194,  19031,
   18867,  18702,  18537,  18371,
   18204,  18036,  17868,  17699,
   17530,  17360,  17189,  17017,
   16845,  16672,  16499,  16325,
   16150,  15975,  15799,  15623,
   15446,  15268,  15090,  14911,
   14732,  14552,  14372,  14191,
   14009,  13827,  13645,  13462,
   13278,  13094,  12909,  12724,
   12539,  12353,  12166,  11980,
   11792,  11604,  11416,  11227,
   11038,  10849,  10659,  10469,
   10278,  10087,   9895,   9703,
    9511,   9319,   9126,   8932,
    8739,   8545,   8351,   8156,
    7961,   7766,   7571,   7375,
    7179,   6982,   6786,   6589,
    6392,   6195,   5997,   5799,
    5601,   5403,   5205,   5006,
    4807,   4608,   4409,   4210,
    4011,   3811,   3611,   3411,
    3211,   3011,   2811,   2610,
    2410,   2209,   2009,   1808,
    1607,   1406,   1206,   1005,
     804,    603,    402,    201,
       0,   -201,   -402,   -603,
    -804,  -1005,  -1206,  -1406,
   -1607,  -1808,  -2009,  -2209,
   -2410,  -2610,  -2811,  -3011,
   -3211,  -3411,  -3611,  -3811,
   -4011,  -4210,  -4409,  -4608,
   -4807,  -5006,  -5205,  -5403,
   -5601,  -5799,  -5997,  -6195,
   -6392,  -6589,  -6786,  -6982,
   -7179,  -7375,  -7571,  -7766,
   -7961,  -8156,  -8351,  -8545,
   -8739,  -8932,  -9126,  -9319,
   -9511,  -9703,  -9895, -10087,
  -10278, -10469, -10659, -10849,
  -11038, -11227, -11416, -11604,
  -11792, -11980, -12166, -12353,
  -12539, -12724, -12909, -13094,
  -13278, -13462, -13645, -13827,
  -14009, -14191, -14372, -14552,
  -14732, -14911, -15090, -15268,
  -15446, -15623, -15799, -15975,
  -16150, -16325, -16499, -16672,
  -16845, -17017, -17189, -17360,
  -17530, -17699, -17868, -18036,
  -18204, -18371, -18537, -18702,
  -18867, -19031, -19194, -19357,
  -19519, -19680, -19840, -20000,
  -20159, -20317, -20474, -20631,
  -20787, -20942, -21096, -21249,
  -21402, -21554, -21705, -21855,
  -22004, -22153, -22301, -22448,
  -22594, -22739, -22883, -23027,
  -23169, -23311, -23452, -23592,
  -23731, -23869, -24006, -24143,
  -24278, -24413, -24546, -24679,
  -24811, -24942, -25072, -25201,
  -25329, -25456, -25582, -25707,
  -25831, -25954, -26077, -26198,
  -26318, -26437, -26556, -26673,
  -26789, -26905, -27019, -27132,
  -27244, -27355, -27466, -27575,
  -27683, -27790, -27896, -28001,
  -28105, -28208, -28309, -28410,
  -28510, -28608, -28706, -28802,
  -28897, -28992, -29085, -29177,
  -29268, -29358, -29446, -29534,
  -29621, -29706, -29790, -29873,
  -29955, -30036, -30116, -30195,
  -30272, -30349, -30424, -30498,
  -30571, -30643, -30713, -30783,
  -30851, -30918, -30984, -31049,
  -31113, -31175, -31236, -31297,
  -31356, -31413, -31470, -31525,
  -31580, -31633, -31684, -31735,
  -31785, -31833, -31880, -31926,
  -31970, -32014, -32056, -32097,
  -32137, -32176, -32213, -32249,
  -32284, -32318, -32350, -32382,
  -32412, -32441, -32468, -32495,
  -32520, -32544, -32567, -32588,
  -32609, -32628, -32646, -32662,
  -32678, -32692, -32705, -32717,
  -32727, -32736, -32744, -32751,
  -32757, -32761, -32764, -32766,
  -32767, -32766, -32764, -32761,
  -32757, -32751, -32744, -32736,
  -32727, -32717, -32705, -32692,
  -32678, -32662, -32646, -32628,
  -32609, -32588, -32567, -32544,
  -32520, -32495, -32468, -32441,
  -32412, -32382, -32350, -32318,
  -32284, -32249, -32213, -32176,
  -32137, -32097, -32056, -32014,
  -31970, -31926, -31880, -31833,
  -31785, -31735, -31684, -31633,
  -31580, -31525, -31470, -31413,
  -31356, -31297, -31236, -31175,
  -31113, -31049, -30984, -30918,
  -30851, -30783, -30713, -30643,
  -30571, -30498, -30424, -30349,
  -30272, -30195, -30116, -30036,
  -29955, -29873, -29790, -29706,
  -29621, -29534, -29446, -29358,
  -29268, -29177, -29085, -28992,
  -28897, -28802, -28706, -28608,
  -28510, -28410, -28309, -28208,
  -28105, -28001, -27896, -27790,
  -27683, -27575, -27466, -27355,
  -27244, -27132, -27019, -26905,
  -26789, -26673, -26556, -26437,
  -26318, -26198, -26077, -25954,
  -25831, -25707, -25582, -25456,
  -25329, -25201, -25072, -24942,
  -24811, -24679, -24546, -24413,
  -24278, -24143, -24006, -23869,
  -23731, -23592, -23452, -23311,
  -23169, -23027, -22883, -22739,
  -22594, -22448, -22301, -22153,
  -22004, -21855, -21705, -21554,
  -21402, -21249, -21096, -20942,
  -20787, -20631, -20474, -20317,
  -20159, -20000, -19840, -19680,
  -19519, -19357, -19194, -19031,
  -18867, -18702, -18537, -18371,
  -18204, -18036, -17868, -17699,
  -17530, -17360, -17189, -17017,
  -16845, -16672, -16499, -16325,
  -16150, -15975, -15799, -15623,
  -15446, -15268, -15090, -14911,
  -14732, -14552, -14372, -14191,
  -14009, -13827, -13645, -13462,
  -13278, -13094, -12909, -12724,
  -12539, -12353, -12166, -11980,
  -11792, -11604, -11416, -11227,
  -11038, -10849, -10659, -10469,
  -10278, -10087,  -9895,  -9703,
   -9511,  -9319,  -9126,  -8932,
   -8739,  -8545,  -8351,  -8156,
   -7961,  -7766,  -7571,  -7375,
   -7179,  -6982,  -6786,  -6589,
   -6392,  -6195,  -5997,  -5799,
   -5601,  -5403,  -5205,  -5006,
   -4807,  -4608,  -4409,  -4210,
   -4011,  -3811,  -3611,  -3411,
   -3211,  -3011,  -2811,  -2610,
   -2410,  -2209,  -2009,  -1808,
   -1607,  -1406,  -1206,  -1005,
    -804,   -603,   -402,   -201,
       0,
};


const int16_t* waveform_table[] = {
  wav_sine,
};


}  // namespace batumi