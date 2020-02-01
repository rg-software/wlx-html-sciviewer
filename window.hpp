#pragma once
//#define __STDC_WANT_SECURE_LIB__ 0

//#include <windows.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>
//#include <sciter-x-dom.hpp>
#include "sciter/sciter-x.h"


//#include <sciter-x-host-callback.h>
//#include <sciter-x-behavior.h>
//#include <sciter-x.h>

class window:
  public sciter::host<window>,
  public sciter::event_handler
{
  static ATOM get_class();

public:
  // from sciter::host
  HWND get_hwnd();
  HINSTANCE get_resource_instance();

public:

  // get object from HWND
  static window* ptr(HWND wnd);

  // create the child window
  window(HWND parent);
  ~window();


  void show();
  bool load_file(const wchar_t* uri);

  void ensure_min_size();

  SIZE get_size(bool minsize = false) const;
  void set_size(const SIZE& size);

public:
  // TC methods
  bool select_all();
  bool copy_selection();
  bool scroll(int percent);


protected:
  BEGIN_FUNCTION_MAP
    FUNCTION_0("launchDebugView", launch_debug);
    FUNCTION_1("peversion", get_version);
    FUNCTION_0("peversion", get_version);
  END_FUNCTION_MAP

protected:
  json::value launch_debug();
  json::value get_version(const json::value& module = json::value());

private:
  HWND wnd;
};
