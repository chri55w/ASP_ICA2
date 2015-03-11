/**
 @file      InputStateProtocol.hpp
 @author    Tyrone Davison
 @date      September 2012
 */

// TODO: document me

#pragma once
#ifndef __TYGA_INPUT_STATE_PROTOCOL__
#define __TYGA_INPUT_STATE_PROTOCOL__

namespace tyga {

/**
 Enumeration of non-printable keyboard keys.
 Printable keys are represented by their capital ASCII value.
 */
enum InputKeyIndex
{
    kInputKeySpace = 32,
    kInputKeySpecial = 256,
    kInputKeyEsc,
    kInputKeyF1,
    kInputKeyF2,
    kInputKeyF3,
    kInputKeyF4,
    kInputKeyF5,
    kInputKeyF6,
    kInputKeyF7,
    kInputKeyF8,
    kInputKeyF9,
    kInputKeyF10,
    kInputKeyF11,
    kInputKeyF12,
    kInputKeyF13,
    kInputKeyF14,
    kInputKeyF15,
    kInputKeyF16,
    kInputKeyF17,
    kInputKeyF18,
    kInputKeyF19,
    kInputKeyF20,
    kInputKeyF21,
    kInputKeyF22,
    kInputKeyF23,
    kInputKeyF24,
    kInputKeyF25,
    kInputKeyUp,
    kInputKeyDown,
    kInputKeyLeft,
    kInputKeyRight,
    kInputKeyLShift,
    kInputKeyRShift,
    kInputKeyLCtrl,
    kInputKeyRCtrl,
    kInputKeyLAlt,
    kInputKeyRAlt,
    kInputKeyTab,
    kInputKeyEnter,
    kInputKeyBackspace,
    kInputKeyInsert,
    kInputKeyDel,
    kInputKeyPageUp,
    kInputKeyPageDown,
    kInputKeyHome,
    kInputKeyEnd,
    kInputKeyPad0,
    kInputKeyPad1,
    kInputKeyPad2,
    kInputKeyPad3,
    kInputKeyPad4,
    kInputKeyPad5,
    kInputKeyPad6,
    kInputKeyPad7,
    kInputKeyPad8,
    kInputKeyPad9,
    kInputKeyPadDivide,
    kInputKeyPadMultiply,
    kInputKeyPadSubtract,
    kInputKeyPadAdd,
    kInputKeyPadDecimal,
    kInputKeyPadEqual,
    kInputKeyPadEnter,
    kInputKeyPadNumLock,
    kInputKeyCapsLock,
    kInputKeyScrollLock,
    kInputKeyPause,
    kInputKeyLSuper,
    kInputKeyRSuper,
    kInputKeyMaxEnum // do not use
};

/**
 Enumeration of the keyboard axes.
 */
enum InputKeyboardAxisIndex
{
    kInputKeyboardAxisLeftRight,
    kInputKeyboardAxisUpDown,
    kInputKeyboardAxisMaxEnum // do not use
};

/**
 Enumeration of mouse button indices.
 */
enum InputMouseButtonIndex
{
    kInputMouseButtonLeft,
    kInputMouseButtonRight,
    kInputMouseButtonMiddle,
    kInputMouseButtonMaxEnum // do not use
};

/**
 Enumeration of the mouse axes.
 */
enum InputMouseAxisIndex
{
    kInputMouseAxisX,
    kInputMouseAxisY,
    kInputMouseAxisMaxEnum // do not use
};

/**
 Enumeration of gamepad axis.
 */
enum InputGamepadAxisIndex
{
    kInputGamepadAxisLeftThumbX,
    kInputGamepadAxisLeftThumbY,
    kInputGamepadAxisLeftTrigger,
    kInputGamepadAxisRightThumbY,
    kInputGamepadAxisRightThumbX,
    kInputGamepadAxisReserved0,
    kInputGamepadAxisReserved1,
    kInputGamepadAxisRightTrigger,
    kInputGamepadAxisMaxEnum // do not use
};

/**
 Enumeration of gamepad buttons.
 */
enum InputGamepadButtonIndex
{
    kInputGamepadButtonA,
    kInputGamepadButtonB,
    kInputGamepadButtonX,
    kInputGamepadButtonY,
    kInputGamepadButtonLeftShoulder,
    kInputGamepadButtonRightShoulder,
    kInputGamepadButtonBack,
    kInputGamepadButtonStart,
    kInputGamepadButtonLeftThumb,
    kInputGamepadButtonRightThumb,
    kInputGamepadButtonReserved0,
    kInputGamepadButtonReserved1,
    kInputGamepadButtonMaxEnum // do not use
};

class InputStateProtocol
{
public:

    virtual int
    keyboardKeyDownCount(int key_index) const =0;

    virtual float
    keyboardAxisPosition(int axis_index) const =0;

    virtual int
    mouseButtonDownCount(int button_index) const =0;

    virtual float
    mouseAxisPosition(int axis_index) const =0;

    virtual int
    mouseCursorPosition(int axis_index) const =0;

    virtual int
    gamepadButtonDownCount(int gamepad_index,
                           int button_index) const =0;

    virtual float
    gamepadAxisPosition(int gamepad_index,
                        int axis_index) const =0;

    virtual bool
    gamepadPresent(int gamepad_index) const =0;
};

} // end namespace tyga

#endif
