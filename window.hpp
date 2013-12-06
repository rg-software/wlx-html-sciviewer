#pragma once

#include <sciter3/sciter-x-host-callback.h>
#include <sciter3/sciter-x-behavior.h>

class window:
  public sciter::host<window>,
  public sciter::event_handler
{
  static ATOM get_class();

public:
  static window* ptr(HWND wnd);
  window(HWND parent);
  ~window();

  void show();
  bool load_file(const wchar_t* uri);

  bool select_all();
  bool copy_selection();
  bool scroll(int percent);

public:
  // from sciter::host
  HWND get_hwnd();
  HINSTANCE get_resource_instance();

protected:
  BEGIN_FUNCTION_MAP
    FUNCTION_0("launchDebugView", launch_debug);
  END_FUNCTION_MAP

protected:
  json::value launch_debug();

private:
  HWND wnd;
};