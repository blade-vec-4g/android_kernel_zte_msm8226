/* 
*  This bmsdata for coslight and bak package battery is qcom battery characterize
*  4v35,2000mah,
*/
#include <linux/batterydata-lib.h>

static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {2043, 2068, 2066, 2059, 2043},
	.cols	= 5
};

static struct single_row_lut fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct sf_lut rbatt_sf = {
	.rows		= 31,
	.cols		= 5,
	.row_entries		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.sf		= {
				{1015, 228, 100, 83, 76},
				{1013, 228, 100, 83, 76},
				{946, 238, 102, 85, 76},
				{889, 246, 106, 86, 78},
				{898, 246, 110, 90, 80},
				{801, 258, 118, 93, 82},
				{805, 223, 121, 97, 85},
				{810, 226, 126, 101, 87},
				{812, 225, 115, 100, 88},
				{822, 223, 103, 89, 81},
				{855, 225, 100, 85, 79},
				{905, 227, 102, 86, 80},
				{974, 230, 103, 90, 81},
				{1055, 235, 105, 91, 84},
				{1146, 244, 106, 89, 83},
				{1248, 249, 106, 86, 78},
				{1362, 256, 106, 86, 78},
				{1515, 286, 109, 88, 79},
				{1606, 282, 99, 85, 78},
				{1430, 301, 102, 86, 79},
				{1586, 319, 105, 88, 80},
				{1751, 335, 108, 90, 81},
				{1934, 356, 111, 92, 83},
				{2203, 371, 116, 93, 83},
				{2506, 400, 115, 91, 80},
				{2979, 444, 113, 91, 82},
				{3668, 515, 118, 93, 83},
				{4833, 627, 125, 98, 87},
				{8571, 899, 143, 106, 95},
				{28443, 7453, 268, 144, 154},
				{69968, 14480, 1555, 6292, 971}
	}
};

#if 0
static struct sf_lut r1batt = {
	.rows		= 31,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.r1		= {
				{401, 202, 109, 100, 100},
				{400, 202, 109, 100, 100},
				{381, 198, 109, 100, 100},
				{381, 198, 109, 100, 100},
				{381, 195, 109, 100, 100},
				{402, 198, 109, 101, 101},
				{401, 198, 110, 101, 101},
				{399, 198, 110, 101, 101},
				{386, 199, 110, 101, 101},
				{386, 200, 111, 102, 102},
				{386, 204, 111, 102, 102},
				{383, 208, 112, 102, 102},
				{388, 209, 112, 103, 102},
				{392, 209, 113, 103, 103},
				{411, 210, 114, 104, 103},
				{410, 212, 114, 104, 103},
				{393, 215, 115, 104, 104},
				{413, 225, 116, 105, 104},
				{404, 220, 116, 105, 104},
				{402, 222, 116, 105, 104},
				{412, 223, 117, 105, 104},
				{434, 224, 117, 105, 104},
				{416, 226, 117, 105, 104},
				{451, 234, 118, 106, 104},
				{438, 233, 118, 106, 104},
				{438, 230, 119, 106, 105},
				{448, 230, 121, 107, 105},
				{462, 233, 123, 108, 106},
				{506, 244, 126, 109, 107},
				{516, 265, 134, 112, 110},
				{653, 514, 378, 146, 289}
	}
};

static struct sf_lut r2batt = {
	.rows		= 31,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.r2		= {
				{1223, 163, 51, 33, 22},
				{1221, 163, 51, 33, 22},
				{1133, 184, 55, 36, 23},
				{1042, 196, 61, 39, 25},
				{1056, 200, 68, 44, 28},
				{881, 216, 80, 49, 31},
				{888, 160, 84, 55, 35},
				{898, 164, 92, 62, 39},
				{914, 162, 74, 59, 40},
				{930, 157, 55, 41, 29},
				{983, 156, 50, 35, 25},
				{1066, 156, 52, 37, 27},
				{1171, 159, 54, 41, 29},
				{1297, 167, 56, 43, 32},
				{1424, 181, 57, 39, 30},
				{1587, 187, 56, 34, 22},
				{1787, 195, 56, 34, 22},
				{2012, 233, 59, 37, 23},
				{2166, 232, 43, 31, 21},
				{1887, 260, 48, 33, 23},
				{2126, 288, 52, 36, 25},
				{2369, 313, 57, 40, 27},
				{2679, 344, 62, 43, 29},
				{3074, 361, 68, 44, 29},
				{3573, 408, 66, 40, 25},
				{4329, 481, 62, 40, 27},
				{5421, 594, 68, 43, 29},
				{7271, 771, 78, 49, 34},
				{13209, 1195, 104, 62, 46},
				{44994, 11661, 295, 119, 137},
				{111297, 22655, 2110, 9922, 1265}
	}
};
#endif

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 31,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4320, 4319, 4322, 4317, 4309},
				{4225, 4245, 4251, 4249, 4243},
				{4156, 4188, 4193, 4190, 4186},
				{4090, 4135, 4138, 4135, 4131},
				{4050, 4083, 4086, 4083, 4079},
				{3949, 4026, 4041, 4036, 4030},
				{3908, 3948, 3980, 3985, 3986},
				{3872, 3914, 3946, 3948, 3945},
				{3836, 3882, 3901, 3905, 3904},
				{3805, 3851, 3861, 3863, 3862},
				{3785, 3825, 3832, 3833, 3833},
				{3771, 3803, 3810, 3810, 3810},
				{3760, 3784, 3793, 3793, 3791},
				{3749, 3771, 3779, 3778, 3775},
				{3738, 3760, 3767, 3763, 3756},
				{3724, 3743, 3754, 3746, 3732},
				{3706, 3722, 3734, 3725, 3710},
				{3686, 3709, 3712, 3703, 3688},
				{3665, 3702, 3691, 3682, 3670},
				{3647, 3695, 3688, 3679, 3667},
				{3635, 3692, 3686, 3678, 3666},
				{3621, 3687, 3685, 3677, 3665},
				{3602, 3678, 3682, 3674, 3662},
				{3582, 3661, 3678, 3669, 3655},
				{3555, 3635, 3662, 3650, 3632},
				{3521, 3598, 3625, 3614, 3593},
				{3475, 3548, 3575, 3564, 3543},
				{3412, 3480, 3510, 3500, 3478},
				{3317, 3383, 3421, 3413, 3389},
				{3185, 3246, 3286, 3284, 3254},
				{3000, 3000, 3000, 3000, 3000}
	}
};

static struct sf_lut pc_sf = {
	.rows		= 1,
	.cols		= 1,
	/* row_entries are cycles here */
	.row_entries		= {0},
	.percent	= {100},
	.sf			= {
				{100}
	}
};

struct bms_battery_data zte_4v35_2000mAh_data = {
	.fcc				= 2000,
	.fcc_temp_lut			= &fcc_temp,
	.fcc_sf_lut				= &fcc_sf,
	.pc_temp_ocv_lut		= &pc_temp_ocv,
	.pc_sf_lut				= &pc_sf,
	.rbatt_sf_lut			= &rbatt_sf,
	.default_rbatt_mohm	= 160
};
