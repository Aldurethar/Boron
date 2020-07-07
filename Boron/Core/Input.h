#pragma once

#include "Core.h"
#include <unordered_map>
#include <memory>

/*
* Header for Input handling.
* The enums are visible to the Application and can be used to handle Application-specific Input
* Inputs will be communicated to the Application through calls to the HandleInput() functions
* The Input class provides capabilities to request Key states and Cursor position
*/

namespace Boron {

	// Forward declarations for Enums
	enum class Keys : int;

	class BORON_API Input {
		friend class InputHandler;

	public:
		static bool IsKeyDown(Keys key);
		static float MouseX();
		static float MouseY();

		static void Init();

	private:
		static float m_MouseX;
		static float m_MouseY;
		static std::unordered_map<Keys, bool>* m_KeyStates;
	};

	class InputHandler {
	public:
		static void HandleKeyInput(int key, int scancode, int action, int mods);
		static void HandleMouseInput(int button, int action, int mods);
		static void HandleMousePos(double xPos, double yPos);
	};

	/* Different Types of Key Events, for use by the Application */
	enum class KeyEventType {
		KeyPressed,
		KeyRepeat,
		KeyReleased
	};

	/* Modifier Keys Bitfield, for use by the Application */
	enum class KeyMods : int {
		Shift = BIT(0),
		Control = BIT(1),
		Alt = BIT(2),
		Super = BIT(3),
		Capslock = BIT(4),
		Numlock = BIT(5),
	};

	/* Keycodes based on GLFW's Codes */
	enum class Keys : int {
		Unknown = -1,

		Mouse1 = 0,
		Mouse2 = 1,
		Mouse3 = 2,
		Mouse4 = 3,
		Mouse5 = 4,
		Mouse6 = 5,
		Mouse7 = 6,
		Mouse8 = 7,
		MouseLast = 7,
		MouseLeft = 0,
		MouseMiddle = 1,
		MouseRight = 2,

		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */
		Zero = 48,
		One = 49,
		Two = 50,
		Three = 51,
		Four = 52,
		Five = 53,
		Six = 54,
		Seven = 55,
		Eight = 56,
		Nine = 57,
		Semicolon = 59, /* ; */
		Equal = 61, /* = */
		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,
		BracketLeft = 91, /* [ */
		Backslash = 92, /* \ */
		BracketRight = 93, /* ] */
		AccentGrave = 96, /* ` */
		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		RightArrow = 262,
		LeftArrow = 263,
		DownArrow = 264,
		UpArrow = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		Capslock = 280,
		Scrolllock = 281,
		Numlock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,
		Num0 = 320,
		Num1 = 321,
		Num2 = 322,
		Num3 = 323,
		Num4 = 324,
		Num5 = 325,
		Num6 = 326,
		Num7 = 327,
		Num8 = 328,
		Num9 = 329,
		NumDecimal = 330,
		NumDivide = 331,
		NumMultiply = 332,
		NumSubtract = 333,
		NumAdd = 334,
		NumEnter = 335,
		NumEqual = 336,
		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348,
	};
}