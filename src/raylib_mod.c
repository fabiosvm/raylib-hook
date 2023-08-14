//
// raylib_mod.c
//

#include "raylib_mod.h"
#include <raylib.h>

typedef struct
{
  HK_USERDATA_HEADER
  Vector2 vector;
} Vector2Userdata;

typedef struct
{
  HK_USERDATA_HEADER
  Color color;
} ColorUserdata;

static ColorUserdata lightGrayColor = { .refCount = 1, .deinit = NULL, .color = LIGHTGRAY };
static ColorUserdata grayColor = { .refCount = 1, .deinit = NULL, .color = GRAY };
static ColorUserdata darkGrayColor = { .refCount = 1, .deinit = NULL, .color = DARKGRAY };
static ColorUserdata yellowColor = { .refCount = 1, .deinit = NULL, .color = YELLOW };
static ColorUserdata goldColor = { .refCount = 1, .deinit = NULL, .color = GOLD };
static ColorUserdata orangeColor = { .refCount = 1, .deinit = NULL, .color = ORANGE };
static ColorUserdata pinkColor = { .refCount = 1, .deinit = NULL, .color = PINK };
static ColorUserdata redColor = { .refCount = 1, .deinit = NULL, .color = RED };
static ColorUserdata maroonColor = { .refCount = 1, .deinit = NULL, .color = MAROON };
static ColorUserdata greenColor = { .refCount = 1, .deinit = NULL, .color = GREEN };
static ColorUserdata limeColor = { .refCount = 1, .deinit = NULL, .color = LIME };
static ColorUserdata darkGreenColor = { .refCount = 1, .deinit = NULL, .color = DARKGREEN };
static ColorUserdata skyBlueColor = { .refCount = 1, .deinit = NULL, .color = SKYBLUE };
static ColorUserdata blueColor = { .refCount = 1, .deinit = NULL, .color = BLUE };
static ColorUserdata darkBlueColor = { .refCount = 1, .deinit = NULL, .color = DARKBLUE };
static ColorUserdata purpleColor = { .refCount = 1, .deinit = NULL, .color = PURPLE };
static ColorUserdata violetColor = { .refCount = 1, .deinit = NULL, .color = VIOLET };
static ColorUserdata darkPurpleColor = { .refCount = 1, .deinit = NULL, .color = DARKPURPLE };
static ColorUserdata beigeColor = { .refCount = 1, .deinit = NULL, .color = BEIGE };
static ColorUserdata brownColor = { .refCount = 1, .deinit = NULL, .color = BROWN };
static ColorUserdata darkBrownColor = { .refCount = 1, .deinit = NULL, .color = DARKBROWN };
static ColorUserdata whiteColor = { .refCount = 1, .deinit = NULL, .color = WHITE };
static ColorUserdata blackColor = { .refCount = 1, .deinit = NULL, .color = BLACK };
static ColorUserdata blankColor = { .refCount = 1, .deinit = NULL, .color = BLANK };
static ColorUserdata magentaColor = { .refCount = 1, .deinit = NULL, .color = MAGENTA };
static ColorUserdata rayWhiteColor = { .refCount = 1, .deinit = NULL, .color = RAYWHITE };

static inline Vector2Userdata *vector2_userdata_new(Vector2 vector);
static inline ColorUserdata *color_userdata_new(Color color);
static inline void load_colors(HkState *state);
static void NewVector2_call(HkState *state, HkValue *args);
static void Vector2GetX_call(HkState *state, HkValue *args);
static void Vector2GetY_call(HkState *state, HkValue *args);
static void InitWindow_call(HkState *state, HkValue *args);
static void WindowShouldClose_call(HkState *state, HkValue *args);
static void CloseWindow_call(HkState *state, HkValue *args);
static void IsWindowReady_call(HkState *state, HkValue *args);
static void ClearBackground_call(HkState *state, HkValue *args);
static void BeginDrawing_call(HkState *state, HkValue *args);
static void EndDrawing_call(HkState *state, HkValue *args);
static void DrawText_call(HkState *state, HkValue *args);
static void GetMonitorPosition_call(HkState *state, HkValue *args);
static void SetTargetFPS_call(HkState *state, HkValue *args);
static void IsMouseButtonPressed_call(HkState *state, HkValue *args);
static void GetMousePosition_call(HkState *state, HkValue *args);
static void DrawCircleV_call(HkState *state, HkValue *args);

static inline Vector2Userdata *vector2_userdata_new(Vector2 vector)
{
  Vector2Userdata *udata = (Vector2Userdata *) hk_allocate(sizeof(*udata));
  hk_userdata_init((HkUserdata *) udata, NULL);
  udata->vector = vector;
  return udata;
}

static inline ColorUserdata *color_userdata_new(Color color)
{
  ColorUserdata *udata = (ColorUserdata *) hk_allocate(sizeof(*udata));
  hk_userdata_init((HkUserdata *) udata, NULL);
  udata->color = color;
  return udata;
}

static inline void load_colors(HkState *state)
{
  hk_state_push_nil(state);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "LIGHTGRAY");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &lightGrayColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "GRAY");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &grayColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "DARKGRAY");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &darkGrayColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "YELLOW");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &yellowColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "GOLD");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &goldColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "ORANGE");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &orangeColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "PINK");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &pinkColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "RED");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &redColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "MAROON");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &maroonColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "GREEN");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &greenColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "LIME");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &limeColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "DARKGREEN");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &darkGreenColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "SKYBLUE");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &skyBlueColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "BLUE");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &blueColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "DARKBLUE");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &darkBlueColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "PURPLE");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &purpleColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "VIOLET");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &violetColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "DARKPURPLE");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &darkPurpleColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "BEIGE");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &beigeColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "BROWN");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &brownColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "DARKBROWN");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &darkBrownColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "WHITE");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &whiteColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "BLACK");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &blackColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "BLANK");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &blankColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "MAGENTA");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &magentaColor);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "RAYWHITE");
  hk_return_if_not_ok(state);
  hk_state_push_userdata(state, (HkUserdata *) &rayWhiteColor);
  hk_return_if_not_ok(state);
  hk_state_construct(state, 26);
}

static void NewVector2_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_number(state, args, 1);
  hk_return_if_not_ok(state);
  hk_state_check_argument_number(state, args, 2);
  hk_return_if_not_ok(state);
  float x = (float) hk_as_number(args[1]);
  float y = (float) hk_as_number(args[2]);
  Vector2 vector = { x, y };
  HkUserdata *udata = (HkUserdata *) vector2_userdata_new(vector);
  hk_state_push_userdata(state, udata);
  if (!hk_state_is_ok(state))
    hk_userdata_free(udata);
}

static void Vector2GetX_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_userdata(state, args, 1);
  hk_return_if_not_ok(state);
  Vector2 vector = ((Vector2Userdata *) hk_as_userdata(args[1]))->vector;
  hk_state_push_number(state, (double) vector.x);
}

static void Vector2GetY_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_userdata(state, args, 1);
  hk_return_if_not_ok(state);
  Vector2 vector = ((Vector2Userdata *) hk_as_userdata(args[1]))->vector;
  hk_state_push_number(state, (double) vector.y);
}

static void InitWindow_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_int(state, args, 1);
  hk_return_if_not_ok(state);
  hk_state_check_argument_int(state, args, 2);
  hk_return_if_not_ok(state);
  hk_state_check_argument_string(state, args, 3);
  hk_return_if_not_ok(state);
  int width = (int) hk_as_number(args[1]);
  int height = (int) hk_as_number(args[2]);
  const char *title = (const char *) hk_as_string(args[3])->chars;
  InitWindow(width, height, title);
  hk_state_push_nil(state);
}

static void WindowShouldClose_call(HkState *state, HkValue *args)
{
  (void) args;
  hk_state_push_bool(state, WindowShouldClose());
}

static void CloseWindow_call(HkState *state, HkValue *args)
{
  (void) args;
  CloseWindow();
  hk_state_push_nil(state);
}

static void IsWindowReady_call(HkState *state, HkValue *args)
{
  (void) args;
  hk_state_push_bool(state, IsWindowReady());
}

static void ClearBackground_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_userdata(state, args, 1);
  hk_return_if_not_ok(state);
  Color color = ((ColorUserdata *) hk_as_userdata(args[1]))->color;
  ClearBackground(color);
  hk_state_push_nil(state);
}

static void BeginDrawing_call(HkState *state, HkValue *args)
{
  (void) args;
  BeginDrawing();
  hk_state_push_nil(state);
}

static void EndDrawing_call(HkState *state, HkValue *args)
{
  (void) args;
  EndDrawing();
  hk_state_push_nil(state);
}

static void DrawText_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_string(state, args, 1);
  hk_return_if_not_ok(state);
  hk_state_check_argument_int(state, args, 2);
  hk_return_if_not_ok(state);
  hk_state_check_argument_int(state, args, 3);
  hk_return_if_not_ok(state);
  hk_state_check_argument_int(state, args, 4);
  hk_return_if_not_ok(state);
  hk_state_check_argument_userdata(state, args, 5);
  hk_return_if_not_ok(state);
  const char *text = (const char *) hk_as_string(args[1])->chars;
  int posX = (int) hk_as_number(args[2]);
  int posY = (int) hk_as_number(args[3]);
  int fontSize = (int) hk_as_number(args[4]);
  Color color = ((ColorUserdata *) hk_as_userdata(args[5]))->color;
  DrawText(text, posX, posY, fontSize, color);
  hk_state_push_nil(state);
}

static void GetMonitorPosition_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_int(state, args, 1);
  hk_return_if_not_ok(state);
  int monitor = (int) hk_as_number(args[1]);
  Vector2 position = GetMonitorPosition(monitor);
  HkUserdata *udata = (HkUserdata *) vector2_userdata_new(position);
  hk_state_push_userdata(state, udata);
  if (!hk_state_is_ok(state))
    hk_userdata_free(udata);
}

static void SetTargetFPS_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_int(state, args, 1);
  hk_return_if_not_ok(state);
  int fps = (int) hk_as_number(args[1]);
  SetTargetFPS(fps);
  hk_state_push_nil(state);
}

static void IsMouseButtonPressed_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_int(state, args, 1);
  hk_return_if_not_ok(state);
  int button = (int) hk_as_number(args[1]);
  hk_state_push_bool(state, IsMouseButtonPressed(button));
}

static void GetMousePosition_call(HkState *state, HkValue *args)
{
  (void) args;
  Vector2 position = GetMousePosition();
  HkUserdata *udata = (HkUserdata *) vector2_userdata_new(position);
  hk_state_push_userdata(state, udata);
  if (!hk_state_is_ok(state))
    hk_userdata_free(udata);
}

static void DrawCircleV_call(HkState *state, HkValue *args)
{
  hk_state_check_argument_userdata(state, args, 1);
  hk_return_if_not_ok(state);
  hk_state_check_argument_number(state, args, 2);
  hk_return_if_not_ok(state);
  hk_state_check_argument_userdata(state, args, 3);
  hk_return_if_not_ok(state);
  Vector2 center = ((Vector2Userdata *) hk_as_userdata(args[1]))->vector;
  float radius = (float) hk_as_number(args[2]);
  Color color = ((ColorUserdata *) hk_as_userdata(args[3]))->color;
  DrawCircleV(center, radius, color);
  hk_state_push_nil(state);
}

HK_LOAD_MODULE_HANDLER(raylib)
{
  hk_state_push_string_from_chars(state, -1, "raylib");
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "colors");
  hk_return_if_not_ok(state);
  load_colors(state);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "MOUSE_BUTTON_LEFT");
  hk_return_if_not_ok(state);
  hk_state_push_number(state, MOUSE_BUTTON_LEFT);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "MOUSE_BUTTON_RIGHT");
  hk_return_if_not_ok(state);
  hk_state_push_number(state, MOUSE_BUTTON_RIGHT);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "MOUSE_BUTTON_MIDDLE");
  hk_return_if_not_ok(state);
  hk_state_push_number(state, MOUSE_BUTTON_MIDDLE);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "MOUSE_BUTTON_SIDE");
  hk_return_if_not_ok(state);
  hk_state_push_number(state, MOUSE_BUTTON_SIDE);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "MOUSE_BUTTON_EXTRA");
  hk_return_if_not_ok(state);
  hk_state_push_number(state, MOUSE_BUTTON_EXTRA);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "MOUSE_BUTTON_FORWARD");
  hk_return_if_not_ok(state);
  hk_state_push_number(state, MOUSE_BUTTON_FORWARD);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "MOUSE_BUTTON_BACK");
  hk_return_if_not_ok(state);
  hk_state_push_number(state, MOUSE_BUTTON_BACK);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "NewVector2");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "NewVector2", 2, NewVector2_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "Vector2GetX");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "Vector2GetX", 1, Vector2GetX_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "Vector2GetY");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "Vector2GetY", 2, Vector2GetY_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "InitWindow");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "InitWindow", 3, InitWindow_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "WindowShouldClose");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "WindowShouldClose", 0, WindowShouldClose_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "CloseWindow");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "CloseWindow", 0, CloseWindow_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "IsWindowReady");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "IsWindowReady", 0, IsWindowReady_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "ClearBackground");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "ClearBackground", 1, ClearBackground_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "BeginDrawing");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "BeginDrawing", 0, BeginDrawing_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "EndDrawing");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "EndDrawing", 0, EndDrawing_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "DrawText");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "DrawText", 5, DrawText_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "GetMonitorPosition");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "GetMonitorPosition", 1, GetMonitorPosition_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "SetTargetFPS");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "SetTargetFPS", 1, SetTargetFPS_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "IsMouseButtonPressed");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "IsMouseButtonPressed", 1, IsMouseButtonPressed_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "GetMousePosition");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "GetMousePosition", 0, GetMousePosition_call);
  hk_return_if_not_ok(state);
  hk_state_push_string_from_chars(state, -1, "DrawCircleV");
  hk_return_if_not_ok(state);
  hk_state_push_new_native(state, "DrawCircleV", 3, DrawCircleV_call);
  hk_return_if_not_ok(state);
  hk_state_construct(state, 24);
}
