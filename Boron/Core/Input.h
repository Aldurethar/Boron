#pragma once

#include "Core.h"

/*
* Header for Input handling.
* The enums are visible to the Application and can be used to handle Application-specific Input
*/

namespace Boron {

	class InputHandler {
	public:
		static void HandleKeyInput(int key, int scancode, int action, int mods);
	};

	/* Different Types of Key Events, for use by the Application */
	enum class KeyEventType {
		BR_KEY_PRESSED,
		BR_KEY_REPEAT,
		BR_KEY_RELEASED
	};

	/* Modifier Keys Bitfield, for use by the Application */
	enum class KeyMods : int {
		BR_KEYMOD_SHIFT = BIT(0),
		BR_KEYMOD_CTRL = BIT(1),
		BR_KEYMOD_ALT = BIT(2),
		BR_KEYMOD_SUPER = BIT(3),
		BR_KEYMOD_CAPS = BIT(4),
		BR_KEYMOD_NUM = BIT(5),
	};

	/* Keycodes based on GLFW's Codes */
	enum class Keys : int {
		BR_KEY_UNKNOWN = -1,
		BR_KEY_SPACE = 32,
		BR_KEY_APOSTROPHE = 39, /* ' */
		BR_KEY_COMMA = 44, /* , */
		BR_KEY_MINUS = 45, /* - */
		BR_KEY_PERIOD = 46, /* . */
		BR_KEY_SLASH = 47, /* / */
		BR_KEY_0 = 48,
		BR_KEY_1 = 49,
		BR_KEY_2 = 50,
		BR_KEY_3 = 51,
		BR_KEY_4 = 52,
		BR_KEY_5 = 53,
		BR_KEY_6 = 54,
		BR_KEY_7 = 55,
		BR_KEY_8 = 56,
		BR_KEY_9 = 57,
		BR_KEY_SEMICOLON = 59, /* ; */
		BR_KEY_EQUAL = 61, /* = */
		BR_KEY_A = 65,
		BR_KEY_B = 66,
		BR_KEY_C = 67,
		BR_KEY_D = 68,
		BR_KEY_E = 69,
		BR_KEY_F = 70,
		BR_KEY_G = 71,
		BR_KEY_H = 72,
		BR_KEY_I = 73,
		BR_KEY_J = 74,
		BR_KEY_K = 75,
		BR_KEY_L = 76,
		BR_KEY_M = 77,
		BR_KEY_N = 78,
		BR_KEY_O = 79,
		BR_KEY_P = 80,
		BR_KEY_Q = 81,
		BR_KEY_R = 82,
		BR_KEY_S = 83,
		BR_KEY_T = 84,
		BR_KEY_U = 85,
		BR_KEY_V = 86,
		BR_KEY_W = 87,
		BR_KEY_X = 88,
		BR_KEY_Y = 89,
		BR_KEY_Z = 90,
		BR_KEY_LEFT_BRACKET = 91, /* [ */
		BR_KEY_BACKSLASH = 92, /* \ */
		BR_KEY_RIGHT_BRACKET = 93, /* ] */
		BR_KEY_GRAVE_ACCENT = 96, /* ` */
		BR_KEY_WORLD_1 = 161, /* non-US #1 */
		BR_KEY_WORLD_2 = 162, /* non-US #2 */
		BR_KEY_ESCAPE = 256,
		BR_KEY_ENTER = 257,
		BR_KEY_TAB = 258,
		BR_KEY_BACKSPACE = 259,
		BR_KEY_INSERT = 260,
		BR_KEY_DELETE = 261,
		BR_KEY_RIGHT = 262,
		BR_KEY_LEFT = 263,
		BR_KEY_DOWN = 264,
		BR_KEY_UP = 265,
		BR_KEY_PAGE_UP = 266,
		BR_KEY_PAGE_DOWN = 267,
		BR_KEY_HOME = 268,
		BR_KEY_END = 269,
		BR_KEY_CAPS_LOCK = 280,
		BR_KEY_SCROLL_LOCK = 281,
		BR_KEY_NUM_LOCK = 282,
		BR_KEY_PRINT_SCREEN = 283,
		BR_KEY_PAUSE = 284,
		BR_KEY_F1 = 290,
		BR_KEY_F2 = 291,
		BR_KEY_F3 = 292,
		BR_KEY_F4 = 293,
		BR_KEY_F5 = 294,
		BR_KEY_F6 = 295,
		BR_KEY_F7 = 296,
		BR_KEY_F8 = 297,
		BR_KEY_F9 = 298,
		BR_KEY_F10 = 299,
		BR_KEY_F11 = 300,
		BR_KEY_F12 = 301,
		BR_KEY_F13 = 302,
		BR_KEY_F14 = 303,
		BR_KEY_F15 = 304,
		BR_KEY_F16 = 305,
		BR_KEY_F17 = 306,
		BR_KEY_F18 = 307,
		BR_KEY_F19 = 308,
		BR_KEY_F20 = 309,
		BR_KEY_F21 = 310,
		BR_KEY_F22 = 311,
		BR_KEY_F23 = 312,
		BR_KEY_F24 = 313,
		BR_KEY_F25 = 314,
		BR_KEY_KP_0 = 320,
		BR_KEY_KP_1 = 321,
		BR_KEY_KP_2 = 322,
		BR_KEY_KP_3 = 323,
		BR_KEY_KP_4 = 324,
		BR_KEY_KP_5 = 325,
		BR_KEY_KP_6 = 326,
		BR_KEY_KP_7 = 327,
		BR_KEY_KP_8 = 328,
		BR_KEY_KP_9 = 329,
		BR_KEY_KP_DECIMAL = 330,
		BR_KEY_KP_DIVIDE = 331,
		BR_KEY_KP_MULTIPLY = 332,
		BR_KEY_KP_SUBTRACT = 333,
		BR_KEY_KP_ADD = 334,
		BR_KEY_KP_ENTER = 335,
		BR_KEY_KP_EQUAL = 336,
		BR_KEY_LEFT_SHIFT = 340,
		BR_KEY_LEFT_CONTROL = 341,
		BR_KEY_LEFT_ALT = 342,
		BR_KEY_LEFT_SUPER = 343,
		BR_KEY_RIGHT_SHIFT = 344,
		BR_KEY_RIGHT_CONTROL = 345,
		BR_KEY_RIGHT_ALT = 346,
		BR_KEY_RIGHT_SUPER = 347,
		BR_KEY_MENU = 348,
	};
}