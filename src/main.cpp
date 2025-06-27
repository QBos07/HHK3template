#include "gfx.h"
#include "src/gevent/gevent.h"
#include "src/gfx.h"
#include "src/gwin/gwin.h"
#include "src/gwin/gwin_button.h"
#include "src/gwin/gwin_widget.h"
#include <appdef.h>

APP_NAME("Your Cool uGFX App Name")
APP_AUTHOR("me")
APP_DESCRIPTION("A very cool app!")
APP_VERSION("1.0.0")

int main() {
  gfxInit();
  auto font = gdispOpenFont("*");
  gwinSetDefaultFont(font);
  gwinSetDefaultStyle(&WhiteWidgetStyle, gFalse);
  gdispClear(GFX_WHITE);

  GWidgetInit init;
  gwinWidgetClearInit(&init);
  init.g.height = 20;
  init.g.width = 20;
  init.g.x = 0;
  init.g.y = 0;
  init.g.show = gTrue;
  init.text = "X";
  auto button_exit = gwinButtonCreate(nullptr, &init);
  init.g.x = 20;
  init.g.y = 20;
  init.g.height = 200;
  init.g.width = 30;
  init.text = "Write something...";
  gwinTexteditCreate(nullptr, &init, 0);
	init.g.show = gTrue;
	init.g.x = 0;
	init.g.y = gdispGetHeight()*3/4;
	init.g.width = gdispGetWidth();
	init.g.height = gdispGetHeight()/4;
	auto ghKeyboard = gwinKeyboardCreate(0, &init);

  GListener listener;
  geventListenerInit(&listener);
  gwinAttachListener(&listener);
	geventAttachSource(&listener, gwinKeyboardGetEventSource(ghKeyboard), GLISTEN_KEYTRANSITIONS|GLISTEN_KEYUP);

  while (true) {
    auto event = geventEventWait(&listener, gDelayForever);
    switch (event->type) {
    case GEVENT_GWIN_BUTTON: {
      auto button_event = reinterpret_cast<GEventGWinButton *>(event);
      if (button_event->gwin == button_exit) {
        gfxDeinit();
        return 0;
      }
    } break;
    }
  }
}