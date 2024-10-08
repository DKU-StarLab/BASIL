// -*- C++ -*- generated by wxGlade 0.5 on Sat May 12 21:47:25 2007 from
// /tdata/tmp/stx-btree/wxbtreedemo/wxBTreeDemo.wxg

#include <wx/image.h>
#include <wx/wx.h>

#ifndef WMAIN_WXG_H
#define WMAIN_WXG_H

// begin wxGlade: ::dependencies
// end wxGlade
class WTreeDrawing;

class WMain_wxg : public wxFrame {
 public:
  // begin wxGlade: WMain_wxg::ids
  enum {
    ID_CHOICE_DATATYPE = wxID_HIGHEST + 1000,
    ID_CHOICE_NODESLOTS = wxID_HIGHEST + 1001,
    ID_CHECKBOX_DUPLICATES = wxID_HIGHEST + 1002,
    ID_BUTTON_INSERT = wxID_HIGHEST + 1003,
    ID_BUTTON_ERASE = wxID_HIGHEST + 1004,
    ID_BUTTON_INSERTRANDOM = wxID_HIGHEST + 1005,
    ID_BUTTON_FINDKEY = wxID_HIGHEST + 1006,
    ID_BUTTON_EQUALRANGE = wxID_HIGHEST + 1007,
    ID_BUTTON_CLEAR = wxID_HIGHEST + 1008,
    ID_BUTTON_LOADFILE = wxID_HIGHEST + 1009
  };
  // end wxGlade

  WMain_wxg(wxWindow* parent, int id, const wxString& title,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxDEFAULT_FRAME_STYLE);

 private:
  // begin wxGlade: WMain_wxg::methods
  void set_properties();
  void do_layout();
  // end wxGlade

 protected:
  // begin wxGlade: WMain_wxg::attributes
  wxStaticBox* sizer_10_staticbox;
  wxStaticBox* sizer_9_staticbox;
  wxStaticBox* sizer_8_staticbox;
  wxStaticBox* sizer_3_staticbox;
  wxChoice* choice_DataType;
  wxChoice* choice_NodeSlots;
  wxCheckBox* checkbox_Duplicates;
  wxTextCtrl* textctrl_Key;
  wxTextCtrl* textctrl_Data;
  wxButton* button_Insert;
  wxButton* button_Erase;
  wxButton* button_InsertRandom;
  wxButton* button_FindKey;
  wxButton* button_EqualRange;
  wxButton* button_Clear;
  wxButton* button_LoadFile;
  wxTextCtrl* textctrl_OpResult;
  WTreeDrawing* window_TreeDrawing;
  wxPanel* panel_Main;
  // end wxGlade
};  // wxGlade: end class

#endif  // WMAIN_WXG_H
