#pragma once

static short key = 1, pointer;
static bool mark = false, reverse = true, save_flag_inp = false;

static const int l = 10;
static float matrix[l][l * 2];
static float minor[l][l + 1][l];
static float inv_matrix[l][l]; // int
static int _rank1 = 0, _rank2 = 0, determinant = 0;
static int k = 0, action = 1;
static int size_x = 0, size_y = 0;
static int menusize, base = 10;
static double b_old = 0, c_old = 0, d_old = 0; //int

static constexpr auto MENUWIDE = 40;
static constexpr auto ELEMENT_LEN = 3;
static constexpr auto UP = 72;
static constexpr auto DOWN = 80;
static constexpr auto LEFT = 75;
static constexpr auto RIGHT = 77;
static constexpr auto ONE = 49;
static constexpr auto TWO = 50;
static constexpr auto THREE = 51;
static constexpr auto FOUR = 52;
static constexpr auto ENTER = 13;
static constexpr auto ESC = 27;
static constexpr auto BACKSPACE = 8;
static constexpr auto LIMIT = 308;

static const double M_PI = 3.1415926535897932384626433832795;
static const double M_2PI(2. * M_PI);