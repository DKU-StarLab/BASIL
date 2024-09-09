// -*- C++ -*- generated by wxGlade 0.5 on Sat May 12 21:47:25 2007 from
// /tdata/tmp/stx-btree/wxbtreedemo/wxBTreeDemo.wxg

#include "WMain_wxg.h"

#include "WTreeDrawing.h"

WMain_wxg::WMain_wxg(wxWindow* parent, int id, const wxString& title,
                     const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE) {
  // begin wxGlade: WMain_wxg::WMain_wxg
  panel_Main = new wxPanel(this, wxID_ANY);
  sizer_8_staticbox = new wxStaticBox(panel_Main, -1, wxT("Data Input"));
  sizer_9_staticbox = new wxStaticBox(panel_Main, -1, wxT("Operation"));
  sizer_10_staticbox = new wxStaticBox(panel_Main, -1, wxT("Drawing"));
  sizer_3_staticbox =
      new wxStaticBox(panel_Main, -1, wxT("B+ Tree Properties"));
  const wxString choice_DataType_choices[] = {wxT("integer"), wxT("string")};
  choice_DataType =
      new wxChoice(panel_Main, ID_CHOICE_DATATYPE, wxDefaultPosition,
                   wxDefaultSize, 2, choice_DataType_choices, 0);
  const wxString choice_NodeSlots_choices[] = {
      wxT("4"),  wxT("5"),  wxT("6"),  wxT("7"),  wxT("8"),
      wxT("9"),  wxT("10"), wxT("11"), wxT("12"), wxT("13"),
      wxT("14"), wxT("15"), wxT("16"), wxT("32")};
  choice_NodeSlots =
      new wxChoice(panel_Main, ID_CHOICE_NODESLOTS, wxDefaultPosition,
                   wxDefaultSize, 14, choice_NodeSlots_choices, 0);
  checkbox_Duplicates =
      new wxCheckBox(panel_Main, ID_CHECKBOX_DUPLICATES, wxT("Duplicate Keys"));
  textctrl_Key = new wxTextCtrl(panel_Main, wxID_ANY, wxEmptyString);
  textctrl_Data = new wxTextCtrl(panel_Main, wxID_ANY, wxEmptyString);
  button_Insert = new wxButton(panel_Main, ID_BUTTON_INSERT, wxT("Insert"),
                               wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
  button_Erase = new wxButton(panel_Main, ID_BUTTON_ERASE, wxT("Erase"),
                              wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
  button_InsertRandom =
      new wxButton(panel_Main, ID_BUTTON_INSERTRANDOM, wxT("Insert Random"),
                   wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
  button_FindKey =
      new wxButton(panel_Main, ID_BUTTON_FINDKEY, wxT("Find Key"),
                   wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
  button_EqualRange =
      new wxButton(panel_Main, ID_BUTTON_EQUALRANGE, wxT("Equal Range"),
                   wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
  button_Clear = new wxButton(panel_Main, ID_BUTTON_CLEAR, wxT("Clear"),
                              wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
  button_LoadFile =
      new wxButton(panel_Main, ID_BUTTON_LOADFILE, wxT("Load File"),
                   wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
  textctrl_OpResult =
      new wxTextCtrl(panel_Main, wxID_ANY, wxEmptyString, wxDefaultPosition,
                     wxDefaultSize, wxTE_READONLY);
  window_TreeDrawing = new WTreeDrawing(panel_Main, wxID_ANY);

  set_properties();
  do_layout();
  // end wxGlade
}

void WMain_wxg::set_properties() {
  // begin wxGlade: WMain_wxg::set_properties
  SetTitle(wxT("STX B+ Tree Demo - http://panthema.net/"));
  choice_DataType->SetSelection(0);
  choice_NodeSlots->SetSelection(1);
  button_Insert->SetToolTip(
      wxT("Insert the key/data pair from the data input fields."));
  button_Erase->SetToolTip(
      wxT("Erase key given in the data input fields from tree"));
  button_InsertRandom->SetToolTip(
      wxT("Insert some random data into the tree."));
  button_FindKey->SetToolTip(
      wxT("Find the key given in data input field within the tree."));
  button_EqualRange->SetToolTip(
      wxT("Perform equal_range() search of the input key field."));
  button_Clear->SetToolTip(wxT("Clear the tree's contents."));
  button_LoadFile->SetToolTip(
      wxT("Load key/data pairs from file. Each line in the file contains key "
          "<space> data pairs."));
  // end wxGlade
}

void WMain_wxg::do_layout() {
  // begin wxGlade: WMain_wxg::do_layout
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxStaticBoxSizer* sizer_10 =
      new wxStaticBoxSizer(sizer_10_staticbox, wxVERTICAL);
  wxBoxSizer* sizer_2 = new wxBoxSizer(wxVERTICAL);
  wxStaticBoxSizer* sizer_9 =
      new wxStaticBoxSizer(sizer_9_staticbox, wxVERTICAL);
  wxFlexGridSizer* grid_sizer_3 = new wxFlexGridSizer(1, 7, 0, 0);
  wxBoxSizer* sizer_7 = new wxBoxSizer(wxHORIZONTAL);
  wxStaticBoxSizer* sizer_8 =
      new wxStaticBoxSizer(sizer_8_staticbox, wxVERTICAL);
  wxFlexGridSizer* grid_sizer_2 = new wxFlexGridSizer(3, 2, 0, 0);
  wxStaticBoxSizer* sizer_3 =
      new wxStaticBoxSizer(sizer_3_staticbox, wxVERTICAL);
  wxFlexGridSizer* grid_sizer_1 = new wxFlexGridSizer(3, 2, 0, 0);
  wxStaticText* label_1 =
      new wxStaticText(panel_Main, wxID_ANY, wxT("Data Type"));
  grid_sizer_1->Add(label_1, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_1->Add(choice_DataType, 0,
                    wxALL | wxALIGN_CENTER_VERTICAL | wxSHAPED, 4);
  wxStaticText* label_3 =
      new wxStaticText(panel_Main, wxID_ANY, wxT("Node Slots"));
  grid_sizer_1->Add(label_3, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_1->Add(choice_NodeSlots, 0,
                    wxALL | wxALIGN_CENTER_VERTICAL | wxSHAPED, 4);
  grid_sizer_1->Add(2, 2, 0, wxADJUST_MINSIZE, 0);
  grid_sizer_1->Add(checkbox_Duplicates, 0, wxALL, 4);
  grid_sizer_1->AddGrowableCol(0);
  grid_sizer_1->AddGrowableCol(1);
  sizer_3->Add(grid_sizer_1, 1, wxEXPAND, 0);
  sizer_7->Add(sizer_3, 1, wxALL | wxEXPAND, 6);
  sizer_8->Add(1, 1, 1, wxADJUST_MINSIZE, 0);
  wxStaticText* label_5 = new wxStaticText(panel_Main, wxID_ANY, wxT("Key"));
  grid_sizer_2->Add(label_5, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_2->Add(textctrl_Key, 0, wxALL | wxEXPAND, 4);
  wxStaticText* label_6 = new wxStaticText(panel_Main, wxID_ANY, wxT("Data"));
  grid_sizer_2->Add(label_6, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_2->Add(textctrl_Data, 1, wxALL | wxEXPAND, 4);
  grid_sizer_2->AddGrowableCol(1);
  sizer_8->Add(grid_sizer_2, 0, wxEXPAND, 0);
  sizer_8->Add(1, 1, 1, wxADJUST_MINSIZE, 0);
  sizer_7->Add(sizer_8, 1, wxRIGHT | wxTOP | wxBOTTOM | wxEXPAND, 6);
  sizer_2->Add(sizer_7, 0, wxEXPAND, 0);
  grid_sizer_3->Add(button_Insert, 0,
                    wxLEFT | wxTOP | wxBOTTOM | wxALIGN_CENTER_HORIZONTAL |
                        wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_3->Add(button_Erase, 0,
                    wxLEFT | wxTOP | wxBOTTOM | wxALIGN_CENTER_HORIZONTAL |
                        wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_3->Add(button_InsertRandom, 0,
                    wxLEFT | wxTOP | wxBOTTOM | wxALIGN_CENTER_HORIZONTAL |
                        wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_3->Add(button_FindKey, 0,
                    wxLEFT | wxTOP | wxBOTTOM | wxALIGN_CENTER_HORIZONTAL |
                        wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_3->Add(button_EqualRange, 0,
                    wxLEFT | wxTOP | wxBOTTOM | wxALIGN_CENTER_HORIZONTAL |
                        wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_3->Add(button_Clear, 0,
                    wxLEFT | wxTOP | wxBOTTOM | wxALIGN_CENTER_HORIZONTAL |
                        wxALIGN_CENTER_VERTICAL,
                    4);
  grid_sizer_3->Add(button_LoadFile, 0, wxALL, 4);
  grid_sizer_3->AddGrowableCol(0);
  grid_sizer_3->AddGrowableCol(1);
  grid_sizer_3->AddGrowableCol(2);
  grid_sizer_3->AddGrowableCol(3);
  grid_sizer_3->AddGrowableCol(4);
  grid_sizer_3->AddGrowableCol(5);
  sizer_9->Add(grid_sizer_3, 0, wxEXPAND, 0);
  sizer_9->Add(textctrl_OpResult, 0, wxALL | wxEXPAND, 4);
  sizer_2->Add(sizer_9, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, 6);
  sizer_1->Add(sizer_2, 0, wxEXPAND, 0);
  sizer_10->Add(window_TreeDrawing, 1, wxALL | wxEXPAND, 2);
  sizer_1->Add(sizer_10, 1, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, 6);
  panel_Main->SetSizer(sizer_1);
  sizer_4->Add(panel_Main, 1, wxEXPAND, 0);
  SetSizer(sizer_4);
  sizer_4->Fit(this);
  Layout();
  Centre();
  // end wxGlade
}
